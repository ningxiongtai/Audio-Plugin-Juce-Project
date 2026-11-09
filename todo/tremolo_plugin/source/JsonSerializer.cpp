namespace tremolo {
struct SerializableParameter {
    float rate;
    bool bypassed;
    juce::String waveform;

    static constexpr auto marshallingVersion = 1;
    template <typename Archive, typename T>
    static void serialise(Archive& archive, T& t)
    {
        if (archive.getVersion() != 1)
            return;

        // 写入插件名称进行自校验
        std::string pluginName = TREMOLO_PLUGIN_NAME;

        archive(juce::named("pluginName", pluginName));
        if (pluginName != TREMOLO_PLUGIN_NAME) {
            return;
        }
        // 统一双向读写各个字段

        archive(juce::named("modulationRateHz", t.rate), juce::named("bypassed", t.bypassed),
                juce::named("modulationWaveform", t.waveform));
    }
};

SerializableParameter from(const tremolo::Parameters& parameter) {
    return {
        .rate = parameter.rate,
        .bypassed = parameter.bypassed,
        .waveform = parameter.waveform,
    };
}



void JsonSerializer::serialize(const Parameters& parameters,
                               juce::OutputStream& output) {
  juce::ignoreUnused(parameters, output);
    const auto parametersToSerialize = from(parameters);
    const auto json = juce::ToVar::convert(parametersToSerialize);
    if (!json.has_value()) {
        return;
    }
    juce::JSON::writeToStream(output, *json, juce::JSON::FormatOptions{}
        .withSpacing(juce::JSON::Spacing::multiLine)
        .withMaxDecimalPlaces(2));
}

juce::Result JsonSerializer::deserialize(juce::InputStream& input,
                                         Parameters& parameters) {
    juce::var parsedResult;
    const auto result = juce::JSON::parse(input.readEntireStreamAsString(), parsedResult);
    if (!result) {
        return result;
    }
    const auto parsedParameters = juce::FromVar::convert<SerializableParameter>(parsedResult);
    if (!parsedParameters.has_value()) {
        return juce::Result::fail("failed to parse parameters");
    }
    const auto modulationWaveformIndex =
    parameters.waveform.choices.indexOf(parsedParameters->waveform);
    if (modulationWaveformIndex < 0) {
        // don't update parameters if modulation waveform name is invalid
        return juce::Result::fail(
            "invalid modulation waveform name; supported values are: " +
            parameters.waveform.choices.joinIntoString(", "));
    }

    parameters.waveform = modulationWaveformIndex;
    parameters.rate = parsedParameters->rate;
    parameters.bypassed = parsedParameters->bypassed;

    return juce::Result::ok();
}
}  // namespace tremolo
