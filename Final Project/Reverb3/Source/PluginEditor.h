/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Reverb3AudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Slider::Listener
{
public:
    Reverb3AudioProcessorEditor (Reverb3AudioProcessor&);
    ~Reverb3AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    void sliderValueChanged (juce::Slider* slider) override;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Reverb3AudioProcessor& audioProcessor;
    
    juce::Slider roomSize;
    juce::Slider damping;
    juce::Slider wetLevel;
    juce::Slider dryLevel;
    juce::Slider width;
    juce::Slider freeze;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Reverb3AudioProcessorEditor)
};
