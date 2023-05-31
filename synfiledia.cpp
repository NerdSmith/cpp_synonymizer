#include "synfiledia.h"
#include "ui_synfiledia.h"
#include <QDebug>

void SynFileDia::checkFilename() {
    this->_file = new QFile(_filename);
    if (!_file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Cant load file";
        this->ui->statusText->setText("Cant open");
        this->_fileState = FileState::Failed;
        return;
    }

    this->ui->statusText->setText("Opened");
    this->_fileState = FileState::Opened;
}

SynFileDia::SynFileDia(QWidget *parent, QString filename) :
    QDialog(parent),
    ui(new Ui::SynFileDia),
    _filename(filename)
{
    ui->setupUi(this);

    this->ui->filename->setText(filename);

    checkFilename();
}

SynFileDia::~SynFileDia()
{
    delete _file;
    delete ui;
}

void SynFileDia::on_loadBtn_clicked()
{
    if (_fileState != FileState::Failed) {
        QTextStream in(this->_file);
        QString content = in.readAll();
        this->ui->fileContentTextEdit->setPlainText(content);

        this->_fileState = FileState::Loaded;
        this->ui->statusText->setText("Loaded");
    }
}


void SynFileDia::on_synBtn_clicked()
{
    if (_fileState != FileState::Failed) {
        if (_fileState != FileState::Opened) {

        }
        if (_fileState != FileState::Loaded) {

        }
    }
}

