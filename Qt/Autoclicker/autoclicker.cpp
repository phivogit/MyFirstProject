#include "autoclicker.h"
#include "ui_autoclicker.h"
#include <windows.h>
#include <thread>
#include <QShortcut>
#include <QAbstractNativeEventFilter>
#include "nativeeventfilter.h"

#define INIT_CSPEED "100"
#define INIT_MOUSE 0

AutoClicker::AutoClicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AutoClicker)
{
    ui->setupUi(this);
    if (INIT_MOUSE == 0) ui->mouseInpLabel->setText("Left Mouse Button");
    else ui->mouseInpLabel->setText("Right Mouse Button");
    mouseState = INIT_MOUSE;
    ui->InpClickSpeed->setText(INIT_CSPEED);
    ui->ButtonStop->setEnabled(false);
    connect(ui->changeMouseInpButton, &QPushButton::clicked, this, &AutoClicker::handleMouseChange);
    connect(ui->ButtonStart, &QPushButton::clicked, this, &AutoClicker::StartClick);
    connect(ui->ButtonStop, &QPushButton::clicked, this, &AutoClicker::StopClick);
    bool success = RegisterHotKey((HWND)this->winId(), 1, 0, VK_F6);
    if (success == 1) {
        qDebug() << "Registered hotkey";
    } else {
        qDebug() << "Failed to register hotkey";
    }
    m_filter = new NativeEventFilter();
    qApp->installNativeEventFilter(m_filter);
    connect(m_filter, &NativeEventFilter::hotkeyPressed, this, &AutoClicker::StartClick);
}

void AutoClicker::click(int speed) {
    while (running == 1) {
        INPUT click = {0};
        INPUT release = {0};
        click.type = INPUT_MOUSE;
        release.type = INPUT_MOUSE;
        if (mouseState == 1) {
            click.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
            release.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
        } else {
            click.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            release.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        }
        click.mi.dx = 0;
        click.mi.dy = 0;
        click.mi.mouseData = 0;
        click.mi.dwExtraInfo = 0;
        click.mi.time = 0;

        release.mi.dx = 0;
        release.mi.dy = 0;
        release.mi.mouseData = 0;
        release.mi.dwExtraInfo = 0;
        release.mi.time = 0;
        SendInput(1, &click, sizeof(INPUT));
        Sleep(20);
        SendInput(1, &release, sizeof(INPUT));
        Sleep(speed);
    }
}

void AutoClicker::StartClick() {
    int speed = getClickSpeed();
    running = 1;
    disconnect(m_filter, &NativeEventFilter::hotkeyPressed, this, &AutoClicker::StartClick);
    connect(m_filter, &NativeEventFilter::hotkeyPressed, this, &AutoClicker::StopClick);
    qDebug() << "Started";
    std::thread t(&AutoClicker::click, this, speed);
    t.detach();
    ui->activateKeyButton->setEnabled(false);
    ui->ButtonStart->setEnabled(false);
    ui->ButtonStop->setEnabled(true);
}

void AutoClicker::StopClick() {
    running = 0;
    disconnect(m_filter, &NativeEventFilter::hotkeyPressed, this, &AutoClicker::StopClick);
    connect(m_filter, &NativeEventFilter::hotkeyPressed, this, &AutoClicker::StartClick);
    ui->activateKeyButton->setEnabled(true);
    ui->ButtonStart->setEnabled(true);
    ui->ButtonStop->setEnabled(false);
    qDebug() << "Stopped";
}

void AutoClicker::handleMouseChange() {
    if (mouseState == 0) {
        mouseState = 1;
        ui->mouseInpLabel->setText("Right Mouse Button");
    } else {
        mouseState = 0;
        ui->mouseInpLabel->setText("Left Mouse Button");
    }
}
void AutoClicker::panelChange() {

}
int AutoClicker::getClickSpeed() {
    QString ClickSpeedText = ui->InpClickSpeed->text();
    int ClickSpeed = ClickSpeedText.toInt();
    return ClickSpeed;
}

void AutoClicker::closeEvent(QCloseEvent *event) {
    bool success = UnregisterHotKey((HWND)this->winId(), 1);
    if (success == 1) {
        qDebug() << "Unregistered hotkey";
    } else {
        qDebug() << "Failed to unregister hotkey";
    }
    QMainWindow::closeEvent(event);
}
AutoClicker::~AutoClicker()
{
    delete ui;
}
