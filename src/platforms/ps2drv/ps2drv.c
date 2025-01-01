#include "ps2drv.h"

/* PS2SDK */
#include <sifrpc.h>
#include <loadfile.h>
#include <libpad.h>
#include <libkbd.h>
#include <delaythread.h>
#include <iopcontrol.h>
#include <libmc.h>
#include <sbv_patches.h>
#define NEWLIB_PORT_AWARE
#include <fileXio_rpc.h>
#include <fileio.h>
/* !PS2SDK */

int ps2drv_load_modules() {
        SifInitRpc(0);
        while (!SifIopReset("", 0)) { }
        while (!SifIopSync()) { }
        SifLoadFileInit();

        sbv_patch_enable_lmb();
        sbv_patch_disable_prefix_check();

        int ret; // TODO: check for errors
        SifExecModuleBuffer(ps2drv_iomanx, size_ps2drv_iomanx, 0, NULL, &ret);
        SifExecModuleBuffer(ps2drv_filexio, size_ps2drv_filexio, 0, NULL, &ret);
        SifLoadModule("rom0:SIO2MAN", 0, NULL);
        SifExecModuleBuffer(ps2drv_mcman, size_ps2drv_mcman, 0, NULL, &ret);
        SifExecModuleBuffer(ps2drv_mcserv, size_ps2drv_mcserv, 0, NULL, &ret);

        fileXioInit();
        fileXioSetRWBufferSize(128 * 1024);
        mcInit(MC_TYPE_MC);

        int dummy; // TODO: what was this?
        ret = SifExecModuleBuffer(ps2drv_usbd, size_ps2drv_usbd, 0, NULL, &dummy);
        ret = SifExecModuleBuffer(ps2drv_ps2kbd, size_ps2drv_ps2kbd, 0, NULL, &dummy);
        ret = PS2KbdInit();

        return ret;
}
