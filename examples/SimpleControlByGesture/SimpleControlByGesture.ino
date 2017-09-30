/*
 * Copyright 2017, OYMotion Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 */
#include <gForceAdapter.h>

#define GFORCE_FIST_PIN 2
#define GFORCE_SPREAD_PIN 3
#define GFORCE_WAVEIN_PIN 4
#define GFORCE_WAVEOUT_PIN 5
#define GFORCE_PINCH_PIN 6
#define GFORCE_SHOOT_PIN 7

GForceAdapter gforce = GForceAdapter(Serial);

void setup() {
    // set pin mode to output
    pinMode(GFORCE_FIST_PIN, OUTPUT);
    pinMode(GFORCE_SPREAD_PIN, OUTPUT);
    pinMode(GFORCE_WAVEIN_PIN, OUTPUT);
    pinMode(GFORCE_WAVEOUT_PIN, OUTPUT);
    pinMode(GFORCE_PINCH_PIN, OUTPUT);
    pinMode(GFORCE_SHOOT_PIN, OUTPUT);

    // default set output low
    digitalWrite(GFORCE_FIST_PIN, LOW);
    digitalWrite(GFORCE_SPREAD_PIN, LOW);
    digitalWrite(GFORCE_WAVEIN_PIN, LOW);
    digitalWrite(GFORCE_WAVEOUT_PIN, LOW);
    digitalWrite(GFORCE_PINCH_PIN, LOW);
    digitalWrite(GFORCE_SHOOT_PIN, LOW);
    gforce.begin();
}

void loop() {
    GF_Data gForceData;
    if (OK == gforce.getGForceData(gForceData)) {

        GF_Gesture gesture;
        switch (gForceData.type) {
        case GF_Data::QUATERNION:
            break;
        case GF_Data::GESTURE:
            gesture = gForceData.value.gesture;
            if (gesture == GF_FIST) {
                digitalWrite(GFORCE_FIST_PIN, HIGH);
            } else if (gesture == GF_SPREAD) {
                digitalWrite(GFORCE_SPREAD_PIN, HIGH);
            } else if (gesture == GF_WAVEIN) {
                digitalWrite(GFORCE_WAVEIN_PIN, HIGH);
            } else if (gesture == GF_WAVEOUT) {
                digitalWrite(GFORCE_WAVEOUT_PIN, HIGH);
            } else if (gesture == GF_PINCH) {
                digitalWrite(GFORCE_PINCH_PIN, HIGH);
            } else if (gesture == GF_SHOOT) {
                digitalWrite(GFORCE_SHOOT_PIN, HIGH);
            } else if (gesture == GF_RELEASE) {
                digitalWrite(GFORCE_FIST_PIN, LOW);
                digitalWrite(GFORCE_SPREAD_PIN, LOW);
                digitalWrite(GFORCE_WAVEIN_PIN, LOW);
                digitalWrite(GFORCE_WAVEOUT_PIN, LOW);
                digitalWrite(GFORCE_PINCH_PIN, LOW);
                digitalWrite(GFORCE_SHOOT_PIN, LOW);
            } else if (gesture == GF_UNKNOWN) {
                digitalWrite(GFORCE_FIST_PIN, HIGH);
                digitalWrite(GFORCE_SPREAD_PIN, HIGH);
                digitalWrite(GFORCE_WAVEIN_PIN, HIGH);
                digitalWrite(GFORCE_WAVEOUT_PIN, HIGH);
                digitalWrite(GFORCE_PINCH_PIN, HIGH);
                digitalWrite(GFORCE_SHOOT_PIN, HIGH);
            }
            break;
        default:
            break;
        }
    }
}
