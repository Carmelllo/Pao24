#ifndef EDITMEDIA_H
#define EDITMEDIA_H

#include <QWidget>
#include "Src/Media/abstractmedia.h"

namespace Ui {
class EditMedia;
}

class EditMedia : public QWidget
{
    Q_OBJECT

public:
    explicit EditMedia(QWidget *parent = nullptr);
    ~EditMedia();

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
