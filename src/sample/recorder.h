#ifndef RECORDER_H
#define RECORDER_H

#include <QAudioInput>
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <exception>
using std::exception;

class Recorder : public QObject
{
	Q_OBJECT
    QAudioInput *audio;
	QFile file;
	QTimer timer;

	void initialiseRecorder();
	void setupTimer();
    void printAvailableDevices();
    void setFormatSettings(QAudioFormat *format);
	void openFile(const QString &fileName);
	void closeFile();
public:
	Recorder();
    ~Recorder();
    void Start();
public slots:
	void Stop();
signals:
	void recordingStopped(qint64 savedBytes);
};

#endif // RECORDER_H
