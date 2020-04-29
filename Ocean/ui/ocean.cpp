/*
***Copyleft (C) 2020 Softwater, Inc
***Contact: bogdyname@gmail.com
***Contact: donvalentiy@yandex.ru
*/

#include "ui/ocean.h"
#include <QFileDialog>
#include "imports/importmanager.h"

Ocean::Ocean(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ocean)
{
    Ocean::ui->setupUi(this);

    //Objects of UI
    try
    {
        Ocean::listMusic = new QListWidget();
    }
    catch (std::bad_alloc &exp)
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

    Ocean::ui->horizontalLayout->QHBoxLayout::addWidget(Ocean::listMusic);

    //STYLE
    Ocean::listMusic->QWidget::setMaximumWidth(150);
    Ocean::listMusic->QWidget::setMinimumWidth(150);

    //CONNECT SIGNALS WITH SLOTS

    //TTS
    ImportManager managerTTS;
}

Ocean::~Ocean()
{
    delete Ocean::ui;
    delete Ocean::listMusic;
}
