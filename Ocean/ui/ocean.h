/*
***Copyleft (C) 2020 Softwater, Inc
***Contact: bogdyname@gmail.com
***Contact: donvalentiy@yandex.ru
*/

#ifndef OCEAN_H
#define OCEAN_H

#include <QDir>
#include <QTimer>
#include <QDebug>
#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <QSlider>
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QPushButton>
#include <QMainWindow>
#include <QStringList>
#include <QMessageBox>
#include <QSpacerItem>
#include <QTextBrowser>
#include <QMediaPlayer>
#include <QResizeEvent>
#include <QMediaContent>
#include <QMediaPlaylist>
#include "ui_ocean.h"

//widgets
#include "addmusicwidget.h"
#include "getstringwidget.h"
#include "selectplaylist.h"

//managers
#include "imports/importmanager.h"
#include "playlists/playlist.h"
#include "player/player.h"

class Ocean : public QMainWindow, private Ui::Ocean
{
    Q_OBJECT

public:
    Ocean(QWidget *parent = nullptr);
    ~Ocean();

/****************************************************************************************************************************************/

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*||||||||||||||||||||||||||||||||||||||||||||||||||this->QWidget||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

    /*--------------------------------------Events for MainWindow--------------------------------*/

    /*
        1) for check resize of MainWindow
    */

protected:
    virtual void resizeEvent(QResizeEvent *event);
    /*--------------------------------------Events for MainWindow--------------------------------*/


    /*-------------------------------------Signals for playlist----------------------------------*/

    /*
        1) pass tracks into music list
        2) Create widget after widget for get string from user
    */

signals:
    void CallOutPassNamesOfSongsToMusicList(const QStringList &songs);
    void CallOutToCreateWindowThisWidgetToGetAddedTracks();
    /*-------------------------------------Signals for playlist----------------------------------*/


    /*-------------------------------------Slots for MainWindow----------------------------------*/

    /*
        1) Slot for hide widgets inside MainWindow
        2) Slot for show widgets inside MainWindow
    */

private slots:
    void Hidder();
    void Shower();
    void GetNamesOfSongsToMusicList(QListWidgetItem *item);
    void PassNamesOfSongsToMusicList(const QStringList &songs);
    /*-------------------------------------Slots for MainWindow----------------------------------*/

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*||||||||||||||||||||||||||||||||||||||||||||||||||this->QWidget||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

/****************************************************************************************************************************************/

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||MANAGERS||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

    /*
        1) Context Menu of Music list
        2) Context Menu of Playlists
        3) Set play list (current after new tracks in app || or just set playlist by name)
    */

    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    // Context Menu of Music list ------------------------------------------------- 1
    //Slot for call and create context menu for Music list (right click on item of Ocean::musicList)
    void ShowContextMenuOfMusicList(const QPoint &point);

    // SLOTS for context menu of music list
    /*
        1) Delete all songs
        2) Delete one selected item
        3) Add song into playlist by name (pass data via SIGNAL of playlist manager)
    */
    void EraseAllItemsFromMusicList();
    void EraseItemFromMusicList();
    void AddSongIntoPlayListByIndex();
    void ParseMusicList(const QString &name);
    // Context Menu of Music list ------------------------------------------------- 1

    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    // Context Menu of Playlists -------------------------------------------------- 2
    //Slot for call and create context menu for Playlist (right click on item of Ocean::playLists)
    void ShowContextMenuOfPlayList(const QPoint &point);

    // SLOTS for context menu of Playlists
    /*
        1) Delete item from QListWidget (Ocean::playLists)
        2) Create playlist via own widget (Ocean::getStringFromUser)
        3) Rename playlist via own widget (Ocean::getStringFromUser)
        4) Save playlist via own object for QMediaPlaylist (Ocean::playlistmanager)
    */
    void EraseItemFromPlayList();
    void CreatePlaylist();
    void RenamePlaylist();
    void Rename(const QListWidgetItem *item, QString buffer);
    void SavePlaylist();
    // Context Menu of Playlists -------------------------------------------------- 2

    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    // Set Playlist --------------------------------------------------------------- 3
    // Set Playlist
    void SetPlayList(QListWidgetItem *item);
    void SetCurrentPlayList();
    // Set Playlist --------------------------------------------------------------- 3

    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||MANAGERS||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

/****************************************************************************************************************************************/

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*||||||||||||||||||||||||||||||||||||||||||||||||||||||||UI|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

