/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_FC206EB6C4DA2904__
#define __JUCE_HEADER_FC206EB6C4DA2904__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class FXPanel  : public Component,
                 public SliderListener,
                 public ButtonListener
{
public:
    //==============================================================================
    FXPanel (TrioAudioProcessor* p);
    ~FXPanel();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* fx_panel_png;
    static const int fx_panel_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    TrioAudioProcessor* processor;

    ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> fxreverb_enabled_att;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> fxreverb_damping_att;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> fxreverb_drylevel_att;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> fxreverb_wetlevel_att;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> fxreverb_freeze_att;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> fxreverb_size_att;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> fxreverb_width_att;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> dampSlider;
    ScopedPointer<Slider> freezeSlider;
    ScopedPointer<Slider> sizeSlider;
    ScopedPointer<Slider> widthSlider;
    ScopedPointer<Slider> wetSlider;
    ScopedPointer<Slider> drySlider;
    ScopedPointer<ToggleButton> enableDelayButton;
    Image cachedImage_fx_panel_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FXPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_FC206EB6C4DA2904__
