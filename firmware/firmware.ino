#include "HID-Project.h"

// PIN MAPPINGS
byte rows[] = {3, 7, 9, 10, 14, 18, 20};

byte currState[] = {1, 1, 1, 1, 1, 1, 1};

const int CMD_DELAY = 10;
const int BAUD_RATE = 115200;

const int ROW_COUNT = sizeof(rows) / sizeof(rows[0]);

byte keys[ROW_COUNT];

void setup()
{
    Keyboard.begin();
    setInitialPinModes();
}

void loop()
{
    readKeysFromCurrentArduino();
    delay(CMD_DELAY);
}

void setInitialPinModes()
{
    for (int x = 0; x < ROW_COUNT; x++)
    {
        pinMode(rows[x], INPUT_PULLUP);
    }
}

void noop() {}

void readKeysFromCurrentArduino()
{
    for (int i = 0; i < ROW_COUNT; i++)
    {
        byte rowCol = rows[i];
        byte state = digitalRead(rowCol);
        if (currState[i] != state) {
            currState[i] = state;
            if (state == 0)
                onPress(i);
            else
                onRelease(i);
        }
    }
}

void onPress(int index)
{
    if (index == 0)
        Keyboard.press(KEY_S);
    else if (index == 1)
        Keyboard.press(KEY_B);
    else if (index == 2)
        Keyboard.press(KEY_C);
    else if (index == 3)
        Keyboard.press(KEY_D);
    else if (index == 4)
        Keyboard.press(KEY_E);
    else if (index == 5)
        Keyboard.press(KEY_VOLUME_DOWN);
    else if (index == 6)
        Keyboard.press(KEY_VOLUME_UP);
}

void onRelease(int index)
{
    if (index == 0)
        noop();
    else if (index == 1)
        noop();
    else if (index == 2)
        noop();
    else if (index == 3)
        noop();
    else if (index == 4)
        noop();
    else if (index == 5)
        noop();
    else if (index == 6)
        noop();
    Keyboard.releaseAll();
}
