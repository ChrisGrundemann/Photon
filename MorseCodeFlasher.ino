// which pin is our LED on?
int led = D0;

// set the duration(s)
int dot = 100;
int dash = dot * 3;
int pause = dot * 15;

// load morse code
String code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", // A-G
    "....", "..", ".---", "-.-", ".-..", "--", "-.", // H-N
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", // O-U
    "...-", ".--", "-..-", "-.--", "--.."            // V-Z
};


//-----------------------------------------------------------
// what message do you want to morse?
String message = "welcome home eva";
// change this ....^
//-----------------------------------------------------------



void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
    flashMessage(message);
    delay(pause);
}


// =============
// = functions =
// =============

// break the message down letter by letter
void flashMessage(String message) {
    for (int i = 0; i < message.length(); i++) {
        char letter = message.charAt(i);
        flashLetter(letter);
    }
}

// convert the letter to morse code
void flashLetter(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        flashDotsDashes(code[letter - 'a']);
    }
    if (letter >= 'A' && letter <= 'Z') {
        flashDotsDashes(code[letter - 'A']);
    }
    else if (letter == ' ') {
        delay(dot * 7); // gap between words
    }
}

// break the code into dots and dashes
void flashDotsDashes(String dotsDashes) {
    for (int i = 0; i < dotsDashes.length(); i++) {
        char dotORdash = dotsDashes.charAt(i);
        if (dotORdash == '.') {
            flash(dot);
        }
        else if (dotORdash = '-') {
            flash(dash);
        }
        else {
            flash(10000);
        }
        delay(dot); // gap between dots and dashes of one letter
    }
    delay(dash); // gap between letters
}

// the flasher - turns LED on and off
void flash(int duration) {
    digitalWrite(led, HIGH);
    delay(duration);
    digitalWrite(led, LOW);
}

// that's all folks
