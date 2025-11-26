#include "autoclicker.h"
#include "ui_autoclicker.h"
#include <windows.h>
#include <thread>
#include <QShortcut>
#include <QAbstractNativeEventFilter>
#include "nativeeventfilter.h"
#include <QKeyEvent>

#define INIT_CSPEED "100"
#define INIT_MOUSE 0
#define INIT_KSPEED "100"
#define INIT_KEY 'A'

AutoClicker::AutoClicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AutoClicker)
{
    ui->setupUi(this);
    ui->mouseOption->setChecked(true);
    this->setFocusPolicy(Qt::StrongFocus);
    if (ui->mouseOption->isChecked()) ui->stackedWidget->setCurrentIndex(0);
    else ui->stackedWidget->setCurrentIndex(1);
    connect(ui->mouseOption, &QRadioButton::clicked, this, &AutoClicker::panelChange);
    connect(ui->keyboardOption, &QRadioButton::clicked, this, &AutoClicker::panelChange);
    // Init Mouse
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
    connect(ui->activateKeyButton, &QPushButton::clicked, this, &AutoClicker::enableMouseHotKeyChangeListen);
    connect(m_filter, &NativeEventFilter::hotkeyPressed, this, &AutoClicker::StartClick);
    // Init Keyboard
    success = RegisterHotKey((HWND)this->winId(), 2, 0, VK_F7);
    if (success == 1) {
        qDebug() << "Registered hotkey";
    } else {
        qDebug() << "Failed to register hotkey";
    }
    ui->KInpClickSpeed->setText(INIT_CSPEED);
    ui->KButtonStop->setEnabled(false);
    newKeyClick = 'A';
    connect(ui->KchangeInpButton, &QPushButton::clicked, this, &AutoClicker::enableKeyChangeListen);
    connect(ui->KactivateKeyButton, &QPushButton::clicked, this, &AutoClicker::enableHotKeyChangeListen);
    connect(m_filter, &NativeEventFilter::keyboardHotkeyPressed, this, &AutoClicker::keyboardStartClick);
}

