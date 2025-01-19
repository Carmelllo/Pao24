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
    QVBoxLayout *Labels;
    QHBoxLayout *Buttons;

    void setupUi(QWidget *MediaWidget)
    {
        if (MediaWidget->objectName().isEmpty())
            MediaWidget->setObjectName("MediaWidget");
        MediaWidget->resize(500, 315);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
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

        horizontalLayout_3->addLayout(ImageLayout);

        Labels = new QVBoxLayout();
        Labels->setObjectName("Labels");
        Buttons = new QHBoxLayout();
        Buttons->setObjectName("Buttons");

        Labels->addLayout(Buttons);


        horizontalLayout_3->addLayout(Labels);


        horizontalLayout_2->addWidget(frame);


        retranslateUi(MediaWidget);

        QMetaObject::connectSlotsByName(MediaWidget);
    } // setupUi

    void retranslateUi(QWidget *MediaWidget)
    {
        MediaWidget->setWindowTitle(QCoreApplication::translate("MediaWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MediaWidget: public Ui_MediaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAWIDGET_H
