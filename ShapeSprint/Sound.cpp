#include "Sound.h"
	// Buffers
	// Load a sound file into a sound buffer
  // Supports WAV, OGG/Vorbis, FLAC only. Download Audacity (free) to convert other formats for use (use WAV or OGG)
//****************
// Globals
// A "buffer" holds sound data, but the creation of a buffer on its own doesn't play a sound. It is the
// equivalent of a mesh in the TL-Engine
sf::SoundBuffer buffer;
//A "sound" is an actual sound in the world. A sound must be associated with a buffer to indicate
//which sound data to play. Sources are equivalent to models in the TL-Engine
sf::Sound sound;
//Each sound source has several properties, see the code for examples. Here we store position and 
//velocity of the sound source above, using a SFML class Vector3f to hold the xyz values
//The velocity is to move the sound around and also for the Doppler effect. In fact SFML does not
//support Doppler, so the velocity is just for our own purposes. Look at the "OpenAL Soft" library
//if you want to do Doppler in your own projects
sf::Vector3f soundPos(20.0, 0.0, -1.0);
sf::Vector3f soundVelocity(-5.0, 0.0, 0.0);
//There is always assumed to be a listener in the wold although we don't need a specific listener variable.
//Listeners also have properties (examples in code). Here we store the listener's position
sf::Vector3f listenerPos(0.0, 0.0, -1.0);

//The listener may be at an angle (which may affect the perception of sound). Here we store the 
//orientation of the listener by specifying their facing direction and upward direction.
//These xyz vectors can be extracted from a world or view matrix
//NOTE: SFML uses a right-handed system for 3D coordinates. To convert from the left-handed system
//we normally use, we must negate all Z values (facing direction has -ve Z below). Without this
//change the sounds from the left and right speakers will be the wrong way round
sf::Vector3f listenerForward(0.0, 0.0, -1.0);
sf::Vector3f listenerUp(0.0, 1.0, -1.0);
float updateTime = Timer();
void playJumpSound()
{
	if (!buffer.loadFromFile("1.wav")) //tada
	{
		cout << "Error loading sound file" << endl;
		while (!_kbhit());
		return;
	}
	// Indicate that our sound source will use the buffer we just loaded
	sound.setBuffer(buffer);
	// Set the properties of the source. Details of all available properties are in the SFML documentation of the Sound class
	sound.setVolume(100.0f); // 0 to 100
	sound.setPitch(0.5f);
	sound.setLoop(false);
	sound.setPosition(soundPos);
	sf::Listener::setGlobalVolume(100.0f); // 0 to 100
	sf::Listener::setPosition(listenerPos);
	sf::Listener::setDirection(listenerForward);
	sf::Listener::setUpVector(listenerUp);
	sound.play();
}
void playMenuSound()
{
	if (!buffer.loadFromFile("Menu.wav")) //tada
	{
		cout << "Error loading sound file" << endl;
		while (!_kbhit());
		return;
	}
	// Indicate that our sound source will use the buffer we just loaded
	sound.setBuffer(buffer);
	// Set the properties of the source. Details of all available properties are in the SFML documentation of the Sound class
	sound.setVolume(100.0f); // 0 to 100
	sound.setPitch(1.0f);
	sound.setLoop(true);
	sound.setPosition(soundPos);
	sf::Listener::setGlobalVolume(100.0f); // 0 to 100
	sf::Listener::setPosition(listenerPos);
	sf::Listener::setDirection(listenerForward);
	sf::Listener::setUpVector(listenerUp);
	sound.play();
}
// Simple timer function, similar to that in TL-Engine. Used for later exercises
// Returns time in seconds since it was last called
float Timer()
{
	static clock_t currTime = clock();
	clock_t prevTime = currTime;
	currTime = clock();
	return float(currTime - prevTime) / CLOCKS_PER_SEC;
}