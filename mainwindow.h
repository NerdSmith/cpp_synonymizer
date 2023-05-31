#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <SynDict.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openFileForSynBtn_clicked();

    void on_loadDictBtn_clicked();

    void on_deleteDictBtn_clicked();

private:
    SynDict sd;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
