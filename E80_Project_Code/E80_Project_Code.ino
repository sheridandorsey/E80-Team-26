#define outputA 15
#define outputB 16
#define siliconPressure 17
#define waterPressure 18
#define current 22

int counter = 0;
int aState;
int alastState;
int delay = 1000;
// 0 for CW 1 for CCW
int currDirection = 0;

void setup() {

    Serial.begin(9600);

    // delays start time
    delay(delay);

    aLastState = analogRead(outputA);
}

void loop() {
    aState = analogRead(outputA);
    if (aState != aLastState && aState == 1) {
        if (analogRead(outputB) != aState) {
            counter--;
            currDirection = 1;
        } else {
            counter++;
            currDirection = 0;
        }
        Serial.print("Position: ");
        // needs to be converted to depth
        Serial.println(counter);
        Serial.print("Direction: ");
        Serial.println(currDirection)
    }
    aLastState = aState
}