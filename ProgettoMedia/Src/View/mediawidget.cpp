#include "mediawidget.h"
#include "ui_mediawidget.h"

MediaWidget::MediaWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MediaWidget)
{
    ui->setupUi(this);

}

MediaWidget::~MediaWidget()
{
    delete ui;
}


void MediaWidget::showMedia(ConcreteVisitor* visitor) {

    clearUI(ui->Labels);
    clearUI(ui->ImageLayout);

    const ConcreteVisitor::Attributes& attributes = visitor->getAttributes();

    widgetName = attributes.name;

    QLabel* name = new QLabel("Name: " + QString::fromStdString(attributes.name));
    QLabel* year = new QLabel("Year: " + QString::fromStdString(attributes.year));
    QLabel* author = new QLabel("Author: " + QString::fromStdString(attributes.author));
    QPushButton* edit = new QPushButton();
    edit->setText("Edit");
    QPushButton* remove = new QPushButton();
    remove->setText("Remove");
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(edit);
    buttonsLayout->addWidget(remove);
    QLabel* image = new QLabel();
    image->setFixedSize(170, 210);
    image->setPixmap(attributes.img);
    image->setScaledContents(true);

    ui->Labels->addWidget(name);
    ui->Labels->addWidget(year);
    ui->Labels->addWidget(author);
    ui->ImageLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    ui->ImageLayout->addWidget(image);

    for (const auto& [key, value] : attributes.details) {
        QLabel* label_detail = new QLabel(QString::fromStdString(key + ": " + value), this);
        ui->Labels->addWidget(label_detail);
    }
    ui->Labels->addLayout(buttonsLayout);
    connect(remove,&QPushButton::clicked ,this , &MediaWidget::onRemoveClicked);
    connect(edit,&QPushButton::clicked ,this , &MediaWidget::onEditClicked);

}
void MediaWidget::onRemoveClicked(){
    emit onRemove(widgetName);
}
void MediaWidget::onEditClicked(){
    emit onEdit(widgetName);
}


void MediaWidget::clearUI(QLayout* layout) {
    if (!layout) return;

    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            // If it's a widget, remove it from the layout and schedule for deletion
            widget->setParent(nullptr);
            widget->deleteLater();
        } else if (QLayout* childLayout = item->layout()) {
            // If it's a nested layout, recursively clear it
            clearUI(childLayout);
        }
        delete item; // Delete the layout item
    }
}
