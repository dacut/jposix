import re, sys

fd = open("src/java/jposix/Posix.java", "r")
bodylines = fd.readlines()
fd.close()

fd = open("src/c/jposix_Posix_constants.c", "w")

print >> fd, """/** @file   jposix_Posix_constants.c
 *  @brief  Constant setters for Posix.java.
 */

/*  Copyright (c) 2008 Kanga International Group.  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *  
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 *  PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER(S), AUTHOR(S), OR CONTRIBUTOR(S) BE LIABLE FOR ANY DIRECT,
 *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 *  GOVERNMENT USE: If you are acquiring this software on behalf of the
 *  U.S. government, the Government shall have only "Restricted Rights" in
 *  the software and related documentation as defined in the Federal
 *  Acquisition Regulations (FARs) in Clause 52.227.19 (c) (2). If you are
 *  acquiring the software on behalf of the Department of Defense, the
 *  software shall be classified as "Commercial Computer Software" and the
 *  Government shall have only "Restricted Rights" as defined in Clause
 *  252.227-7013 (c) (1) of DFARs.  Notwithstanding the foregoing, the
 *  authors grant the U.S. Government and others acting in its behalf
 *  permission to use and distribute the software in accordance with the
 *  terms specified in this license.
 *
 *  $Id$
 */

#include <jni.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
"""

constreg = re.compile(r"^ *public static final int ([A-Z0-9_]+); *$")
names = []
 
for line in bodylines:
    line = line.rstrip()

    match = constreg.match(line)
    if match is None:
        continue

    name = match.group(1)
    mangled = name.replace("_", "_1")
    names.append(name)
    
    print >> fd, """
JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1%(mangled)s(JNIEnv *env, jclass clazz)
{
#if defined(%(name)s)
    return %(name)s;
#else
    return 0;
#endif
}
""" % { 'name': name, 'mangled': mangled }
# end for

fd.close()

# Replace the generated section
found = False
for start in xrange(len(bodylines)):
    if "// !! start generated" in bodylines[start]:
        found = True
        break

if not found:
    print >> sys.stderr, "Did not find start of generated section."
    sys.exit(1)

found = False
for end in xrange(start + 1, len(bodylines)):
    if "// !! end generated" in bodylines[end]:
        found = True
        break

if not found:
    print >> sys.stderr, "Did not find start of generated section."
    sys.exit(1)

fd = open("src/java/jposix/Posix.java", "w")
fd.write("".join(bodylines[:start+1]))

for name in names:
    fd.write("    private static native int _get_%s();\n" % name)

fd.write("\n    static {\n        loadLibrary(\"jposix-0.1\");\n")
for name in names:
    fd.write("        %s = _get_%s();\n" % (name, name))
fd.write("    }\n")

fd.write("".join(bodylines[end:]))
fd.close()
