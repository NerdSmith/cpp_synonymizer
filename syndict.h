#ifndef SYNDICT_H
#define SYNDICT_H
#include <QString>
#include <QVector>
#include <QMap>
#include <QString>

using namespace std;

class SynDict
{
    using Row = QVector<QString>;
    using Table = QVector<Row>;
private:
    QVector<Table> _tables;
    QStringList _files;
    bool skipRepeat = false;
public:
    SynDict();
    bool loadFromFile(QString filename);
    QString findSyn(QString word);
    QStringList getFiles();
    void rmByIdx(int idx);
    ~SynDict();
};

#endif // SYNDICT_H
