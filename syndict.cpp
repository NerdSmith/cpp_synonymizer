#include "syndict.h"
#include <sstream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include <cstdlib>
#include <ctime>

SynDict::SynDict()
{

}

bool SynDict::loadFromFile(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text) || _files.contains(filename)) {
        qCritical() << "Cant load file";
        return false;
    }
    QTextStream in(&file);
    Table table;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList words = line.split(",");

//        QString key;
        Row values;

        for (const QString& item : words) {
            values.append(item);
        }
        table.append(values);
    }

    _tables.append(table);
    _files.append(filename);

    qInfo() << "File " << filename << " is loaded";
    return true;
}

QString SynDict::findSyn(QString word)
{
    QString found;
    std::srand(std::time(nullptr));
    for (auto& table : _tables) {
        for (const Row& row : table) {
            if (row.contains(word)) {
                if (!found.isEmpty() && skipRepeat) {
                    continue;
                }
                int randomIndex = std::rand() % row.size();
                found = row[randomIndex];
                qInfo() << "Found syn for word: " << word << " -> " << found;
            }
        }
    }
    return found;
}

QStringList SynDict::getFiles() {
    return this->_files;
}

void SynDict::rmByIdx(int idx)
{
    if (idx >= 0 && idx < this->_files.size()) {
        this->_files.removeAt(idx);
        this->_tables.removeAt(idx);
    }
}

SynDict::~SynDict()
{

}
