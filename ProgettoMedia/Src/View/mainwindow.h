#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include "Src/Container/container.h"
#include "medialistwidget.h"
#include "Src/Visitor/concretevisitor.h"
#include "mediawidget.h"
#include <QString>

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
    void checkWidget(QWidget*);
    void showError(const QString &);
    bool showQuestion();
    void onMediaEdited(AbstractMedia* media);
    void clearMedias();

public slots:
    void showEditOnAdd();
    void showEdit(const std::string& name);
    void onMediaCreated(AbstractMedia*);
    void onMediaDeleted(const std::string&);
    void showMediaWidget(const std::string&);
    void saveMedia();
    void openMedia();

private:
    QSplitter *HSplitter;
    QSplitter *VSplitter;
    Container* container;
    Container* searchContainer;
    //EditMedia* editMediaEdit;
    ConcreteVisitor* visitor;
    MediaWidget* mediaWidget;
    MediaListWidget* list;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
