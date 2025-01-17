#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchbar.h"
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
    SearchBar* searchbar = new SearchBar();

    editMediaWidget = new EditMedia();
    visitor = new ConcreteVisitor();

    list = new MediaListWidget(this);

    list->setBaseSize(100,100);

    HSplitter = new QSplitter;
    VSplitter = new QSplitter;

    HSplitter->setChildrenCollapsible(false);
    VSplitter->setChildrenCollapsible(false);

    VSplitter->setOrientation(Qt::Vertical);

    VSplitter->setHandleWidth(0);


    VSplitter->addWidget(searchbar);
    VSplitter->addWidget(HSplitter);
    HSplitter->addWidget(list);


    setCentralWidget(VSplitter);

    connect(searchbar, &SearchBar::onSearch, this, &MainWindow::search);
    connect(list, &MediaListWidget::addClick, this, &MainWindow::showEditOnAdd);
    connect(editMediaWidget, &EditMedia::onApply, this, &MainWindow::onMediaCreated);
    connect(list, &MediaListWidget::sendWidgetName, this, &MainWindow::showMediaWidget);

    container = new Container();
    searchContainer = new Container();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEditOnAdd() {
    EditMedia* editMedia = new EditMedia();

    connect(editMedia, &EditMedia::onApply, this, &MainWindow::onMediaCreated);
    editMedia->setWindowTitle("Edit Media");
    editMedia->setWindowModality(Qt::ApplicationModal);
    editMedia->setFocus();

    editMedia->show();
}

void MainWindow::onMediaCreated(AbstractMedia* media) {
    //logic to add media to container
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

void MainWindow::showMediaWidget(const std::string& name){
    ConcreteVisitor* visitor = new ConcreteVisitor();
    qDebug() << name << " button clicked!";
    for(auto it = container->begin(); it != container->end(); ++it){
        qDebug() << "Comparing:" << QString::fromStdString(name) << "with" << (*it)->getName();
        if(name==(*it)->getName()){
            qDebug() << name << "Works";
            (*it)->accept(visitor);
            mediaWidget->show(visitor);
            update();
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

void MainWindow::update(){
    if(!mediaWidget->isActiveWindow() && HSplitter->indexOf(mediaWidget) == -1)
        HSplitter->addWidget(mediaWidget);

}

void MainWindow::showError(const QString &message) {
    QMessageBox::critical(
        this,                     // Parent widget (use this if inside a window)
        "Error",                   // Title of the popup window
        message,                   // The error message
        QMessageBox::Ok            // Button (Ok button to close the popup)
        );
}

