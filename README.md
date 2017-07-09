# Voltage Monitor Example

## Description:

	This code uses a voltage divider to measure the battery voltage using the 
	analog input pin on the Arducam ESP8266 Uno board.

## Wiring Diagram:
	
			         R1               R2
		-----------VVVVVV-----------VVVVVV-----------
		|                     |                     |
		|                     |                     |
		|                     |                     |
		|                     |                     |
	  VBATT                 SENSE                  GND

			    SENSE = (VBAT*R2) / (R1+R2)
				  VBATT = (R1+R2) * SENSE / R2
				  MAX(SENSE) = VREF = 3.3V
				  MAX(VBATT) = 4.2V
			
## Notes:

	1) Larger resistors will draw less current

	2) The Arducam ESP8266 Uno board uses a 3.3V reference voltage

	3) SENSE must be less than 3.3V so it may be read by the ADC

		MAX(SENSE) > (MAX(VBATT)*R2) / (R1+R2)
		MAX(SENSE)*R1 + MAX(SENSE)*R2 > MAX(VBATT)*R2
		R1 > ( MAX(VBATT) - MAX(SENSE) ) / ( MAX(SENSE) * R2 )
	
	4) The ADC is 8-bit 
	
		ADC = 1024 * SENSE / VREF
		SENSE = ADC * VREF / 1024

	5) VBATT is connected directly to the positive battery terminal

	6) SENSE is connected to the A0 pin on the board

	7) GND is connected to one of the GND pins on the board
