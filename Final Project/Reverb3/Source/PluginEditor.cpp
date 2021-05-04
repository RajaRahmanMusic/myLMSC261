/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Reverb3AudioProcessorEditor::Reverb3AudioProcessorEditor (Reverb3AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 450);
    
    // these define the parameters of our room size object
    roomSize.setSliderStyle (juce::Slider::LinearVertical);
    roomSize.setRange (0.0, 1.0, 0.01);
    roomSize.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 37.5);
    roomSize.setPopupDisplayEnabled (true, false, this);
    roomSize.setTextValueSuffix (" Room Size");
    roomSize.setValue(0.5);
    
    // these define the parameters of our damping object
    damping.setSliderStyle (juce::Slider::LinearVertical);
    damping.setRange (0.0, 1.0, 0.01);
    damping.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 37.5);
    damping.setPopupDisplayEnabled (true, false, this);
    damping.setTextValueSuffix (" Damping");
    damping.setValue(0.0);
    
    // these define the parameters of our Wet Level object
    wetLevel.setSliderStyle (juce::Slider::LinearVertical);
    wetLevel.setRange (0.0, 1.0, 0.01);
    wetLevel.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 37.5);
    wetLevel.setPopupDisplayEnabled (true, false, this);
    wetLevel.setTextValueSuffix (" Wet Level");
    wetLevel.setValue(1.0);

    // these define the parameters of our dry level object
    dryLevel.setSliderStyle (juce::Slider::LinearVertical);
    dryLevel.setRange (0.0, 1.0, 0.01);
    dryLevel.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 37.5);
    dryLevel.setPopupDisplayEnabled (true, false, this);
    dryLevel.setTextValueSuffix (" Dry Level");
    dryLevel.setValue(0.0);
    
    // these define the parameters of our width object
    width.setSliderStyle (juce::Slider::LinearVertical);
    width.setRange (0.0, 1.0, 0.01);
    width.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 37.5);
    width.setPopupDisplayEnabled (true, false, this);
    width.setTextValueSuffix (" Width");
    width.setValue(0.0);
    
    // these define the parameters of our freeze object
    freeze.setSliderStyle (juce::Slider::LinearVertical);
    freeze.setRange (0.0, 1.0, 1.0);
    freeze.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 37.5);
    freeze.setPopupDisplayEnabled (true, false, this);
    freeze.setTextValueSuffix (" Freeze");
    freeze.setValue(0.0);
    
    // this function adds the slider to the editor
    addAndMakeVisible (&roomSize);
    addAndMakeVisible (&damping);
    addAndMakeVisible (&wetLevel);
    addAndMakeVisible (&dryLevel);
    addAndMakeVisible (&width);
    addAndMakeVisible (&freeze);
    
    // add the listener to the slider
    roomSize.addListener (this);
    damping.addListener (this);
    wetLevel.addListener (this);
    dryLevel.addListener (this);
    width.addListener (this);
    freeze.addListener (this);
}
// This line is where the Slider values were supposed to override the default reverb settings as defined in the class reverb in the juce_Reverb.h file 
void Reverb3AudioProcessorEditor::sliderValueChanged (juce::Slider  * slider)
{
    audioProcessor.roomSize = roomSize.getValue();
}


Reverb3AudioProcessorEditor::~Reverb3AudioProcessorEditor()
{
}

//==============================================================================
void Reverb3AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (30.0f);
    g.drawFittedText ("DUMMYV3RB", getLocalBounds(), juce::Justification::centredTop, 1);
}

void Reverb3AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    // sets the position and size of the slider with arguments (x, y, width, height)
    roomSize.setBounds (112.5, 75, 75, getHeight() - 150);
    damping.setBounds (187.5, 75, 75, getHeight() - 150);
    wetLevel.setBounds (262.5, 75, 75, getHeight() - 150);
    dryLevel.setBounds (337.5, 75, 75, getHeight() - 150);
    width.setBounds (412.5, 75, 75, getHeight() - 150);
    freeze.setBounds (487.5, 75, 75, getHeight() - 150);
}
