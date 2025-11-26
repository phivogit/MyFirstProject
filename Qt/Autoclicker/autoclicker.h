#ifndef AUTOCLICKER_H
#define AUTOCLICKER_H

#include <QMainWindow>
#include <windows.h>
#include "nativeeventfilter.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AutoClicker;
}
QT_END_NAMESPACE

class AutoClicker : public QMainWindow
{
    Q_OBJECT
protected:
    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
public:
    AutoClicker(QWidget *parent = nullptr);
    ~AutoClicker();
private slots:
    void handleMouseChange();
    int getClickSpeed(bool type);
    void StartClick();
    void StopClick();
    void keyboardStartClick();
    void keyboardStopClick();
    void click(int speed);
    void keyboardClick(int speed);
    void panelChange();
    void enableKeyChangeListen();
    void disableKeyChangeListen();
    void enableMouseHotKeyChangeListen();
    void disableMouseHotKeyChangeListen();
    void enableHotKeyChangeListen();
    void disableHotKeyChangeListen();

private:
    Ui::AutoClicker *ui;
    int mouseState = 0;
    bool running = 0;
    bool listeningForKeyClick = 0;
    bool listeningForMouseHotKey = 0;
    bool listeningForHotKey = 0;
    NativeEventFilter *m_filter;
    int newKeyClick = 0;
    UINT newKeyClickModifiers = Qt::NoModifier;
    int newMouseHotKey = 0;
    UINT newMouseHotKeyModifiers = Qt::NoModifier;
    int newHotKey = 0;
    UINT newHotKeyModifiers = Qt::NoModifier;
};
#endif // AUTOCLICKER_H
