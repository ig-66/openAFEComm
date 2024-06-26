#ifndef _OPENAFE_SHARED_
#define _OPENAFE_SHARED_

#include <stdint.h>

// *** WARNING! -> THE COMMAND ID OF 0 (ZERO) IS INVALID! ***
#define CMDID_CHK 1u // Check if the AFE IC is responding, AKA read the ADIID register.
#define CMDID_DIE 2u   // Kill any operation taking place in the MCU and reset it.
#define CMDID_RUN 3u   // Run the Voltammetry that is already loaded (for the sequencer ONLY).

#define CMDID_CVW 4u	// Feed CV parameters, check possibility of the wave and start the voltammetry.
#define CMDID_DPV 5u 	// Feed DPV parameters, check possibility of the wave and start the voltammetry.
#define CMDID_SWV 6u	// Feed SW parameters, check possibility of the wave and start the voltammetry.

#define CMDID_TIA 10u // Command to change the Transimpedance Amplifier gain resistor.
#define CMDID_CUR 11u // Command to change the TIA gain resistor using the current as the parameter.

#define CMDID_CV_PARAMS 155u  // Feed the CV params and the sequencer (for the sequencer ONLY).
#define CMDID_DPV_PARAMS 156u // Feed the DVP params and the sequencer (for the sequencer ONLY).
#define CMDID_SW_PARAMS 157u  // Feed the SW params and the sequencer (for the sequencer ONLY).

#define EXE_CVW_DONE 200u // Execution of Cyclic voltammetry finished.
#define EXE_DPV_DONE 201u // Execution of Differential Pulse voltammetry finished.
#define EXE_SWV_DONE 202u // Execution of Square wave voltammetry finished.

#define STATUS_VOLTAMMETRY_UNDERGOING 210u // The Voltammetry process is currently in progress.

// YOU MAY WANT TO TAKE A LOOK AT THIS:
// https://bitbucket.org/moduhub/pstat1fw-git/src/master/src/main.c
/**
 * @brief Command parameters type. Hold the information of a command.
 *
 */
struct command_t
{
	uint8_t id;				 // Command ID.
	uint16_t settlingTime;	 // Settling time, in milliseconds.
	float startingPotential; // Starting potential, in mV.
	float endingPotential;	 // Ending potential, in mV.
	float scanRate;			 // Scan rate, in mV.
	float stepSize;			 // Step size, in mV.
	uint8_t numCycles;		 // Number of cycles.
	uint16_t numPoints;		 // Number of points.
	float pulseAmplitude;	 // Pulse amplitude in mV.
	uint16_t gainTIA;		 // TIA gain.
	uint16_t currentRange;	 // AFE current range, in uA.	
	uint16_t pulseWidth; 	 // Pulse top width, in milliseconds.
	uint16_t baseWidth;		 // Base width, in milliseconds.
	uint16_t samplePeriodPulse; // Sample time before the pulse go down.
	uint16_t samplePeriodBase;	// Sample time before the pulse go up.
	float pulseFrequency;		// Pulse frequency, in Hertz.
};

#endif // _OPENAFE_SHARED_