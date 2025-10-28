#ifndef NATIVEEVENTFILTER_H
#define NATIVEEVENTFILTER_H

#include <QObject>
#include <QAbstractNativeEventFilter>

class NativeEventFilter : public QObject, public QAbstractNativeEventFilter {
    Q_OBJECT
public:
    explicit NativeEventFilter(QObject *parent = nullptr);
    bool nativeEventFilter(const QByteArray &eventType, void *message, qintptr *result) override;
signals:
    void hotkeyPressed();
};

#endif // NATIVEEVENTFILTER_H
