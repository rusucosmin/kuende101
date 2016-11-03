#ifndef REDDITPOSTMODEL_H
#define REDDITPOSTMODEL_H

#include <QAbstractItemModel>

class RedditPostModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit RedditPostModel(QObject *parent = 0);

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // REDDITPOSTMODEL_H