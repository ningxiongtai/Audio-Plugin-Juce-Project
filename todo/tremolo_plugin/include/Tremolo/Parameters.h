#pragma once

namespace tremolo {
struct Parameters {
  explicit Parameters(juce::AudioProcessor&);

  juce::AudioParameterFloat& rate;
  JUCE_DECLARE_NON_COPYABLE(Parameters);

  //void JUCE_DECLARE_NON_MOVABLE(Parameters);

};
}  // namespace tremolo
