/** @file   TestPosix.java
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

package jposix.test;

import jposix.OSException;
import jposix.Posix;

import org.junit.Test;
import static org.junit.Assert.*;

public class TestPosix {
    @Test(expected=NullPointerException.class)
    public void accessNull()
        throws OSException
    {
        Posix.access((byte[]) null, 0);
    }

    @Test
    public void accessNonexistent()
    {
        try {
            Posix.access("/.a.directory.which-should!not~exist", Posix.R_OK);
            fail("Expected an OSException.");
        }
        catch (OSException e) {
            assertEquals(Posix.ENOENT, e.getErrno());
        }
    }

    @Test
    public void accessRootWrite()
    {
        try {
            Posix.access("/", Posix.W_OK);
            fail("Expected an OSException.");
        }
        catch (OSException e) {
            assertEquals(Posix.EACCES, e.getErrno());
        }
    }

    @Test
    public void accessSuccess()
        throws OSException
    {
        Posix.access("/", Posix.R_OK);
    }

    @Test
    public void chdirNonexistent()
    {
        try {
            Posix.chdir("/.a.directory.which-should!not~exist");
            fail("Expected an OSException.");
        }
        catch (OSException e) {
            assertEquals(Posix.ENOENT, e.getErrno());
        }
    }

    @Test(expected=NullPointerException.class)
    public void chdirNull()
        throws OSException
    {
        Posix.chdir((byte[]) null);
    }

    @Test
    public void chdirSuccess()
        throws OSException
    {
        Posix.chdir("/tmp");
    }

    @Test(expected=NullPointerException.class)
    public void cryptNullKey()
        throws OSException
    {
        Posix.crypt(null, "".getBytes());
    }

    @Test(expected=NullPointerException.class)
    public void cryptNullSalt()
        throws OSException
    {
        Posix.crypt("".getBytes(), null);
    }

    @Test(expected=IllegalArgumentException.class)
    public void cryptSaltTooLong()
        throws OSException
    {
        Posix.crypt("", "123");
    }

    @Test(expected=IllegalArgumentException.class)
    public void cryptSaltTooShort()
        throws OSException
    {
        Posix.crypt("", "1");
    }

    @Test
    public void cryptSuccess()
        throws OSException
    {
        String crypt1 = Posix.crypt("helloworld", "aa");
        String crypt2 = Posix.crypt("helloworld", "ab");

        assertEquals("aaCNfh7.82PaE", crypt1);
        assertEquals("abINGpTYxkpU.", crypt2);
    }

    @Test(expected=NullPointerException.class)
    public void encryptNull()
        throws OSException
    {
        Posix.encrypt((byte[]) null, false);
    }

    @Test
    public void encryptSuccess()
        throws OSException
    {
        byte[] block = new byte[8];
        for (int i = 0; i < 8; ++i)
            block[i] = (byte) i;

        Posix.encrypt(block, false);
        Posix.encrypt(block, true);

        for (int i = 0; i < 8; ++i)
            assertEquals((byte) i, block[i]);
    }

    @Test
    public void environSuccess()
    {
        String[] env = Posix.environStr();
        assertTrue(env.length > 0);
        
        boolean homeFound = false;
        for (int i = 0; ! homeFound && i < env.length; ++i) {
            if (env[i].startsWith("HOME="))
                homeFound = true;
        }
         
        assertTrue(homeFound);
    }

    @Test
    public void fork()
        throws OSException
    {
        int result = Posix.fork();

        assertTrue(result != -1);
        if (result == 0) {
            Posix._exit(0);
        }
    }

    @Test
    public void getenv()
        throws OSException
    {
        System.out.println("getenv(\"HOME\") == \"" + Posix.getenv("HOME") +
                           "\"");
    }

    @Test
    public void gethostid()
        throws OSException
    {
        System.out.println("gethostid() == " + Posix.gethostid());
    }

    @Test
    public void gethostname()
        throws OSException
    {
        System.out.println("gethostname() == \"" + Posix.gethostnameStr() +
                           "\"");
    }

    @Test
    public void getlogin()
        throws OSException
    {
        // This usually fails under ant -- getlogin() returns NULL because
        // the process doesn't have a controlling terminal.
        try {
            System.out.println("getlogin() == \"" + Posix.getloginStr() + 
                               "\"");
        }
        catch (OSException e) {
            if (e.getErrno() != Posix.EINVAL && e.getErrno() != Posix.ENOTTY) {
                throw e;
            }

            System.out.println("getlogin() has no controlling terminal -- " +
                               "skipping test.");
        }
    }

    @Test
    public void getpagesize()
    {
        System.out.println("getpagesize() == " + Posix.getpagesize());
    }

    @Test
    public void getpid()
    {
        System.out.println("getpid() == " + Posix.getpid());
    }

    @Test
    public void getppid()
    {
        System.out.println("getppid() == " + Posix.getppid());
    }

    @Test
    public void getpgid()
        throws OSException
    {
        System.out.println("getpgid(getpid()) == " +
                           Posix.getpgid(Posix.getpid()));
    }

    @Test
    public void getresgid()
        throws OSException
    {
        int[] gids = Posix.getresgid();

        System.out.println("getresgid(): rgid=" + gids[0] + " egid=" +
                           gids[1] + " sgid=" + gids[2]);
    }

    @Test
    public void getresuid()
        throws OSException
    {
        int[] uids = Posix.getresuid();

        System.out.println("getresuid(): ruid=" + uids[0] + " euid=" +
                           uids[1] + " suid=" + uids[2]);
    }

    @Test
    public void getsid()
        throws OSException
    {
        System.out.println("getsid(getpid()) == " +
                           Posix.getsid(Posix.getpid()));
    }

    @Test
    public void groupAndUserIds()
    {
        System.out.println("uid=" + Posix.getuid() + " " +
                           "gid=" + Posix.getgid() + " " +
                           "euid=" + Posix.geteuid() + " " +
                           "egid=" + Posix.getegid());
    }

    @Test
    public void groups()
    {
        int[] groups = Posix.getgroups();
        System.out.print("groups=[");
        for (int i = 0; i < groups.length; ++i) {
            if (i > 0) System.out.print(" ");
            System.out.print(groups[i]);
        }

        System.out.println("]");
    }

    @Test
    public void pipe()
        throws OSException
    {
        int[] fd = new int[2];
        String writeme = "Hello world";
        byte[] buf = new byte[writeme.length()];
        
        Posix.pipe(fd);

        Posix.write(fd[1], writeme.getBytes());
        Posix.read(fd[0], buf);

        assertEquals(writeme, new String(buf));

        Posix.close(fd[0]);
        Posix.close(fd[1]);
    }

    @Test
    public void usershells()
    {
        String shell;

        Posix.setusershell();
        System.out.print("usershells:");
        while ((shell = Posix.getusershellStr()) != null) {
            System.out.print(" " + shell);
        }

        Posix.endusershell();
        System.out.println("");
    }
}

/* Local variables: */
/* mode: Java */
/* indent-tabs-mode: nil */
/* tab-width: 8 */
/* End: */
/* vi: set expandtab tabstop=8 */
