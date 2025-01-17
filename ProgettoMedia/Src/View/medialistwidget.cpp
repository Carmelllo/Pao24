#include "medialistwidget.h"
#include "Src/Media/abstractmedia.h"
#include "ui_medialistwidget.h"
#include "listwidgetelement.h"
#include "Src/Container/container.h"



MediaListWidget::MediaListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaListWidget)
{
    ui->setupUi(this);
    connect(ui->addbutton, &QPushButton::clicked, this, &MediaListWidget::onAddButtonClicked);
}

MediaListWidget::~MediaListWidget()
{
    delete ui;
}

void MediaListWidget::onAddButtonClicked() {
    emit addClick();
}



void MediaListWidget::addWidget(const QPixmap& img, const std::string &s){

    bool found = false;
    for (auto* it : listElementWidgets) {
        if (it->getName().toStdString() == s) {
            found = true;
            return;
        }
    }
    if(!found){
    ListWidgetElement* elementWidget = new ListWidgetElement();

    listElementWidgets.push_back(elementWidget);

    elementWidget->onMediaAdded(img , s);

    QListWidgetItem* listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(356, 180));

    ui->listWidget->addItem(listItem);

    ui->listWidget->setItemWidget(listItem, elementWidget);
    }
}

void MediaListWidget::showWidgets(Container * container){
    for(auto it = container->begin();it!= container->end(); ++it)
    {
        addWidget((*it)->getImage() , (*it)->getName());
    }
}

void MediaListWidget::refresh(){

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem* item = ui->listWidget->takeItem(i);
        QWidget* widget = ui->listWidget->itemWidget(item);
        delete widget;
        delete item;
    }
    ui->listWidget->clear();

    listElementWidgets.clear();
}

