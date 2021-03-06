# CUE/BIN Splitter

This is a tiny tool I wrote to take a slightly processed CUE file, a raw PCM
file, and split it up into a collection of raw PCM files (one for each track).

The code style is mostly in the styles of "hacked together" and "let's put
everything in main and sort it out later once I get it working". Since it's not
an absolute showstopper, I'm working on changing this when I get the free time
here and there.

This tool takes a list of times (mm:ss:ff) from stdin and (blindly) outputs
files named according to the track number.
**It will overwrite any existing file with the same name**


## Usage

	Options:
	  -r bitrate_Hz
	  -c channel_count
	  -i input_file
	  -s size of a single channel's sample (bytes)
	  -n output file name (prepended with track number)


## Sample Usage

Assuming you want to use the first indices of each track as a boundary and
were chopping up a 44100 Hz, two channel, 16 bit audio stream,

	grep "INDEX 01" audio.cue | \
	  sed -e 's/INDEX 01//g' | \
	  cue-bin-split -i audio.bin -c 2 -r 44100 -s 2 -f -track.raw

Would output each track named as `001-track.raw`, `002-track.raw` and so on.

You might then push them through ffmpeg, lame, and/or friends to get them to
another audio format such as flac or mp3.

Or if you're feeling high on disc space, just prepend a WAV header to the PCM
data.
