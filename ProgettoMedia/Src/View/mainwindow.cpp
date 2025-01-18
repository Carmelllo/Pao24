#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchbar.h"
#include "Src/Json/jsonstorage.h"
#include "Src/View/editmedia.h"
#include <QVBoxLayout>
#include <QSplitter>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menubar->setNativeMenuBar(false);
    ui->statusbar->showMessage("Status : I'm working on it!");

    this->setWindowTitle(QString::fromStdString("Media library"));

    mediaWidget = new MediaWidget();

    //editMediaAdd = new EditMedia();

    SearchBar* searchbar = new SearchBar();

    visitor = new ConcreteVisitor();



    list = new MediaListWidget(this);

    list->setBaseSize(100,100);

    HSplitter = new QSplitter;
    VSplitter = new QSplitter;

    HSplitter->setChildrenCollapsible(true);
    VSplitter->setChildrenCollapsible(false);

    VSplitter->setOrientation(Qt::Vertical);

    VSplitter->setHandleWidth(0);


    VSplitter->addWidget(searchbar);
    VSplitter->addWidget(HSplitter);
    HSplitter->addWidget(list);

    setCentralWidget(VSplitter);

    connect(searchbar, &SearchBar::onSearch, this, &MainWindow::search);
    connect(list, &MediaListWidget::addClick, this, &MainWindow::showEditOnAdd);
    connect(list, &MediaListWidget::sendWidgetName, this, &MainWindow::showMediaWidget);
    connect(mediaWidget, &MediaWidget::onRemove, this, &MainWindow::onMediaDeleted);
    connect(mediaWidget, &MediaWidget::onEdit, this, &MainWindow::showEdit);

    //So i can connect the menu button using connect()
    QAction *saveAction = new QAction("Save Media", this);
    ui->menuSave->addAction(saveAction);

    connect(saveAction, &QAction::triggered, this , &MainWindow::saveMedia);

    QAction *openAction = new QAction("Open Media", this);
    ui->menuOpen->addAction(openAction);

    connect(openAction, &QAction::triggered, this , &MainWindow::openMedia);

    container = new Container();
    searchContainer = new Container();
    // MovieMedia* movie = new MovieMedia();

    // container->add(movie);
    //list->showWidgets(container, visitor);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::saveMedia(){

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Media"), "", tr("JSON Files (*.json);;All Files (*)"));
    if (fileName.isEmpty()) {
        return;
    }
    JsonStorage jsonStorage;
    QJsonArray mediaArray;
    for(auto it = container->begin(); it != container->end(); ++it){
        mediaArray.append(jsonStorage.turnToObject(**it));  // Add each media to the JSON array
    }
    QJsonDocument doc(mediaArray);
    QFile saveFile(fileName);
    if (!saveFile.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open the file for writing."));
        return;
    }
    saveFile.write(doc.toJson());
    saveFile.close();

    QMessageBox::information(this, tr("Success"), tr("Your media has been saved!"));

}

void MainWindow::openMedia(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Media File"), "", tr("JSON Files (*.json);;All Files (*)"));
    if (fileName.isEmpty()) {
        return;
    }
    QFile loadFile(fileName);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open the file for reading."));
        return;
    }
    QByteArray fileData = loadFile.readAll();
    loadFile.close();
    QJsonDocument doc = QJsonDocument::fromJson(fileData);
    if (doc.isNull()) {
        QMessageBox::critical(this, tr("Error"), tr("Invalid JSON data."));
        return;
    }
    QJsonArray mediaArray = doc.array();

    clearMedias();
    for (const QJsonValue &value : mediaArray) {
        if (value.isObject()) {
            QJsonObject mediaObject = value.toObject();

            try {
                AbstractMedia *media = JsonStorage::turnToMedia(mediaObject);
                container->add(media);
            } catch (const std::invalid_argument &e) {
                QMessageBox::critical(this, tr("Error"), tr("Error processing JSON: ") + e.what());
                return;
            }
        }
    }
    QMessageBox::information(this, tr("Success"), tr("Media has been loaded successfully!"));

    list->refresh();
    list->showWidgets(container, visitor);

}



void MainWindow::showEditOnAdd() {
    EditMedia* editMediaAdd = new EditMedia();

    connect(editMediaAdd, &EditMedia::onApply, this, &MainWindow::onMediaCreated);
    editMediaAdd->showEditWindow();
}
void MainWindow::showEdit(const std::string& name) {

    EditMedia* editMediaEdit = new EditMedia();
    ConcreteVisitor* visitor = new ConcreteVisitor();

    for (auto it = container->begin(); it != container->end();) {
        if ((*it)->getName() == name) {
            (*it)->accept(visitor);

            editMediaEdit->onApplyEditButtonClicked(visitor);
            connect(editMediaEdit, &EditMedia::onApply, this, &MainWindow::onMediaEdited);
            editMediaEdit->showEditWindow();

            mediaWidget->hide();

            container->remove(*it);
            list->refresh();
            list->showWidgets(container, visitor);
            delete visitor;

            break;
        } else {
            ++it;
        }
    }
}

void MainWindow::onMediaCreated(AbstractMedia* media) {
    qDebug() << container->size();

    for(auto it = container->begin(); it != container->end(); ++it){
        if(media->getName()==(*it)->getName()){
            showError("Name already taken");
            return;
        }
    }
    container->add(media);
    list->refresh();//importante per non mostrare duplicati se aggiungo nome uguale e poi nome nuovo
    list->showWidgets(container, visitor);
}
void MainWindow::onMediaEdited(AbstractMedia* media) {
    container->add(media);
    list->refresh();
    list->showWidgets(container, visitor);
}

void MainWindow::onMediaDeleted(const std::string& name){

    if(showQuestion()){
    for (auto it = container->begin(); it != container->end();) {
        if ((*it)->getName() == name) {
            qDebug() << name << " = " << ((*it)->getName());
            container->remove(*it);
            list->refresh();
            list->showWidgets(container, visitor);
            mediaWidget->hide();
            break;
        } else {
            ++it;
        }
    }}
}

void MainWindow::showMediaWidget(const std::string& name){
    ConcreteVisitor* visitor = new ConcreteVisitor();

    for(auto it = container->begin(); it != container->end(); ++it){
        if(name==(*it)->getName()){
            (*it)->accept(visitor);
            mediaWidget->showMedia(visitor);
            checkWidget(mediaWidget);
            mediaWidget->show();
            delete visitor;
        }

    }
}



void MainWindow::search(std::string& query) {
    list->refresh();
    searchContainer->clear();
    container->search(searchContainer, query);
    //searchContainer has the right entries so i can call showWidgets
    if(!searchContainer->empty()){
        list->showWidgets(searchContainer, visitor);
        ui->statusbar->showMessage("Status: Found " + QString::number(searchContainer->size()) + " medias for query: " + QString::fromStdString(query));
    }
    else{
        ui->statusbar->showMessage("Status: No media found");
    }
}

void MainWindow::checkWidget(QWidget* widget){
    if(!widget->isActiveWindow() && HSplitter->indexOf(widget) == -1){
        HSplitter->addWidget(widget);
    }
}

void MainWindow::showError(const QString &message) {
    QMessageBox::critical(this, "Error", message, QMessageBox::Ok);
}

bool MainWindow::showQuestion() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to delete this item?",QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        return true;
    } else {
        return false;
    }
}

void MainWindow::clearMedias() {
    // Safe way to clear container by iterating backwards
    container->clear();
    list->refresh();
    list->showWidgets(container, visitor);
}
