# This Python file uses the following encoding: utf-8

# if__name__ == "__main__":
#     pass
from pydub import AudioSegment
import glob
#AudioSegment.ffmpeg = "C:\\ffmpeg\\bin\\ffmpeg.exe"
#AudioSegment.ffmpeg ="C:\\Users\\lucas\\AppData\\Local\\Programs\\Python\\Python36-32\\Lib\\site-packages\\ffmpeg\\ffmpeg.exe\\bin\\ffmpeg.exe"
def mix(audio,audio2,fileLocal):
        sound1 = AudioSegment.from_wav(audio)
        sound2 = AudioSegment.from_wav(audio2)
        combined_sounds = sound1 + sound2
        combined_sounds.export(fileLocal+"/teste1.wav", format="wav")
        print("oi")
print("chau")
def arquivos_exibe():
    for f in glob.glob('*.*'):
        print(f)

