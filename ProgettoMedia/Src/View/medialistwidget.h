#ifndef MEDIALISTWIDGET_H
#define MEDIALISTWIDGET_H
#include <QWidget>
#include "listwidgetelement.h"
#include "Src/Container/container.h"
#include "Src/Visitor/concretevisitor.h"

namespace Ui {
class MediaListWidget;
}

class MediaListWidget : public QWidget
{
    Q_OBJECT

private:
    std::vector<ListWidgetElement*> listElementWidgets;
public:
    explicit MediaListWidget(
        QWidget *parent = nullptr);
    ~MediaListWidget();
    void refresh();
    void addWidget(const QPixmap&, const std::string &, const std::string &);
    void showWidgets(Container * , ConcreteVisitor *);
signals:
    void addClick();
private slots:
    void onAddButtonClicked();
private:
    Ui::MediaListWidget *ui;
};

#endif // MEDIALISTWIDGET_H
