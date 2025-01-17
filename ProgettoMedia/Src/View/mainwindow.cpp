#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchbar.h"
#include <QVBoxLayout>
#include <QSplitter>

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

    list = new MediaListWidget();

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
    connect(list, &MediaListWidget::addClick, this, &MainWindow::showEdit);
    connect(editMediaWidget, &EditMedia::onApply, this, &MainWindow::onMediaCreated);

    container = new Container();
    searchContainer = new Container();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEdit() {
    editMediaWidget->setWindowTitle("Edit Media");
    editMediaWidget->setWindowModality(Qt::ApplicationModal);
    editMediaWidget->setFocus();

    editMediaWidget->show();
}

void MainWindow::onMediaCreated(AbstractMedia* media) {
    //logic to add sensor to container
    for(auto it = container->begin(); it != container->end(); ++it){
        if(media->getName()==(*it)->getName()){
            return;
        }
    }
    container->add(media);
    list->showWidgets(container, visitor);
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
    if(!mediaWidget->isActiveWindow())
        HSplitter->addWidget(mediaWidget);

    HSplitter->replaceWidget(2,mediaWidget);


}

