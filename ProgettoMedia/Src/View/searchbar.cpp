#include "searchbar.h"
#include "ui_searchbar.h"

SearchBar::SearchBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchBar)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this ,&SearchBar::search);
}

SearchBar::~SearchBar()
{
    delete ui;
}

void SearchBar::search() {
    std::string query_text = ui->lineEdit->text().toStdString();
    emit onSearch(query_text);
}
