#include <iostream>
#include <cmath>
using namespace std;
/* kvnisnthere's simple playback speed to pitch calculator windows v1.0.2
*  made by kvnisnthere (AZMATIC)
*  simple calculator tool to help scale pitch with time
*  5-16-2024        */
//define values
float tempo1, tempo2, playback_speed, pitch;
int mode;
//reset values (for future update)
void resetValues () {
    tempo1 = 0;
    tempo2 = 0;
    playback_speed= 1;
    pitch = 0;
}
//input functions
void get_playback_speed() {
    cout << "enter playback speed: ";
    cin >> playback_speed;
}
void get_tempo1 () {
        cout << "input tempo:  ";
        cin >> tempo1;
}
void get_tempo2 () {
        cout << "input desired tempo: ";
        cin >> tempo2;
}
void get_pitch () {
    cout << "input pitch shift (in semitones) : ";
    cin >> pitch;
}
//math equations
void convert_pitch_to_playback_speed() {playback_speed= powf(2, pitch/12);}
void convert_playback_speed_to_pitch () {pitch = 12*log2f(playback_speed);}
void convert_playback_speed_to_tempo2 () {tempo2 = tempo1*playback_speed;}
//modes
void speed_mode () {
    cout << "\n--------------------------------------------------------------"
            "\nplayback speed mode:\n\n"
            "   *tempo is optional*   type 0 if no tempo \n\n";
    get_playback_speed();
    get_tempo1();
    convert_playback_speed_to_tempo2();
    convert_playback_speed_to_pitch();
    cout << "\n--------------------------------------------------------------"
            "\ntranspose: " << pitch <<" semitones\n""desired tempo: " << tempo2 <<"bpm \n\n";
    resetValues();
}
void tempo_mode() {
        cout <<"\n--------------------------------------------------------------"
               "\ntempo mode:\n\n";
        get_tempo1();
        get_tempo2();
        playback_speed= tempo2/tempo1;
        convert_playback_speed_to_pitch ();
        cout << "\n--------------------------------------------------------------"
                "\nplayback speed: " << playback_speed<<"x\npitch: " << pitch <<" semitones\n\n";
        resetValues();
    }
void pitch_mode () {
        cout << "\n--------------------------------------------------------------"
                "\npitch mode:\n\n"
                "   *tempo is optional*   type 0 if no tempo \n\n";
        get_pitch();
        get_tempo1();
        convert_pitch_to_playback_speed();
        convert_playback_speed_to_tempo2();
        cout << "\n--------------------------------------------------------------"
                "\nplayback speed: " << playback_speed<<"x\n""tempo: " << tempo2 <<"bpm \n\n";
        resetValues();
    }
void mode_select () {
        cout << "enter desired mode (number):   ";
        cin >> mode;
        switch (mode) {
            case 1:
                speed_mode();
                break;
            case 2:
                tempo_mode();
                break;
            case 3:
                pitch_mode();
                break;
            default:
                cout << "\nno mode selected";
        }
    }
int main() {
    cout <<
        "\n\nkvnisnthere's simple playback speed to pitch calculator v1.0.2"
        "\n--------------------------------------------------------------"
        "\n"
        "   mode select:\n"
        "\n"
        "       1: playback speed mode\n"
        "               playback speed & tempo* --> desired transpose & tempo\n"
        "\n"
        "       2: tempo mode\n"
        "               tempo & desired tempo --> time scale & pitch shift\n"
        "\n"
        "       3: pitch mode\n"
        "               pitch shift (semitones) & tempo* --> desired playback speed & tempo\n"
          "\n--------------------------------------------------------------"
        "\n*tempo not required"
        "\n\n";
    mode_select();
    cout << "\n\n---------------------------------------------------\n";
    system("pause");
    return 0;
}