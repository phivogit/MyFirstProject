#include "autoclicker.h"
#include "ui_autoclicker.h"
#include <windows.h>
#include <thread>
#include <QShortcut>

AutoClicker::AutoClicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AutoClicker)
{
    ui->setupUi(this);
    ui->mouseInpLabel->setText("Left Mouse Button");
    mouseState = 0;
    ui->InpClickSpeed->setText("1000");
    connect(ui->changeMouseInpButton, &QPushButton::clicked, this, &AutoClicker::handleMouseChange);
    connect(ui->ButtonStart, &QPushButton::clicked, this, &AutoClicker::StartClick);
    connect(ui->ButtonStop, &QPushButton::clicked, this, &AutoClicker::StopClick);
}

void AutoClicker::click(int speed, INPUT &click, INPUT &release) {
    while (running == 1) {
        SendInput(1, &click, sizeof(INPUT));
        Sleep(10);
        SendInput(1, &release, sizeof(INPUT));
        Sleep(speed);
        qDebug() << "Click!";
    }
}

void AutoClicker::StartClick() {
    INPUT click = {};
    INPUT release = {};
    int speed = getClickSpeed();
    running = 1;
    click.type = INPUT_MOUSE;
    release.type = INPUT_MOUSE;
    if (mouseState == 1) {
        click.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        release.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    } else {
        click.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        release.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    }
    UINT result = SendInput(1, &click, sizeof(INPUT));
    qDebug() << "SendInput result:" << result << "Error:" << GetLastError();
    std::thread t(&AutoClicker::click, this, speed, std::ref(click), std::ref(release));
    t.detach();
    ui->ButtonStart->setEnabled(false);
}

void AutoClicker::StopClick() {
    running = 0;
    ui->ButtonStart->setEnabled(true);
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

int AutoClicker::getClickSpeed() {
    QString ClickSpeedText = ui->InpClickSpeed->text();
    int ClickSpeed = ClickSpeedText.toInt();
    return ClickSpeed;
}

AutoClicker::~AutoClicker()
{
    delete ui;
}
