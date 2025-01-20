/********************************************************************************
** Form generated from reading UI file 'medialistwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIALISTWIDGET_H
#define UI_MEDIALISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MediaListWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QPushButton *addbutton;

    void setupUi(QWidget *MediaListWidget)
    {
        if (MediaListWidget->objectName().isEmpty())
            MediaListWidget->setObjectName(QString::fromUtf8("MediaListWidget"));
        MediaListWidget->resize(400, 615);
        MediaListWidget->setMinimumSize(QSize(300, 600));
        verticalLayout = new QVBoxLayout(MediaListWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(MediaListWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 0));
        frame->setMaximumSize(QSize(9999999, 999999));
        frame->setBaseSize(QSize(300, 300));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout_2->addLayout(horizontalLayout);

        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        addbutton = new QPushButton(frame);
        addbutton->setObjectName(QString::fromUtf8("addbutton"));

        verticalLayout_2->addWidget(addbutton);


        verticalLayout->addWidget(frame);


        retranslateUi(MediaListWidget);

        QMetaObject::connectSlotsByName(MediaListWidget);
    } // setupUi

    void retranslateUi(QWidget *MediaListWidget)
    {
        MediaListWidget->setWindowTitle(QCoreApplication::translate("MediaListWidget", "Form", nullptr));
        addbutton->setText(QCoreApplication::translate("MediaListWidget", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MediaListWidget: public Ui_MediaListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIALISTWIDGET_H
