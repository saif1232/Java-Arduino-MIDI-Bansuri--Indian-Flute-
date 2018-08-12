


void noteOn(byte channel, byte pitch, byte velocity) {
  MIDIEvent noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MIDIUSB.write(noteOn);
}


void controlChange(byte channel, byte control, byte value) {
  MIDIEvent event = {0x0B, 0xB0 | channel, control, value};
  MIDIUSB.write(event);
}

///Global variables
const int buttonPin2 = 2;
const int buttonPin3 = 3;
const int buttonPin4 = 4;
const int buttonPin5 = 5;
const int buttonPin6 = 6;
const int buttonPin7 = 7;

int buttonState2 = HIGH;
int buttonState3 = HIGH;
int buttonState4 = HIGH;
int buttonState5 = HIGH;
int buttonState6 = HIGH;
int buttonState7 = HIGH;

int Currentnote = 20;
int Previousnote = 20; 

int sensorValue = 0;
bool notesoff = false;

void setup() {
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);
  Serial.begin(9600);    ////////////////////////////////////allow me to test
  controlChange(0, 126, 0); //mono mode
}

void loop() {
sensorValue = analogRead(A1)/8;

  if(sensorValue > 50){ /// turns all notes off if sensor value not high enough
    if (notesoff == false){
controlChange(0, 123, 0);
notesoff=true;
 Currentnote = 20;
 Previousnote = 20;
    }
  }
   
  if(sensorValue < 48){ ////////////////////////////////////////////////////////THIS MEANS NOTE IS BEING PLAYED

    int vol = map(sensorValue, 15, 48, 50, 127);///////////////////need to remap sensor value for cc7 volume
    controlChange(0, 7, vol);
    notesoff=false;
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2 == HIGH && Previousnote != 0){
controlChange(0, 123, 0);
      noteOn(0, 57, 127); //No Buttons
    Currentnote = 0;    
     MIDIUSB.flush();
      }

    buttonState2 = digitalRead(buttonPin2);buttonState3 = digitalRead(buttonPin3);
  delay(20);
    if (buttonState2 == LOW && buttonState3 == HIGH && Previousnote != 1){
      controlChange(0, 123, 0);
       noteOn(0, 64, sensorValue);
         Currentnote = 1;
       MIDIUSB.flush();
      }

    buttonState2 = digitalRead(buttonPin2);buttonState3 = digitalRead(buttonPin3);buttonState4 = digitalRead(buttonPin4);
   delay(20);
    if (buttonState2 == LOW && buttonState3 == LOW && buttonState4 == HIGH  && Previousnote != 2){
       controlChange(0, 123, 0);
        noteOn(0, 62, 127); //BUTTON 20
        Currentnote = 2;
       MIDIUSB.flush();
      }

    buttonState2 = digitalRead(buttonPin2);buttonState3 = digitalRead(buttonPin3);buttonState4 = digitalRead(buttonPin4);buttonState5 = digitalRead(buttonPin5);
   delay(20);
    if (buttonState2 == LOW && buttonState3 == LOW && buttonState4 == LOW && buttonState5 == HIGH  && Previousnote != 3){
       controlChange(0, 123, 0);
        noteOn(0, 60, 127); //BUTTON 3
         Currentnote = 3;
       MIDIUSB.flush();
      }
      
    buttonState2 = digitalRead(buttonPin2);buttonState3 = digitalRead(buttonPin3);buttonState4 = digitalRead(buttonPin4);buttonState5 = digitalRead(buttonPin5);buttonState6 = digitalRead(buttonPin6);
   delay(20);
    if (buttonState2 == LOW && buttonState3 == LOW && buttonState4 == LOW && buttonState5 == LOW && buttonState6 == HIGH){
       controlChange(0, 123, 0);
        noteOn(0, 59, 127); //BUTTON 4
        MIDIUSB.flush();
      }
      
    buttonState2 = digitalRead(buttonPin2);buttonState3 = digitalRead(buttonPin3);buttonState4 = digitalRead(buttonPin4);buttonState5 = digitalRead(buttonPin5);buttonState6 = digitalRead(buttonPin6);buttonState7 = digitalRead(buttonPin7);
    delay(20);
    if (buttonState2 == LOW && buttonState3 == LOW && buttonState4 == LOW && buttonState5 == LOW && buttonState6 == LOW && buttonState7 == HIGH){
       controlChange(0, 123, 0);
        noteOn(0, 69, 127); //BUTTON 5
       MIDIUSB.flush();
      }

     buttonState2 = digitalRead(buttonPin2);buttonState3 = digitalRead(buttonPin3);buttonState4 = digitalRead(buttonPin4);buttonState5 = digitalRead(buttonPin5);buttonState6 = digitalRead(buttonPin6);buttonState7 = digitalRead(buttonPin7);
   delay(20);
    if (buttonState2 == LOW && buttonState3 == LOW && buttonState4 == LOW && buttonState5 == LOW && buttonState6 == LOW && buttonState7 == LOW){
       controlChange(0, 123, 0);
        noteOn(0, 67, 127); //BUTTON 6
       MIDIUSB.flush(); 
      }
      Previousnote = Currentnote;
  }
}

//  // LINK FOR HELPFUL STUFF http://www.bansuriflute.co.uk/p/beginners-how-to-play-bansuri.html
// http://www.somascape.org/midi/tech/spec.html#ctrlnums


