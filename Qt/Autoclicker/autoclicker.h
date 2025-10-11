#ifndef AUTOCLICKER_H
#define AUTOCLICKER_H

#include <QMainWindow>
#include <windows.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class AutoClicker;
}
QT_END_NAMESPACE

class AutoClicker : public QMainWindow
{
    Q_OBJECT

public:
    AutoClicker(QWidget *parent = nullptr);
    ~AutoClicker();
private slots:
    void handleMouseChange();
    int getClickSpeed();
    void StartClick();
    void StopClick();
    void click(int speed, INPUT &click, INPUT &release);

private:
    Ui::AutoClicker *ui;
    int mouseState = 0;
    bool running = 0;
};
#endif // AUTOCLICKER_H
