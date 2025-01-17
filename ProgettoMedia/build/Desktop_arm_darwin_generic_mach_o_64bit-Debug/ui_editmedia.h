/********************************************************************************
** Form generated from reading UI file 'editmedia.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITMEDIA_H
#define UI_EDITMEDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditMedia
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *nameLayout;
    QLabel *label_2;
    QLineEdit *name;
    QHBoxLayout *categoryLayout;
    QLabel *label;
    QComboBox *comboBox;
    QStackedWidget *infoStackedWidget;
    QWidget *page;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *pagesLayout;
    QLabel *label_8;
    QSpinBox *pages;
    QHBoxLayout *publisherLayout;
    QLabel *label_9;
    QLineEdit *publisher;
    QHBoxLayout *genreLayout;
    QLabel *label_10;
    QLineEdit *genre;
    QWidget *page_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *volumeLayout;
    QLabel *label_5;
    QSpinBox *volume;
    QHBoxLayout *issueLayout;
    QLabel *label_6;
    QSpinBox *issue;
    QHBoxLayout *journalLayout;
    QLabel *label_7;
    QLineEdit *journal;
    QWidget *page_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *lengthLayout;
    QLabel *label_11;
    QTimeEdit *length;
    QHBoxLayout *directorLayout;
    QLabel *label_12;
    QLineEdit *director;
    QHBoxLayout *studioLayout;
    QLabel *label_13;
    QLineEdit *studio;
    QHBoxLayout *authorLayout;
    QLabel *label_4;
    QLineEdit *author;
    QHBoxLayout *yearLayout;
    QLabel *label_3;
    QSpinBox *year;
    QHBoxLayout *horizontalLayout;
    QLabel *label_14;
    QTextEdit *description;
    QDialogButtonBox *confirmationBtns;
    QStackedWidget *imageStackedWidget;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *uploadBtn;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *imageLabel;
    QPushButton *reuploadBtn;

    void setupUi(QWidget *EditMedia)
    {
        if (EditMedia->objectName().isEmpty())
            EditMedia->setObjectName("EditMedia");
        EditMedia->resize(550, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditMedia->sizePolicy().hasHeightForWidth());
        EditMedia->setSizePolicy(sizePolicy);
        EditMedia->setMinimumSize(QSize(550, 600));
        EditMedia->setMaximumSize(QSize(550, 600));
        gridLayout = new QGridLayout(EditMedia);
        gridLayout->setObjectName("gridLayout");
        nameLayout = new QHBoxLayout();
        nameLayout->setObjectName("nameLayout");
        label_2 = new QLabel(EditMedia);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        nameLayout->addWidget(label_2);

        name = new QLineEdit(EditMedia);
        name->setObjectName("name");
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        name->setMinimumSize(QSize(250, 0));
        name->setMaximumSize(QSize(250, 16777215));

        nameLayout->addWidget(name);


        gridLayout->addLayout(nameLayout, 1, 0, 1, 1);

        categoryLayout = new QHBoxLayout();
        categoryLayout->setObjectName("categoryLayout");
        label = new QLabel(EditMedia);
        label->setObjectName("label");
        label->setLineWidth(1);
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        categoryLayout->addWidget(label);

        comboBox = new QComboBox(EditMedia);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(250, 0));
        comboBox->setMaximumSize(QSize(250, 16777215));
        comboBox->setInsertPolicy(QComboBox::InsertPolicy::InsertAtBottom);

        categoryLayout->addWidget(comboBox);


        gridLayout->addLayout(categoryLayout, 0, 0, 1, 1);

        infoStackedWidget = new QStackedWidget(EditMedia);
        infoStackedWidget->setObjectName("infoStackedWidget");
        infoStackedWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(infoStackedWidget->sizePolicy().hasHeightForWidth());
        infoStackedWidget->setSizePolicy(sizePolicy1);
        infoStackedWidget->setMinimumSize(QSize(311, 160));
        infoStackedWidget->setMaximumSize(QSize(350, 150));
        infoStackedWidget->setFrameShape(QFrame::Shape::NoFrame);
        infoStackedWidget->setFrameShadow(QFrame::Shadow::Plain);
        page = new QWidget();
        page->setObjectName("page");
        verticalLayoutWidget_5 = new QWidget(page);
        verticalLayoutWidget_5->setObjectName("verticalLayoutWidget_5");
        verticalLayoutWidget_5->setGeometry(QRect(0, 0, 331, 161));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pagesLayout = new QHBoxLayout();
        pagesLayout->setObjectName("pagesLayout");
        label_8 = new QLabel(verticalLayoutWidget_5);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        pagesLayout->addWidget(label_8);

        pages = new QSpinBox(verticalLayoutWidget_5);
        pages->setObjectName("pages");
        pages->setMinimumSize(QSize(250, 0));
        pages->setMaximumSize(QSize(16777215, 16777215));
        pages->setMaximum(9999);

        pagesLayout->addWidget(pages);


        verticalLayout_2->addLayout(pagesLayout);

        publisherLayout = new QHBoxLayout();
        publisherLayout->setObjectName("publisherLayout");
        label_9 = new QLabel(verticalLayoutWidget_5);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        publisherLayout->addWidget(label_9);

        publisher = new QLineEdit(verticalLayoutWidget_5);
        publisher->setObjectName("publisher");
        publisher->setMinimumSize(QSize(0, 0));
        publisher->setMaximumSize(QSize(250, 16777215));

        publisherLayout->addWidget(publisher);


        verticalLayout_2->addLayout(publisherLayout);

        genreLayout = new QHBoxLayout();
        genreLayout->setObjectName("genreLayout");
        label_10 = new QLabel(verticalLayoutWidget_5);
        label_10->setObjectName("label_10");
        label_10->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        genreLayout->addWidget(label_10);

        genre = new QLineEdit(verticalLayoutWidget_5);
        genre->setObjectName("genre");
        genre->setMinimumSize(QSize(0, 0));
        genre->setMaximumSize(QSize(250, 16777215));

        genreLayout->addWidget(genre);


        verticalLayout_2->addLayout(genreLayout);

        infoStackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayoutWidget = new QWidget(page_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 331, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        volumeLayout = new QHBoxLayout();
        volumeLayout->setObjectName("volumeLayout");
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        volumeLayout->addWidget(label_5);

        volume = new QSpinBox(verticalLayoutWidget);
        volume->setObjectName("volume");
        volume->setMinimumSize(QSize(250, 0));
        volume->setMaximumSize(QSize(16777215, 16777215));
        volume->setMaximum(999);

        volumeLayout->addWidget(volume);


        verticalLayout->addLayout(volumeLayout);

        issueLayout = new QHBoxLayout();
        issueLayout->setObjectName("issueLayout");
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        issueLayout->addWidget(label_6);

        issue = new QSpinBox(verticalLayoutWidget);
        issue->setObjectName("issue");
        issue->setMinimumSize(QSize(250, 0));
        issue->setMaximumSize(QSize(16777215, 16777215));
        issue->setMaximum(9999);

        issueLayout->addWidget(issue);


        verticalLayout->addLayout(issueLayout);

        journalLayout = new QHBoxLayout();
        journalLayout->setObjectName("journalLayout");
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        journalLayout->addWidget(label_7);

        journal = new QLineEdit(verticalLayoutWidget);
        journal->setObjectName("journal");
        journal->setMinimumSize(QSize(0, 0));
        journal->setMaximumSize(QSize(250, 16777215));

        journalLayout->addWidget(journal);


        verticalLayout->addLayout(journalLayout);

        infoStackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayoutWidget_2 = new QWidget(page_3);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 331, 161));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lengthLayout = new QHBoxLayout();
        lengthLayout->setObjectName("lengthLayout");
        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName("label_11");

        lengthLayout->addWidget(label_11);

        length = new QTimeEdit(verticalLayoutWidget_2);
        length->setObjectName("length");
        length->setMinimumSize(QSize(250, 0));
        length->setMaximumSize(QSize(250, 16777215));

        lengthLayout->addWidget(length);


        verticalLayout_4->addLayout(lengthLayout);

        directorLayout = new QHBoxLayout();
        directorLayout->setObjectName("directorLayout");
        label_12 = new QLabel(verticalLayoutWidget_2);
        label_12->setObjectName("label_12");

        directorLayout->addWidget(label_12);

        director = new QLineEdit(verticalLayoutWidget_2);
        director->setObjectName("director");
        director->setMaximumSize(QSize(250, 16777215));

        directorLayout->addWidget(director);


        verticalLayout_4->addLayout(directorLayout);

        studioLayout = new QHBoxLayout();
        studioLayout->setObjectName("studioLayout");
        label_13 = new QLabel(verticalLayoutWidget_2);
        label_13->setObjectName("label_13");

        studioLayout->addWidget(label_13);

        studio = new QLineEdit(verticalLayoutWidget_2);
        studio->setObjectName("studio");
        studio->setMinimumSize(QSize(250, 0));
        studio->setMaximumSize(QSize(250, 16777215));

        studioLayout->addWidget(studio);


        verticalLayout_4->addLayout(studioLayout);

        infoStackedWidget->addWidget(page_3);

        gridLayout->addWidget(infoStackedWidget, 5, 0, 1, 1);

        authorLayout = new QHBoxLayout();
        authorLayout->setObjectName("authorLayout");
        label_4 = new QLabel(EditMedia);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        authorLayout->addWidget(label_4);

        author = new QLineEdit(EditMedia);
        author->setObjectName("author");
        sizePolicy.setHeightForWidth(author->sizePolicy().hasHeightForWidth());
        author->setSizePolicy(sizePolicy);
        author->setMinimumSize(QSize(250, 0));
        author->setMaximumSize(QSize(250, 16777215));

        authorLayout->addWidget(author);


        gridLayout->addLayout(authorLayout, 3, 0, 1, 1);

        yearLayout = new QHBoxLayout();
        yearLayout->setObjectName("yearLayout");
        label_3 = new QLabel(EditMedia);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(100, 16777215));
        label_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        yearLayout->addWidget(label_3);

        year = new QSpinBox(EditMedia);
        year->setObjectName("year");
        sizePolicy.setHeightForWidth(year->sizePolicy().hasHeightForWidth());
        year->setSizePolicy(sizePolicy);
        year->setMinimumSize(QSize(250, 0));
        year->setMaximumSize(QSize(250, 16777215));
        year->setMaximum(9999);
        year->setSingleStep(1);
        year->setValue(2025);

        yearLayout->addWidget(year);


        gridLayout->addLayout(yearLayout, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_14 = new QLabel(EditMedia);
        label_14->setObjectName("label_14");
        label_14->setLineWidth(1);
        label_14->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop|Qt::AlignmentFlag::AlignTrailing);

        horizontalLayout->addWidget(label_14);

        description = new QTextEdit(EditMedia);
        description->setObjectName("description");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy2);
        description->setMaximumSize(QSize(16777215, 100));

        horizontalLayout->addWidget(description);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        confirmationBtns = new QDialogButtonBox(EditMedia);
        confirmationBtns->setObjectName("confirmationBtns");
        confirmationBtns->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        gridLayout->addWidget(confirmationBtns, 6, 1, 1, 1);

        imageStackedWidget = new QStackedWidget(EditMedia);
        imageStackedWidget->setObjectName("imageStackedWidget");
        sizePolicy.setHeightForWidth(imageStackedWidget->sizePolicy().hasHeightForWidth());
        imageStackedWidget->setSizePolicy(sizePolicy);
        imageStackedWidget->setMaximumSize(QSize(170, 300));
        imageStackedWidget->setFrameShape(QFrame::Shape::NoFrame);
        imageStackedWidget->setFrameShadow(QFrame::Shadow::Plain);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        verticalLayout_3 = new QVBoxLayout(page_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        uploadBtn = new QPushButton(page_4);
        uploadBtn->setObjectName("uploadBtn");

        verticalLayout_3->addWidget(uploadBtn);

        imageStackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        verticalLayout_5 = new QVBoxLayout(page_5);
        verticalLayout_5->setObjectName("verticalLayout_5");
        imageLabel = new QLabel(page_5);
        imageLabel->setObjectName("imageLabel");
        sizePolicy.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy);
        imageLabel->setMinimumSize(QSize(120, 210));
        imageLabel->setMaximumSize(QSize(150, 210));
        imageLabel->setStyleSheet(QString::fromUtf8(""));
        imageLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(imageLabel);

        reuploadBtn = new QPushButton(page_5);
        reuploadBtn->setObjectName("reuploadBtn");

        verticalLayout_5->addWidget(reuploadBtn);

        imageStackedWidget->addWidget(page_5);

        gridLayout->addWidget(imageStackedWidget, 0, 1, 6, 1);


        retranslateUi(EditMedia);

        infoStackedWidget->setCurrentIndex(0);
        imageStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EditMedia);
    } // setupUi

    void retranslateUi(QWidget *EditMedia)
    {
        EditMedia->setWindowTitle(QCoreApplication::translate("EditMedia", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("EditMedia", "Name", nullptr));
        name->setText(QString());
        name->setPlaceholderText(QCoreApplication::translate("EditMedia", "Type media name", nullptr));
        label->setText(QCoreApplication::translate("EditMedia", "Category", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("EditMedia", "Book", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("EditMedia", "Article", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("EditMedia", "Movie", nullptr));

        label_8->setText(QCoreApplication::translate("EditMedia", "Pages", nullptr));
        label_9->setText(QCoreApplication::translate("EditMedia", "Publisher", nullptr));
        publisher->setPlaceholderText(QCoreApplication::translate("EditMedia", "Type Publisher", nullptr));
        label_10->setText(QCoreApplication::translate("EditMedia", "Genre", nullptr));
        genre->setPlaceholderText(QCoreApplication::translate("EditMedia", "Type the genre", nullptr));
        label_5->setText(QCoreApplication::translate("EditMedia", "Volume", nullptr));
        label_6->setText(QCoreApplication::translate("EditMedia", "Issue", nullptr));
        label_7->setText(QCoreApplication::translate("EditMedia", "Journal", nullptr));
        journal->setPlaceholderText(QCoreApplication::translate("EditMedia", "Type the Journal's name", nullptr));
        label_11->setText(QCoreApplication::translate("EditMedia", "Length", nullptr));
        label_12->setText(QCoreApplication::translate("EditMedia", "Director", nullptr));
        label_13->setText(QCoreApplication::translate("EditMedia", "Studio", nullptr));
        label_4->setText(QCoreApplication::translate("EditMedia", "Author", nullptr));
        author->setPlaceholderText(QCoreApplication::translate("EditMedia", "Type author's name", nullptr));
        label_3->setText(QCoreApplication::translate("EditMedia", "Year", nullptr));
        label_14->setText(QCoreApplication::translate("EditMedia", "Description", nullptr));
        uploadBtn->setText(QCoreApplication::translate("EditMedia", "Upload Image", nullptr));
        imageLabel->setText(QString());
        reuploadBtn->setText(QCoreApplication::translate("EditMedia", "Upload Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditMedia: public Ui_EditMedia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITMEDIA_H
