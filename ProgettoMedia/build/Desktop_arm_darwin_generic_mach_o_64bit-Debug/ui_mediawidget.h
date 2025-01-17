/********************************************************************************
** Form generated from reading UI file 'mediawidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAWIDGET_H
#define UI_MEDIAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MediaWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *ImageLayout;
    QLabel *image;
    QVBoxLayout *Labels;
    QLabel *name;
    QLabel *year;
    QLabel *author;
    QLabel *empty1;
    QLabel *empty2;
    QLabel *empty3;
    QHBoxLayout *Buttons;
    QPushButton *edit;
    QPushButton *delete_2;

    void setupUi(QWidget *MediaWidget)
    {
        if (MediaWidget->objectName().isEmpty())
            MediaWidget->setObjectName("MediaWidget");
        MediaWidget->resize(500, 315);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MediaWidget->sizePolicy().hasHeightForWidth());
        MediaWidget->setSizePolicy(sizePolicy);
        MediaWidget->setMinimumSize(QSize(500, 0));
        MediaWidget->setMaximumSize(QSize(1000, 16777215));
        horizontalLayout_2 = new QHBoxLayout(MediaWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        frame = new QFrame(MediaWidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(4, 0));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        ImageLayout = new QVBoxLayout();
        ImageLayout->setObjectName("ImageLayout");
        image = new QLabel(frame);
        image->setObjectName("image");
        image->setMinimumSize(QSize(170, 210));
        image->setMaximumSize(QSize(170, 210));
        image->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 224, 159)"));
        image->setFrameShape(QFrame::Shape::Box);
        image->setFrameShadow(QFrame::Shadow::Raised);
        image->setLineWidth(2);
        image->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing);
        image->setWordWrap(false);

        ImageLayout->addWidget(image);


        horizontalLayout_3->addLayout(ImageLayout);

        Labels = new QVBoxLayout();
        Labels->setObjectName("Labels");
        name = new QLabel(frame);
        name->setObjectName("name");

        Labels->addWidget(name);

        year = new QLabel(frame);
        year->setObjectName("year");

        Labels->addWidget(year);

        author = new QLabel(frame);
        author->setObjectName("author");

        Labels->addWidget(author);

        empty1 = new QLabel(frame);
        empty1->setObjectName("empty1");

        Labels->addWidget(empty1);

        empty2 = new QLabel(frame);
        empty2->setObjectName("empty2");

        Labels->addWidget(empty2);

        empty3 = new QLabel(frame);
        empty3->setObjectName("empty3");

        Labels->addWidget(empty3);

        Buttons = new QHBoxLayout();
        Buttons->setObjectName("Buttons");
        edit = new QPushButton(frame);
        edit->setObjectName("edit");

        Buttons->addWidget(edit);

        delete_2 = new QPushButton(frame);
        delete_2->setObjectName("delete_2");

        Buttons->addWidget(delete_2);


        Labels->addLayout(Buttons);


        horizontalLayout_3->addLayout(Labels);


        horizontalLayout_2->addWidget(frame);


        retranslateUi(MediaWidget);

        QMetaObject::connectSlotsByName(MediaWidget);
    } // setupUi

    void retranslateUi(QWidget *MediaWidget)
    {
        MediaWidget->setWindowTitle(QCoreApplication::translate("MediaWidget", "Form", nullptr));
        image->setText(QString());
        name->setText(QCoreApplication::translate("MediaWidget", "Name:", nullptr));
        year->setText(QCoreApplication::translate("MediaWidget", "Year:", nullptr));
        author->setText(QCoreApplication::translate("MediaWidget", "Author", nullptr));
        empty1->setText(QCoreApplication::translate("MediaWidget", "TBA:", nullptr));
        empty2->setText(QCoreApplication::translate("MediaWidget", "TBA:", nullptr));
        empty3->setText(QCoreApplication::translate("MediaWidget", "TBA:", nullptr));
        edit->setText(QCoreApplication::translate("MediaWidget", "Edit", nullptr));
        delete_2->setText(QCoreApplication::translate("MediaWidget", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MediaWidget: public Ui_MediaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAWIDGET_H
