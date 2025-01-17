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
    QString getName() const;
    void onMediaAdded(const QPixmap&,const std::string&, const std::string &);
public slots:
    void onInspect();
signals:
    void inspectClicked(std::string&);
private:
    Ui::ListWidgetElement *ui;
};

#endif // LISTWIDGETELEMENT_H
