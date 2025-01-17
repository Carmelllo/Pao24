#include "listwidgetelement.h"
#include "ui_listwidgetelement.h"

ListWidgetElement::ListWidgetElement(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListWidgetElement)
{
    ui->setupUi(this);

}

ListWidgetElement::~ListWidgetElement()
{
    delete ui;
}

void ListWidgetElement::onMediaAdded(const QPixmap& img, const std::string & lab){

    ui->label->setPixmap(img);
    ui->label->setScaledContents(true);
    ui->label_2->setText(QString::fromStdString(lab));
}

QString ListWidgetElement::getName(){
    return ui->label_2->text();
}
