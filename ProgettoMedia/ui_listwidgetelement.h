/********************************************************************************
** Form generated from reading UI file 'listwidgetelement.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWIDGETELEMENT_H
#define UI_LISTWIDGETELEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListWidgetElement
{
public:
    QHBoxLayout *horizontalLayout_2;
    QLabel *image;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *descriptionLabel;

    void setupUi(QWidget *ListWidgetElement)
    {
        if (ListWidgetElement->objectName().isEmpty())
            ListWidgetElement->setObjectName(QString::fromUtf8("ListWidgetElement"));
        ListWidgetElement->resize(356, 130);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ListWidgetElement->sizePolicy().hasHeightForWidth());
        ListWidgetElement->setSizePolicy(sizePolicy);
        ListWidgetElement->setMinimumSize(QSize(356, 130));
        ListWidgetElement->setMaximumSize(QSize(356, 154));
        horizontalLayout_2 = new QHBoxLayout(ListWidgetElement);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        image = new QLabel(ListWidgetElement);
        image->setObjectName(QString::fromUtf8("image"));
        sizePolicy.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy);
        image->setMinimumSize(QSize(100, 100));
        image->setMaximumSize(QSize(100, 100));
        image->setStyleSheet(QString::fromUtf8("border: 2px solid grey;"));
        image->setFrameShape(QFrame::Shape::Box);

        horizontalLayout_2->addWidget(image);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        nameLabel = new QLabel(ListWidgetElement);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        sizePolicy.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(nameLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton = new QPushButton(ListWidgetElement);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(30, 16777215));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::DialogInformation")));
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        descriptionLabel = new QLabel(ListWidgetElement);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));
        sizePolicy.setHeightForWidth(descriptionLabel->sizePolicy().hasHeightForWidth());
        descriptionLabel->setSizePolicy(sizePolicy);
        descriptionLabel->setMinimumSize(QSize(220, 10));
        descriptionLabel->setMaximumSize(QSize(220, 16777215));
        descriptionLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        descriptionLabel->setWordWrap(true);

        verticalLayout_2->addWidget(descriptionLabel);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ListWidgetElement);

        QMetaObject::connectSlotsByName(ListWidgetElement);
    } // setupUi

    void retranslateUi(QWidget *ListWidgetElement)
    {
        ListWidgetElement->setWindowTitle(QCoreApplication::translate("ListWidgetElement", "Form", nullptr));
        image->setText(QString());
        nameLabel->setText(QCoreApplication::translate("ListWidgetElement", "Nome", nullptr));
        pushButton->setText(QString());
        descriptionLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListWidgetElement: public Ui_ListWidgetElement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWIDGETELEMENT_H
