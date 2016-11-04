#ifndef REDDITPOST_H
#define REDDITPOST_H

#include <QString>
#include <QUrl>

class RedditPost
{
public:
    RedditPost(QString title, QString author, QUrl image, QString subreddit, int upvotes);
    QUrl getImage() const;
    QString getTitle() const;
    QString getAuthor() const;
    QString getSubreddit() const;
    int getUpvotes() const;
private:
    QUrl image;
    QString title;
    QString author;
    QString subreddit;
    int upvotes;
};

#endif // REDDITPOST_H
