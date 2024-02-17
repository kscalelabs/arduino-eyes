# Makefile

all:
	echo "Motor programmer Makefile"

list:
	@arduino-cli board list

compile:
	@arduino-cli compile --fqbn arduino:renesas_uno:minima arduino-eyes.ino

upload:
	@arduino-cli upload --fqbn arduino:renesas_uno:minima --verbose

run: compile upload
