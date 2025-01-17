/********************************************************************************
** Form generated from reading UI file 'listwidgetelement.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWIDGETELEMENT_H
#define UI_LISTWIDGETELEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListWidgetElement
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *ListWidgetElement)
    {
        if (ListWidgetElement->objectName().isEmpty())
            ListWidgetElement->setObjectName("ListWidgetElement");
        ListWidgetElement->resize(356, 130);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ListWidgetElement->sizePolicy().hasHeightForWidth());
        ListWidgetElement->setSizePolicy(sizePolicy);
        ListWidgetElement->setMinimumSize(QSize(356, 130));
        ListWidgetElement->setMaximumSize(QSize(356, 154));
        horizontalLayout_2 = new QHBoxLayout(ListWidgetElement);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(ListWidgetElement);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(100, 100));
        label->setMaximumSize(QSize(100, 100));
        label->setStyleSheet(QString::fromUtf8("border: 2px solid grey;"));
        label->setFrameShape(QFrame::Shape::Box);

        horizontalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(ListWidgetElement);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(ListWidgetElement);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(0, 100));
        label_3->setMaximumSize(QSize(200, 16777215));
        label_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_3->setWordWrap(true);

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ListWidgetElement);

        QMetaObject::connectSlotsByName(ListWidgetElement);
    } // setupUi

    void retranslateUi(QWidget *ListWidgetElement)
    {
        ListWidgetElement->setWindowTitle(QCoreApplication::translate("ListWidgetElement", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("ListWidgetElement", "Nome", nullptr));
        label_3->setText(QCoreApplication::translate("ListWidgetElement", "first line An a few word im gonna say for the record\n"
"second line\n"
"third line\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListWidgetElement: public Ui_ListWidgetElement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWIDGETELEMENT_H
