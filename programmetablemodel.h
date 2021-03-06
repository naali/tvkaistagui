#ifndef PROGRAMMETABLEMODEL_H
#define PROGRAMMETABLEMODEL_H

#include <QAbstractTableModel>
#include "programme.h"

class ProgrammeTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ProgrammeTableModel(bool detailsVisible, QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void setFormat(int format);
    int format() const;
    void setSortKey(int key, bool descending);
    int sortKey() const;
    bool isDescending() const;
    void setProgrammes(const QList<Programme> &programmes);
    int programmeCount() const;
    void setInfoText(const QString &text);
    QString infoText() const;
    Programme programme(int index) const;
    int defaultProgrammeIndex() const;

private:
    QList<Programme> m_programmes;
    QString m_infoText;
    bool m_detailsVisible;
    int m_format;
    int m_flagMask;
    int m_sortKey;
    int m_descending;
};

#endif // PROGRAMMETABLEMODEL_H
