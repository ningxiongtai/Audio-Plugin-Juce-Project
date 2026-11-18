namespace tremolo {
PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p) ,
    sliderAttachment{p.getParameterRefs().rate,  rateSlider}{
    background.setImage(juce::ImageCache::getFromMemory(
      assets::Background_png, assets::Background_pngSize));

  logo.setImage(
      juce::ImageCache::getFromMemory(assets::Logo_png, assets::Logo_pngSize));

  addAndMakeVisible(background);
  addAndMakeVisible(logo);
  addAndMakeVisible(lfoVisiualizer);
  rateSlider.setSliderStyle(juce::Slider::Rotary);
  rateSlider.setTextBoxStyle(juce::Slider::NoTextBox,false, 0, 0);
  rateSlider.setPopupDisplayEnabled(true, true, this);

  rateSlider.setTextValueSuffix(" Hz");

  addAndMakeVisible(rateSlider);
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(540, 270);
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

  lfoVisiualizer.setBounds(18, 149, 504, 92);
}
}  // namespace tremolo
