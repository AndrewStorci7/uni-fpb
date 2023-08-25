#include <iostream>
using namespace std;

class Radio {
private:
    bool stato;         // Accesa o Spenta
    int volume;         // Volume (0-30)
    float freq;         // Frequenza radio
public:
    Radio() {
        stato = false;
        volume = 5;
        freq = 108.5;
    }

    Radio(int v, float f) {
        this->stato = true;
        this->volume = v;
        this->freq = f;
    }

    void incFreq() { this->freq += 0.5; }

    void decFreq() { this->freq -= 0.5; }

    void incVolume() {
        if (this->volume < 30)
            this->volume += 1;
    }

    void decVolume() {
        if (this->volume > 0)
            this->volume -= 1;
    }

    void changeStato() { this->stato = (this->stato) ? false : true; }

    void stampaRadio() {
        string s = (this->stato) ? "Accesa" : "Spenta";
        cout << "ClassC++ {"
                "\n\tStatus: " << s <<
                "\n\tVolume: " << this->volume <<
                "\n\tFrequency: " << this->freq <<
                "\n}\n";
    }
};

int main() {
    Radio* radio = new Radio();
    cout << "Initial ClassC++: " << endl;
    int c = 0;
    do {
        radio->stampaRadio();
        cout << "\n\nOperazioni Disponibili: "
                "\n\t1- Accendi/Spegni radio"
                "\n\t2- Cambia frequenza"
                "\n\t3- Cambia volume"
                "\n(digita -1 per uscire) >> ";
        cin >> c;
        switch (c) {
            case 1:
                radio->changeStato();
                break;
            case 2: {
                int c = 0;
                cout << "Come desideri cambiare la frequenza: "
                        "\n\t1- Aumentare"
                        "\n\t2- Diminuire"
                        "\n> ";
                cin >> c;
                switch (c) {
                    case 1:
                        radio->incFreq();
                        break;
                    case 2:
                        radio->decFreq();
                        break;
                    default:
                        radio->incFreq();
                        break;
                }
            }
                break;
            case 3: {
                int c = 0;
                cout << "Come desideri cambiare il volume: "
                        "\n\t1- Aumentare"
                        "\n\t2- Diminuire"
                        "\n> ";
                cin >> c;
                switch (c) {
                    case 1:
                        radio->incVolume();
                        break;
                    case 2:
                        radio->decVolume();
                        break;
                    default:
                        radio->incVolume();
                        break;
                }
            }
                break;
            default:
                c = -1;
                break;
        }
    } while (c != -1);
    return 0;
}
