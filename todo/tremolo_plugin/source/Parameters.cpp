
namespace tremolo {

auto& addParameterToProcessor(juce::AudioProcessor& processor, auto parameter) {
    auto& parameterReference = *parameter;
    processor.addParameter(parameter.release());
    return parameterReference;
}
 namespace  {
     juce::AudioParameterFloat& createModulationRateParameter(juce::AudioProcessor& processor) {
         const auto versionHint = 1;

         auto parameter = std::make_unique<juce::AudioParameterFloat>(
             juce::ParameterID{"modulation.rate", versionHint},
             "Modulation rate",
             juce::NormalisableRange<float>{0.1f,
                 20.f, 0.01f, 0.4f, },
             5.f,
             juce::AudioParameterFloatAttributes{}.withLabel("Hz")
                 );
        return  addParameterToProcessor(processor, std::move(parameter));

     }

     juce::AudioParameterFloat& createGainParameter(juce::AudioProcessor& processor) {
         auto attribute = juce::AudioParameterFloatAttributes().withLabel("Gain")
         .withStringFromValueFunction([] (float value, int)  {
             return juce::String{value,1};
         });

         auto parameter = std::make_unique<juce::AudioParameterFloat>(
             juce::ParameterID{"gain", 1},
             "Gain",
             juce::NormalisableRange<float>{-12.f, 12.f, 0.1f},
             0.0f,
             attribute
             );
         return addParameterToProcessor(processor, std::move(parameter));

     }

     juce::AudioParameterBool& createBypassParameter(juce::AudioProcessor& processor) {
         const auto versionHint = 1;
         auto parameter = std::make_unique<juce::AudioParameterBool>(
             juce::ParameterID{"bypassed", versionHint},
             "Bypass",
             false);
         return addParameterToProcessor(processor, std::move(parameter));
     }

    juce::AudioParameterChoice& createWaveformParameter(juce::AudioProcessor& processor) {
         const auto versionHint = 1;
         auto parameter = std::make_unique<juce::AudioParameterChoice>(
             juce::ParameterID{"waveform", versionHint},
             "Modulation Waveform",
             juce::StringArray{"Sine", "Triangle"},
             0
             );
         return addParameterToProcessor(processor, std::move(parameter));
     }
 }

Parameters::Parameters(juce::AudioProcessor& processor)

: rate{createModulationRateParameter(processor)},
  gain{createGainParameter(processor)},
    bypassed{createBypassParameter(processor)},
    waveform{createWaveformParameter(processor)}
{
 
}
}  // namespace tremolo
