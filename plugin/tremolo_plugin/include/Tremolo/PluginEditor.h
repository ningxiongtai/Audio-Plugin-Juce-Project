#pragma once
#include "LfoVisualizer.h"

namespace tremolo {
class PluginEditor : public juce::AudioProcessorEditor {
public:
  explicit PluginEditor(PluginProcessor&);

  void resized() override;

private:
  juce::ImageComponent background;
  juce::ImageComponent logo;

  LfoVisualizer lfoVisiualizer;
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
}  // namespace tremolo
