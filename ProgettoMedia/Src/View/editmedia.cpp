#include "editmedia.h"
#include "ui_editmedia.h"
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QMessageBox>
#include "Src/Container/container.h"
#include "Src/Media/bookmedia.h"
#include "Src/Media/articlemedia.h"
#include "Src/Media/moviemedia.h"
#include "Src/Converter/converter.h"

EditMedia::EditMedia(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EditMedia)
{
    ui->setupUi(this);
    connect(ui->comboBox,qOverload<int>(&QComboBox::currentIndexChanged) ,this , &EditMedia::changeView);
    connect(ui->confirmationBtns, &QDialogButtonBox::rejected ,this, &EditMedia::close);//sistema upload
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

    AbstractMedia * media = nullptr;
    QString name = ui->name->text();
    QString author = ui->author->text();
    QString description = ui->description->toPlainText();
    unsigned int year = ui->year->value();
    QPixmap picture = ui->imageLabel->pixmap();

    std::string imagePath = Converter::convertPixmapToPath(picture);



    if (ui->comboBox->currentIndex() == 0){// Libro
            media = new BookMedia(
            name.toStdString(),
            year,
            author.toStdString(),
            description.toStdString(),
            imagePath,
            ui->pages->text().toUInt(),
            (ui->publisher->text()).toStdString(),
            (ui->genre->text()).toStdString());


    }

    if (ui->comboBox->currentIndex()== 1){// Articolo
        media = new ArticleMedia(
            name.toStdString(),
            year,
            author.toStdString(),
            description.toStdString(),
            imagePath,
            ui->volume->value(),
            ui->issue->value(),
            (ui->journal->text()).toStdString()
            );


    }

    if (ui->comboBox->currentIndex() == 2){// Film
            media = new MovieMedia(
            name.toStdString(),
            year,
            author.toStdString(),
            description.toStdString(),
            imagePath,
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
void EditMedia::showEditMedia(ConcreteVisitor* visitor) {
    const ConcreteVisitor::Attributes& attributes = visitor->getAttributes();


    ui->name->setText(QString::fromStdString(attributes.name));
    ui->year->setValue(std::stoi(attributes.year));
    ui->author->setText(QString::fromStdString(attributes.author));
    ui->imageLabel->setPixmap (Converter::convertPathToPixmap(attributes.img));
    ui->description->setText(QString::fromStdString(attributes.description));

    if (attributes.details.find("Pages") != attributes.details.end()) {
        ui->comboBox->setCurrentIndex(0);
    } else if (attributes.details.find("Volume") != attributes.details.end()) {
        ui->comboBox->setCurrentIndex(1);
    } else if (attributes.details.find("Length") != attributes.details.end()) {
        ui->comboBox->setCurrentIndex(2);
    }


    if (ui->comboBox->currentIndex() == 0) {// Libro
        auto pagesIter = attributes.details.find("Pages");
        auto publisherIter = attributes.details.find("Publisher");
        auto genreIter = attributes.details.find("Genre");

        ui->pages->setValue((pagesIter != attributes.details.end()) ? std::stoi(pagesIter->second) : 0);
        ui->publisher->setText((publisherIter != attributes.details.end()) ? QString::fromStdString(publisherIter->second) : "Unknown");
        ui->genre->setText((genreIter != attributes.details.end()) ? QString::fromStdString(genreIter->second) : "Unknown");
    }

    if (ui->comboBox->currentIndex() == 1) {// Articolo
        auto volumeIter = attributes.details.find("Volume");
        auto issueIter = attributes.details.find("Issue");
        auto journalIter = attributes.details.find("Journal");

        ui->volume->setValue((volumeIter != attributes.details.end()) ? std::stoi(volumeIter->second) : 0);
        ui->issue->setValue((issueIter != attributes.details.end()) ? std::stoi(issueIter->second) : 0);
        ui->journal->setText((journalIter != attributes.details.end()) ? QString::fromStdString(journalIter->second) : "Unknown");
    }

    if (ui->comboBox->currentIndex() == 2) {// Film
        auto lengthIter = attributes.details.find("Length");
        auto directorIter = attributes.details.find("Director");
        auto studioIter = attributes.details.find("Studio");

        int totalMinutes = (lengthIter != attributes.details.end()) ? std::stoi(lengthIter->second) : 0;
        int hours = totalMinutes / 60;
        int minutes = totalMinutes % 60;

        QTime time(hours, minutes);

        ui->length->setTime(time);
        ui->director->setText((directorIter != attributes.details.end()) ? QString::fromStdString(directorIter->second) : "Unknown");
        ui->studio->setText((studioIter != attributes.details.end()) ? QString::fromStdString(studioIter->second) : "Unknown");
    }

    QPushButton* cancelButton = ui->confirmationBtns->button(QDialogButtonBox::Cancel);
    if (cancelButton) {
        cancelButton->hide();
    }
}



