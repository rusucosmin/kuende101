#include "randomstringmodel.h"
#include <qdebug.h>

RandomStringModel::RandomStringModel(QObject *parent)
    : QAbstractListModel(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(append_random_string()));
    timer->start(1000);
}

RandomStringModel::~RandomStringModel() {
    delete timer;
}

int RandomStringModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant RandomStringModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row < 0 || row >= m_data.count())
        return QVariant();

    switch(role) {
        case Qt::DisplayRole:
            return m_data.value(row);
    }

    return QVariant();
}

void RandomStringModel::insert(int index, const QString& value) {
    if(index < 0 || index > m_data.count())
        return ;

    emit beginInsertRows(QModelIndex(), index, index);
    m_data.insert(index, value);
    emit endInsertRows();

    emit countChanged(m_data.count());
}

void RandomStringModel::append(const QString& value) {
    this->insert(m_data.count(),  value);
}

void RandomStringModel::remove(int index) {
    if(index < 0 || index >= m_data.count())
        return ;
    emit beginRemoveRows(QModelIndex(), index, index);
    m_data.removeAt(index);
    emit endRemoveRows();

    emit countChanged(m_data.count());
}

QString RandomStringModel::get(int index) {
    if(index < 0 or index >= m_data.count())
        return QString();
    return m_data.at(index);
}

void RandomStringModel::clear() {
    if(m_data.count() == 0)
        return ;
    emit beginRemoveRows(QModelIndex(), 0, m_data.count() - 1);
    m_data.clear();
    emit endRemoveRows();

    emit countChanged(m_data.count());
}

int RandomStringModel::count() {
    return m_data.count();
}

QString RandomStringModel::getRandomString(int st, int dr) {
    static const QString chSet("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    QString s;
    int sz = st + qrand() % (dr - st + 1);
    for(int i = 0; i < sz; ++ i) {
        int act = qrand() % chSet.size();
        s.append(chSet.at(act));
    }
    return s;
}

void RandomStringModel::append_random_string() {
    append(getRandomString(10, 300));
}
