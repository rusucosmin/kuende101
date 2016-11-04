#include "redditpost.h"

RedditPost::RedditPost(QString title, QString author, QUrl image, QString subreddit, int upvotes) {
    this->title = title;
    this->author = author;
    this->image = image;
    this->subreddit = subreddit;
    this->upvotes = upvotes;
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
