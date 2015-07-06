/*
 * Part of cue-bin-split - Splits raw PCM files on time boundaries
 * Copyright (c) 2015 David Phillips <dbphillipsnz@gmail.com>
 * All rights reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "misc.h"

/* Grabs a 'mm:ss:ff' stamp from stdin */
int get_stamp(int *m, int *s, int *f)
{
	return fscanf(stdin, "%d:%d:%d\n", m, s, f);
}

/* Constructs an output filename in the specified buffer based on the given format and track number
 * Main purpose is to catch buffer overflow with snprintf
 */
void construct_out_name(char *buffer, size_t buffer_size, char* format, unsigned int track)
{
	if (snprintf(buffer, buffer_size, format, track) == buffer_size)
	{
		fprintf(stderr, "Filename too large for buffer (max %zd)\n", buffer_size);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/* Displays the help/syntax message and dies
 * Does what it says on the tin
 */
void die_help()
{
	fprintf(stderr,
		"\n"
		"Options: \n"
		"  -r bitrate_Hz\n"
		"  -c channel_count\n"
		"  -i input_file\n"
		"  -s size of a single channel's sample (bytes)\n"
		"  -f name_format (%%d and co are replaced with track number)\n"
	);
	exit(EXIT_FAILURE);
}
