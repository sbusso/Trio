/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oszillator.h"
#include "MultimodeOscillator.h"
#include "Voice.h"
#include "ADSR.h"
#include "MultimodeFilter.h"
#include "Model.h"

#include <stack>
#include <vector>
#include "ADSR.h"
#include "Distortion.h"
#include "StereoDelay.h"
#include "StereoReverb.h"
#include "Sequencer.h"


using namespace std;

//==============================================================================
/**
*/
class TrioAudioProcessor  : public AudioProcessor, public AudioProcessorValueTreeState::Listener, public ComboBox::Listener, public ChangeBroadcaster
{
public:
    
    enum ModulatorType {
        ENV,
        LFO1,
        LFO2,
        SEQUENCER
    };
    
    //==============================================================================
    TrioAudioProcessor();
    ~TrioAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    // bool setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet) override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;
    void processSequencer(double sampleRate, int numSamples);
    void processMidi(MidiBuffer& midiMessages);
    void processModulation();
    void processFX(float* left, float* right, int numSamples);
    void processLFOs();
    
    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void parameterChanged(const String &parameterID, float newValue) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    
    StereoDelay* getStereoDelay();

    MultimodeFilter* getFilter();
    ADSR* getFilterEnv();
    Model* getModel();
    ScopedPointer<StereoReverb> reverb;
    ScopedPointer<Distortion> distortion;
    Reverb::Parameters reverbParams;    
    
    AudioProcessorValueTreeState* getValueTreeState();
    void setState(ValueTree* state, bool notify);
    StereoReverb* getReverb();
    Distortion* getDistortion();
    
    vector<String> getProgramNames();
    String getSelectedProgram();
    void setSelectedProgram(String program);
    
    void selectFilterModulator(ModulatorType type);
    
    void configureOscillators(Oszillator::OscMode mode1, Oszillator::OscMode mode2, Oszillator::OscMode mode3);
    void setupOscillators(Oszillator::OscMode mode1, Oszillator::OscMode mode2, Oszillator::OscMode mode3);
	void setupOscillator(int osc,Oszillator::OscMode mode);
    Oszillator* createOscillator(Oszillator::OscMode mode);
    void cleanupVoices();
    
    void setFxReverbEnabled(bool enabled);
    void setFxDelayEnabled(bool enabled);
    void setFxDistEnabled(bool enabled);
	void addProgram(String name);

	void updateParam(const juce::String &parameterID, float newValue);

    Sequencer* getSequencer();
    vector<AudioProcessorParameter*> registeredParams;
   
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrioAudioProcessor)
    
    double sampleRate;
    int samplesPerBlock;
    
    float globalPitch;
    float elapsed;
    float lastTime;
    float currentTime;
    float deltaTime;
    float bpm;
    
    float lastppq;
    float currentppq;
    float deltappq;
    
    int tick;
    int lastTick;
    
    vector<StereoEffect*> effects;
    
    ScopedPointer<MultimodeFilter> multimodeFilter;
    ScopedPointer<MultimodeFilter> outputFilter;

    
    ScopedPointer<StereoDelay> stereoDelay;
    
    IIRCoefficients ic;
    
    float filterCutoff;
    
    vector<Voice*> voices;
    int getVoicesPlaying();
    ScopedPointer<ADSR> filterEnvelope;
    Model* model;
    Sine* lfo1;
    Sine* lfo2;
    
    ScopedPointer<AudioProcessorValueTreeState> parameters;
    juce::AudioPlayHead::CurrentPositionInfo result;
    
    vector<String> programNames;
    String selectedProgram;
    vector<Voice*> getVoices() const;
    int currentProgramNumber;
    
    ComboBox* programCombo = 0;
   
    ScopedPointer<Sequencer> sequencer;
    
    int octave = 0;
    
    bool fxReverbEnabled;
    bool fxDelayEnabled;
    bool fxDistortionEnabled;
    
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
