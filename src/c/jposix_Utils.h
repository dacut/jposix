/** @file   jposix_Utils.h
 *  @brief  
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

#ifndef JPOSIX_UTILS_H
#define JPOSIX_UTILS_H

#include <jni.h>
#include <sys/stat.h>
#include <sys/types.h>

#define CHAR_TO_BYTEARRAY(result, buffer, bufferSize)                   \
    do {                                                                \
        int __tmpbufsize = (int) (bufferSize);                          \
                                                                        \
        if ((result = (*env)->NewByteArray(                             \
                 env, __tmpbufsize)) == NULL) {                         \
            goto finally;                                               \
        }                                                               \
                                                                        \
        (*env)->SetByteArrayRegion(env, result, 0, __tmpbufsize,        \
                                   (jbyte *) (buffer));                 \
    } while (0)

#define BYTEARRAY_TO_CHAR(buffer, bufferSize, ba)                       \
    do {                                                                \
        if (ba == NULL) {                                               \
            throwNullPointerException(env, #ba " cannot be null");      \
            goto finally;                                               \
        }                                                               \
                                                                        \
        XBYTEARRAY_TO_CHAR(buffer, bufferSize, ba);                     \
    } while (0)

#define XBYTEARRAY_TO_CHAR(buffer, bufferSize, ba)                      \
    do {                                                                \
        bufferSize = (*env)->GetArrayLength(env, ba);                   \
        XMALLOC(buffer, bufferSize + 1);                                \
        (*env)->GetByteArrayRegion(env, ba, 0, bufferSize,              \
                                   (jbyte *) buffer);                   \
        buffer[bufferSize] = '\0';                                      \
    } while (0)


#define XMALLOC(var, size)                                              \
    do {                                                                \
        if ((var = malloc(size)) == NULL) {                             \
            throwOutOfMemoryError(env);                                 \
            goto finally;                                               \
        }                                                               \
    } while (0)

#define XFREE(var)                              \
    if (var == NULL) ;                          \
    else free(var)

JNIEXPORT extern jclass java_lang_IllegalArgumentException_class;
JNIEXPORT extern jclass java_lang_NullPointerException_class;
JNIEXPORT extern jclass java_lang_OutOfMemoryError_class;
JNIEXPORT extern jclass java_lang_UnsupportedOperationException_class;
JNIEXPORT extern jclass byte_array_class;

JNIEXPORT extern jclass jposix_OSException_class;
JNIEXPORT extern jmethodID jposix_OSException_init;

JNIEXPORT extern jclass jposix_Posix_class;

JNIEXPORT extern jclass jposix_struct_Stat_class;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_dev;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_ino;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_mode;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_nlink;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_uid;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_gid;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_rdev;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_size;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_blksize;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_blocks;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_atime;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_mtime;
JNIEXPORT extern jfieldID jposix_struct_Stat_st_ctime;
JNIEXPORT jobject JNICALL stat2java(JNIEnv *env, struct stat const *sbuf);

JNIEXPORT void JNICALL throwOutOfMemoryError(JNIEnv *env);
JNIEXPORT void JNICALL throwIllegalArgumentException(
    JNIEnv *env,
    char const *reason);
JNIEXPORT void JNICALL throwNullPointerException(
    JNIEnv *env,
    char const *reason);
JNIEXPORT void JNICALL throwOSException(JNIEnv *env, int errorcode);
JNIEXPORT void JNICALL throwUnsupportedOperationException(
    JNIEnv *env,
    char const *reason);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved);

#endif /* JPOSIX_UTILS_H */

/* Local variables: */
/* mode: C */
/* indent-tabs-mode: nil */
/* tab-width: 8 */
/* End: */
/* vi: set expandtab tabstop=8 */
