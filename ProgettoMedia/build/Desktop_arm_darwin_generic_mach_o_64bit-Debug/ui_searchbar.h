/********************************************************************************
** Form generated from reading UI file 'searchbar.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBAR_H
#define UI_SEARCHBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchBar
{
public:
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *SearchBar)
    {
        if (SearchBar->objectName().isEmpty())
            SearchBar->setObjectName("SearchBar");
        SearchBar->resize(845, 114);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearchBar->sizePolicy().hasHeightForWidth());
        SearchBar->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(SearchBar);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        frame = new QFrame(SearchBar);
        frame->setObjectName("frame");
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(600, 50));
        frame->setMaximumSize(QSize(600, 50));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_5->addWidget(lineEdit);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");

        horizontalLayout_5->addWidget(pushButton);


        horizontalLayout_4->addWidget(frame);


        retranslateUi(SearchBar);

        QMetaObject::connectSlotsByName(SearchBar);
    } // setupUi

    void retranslateUi(QWidget *SearchBar)
    {
        SearchBar->setWindowTitle(QCoreApplication::translate("SearchBar", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("SearchBar", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchBar: public Ui_SearchBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBAR_H
