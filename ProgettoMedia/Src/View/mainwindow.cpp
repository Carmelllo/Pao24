#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchbar.h"
#include "Src/View/editmedia.h"
#include <QVBoxLayout>
#include <QSplitter>
#include "Src/Manager/mediafilemanager.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menubar->setNativeMenuBar(false);

    this->setWindowTitle(QString::fromStdString("Media library"));

    mediaWidget = new MediaWidget();

    mediaManager = new MediaManager();

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
    saveAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    ui->menuSave->addAction(saveAction);

    connect(saveAction, &QAction::triggered, this , &MainWindow::saveMedia);

    QAction *openAction = new QAction("Open Media", this);
    openAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    ui->menuOpen->addAction(openAction);

    connect(openAction, &QAction::triggered, this , &MainWindow::openMedia);

    QAction *closeAction = new QAction("Close Media", this);
    closeAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_W));
    ui->menuClose->addAction(closeAction);

    connect(closeAction, &QAction::triggered, this , &MainWindow::clearMedias);

    QAction *helpAction = new QAction("Shortcuts", this);
    ui->menuHelp->addAction(helpAction);

    connect(helpAction, &QAction::triggered, this , &MainWindow::onShowHelpClicked);

    container = new Container();
    searchContainer = new Container();
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
    MediaFileManager::saveMedia(fileName, container);
    ui->statusbar->showMessage("Status: Succesfully saved media file!");

}

void MainWindow::openMedia(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Media File"), "", tr("JSON Files (*.json);;All Files (*)"));
    if (fileName.isEmpty()) {
        return;
    }

    if (MediaFileManager::openMedia(fileName, container)) {
        ui->statusbar->showMessage("Status: Succesfully opened media file!");
        list->refresh();
        list->showWidgets(container, visitor);
    }

}

void MainWindow::showEditOnAdd() {
    EditMedia* editMediaAdd = new EditMedia();

    connect(editMediaAdd, &EditMedia::onApply, this, &MainWindow::onMediaCreated);
    editMediaAdd->showEditWindow();


}
void MainWindow::showEdit(const std::string& name)
{
    EditMedia* editMediaEdit = new EditMedia();
    ConcreteVisitor* visitor = new ConcreteVisitor();

    if (mediaManager->editMedia(container, name, visitor)) {
        connect(editMediaEdit, &EditMedia::onApply, this, &MainWindow::onMediaEdited);

        editMediaEdit->showEditMedia(visitor);
        editMediaEdit->showEditWindow();

        mediaWidget->hide();
        refreshList();
    } else {
        showError("Media not found");
    }

    delete visitor;
}

void MainWindow::onMediaCreated(AbstractMedia* media) {

    if (mediaManager->addMedia(container, media)) {
        ui->statusbar->showMessage("Status: Succesfully created media " + QString::fromStdString(media->getName()) + " !");
        refreshList();
    } else {
        showError("Name already taken");
    }
}
void MainWindow::onMediaEdited(AbstractMedia* media) {
    ui->statusbar->showMessage("Status: Succesfully edited media " + QString::fromStdString(media->getName()) + " !");
    container->add(media);
    list->refresh();
    list->showWidgets(container, visitor);
}

void MainWindow::showMediaWidget(const std::string& name){
    ConcreteVisitor* visitor = new ConcreteVisitor();

    const AbstractMedia* media = mediaManager->findMediaByName(name, container);
    (media)->accept(visitor);
    mediaWidget->showMedia(visitor);
    checkWidget(mediaWidget);
    mediaWidget->show();
    delete visitor;
}
void MainWindow::onMediaDeleted(const std::string& name){

    if (showQuestion()) {
        if (mediaManager->deleteMedia(container, name)) {
            ui->statusbar->showMessage("Status: Deleted " + QString::fromStdString(name) + " !");

            refreshList();
            mediaWidget->hide();
        } else {
            showError("Error deleting media");
        }
    }
}




void MainWindow::search(std::string& query) {
    list->refresh();
    searchContainer->clear();
    container->search(searchContainer, query);
    //searchContainer ha le giuste entries
    if(!searchContainer->empty()){
        list->showWidgets(searchContainer, visitor);
        ui->statusbar->showMessage("Status: Found " + QString::number(searchContainer->size()) + " medias for query " + QString::fromStdString(query));
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

    MediaFileManager::clearMedia(container);
    mediaWidget->hide();
    list->refresh();
    list->showWidgets(container, visitor);
}

void MainWindow::refreshList(){
    list->refresh();
    list->showWidgets(container, visitor);
}

void MainWindow::onShowHelpClicked() {
    QString helpText = "Keyboard Shortcuts:\n\n"
                       "Save: Ctrl + S\n"
                       "Open: Ctrl + O\n"
                       "Close: Ctrl + W\n\n";
    QMessageBox::information(this, "Shortcuts", helpText);
}
