# achilles--toe
A footswitch for controlling Reaper and NeuralDSP plugins made with Arduino UNO  
(Well, actually it's a MIDI-controller, not necessarily a footswitch).

Important note: this can't be used with Arduino NANO.  
This project can be implemented in a more easy and convenient way using Arduino Leonardo.

The code basically emulates keyboard presses. All you a user needs to do is to bind Reaper or any VST plugin to a key that is available in the code.  
You can easily configure the code to change some keys or to add additional buttons.

# The functionality in the default configuration:  
A1: Play/Stop  
A2: Record  
A3: Go to the start of  the Reaper project  
A4: Switch to the previous NeuralDSP preset (must be binded in the plugin)  
A5: Switch to the next NeuralDSP preset (must be binded in the plugin)  

# How to make this work  
Just uploading the code onto UNO won't work as the controller must be recognized by the PC as a keyboard.  
To achieve this, you'll need to use free software called FLIP.  
First, upload the sketch from this repository to UNO.  
Then flash UNO with the "keyboard.hex" file, included in the repository. This'll be enough.  
To revert UNO to it's default state, use the other .hex file.  
