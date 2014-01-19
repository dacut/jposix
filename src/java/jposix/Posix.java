/** @file   Posix.java
 *  @brief  Posix base for jposix.
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

package jposix;

import java.nio.charset.Charset;
import jposix.struct.Stat;
import static java.lang.System.loadLibrary;

public abstract class Posix {
    /** fcntl command: duplicate file descriptor. 
     *
     *  Finds the lowest numbered file descriptor available greater than or
     *  equal to the specified descriptor and makes it be a copy of the
     *  specified descriptor.
     *
     *  The new descriptor's close-on-exec flag is set to off.
     *
     *  @see #fcntl
     */
    public static final int F_DUPFD;

    /** fcntl command: duplicate file descriptor and close on exec.
     *  Linux 2.6 only.
     *
     *  @see #fcntl
     */
    public static final int F_DUPFD_CLOEXEC;

    /** fcntl command: get file descriptor flags.
     *
     *  Returns the flags for the file descriptor.
     *  <ul><li>{@code FD_CLOEXEC}: the file descriptor will be closed upon
     *  an {@code exec()} call.</li></ul>
     *
     *  @see #fcntl
     */
    public static final int F_GETFD;

    /** fcntl command: set file descriptor flags.
     *
     *  Sets the flags for the file descriptor.
     *  <ul><li>{@code FD_CLOEXEC}: the file descriptor will be closed upon
     *  an {@code exec()} call.</li></ul>
     *
     *  @see #fcntl
     */
    public static final int F_SETFD;

    /** fcntl command: get file status flags.
     *
     *  Retrieves the flags passed into the {@code open()} command and modified
     *  by subsequent {@code fcntl()} commands on this file descriptor.
     *
     *  @see #fcntl
     *  @see #open
     */
    public static final int F_GETFL;

    /** fcntl command: set file status flags.
     *
     *  Sets the status flags for the specified file descriptor.  Not all flags
     *  may be modified; see the documentation specific to the operating
     *  system.
     *
     *  @see #fcntl
     *  @see #open
     */
    public static final int F_SETFL;
    public static final int F_GETLK;
    public static final int F_SETLK;
    public static final int F_SETLKW;
    public static final int F_GETOWN;
    public static final int F_SETOWN;
    public static final int F_GETSIG;
    public static final int F_SETSIG;
    public static final int F_GETLEASE;
    public static final int F_SETLEASE;
    public static final int F_NOTIFY;

    /** fcntl: F_GETLK/F_SETLK flags: Read lock. */
    public static final int F_RDLCK;

    /** fcntl: F_GETLK/F_SETLK flags: Write lock. */
    public static final int F_WRLCK;

    /** fcntl: F_GETLK/F_SETLK flags: Unlock. */
    public static final int F_UNLCK;

    public static final int F_UNLOCK;
    public static final int F_LOCK;
    public static final int F_TLOCK;
    public static final int F_TEST;

    public static final int O_RDONLY;
    public static final int O_WRONLY;
    public static final int O_RDWR;
    public static final int O_CREAT;
    public static final int O_EXCL;
    public static final int O_NOCTTY;
    public static final int O_TRUNC;
    public static final int O_APPEND;
    public static final int O_NONBLOCK;
    public static final int O_NDELAY;
    public static final int O_SYNC;
    public static final int O_FSYNC;
    public static final int O_ASYNC;
    public static final int O_DIRECT;
    public static final int O_DIRECTORY;
    public static final int O_NOFOLLOW;
    public static final int O_DSYNC;
    public static final int O_RSYNC;
    public static final int O_LARGEFILE;

    public static final int POSIX_FADV_NORMAL;
    public static final int POSIX_FADV_SEQUENTIAL;
    public static final int POSIX_FADV_RANDOM;
    public static final int POSIX_FADV_NOREUSE;
    public static final int POSIX_FADV_WILLNEED;
    public static final int POSIX_FADV_DONTNEED;

    public static final int S_IFMT;
    public static final int S_IFDIR;
    public static final int S_IFCHR;
    public static final int S_IFREG;
    public static final int S_IFIFO;
    public static final int S_IFLNK;
    public static final int S_IFSOCK;
    public static final int S_ISUID;
    public static final int S_ISGID;
    public static final int S_IREAD;
    public static final int S_IWRITE;
    public static final int S_IEXEC;
    public static final int S_IRUSR;
    public static final int S_IWUSR;
    public static final int S_IXUSR;
    public static final int S_IRWXU;
    public static final int S_IRGRP;
    public static final int S_IWGRP;
    public static final int S_IXGRP;
    public static final int S_IRWXG;
    public static final int S_IROTH;
    public static final int S_IWOTH;
    public static final int S_IXOTH;
    public static final int S_IRWXO;

    public static final int STDIN_FILENO = 0;
    public static final int STDOUT_FILENO = 1;
    public static final int STDERR_FILENO = 2;

    public static final int R_OK;
    public static final int W_OK;
    public static final int X_OK;
    public static final int F_OK;

    public static final int SEEK_SET = 0;
    public static final int SEEK_CUR = 1;
    public static final int SEEK_END = 2;

    /* errno constants */
    public static final int EPERM;
    public static final int ENOENT;
    public static final int ESRCH;
    public static final int EINTR;
    public static final int EIO;
    public static final int ENXIO;
    public static final int E2BIG;
    public static final int ENOEXEC;
    public static final int EBADF;
    public static final int ECHILD;
    public static final int EAGAIN;
    public static final int ENOMEM;
    public static final int EACCES;
    public static final int EFAULT;
    public static final int ENOTBLK;
    public static final int EBUSY;
    public static final int EEXIST;
    public static final int EXDEV;
    public static final int ENODEV;
    public static final int ENOTDIR;
    public static final int EISDIR;
    public static final int EINVAL;
    public static final int ENFILE;
    public static final int EMFILE;
    public static final int ENOTTY;
    public static final int ETXTBSY;
    public static final int EFBIG;
    public static final int ENOSPC;
    public static final int ESPIPE;
    public static final int EROFS;
    public static final int EMLINK;
    public static final int EPIPE;
    public static final int EDOM;
    public static final int ERANGE;
    public static final int EDEADLK;
    public static final int ENAMETOOLONG;
    public static final int ENOLCK;
    public static final int ENOSYS;
    public static final int ENOTEMPTY;
    public static final int ELOOP;
    public static final int EWOULDBLOCK;
    public static final int ENOMSG;
    public static final int EIDRM;
    public static final int ECHRNG;
    public static final int EL2NSYNC;
    public static final int EL3HLT;
    public static final int EL3RST;
    public static final int ELNRNG;
    public static final int EUNATCH;
    public static final int ENOCSI;
    public static final int EL2HLT;
    public static final int EBADE;
    public static final int EBADR;
    public static final int EXFULL;
    public static final int ENOANO;
    public static final int EBADRQC;
    public static final int EBADSLT;
    public static final int EDEADLOCK;
    public static final int EBFONT;
    public static final int ENOSTR;
    public static final int ENODATA;
    public static final int ETIME;
    public static final int ENOSR;
    public static final int ENONET;
    public static final int ENOPKG;
    public static final int EREMOTE;
    public static final int ENOLINK;
    public static final int EADV;
    public static final int ESRMNT;
    public static final int ECOMM;
    public static final int EPROTO;
    public static final int EMULTIHOP;
    public static final int EDOTDOT;
    public static final int EBADMSG;
    public static final int EOVERFLOW;
    public static final int ENOTUNIQ;
    public static final int EBADFD;
    public static final int EREMCHG;
    public static final int ELIBACC;
    public static final int ELIBBAD;
    public static final int ELIBSCN;
    public static final int ELIBMAX;
    public static final int ELIBEXEC;
    public static final int EILSEQ;
    public static final int ERESTART;
    public static final int ESTRPIPE;
    public static final int EUSERS;
    public static final int ENOTSOCK;
    public static final int EDESTADDRREQ;
    public static final int EMSGSIZE;
    public static final int EPROTOTYPE;
    public static final int ENOPROTOOPT;
    public static final int EPROTONOSUPPORT;
    public static final int ESOCKTNOSUPPORT;
    public static final int EOPNOTSUPP;
    public static final int EPFNOSUPPORT;
    public static final int EAFNOSUPPORT;
    public static final int EADDRINUSE;
    public static final int EADDRNOTAVAIL;
    public static final int ENETDOWN;
    public static final int ENETUNREACH;
    public static final int ENETRESET;
    public static final int ECONNABORTED;
    public static final int ECONNRESET;
    public static final int ENOBUFS;
    public static final int EISCONN;
    public static final int ENOTCONN;
    public static final int ESHUTDOWN;
    public static final int ETOOMANYREFS;
    public static final int ETIMEDOUT;
    public static final int ECONNREFUSED;
    public static final int EHOSTDOWN;
    public static final int EHOSTUNREACH;
    public static final int EALREADY;
    public static final int EINPROGRESS;
    public static final int ESTALE;
    public static final int EUCLEAN;
    public static final int ENOTNAM;
    public static final int ENAVAIL;
    public static final int EISNAM;
    public static final int EREMOTEIO;
    public static final int EDQUOT;
    public static final int ENOMEDIUM;
    public static final int EMEDIUMTYPE;
    public static final int ECANCELED;
    public static final int ENOKEY;
    public static final int EKEYEXPIRED;
    public static final int EKEYREVOKED;
    public static final int EKEYREJECTED;
    public static final int EOWNERDEAD;
    public static final int ENOTRECOVERABLE;

    public static final int ATEXIT_MAX;

    public static native boolean S_ISTYPE(int mode, int mask);
    public static native boolean S_ISDIR(int mode);
    public static native boolean S_ISBLK(int mode);
    public static native boolean S_ISREG(int mode);
    public static native boolean S_ISFIFO(int mode);
    public static native boolean S_ISLNK(int mode);
    public static native boolean S_ISSOCK(int mode);

    public static native void abort();

    public static void access(String path, int type)
        throws OSException
    {
        access(path.getBytes(), type);
    }

    public static native void access(byte[] path, int type)
        throws OSException;

    public static void acct(String filename)
        throws OSException
    {
        acct(filename.getBytes());
    }

    public static native void acct(byte[] filename)
        throws OSException;

    public static native int alarm(int seconds)
        throws OSException;

    public static native void brk(long address)
        throws OSException;

    public static void chdir(String path)
        throws OSException
    {
        chdir(path.getBytes());
    }

    public static native void chdir(byte[] path)
        throws OSException;

    public static void chown(String path, int owner, int group)
        throws OSException
    {
        chown(path.getBytes(), owner, group);
    }
    
    public static native void chown(byte[] path, int owner, int group)
        throws OSException;

    public static void chroot(String path)
        throws OSException
    {
        chroot(path.getBytes());
    }

    public static native void chroot(byte[] path)
        throws OSException;

    public static native void close(int fd)
        throws OSException;

    public static native byte[] confstr(int name)
        throws OSException, UnsupportedOperationException;

    public static int creat(String file, int mode)
        throws OSException
    {
        return creat(file.getBytes(), mode);
    }

    public static native int creat(byte[] file, int mode)
        throws OSException;

    public static String crypt(String key, String salt)
        throws OSException
    {
        return new String(crypt(key.getBytes(), salt.getBytes()));
    }

    public static native byte[] crypt(byte[] key, byte[] salt)
        throws OSException;

    public static native byte[] ctermid();

    public static native void daemon(boolean nochdir, boolean noclose)
        throws OSException;

    public static native int dup(int fd)
        throws OSException;

    public static native int dup2(int oldfd, int newfd2)
        throws OSException;

    public static native void encrypt(byte[] block, boolean decrypt)
        throws OSException;

    public static native void endusershell();

    public static String[] environStr()
    {
        byte[][] env = environ();
        String[] result = new String[env.length];

        for (int i = 0; i < env.length; ++i) {
            result[i] = new String(env[i]);
        }

        return result;
    }

    public static native byte[][] environ();

    public static native void euidaccess(byte[] path, int type)
        throws OSException, UnsupportedOperationException;

    public static native void execv(byte[] path, byte[][] argv)
        throws OSException;

    public static native void execve(byte[] path, byte[][] argv, byte[][] envp)
        throws OSException;

    public static native void execvp(byte[] file, byte[][] argv)
        throws OSException;

    public static native void _exit(int status);

    public static native void fchdir(int fd)
        throws OSException, UnsupportedOperationException;

    public static native void fchown(int fd, int owner, int group)
        throws OSException, UnsupportedOperationException;

    public static int fcntl(int fd, int cmd)
        throws OSException
    {
        if (cmd == F_DUPFD ||
            (cmd == F_DUPFD_CLOEXEC && F_DUPFD_CLOEXEC != 0) ||
            cmd == F_GETFD ||
            cmd == F_GETFL ||
            cmd == F_GETOWN ||
            cmd == F_GETSIG ||
            cmd == F_GETLEASE)
            return _fcntl1(fd, cmd);
        else
            throw new IllegalArgumentException(
                "fcntl for command " + cmd + " requires an argument.");
    }

    public static int fcntl(int fd, int cmd, int arg)
        throws OSException
    {
        if (cmd == F_SETFD || 
            cmd == F_SETFL ||
            cmd == F_SETOWN ||
            cmd == F_SETSIG || 
            cmd == F_SETLEASE ||
            cmd == F_NOTIFY)
            return _fcntl2(fd, cmd, arg);
        else
            throw new IllegalArgumentException(
                "fcntl for command " + cmd + " does not take an integer " +
                "argument.");
    }

    private static native int _fcntl1(int fd, int cmd)
        throws OSException;

    private static native int _fcntl2(int fd, int cmd, int arg)
        throws OSException;

    public static native void fdatasync(int fd)
        throws OSException;

    public static native void fexecve(int fd, byte[][] argv, byte[][] envp)
        throws OSException, UnsupportedOperationException;

    public static native int fork()
        throws OSException;

    public static native long fpathconf(int fd, int name)
        throws OSException;
    
    public static native Stat fstat(int fd)
        throws OSException;

    public static native void fsync(int fd)
        throws OSException;

    public static native void ftruncate(int fd, long length)
        throws OSException;

    public static String getcwdStr()
        throws OSException
    {
        return new String(getcwd());
    }

    public static native byte[] getcwd()
        throws OSException;

    public static String getdomainnameStr()
        throws OSException
    {
        return new String(getdomainname());
    }

    public static native byte[] getdomainname()
        throws OSException;

    public static native int getdtablesize()
        throws OSException;

    public static native int getegid();

    public static String getenv(String name)
    {
        byte[] result = getenv(name.getBytes());
        if (result == null)
            return null;

        return new String(result);
    }

    public static native byte[] getenv(byte[] name);

    public static native int geteuid();

    public static native int getgid();

    public static native int[] getgroups();

    public static native int gethostid();

    public static String gethostnameStr()
        throws OSException
    {
        return new String(gethostname());
    }

    public static native byte[] gethostname()
        throws OSException;

    public static String getloginStr()
        throws OSException
    {
        return new String(getlogin());
    }

    public static native byte[] getlogin()
        throws OSException;

    public static native int getpagesize();

    public static String getpass(String prompt)
        throws OSException
    {
        return new String(getpass(prompt.getBytes()));
    }

    public static native byte[] getpass(byte[] prompt)
        throws OSException;

    public static native int getpgid(int pid)
        throws OSException, UnsupportedOperationException;

    public static native int getpid();

    public static native int getppid();

    public static native int[] getresgid()
        throws OSException, UnsupportedOperationException;

    public static native int[] getresuid()
        throws OSException, UnsupportedOperationException;

    public static native int getsid(int pid)
        throws OSException, UnsupportedOperationException;

    public static native int getuid();

    public static String getusershellStr()
    {
        byte[] result = getusershell();

        if (result == null)
            return null;

        return new String(result);
    }

    public static native byte[] getusershell();

    public static native boolean isatty(int fd);

    public static void lchown(String path, int owner, int group)
        throws OSException, UnsupportedOperationException
    {
        lchown(path.getBytes(), owner, group);
    }

    public static native void lchown(byte[] path, int owner, int group)
        throws OSException, UnsupportedOperationException;

    public static void link(String from, String to)
        throws OSException
    {
        link(from.getBytes(), to.getBytes());
    }

    public static native void link(byte[] from, byte[] to)
        throws OSException;

    public static native void lockf(int fd, int cmd, long length)
        throws OSException;

    public static native long lseek(int fd, long offset, int whence)
        throws OSException;

    public static Stat lstat(String path)
        throws OSException
    {
        return lstat(path.getBytes());
    }

    public static native Stat lstat(byte[] path)
        throws OSException;

    public static native int nice(int increment)
        throws OSException, UnsupportedOperationException;

    public static int open(String file, int oflag)
        throws OSException
    {
        if ((oflag & O_CREAT) != 0)
            throw new IllegalArgumentException(
                "Mode must be specified when oflag includes O_CREAT.");

        return open(file.getBytes(), oflag, 0);
    }

    public static int open(String file, int oflag, int mode)
        throws OSException
    {
        return open(file.getBytes(), oflag, mode);
    }

    public static int open(byte[] file, int oflag)
        throws OSException
    {
        if ((oflag & O_CREAT) != 0)
            throw new IllegalArgumentException(
                "Mode must be specified when oflag includes O_CREAT.");

        return open(file, oflag, 0);
    }

    public static native int open(byte[] file, int oflag, int mode)
        throws OSException;

    public static native void pause()
        throws OSException;

    public static long pathconf(String path, int name)
        throws OSException
    {
        return pathconf(path.getBytes(), name);
    }

    public static native long pathconf(byte[] path, int name)
        throws OSException;

    public static native void pipe(int[] pipedes)
        throws OSException;

    public static native void posix_fadvise(int fd, long offset, long len,
                                            int advise)
        throws OSException;

    public static native void posix_fallocate(int fd, long offset, long len)
        throws OSException;

    public static int pread(int fd, byte[] buf, long offset)
        throws OSException, UnsupportedOperationException
    {
        return pread(fd, buf, 0, buf.length, offset);
    }

    public static native int pread(int fd, byte[] buf, int start, int len,
                                   long offset)
        throws OSException, UnsupportedOperationException;

    /* public static native void profil(short[] buf, long offset, int scale)
       throws OSException;
    */

    public static int pwrite(int fd, byte[] buf, long offset)
        throws OSException, UnsupportedOperationException
    {
        return pwrite(fd, buf, 0, buf.length, offset);
    }

    public static native int pwrite(int fd, byte[] buf, int start, int len,
                             long offset)
        throws OSException, UnsupportedOperationException;

    public static int read(int fd, byte[] buf)
        throws OSException
    {
        return read(fd, buf, 0, buf.length);
    }

    public static native int read(int fd, byte[] buf, int start, int len)
        throws OSException;

    public static String readlink(String path)
        throws OSException
    {
        return new String(readlink(path.getBytes()));
    }

    public static native byte[] readlink(byte[] path)
        throws OSException;

    public static void rmdir(String path)
        throws OSException
    {
        rmdir(path.getBytes());
    }

    public static native void rmdir(byte[] path)
        throws OSException;

    public static native long sbrk(long increment)
        throws OSException;

    public static void setdomainname(String name)
        throws OSException
    {
        setdomainname(name.getBytes());
    }

    public static native void setdomainname(byte[] name)
        throws OSException;

    public static native void setegid(int gid)
        throws OSException, UnsupportedOperationException;

    public static native void seteuid(int uid)
        throws OSException, UnsupportedOperationException;

    public static native void setgid(int gid)
        throws OSException;

    public static native void setgroups(int[] list)
        throws OSException;

    public static native void sethostid(int id)
        throws OSException;

    public static native void sethostname(byte[] hostname)
        throws OSException;

    public static native void setlogin(byte[] name)
        throws OSException;

    public static native void setpgid(int pid, int pgid)
        throws OSException;

    public static native void setregid(int rgid, int egid)
        throws OSException, UnsupportedOperationException;

    public static native void setresgid(int rgid, int egid, int sgid)
        throws OSException, UnsupportedOperationException;

    public static native void setresuid(int ruid, int euid, int suid)
        throws OSException, UnsupportedOperationException;

    public static native void setreuid(int ruid, int euid)
        throws OSException, UnsupportedOperationException;

    public static native int setsid()
        throws OSException;

    public static native void setuid(int uid)
        throws OSException;

    public static native void setusershell();

    public static native void sleep(int seconds)
        throws OSException;

    public static native Stat stat(byte[] path)
        throws OSException;

    public static native String strerror(int errno);

    public static native void symlink(byte[] from, byte[] to)
        throws OSException;

    public static native void sync();

    public static native long sysconf(int name)
        throws OSException;

    public static native int tcgetpgrp(int fd)
        throws OSException;

    public static native void tcsetpgrp(int fd, int pgrpid)
        throws OSException;

    public static native void truncate(byte[] file, long length)
        throws OSException;

    public static native byte[] ttyname(int fd)
        throws OSException;

    public static native int ttyslot()
        throws OSException, UnsupportedOperationException;

    public static native void ualarm(int value, int interval)
        throws OSException, UnsupportedOperationException;

    public static native void unlink(byte[] path)
        throws OSException;

    public static native void usleep(int useconds)
        throws OSException, UnsupportedOperationException;

    public static native int vfork()
        throws OSException, UnsupportedOperationException;

    public static int write(int fd, byte[] buf)
        throws OSException
    {
        return write(fd, buf, 0, buf.length);
    }

    public static native int write(int fd, byte[] buf, int start, int len)
        throws OSException;

    // !! start generated
    private static native int _get_F_DUPFD();
    private static native int _get_F_DUPFD_CLOEXEC();
    private static native int _get_F_GETFD();
    private static native int _get_F_SETFD();
    private static native int _get_F_GETFL();
    private static native int _get_F_SETFL();
    private static native int _get_F_GETLK();
    private static native int _get_F_SETLK();
    private static native int _get_F_SETLKW();
    private static native int _get_F_GETOWN();
    private static native int _get_F_SETOWN();
    private static native int _get_F_GETSIG();
    private static native int _get_F_SETSIG();
    private static native int _get_F_GETLEASE();
    private static native int _get_F_SETLEASE();
    private static native int _get_F_NOTIFY();
    private static native int _get_F_RDLCK();
    private static native int _get_F_WRLCK();
    private static native int _get_F_UNLCK();
    private static native int _get_F_UNLOCK();
    private static native int _get_F_LOCK();
    private static native int _get_F_TLOCK();
    private static native int _get_F_TEST();
    private static native int _get_O_RDONLY();
    private static native int _get_O_WRONLY();
    private static native int _get_O_RDWR();
    private static native int _get_O_CREAT();
    private static native int _get_O_EXCL();
    private static native int _get_O_NOCTTY();
    private static native int _get_O_TRUNC();
    private static native int _get_O_APPEND();
    private static native int _get_O_NONBLOCK();
    private static native int _get_O_NDELAY();
    private static native int _get_O_SYNC();
    private static native int _get_O_FSYNC();
    private static native int _get_O_ASYNC();
    private static native int _get_O_DIRECT();
    private static native int _get_O_DIRECTORY();
    private static native int _get_O_NOFOLLOW();
    private static native int _get_O_DSYNC();
    private static native int _get_O_RSYNC();
    private static native int _get_O_LARGEFILE();
    private static native int _get_POSIX_FADV_NORMAL();
    private static native int _get_POSIX_FADV_SEQUENTIAL();
    private static native int _get_POSIX_FADV_RANDOM();
    private static native int _get_POSIX_FADV_NOREUSE();
    private static native int _get_POSIX_FADV_WILLNEED();
    private static native int _get_POSIX_FADV_DONTNEED();
    private static native int _get_S_IFMT();
    private static native int _get_S_IFDIR();
    private static native int _get_S_IFCHR();
    private static native int _get_S_IFREG();
    private static native int _get_S_IFIFO();
    private static native int _get_S_IFLNK();
    private static native int _get_S_IFSOCK();
    private static native int _get_S_ISUID();
    private static native int _get_S_ISGID();
    private static native int _get_S_IREAD();
    private static native int _get_S_IWRITE();
    private static native int _get_S_IEXEC();
    private static native int _get_S_IRUSR();
    private static native int _get_S_IWUSR();
    private static native int _get_S_IXUSR();
    private static native int _get_S_IRWXU();
    private static native int _get_S_IRGRP();
    private static native int _get_S_IWGRP();
    private static native int _get_S_IXGRP();
    private static native int _get_S_IRWXG();
    private static native int _get_S_IROTH();
    private static native int _get_S_IWOTH();
    private static native int _get_S_IXOTH();
    private static native int _get_S_IRWXO();
    private static native int _get_R_OK();
    private static native int _get_W_OK();
    private static native int _get_X_OK();
    private static native int _get_F_OK();
    private static native int _get_EPERM();
    private static native int _get_ENOENT();
    private static native int _get_ESRCH();
    private static native int _get_EINTR();
    private static native int _get_EIO();
    private static native int _get_ENXIO();
    private static native int _get_E2BIG();
    private static native int _get_ENOEXEC();
    private static native int _get_EBADF();
    private static native int _get_ECHILD();
    private static native int _get_EAGAIN();
    private static native int _get_ENOMEM();
    private static native int _get_EACCES();
    private static native int _get_EFAULT();
    private static native int _get_ENOTBLK();
    private static native int _get_EBUSY();
    private static native int _get_EEXIST();
    private static native int _get_EXDEV();
    private static native int _get_ENODEV();
    private static native int _get_ENOTDIR();
    private static native int _get_EISDIR();
    private static native int _get_EINVAL();
    private static native int _get_ENFILE();
    private static native int _get_EMFILE();
    private static native int _get_ENOTTY();
    private static native int _get_ETXTBSY();
    private static native int _get_EFBIG();
    private static native int _get_ENOSPC();
    private static native int _get_ESPIPE();
    private static native int _get_EROFS();
    private static native int _get_EMLINK();
    private static native int _get_EPIPE();
    private static native int _get_EDOM();
    private static native int _get_ERANGE();
    private static native int _get_EDEADLK();
    private static native int _get_ENAMETOOLONG();
    private static native int _get_ENOLCK();
    private static native int _get_ENOSYS();
    private static native int _get_ENOTEMPTY();
    private static native int _get_ELOOP();
    private static native int _get_EWOULDBLOCK();
    private static native int _get_ENOMSG();
    private static native int _get_EIDRM();
    private static native int _get_ECHRNG();
    private static native int _get_EL2NSYNC();
    private static native int _get_EL3HLT();
    private static native int _get_EL3RST();
    private static native int _get_ELNRNG();
    private static native int _get_EUNATCH();
    private static native int _get_ENOCSI();
    private static native int _get_EL2HLT();
    private static native int _get_EBADE();
    private static native int _get_EBADR();
    private static native int _get_EXFULL();
    private static native int _get_ENOANO();
    private static native int _get_EBADRQC();
    private static native int _get_EBADSLT();
    private static native int _get_EDEADLOCK();
    private static native int _get_EBFONT();
    private static native int _get_ENOSTR();
    private static native int _get_ENODATA();
    private static native int _get_ETIME();
    private static native int _get_ENOSR();
    private static native int _get_ENONET();
    private static native int _get_ENOPKG();
    private static native int _get_EREMOTE();
    private static native int _get_ENOLINK();
    private static native int _get_EADV();
    private static native int _get_ESRMNT();
    private static native int _get_ECOMM();
    private static native int _get_EPROTO();
    private static native int _get_EMULTIHOP();
    private static native int _get_EDOTDOT();
    private static native int _get_EBADMSG();
    private static native int _get_EOVERFLOW();
    private static native int _get_ENOTUNIQ();
    private static native int _get_EBADFD();
    private static native int _get_EREMCHG();
    private static native int _get_ELIBACC();
    private static native int _get_ELIBBAD();
    private static native int _get_ELIBSCN();
    private static native int _get_ELIBMAX();
    private static native int _get_ELIBEXEC();
    private static native int _get_EILSEQ();
    private static native int _get_ERESTART();
    private static native int _get_ESTRPIPE();
    private static native int _get_EUSERS();
    private static native int _get_ENOTSOCK();
    private static native int _get_EDESTADDRREQ();
    private static native int _get_EMSGSIZE();
    private static native int _get_EPROTOTYPE();
    private static native int _get_ENOPROTOOPT();
    private static native int _get_EPROTONOSUPPORT();
    private static native int _get_ESOCKTNOSUPPORT();
    private static native int _get_EOPNOTSUPP();
    private static native int _get_EPFNOSUPPORT();
    private static native int _get_EAFNOSUPPORT();
    private static native int _get_EADDRINUSE();
    private static native int _get_EADDRNOTAVAIL();
    private static native int _get_ENETDOWN();
    private static native int _get_ENETUNREACH();
    private static native int _get_ENETRESET();
    private static native int _get_ECONNABORTED();
    private static native int _get_ECONNRESET();
    private static native int _get_ENOBUFS();
    private static native int _get_EISCONN();
    private static native int _get_ENOTCONN();
    private static native int _get_ESHUTDOWN();
    private static native int _get_ETOOMANYREFS();
    private static native int _get_ETIMEDOUT();
    private static native int _get_ECONNREFUSED();
    private static native int _get_EHOSTDOWN();
    private static native int _get_EHOSTUNREACH();
    private static native int _get_EALREADY();
    private static native int _get_EINPROGRESS();
    private static native int _get_ESTALE();
    private static native int _get_EUCLEAN();
    private static native int _get_ENOTNAM();
    private static native int _get_ENAVAIL();
    private static native int _get_EISNAM();
    private static native int _get_EREMOTEIO();
    private static native int _get_EDQUOT();
    private static native int _get_ENOMEDIUM();
    private static native int _get_EMEDIUMTYPE();
    private static native int _get_ECANCELED();
    private static native int _get_ENOKEY();
    private static native int _get_EKEYEXPIRED();
    private static native int _get_EKEYREVOKED();
    private static native int _get_EKEYREJECTED();
    private static native int _get_EOWNERDEAD();
    private static native int _get_ENOTRECOVERABLE();
    private static native int _get_ATEXIT_MAX();

    static {
        loadLibrary("jposix-0.1");
        F_DUPFD = _get_F_DUPFD();
        F_DUPFD_CLOEXEC = _get_F_DUPFD_CLOEXEC();
        F_GETFD = _get_F_GETFD();
        F_SETFD = _get_F_SETFD();
        F_GETFL = _get_F_GETFL();
        F_SETFL = _get_F_SETFL();
        F_GETLK = _get_F_GETLK();
        F_SETLK = _get_F_SETLK();
        F_SETLKW = _get_F_SETLKW();
        F_GETOWN = _get_F_GETOWN();
        F_SETOWN = _get_F_SETOWN();
        F_GETSIG = _get_F_GETSIG();
        F_SETSIG = _get_F_SETSIG();
        F_GETLEASE = _get_F_GETLEASE();
        F_SETLEASE = _get_F_SETLEASE();
        F_NOTIFY = _get_F_NOTIFY();
        F_RDLCK = _get_F_RDLCK();
        F_WRLCK = _get_F_WRLCK();
        F_UNLCK = _get_F_UNLCK();
        F_UNLOCK = _get_F_UNLOCK();
        F_LOCK = _get_F_LOCK();
        F_TLOCK = _get_F_TLOCK();
        F_TEST = _get_F_TEST();
        O_RDONLY = _get_O_RDONLY();
        O_WRONLY = _get_O_WRONLY();
        O_RDWR = _get_O_RDWR();
        O_CREAT = _get_O_CREAT();
        O_EXCL = _get_O_EXCL();
        O_NOCTTY = _get_O_NOCTTY();
        O_TRUNC = _get_O_TRUNC();
        O_APPEND = _get_O_APPEND();
        O_NONBLOCK = _get_O_NONBLOCK();
        O_NDELAY = _get_O_NDELAY();
        O_SYNC = _get_O_SYNC();
        O_FSYNC = _get_O_FSYNC();
        O_ASYNC = _get_O_ASYNC();
        O_DIRECT = _get_O_DIRECT();
        O_DIRECTORY = _get_O_DIRECTORY();
        O_NOFOLLOW = _get_O_NOFOLLOW();
        O_DSYNC = _get_O_DSYNC();
        O_RSYNC = _get_O_RSYNC();
        O_LARGEFILE = _get_O_LARGEFILE();
        POSIX_FADV_NORMAL = _get_POSIX_FADV_NORMAL();
        POSIX_FADV_SEQUENTIAL = _get_POSIX_FADV_SEQUENTIAL();
        POSIX_FADV_RANDOM = _get_POSIX_FADV_RANDOM();
        POSIX_FADV_NOREUSE = _get_POSIX_FADV_NOREUSE();
        POSIX_FADV_WILLNEED = _get_POSIX_FADV_WILLNEED();
        POSIX_FADV_DONTNEED = _get_POSIX_FADV_DONTNEED();
        S_IFMT = _get_S_IFMT();
        S_IFDIR = _get_S_IFDIR();
        S_IFCHR = _get_S_IFCHR();
        S_IFREG = _get_S_IFREG();
        S_IFIFO = _get_S_IFIFO();
        S_IFLNK = _get_S_IFLNK();
        S_IFSOCK = _get_S_IFSOCK();
        S_ISUID = _get_S_ISUID();
        S_ISGID = _get_S_ISGID();
        S_IREAD = _get_S_IREAD();
        S_IWRITE = _get_S_IWRITE();
        S_IEXEC = _get_S_IEXEC();
        S_IRUSR = _get_S_IRUSR();
        S_IWUSR = _get_S_IWUSR();
        S_IXUSR = _get_S_IXUSR();
        S_IRWXU = _get_S_IRWXU();
        S_IRGRP = _get_S_IRGRP();
        S_IWGRP = _get_S_IWGRP();
        S_IXGRP = _get_S_IXGRP();
        S_IRWXG = _get_S_IRWXG();
        S_IROTH = _get_S_IROTH();
        S_IWOTH = _get_S_IWOTH();
        S_IXOTH = _get_S_IXOTH();
        S_IRWXO = _get_S_IRWXO();
        R_OK = _get_R_OK();
        W_OK = _get_W_OK();
        X_OK = _get_X_OK();
        F_OK = _get_F_OK();
        EPERM = _get_EPERM();
        ENOENT = _get_ENOENT();
        ESRCH = _get_ESRCH();
        EINTR = _get_EINTR();
        EIO = _get_EIO();
        ENXIO = _get_ENXIO();
        E2BIG = _get_E2BIG();
        ENOEXEC = _get_ENOEXEC();
        EBADF = _get_EBADF();
        ECHILD = _get_ECHILD();
        EAGAIN = _get_EAGAIN();
        ENOMEM = _get_ENOMEM();
        EACCES = _get_EACCES();
        EFAULT = _get_EFAULT();
        ENOTBLK = _get_ENOTBLK();
        EBUSY = _get_EBUSY();
        EEXIST = _get_EEXIST();
        EXDEV = _get_EXDEV();
        ENODEV = _get_ENODEV();
        ENOTDIR = _get_ENOTDIR();
        EISDIR = _get_EISDIR();
        EINVAL = _get_EINVAL();
        ENFILE = _get_ENFILE();
        EMFILE = _get_EMFILE();
        ENOTTY = _get_ENOTTY();
        ETXTBSY = _get_ETXTBSY();
        EFBIG = _get_EFBIG();
        ENOSPC = _get_ENOSPC();
        ESPIPE = _get_ESPIPE();
        EROFS = _get_EROFS();
        EMLINK = _get_EMLINK();
        EPIPE = _get_EPIPE();
        EDOM = _get_EDOM();
        ERANGE = _get_ERANGE();
        EDEADLK = _get_EDEADLK();
        ENAMETOOLONG = _get_ENAMETOOLONG();
        ENOLCK = _get_ENOLCK();
        ENOSYS = _get_ENOSYS();
        ENOTEMPTY = _get_ENOTEMPTY();
        ELOOP = _get_ELOOP();
        EWOULDBLOCK = _get_EWOULDBLOCK();
        ENOMSG = _get_ENOMSG();
        EIDRM = _get_EIDRM();
        ECHRNG = _get_ECHRNG();
        EL2NSYNC = _get_EL2NSYNC();
        EL3HLT = _get_EL3HLT();
        EL3RST = _get_EL3RST();
        ELNRNG = _get_ELNRNG();
        EUNATCH = _get_EUNATCH();
        ENOCSI = _get_ENOCSI();
        EL2HLT = _get_EL2HLT();
        EBADE = _get_EBADE();
        EBADR = _get_EBADR();
        EXFULL = _get_EXFULL();
        ENOANO = _get_ENOANO();
        EBADRQC = _get_EBADRQC();
        EBADSLT = _get_EBADSLT();
        EDEADLOCK = _get_EDEADLOCK();
        EBFONT = _get_EBFONT();
        ENOSTR = _get_ENOSTR();
        ENODATA = _get_ENODATA();
        ETIME = _get_ETIME();
        ENOSR = _get_ENOSR();
        ENONET = _get_ENONET();
        ENOPKG = _get_ENOPKG();
        EREMOTE = _get_EREMOTE();
        ENOLINK = _get_ENOLINK();
        EADV = _get_EADV();
        ESRMNT = _get_ESRMNT();
        ECOMM = _get_ECOMM();
        EPROTO = _get_EPROTO();
        EMULTIHOP = _get_EMULTIHOP();
        EDOTDOT = _get_EDOTDOT();
        EBADMSG = _get_EBADMSG();
        EOVERFLOW = _get_EOVERFLOW();
        ENOTUNIQ = _get_ENOTUNIQ();
        EBADFD = _get_EBADFD();
        EREMCHG = _get_EREMCHG();
        ELIBACC = _get_ELIBACC();
        ELIBBAD = _get_ELIBBAD();
        ELIBSCN = _get_ELIBSCN();
        ELIBMAX = _get_ELIBMAX();
        ELIBEXEC = _get_ELIBEXEC();
        EILSEQ = _get_EILSEQ();
        ERESTART = _get_ERESTART();
        ESTRPIPE = _get_ESTRPIPE();
        EUSERS = _get_EUSERS();
        ENOTSOCK = _get_ENOTSOCK();
        EDESTADDRREQ = _get_EDESTADDRREQ();
        EMSGSIZE = _get_EMSGSIZE();
        EPROTOTYPE = _get_EPROTOTYPE();
        ENOPROTOOPT = _get_ENOPROTOOPT();
        EPROTONOSUPPORT = _get_EPROTONOSUPPORT();
        ESOCKTNOSUPPORT = _get_ESOCKTNOSUPPORT();
        EOPNOTSUPP = _get_EOPNOTSUPP();
        EPFNOSUPPORT = _get_EPFNOSUPPORT();
        EAFNOSUPPORT = _get_EAFNOSUPPORT();
        EADDRINUSE = _get_EADDRINUSE();
        EADDRNOTAVAIL = _get_EADDRNOTAVAIL();
        ENETDOWN = _get_ENETDOWN();
        ENETUNREACH = _get_ENETUNREACH();
        ENETRESET = _get_ENETRESET();
        ECONNABORTED = _get_ECONNABORTED();
        ECONNRESET = _get_ECONNRESET();
        ENOBUFS = _get_ENOBUFS();
        EISCONN = _get_EISCONN();
        ENOTCONN = _get_ENOTCONN();
        ESHUTDOWN = _get_ESHUTDOWN();
        ETOOMANYREFS = _get_ETOOMANYREFS();
        ETIMEDOUT = _get_ETIMEDOUT();
        ECONNREFUSED = _get_ECONNREFUSED();
        EHOSTDOWN = _get_EHOSTDOWN();
        EHOSTUNREACH = _get_EHOSTUNREACH();
        EALREADY = _get_EALREADY();
        EINPROGRESS = _get_EINPROGRESS();
        ESTALE = _get_ESTALE();
        EUCLEAN = _get_EUCLEAN();
        ENOTNAM = _get_ENOTNAM();
        ENAVAIL = _get_ENAVAIL();
        EISNAM = _get_EISNAM();
        EREMOTEIO = _get_EREMOTEIO();
        EDQUOT = _get_EDQUOT();
        ENOMEDIUM = _get_ENOMEDIUM();
        EMEDIUMTYPE = _get_EMEDIUMTYPE();
        ECANCELED = _get_ECANCELED();
        ENOKEY = _get_ENOKEY();
        EKEYEXPIRED = _get_EKEYEXPIRED();
        EKEYREVOKED = _get_EKEYREVOKED();
        EKEYREJECTED = _get_EKEYREJECTED();
        EOWNERDEAD = _get_EOWNERDEAD();
        ENOTRECOVERABLE = _get_ENOTRECOVERABLE();
        ATEXIT_MAX = _get_ATEXIT_MAX();
    }
    // !! end generated
}

/* Local variables: */
/* mode: Java */
/* indent-tabs-mode: nil */
/* tab-width: 8 */
/* End: */
/* vi: set expandtab tabstop=8 */
