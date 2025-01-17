#include "editmedia.h"
#include "ui_editmedia.h"
#include <QDialogButtonBox>
#include <QFileDialog>
#include "Src/Container/container.h"
#include "Src/Media/bookmedia.h"
#include "Src/Media/articlemedia.h"
#include "Src/Media/moviemedia.h"

EditMedia::EditMedia(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EditMedia)
{
    ui->setupUi(this);
    connect(ui->comboBox,qOverload<int>(&QComboBox::currentIndexChanged) ,this , &EditMedia::changeView);
    connect(ui->confirmationBtns, &QDialogButtonBox::rejected ,this, &EditMedia::close );
    connect(ui->uploadBtn, &QPushButton::clicked ,this, &EditMedia::uploadImage);
    connect(ui->reuploadBtn, &QPushButton::clicked ,this, &EditMedia::uploadImage);
    connect(ui->confirmationBtns, &QDialogButtonBox::accepted ,this, &EditMedia::onApplyButtonClicked);

}

EditMedia::~EditMedia()
{
    delete ui;
}

void EditMedia::changeView(int index)
{
    ui->infoStackedWidget->setCurrentIndex(index);
}

void EditMedia::uploadImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select an Image", "", "Images (*.png *.jpg *.bmp *.jpeg)");

    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        ui->imageLabel->setPixmap(pixmap);
        ui->imageLabel->setScaledContents(true);
        ui->imageStackedWidget->setCurrentIndex(1);
    }
}

void EditMedia::onApplyButtonClicked() {

    ui->imageStackedWidget->setCurrentIndex(0);

    AbstractMedia * media = nullptr;
    QString name = ui->name->text();
    QString author = ui->author->text();
    QString description = ui->description->toPlainText();
    qDebug() << description;
    unsigned int year = ui->year->value();
    QPixmap picture = ui->imageLabel->pixmap();


    if (ui->comboBox->currentIndex() == 0){// Book
            media = new BookMedia(
            name.toStdString(),
            year,
            author.toStdString(),
            picture,
            ui->pages->text().toUInt(),
            (ui->publisher->text()).toStdString(),
            (ui->genre->text()).toStdString());

    }

    if (ui->comboBox->currentIndex() == 1){// Article
            media = new ArticleMedia(
            name.toStdString(),
            year,
            author.toStdString(),
            picture,
            ui->volume->value(),
            ui->issue->value()),
            (ui->journal->text()).toStdString();

    }

    if (ui->comboBox->currentIndex() == 2){// Movie
            media = new MovieMedia(
            name.toStdString(),
            year,
            author.toStdString(),
            picture,
            double(ui->length->time().minute() + ( ui->length->time().hour() * 60 )),
            (ui->director->text()).toStdString(),
            (ui->studio->text()).toStdString());

    }

    emit onApply(media);
    close();
}
