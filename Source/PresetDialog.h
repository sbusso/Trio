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

#ifndef __JUCE_HEADER_9629A2AF4CBBA0BE__
#define __JUCE_HEADER_9629A2AF4CBBA0BE__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Model.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PresetDialog  : public Component,
public Button::Listener
{
public:
    //==============================================================================
    PresetDialog (ComboBox* presetBox);
    ~PresetDialog();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setData(ScopedPointer<XmlElement> xml);
    void visibilityChanged() override;
    void setVisible (bool shouldBeVisible) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ComboBox* presetBox;
    ScopedPointer<XmlElement> xml;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> okButton;
    ScopedPointer<TextButton> cancelButton;
    ScopedPointer<TextEditor> textEditor;
    ScopedPointer<Label> label;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetDialog)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_9629A2AF4CBBA0BE__
