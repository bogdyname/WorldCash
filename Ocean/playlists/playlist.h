/*
***Copyleft (C) 2020 Softwater, Inc
***Contact: bogdyname@gmail.com
***Contact: donvalentiy@yandex.ru
***Created by bogdyname
*/

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QDir>
#include <QFile>
#include <QList>
#include <QString>
#include <QFileDialog>
#include <QMediaObject>
#include <QMediaPlaylist>
#include <QCoreApplication>

class Playlist : public QMediaPlaylist
{
    Q_OBJECT

    //dir 'bin' for saving and loading playlists

public:
    Playlist();
    ~Playlist();

signals:
    void SetCurrentPlayList(QMediaPlaylist *currentPlaylist);
    void SetDefaultPlayList(QMediaPlaylist *currentPlaylist);

public slots:
    void CreateCurrentPlayList(const QString &name);
    void RemoveCurrentPlayList(const QString &name);

public:
    QMediaPlaylist* GetCurrentPlayList();
    QMediaPlaylist* GetDefaultPlayList();
    void LoadDefaultPlayList();
    void LoadPlayList(const QString &name);

    //check out these methods
private:
    bool CreatePlayList(const QString &name, const QStringList &list, QMediaPlaylist *currentPlaylist);
    bool RemovePlayList(const QString &name);
    bool LookingForPlayList(const QString &name, QMediaPlaylist *medialist);
    bool CreateDefaultPlaylist(QMediaPlaylist *medialist);
    bool CheckSettingsDir();

private:
    QFileDialog *dialog = nullptr;
    QDir *settingsDir = nullptr;
    QStringList list;
    QStringList allSongs;
    QMediaPlaylist *currentPlaylist = nullptr;
    QMediaPlaylist *defaultPlaylist = nullptr;
};

#endif
