#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
#include "Src/Media/bookmedia.h"
#include "Src/Media/articlemedia.h"
#include "Src/Media/moviemedia.h"

namespace Ui {
class MediaWidget;
}

class MediaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MediaWidget(QWidget *parent = nullptr);
    ~MediaWidget();



private:
    Ui::MediaWidget *ui;
};

#endif // MEDIAWIDGET_H
