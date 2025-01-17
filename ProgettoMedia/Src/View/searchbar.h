#ifndef SEARCHBAR_H
#define SEARCHBAR_H
#include <QWidget>

namespace Ui {
class SearchBar;
}

class SearchBar : public QWidget
{
    Q_OBJECT

public:
    explicit SearchBar(QWidget *parent = nullptr);
    ~SearchBar();
public slots:
    void search();
signals:
    void onSearch(std::string&);

private:
    Ui::SearchBar *ui;

};

#endif // SEARCHBAR_H
