/*
  ==============================================================================

    Voice.cpp
    Created: 4 Jun 2016 6:53:08pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "Voice.h"
#include "Math.h"

Voice::Voice() {
    this->calculateFrequencyTable();
}

Voice::~Voice() {
    
}

void Voice::setNote(Note* note) {
    this->note = note;
    this->noteNumber = note->getMidiNote();
    this->velocity = note->getVelocity();
    for(std::vector<Oszillator*>::iterator it = oscillators.begin(); it != oscillators.end(); ++it) {
        Oszillator* o = *it;
        o->setFrequency(midiNote[note->getMidiNote() + o->getPitch()]);
    }
}

Note* Voice::getNote() const {
    return this->note;
}

void Voice::addOszillator(Oszillator* o) {
    this->oscillators.push_back(o);
}

vector<Oszillator*> Voice::getOszillators() const {
    return this->oscillators;
}

float Voice::process() {
    
    float value = 0;
    float amplitude = (1.0f / (float) 127) * this->velocity;
    
    for(std::vector<Oszillator*>::iterator it = oscillators.begin(); it != oscillators.end(); ++it) {
        Oszillator* o = *it;
        value += o->process();
    }
    
    value = (value / oscillators.size()) * amplitude;
    
    return value;
    
}

void Voice::setNoteNumber(int number) {
    this->noteNumber = number;
}

int Voice::getNoteNumber() const {
    return this->noteNumber;
}

void Voice::setPitch(int number) {
    this->pitch = number;
}

int Voice::getPitch() const {
    return this->pitch;
}

void Voice::updateOscillator(int index) {
    oscillators.at(index)->setFrequency(midiNote[this->noteNumber + oscillators.at(index)->getPitch()]);
}

void Voice::calculateFrequencyTable() {
    int a = 440; // a is 440 hz...
    for (int x = 0; x < 127; ++x)
    {
        midiNote[x] = a * pow(2.0,(x-69.0)/12.0);
    }
}