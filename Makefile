# Makefile

arduino := arduino:avr:uno
# arduino := arduino:renesas_uno:minima 

all:
	echo "Motor programmer Makefile"

list:
	@arduino-cli board list

compile:
	@arduino-cli compile --fqbn $(arduino) arduino-eyes.ino

upload:
	@arduino-cli upload --fqbn $(arduino) --verbose

run: compile upload
