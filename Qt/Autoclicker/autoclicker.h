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
    int getClickSpeed();
    void StartClick();
    void StopClick();
    void click(int speed);
    void panelChange();
    void enableKeyChangeListen();
    void disableKeyChangeListen();

private:
    Ui::AutoClicker *ui;
    int mouseState = 0;
    bool running = 0;
    bool listeningForKey = 0;
    NativeEventFilter *m_filter;
    int newHotkey = 0;
    Qt::KeyboardModifiers newKeyModifiers = Qt::NoModifier;
};
#endif // AUTOCLICKER_H
