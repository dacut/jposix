/** @file   jposix_Utils.c
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

#include "jposix_Utils.h"

JNIEXPORT jclass java_lang_IllegalArgumentException_class;
JNIEXPORT jclass java_lang_NullPointerException_class;
JNIEXPORT jclass java_lang_OutOfMemoryError_class;
JNIEXPORT jclass java_lang_UnsupportedOperationException_class;
JNIEXPORT jclass byte_array_class;

JNIEXPORT jclass jposix_OSException_class;
JNIEXPORT jmethodID jposix_OSException_init;

JNIEXPORT jclass jposix_Posix_class;

JNIEXPORT jclass jposix_struct_Stat_class;
JNIEXPORT jfieldID jposix_struct_Stat_st_dev;
JNIEXPORT jfieldID jposix_struct_Stat_st_ino;
JNIEXPORT jfieldID jposix_struct_Stat_st_mode;
JNIEXPORT jfieldID jposix_struct_Stat_st_nlink;
JNIEXPORT jfieldID jposix_struct_Stat_st_uid;
JNIEXPORT jfieldID jposix_struct_Stat_st_gid;
JNIEXPORT jfieldID jposix_struct_Stat_st_rdev;
JNIEXPORT jfieldID jposix_struct_Stat_st_size;
JNIEXPORT jfieldID jposix_struct_Stat_st_blksize;
JNIEXPORT jfieldID jposix_struct_Stat_st_blocks;
JNIEXPORT jfieldID jposix_struct_Stat_st_atime;
JNIEXPORT jfieldID jposix_struct_Stat_st_mtime;
JNIEXPORT jfieldID jposix_struct_Stat_st_ctime;

JNIEXPORT void throwOutOfMemoryError(JNIEnv *env)
{
    (*env)->ThrowNew(env, java_lang_OutOfMemoryError_class, "Out of memory.");
    return;
}

JNIEXPORT void JNICALL throwIllegalArgumentException(
    JNIEnv *env,
    char const *reason)
{
    (*env)->ThrowNew(env, java_lang_IllegalArgumentException_class, reason);
    return;
}


JNIEXPORT void JNICALL throwNullPointerException(
    JNIEnv *env,
    char const *reason)
{
    (*env)->ThrowNew(env, java_lang_NullPointerException_class, reason);
    return;
}

JNIEXPORT void throwOSException(JNIEnv *env, int errorcode)
{
    jobject exc = (*env)->NewObject(env, jposix_OSException_class,
                                    jposix_OSException_init, errorcode);

    if (exc == NULL) {
        if ((*env)->ExceptionOccurred(env) == NULL)
            throwOutOfMemoryError(env);
    }
    else
        (*env)->Throw(env, exc);

    return;
}

JNIEXPORT void JNICALL throwUnsupportedOperationException(
    JNIEnv *env,
    char const *reason)
{
    (*env)->ThrowNew(env, java_lang_UnsupportedOperationException_class,
                     reason);
    return;
}


JNIEXPORT jobject JNICALL stat2java(JNIEnv *env, struct stat const *sbuf)
{
    jobject result = (*env)->AllocObject(env, jposix_struct_Stat_class);
    
    if (result == NULL) {
        if ((*env)->ExceptionOccurred(env) == NULL)
            throwOutOfMemoryError(env);

        return NULL;
    }

#define COPY_STAT_FIELD_LONG(fieldname)                               \
    (*env)->SetLongField(env, result, jposix_struct_Stat_##fieldname, \
                         (long) sbuf->fieldname)
#define COPY_STAT_FIELD_INT(fieldname)                                \
    (*env)->SetIntField(env, result, jposix_struct_Stat_##fieldname,  \
                         (long) sbuf->fieldname)

    COPY_STAT_FIELD_LONG(st_dev);
    COPY_STAT_FIELD_LONG(st_ino);
    COPY_STAT_FIELD_INT(st_mode);
    COPY_STAT_FIELD_LONG(st_nlink);
    COPY_STAT_FIELD_INT(st_uid);
    COPY_STAT_FIELD_INT(st_gid);
    COPY_STAT_FIELD_LONG(st_rdev);
    COPY_STAT_FIELD_LONG(st_size);
    COPY_STAT_FIELD_LONG(st_blksize);
    COPY_STAT_FIELD_LONG(st_blocks);
    COPY_STAT_FIELD_LONG(st_atime);
    COPY_STAT_FIELD_LONG(st_mtime);
    COPY_STAT_FIELD_LONG(st_ctime);

    return result;
}

static jclass getGlobalClassReference(JNIEnv *env, char const *name)
{
    jclass clazz = (*env)->FindClass(env, name);
    if (clazz != NULL)
        clazz = (*env)->NewGlobalRef(env, clazz);

    return clazz;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv *env;

    if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_4))
        return 0;

    /* Initialize the cached classes. */
    java_lang_OutOfMemoryError_class = NULL;
    jposix_OSException_class = NULL;

