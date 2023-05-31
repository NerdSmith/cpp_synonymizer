#ifndef SYNFILEDIA_H
#define SYNFILEDIA_H

#include <QDialog>
#include <QFile>

namespace Ui {
class SynFileDia;
}

class SynFileDia : public QDialog
{
    Q_OBJECT
    enum FileState {
        Failed,
        Opened,
        Loaded,
        Synonymized
    };

public:
    SynFileDia(QWidget *parent = nullptr, QString filename = "");
    ~SynFileDia();

private slots:
    void on_loadBtn_clicked();

    void on_synBtn_clicked();

private:
    void checkFilename();
    Ui::SynFileDia *ui;
    QString _filename;
    FileState _fileState = FileState::Failed;
    QFile* _file;
};

#endif // SYNFILEDIA_H
