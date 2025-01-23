#ifndef EDITMEDIA_H
#define EDITMEDIA_H

#include <QWidget>
#include "Src/Media/abstractmedia.h"
#include "Src/Visitor/concretevisitor.h"

namespace Ui {
class EditMedia;
}

class EditMedia : public QWidget
{
    Q_OBJECT
private:
public:
    explicit EditMedia(QWidget *parent = nullptr);
    ~EditMedia();
    void showEditWindow();
    void showEditMedia(ConcreteVisitor* visitor);
signals:
    void onApply(AbstractMedia *);

private slots:
    void onApplyButtonClicked();
    void changeView(int);
    void uploadImage();


private:
    Ui::EditMedia *ui;
};

#endif // EDITMEDIA_H
