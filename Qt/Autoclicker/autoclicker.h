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

private:
    Ui::AutoClicker *ui;
    int mouseState = 0;
    bool running = 0;
    NativeEventFilter *m_filter;
};
#endif // AUTOCLICKER_H
