#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
#include "Src/Visitor/concretevisitor.h"
#include <QtWidgets>

namespace Ui {
class MediaWidget;
}

class MediaWidget : public QWidget
{
    Q_OBJECT
private:
    std::string widgetName;
public:
    explicit MediaWidget(QWidget *parent = nullptr);
    ~MediaWidget();
    void showMedia(ConcreteVisitor* visitor);
    void clearUI(QLayout* layout);
public slots:
    void onRemoveClicked();
    void onEditClicked();
signals:
    void onRemove(const std::string&);
    void onEdit(const std::string&);
private:
    Ui::MediaWidget *ui;
};

#endif // MEDIAWIDGET_H
