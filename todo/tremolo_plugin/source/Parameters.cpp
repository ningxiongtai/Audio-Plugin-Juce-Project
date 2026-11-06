
namespace tremolo {

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

         auto& parameterReference = *parameter;
         processor.addParameter(parameter.release());
         return parameterReference;
     }

     juce::AudioParameterFloat& createGainParameter(juce::AudioProcessor& processor) {
         auto attribute = juce::AudioParameterFloatAttributes().withLabel("Gain")
         .withStringFromValueFunction([] (float value, int)  {
             return juce::String{value,1};
         });

         auto parameterGain = std::make_unique<juce::AudioParameterFloat>(
             juce::ParameterID{"gain", 1},
             "Gain",
             juce::NormalisableRange<float>{-12.f, 12.f, 0.1f},
             0.0f,
             attribute
             );
         auto& parameterReferenceGain = *parameterGain;
         processor.addParameter(parameterGain.release());
         return parameterReferenceGain;

     }
 }

Parameters::Parameters(juce::AudioProcessor& processor)
// TODO: create parameters
// TODO: retrieve references to parameters
// TODO: add parameters to the processor
: rate{createModulationRateParameter(processor)}
 , gain{createGainParameter(processor)}
{
 
}
}  // namespace tremolo
