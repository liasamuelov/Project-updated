/* ********************************************************************
 * FILE: preprocessor.h
 * OWNER / מי מממשת: ליה
 * STATUS: TODO - לממש
 * מה עושים כאן: הממשק של הקדם-אסמבלר.
 * ******************************************************************** */

/*
 * preprocessor.h - the pre-assembler stage (macro expansion).
 * OWNER: Lia.
 */
#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include "globals.h"

/* Reads the .as source file, expands all macros, and writes the expanded
   source into the .am file. Returns TRUE on success, FALSE if the input
   could not be processed (in that case no further stages should run and
   the assembler should move on to the next input file). */
boolean preprocess_file(const char *as_filename, const char *am_filename);

#endif /* PREPROCESSOR_H */
