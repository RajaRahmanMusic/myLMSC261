# Journey through my final project: DummyV3rb


## The Presentation

[This](https://docs.google.com/presentation/d/1SWFwb4zoeA15udglICN3JFAyaPJK6grkDgq5TtX9qps/edit?usp=sharing) is the google slides presentation I gave to my Introduction to Computer Programming class! The information regarding why I chose to create a reverb plugin, pseudocode, and plans for future implementation.

---

## The Process

### Downloading and installing juce

This process was very simple at the surface level, I would then realize later that there was much more to this simple task than what meets the eye, I went to the website and used an edu email to get an educational license. Once I got everything installed I created my first project

### Build issue

I had no problems using JUCE until it came to save and export the project to an IDE. JUCE did not support Visual Studio, so I consulted the JUCE manual and downloaded Clion, as it was listed as a compatible IDE, I quickly learned it was not. I could export a JUCE project to Clion, but I was unable to build, so this wouldn’t do.

### System compatibility

Due to Clion not working, I went back to the JUCE manual to see if I could use another IDE. I found Xcode was compatible, but I was unable to download it as the App Store stated I must have OSX Big Sur, while my computer is on 10.14.15, which is Mojave. This then called into question if the version of JUCE I had was even compatible with my OS. Just to make sure, I deleted JUCE and downloaded the first major release after my OS to remove the unknown variable.

### Cmake fiasco

After being at a standstill for about a week, I browsed the documentation for JUCE and came across a .txt file that said you needed Cmake to build if you do not use Xcode on Mac. I then spent a week trying to understand how use it to build to no avail.

### The importance of paths

As I was completely stuck, I reached out to my professor for help. She took a look at my computer and helped me diagnose and remedy the problems that were plaguing me. Firstly, when I had redownloaded JUCE, I didn’t play attention to the file paths and as a result JUCE couldn’t operate properly regardless of the issues I was having with the IDE. I ended up deleting and redownloading JUCE again, but this time I gave special attention to where it was being downloaded. Secondly, using Clion was more trouble than it was worth so I would begin to look for a way to download an old version of Xcode.

### The hunt for Xcode

After hours of searching, Older versions of Xcode appeared to be locked behind a paywall in the form of Apple’s developer program. I reached out to my professor once again, and she helped me find a version of Xcode compatible with Mojave.
After downloading Xcode, I used a JUCE example project and it finally built! Now I was off to the races.

### Learning C++

Now that I finally got my system working it was time to start coding the plug-in. I’m order to accomplish this task I had to learn C++. I had only used python up to this point which uses an interpreter, so this would be my first time using a compiler language. This was also the reason I chose to use C++, it would reduce latency as there wouldn’t be a need for an interpreter, which would slow down the entire process of the audio data being reverberated. I used the tutorial on cplusplus.com to learn the basics, and would occasionally consult stack overflow if I was confused about something specifically. As I was very new to C++, it limited my ability to not only write my own code without a myriad of syntax errors, but also my ability to understand the code that JUCE had already supplied for me. Although, I thoroughly enjoyed getting to experiment and tinker with C++. I thought it was really cool that you could “include” h files in cpp files to help organize large amounts of code with different usages. Another useful feature of C++ is the ability to declare public and private.

### Researching juce

JUCE was a helpful tool as it already had much of the back end code such as classes and algorithms defined within its several modules. The JUCE reference manual was super useful when trying to figure out how to understand what tools were at my disposal to design the plug-in, no part of this process would have been possible without JUCE.

### Building the GUI

The GUI seemed to be the most manageable area to begin my work, I dug through the class references and plug in making tutorials and discovered how to make a working GUI for the reverb plugin Here is some of the code:

``` C++
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
```

### THE WALL

After hours of consultation and research I was brought to a screeching halt by 3 major errors. The first problem I encountered was how to properly perform the reverb effect on the audio. Every time I would try to include juce_Reverb.h, it would say it was defined twice, so I was unable to actually call it. I found out later that this was due to it's inclusion in the juceheader.h file, but even though I would call the class, it would not recognize the public members within it for 2 reasons, errors 2 and 3. The second error was my lack of knowledge on how to pull variables out of a structure, I looked around on stack overflow to see if anyone could shed some insight, but it was mostly people saying not to attempt it. The third error is as follows:
``` C++
void Reverb3AudioProcessorEditor::sliderValueChanged (juce::Slider  * slider)
{
    audioProcessor.roomSize = roomSize.getValue();
}
```
As there is no member in Reverb3AudioProcessor called roomSize due to both of the aforementioned errors, this kept the GUI from actually being able to change the parameters of the reverb.

---

## The Sources

### JUCE Resources

[Plugin coding guide](https://docs.juce.com/master/tutorial_code_basic_plugin.html)

[Reverb class reference](https://docs.juce.com/master/classReverb.html)

[Slider Class reference](https://docs.juce.com/master/classSlider.html#a59e3fd9bc86e488070c12889747e7bbe)

[JUCE Forum](https://forum.juce.com/)

[Setting up Projucer](https://docs.juce.com/master/tutorial_manage_projucer_project.html)

[Projucer manual](https://juce.com/discover/stories/projucer-manual)

### GitHubs

[Circular buffer](https://github.com/ffAudio/ffTapeDelay)

[JUCE plugin reflection](https://deepio.github.io/daAudioPlugins/about/)

[Reverb plugin reference](https://github.com/martineastwood/mverb)

[JUCE Framework](https://github.com/juce-framework/JUCE)

### Other

[C++ guide](https://www.cplusplus.com/doc/tutorial/variables/)

[Artificial reverb article](https://ccrma.stanford.edu/~jos/pasp/History_FDNs_Artificial_Reverberation.html)

[Reverb in Python](http://ajaxsoundstudio.com/pyodoc/examples/07-effects/02-schroeder-reverb.html)

[JUCE tutorials](https://www.youtube.com/channel/UCpKb02FsH4WH4X_2xhIoJ1A)
