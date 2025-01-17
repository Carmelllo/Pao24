#ifndef LISTWIDGETELEMENT_H
#define LISTWIDGETELEMENT_H

#include <QWidget>

namespace Ui {
class ListWidgetElement;
}

class ListWidgetElement : public QWidget
{
    Q_OBJECT

public:
    explicit ListWidgetElement(QWidget *parent = nullptr);
    ~ListWidgetElement();
    QString getName();
    void onMediaAdded(const QPixmap&,const std::string&);
private:
    Ui::ListWidgetElement *ui;
};

#endif // LISTWIDGETELEMENT_H
