#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
#include "Src/Visitor/concretevisitor.h"

namespace Ui {
class MediaWidget;
}

class MediaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MediaWidget(QWidget *parent = nullptr);
    ~MediaWidget();
    void show(ConcreteVisitor* visitor);
    void clearUI(QLayout* layout);
private:
    Ui::MediaWidget *ui;
};

#endif // MEDIAWIDGET_H
