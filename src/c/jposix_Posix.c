/** @file   jposix_Posix.c
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

#include <jni.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "jposix_Posix.h"
#include "jposix_Utils.h"

extern char **environ;

JNIEXPORT jboolean JNICALL Java_jposix_Posix_S_1ISTYPE(
    JNIEnv *env,
    jclass self,
    jint mode,
    jint mask)
{
#ifdef S_ISTYPE
    return S_ISTYPE(mode, mask);
#else
    (*env)->ThrowNew(env, java_lang_UnsupportedOperationException_class,
                     "Macro S_ISTYPE not defined on this platform.");
    return 0;
#endif
}

JNIEXPORT jboolean JNICALL Java_jposix_Posix_S_1ISDIR(
    JNIEnv *env,
    jclass self,
    jint mode)
{
#ifdef S_ISDIR
    return S_ISDIR(mode);
#else
    (*env)->ThrowNew(env, java_lang_UnsupportedOperationException_class,
                     "Macro S_ISDIR not defined on this platform.");
    return 0;
#endif
}

JNIEXPORT jboolean JNICALL Java_jposix_Posix_S_1ISBLK(
    JNIEnv *env,
    jclass self,
    jint mode)
{
#ifdef S_ISBLK
    return S_ISBLK(mode);
#else
    (*env)->ThrowNew(env, java_lang_UnsupportedOperationException_class,
                     "Macro S_ISBLK not defined on this platform.");
    return 0;
#endif
}

JNIEXPORT jboolean JNICALL Java_jposix_Posix_S_1ISREG(
    JNIEnv *env,
    jclass self,
    jint mode)
{
#ifdef S_ISREG
    return S_ISREG(mode);
#else
    (*env)->ThrowNew(env, java_lang_UnsupportedOperationException_class,
                     "Macro S_ISREG not defined on this platform.");
    return 0;
#endif
}

JNIEXPORT jboolean JNICALL Java_jposix_Posix_S_1ISFIFO(
    JNIEnv *env,
    jclass self,
    jint mode)
{
#ifdef S_ISFIFO
    return S_ISFIFO(mode);
#else
    (*env)->ThrowNew(env, java_lang_UnsupportedOperationException_class,
                     "Macro S_ISFIFO not defined on this platform.");
    return 0;
#endif
}

JNIEXPORT jboolean JNICALL Java_jposix_Posix_S_1ISLNK(
    JNIEnv *env,
    jclass self,
    jint mode)
{
#ifdef S_ISLNK
    return S_ISLNK(mode);
#else
    (*env)->ThrowNew(env, java_lang_UnsupportedOperationException_class,
                     "Macro S_ISLNK not defined on this platform.");
    return 0;
#endif
}

JNIEXPORT jboolean JNICALL Java_jposix_Posix_S_1ISSOCK(
    JNIEnv *env,
    jclass self,
    jint mode)
{
#ifdef S_ISSOCK
    return S_ISSOCK(mode);
#else
    (*env)->ThrowNew(env, java_lang_UnsupportedOperationException_class,
                     "Macro S_ISSOCK not defined on this platform.");
    return 0;
#endif
}

JNIEXPORT void JNICALL Java_jposix_Posix_abort(
    JNIEnv *env,
    jclass clazz)
{
    abort();
}

JNIEXPORT void JNICALL Java_jposix_Posix_access(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path,
    int type)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    if (access((char *) pathBytes, type) != 0) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    XFREE(pathBytes);
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_acct(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;

    /* path is allowed to be null.  See the man page for acct(2). */
    if (path != NULL) {
        XBYTEARRAY_TO_CHAR(pathBytes, pathLength, path);
    }

    if (acct((char *) pathBytes) != 0) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    XFREE(pathBytes);
    return;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_alarm(
    JNIEnv *env,
    jclass clazz,
    jint seconds)
{
    return (jint) alarm((unsigned int) seconds);
}

