#ifndef REDDITPOSTMODEL_H
#define REDDITPOSTMODEL_H

#include <QAbstractItemModel>
#include <qnetworkaccessmanager.h>
#include <QNetworkReply>
#include <QSslConfiguration>
#include <qssl.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <redditpost.h>
#include <QHash>

class RedditPostModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum PostRoles {
        Title = Qt::UserRole + 1,
        Author = Qt::UserRole + 2,
        ImageUrl = Qt::UserRole + 3,
        Subreddit = Qt::UserRole + 4,
        Upvotes = Qt::UserRole + 5,
    };

    explicit RedditPostModel(QObject *parent = 0);
    ~RedditPostModel();

public:
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE void insert(int index, const RedditPost & data);
    Q_INVOKABLE void append(const RedditPost& data);
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE RedditPost get(int index);
    Q_INVOKABLE int count();

    Q_PROPERTY(int count READ count NOTIFY countChanged)

protected:
     virtual QHash<int, QByteArray> roleNames() const override;

signals:
    void countChanged(int newCount);

private slots:
    void getResponse(QNetworkReply *repl);
private:
    QNetworkAccessManager* conManager;
    QList<RedditPost> m_data;
    QHash<int, QByteArray> m_roleNames;
};

#endif // REDDITPOSTMODEL_H
