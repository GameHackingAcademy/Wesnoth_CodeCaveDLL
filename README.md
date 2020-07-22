# CodeCaveDLL

A DLL that redirects the "Terrain Description" function in Wesnoth 1.14.9 to a custom function that sets the player's gold to 888. This custom function then recreates the "Terrain Description" function and returns execution to the program.
	
This is done through the use of a codecave. When injected, the DLL modifies the function that displays the terrain description and changes the code to jump to the codecave function defined in the DLL. The codecave function then saves the registers, sets the gold to 888, and then restores the original modified instructions before returning to the original calling code.
	
This must be injected into the Wesnoth process to work. One way to do this is to use a DLL injector. Another way is to enable AppInit_DLLs in the registry.
	
The offsets and explanation of the codecave are covered in https://gamehacking.academy/lesson/11 and https://gamehacking.academy/lesson/16
