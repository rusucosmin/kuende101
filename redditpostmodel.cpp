#include "redditpostmodel.h"

RedditPostModel::RedditPostModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_roleNames[Title] = "title";
    m_roleNames[Author] = "author";
    m_roleNames[ImageUrl] = "imageUrl";
    m_roleNames[Subreddit] = "subreddit";
    m_roleNames[Upvotes] = "upvotes";

    conManager = new QNetworkAccessManager(this);
    QNetworkRequest req;
    req.setUrl(QUrl(QString("https://www.reddit.com/.json")));
    connect(conManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(getResponse(QNetworkReply *)));
    conManager->get(req);
}

int RedditPostModel::rowCount(const QModelIndex &parent) const
{
    return m_data.count();
}

QVariant RedditPostModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    if(row < 0 or row >= m_data.count())
        return QVariant();

    const RedditPost& act = m_data.at(row);

    switch(role) {
        case Title:
            return act.getTitle();
        case Author:
            return act.getAuthor();
        case ImageUrl:
            return act.getImage();
        case Subreddit:
            return act.getSubreddit();
        case Upvotes:
            return act.getUpvotes();
    }
    return QVariant();
}

void RedditPostModel::insert(int index, const RedditPost& data) {
    if(index < 0 or index > m_data.count())
        return ;
    emit beginInsertRows(QModelIndex(), index, index);
    m_data.insert(index, data);
    emit endInsertRows();

    emit countChanged(m_data.count());
}

void RedditPostModel::append(const RedditPost& data) {
    this->insert(m_data.count(), data);
}

void RedditPostModel::remove(int index) {
    if(index < 0 or index >= m_data.count())
        return ;
    emit beginRemoveRows(QModelIndex(), index, index);
    m_data.removeAt(index);
    emit endRemoveRows();

    emit countChanged(m_data.count());
}

RedditPost RedditPostModel::get(int index) {
    if(index < 0 or index >= m_data.count())
        return RedditPost(QString(""), QString(""), QUrl(""), QString(""), 0);
    return m_data.at(index);
}

int RedditPostModel::count() {
    return m_data.count();
}

void RedditPostModel::getResponse(QNetworkReply *repl) {
    if(repl->error() == QNetworkReply::NoError) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(repl->readAll());
        QJsonObject jsonRoot = jsonDoc.object();
        QJsonArray postArr = (jsonRoot["data"].toObject())["children"].toArray();
        for(int i = 0; i < postArr.size(); ++ i) {
            QJsonObject act = postArr.at(i).toObject()["data"].toObject();
            RedditPost post(act["title"].toString(), act["author"].toString(), QUrl(act["thumbnail"].toString()), act["subreddit"].toString(), act["ups"].toInt());
            this->append(post);
        }
    }
    else {
        qDebug() << "Error getting the data!";
    }
}

QHash<int, QByteArray> RedditPostModel::roleNames() const {
    return m_roleNames;
}

RedditPostModel::~RedditPostModel() {
}
