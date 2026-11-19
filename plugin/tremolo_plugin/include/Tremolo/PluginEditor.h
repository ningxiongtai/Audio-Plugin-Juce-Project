#pragma once
#include "LfoVisualizer.h"
#include "RateSlider.h"

namespace tremolo {
class PluginEditor : public juce::AudioProcessorEditor {
public:
  explicit PluginEditor(PluginProcessor&);
  ~PluginEditor() override;
  void resized() override;

private:
  juce::ImageComponent background;
  juce::ImageComponent logo;

  juce::ComboBox waveformComboBox;
  juce::ComboBoxParameterAttachment waveformAttachment;

  juce::Slider rateSlider;
  juce::SliderParameterAttachment sliderAttachment;

  juce::ToggleButton bypassButton {"Bypassed"};
  juce::ButtonParameterAttachment bypassButtonAttachment;

  LfoVisualizer lfoVisiualizer;

  CustomLookAndFeel customLookAndFeel;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
}  // namespace tremolo
