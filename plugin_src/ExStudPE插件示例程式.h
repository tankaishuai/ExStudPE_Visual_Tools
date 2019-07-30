
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the EXSTUDPE_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// EXSTUDPE_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef EXSTUDPE_EXPORTS
#define EXSTUDPE_API __declspec(dllexport)
#else
#define EXSTUDPE_API __declspec(dllimport)
#endif

// This class is exported from the ExStudPE插件示例程式.dll

