#ifndef VMOUSECONTROL_H
#define VMOUSECONTROL_H

#include <QThread>
#include <QProcess>
#include <QPointer>
#include <QVector>
#include <QTcpServer>

class QIODevice;
class VMouseControl : public QObject
{
    Q_OBJECT
public:
    enum VMouseState
    {
        SHOW = 1,
        HIDE = 2
    };

    explicit VMouseControl(QObject *parent = nullptr);
    ~VMouseControl();

    bool start(const QString& serial, int port);
    void stop();
    void installonly(const QString& serial, int port);
    void sendMsg(VMouseState state,int xLocal,int yLocal,int xSize,int ySize);
    QTcpSocket *getVMouseSocket();

private:
    bool runVMouseProcess(const QString& serial, int port, bool wait = true);
    void startVMouse(int port);
    void stopVMouse();

signals:
    void connectTo(int port);
    void sendCtrMsg(const QByteArray &buffer);

private:
    QThread m_workerThread;
    QProcess m_vmouse;
    QVector<char> m_buffer;
    bool m_running = false;
};

#endif // VMOUSECONTROL_H