void AutoClicker::panelChange() {
    if (ui->mouseOption->isChecked() == false) {
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        ui->stackedWidget->setCurrentIndex(0);
    }
}
UINT qtModtoWinMod(Qt::KeyboardModifiers modifiers) {
    UINT winMod = 0;
    if (modifiers & Qt::ControlModifier) winMod |= MOD_CONTROL;
    if (modifiers & Qt::ShiftModifier) winMod |= MOD_SHIFT;
    if (modifiers & Qt::AltModifier) winMod |= MOD_ALT;
    if (modifiers & Qt::MetaModifier) winMod |= MOD_WIN;
    return winMod;
}
UINT qtKeytoWinKey(int qtKey) {
    switch (qtKey) {
        case Qt::Key_F1: return VK_F1;
        case Qt::Key_F2: return VK_F2;
        case Qt::Key_F3: return VK_F3;
        case Qt::Key_F4: return VK_F4;
        case Qt::Key_F5: return VK_F5;
        case Qt::Key_F6: return VK_F6;
        case Qt::Key_F7: return VK_F7;
        case Qt::Key_F8: return VK_F8;
        case Qt::Key_F9: return VK_F9;
        case Qt::Key_F10: return VK_F10;
        case Qt::Key_F11: return VK_F11;
        case Qt::Key_F12: return VK_F12;
        case Qt::Key_F13: return VK_F13;
        case Qt::Key_F14: return VK_F14;
        case Qt::Key_F15: return VK_F15;
        case Qt::Key_F16: return VK_F16;
        case Qt::Key_F17: return VK_F17;
        case Qt::Key_F18: return VK_F18;
        case Qt::Key_F19: return VK_F19;
        case Qt::Key_F20: return VK_F20;
        case Qt::Key_F21: return VK_F21;
        case Qt::Key_F22: return VK_F22;
        case Qt::Key_F23: return VK_F23;
        case Qt::Key_F24: return VK_F24;

        case Qt::Key_A: return 'A';
        case Qt::Key_B: return 'B';
        case Qt::Key_C: return 'C';
        case Qt::Key_D: return 'D';
        case Qt::Key_E: return 'E';
        case Qt::Key_F: return 'F';
        case Qt::Key_G: return 'G';
        case Qt::Key_H: return 'H';
        case Qt::Key_I: return 'I';
        case Qt::Key_J: return 'J';
        case Qt::Key_K: return 'K';
        case Qt::Key_L: return 'L';
        case Qt::Key_M: return 'M';
        case Qt::Key_N: return 'N';
        case Qt::Key_O: return 'O';
        case Qt::Key_P: return 'P';
        case Qt::Key_Q: return 'Q';
        case Qt::Key_R: return 'R';
        case Qt::Key_S: return 'S';
        case Qt::Key_T: return 'T';
        case Qt::Key_U: return 'U';
        case Qt::Key_V: return 'V';
        case Qt::Key_W: return 'W';
        case Qt::Key_X: return 'X';
        case Qt::Key_Y: return 'Y';
        case Qt::Key_Z: return 'Z';

        case Qt::Key_Minus:        return VK_OEM_MINUS;
        case Qt::Key_Plus:         return VK_OEM_PLUS;
        case Qt::Key_Comma:        return VK_OEM_COMMA;
        case Qt::Key_Period:       return VK_OEM_PERIOD;
        case Qt::Key_Semicolon:    return VK_OEM_1;
        case Qt::Key_Slash:        return VK_OEM_2;
        case Qt::Key_QuoteLeft:    return VK_OEM_3;
        case Qt::Key_BracketLeft:  return VK_OEM_4;
        case Qt::Key_Backslash:    return VK_OEM_5;
        case Qt::Key_BracketRight: return VK_OEM_6;
        case Qt::Key_Apostrophe:   return VK_OEM_7;

        case Qt::Key_0: return '0';
        case Qt::Key_1: return '1';
        case Qt::Key_2: return '2';
        case Qt::Key_3: return '3';
        case Qt::Key_4: return '4';
        case Qt::Key_5: return '5';
        case Qt::Key_6: return '6';
        case Qt::Key_7: return '7';
        case Qt::Key_8: return '8';
        case Qt::Key_9: return '9';
        default: return 0;
    }
}
// Mouse
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
    int speed = getClickSpeed(0);
    running = 1;
    disconnect(m_filter, &NativeEventFilter::hotkeyPressed, this, &AutoClicker::StartClick);
    connect(m_filter, &NativeEventFilter::hotkeyPressed, this, &AutoClicker::StopClick);
    qDebug() << "Started";
    std::thread t(&AutoClicker::click, this, speed);
    t.detach();
    ui->activateKeyButton->setEnabled(false);
    ui->ButtonStart->setEnabled(false);
    ui->ButtonStop->setEnabled(true);
    ui->changeMouseInpButton->setEnabled(false);

}
void AutoClicker::StopClick() {
    running = 0;
    disconnect(m_filter, &NativeEventFilter::hotkeyPressed, this, &AutoClicker::StopClick);
    connect(m_filter, &NativeEventFilter::hotkeyPressed, this, &AutoClicker::StartClick);
    ui->activateKeyButton->setEnabled(true);
    ui->ButtonStart->setEnabled(true);
    ui->ButtonStop->setEnabled(false);
    ui->changeMouseInpButton->setEnabled(true);
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

int AutoClicker::getClickSpeed(bool type) {
    if (type == 0) {
        QString ClickSpeedText = ui->InpClickSpeed->text();
        int ClickSpeed = ClickSpeedText.toInt();
        if (ClickSpeed <= 0) return 1;
        else return ClickSpeed;
    } else {
        QString ClickSpeedText = ui->KInpClickSpeed->text();
        int ClickSpeed = ClickSpeedText.toInt();
        if (ClickSpeed <= 0) return 1;
        else return ClickSpeed;
    }
}
void AutoClicker::enableMouseHotKeyChangeListen() {
    qDebug() << "Listening for mouse hotkey...";
    ui->activateKeyButton->setEnabled(false);
    ui->Header->setEnabled(false);
    listeningForMouseHotKey = 1;
    this->setFocus();
}
void AutoClicker::disableMouseHotKeyChangeListen() {
    qDebug() << "Listening for mouse hotkey...";
    ui->activateKeyButton->setEnabled(true);
    ui->Header->setEnabled(true);
    listeningForMouseHotKey = 0;
    this->setFocus();
}
// Keyboard
void AutoClicker::keyboardStartClick() {
    int speed = getClickSpeed(1);
    ui->KInpClickSpeed->setReadOnly(true);
    ui->KchangeInpButton->setEnabled(false);
    ui->KactivateKeyButton->setEnabled(false);
    ui->KButtonStart->setEnabled(false);
    ui->KButtonStop->setEnabled(true);
    disconnect(m_filter, &NativeEventFilter::keyboardHotkeyPressed, this, &AutoClicker::keyboardStartClick);
    connect(m_filter, &NativeEventFilter::keyboardHotkeyPressed, this, &AutoClicker::keyboardStopClick);
    running = 1;
    std::thread t(&AutoClicker::keyboardClick, this, speed);
    t.detach();
}
void AutoClicker::keyboardStopClick() {
    ui->KInpClickSpeed->setReadOnly(false);
    ui->KchangeInpButton->setEnabled(true);
    ui->KactivateKeyButton->setEnabled(true);
    ui->KButtonStart->setEnabled(true);
    ui->KButtonStop->setEnabled(false);
    disconnect(m_filter, &NativeEventFilter::keyboardHotkeyPressed, this, &AutoClicker::keyboardStopClick);
    connect(m_filter, &NativeEventFilter::keyboardHotkeyPressed, this, &AutoClicker::keyboardStartClick);
    running = 0;
}
void AutoClicker::keyboardClick(int speed) {
    WORD mainKey = (WORD)this->newKeyClick;
    UINT mods = this->newKeyClickModifiers;
    
    while (running == 1) {
        INPUT inputs[8] = {}; 
        int count = 0;
        
        if (mods & MOD_CONTROL) {
            inputs[count].type = INPUT_KEYBOARD;
            inputs[count].ki.wVk = VK_CONTROL;
            inputs[count].ki.dwFlags = 0; // Press Down
            count++;
        }
        if (mods & MOD_SHIFT) {
            inputs[count].type = INPUT_KEYBOARD;
            inputs[count].ki.wVk = VK_SHIFT;
            inputs[count].ki.dwFlags = 0;
            count++;
        }
        if (mods & MOD_ALT) {
            inputs[count].type = INPUT_KEYBOARD;
            inputs[count].ki.wVk = VK_MENU;
            inputs[count].ki.dwFlags = 0;
            count++;
        }
        
        inputs[count].type = INPUT_KEYBOARD;
        inputs[count].ki.wVk = mainKey;
        inputs[count].ki.dwFlags = 0;
        count++;
        
        inputs[count].type = INPUT_KEYBOARD;
        inputs[count].ki.wVk = mainKey;
        inputs[count].ki.dwFlags = KEYEVENTF_KEYUP;
        count++;
        
        if (mods & MOD_ALT) {
            inputs[count].type = INPUT_KEYBOARD;
            inputs[count].ki.wVk = VK_MENU;
            inputs[count].ki.dwFlags = KEYEVENTF_KEYUP;
            count++;
        }
        if (mods & MOD_SHIFT) {
            inputs[count].type = INPUT_KEYBOARD;
            inputs[count].ki.wVk = VK_SHIFT;
            inputs[count].ki.dwFlags = KEYEVENTF_KEYUP;
            count++;
        }
        if (mods & MOD_CONTROL) {
            inputs[count].type = INPUT_KEYBOARD;
            inputs[count].ki.wVk = VK_CONTROL;
            inputs[count].ki.dwFlags = KEYEVENTF_KEYUP;
            count++;
        }
        
        SendInput(count, inputs, sizeof(INPUT));
        Sleep(speed);
    }
}
void AutoClicker::keyPressEvent(QKeyEvent *event) {
    if (this->listeningForKeyClick) {
        if (event->key() == Qt::Key_Control ||
            event->key() == Qt::Key_Alt ||
            event->key() == Qt::Key_Shift ||
            event->key() == Qt::Key_Meta) { return; }
        if (event->key() == Qt::Key_Escape) {
            AutoClicker::disableKeyChangeListen();
            return;
        }
        int Hotkey = event->key();
        Qt::KeyboardModifiers KeyModifiers = event->modifiers();
        QKeySequence newKeySequence(KeyModifiers | Hotkey);
        QString sequenceString = newKeySequence.toString(QKeySequence::NativeText);
        ui->KKey->setText(sequenceString);
        this->newKeyClick = qtKeytoWinKey(event->key());
        this->newKeyClickModifiers = qtModtoWinMod(event->modifiers());

        AutoClicker::disableKeyChangeListen();
        event->accept();
        return;
    } else if (this->listeningForHotKey) {
        if (event->key() == Qt::Key_Control ||
            event->key() == Qt::Key_Alt ||
            event->key() == Qt::Key_Shift ||
            event->key() == Qt::Key_Meta) { return; }
        if (event->key() == Qt::Key_Escape) {
            AutoClicker::disableHotKeyChangeListen();
            return;
        }
        int Hotkey = event->key();
        Qt::KeyboardModifiers KeyModifiers = event->modifiers();
        QKeySequence newKeySequence(KeyModifiers | Hotkey);
        QString sequenceString = newKeySequence.toString(QKeySequence::NativeText);
        bool success;
        ui->KactivateKeyButton->setText(sequenceString);
        this->newHotKey = qtKeytoWinKey(event->key());
        this->newHotKeyModifiers = qtModtoWinMod(event->modifiers());
        UnregisterHotKey((HWND)this->winId(), 2);
        success = RegisterHotKey((HWND)this->winId(), 2, this->newHotKeyModifiers, this->newHotKey);
        AutoClicker::disableHotKeyChangeListen();
        if(success) qDebug() << "Hotkey updated successfully";
        else qDebug() << "Failed to register new hotkey";
        event->accept();
        return;
    } else if (this->listeningForMouseHotKey) {
        if (event->key() == Qt::Key_Control ||
            event->key() == Qt::Key_Alt ||
            event->key() == Qt::Key_Shift ||
            event->key() == Qt::Key_Meta) { return; }
        if (event->key() == Qt::Key_Escape) {
            AutoClicker::disableMouseHotKeyChangeListen();
            return;
        }
        int Hotkey = event->key();
        Qt::KeyboardModifiers KeyModifiers = event->modifiers();
        QKeySequence newKeySequence(KeyModifiers | Hotkey);
        QString sequenceString = newKeySequence.toString(QKeySequence::NativeText);
        bool success;
        ui->activateKeyButton->setText(sequenceString);
        this->newMouseHotKey = qtKeytoWinKey(event->key());
        this->newMouseHotKeyModifiers = qtModtoWinMod(event->modifiers());
        UnregisterHotKey((HWND)this->winId(), 1);
        success = RegisterHotKey((HWND)this->winId(), 1, this->newMouseHotKeyModifiers, this->newMouseHotKey);
        AutoClicker::disableMouseHotKeyChangeListen();
        if(success) qDebug() << "Hotkey updated successfully";
        else qDebug() << "Failed to register new hotkey";
        event->accept();
        return;
    }
    QMainWindow::keyPressEvent(event);
}
void AutoClicker::enableKeyChangeListen() {
    qDebug() << "Listening for key...";
    ui->KactivateKeyButton->setEnabled(false);
    ui->KchangeInpButton->setEnabled(false);
    ui->Header->setEnabled(false);
    listeningForKeyClick = 1;
    this->setFocus();
}
void AutoClicker::enableHotKeyChangeListen() {
    qDebug() << "Listening for hotkey...";
    ui->KactivateKeyButton->setEnabled(false);
    ui->KchangeInpButton->setEnabled(false);
    ui->Header->setEnabled(false);
    listeningForHotKey = 1;
    this->setFocus();
}
void AutoClicker::disableKeyChangeListen() {
    qDebug() << "Stopped listening for hotkey.";
    ui->KactivateKeyButton->setEnabled(true);
    ui->KchangeInpButton->setEnabled(true);
    ui->Header->setEnabled(true);
    listeningForKeyClick = 0;
}
void AutoClicker::disableHotKeyChangeListen() {
    qDebug() << "Listening for hotkey...";
    ui->KactivateKeyButton->setEnabled(true);
    ui->KchangeInpButton->setEnabled(true);
    ui->Header->setEnabled(true);
    listeningForHotKey = 0;
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
