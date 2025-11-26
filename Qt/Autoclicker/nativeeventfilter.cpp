#include "nativeeventfilter.h"
#include <windows.h>

#define HOTKEY_ID 1
#define KEYBOARD_HOTKEY_ID 2

NativeEventFilter::NativeEventFilter(QObject *parent) : QObject(parent) {

}

bool NativeEventFilter::nativeEventFilter(const QByteArray &eventType, void *message, qintptr *result) {
    if (eventType == "windows_generic_MSG") {
        MSG *msg = static_cast<MSG *>(message);
        if (msg->message == WM_HOTKEY) {
            if (msg->wParam == HOTKEY_ID) {
                emit hotkeyPressed();
                return true;
            } else if (msg->wParam == KEYBOARD_HOTKEY_ID) {
                emit keyboardHotkeyPressed();
                return true;
            }
        }
    }
    return false;
}