#define LOAD_CLASS(varname, classname)                                  \
    do {                                                                \
        if ((varname = getGlobalClassReference(env, classname)) == NULL) \
            goto error;                                                 \
    } while (0)

    LOAD_CLASS(java_lang_IllegalArgumentException_class,
               "java/lang/IllegalArgumentException");
    LOAD_CLASS(java_lang_NullPointerException_class,
               "java/lang/NullPointerException");
    LOAD_CLASS(java_lang_OutOfMemoryError_class, "java/lang/OutOfMemoryError");
    LOAD_CLASS(java_lang_UnsupportedOperationException_class,
               "java/lang/UnsupportedOperationException");
    LOAD_CLASS(byte_array_class, "[B");
    LOAD_CLASS(jposix_OSException_class, "jposix/OSException");
    LOAD_CLASS(jposix_Posix_class, "jposix/Posix");
    LOAD_CLASS(jposix_struct_Stat_class, "jposix/struct/Stat");

    /* Find the constructor for OSException. */
    if ((jposix_OSException_init = (*env)->GetMethodID(
             env, jposix_OSException_class, "<init>", "(I)V")) == NULL)
        goto error;

    /* Find the fields for Stat. */
#define GET_STAT_FIELD_LONG(name)                                       \
    do {                                                                \
        if ((jposix_struct_Stat_##name = (*env)->GetFieldID(            \
                 env, jposix_struct_Stat_class, #name, "J")) == NULL)   \
            goto error;                                                 \
    } while (0)

#define GET_STAT_FIELD_INT(name)                                        \
    do {                                                                \
        if ((jposix_struct_Stat_##name = (*env)->GetFieldID(            \
                 env, jposix_struct_Stat_class, #name, "I")) == NULL)   \
            goto error;                                                 \
    } while (0)

    GET_STAT_FIELD_LONG(st_dev);
    GET_STAT_FIELD_LONG(st_ino);
    GET_STAT_FIELD_INT(st_mode);
    GET_STAT_FIELD_LONG(st_nlink);
    GET_STAT_FIELD_INT(st_uid);
    GET_STAT_FIELD_INT(st_gid);
    GET_STAT_FIELD_LONG(st_rdev);
    GET_STAT_FIELD_LONG(st_size);
    GET_STAT_FIELD_LONG(st_blksize);
    GET_STAT_FIELD_LONG(st_blocks);
    GET_STAT_FIELD_LONG(st_atime);
    GET_STAT_FIELD_LONG(st_mtime);
    GET_STAT_FIELD_LONG(st_ctime);

    return JNI_VERSION_1_4;
    
error:
#define UNLOAD_CLASS(varname)                                          \
    do {                                                               \
        if (varname != NULL)                                           \
            (*env)->DeleteGlobalRef(env, varname);                     \
    } while (0)

    UNLOAD_CLASS(java_lang_OutOfMemoryError_class);
    UNLOAD_CLASS(jposix_OSException_class);
    UNLOAD_CLASS(jposix_struct_Stat_class);

    return 0;
}

/* Local variables: */
/* mode: C */
/* indent-tabs-mode: nil */
/* tab-width: 8 */
/* End: */
/* vi: set expandtab tabstop=8 */
