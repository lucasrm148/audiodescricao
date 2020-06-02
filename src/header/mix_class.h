#ifndef MIX_CLASS_H
#define MIX_CLASS_H
#include <QAudioRecorder>
#include <QString>
class QAudioRecorder;
class mix_class
{
public:
       mix_class();
       bool createAudio(QString fileDirectory,QString fileName="file.wav");
       bool audio_space(int time);
       bool audio_mix(QString audio1,QString audio2,QString fileLocal);
       FILE auido_retun();
private:
   QAudioRecorder *AudioRecorder;
   FILE file;
};

#endif // MIX_CLASS_H
