#ifndef RANDOMSTRINGMODEL_H
#define RANDOMSTRINGMODEL_H

#include <QAbstractItemModel>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QtGlobal>
#include <QTimer>

class RandomStringModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit RandomStringModel(QObject *parent = 0);
    ~RandomStringModel();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE void insert(int index, const QString& value);
    Q_INVOKABLE void append(const QString& value);
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void clear();
    Q_INVOKABLE int count();
    Q_INVOKABLE QString get(int index);
    Q_INVOKABLE void append_random_string();

    Q_PROPERTY(int count READ count NOTIFY countChanged)

signals:
    void countChanged(int newCount);


private:
    QList<QString> m_data;
    QString getRandomString(int start, int end);
    QTimer *timer;
};

#endif // RANDOMSTRINGMODEL_H
