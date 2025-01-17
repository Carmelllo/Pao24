#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include "Src/Container/container.h"
#include "medialistwidget.h"
#include "Src/Visitor/concretevisitor.h"
#include "editmedia.h"
#include "mediawidget.h"
#include <QString> // Ensure QString is included


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void search(std::string&);
    void update();
    void showError(const QString &);

public slots:
    void showEditOnAdd();
    void onMediaCreated(AbstractMedia*);
    void showMediaWidget(const std::string&);
private:
    QSplitter *HSplitter;
    QSplitter *VSplitter;
    Container* container;
    Container* searchContainer;
    ConcreteVisitor* visitor;
    MediaWidget* mediaWidget;
    MediaListWidget* list;
    EditMedia* editMediaWidget;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
