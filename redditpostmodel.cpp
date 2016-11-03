#include "redditpostmodel.h"

RedditPostModel::RedditPostModel(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QModelIndex RedditPostModel::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex RedditPostModel::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int RedditPostModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int RedditPostModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant RedditPostModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
