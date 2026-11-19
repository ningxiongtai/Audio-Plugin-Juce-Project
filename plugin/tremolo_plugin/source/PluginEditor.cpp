namespace tremolo {
PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p) ,
  sliderAttachment{p.getParameterRefs().rate,  rateSlider},
  bypassButtonAttachment {p.getParameterRefs().bypassed,  bypassButton},
  waveformAttachment {p.getParameterRefs().waveform,  waveformComboBox}
{

  background.setImage(juce::ImageCache::getFromMemory(
      assets::Background_png, assets::Background_pngSize));

  logo.setImage(
      juce::ImageCache::getFromMemory(assets::Logo_png, assets::Logo_pngSize));

  addAndMakeVisible(background);
  addAndMakeVisible(logo);
  addAndMakeVisible(lfoVisiualizer);
  addAndMakeVisible(bypassButton);
  addAndMakeVisible(waveformComboBox);

  waveformComboBox.addItemList(p.getParameterRefs().waveform.choices, 1);
  waveformAttachment.sendInitialUpdate();
  rateSlider.setSliderStyle(juce::Slider::Rotary);
  rateSlider.setTextBoxStyle(juce::Slider::NoTextBox,false, 0, 0);
  rateSlider.setPopupDisplayEnabled(true, true, this);

  rateSlider.setTextValueSuffix(" Hz");

  bypassButton.onClick = [this] () {
    bypassButton.setButtonText( bypassButton.getToggleState() ? "Bypassed" : "Off");
  };
  bypassButton.onClick();
  addAndMakeVisible(rateSlider);
  setLookAndFeel(&customLookAndFeel);
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(540, 270);
}

PluginEditor::~PluginEditor() {
    setLookAndFeel(nullptr);
}

void PluginEditor::resized() {
  const auto bounds = getLocalBounds();

  background.setBounds(bounds);

  logo.setBounds({16, 16, 105, 24});

  auto rateSliderBounds = bounds;
  rateSliderBounds.removeFromLeft(230);
  rateSliderBounds.removeFromRight(230);
  rateSliderBounds.removeFromTop(40);
  rateSliderBounds.removeFromBottom(150);
  rateSlider.setBounds(rateSliderBounds);

  auto buttonBounds = bounds;
  buttonBounds.removeFromTop(66);
  buttonBounds.removeFromRight(16);
  buttonBounds.removeFromBottom(176);

  buttonBounds.removeFromLeft(392);
  bypassButton.setBounds(buttonBounds);

  auto waveformComboBoxBounds = bounds;
  waveformComboBoxBounds.removeFromTop(66);
  waveformComboBoxBounds.removeFromRight(392);
  waveformComboBoxBounds.removeFromBottom(176);
  waveformComboBoxBounds.removeFromLeft(16);
  waveformComboBox.setBounds(waveformComboBoxBounds);

  lfoVisiualizer.setBounds(18, 149, 504, 92);
}
}  // namespace tremolo
