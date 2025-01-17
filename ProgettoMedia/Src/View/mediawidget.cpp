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


