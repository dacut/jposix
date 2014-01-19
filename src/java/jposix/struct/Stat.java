/** @file   Stat.java
 *  @brief  jposix implementation of struct stat.
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

package jposix.struct;

import java.lang.String;

public final class Stat {
    /** ID of device containing the file. */
    public long st_dev;

    /** inode number. */
    public long st_ino;

    /** Protection bits. */
    public int st_mode;

    /** Number of hard links. */
    public long st_nlink;

    /** User ID of owner. */
    public int st_uid;

    /** Group ID of owner. */
    public int st_gid;

    /** Device ID (if special file). */
    public long st_rdev;

    /** Total size, in bytes. */
    public long st_size;

    /** Block size for filesystem I/O. */
    public long st_blksize;

    /** Number of blocks allocated. */
    public long st_blocks;

    /** Time of last access. */
    public long st_atime;

    /** Time of last modification. */
    public long st_mtime;

    /** Time of last status change. */
    public long st_ctime;

    public String toString()
    {
        return String.format(
            "[stat st_dev=%d st_ino=%d st_mode=0%06o st_nlink=%d st_uid=%d " +
            "st_gid=%d st_rdev=%d st_size=%d st_blksize=%d st_atime=%d " +
            "st_mtime=%d st_ctime=%d]",
            st_dev, st_ino, st_mode, st_nlink, st_uid, st_gid, st_rdev,
            st_size, st_blksize, st_atime, st_mtime, st_ctime);
    }
}

/* Local variables: */
/* mode: Java */
/* indent-tabs-mode: nil */
/* tab-width: 8 */
/* End: */
/* vi: set expandtab tabstop=8 */
