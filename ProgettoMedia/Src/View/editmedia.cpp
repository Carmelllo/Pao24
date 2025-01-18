#include "editmedia.h"
#include "ui_editmedia.h"
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QMessageBox>
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


void EditMedia::showEditWindow(){
    setWindowTitle("Edit Media");
    setWindowModality(Qt::ApplicationModal);
    setFocus();

    show();
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

    AbstractMedia * media;
    QString name = ui->name->text();
    QString author = ui->author->text();
    QString description = ui->description->toPlainText();
    unsigned int year = ui->year->value();
    QPixmap picture = ui->imageLabel->pixmap();


    if (ui->comboBox->currentIndex() == 0){// Book
            media = new BookMedia(
            name.toStdString(),
            year,
            author.toStdString(),
            description.toStdString(),
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
            description.toStdString(),
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
            description.toStdString(),
            picture,
            (ui->length->time().minute() + ( ui->length->time().hour() * 60 )),
            (ui->director->text()).toStdString(),
            (ui->studio->text()).toStdString());

    }

    emit onApply(media);

    if (ui->imageLabel) {
        ui->imageLabel->clear();
    }
    ui->imageStackedWidget->setCurrentIndex(0);

    close();
}
void EditMedia::onApplyEditButtonClicked(ConcreteVisitor* visitor) {
    const ConcreteVisitor::Attributes& attributes = visitor->getAttributes();


    ui->name->setText(QString::fromStdString(attributes.name));
    ui->year->setValue(std::stoi(attributes.year));
    ui->author->setText(QString::fromStdString(attributes.author));
    ui->imageLabel->setPixmap(attributes.img);

    if (ui->comboBox->currentIndex() == 0){// Book

        ui->pages->setValue(std::stoi(attributes.details.at("Pages")));
        ui->publisher->setText(QString::fromStdString(attributes.details.at("Publisher")));
        ui->genre->setText(QString::fromStdString(attributes.details.at("Genre")));
    }
    if (ui->comboBox->currentIndex() == 1){// Article

        ui->volume->setValue(std::stoi(attributes.details.at("Volume")));
        ui->issue->setValue(std::stoi(attributes.details.at("Issue")));
        ui->journal->setText(QString::fromStdString(attributes.details.at("Journal")));
    }
    if (ui->comboBox->currentIndex() == 3){// Movie

        int totalMinutes = std::stoi(attributes.details.at("Length"));
        int hours = totalMinutes / 60;
        int minutes = totalMinutes % 60;

        QTime time(hours, minutes);

        ui->length->setTime(time);
        ui->director->setText(QString::fromStdString(attributes.details.at("Director")));
        ui->studio->setText(QString::fromStdString(attributes.details.at("Studio")));
    }



}

