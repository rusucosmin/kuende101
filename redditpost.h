#ifndef REDDITPOST_H
#define REDDITPOST_H

#include <QString>
#include <QUrl>
#include <QColor>

class RedditPost
{
public:
    RedditPost() {};
    RedditPost(QString title, QString author, QUrl image, QString subreddit, int upvotes, QString id);
    QUrl getImage() const;
    QString getTitle() const;
    QString getAuthor() const;
    QString getSubreddit() const;
    int getUpvotes() const;
    QString getId() const;
    QColor getColor() const;
    void setColor(QColor);
    void setUpvotes(int);
private:
    QUrl image;
    QString title;
    QString author;
    QString subreddit;
    QString id;
    QColor color;
    int upvotes;
};

#endif // REDDITPOST_H
