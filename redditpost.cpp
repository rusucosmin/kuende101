#include "redditpost.h"

RedditPost::RedditPost(QString title, QString author, QUrl image, QString subreddit, int upvotes, QString id) {
    this->title = title;
    this->author = author;
    this->image = image;
    this->subreddit = subreddit;
    this->upvotes = upvotes;
    this->id = id;
    this->color = QColor("#00000000");
}

QColor RedditPost::getColor() const {
    return this->color;
}

void RedditPost::setColor(QColor col) {
    this->color = col;
}

void RedditPost::setUpvotes(int x) {
    this->upvotes = x;
}

QUrl RedditPost::getImage() const {
    return image;
}

QString RedditPost::getAuthor() const {
    return author;
}

QString RedditPost::getTitle() const {
    return title;
}

int RedditPost::getUpvotes() const {
    return upvotes;
}

QString RedditPost::getSubreddit() const {
    return subreddit;
}

QString RedditPost::getId() const {
    return id;
}
