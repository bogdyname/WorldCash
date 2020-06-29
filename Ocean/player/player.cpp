/*
***Copyleft (C) 2020 Softwater, Inc
***Contact: bogdyname@gmail.com
***Contact: donvalentiy@yandex.ru
***Created by bogdyname
***Created by Valentiy
*/

#include "player.h"

Player::Player()
{
    try
    {
        Player::player = new QMediaPlayer();
    }
    catch(std::bad_alloc &exp)
    {
        #ifndef Q_DEBUG
        qCritical() << "Exception caught: " << exp.std::bad_alloc::what();
        #endif
        abort();
    }
    catch(...)
    {
        #ifndef Q_DEBUG
        qCritical() << "Some exception caught";
        #endif
        abort();
    }

    return;
}

Player::~Player()
{
    delete Player::player;

    return;
}

//Public slots
void Player::CallSetMod(const unsigned short int &mod)
{
    if(Player::SetModOfPlayer(mod))
        qDebug() << "set mod: " << mod;
    else
        qDebug() << "error: set mod";

    return;
}

void Player::CallSetPlayList(QMediaPlaylist *playlist)
{
    if(Player::SetPlayList(playlist))
        qDebug() << "set playlist";
    else
        qDebug() << "error: set playlist";

    return;
}

void Player::CallSetVolume(const unsigned short int &volume)
{
    if(Player::SetVolume(volume))
        qDebug() << "set volume" << volume;
    else
        qDebug() << "error: set volume";

    return;
}

//Methods
const QMediaPlayer* Player::GetPlayer()
{
    return Player::player;
}

qint64 Player::GetPositionOfTrack()
{
    return Player::player->position();
}

void Player::SetPositionOfTrack(const qint64 &position)
{
    Player::player->QMediaPlayer::setPosition(position);

    return;
}

bool Player::SetModOfPlayer(const unsigned short int &mod)
{
    switch(mod)
    {
        //Loop player
        case 0:
        {
            Player::player->QMediaPlayer::setPlaybackRate(QMediaPlaylist::Loop);
            return true;
        }
        break;

        //Random player
        case 1:
        {
            Player::player->QMediaPlayer::setPlaybackRate(QMediaPlaylist::Random);
            return true;
        }
        break;

        //Default sequential player (one by one)
        case 2:
        {
            Player::player->QMediaPlayer::setPlaybackRate(QMediaPlaylist::Sequential);
            return true;
        }
        break;
        //False
        default: return false;
    }
}

bool Player::SetPlayList(QMediaPlaylist *playlist)
{
    if(!playlist->QMediaPlaylist::isEmpty())
    {
        Player::player->QMediaPlayer::setPlaylist(playlist);
        return true;
    }
    else
        return false;
}

bool Player::SetVolume(const unsigned short int &volume)
{
    if(volume > 0)
    {
        Player::player->QMediaPlayer::setVolume(volume);
        return true;
    }
    else
        return false;
}