    /*
       1) Widget for get string from user
       2) Widget for get name of selected playlist
       3) Widget for info of song //Valenty
    */

    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    // Widget for get string from user -------------------------------------------- 1
    /*
        1) Close widget via 'cancel button' without string
        2) Close widget via return pressed and pass string from user
    */
    void ClosegetStringFromUserViaCancel();
    void ClosegetStringFromUserViaOkay();
    // Widget for get string from user -------------------------------------------- 1

    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    // Widget for get name of playlist from user ---------------------------------- 2
    /*
        1) Close widget after get name of selected playlist
        2) Close widget via 'cancel button'
    */
    void ClosegetStringWithSelectedPlaylist();
    void ClosegetStringWithSelectedPlaylistViaCancel();
    // Widget for get name of playlist from user ---------------------------------- 2

    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    // Widget for get added tracks from widget  ----------------------------------- 3
    /*
        1) Close widget via 'cancel button'
        2) Pass tracks into buffer
    */
    void ClosegetAddedTracksFromWidgetViaCancel();
    void PassAddedTracksIntoBuffer(const QStringList &list);
    // Widget for get added tracks from widget  ----------------------------------- 3

    //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*||||||||||||||||||||||||||||||||||||||||||||||||||||||||UI|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

/****************************************************************************************************************************************/

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*||||||||||||||||||||||||||||||||||||||||||||||||||||||Tools||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

    /*
        1) Timer for Ocean::getStringFromUser
        2) Timer for Ocean::getStringWithSelectedPlaylist
        3) Timer for Ocean::getAddedTracksFromWidget
        4) Get names of playlists from 'bin' dir
        5) Create widget after widget for get string from user
        6) Write name of default playlist 'all' into QListWidget
    */

    //REFACTORED THIS CODE (make one SLOT)
    //REFACTORED THIS CODE (make one SLOT)
    //REFACTORED THIS CODE (make one SLOT)
    void IfgetStringFromUserClosed();//-----------------------------------------1
    void IfgetStringWithSelectedPlaylistClosed();//-----------------------------2
    void IfgetAddedTracksFromWidgetClosed();//----------------------------------3
    QStringList GetNamesOfPlaylistsFromBinDir();//------------------------------5
    void CallWidgetAfterCreatePlaylistSlot();//---------------------------------6
    void WriteDefaultPlayList(); //---------------------------------------------7

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*||||||||||||||||||||||||||||||||||||||||||||||||||||||Tools||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

/****************************************************************************************************************************************/

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||METHODS FOR UI||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

    /*
        1) get all items from list widget (alg)
    */

private:
    QStringList GetAllItemsFromList();

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||METHODS FOR UI||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

/****************************************************************************************************************************************/

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||OBJECTS|||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

private:
    //UI--------------------------------------------------------------
    //track status (maybe bit rank)
    QSlider *sliderOfTrack = nullptr;

    //right side (working with app)
    QSpacerItem *spacer = nullptr;
    QPixmap *ownImage = nullptr;
    QSlider *sliderOfVolume = nullptr;
    QLabel *imageOfPlayList = nullptr;
    QComboBox *sortBy = nullptr;

    //lists of playlists and musiclists
    QListWidget *playLists = nullptr;
    QListWidget *musicList = nullptr;

    //player
    QPushButton *playTrack = nullptr;
    QPushButton *pauseTrack = nullptr;
    QPushButton *stopTrack = nullptr;
    QPushButton *nextTrack = nullptr;
    QPushButton *previousTrack = nullptr;

    //add music buttons
    QPushButton *buttonForAddMusicWithDel = nullptr;
    QPushButton *buttonForAddMusicOnlyCopy = nullptr;
    //UI--------------------------------------------------------------

    //TOOLS-----------------------------------------------------------
    //ToolS for widgets
    QTimer *timerForCheckWidgets = nullptr;
    QTimer *timerForCheckDefaultPlayList = nullptr;
    QStringList bufferOfAddedTracks = {};
    QDir *cd = nullptr;
    //TOOLS-----------------------------------------------------------


    //Own Objects-----------------------------------------------------

    /*
        1) UI own widgets
        2) Managers
    */
private:
    // UI own widgets ----------------------------------------------- 1
    //ui widgets
    AddMusicWidget *getAddedTracksFromWidget = nullptr;
    GetStringWidget *getStringFromUser = nullptr;
    SelectPlaylist *getStringWithSelectedPlaylist = nullptr;
    // UI own widgets ----------------------------------------------- 1

    // Managers ----------------------------------------------------- 2
    ImportManager *importManager = nullptr;
    Playlist *playlistmanager = nullptr;
    Player *playermanager = nullptr;
    // Managers ----------------------------------------------------- 2
    //Own Objects-----------------------------------------------------


    //default UI
private:
    Ui::Ocean *ui;

    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||OBJECTS|||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
};
#endif
