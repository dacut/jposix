/** @file   jposix_Posix_constants.c
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


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1DUPFD(JNIEnv *env, jclass clazz)
{
#if defined(F_DUPFD)
    return F_DUPFD;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1DUPFD_1CLOEXEC(JNIEnv *env, jclass clazz)
{
#if defined(F_DUPFD_CLOEXEC)
    return F_DUPFD_CLOEXEC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1GETFD(JNIEnv *env, jclass clazz)
{
#if defined(F_GETFD)
    return F_GETFD;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1SETFD(JNIEnv *env, jclass clazz)
{
#if defined(F_SETFD)
    return F_SETFD;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1GETFL(JNIEnv *env, jclass clazz)
{
#if defined(F_GETFL)
    return F_GETFL;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1SETFL(JNIEnv *env, jclass clazz)
{
#if defined(F_SETFL)
    return F_SETFL;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1GETLK(JNIEnv *env, jclass clazz)
{
#if defined(F_GETLK)
    return F_GETLK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1SETLK(JNIEnv *env, jclass clazz)
{
#if defined(F_SETLK)
    return F_SETLK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1SETLKW(JNIEnv *env, jclass clazz)
{
#if defined(F_SETLKW)
    return F_SETLKW;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1GETOWN(JNIEnv *env, jclass clazz)
{
#if defined(F_GETOWN)
    return F_GETOWN;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1SETOWN(JNIEnv *env, jclass clazz)
{
#if defined(F_SETOWN)
    return F_SETOWN;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1GETSIG(JNIEnv *env, jclass clazz)
{
#if defined(F_GETSIG)
    return F_GETSIG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1SETSIG(JNIEnv *env, jclass clazz)
{
#if defined(F_SETSIG)
    return F_SETSIG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1GETLEASE(JNIEnv *env, jclass clazz)
{
#if defined(F_GETLEASE)
    return F_GETLEASE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1SETLEASE(JNIEnv *env, jclass clazz)
{
#if defined(F_SETLEASE)
    return F_SETLEASE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1NOTIFY(JNIEnv *env, jclass clazz)
{
#if defined(F_NOTIFY)
    return F_NOTIFY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1RDLCK(JNIEnv *env, jclass clazz)
{
#if defined(F_RDLCK)
    return F_RDLCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1WRLCK(JNIEnv *env, jclass clazz)
{
#if defined(F_WRLCK)
    return F_WRLCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1UNLCK(JNIEnv *env, jclass clazz)
{
#if defined(F_UNLCK)
    return F_UNLCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1UNLOCK(JNIEnv *env, jclass clazz)
{
#if defined(F_UNLOCK)
    return F_UNLOCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1LOCK(JNIEnv *env, jclass clazz)
{
#if defined(F_LOCK)
    return F_LOCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1TLOCK(JNIEnv *env, jclass clazz)
{
#if defined(F_TLOCK)
    return F_TLOCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1TEST(JNIEnv *env, jclass clazz)
{
#if defined(F_TEST)
    return F_TEST;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1RDONLY(JNIEnv *env, jclass clazz)
{
#if defined(O_RDONLY)
    return O_RDONLY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1WRONLY(JNIEnv *env, jclass clazz)
{
#if defined(O_WRONLY)
    return O_WRONLY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1RDWR(JNIEnv *env, jclass clazz)
{
#if defined(O_RDWR)
    return O_RDWR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1CREAT(JNIEnv *env, jclass clazz)
{
#if defined(O_CREAT)
    return O_CREAT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1EXCL(JNIEnv *env, jclass clazz)
{
#if defined(O_EXCL)
    return O_EXCL;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1NOCTTY(JNIEnv *env, jclass clazz)
{
#if defined(O_NOCTTY)
    return O_NOCTTY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1TRUNC(JNIEnv *env, jclass clazz)
{
#if defined(O_TRUNC)
    return O_TRUNC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1APPEND(JNIEnv *env, jclass clazz)
{
#if defined(O_APPEND)
    return O_APPEND;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1NONBLOCK(JNIEnv *env, jclass clazz)
{
#if defined(O_NONBLOCK)
    return O_NONBLOCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1NDELAY(JNIEnv *env, jclass clazz)
{
#if defined(O_NDELAY)
    return O_NDELAY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1SYNC(JNIEnv *env, jclass clazz)
{
#if defined(O_SYNC)
    return O_SYNC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1FSYNC(JNIEnv *env, jclass clazz)
{
#if defined(O_FSYNC)
    return O_FSYNC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1ASYNC(JNIEnv *env, jclass clazz)
{
#if defined(O_ASYNC)
    return O_ASYNC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1DIRECT(JNIEnv *env, jclass clazz)
{
#if defined(O_DIRECT)
    return O_DIRECT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1DIRECTORY(JNIEnv *env, jclass clazz)
{
#if defined(O_DIRECTORY)
    return O_DIRECTORY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1NOFOLLOW(JNIEnv *env, jclass clazz)
{
#if defined(O_NOFOLLOW)
    return O_NOFOLLOW;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1DSYNC(JNIEnv *env, jclass clazz)
{
#if defined(O_DSYNC)
    return O_DSYNC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1RSYNC(JNIEnv *env, jclass clazz)
{
#if defined(O_RSYNC)
    return O_RSYNC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1O_1LARGEFILE(JNIEnv *env, jclass clazz)
{
#if defined(O_LARGEFILE)
    return O_LARGEFILE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1POSIX_1FADV_1NORMAL(JNIEnv *env, jclass clazz)
{
#if defined(POSIX_FADV_NORMAL)
    return POSIX_FADV_NORMAL;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1POSIX_1FADV_1SEQUENTIAL(JNIEnv *env, jclass clazz)
{
#if defined(POSIX_FADV_SEQUENTIAL)
    return POSIX_FADV_SEQUENTIAL;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1POSIX_1FADV_1RANDOM(JNIEnv *env, jclass clazz)
{
#if defined(POSIX_FADV_RANDOM)
    return POSIX_FADV_RANDOM;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1POSIX_1FADV_1NOREUSE(JNIEnv *env, jclass clazz)
{
#if defined(POSIX_FADV_NOREUSE)
    return POSIX_FADV_NOREUSE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1POSIX_1FADV_1WILLNEED(JNIEnv *env, jclass clazz)
{
#if defined(POSIX_FADV_WILLNEED)
    return POSIX_FADV_WILLNEED;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1POSIX_1FADV_1DONTNEED(JNIEnv *env, jclass clazz)
{
#if defined(POSIX_FADV_DONTNEED)
    return POSIX_FADV_DONTNEED;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IFMT(JNIEnv *env, jclass clazz)
{
#if defined(S_IFMT)
    return S_IFMT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IFDIR(JNIEnv *env, jclass clazz)
{
#if defined(S_IFDIR)
    return S_IFDIR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IFCHR(JNIEnv *env, jclass clazz)
{
#if defined(S_IFCHR)
    return S_IFCHR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IFREG(JNIEnv *env, jclass clazz)
{
#if defined(S_IFREG)
    return S_IFREG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IFIFO(JNIEnv *env, jclass clazz)
{
#if defined(S_IFIFO)
    return S_IFIFO;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IFLNK(JNIEnv *env, jclass clazz)
{
#if defined(S_IFLNK)
    return S_IFLNK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IFSOCK(JNIEnv *env, jclass clazz)
{
#if defined(S_IFSOCK)
    return S_IFSOCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1ISUID(JNIEnv *env, jclass clazz)
{
#if defined(S_ISUID)
    return S_ISUID;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1ISGID(JNIEnv *env, jclass clazz)
{
#if defined(S_ISGID)
    return S_ISGID;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IREAD(JNIEnv *env, jclass clazz)
{
#if defined(S_IREAD)
    return S_IREAD;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IWRITE(JNIEnv *env, jclass clazz)
{
#if defined(S_IWRITE)
    return S_IWRITE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IEXEC(JNIEnv *env, jclass clazz)
{
#if defined(S_IEXEC)
    return S_IEXEC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IRUSR(JNIEnv *env, jclass clazz)
{
#if defined(S_IRUSR)
    return S_IRUSR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IWUSR(JNIEnv *env, jclass clazz)
{
#if defined(S_IWUSR)
    return S_IWUSR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IXUSR(JNIEnv *env, jclass clazz)
{
#if defined(S_IXUSR)
    return S_IXUSR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IRWXU(JNIEnv *env, jclass clazz)
{
#if defined(S_IRWXU)
    return S_IRWXU;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IRGRP(JNIEnv *env, jclass clazz)
{
#if defined(S_IRGRP)
    return S_IRGRP;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IWGRP(JNIEnv *env, jclass clazz)
{
#if defined(S_IWGRP)
    return S_IWGRP;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IXGRP(JNIEnv *env, jclass clazz)
{
#if defined(S_IXGRP)
    return S_IXGRP;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IRWXG(JNIEnv *env, jclass clazz)
{
#if defined(S_IRWXG)
    return S_IRWXG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IROTH(JNIEnv *env, jclass clazz)
{
#if defined(S_IROTH)
    return S_IROTH;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IWOTH(JNIEnv *env, jclass clazz)
{
#if defined(S_IWOTH)
    return S_IWOTH;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IXOTH(JNIEnv *env, jclass clazz)
{
#if defined(S_IXOTH)
    return S_IXOTH;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1S_1IRWXO(JNIEnv *env, jclass clazz)
{
#if defined(S_IRWXO)
    return S_IRWXO;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1R_1OK(JNIEnv *env, jclass clazz)
{
#if defined(R_OK)
    return R_OK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1W_1OK(JNIEnv *env, jclass clazz)
{
#if defined(W_OK)
    return W_OK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1X_1OK(JNIEnv *env, jclass clazz)
{
#if defined(X_OK)
    return X_OK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1F_1OK(JNIEnv *env, jclass clazz)
{
#if defined(F_OK)
    return F_OK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EPERM(JNIEnv *env, jclass clazz)
{
#if defined(EPERM)
    return EPERM;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOENT(JNIEnv *env, jclass clazz)
{
#if defined(ENOENT)
    return ENOENT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ESRCH(JNIEnv *env, jclass clazz)
{
#if defined(ESRCH)
    return ESRCH;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EINTR(JNIEnv *env, jclass clazz)
{
#if defined(EINTR)
    return EINTR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EIO(JNIEnv *env, jclass clazz)
{
#if defined(EIO)
    return EIO;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENXIO(JNIEnv *env, jclass clazz)
{
#if defined(ENXIO)
    return ENXIO;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1E2BIG(JNIEnv *env, jclass clazz)
{
#if defined(E2BIG)
    return E2BIG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOEXEC(JNIEnv *env, jclass clazz)
{
#if defined(ENOEXEC)
    return ENOEXEC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EBADF(JNIEnv *env, jclass clazz)
{
#if defined(EBADF)
    return EBADF;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ECHILD(JNIEnv *env, jclass clazz)
{
#if defined(ECHILD)
    return ECHILD;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EAGAIN(JNIEnv *env, jclass clazz)
{
#if defined(EAGAIN)
    return EAGAIN;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOMEM(JNIEnv *env, jclass clazz)
{
#if defined(ENOMEM)
    return ENOMEM;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EACCES(JNIEnv *env, jclass clazz)
{
#if defined(EACCES)
    return EACCES;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EFAULT(JNIEnv *env, jclass clazz)
{
#if defined(EFAULT)
    return EFAULT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOTBLK(JNIEnv *env, jclass clazz)
{
#if defined(ENOTBLK)
    return ENOTBLK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EBUSY(JNIEnv *env, jclass clazz)
{
#if defined(EBUSY)
    return EBUSY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EEXIST(JNIEnv *env, jclass clazz)
{
#if defined(EEXIST)
    return EEXIST;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EXDEV(JNIEnv *env, jclass clazz)
{
#if defined(EXDEV)
    return EXDEV;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENODEV(JNIEnv *env, jclass clazz)
{
#if defined(ENODEV)
    return ENODEV;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOTDIR(JNIEnv *env, jclass clazz)
{
#if defined(ENOTDIR)
    return ENOTDIR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EISDIR(JNIEnv *env, jclass clazz)
{
#if defined(EISDIR)
    return EISDIR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EINVAL(JNIEnv *env, jclass clazz)
{
#if defined(EINVAL)
    return EINVAL;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENFILE(JNIEnv *env, jclass clazz)
{
#if defined(ENFILE)
    return ENFILE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EMFILE(JNIEnv *env, jclass clazz)
{
#if defined(EMFILE)
    return EMFILE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOTTY(JNIEnv *env, jclass clazz)
{
#if defined(ENOTTY)
    return ENOTTY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ETXTBSY(JNIEnv *env, jclass clazz)
{
#if defined(ETXTBSY)
    return ETXTBSY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EFBIG(JNIEnv *env, jclass clazz)
{
#if defined(EFBIG)
    return EFBIG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOSPC(JNIEnv *env, jclass clazz)
{
#if defined(ENOSPC)
    return ENOSPC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ESPIPE(JNIEnv *env, jclass clazz)
{
#if defined(ESPIPE)
    return ESPIPE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EROFS(JNIEnv *env, jclass clazz)
{
#if defined(EROFS)
    return EROFS;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EMLINK(JNIEnv *env, jclass clazz)
{
#if defined(EMLINK)
    return EMLINK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EPIPE(JNIEnv *env, jclass clazz)
{
#if defined(EPIPE)
    return EPIPE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EDOM(JNIEnv *env, jclass clazz)
{
#if defined(EDOM)
    return EDOM;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ERANGE(JNIEnv *env, jclass clazz)
{
#if defined(ERANGE)
    return ERANGE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EDEADLK(JNIEnv *env, jclass clazz)
{
#if defined(EDEADLK)
    return EDEADLK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENAMETOOLONG(JNIEnv *env, jclass clazz)
{
#if defined(ENAMETOOLONG)
    return ENAMETOOLONG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOLCK(JNIEnv *env, jclass clazz)
{
#if defined(ENOLCK)
    return ENOLCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOSYS(JNIEnv *env, jclass clazz)
{
#if defined(ENOSYS)
    return ENOSYS;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOTEMPTY(JNIEnv *env, jclass clazz)
{
#if defined(ENOTEMPTY)
    return ENOTEMPTY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ELOOP(JNIEnv *env, jclass clazz)
{
#if defined(ELOOP)
    return ELOOP;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EWOULDBLOCK(JNIEnv *env, jclass clazz)
{
#if defined(EWOULDBLOCK)
    return EWOULDBLOCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOMSG(JNIEnv *env, jclass clazz)
{
#if defined(ENOMSG)
    return ENOMSG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EIDRM(JNIEnv *env, jclass clazz)
{
#if defined(EIDRM)
    return EIDRM;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ECHRNG(JNIEnv *env, jclass clazz)
{
#if defined(ECHRNG)
    return ECHRNG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EL2NSYNC(JNIEnv *env, jclass clazz)
{
#if defined(EL2NSYNC)
    return EL2NSYNC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EL3HLT(JNIEnv *env, jclass clazz)
{
#if defined(EL3HLT)
    return EL3HLT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EL3RST(JNIEnv *env, jclass clazz)
{
#if defined(EL3RST)
    return EL3RST;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ELNRNG(JNIEnv *env, jclass clazz)
{
#if defined(ELNRNG)
    return ELNRNG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EUNATCH(JNIEnv *env, jclass clazz)
{
#if defined(EUNATCH)
    return EUNATCH;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOCSI(JNIEnv *env, jclass clazz)
{
#if defined(ENOCSI)
    return ENOCSI;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EL2HLT(JNIEnv *env, jclass clazz)
{
#if defined(EL2HLT)
    return EL2HLT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EBADE(JNIEnv *env, jclass clazz)
{
#if defined(EBADE)
    return EBADE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EBADR(JNIEnv *env, jclass clazz)
{
#if defined(EBADR)
    return EBADR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EXFULL(JNIEnv *env, jclass clazz)
{
#if defined(EXFULL)
    return EXFULL;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOANO(JNIEnv *env, jclass clazz)
{
#if defined(ENOANO)
    return ENOANO;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EBADRQC(JNIEnv *env, jclass clazz)
{
#if defined(EBADRQC)
    return EBADRQC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EBADSLT(JNIEnv *env, jclass clazz)
{
#if defined(EBADSLT)
    return EBADSLT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EDEADLOCK(JNIEnv *env, jclass clazz)
{
#if defined(EDEADLOCK)
    return EDEADLOCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EBFONT(JNIEnv *env, jclass clazz)
{
#if defined(EBFONT)
    return EBFONT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOSTR(JNIEnv *env, jclass clazz)
{
#if defined(ENOSTR)
    return ENOSTR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENODATA(JNIEnv *env, jclass clazz)
{
#if defined(ENODATA)
    return ENODATA;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ETIME(JNIEnv *env, jclass clazz)
{
#if defined(ETIME)
    return ETIME;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOSR(JNIEnv *env, jclass clazz)
{
#if defined(ENOSR)
    return ENOSR;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENONET(JNIEnv *env, jclass clazz)
{
#if defined(ENONET)
    return ENONET;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOPKG(JNIEnv *env, jclass clazz)
{
#if defined(ENOPKG)
    return ENOPKG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EREMOTE(JNIEnv *env, jclass clazz)
{
#if defined(EREMOTE)
    return EREMOTE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOLINK(JNIEnv *env, jclass clazz)
{
#if defined(ENOLINK)
    return ENOLINK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EADV(JNIEnv *env, jclass clazz)
{
#if defined(EADV)
    return EADV;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ESRMNT(JNIEnv *env, jclass clazz)
{
#if defined(ESRMNT)
    return ESRMNT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ECOMM(JNIEnv *env, jclass clazz)
{
#if defined(ECOMM)
    return ECOMM;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EPROTO(JNIEnv *env, jclass clazz)
{
#if defined(EPROTO)
    return EPROTO;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EMULTIHOP(JNIEnv *env, jclass clazz)
{
#if defined(EMULTIHOP)
    return EMULTIHOP;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EDOTDOT(JNIEnv *env, jclass clazz)
{
#if defined(EDOTDOT)
    return EDOTDOT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EBADMSG(JNIEnv *env, jclass clazz)
{
#if defined(EBADMSG)
    return EBADMSG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EOVERFLOW(JNIEnv *env, jclass clazz)
{
#if defined(EOVERFLOW)
    return EOVERFLOW;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOTUNIQ(JNIEnv *env, jclass clazz)
{
#if defined(ENOTUNIQ)
    return ENOTUNIQ;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EBADFD(JNIEnv *env, jclass clazz)
{
#if defined(EBADFD)
    return EBADFD;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EREMCHG(JNIEnv *env, jclass clazz)
{
#if defined(EREMCHG)
    return EREMCHG;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ELIBACC(JNIEnv *env, jclass clazz)
{
#if defined(ELIBACC)
    return ELIBACC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ELIBBAD(JNIEnv *env, jclass clazz)
{
#if defined(ELIBBAD)
    return ELIBBAD;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ELIBSCN(JNIEnv *env, jclass clazz)
{
#if defined(ELIBSCN)
    return ELIBSCN;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ELIBMAX(JNIEnv *env, jclass clazz)
{
#if defined(ELIBMAX)
    return ELIBMAX;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ELIBEXEC(JNIEnv *env, jclass clazz)
{
#if defined(ELIBEXEC)
    return ELIBEXEC;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EILSEQ(JNIEnv *env, jclass clazz)
{
#if defined(EILSEQ)
    return EILSEQ;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ERESTART(JNIEnv *env, jclass clazz)
{
#if defined(ERESTART)
    return ERESTART;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ESTRPIPE(JNIEnv *env, jclass clazz)
{
#if defined(ESTRPIPE)
    return ESTRPIPE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EUSERS(JNIEnv *env, jclass clazz)
{
#if defined(EUSERS)
    return EUSERS;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOTSOCK(JNIEnv *env, jclass clazz)
{
#if defined(ENOTSOCK)
    return ENOTSOCK;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EDESTADDRREQ(JNIEnv *env, jclass clazz)
{
#if defined(EDESTADDRREQ)
    return EDESTADDRREQ;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EMSGSIZE(JNIEnv *env, jclass clazz)
{
#if defined(EMSGSIZE)
    return EMSGSIZE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EPROTOTYPE(JNIEnv *env, jclass clazz)
{
#if defined(EPROTOTYPE)
    return EPROTOTYPE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOPROTOOPT(JNIEnv *env, jclass clazz)
{
#if defined(ENOPROTOOPT)
    return ENOPROTOOPT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EPROTONOSUPPORT(JNIEnv *env, jclass clazz)
{
#if defined(EPROTONOSUPPORT)
    return EPROTONOSUPPORT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ESOCKTNOSUPPORT(JNIEnv *env, jclass clazz)
{
#if defined(ESOCKTNOSUPPORT)
    return ESOCKTNOSUPPORT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EOPNOTSUPP(JNIEnv *env, jclass clazz)
{
#if defined(EOPNOTSUPP)
    return EOPNOTSUPP;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EPFNOSUPPORT(JNIEnv *env, jclass clazz)
{
#if defined(EPFNOSUPPORT)
    return EPFNOSUPPORT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EAFNOSUPPORT(JNIEnv *env, jclass clazz)
{
#if defined(EAFNOSUPPORT)
    return EAFNOSUPPORT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EADDRINUSE(JNIEnv *env, jclass clazz)
{
#if defined(EADDRINUSE)
    return EADDRINUSE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EADDRNOTAVAIL(JNIEnv *env, jclass clazz)
{
#if defined(EADDRNOTAVAIL)
    return EADDRNOTAVAIL;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENETDOWN(JNIEnv *env, jclass clazz)
{
#if defined(ENETDOWN)
    return ENETDOWN;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENETUNREACH(JNIEnv *env, jclass clazz)
{
#if defined(ENETUNREACH)
    return ENETUNREACH;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENETRESET(JNIEnv *env, jclass clazz)
{
#if defined(ENETRESET)
    return ENETRESET;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ECONNABORTED(JNIEnv *env, jclass clazz)
{
#if defined(ECONNABORTED)
    return ECONNABORTED;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ECONNRESET(JNIEnv *env, jclass clazz)
{
#if defined(ECONNRESET)
    return ECONNRESET;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOBUFS(JNIEnv *env, jclass clazz)
{
#if defined(ENOBUFS)
    return ENOBUFS;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EISCONN(JNIEnv *env, jclass clazz)
{
#if defined(EISCONN)
    return EISCONN;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOTCONN(JNIEnv *env, jclass clazz)
{
#if defined(ENOTCONN)
    return ENOTCONN;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ESHUTDOWN(JNIEnv *env, jclass clazz)
{
#if defined(ESHUTDOWN)
    return ESHUTDOWN;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ETOOMANYREFS(JNIEnv *env, jclass clazz)
{
#if defined(ETOOMANYREFS)
    return ETOOMANYREFS;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ETIMEDOUT(JNIEnv *env, jclass clazz)
{
#if defined(ETIMEDOUT)
    return ETIMEDOUT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ECONNREFUSED(JNIEnv *env, jclass clazz)
{
#if defined(ECONNREFUSED)
    return ECONNREFUSED;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EHOSTDOWN(JNIEnv *env, jclass clazz)
{
#if defined(EHOSTDOWN)
    return EHOSTDOWN;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EHOSTUNREACH(JNIEnv *env, jclass clazz)
{
#if defined(EHOSTUNREACH)
    return EHOSTUNREACH;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EALREADY(JNIEnv *env, jclass clazz)
{
#if defined(EALREADY)
    return EALREADY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EINPROGRESS(JNIEnv *env, jclass clazz)
{
#if defined(EINPROGRESS)
    return EINPROGRESS;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ESTALE(JNIEnv *env, jclass clazz)
{
#if defined(ESTALE)
    return ESTALE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EUCLEAN(JNIEnv *env, jclass clazz)
{
#if defined(EUCLEAN)
    return EUCLEAN;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOTNAM(JNIEnv *env, jclass clazz)
{
#if defined(ENOTNAM)
    return ENOTNAM;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENAVAIL(JNIEnv *env, jclass clazz)
{
#if defined(ENAVAIL)
    return ENAVAIL;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EISNAM(JNIEnv *env, jclass clazz)
{
#if defined(EISNAM)
    return EISNAM;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EREMOTEIO(JNIEnv *env, jclass clazz)
{
#if defined(EREMOTEIO)
    return EREMOTEIO;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EDQUOT(JNIEnv *env, jclass clazz)
{
#if defined(EDQUOT)
    return EDQUOT;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOMEDIUM(JNIEnv *env, jclass clazz)
{
#if defined(ENOMEDIUM)
    return ENOMEDIUM;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EMEDIUMTYPE(JNIEnv *env, jclass clazz)
{
#if defined(EMEDIUMTYPE)
    return EMEDIUMTYPE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ECANCELED(JNIEnv *env, jclass clazz)
{
#if defined(ECANCELED)
    return ECANCELED;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOKEY(JNIEnv *env, jclass clazz)
{
#if defined(ENOKEY)
    return ENOKEY;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EKEYEXPIRED(JNIEnv *env, jclass clazz)
{
#if defined(EKEYEXPIRED)
    return EKEYEXPIRED;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EKEYREVOKED(JNIEnv *env, jclass clazz)
{
#if defined(EKEYREVOKED)
    return EKEYREVOKED;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EKEYREJECTED(JNIEnv *env, jclass clazz)
{
#if defined(EKEYREJECTED)
    return EKEYREJECTED;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1EOWNERDEAD(JNIEnv *env, jclass clazz)
{
#if defined(EOWNERDEAD)
    return EOWNERDEAD;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ENOTRECOVERABLE(JNIEnv *env, jclass clazz)
{
#if defined(ENOTRECOVERABLE)
    return ENOTRECOVERABLE;
#else
    return 0;
#endif
}


JNIEXPORT jint JNICALL Java_jposix_Posix__1get_1ATEXIT_1MAX(JNIEnv *env, jclass clazz)
{
#if defined(ATEXIT_MAX)
    return ATEXIT_MAX;
#else
    return 0;
#endif
}

