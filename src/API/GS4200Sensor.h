#pragma once
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the GS4200SENSOR_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// GS4200SENSOR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef GS4200SENSOR_EXPORTS
#define GS4200SENSOR_API __declspec(dllexport)
#else
#define GS4200SENSOR_API __declspec(dllimport)
#endif

#define OK 0
#define FAIL -1
#define INVALID_INDEX -2
#define INVALID_PARAMETER -3
#define INVALID_STATE -4

//Enumeration of the available pressure units
enum PressureUnits
{
   bar,
   mbar,
   psi,
   MPa,
   Pa,
   mmH2O,
   mmHg,
   atm,
   kgcm2
};

//Enumeration of the available temperature units
enum TemperatureUnits
{
   C,
   K,
   F
};



extern "C"
{
   //SETUP AND INITIALISATION
   //Searches all serial ports to find pressure sensors.  The number of sensors that were found is returned in the SensorCount parameter.
   GS4200SENSOR_API int FindSensors(int* SensorCount);

   //Retrieves information for a particular sensor
   GS4200SENSOR_API int GetSensorInfo(int SensorIndex, int* PortNumber, char* SerialNumber, int SerialNumberLength);

   //Opens communications with a sensor and sets it ready for use
   GS4200SENSOR_API int UseSensor(int SensorIndex);

   //Closes communications with a sensor and releases it
   GS4200SENSOR_API int ReleaseSensor(int SensorIndex);

   // Retrieves the manufacture date for the given sensor
   GS4200SENSOR_API int GetManufactureDate(int sensorIndex, long long* date);

   // Retrieves the calibration date for the given sensor
   GS4200SENSOR_API int GetCalibrationDate(int sensorIndex, long long* date);

   //INFORMATION
   //Retrieves the pressure range for a given sensor.
   GS4200SENSOR_API int GetPressureRange(int SensorIndex, float* Range);

   //This function is given a pressure units code and a string containing the units in text form is returned in the UnitString parameter.
   GS4200SENSOR_API int GetPressureUnits(int Units, char* UnitString, int UnitStringLength);

   //This function is given a temperature units code and a string containing the units in text form is returned in the UnitString parameter.
   GS4200SENSOR_API int GetTemperatureUnits(int Units, char* UnitString, int UnitStringLength);

   //OPERATION
   //This function reads the pressure in the selected engineering units.
   GS4200SENSOR_API int Read(int SensorIndex, int Units, int Absolute, float Temperature, float* Pressure);

   //This function reads the temperature in the selected engineering units.
   GS4200SENSOR_API int ReadTemperature(int SensorIndex, int Units, float* Temperature);

   //This sets the difference between absolute and gauge pressures in bar.  The value is used in the Read function when giving absolute values.
   GS4200SENSOR_API int SetGaugeDifferential(int SensorIndex, float Differential);

   //CLEAN-UP
   //This function must be called when the application code has finished using the library.  This closes communications and cleans up all system resources.
   GS4200SENSOR_API int CleanUp();
}

