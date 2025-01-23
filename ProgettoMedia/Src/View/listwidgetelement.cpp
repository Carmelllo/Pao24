#include "listwidgetelement.h"
#include "ui_listwidgetelement.h"

ListWidgetElement::ListWidgetElement(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListWidgetElement)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &ListWidgetElement::onInspect);
}

ListWidgetElement::~ListWidgetElement()
{
    delete ui;
}

void ListWidgetElement::onMediaAdded(const QPixmap& img, const std::string & name, const std::string & desc){

    ui->image->setPixmap(img);
    ui->image->setScaledContents(true);
    ui->nameLabel->setText(QString::fromStdString(name));

    ui->descriptionLabel->setText("Description:\n" + (QString::fromStdString(desc)));
    ui->descriptionLabel->setWordWrap(true);

}

QString ListWidgetElement::getName() const{
    return ui->nameLabel->text();
}

void ListWidgetElement::onInspect(){
        std::string name = ui->nameLabel->text().toStdString();
        emit inspectClicked(name);
}
