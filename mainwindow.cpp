#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <SynFileDia.h>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openFileForSynBtn_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Текстовые файлы (*.txt)");
    if (!filePath.isEmpty()) {
        SynFileDia sfd(this, filePath);
        sfd.exec();
    }
}


void MainWindow::on_loadDictBtn_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл", "", "CSV файлы (*.csv)");
    if (!filePath.isEmpty()) {
        this->sd.loadFromFile(filePath);
        this->ui->openedDictsListWid->clear();
        this->ui->openedDictsListWid->addItems(this->sd.getFiles());
    }
}


void MainWindow::on_deleteDictBtn_clicked()
{
    int selectedItemIdx = this->ui->openedDictsListWid->currentRow();

    if (selectedItemIdx != -1) {
        this->sd.rmByIdx(selectedItemIdx);
        delete this->ui->openedDictsListWid->takeItem(selectedItemIdx);
    }
}