JNIEXPORT void JNICALL Java_jposix_Posix_brk(
    JNIEnv *env,
    jclass clazz,
    jlong address)
{
    void *addr;

    if (sizeof(void *) == 4) {
        if (address >= 0x100000000LL) {
            throwIllegalArgumentException(
                env,
                "Address must be 32-bits on this platform.");
            return;
        }

        addr = (void *) (uintptr_t) address;
    } else {
        addr = (void *) (uintptr_t) address;
    }

    if (brk(addr) != 0) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_chdir(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    if (chdir((char *) pathBytes) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    XFREE(pathBytes);
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_chown(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path,
    jint uid,
    jint gid)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    if (chown((char *) pathBytes, (uid_t) uid, (gid_t) gid) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    XFREE(pathBytes);
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_chroot(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    if (chroot((char *) pathBytes) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    XFREE(pathBytes);
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_close(
    JNIEnv *env,
    jclass clazz,
    jint fd)
{
    if (close(fd) == -1)
        throwOSException(env, errno);

    return;
}

JNIEXPORT jbyteArray JNICALL Java_jposix_Posix_confstr(
    JNIEnv *env,
    jclass clazz,
    jint name)
{
    char *buf = NULL;
    size_t bufSize;
    jobject result;

    /* Determine the size needed for buf first. */
    bufSize = confstr(name, NULL, 0);
    
    if (bufSize == 0) {
        throwOSException(env, errno);
        goto finally;
    }

    XMALLOC(buf, bufSize);

    /* Now actually grab the string. */
    confstr(name, buf, bufSize);
    
    CHAR_TO_BYTEARRAY(result, buf, bufSize-1);

finally:
    XFREE(buf);
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_creat(
    JNIEnv *env,
    jclass clazz,
    jbyteArray file,
    jint mode)
{
    jsize fileLength;
    jbyte *fileBytes = NULL;
    int result = -1;

    if (file == NULL) {
        throwNullPointerException(env, "file cannot be null");
        goto finally;
    }

    BYTEARRAY_TO_CHAR(fileBytes, fileLength, file);

    if ((result = creat((char *) fileBytes, mode)) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    XFREE(fileBytes);
    return result;
}

JNIEXPORT jbyteArray JNICALL Java_jposix_Posix_crypt(
    JNIEnv *env,
    jclass clazz,
    jbyteArray key,
    jbyteArray salt)
{
    jsize keySize, saltSize;
    jbyte *keyBytes = NULL;
    jbyte *saltBytes = NULL;
    char *resultBytes;
    jbyteArray result = NULL;

    BYTEARRAY_TO_CHAR(keyBytes, keySize, key);
    BYTEARRAY_TO_CHAR(saltBytes, saltSize, salt);

    if (saltSize != 2) {
        throwIllegalArgumentException(env, "salt must be a 2-byte array.");
        goto finally;
    }

    resultBytes = crypt((char *) keyBytes, (char *) saltBytes);
    if (resultBytes == NULL) {
        throwOSException(env, errno);
        goto finally;
    }

    CHAR_TO_BYTEARRAY(result, resultBytes, strlen(resultBytes));

finally:
    XFREE(keyBytes);
    XFREE(saltBytes);

    return result;
}

JNIEXPORT jobject JNICALL Java_jposix_Posix_ctermid(
    JNIEnv *env,
    jclass clazz)
{
    char terminal[L_ctermid+1];
    int terminalSize;
    jobject result;

    ctermid(terminal);

    terminalSize = strlen(terminal);

    CHAR_TO_BYTEARRAY(result, terminal, terminalSize);

finally:
    return result;
}

JNIEXPORT void JNICALL Java_jposix_Posix_daemon(
    JNIEnv *env,
    jclass clazz,
    jboolean nochdir,
    jboolean noclose)
{
    if (daemon((int) nochdir, (int) noclose) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_dup(
    JNIEnv *env,
    jclass clazz,
    jint fd)
{
    jint result;

    if ((result = dup(fd)) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_dup2(
    JNIEnv *env,
    jclass clazz,
    jint oldfd,
    jint newfd)
{
    jint result;

    if ((result = dup2(oldfd, newfd)) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return result;
}

JNIEXPORT void JNICALL Java_jposix_Posix_encrypt(
    JNIEnv *env,
    jclass clazz,
    jbyteArray block,
    jboolean decrypt)
{
    jbyte blockBytes[8];
    char encBlock[64];
    int i, j;

    if (block == NULL) {
        throwNullPointerException(env, "block cannot be null");
        goto finally;
    }

    if ((*env)->GetArrayLength(env, block) != 8) {
        throwIllegalArgumentException(env, "block must be exactly 8 bytes.");
        goto finally;
    }

    (*env)->GetByteArrayRegion(env, block, 0, 8, blockBytes);
    
    /* Convert packed array to encrypt()'s sparse array. */
    for (i = 0, j = 0; i < 8; ++i) {
        encBlock[j++] = ((blockBytes[i] & 0x01) != 0 ? 1 : 0);
        encBlock[j++] = ((blockBytes[i] & 0x02) != 0 ? 1 : 0);
        encBlock[j++] = ((blockBytes[i] & 0x04) != 0 ? 1 : 0);
        encBlock[j++] = ((blockBytes[i] & 0x08) != 0 ? 1 : 0);
        encBlock[j++] = ((blockBytes[i] & 0x10) != 0 ? 1 : 0);
        encBlock[j++] = ((blockBytes[i] & 0x20) != 0 ? 1 : 0);
        encBlock[j++] = ((blockBytes[i] & 0x40) != 0 ? 1 : 0);
        encBlock[j++] = ((blockBytes[i] & 0x80) != 0 ? 1 : 0);
    }

    errno = 0;
    encrypt((char *) encBlock, (int) decrypt);
    if (errno != 0) {
        throwOSException(env, errno);
        goto finally;
    }

    /* Convert the sparse array back. */
    for (i = 0, j = 0; i < 8; ++i) {
        blockBytes[i] = 0;

        blockBytes[i] |= (encBlock[j++] != 0 ? 0x01 : 0x00);
        blockBytes[i] |= (encBlock[j++] != 0 ? 0x02 : 0x00);
        blockBytes[i] |= (encBlock[j++] != 0 ? 0x04 : 0x00);
        blockBytes[i] |= (encBlock[j++] != 0 ? 0x08 : 0x00);
        blockBytes[i] |= (encBlock[j++] != 0 ? 0x10 : 0x00);
        blockBytes[i] |= (encBlock[j++] != 0 ? 0x20 : 0x00);
        blockBytes[i] |= (encBlock[j++] != 0 ? 0x40 : 0x00);
        blockBytes[i] |= (encBlock[j++] != 0 ? 0x80 : 0x00);
    }

    (*env)->SetByteArrayRegion(env, block, 0, 8, blockBytes);

finally:
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_endusershell(
    JNIEnv *env,
    jclass clazz)
{
    endusershell();
}

JNIEXPORT jobject JNICALL Java_jposix_Posix_environ(
    JNIEnv *env,
    jclass clazz)
{
    jsize i, nEnviron;
    jobject result;

    /* Count the number of environment variables. */
    for (nEnviron = 0; environ[nEnviron] != NULL; ++nEnviron)
        ;

    if ((result = (*env)->NewObjectArray(env, nEnviron, byte_array_class, 
                                         NULL)) == NULL)
    {
        goto finally;
    }

    for (i = 0; i < nEnviron; ++i) {
        jobject el;

        CHAR_TO_BYTEARRAY(el, environ[i], strlen(environ[i]));
        
        (*env)->SetObjectArrayElement(env, result, i, el);
    }

finally:
    return result;
}

JNIEXPORT void JNICALL Java_jposix_Posix_euidaccess(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path,
    jint type)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    if (euidaccess((char *) pathBytes, type) != 0) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    XFREE(pathBytes);
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_execv(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path,
    jobjectArray args)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;
    char **argv = NULL;
    jsize i, nArgs;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    if (args == NULL) {
        throwNullPointerException(env, "argv cannot be null");
        goto finally;
    }

    nArgs = (*env)->GetArrayLength(env, args);
    XMALLOC(argv, sizeof(char *) * (nArgs + 1));

    /* Initialize argv to NULL before we copy byte arrays over.  This makes
       the finally block work as intended should an out-of-memory condition
       occur. */
    for (i = 0; i < nArgs; ++i)
        argv[i] = NULL;
    argv[nArgs] = NULL;

    /* Copy the array into argv. */
    for (i = 0; i < nArgs; ++i) {
        jobject el;
        char *elBytes;
        jsize elLength;

        el = (*env)->GetObjectArrayElement(env, args, i);
        BYTEARRAY_TO_CHAR(elBytes, elLength, el);
        argv[i] = elBytes;
    }

    execv((char *) pathBytes, argv);
    throwOSException(env, errno);

finally:
    if (argv != 0) {
        for (i = 0; i < nArgs; ++i)
            XFREE(argv[i]);

        free(argv);
    }

    XFREE(pathBytes);

    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_execve(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path,
    jobjectArray args,
    jobjectArray envs)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;
    char **argv = NULL;
    char **envp = NULL;
    jsize i, nArgs, nEnvs;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    if (args == NULL) {
        throwNullPointerException(env, "argv cannot be null");
        goto finally;
    }

    if (envs == NULL) {
        throwNullPointerException(env, "envp cannot be null");
        goto finally;
    }

    nArgs = (*env)->GetArrayLength(env, args);
    XMALLOC(argv, sizeof(char *) * (nArgs + 1));

    /* Initialize argv to NULL before we copy byte arrays over.  This makes
       the finally block work as intended should an out-of-memory condition
       occur. */
    for (i = 0; i < nArgs; ++i)
        argv[i] = NULL;
    argv[nArgs] = NULL;


    nEnvs = (*env)->GetArrayLength(env, envs);
    XMALLOC(envp, sizeof(char *) * (nEnvs + 1));

    /* Likewise, initialize envp to NULL. */
    for (i = 0; i < nEnvs; ++i)
        envp[i] = NULL;
    envp[nEnvs] = NULL;

    /* Copy the argument array into argv. */
    for (i = 0; i < nArgs; ++i) {
        jobject el;
        char *elBytes;
        jsize elLength;

        el = (*env)->GetObjectArrayElement(env, args, i);
        BYTEARRAY_TO_CHAR(elBytes, elLength, el);
        argv[i] = elBytes;
    }

    /* Likewise for the environment array. */
    for (i = 0; i < nEnvs; ++i) {
        jobject el;
        char *elBytes;
        jsize elLength;

        el = (*env)->GetObjectArrayElement(env, args, i);
        BYTEARRAY_TO_CHAR(elBytes, elLength, el);
        envp[i] = elBytes;
    }

    execve((char *) pathBytes, argv, envp);
    throwOSException(env, errno);

finally:
    if (argv != 0) {
        for (i = 0; i < nArgs; ++i)
            XFREE(argv[i]);

        free(argv);
    }

    if (envp != 0) {
        for (i = 0; i < nArgs; ++i)
            XFREE(envp[i]);

        free(envp);
    }

    XFREE(pathBytes);

    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_execvp(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path,
    jobjectArray args)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;
    char **argv = NULL;
    jsize i, nArgs;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    if (args == NULL) {
        throwNullPointerException(env, "args cannot be null");
        goto finally;
    }

    nArgs = (*env)->GetArrayLength(env, args);
    XMALLOC(argv, sizeof(char *) * (nArgs + 1));

    /* Initialize argv to NULL before we copy byte arrays over.  This makes
       the finally block work as intended should an out-of-memory condition
       occur. */
    for (i = 0; i < nArgs; ++i)
        argv[i] = NULL;
    argv[nArgs] = NULL;

    /* Copy the array into argv. */
    for (i = 0; i < nArgs; ++i) {
        jobject el;
        char *elBytes;
        jsize elLength;

        el = (*env)->GetObjectArrayElement(env, args, i);
        BYTEARRAY_TO_CHAR(elBytes, elLength, el);
        argv[i] = elBytes;
    }

    execvp((char *) pathBytes, argv);
    throwOSException(env, errno);

finally:
    if (argv != 0) {
        for (i = 0; i < nArgs; ++i)
            XFREE(argv[i]);

        free(argv);
    }

    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix__1exit(
    JNIEnv *env,
    jclass clazz,
    jint status)
{
    _exit(status);
}

JNIEXPORT void JNICALL Java_jposix_Posix_fchdir(
    JNIEnv *env,
    jclass clazz,
    jint fd)
{
    if (fchdir(fd) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_fchown(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jint owner,
    jint group)
{
    if (fchown(fd, owner, group) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return;
}

JNIEXPORT jint JNICALL Java_jposix_Posix__1fcntl1(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jint cmd)
{
    jint result;

    errno = 0;
    result = fcntl(fd, cmd);

    if (errno != 0) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix__1fcntl2(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jint cmd,
    jint arg)
{
    jint result;

    errno = 0;
    result = fcntl(fd, cmd, arg);

    if (errno != 0) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return result;
}

JNIEXPORT void JNICALL Java_jposix_Posix_fdatasync(
    JNIEnv *env,
    jclass clazz,
    jint fd)
{
    if (fdatasync(fd) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_fexecve(
    JNIEnv *env,
    jclass clazz,
    int fd,
    jobjectArray args,
    jobjectArray envs)
{
#ifdef HAS_FEXECVE
    char **argv = NULL;
    char **envp = NULL;
    jsize i, nArgs, nEnvs;

    if (args == NULL) {
        throwNullPointerException(env, "argv cannot be null");
        goto finally;
    }

    if (envs == NULL) {
        throwNullPointerException(env, "envp cannot be null");
        goto finally;
    }

    nArgs = (*env)->GetArrayLength(env, args);
    XMALLOC(argv, sizeof(char *) * (nArgs + 1));

    /* Initialize argv to NULL before we copy byte arrays over.  This makes
       the finally block work as intended should an out-of-memory condition
       occur. */
    for (i = 0; i < nArgs; ++i)
        argv[i] = NULL;
    argv[nArgs] = NULL;


    nEnvs = (*env)->GetArrayLength(env, envs);
    XMALLOC(envp, sizeof(char *) * (nEnvs + 1));

    /* Likewise, initialize envp to NULL. */
    for (i = 0; i < nEnvs; ++i)
        envp[i] = NULL;
    envp[nEnvs] = NULL;

    /* Copy the argument array into argv. */
    for (i = 0; i < nArgs; ++i) {
        jobject el;
        char *elBytes;
        jsize elLength;

        el = (*env)->GetObjectArrayElement(env, args, i);
        BYTEARRAY_TO_CHAR(elBytes, elLength, el);
        argv[i] = elBytes;
    }

    /* Likewise for the environment array. */
    for (i = 0; i < nEnvs; ++i) {
        jobject el;
        char *elBytes;
        jsize elLength;

        el = (*env)->GetObjectArrayElement(env, args, i);
        BYTEARRAY_TO_CHAR(elBytes, elLength, el);
        envp[i] = elBytes;
    }

    fexecve(fd, argv, envp);
    throwOSException(env, errno);

finally:
    if (argv != 0) {
        for (i = 0; i < nArgs; ++i)
            XFREE(argv[i]);

        free(argv);
    }

    if (envp != 0) {
        for (i = 0; i < nArgs; ++i)
            XFREE(envp[i]);

        free(envp);
    }

    return;
#else /* ! HAS_FEXECVE */
    throwUnsupportedOperationException(
        "fexecve not supported on this platform");
    return;
#endif
}

JNIEXPORT jint JNICALL Java_jposix_Posix_fork(
    JNIEnv *env,
    jclass clazz)
{
    pid_t result = fork();

    if (result == (pid_t) -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return (int) result;
}


JNIEXPORT jlong JNICALL Java_jposix_Posix_fpathconf(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jint name)
{
    jlong result;

    errno = 0;
    result = fpathconf(fd, name);
    if (errno != 0) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return result;
}

JNIEXPORT jobject JNICALL Java_jposix_Posix_fstat(
    JNIEnv *env,
    jclass clazz,
    jint fd)
{
    struct stat statbuf;
    jobject result;

    if (fstat(fd, &statbuf) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

    result = stat2java(env, &statbuf);

finally:
    return result;
}

JNIEXPORT void JNICALL Java_jposix_Posix_fsync(
    JNIEnv *env,
    jclass clazz,
    jint fd)
{
    if (fsync(fd) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_ftruncate(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jlong length)
{
    if (ftruncate(fd, length) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return;
}

JNIEXPORT jbyteArray JNICALL Java_jposix_Posix_getcwd(
    JNIEnv *env,
    jclass clazz)
{
    char *buf = NULL;
    size_t bufSize = 256;
    jobject result = NULL;

    /* Keep trying until we have a big enough buf. */
    while (1) {
        XMALLOC(buf, bufSize);

        errno = 0;
        getcwd(buf, bufSize);
        if (errno == 0) {
            CHAR_TO_BYTEARRAY(result, buf, strlen(buf));
            break;
        }
        
        if (errno != ERANGE) {
            throwOSException(env, errno);
            goto finally;
        }

        /* Need to try again with bigger buf. */
        XFREE(buf);
        buf = NULL;
        bufSize *= 2;
    }

finally:
    XFREE(buf);
    return result;
}

JNIEXPORT jbyteArray JNICALL Java_jposix_Posix_getdomainname(
    JNIEnv *env,
    jclass clazz)
{
    char *buf = NULL;
    size_t bufSize = 256;
    jobject result = NULL;

    /* Keep trying until we have a big enough buf. */
    while (1) {
        XMALLOC(buf, bufSize);

        errno = 0;
        getdomainname(buf, bufSize);
        if (errno == 0) {
            CHAR_TO_BYTEARRAY(result, buf, strlen(buf));
            break;
        }
        
        if (errno != EINVAL) {
            throwOSException(env, errno);
            goto finally;
        }

        /* Need to try again with bigger buf. */
        XFREE(buf);
        buf = NULL;
        bufSize *= 2;
    }

finally:
    XFREE(buf);
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_getdtablesize(
    JNIEnv *env,
    jclass clazz)
{
    jint result;

    errno = 0;
    result = getdtablesize();
    if (errno != 0) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_getegid(
    JNIEnv *env,
    jclass clazz)
{
    return getegid();
}

JNIEXPORT jbyteArray JNICALL Java_jposix_Posix_getenv(
    JNIEnv *env,
    jclass clazz,
    jbyteArray name)
{
    jsize nameSize;
    jbyte *nameBytes = NULL;
    jbyteArray result = NULL;
    char *value;

    BYTEARRAY_TO_CHAR(nameBytes, nameSize, name);
    
    value = getenv((char *) nameBytes);
    if (value != NULL) {
        CHAR_TO_BYTEARRAY(result, value, strlen(value));
    }

finally:
    XFREE(nameBytes);
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_geteuid(
    JNIEnv *env,
    jclass clazz)
{
    return geteuid();
}

JNIEXPORT jint JNICALL Java_jposix_Posix_getgid(
    JNIEnv *env,
    jclass clazz)
{
    return getgid();
}

JNIEXPORT jintArray JNICALL Java_jposix_Posix_getgroups(
    JNIEnv *env,
    jclass clazz)
{
    gid_t *groups = NULL;
    jint *jgroups;
    int i, size = 0;
    jintArray result;

    size = getgroups(0, NULL);
    
    XMALLOC(groups, sizeof(int) * size);
    XMALLOC(jgroups, sizeof(jint) * size);

    if (getgroups(size, groups) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

    if ((result = (*env)->NewIntArray(env, size)) == NULL)
        goto finally;

    /* Need to copy groups to an int array; sizeof(gid_t) may not be the same
       as sizeof(jint). */
    for (i = 0; i < size; ++i)
        jgroups[i] = (jint) groups[i];

    (*env)->SetIntArrayRegion(env, result, 0, size, jgroups);

finally:
    XFREE(groups);
    XFREE(jgroups);
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_gethostid(
    JNIEnv *env,
    jclass clazz)
{
    return gethostid();
}

JNIEXPORT jbyteArray JNICALL Java_jposix_Posix_gethostname(
    JNIEnv *env,
    jclass clazz)
{
    char *buf = NULL;
    size_t bufSize = HOST_NAME_MAX + 1;
    jobject result = NULL;

    /* Keep trying until we have a big enough buf. */
    while (1) {
        XMALLOC(buf, bufSize);

        if (gethostname(buf, bufSize) == 0) {
            CHAR_TO_BYTEARRAY(result, buf, strlen(buf));
            break;
        }

        if (errno != EINVAL) {
            throwOSException(env, errno);
            goto finally;
        }

        /* Need to try again with bigger buf. */
        XFREE(buf);
        buf = NULL;
        bufSize *= 2;
    }

finally:
    XFREE(buf);
    return result;
}

JNIEXPORT jbyteArray JNICALL Java_jposix_Posix_getlogin(
    JNIEnv *env,
    jclass clazz)
{
    char *buf = NULL;
    size_t bufSize = 64;
    jobject result = NULL;

    /* Keep trying until we have a big enough buf. */
    while (1) {
        XMALLOC(buf, bufSize);

        if (getlogin_r(buf, bufSize) == 0) {
            CHAR_TO_BYTEARRAY(result, buf, strlen(buf));
            break;
        }

        if (errno != ERANGE) {
            throwOSException(env, errno);
            goto finally;
        }

        /* Need to try again with bigger buf. */
        XFREE(buf);
        buf = NULL;
        bufSize *= 2;
    }

finally:
    XFREE(buf);
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_getpagesize(
    JNIEnv *env,
    jclass clazz)
{
    return getpagesize();
}

JNIEXPORT jbyteArray JNICALL Java_jposix_Posix_getpass(
    JNIEnv *env,
    jclass clazz,
    jbyteArray prompt)
{
    jsize promptSize;
    char *promptBytes = NULL;
    char *password;
    jobject result = NULL;

    BYTEARRAY_TO_CHAR(promptBytes, promptSize, prompt);
    password = getpass(promptBytes);
    
    if (password == NULL) {
        throwOSException(env, errno);
        goto finally;
    }

    CHAR_TO_BYTEARRAY(result, password, strlen(password));
    
finally:
    XFREE(promptBytes);
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_getpgid(
    JNIEnv *env,
    jclass clazz,
    jint pid)
{
    jint result;

    if ((result = (jint) getpgid((pid_t) pid)) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_getpid(
    JNIEnv *env,
    jclass clazz)
{
    return (jint) getpid();
}

JNIEXPORT jint JNICALL Java_jposix_Posix_getppid(
    JNIEnv *env,
    jclass clazz)
{
    return (jint) getppid();
}

JNIEXPORT jintArray JNICALL Java_jposix_Posix_getresgid(
    JNIEnv *env,
    jclass clazz)
{
#ifdef HAS_GETRESGID
    uid_t rgid, egid, sgid;
    jint gids[3];
    jintArray result = NULL;

    if (getresgid(&rgid, &egid, &sgid) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

    if ((result = (*env)->NewIntArray(env, 3)) == NULL)
        goto finally;

    gids[0] = (jint) rgid;
    gids[1] = (jint) egid;
    gids[2] = (jint) sgid;

    (*env)->SetIntArrayRegion(env, result, 0, 3, gids);

finally:
    return result;

#else /* ! HAS_GETRESGID */
    throwUnsupportedOperationException(
        "getresgid not supported on this platform");
    return;
#endif
}

JNIEXPORT jintArray JNICALL Java_jposix_Posix_getresuid(
    JNIEnv *env,
    jclass clazz)
{
#ifdef HAS_GETRESUID
    uid_t ruid, euid, suid;
    jint uids[3];
    jintArray result = NULL;

    if (getresuid(&ruid, &euid, &suid) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

    if ((result = (*env)->NewIntArray(env, 3)) == NULL)
        goto finally;

    uids[0] = (jint) ruid;
    uids[1] = (jint) euid;
    uids[2] = (jint) suid;

    (*env)->SetIntArrayRegion(env, result, 0, 3, uids);

finally:
    return result;

#else /* ! HAS_GETRESUID */
    throwUnsupportedOperationException(
        "getresuid not supported on this platform");
    return;
#endif
}

JNIEXPORT jint JNICALL Java_jposix_Posix_getsid(
    JNIEnv *env,
    jclass clazz,
    jint pid)
{
#ifdef HAS_GETSID
    jint result;

    if ((result = (jint) getsid((pid_t) pid)) == (pid_t) -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return result;

#else /* ! HAS_GETSID */
    throwUnsupportedOperationException(
        "getsid not supported on this platform");
    return 0;
#endif
}

JNIEXPORT jint JNICALL Java_jposix_Posix_getuid(
    JNIEnv *env,
    jclass clazz)
{
    return getuid();
}

JNIEXPORT jbyteArray JNICALL Java_jposix_Posix_getusershell(
    JNIEnv *env,
    jclass clazz)
{
    jbyteArray result = NULL;
    char *shell;

    if ((shell = getusershell()) != NULL)
        CHAR_TO_BYTEARRAY(result, shell, strlen(shell));

finally:
    return result;
}

JNIEXPORT jboolean JNICALL Java_jposix_Posix_isatty(
    JNIEnv *env,
    jclass clazz,
    jint fd)
{
    return (isatty(fd) != 0 ? JNI_TRUE : JNI_FALSE);
}

JNIEXPORT void JNICALL Java_jposix_Posix_lchown(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path,
    jint uid,
    jint gid)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    if (lchown((char *) pathBytes, (uid_t) uid, (gid_t) gid) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    XFREE(pathBytes);
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_link(
    JNIEnv *env,
    jclass clazz,
    jbyteArray from,
    jbyteArray to)
{
    jsize fromLength, toLength;
    char *fromBytes = NULL, *toBytes = NULL;

    BYTEARRAY_TO_CHAR(fromBytes, fromLength, from);
    BYTEARRAY_TO_CHAR(toBytes, toLength, to);

    if (link(fromBytes, toBytes) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    XFREE(fromBytes);
    XFREE(toBytes);
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_lockf(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jint cmd,
    jlong len)
{
    if (lockf(fd, cmd, (off_t) len) == -1)
        throwOSException(env, errno);

    return;
}

JNIEXPORT jlong JNICALL Java_jposix_Posix_lseek(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jlong offset,
    jint whence)
{
    off_t newpos;

    if ((newpos = lseek(fd, (off_t) offset, whence)) == (off_t) -1)
        throwOSException(env, errno);
        
    return (jlong) newpos;
}

JNIEXPORT jobject JNICALL Java_jposix_Posix_lstat(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;
    jobject result = NULL;
    struct stat statbuf;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    if (lstat((char *) pathBytes, &statbuf) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

    result = stat2java(env, &statbuf);

finally:
    XFREE(pathBytes);
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_nice(
    JNIEnv *env,
    jclass clazz,
    jint increment)
{
    jint result;

    errno = 0;
    result = nice(increment);
    if (errno != 0) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_open(
    JNIEnv *env,
    jclass clazz,
    jbyteArray file,
    jint oflag,
    jint mode)
{
    jsize fileLength;
    char *fileBytes = NULL;
    jint result;

    BYTEARRAY_TO_CHAR(fileBytes, fileLength, file);

    if ((result = open(fileBytes, oflag, mode)) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    XFREE(fileBytes);
    return result;
}

JNIEXPORT void JNICALL Java_jposix_Posix_pause(
    JNIEnv *env,
    jclass clazz)
{
    if (pause() == -1)
        throwOSException(env, errno);

    return;
}

JNIEXPORT jlong JNICALL Java_jposix_Posix_pathconf(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path,
    jint name)
{
    jsize pathLength;
    char *pathBytes = NULL;
    jlong result;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    errno = 0;
    result = pathconf(pathBytes, name);
    if (errno != 0) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    XFREE(pathBytes);
    return result;
}

JNIEXPORT void JNICALL Java_jposix_Posix_pipe(
    JNIEnv *env,
    jclass clazz,
    jintArray pipedes)
{
    int fds[2];

    if (pipedes == NULL) {
        throwNullPointerException(env, "pipedes cannot be null");
        goto finally;
    }

    if ((*env)->GetArrayLength(env, pipedes) != 2) {
        throwNullPointerException(env, "Length of pipedes array must be 2");
        goto finally;
    }

    if (pipe(fds) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

    (*env)->SetIntArrayRegion(env, pipedes, 0, 2, fds);

finally:
    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_posix__1fadvise(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jlong offset,
    jlong len,
    jint advise)
{
    if (posix_fadvise(fd, (off_t) offset, (off_t) len, advise) == -1)
        throwOSException(env, errno);

    return;
}

JNIEXPORT void JNICALL Java_jposix_Posix_posix__1fallocate(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jlong offset,
    jlong len)
{
    if (posix_fallocate(fd, (off_t) offset, (off_t) len) == -1)
        throwOSException(env, errno);

    return;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_pread(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jbyteArray buf,
    jint start,
    jint len,
    jlong offset)
{
    jsize bufSize;
    jbyte *elements;
    ssize_t result;

    if (buf == NULL) {
        throwNullPointerException(env, "buf cannot be null");
        goto finally;
    }

    bufSize = (*env)->GetArrayLength(env, buf);
    
    if (start < 0) {
        throwIllegalArgumentException(env, "start cannot be negative");
        goto finally;
    }

    if (start >= bufSize) {
        throwIllegalArgumentException(
            env, "start must be less than buf.length");
        goto finally;
    }

    if (len < 0) {
        throwIllegalArgumentException(env, "length cannot be negative");
        goto finally;
    }

    if (start + len > bufSize) {
        throwIllegalArgumentException(
            env, "start + length cannot be greater than buf.length");
        goto finally;
    }

    if ((elements = (*env)->GetByteArrayElements(env, buf, NULL)) == NULL)
        goto finally;

    result = pread(fd, elements + start, (size_t) len, (off_t) offset);
    if (result == -1) {
        (*env)->ReleaseByteArrayElements(env, buf, elements, JNI_ABORT);
        throwOSException(env, errno);
        goto finally;
    }

    (*env)->ReleaseByteArrayElements(env, buf, elements, 0);
    
finally:
    return (jint) result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_pwrite(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jbyteArray buf,
    jint start,
    jint len,
    jlong offset)
{
    jsize bufSize;
    jbyte *elements;
    ssize_t result;

    if (buf == NULL) {
        throwNullPointerException(env, "buf cannot be null");
        goto finally;
    }

    bufSize = (*env)->GetArrayLength(env, buf);
    
    if (start < 0) {
        throwIllegalArgumentException(env, "start cannot be negative");
        goto finally;
    }

    if (start >= bufSize) {
        throwIllegalArgumentException(
            env, "start must be less than buf.length");
        goto finally;
    }

    if (len < 0) {
        throwIllegalArgumentException(env, "length cannot be negative");
        goto finally;
    }

    if (start + len > bufSize) {
        throwIllegalArgumentException(
            env, "start + length cannot be greater than buf.length");
        goto finally;
    }

    if ((elements = (*env)->GetByteArrayElements(env, buf, NULL)) == NULL)
        goto finally;

    result = pwrite(fd, elements + start, (size_t) len, (off_t) offset);
    (*env)->ReleaseByteArrayElements(env, buf, elements, JNI_ABORT);

    if (result == -1) {
        throwOSException(env, errno);
        goto finally;
    }

finally:
    return (jint) result;
}

JNIEXPORT jint JNICALL Java_jposix_Posix_read(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jbyteArray buf,
    jint start,
    jint len)
{
    jsize bufSize;
    jbyte *elements;
    ssize_t result;

    if (buf == NULL) {
        throwNullPointerException(env, "buf cannot be null");
        goto finally;
    }

    bufSize = (*env)->GetArrayLength(env, buf);
    
    if (start < 0) {
        throwIllegalArgumentException(env, "start cannot be negative");
        goto finally;
    }

    if (start >= bufSize) {
        throwIllegalArgumentException(
            env, "start must be less than buf.length");
        goto finally;
    }

    if (len < 0) {
        throwIllegalArgumentException(env, "length cannot be negative");
        goto finally;
    }

    if (start + len > bufSize) {
        throwIllegalArgumentException(
            env, "start + length cannot be greater than buf.length");
        goto finally;
    }

    if ((elements = (*env)->GetByteArrayElements(env, buf, NULL)) == NULL)
        goto finally;

    result = read(fd, elements + start, (size_t) len);
    if (result == -1) {
        (*env)->ReleaseByteArrayElements(env, buf, elements, JNI_ABORT);
        throwOSException(env, errno);
        goto finally;
    }

    (*env)->ReleaseByteArrayElements(env, buf, elements, 0);
    
finally:
    return (jint) result;
}

JNIEXPORT jlong JNICALL Java_jposix_Posix_sbrk(
    JNIEnv *env,
    jclass clazz,
    jlong increment)
{
    void *result;

    if (sizeof(void *) == 4) {
        if (increment >= 0x100000000LL) {
            throwIllegalArgumentException(
                env,
                "Address increments must be 32-bits on this platform");
            return 0;
        }
    }

    result = sbrk((ptrdiff_t) increment);
    return (jlong) (intptr_t) result;
}

JNIEXPORT void JNICALL Java_jposix_Posix_setusershell(
    JNIEnv *env,
    jclass clazz)
{
    setusershell();
}

JNIEXPORT jobject JNICALL Java_jposix_Posix_stat(
    JNIEnv *env,
    jclass clazz,
    jbyteArray path)
{
    jsize pathLength;
    jbyte *pathBytes = NULL;
    jobject result = NULL;
    struct stat statbuf;

    BYTEARRAY_TO_CHAR(pathBytes, pathLength, path);

    if (stat((char *) pathBytes, &statbuf) == -1) {
        throwOSException(env, errno);
        goto finally;
    }

    result = stat2java(env, &statbuf);

finally:
    XFREE(pathBytes);
    return result;
}

JNIEXPORT jstring JNICALL Java_jposix_Posix_strerror(
    JNIEnv *env,
    jclass self,
    jint errcode)
{
    return (*env)->NewStringUTF(env, strerror(errcode));
}


JNIEXPORT jint JNICALL Java_jposix_Posix_write(
    JNIEnv *env,
    jclass clazz,
    jint fd,
    jbyteArray buf,
    jint start,
    jint len)
{
    jsize bufSize;
    jbyte *elements;
    ssize_t result;

    if (buf == NULL) {
        throwNullPointerException(env, "buf cannot be null");
        goto finally;
    }

    bufSize = (*env)->GetArrayLength(env, buf);
    
    if (start < 0) {
        throwIllegalArgumentException(env, "start cannot be negative");
        goto finally;
    }

    if (start >= bufSize) {
        throwIllegalArgumentException(
            env, "start must be less than buf.length");
        goto finally;
    }

    if (len < 0) {
        throwIllegalArgumentException(env, "length cannot be negative");
        goto finally;
    }

    if (start + len > bufSize) {
        throwIllegalArgumentException(
            env, "start + length cannot be greater than buf.length");
        goto finally;
    }

    if ((elements = (*env)->GetByteArrayElements(env, buf, NULL)) == NULL)
        goto finally;

    result = write(fd, elements + start, (size_t) len);
    (*env)->ReleaseByteArrayElements(env, buf, elements, JNI_ABORT);

    if (result == -1) {
        throwOSException(env, errno);
        goto finally;
    }
    
finally:
    return (jint) result;
}

/* Local variables: */
/* mode: C */
/* indent-tabs-mode: nil */
/* tab-width: 8 */
/* End: */
/* vi: set expandtab tabstop=8 */
