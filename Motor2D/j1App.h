#ifndef __j1APP_H__
#define __j1APP_H__

#include "p2List.h"
#include "j1Module.h"
#include "PugiXml\src\pugixml.hpp"

// Modules
class j1Window;
class j1Input;
class j1Render;
class j1Textures;
class j1Audio;
class j1Scene;

class j1App
{
public:

	// Constructor
	j1App(int argc, char* args[]);

	// Destructor
	virtual ~j1App();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool Update();

	// Called before quitting
	bool CleanUp();

	// Add a new module to handle
	void AddModule(j1Module* module);

	// Exposing some properties for reading
	int GetArgc() const;
	const char* GetArgv(int index) const;
	const char* GetTitle() const;
	const char* GetOrganization() const;

	//Load and Save confirmations
	void Save();
	void Load();
	// TODO 1: Create methods to save and load
	// that can be called anytime, even if they 
	// will one execute by the very end of the frame
	// Load / Save

private:

	// Load config file
	bool LoadConfig();

	//Load Save/Load file
	bool LoadSaveFile();

	// Call modules before each loop iteration
	void PrepareUpdate();

	// Call modules before each loop iteration
	void FinishUpdate();

	// Call modules before each loop iteration
	bool PreUpdate();

	// Call modules on each loop iteration
	bool DoUpdate();

	// Call modules after each loop iteration
	bool PostUpdate();

	// Saving method
	const bool RealSave();

	// Loading method
	bool RealLoad();

public:

	// Modules
	j1Window*			win;
	j1Input*			input;
	j1Render*			render;
	j1Textures*			tex;
	j1Audio*			audio;
	j1Scene*			scene;

private:

	p2List<j1Module*>	modules;
	uint				frames;
	float				dt;
	pugi::xml_document	config_file;
	pugi::xml_document	save_file;
	pugi::xml_node		save_node;
	pugi::xml_node		config;
	pugi::xml_node		app_config;
	int					argc;
	char**				args;
	mutable bool		want_to_save;
	mutable bool		want_to_load;

	p2SString			title;
	p2SString			organization;

};

extern j1App* App;

#endif