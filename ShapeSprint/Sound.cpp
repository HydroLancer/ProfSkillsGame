#include "Sound.h"
////////////////////////////////////////
////								////
////			BUFFERS				////
////								////
////////////////////////////////////////
// Buffers store the sound file, but do not play them directly
// Supported file formats: .WAV, .OGG
sf::SoundBuffer jumpBuffer;
sf::SoundBuffer coinPickupBuffer;

////////////////////////////////////////
////								////
////		     MUSIC				////
////								////
////////////////////////////////////////
// Like a sound but requires no buffer
// The files are loaded in and streamed
sf::Music menuMusic;
sf::Music level1Music;

////////////////////////////////////////
////								////
////		SOUND INSTANCES			////
////								////
////////////////////////////////////////
sf::Sound jumpSound;
sf::Sound coinPickupSound;

// Position and velocity of sounds
sf::Vector3f soundPos(0.0f, 0.0f, 0.0f);
sf::Vector3f soundVelocity(0.0, 0.0, 0.0);

// 'Listeners' position
sf::Vector3f listenerPos(0.0, 0.0, -1.0);

// 'Listener' orientation
sf::Vector3f listenerForward(0.0, 0.0, -1.0);
sf::Vector3f listenerUp(0.0, 1.0, -1.0);

float updateTime = Timer();

////////////////////////////////////////
////								////
////			STREAMS				////
////								////
////////////////////////////////////////
//// MUSIC STREAMS ////
void PlayMenuMusic()
{
	if (!menuMusic.openFromFile("Menu.wav")) //tada
	{
		cout << "Error loading sound file" << endl;
		while (!_kbhit());
		return;
	}
	// Set the properties of the source. Details of all available properties are in the SFML documentation of the Sound class
	menuMusic.setVolume(15.0f); // 0 to 100
	menuMusic.setPitch(1.0f);
	menuMusic.setLoop(true);
	menuMusic.setPosition(soundPos);

	menuMusic.play();
}

void PlayLevel1Music()
{
	menuMusic.stop();

	if (!level1Music.openFromFile("Level 1.wav")) //tada
	{
		cout << "Error loading sound file" << endl;
		while (!_kbhit());
		return;
	}

	// Set the properties of the source. Details of all available properties are in the SFML documentation of the Sound class
	level1Music.setVolume(15.0f);
	level1Music.setPitch(1.0f);
	level1Music.setLoop(true);
	level1Music.setPosition(soundPos);
	level1Music.play();
}

////////////////////////////////////////
////								////
////			SOUNDS				////
////								////
////////////////////////////////////////
void LoadAllSounds()
{
	sf::Listener::setGlobalVolume(100.0f);			// Overall volume for ALL sounds and music
	sf::Listener::setPosition(listenerPos);			// Sets the position of where the sound is played in world space
	sf::Listener::setDirection(listenerForward);	// ???
	sf::Listener::setUpVector(listenerUp);			// ???

	if (!jumpBuffer.loadFromFile("jump.wav")) //tada
	{
		cout << "Error loading sound file \"jump.wav\"" << endl;
		while (!_kbhit());
		return;
	}

	if (!coinPickupBuffer.loadFromFile("coin_pickup.wav")) //tada
	{
		cout << "Error loading sound file \"coin_pickup.wav\"" << endl;
		while (!_kbhit());
		return;
	}
}

void PlayJumpSound()
{
	// Indicate that our sound source will use the buffer we just loaded
	jumpSound.setBuffer(jumpBuffer);
	// Set the properties of the source. Details of all available properties are in the SFML documentation of the Sound class
	jumpSound.setVolume(800.0f); // 0 to 100
	jumpSound.setPitch(0.5f);
	jumpSound.setLoop(false);
	jumpSound.setPosition(soundPos);
	jumpSound.play();
}

void PlayCoinPickupSound()
{
	// Indicate that our sound source will use the buffer we just loaded
	coinPickupSound.setBuffer(coinPickupBuffer);
	// Set the properties of the source. Details of all available properties are in the SFML documentation of the Sound class
	coinPickupSound.setVolume(8.0f); // 0 to 100
	coinPickupSound.setPitch(1.0f);
	coinPickupSound.setLoop(false);
	coinPickupSound.setPosition(soundPos);

	coinPickupSound.play();
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