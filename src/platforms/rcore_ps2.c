/**********************************************************************************************
*
*   rcore_ps2 - Functions to manage window, graphics device and inputs
*
*   PLATFORM: PS2
*       - PlayStation 2
*
*   LIMITATIONS:
*       - Limitation 01
*       - Limitation 02
*
*   POSSIBLE IMPROVEMENTS:
*       - Improvement 01
*       - Improvement 02
*
*   ADDITIONAL NOTES:
*       - Based in original port by Antonio Jose Ramos Marquez aka bigboss @psxdev
*       - Written by Hakan Candar @hakanrw (GitHub) based on rcore_psp.c
*
*   CONFIGURATION:
*       - make PLATFORM=PLATFORM_PS2
*
*   DEPENDENCIES:
*       PS2DEV, PS2SDK - Provides C API to access PS2 homebrew functionality
*
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5) and contributors
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include <kernel.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <GL/gl.h>
#include <GL/ps2gl.h>

#include <libkbd.h>
#include "ps2drv/ps2drv.h"

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef struct {
    // TODO: Define the platform specific variables required

    // Display data
    //EGLDisplay device;                  // Native display device (physical screen connection)
    //EGLSurface surface;                 // Surface to draw on, framebuffers (connected to context)
    //EGLContext context;                 // Graphic context, mode in which drawing can be done
    //EGLConfig config;                   // Graphic config
    bool first_frame;
} PlatformData;

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
extern CoreData CORE;                   // Global CORE state context

static PlatformData platform = { 0 };   // Platform specific data

//----------------------------------------------------------------------------------
// Module Internal Functions Declaration
//----------------------------------------------------------------------------------
int InitPlatform(void);          // Initialize platform (graphics, inputs and more)
bool InitGraphicsDevice(void);   // Initialize graphics device

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
// NOTE: Functions declaration is provided by raylib.h

//----------------------------------------------------------------------------------
// Module Functions Definition: Window and Graphics Device
//----------------------------------------------------------------------------------

// Check if application should close
bool WindowShouldClose(void)
{
    if (CORE.Window.ready) return CORE.Window.shouldClose;
    else return true;
}

// Toggle fullscreen mode
void ToggleFullscreen(void)
{
    TRACELOG(LOG_WARNING, "ToggleFullscreen() not available on target platform");
}

// Toggle borderless windowed mode
void ToggleBorderlessWindowed(void)
{
    TRACELOG(LOG_WARNING, "ToggleBorderlessWindowed() not available on target platform");
}

// Set window state: maximized, if resizable
void MaximizeWindow(void)
{
    TRACELOG(LOG_WARNING, "MaximizeWindow() not available on target platform");
}

// Set window state: minimized
void MinimizeWindow(void)
{
    TRACELOG(LOG_WARNING, "MinimizeWindow() not available on target platform");
}

// Set window state: not minimized/maximized
void RestoreWindow(void)
{
    TRACELOG(LOG_WARNING, "RestoreWindow() not available on target platform");
}

// Set window configuration state using flags
void SetWindowState(unsigned int flags)
{
    TRACELOG(LOG_WARNING, "SetWindowState() not available on target platform");
}

// Clear window configuration state flags
void ClearWindowState(unsigned int flags)
{
    TRACELOG(LOG_WARNING, "ClearWindowState() not available on target platform");
}

// Set icon for window
void SetWindowIcon(Image image)
{
    TRACELOG(LOG_WARNING, "SetWindowIcon() not available on target platform");
}

// Set icon for window
void SetWindowIcons(Image *images, int count)
{
    TRACELOG(LOG_WARNING, "SetWindowIcons() not available on target platform");
}

// Set title for window
void SetWindowTitle(const char *title)
{
    CORE.Window.title = title;
}

// Set window position on screen (windowed mode)
void SetWindowPosition(int x, int y)
{
    TRACELOG(LOG_WARNING, "SetWindowPosition() not available on target platform");
}

// Set monitor for the current window
void SetWindowMonitor(int monitor)
{
    TRACELOG(LOG_WARNING, "SetWindowMonitor() not available on target platform");
}

// Set window minimum dimensions (FLAG_WINDOW_RESIZABLE)
void SetWindowMinSize(int width, int height)
{
    CORE.Window.screenMin.width = width;
    CORE.Window.screenMin.height = height;
}

// Set window maximum dimensions (FLAG_WINDOW_RESIZABLE)
void SetWindowMaxSize(int width, int height)
{
    CORE.Window.screenMax.width = width;
    CORE.Window.screenMax.height = height;
}

// Set window dimensions
void SetWindowSize(int width, int height)
{
    TRACELOG(LOG_WARNING, "SetWindowSize() not available on target platform");
}

// Set window opacity, value opacity is between 0.0 and 1.0
void SetWindowOpacity(float opacity)
{
    TRACELOG(LOG_WARNING, "SetWindowOpacity() not available on target platform");
}

// Set window focused
void SetWindowFocused(void)
{
    TRACELOG(LOG_WARNING, "SetWindowFocused() not available on target platform");
}

// Get native window handle
void *GetWindowHandle(void)
{
    TRACELOG(LOG_WARNING, "GetWindowHandle() not implemented on target platform");
    return NULL;
}

// Get number of monitors
int GetMonitorCount(void)
{
    TRACELOG(LOG_WARNING, "GetMonitorCount() not implemented on target platform");
    return 1;
}

// Get number of monitors
int GetCurrentMonitor(void)
{
    TRACELOG(LOG_WARNING, "GetCurrentMonitor() not implemented on target platform");
    return 0;
}

// Get selected monitor position
Vector2 GetMonitorPosition(int monitor)
{
    TRACELOG(LOG_WARNING, "GetMonitorPosition() not implemented on target platform");
    return (Vector2){ 0, 0 };
}

// Get selected monitor width (currently used by monitor)
int GetMonitorWidth(int monitor)
{
    TRACELOG(LOG_WARNING, "GetMonitorWidth() not implemented on target platform");
    return 0;
}

// Get selected monitor height (currently used by monitor)
int GetMonitorHeight(int monitor)
{
    TRACELOG(LOG_WARNING, "GetMonitorHeight() not implemented on target platform");
    return 0;
}

// Get selected monitor physical width in millimetres
int GetMonitorPhysicalWidth(int monitor)
{
    TRACELOG(LOG_WARNING, "GetMonitorPhysicalWidth() not implemented on target platform");
    return 0;
}

// Get selected monitor physical height in millimetres
int GetMonitorPhysicalHeight(int monitor)
{
    TRACELOG(LOG_WARNING, "GetMonitorPhysicalHeight() not implemented on target platform");
    return 0;
}

// Get selected monitor refresh rate
int GetMonitorRefreshRate(int monitor)
{
    TRACELOG(LOG_WARNING, "GetMonitorRefreshRate() not implemented on target platform");
    return 0;
}

// Get the human-readable, UTF-8 encoded name of the selected monitor
const char *GetMonitorName(int monitor)
{
    TRACELOG(LOG_WARNING, "GetMonitorName() not implemented on target platform");
    return "";
}

// Get window position XY on monitor
Vector2 GetWindowPosition(void)
{
    TRACELOG(LOG_WARNING, "GetWindowPosition() not implemented on target platform");
    return (Vector2){ 0, 0 };
}

// Get window scale DPI factor for current monitor
Vector2 GetWindowScaleDPI(void)
{
    TRACELOG(LOG_WARNING, "GetWindowScaleDPI() not implemented on target platform");
    return (Vector2){ 1.0f, 1.0f };
}

// Set clipboard text content
void SetClipboardText(const char *text)
{
    TRACELOG(LOG_WARNING, "SetClipboardText() not implemented on target platform");
}

// Get clipboard text content
// NOTE: returned string is allocated and freed by GLFW
const char *GetClipboardText(void)
{
    TRACELOG(LOG_WARNING, "GetClipboardText() not implemented on target platform");
    return NULL;
}

// Show mouse cursor
void ShowCursor(void)
{
    CORE.Input.Mouse.cursorHidden = false;
}

// Hides mouse cursor
void HideCursor(void)
{
    CORE.Input.Mouse.cursorHidden = true;
}

// Enables cursor (unlock cursor)
void EnableCursor(void)
{
    // Set cursor position in the middle
    SetMousePosition(CORE.Window.screen.width/2, CORE.Window.screen.height/2);

    CORE.Input.Mouse.cursorHidden = false;
}

// Disables cursor (lock cursor)
void DisableCursor(void)
{
    // Set cursor position in the middle
    SetMousePosition(CORE.Window.screen.width/2, CORE.Window.screen.height/2);

    CORE.Input.Mouse.cursorHidden = true;
}

// Swap back buffer with front buffer (screen drawing)
void SwapScreenBuffer(void)
{
    // TODO
    //eglSwapBuffers(platform.device, platform.surface);
}

//----------------------------------------------------------------------------------
// Module Functions Definition: Misc
//----------------------------------------------------------------------------------

// Get elapsed time measure in seconds since InitTimer()
double GetTime(void)
{
    double time = 0.0;
    struct timespec ts = { 0 };
    clock_gettime(CLOCK_MONOTONIC, &ts);
    unsigned long long int nanoSeconds = (unsigned long long int)ts.tv_sec*1000000000LLU + (unsigned long long int)ts.tv_nsec;

    time = (double)(nanoSeconds - CORE.Time.base)*1e-9;  // Elapsed time since InitTimer()

    return time;
}

// Open URL with default system browser (if available)
// NOTE: This function is only safe to use if you control the URL given.
// A user could craft a malicious string performing another action.
// Only call this function yourself not with user input or make sure to check the string yourself.
// Ref: https://github.com/raysan5/raylib/issues/686
void OpenURL(const char *url)
{
   // Security check to (partially) avoid malicious code on target platform
    if (strchr(url, '\'') != NULL) TRACELOG(LOG_WARNING, "SYSTEM: Provided URL could be potentially malicious, avoid [\'] character");
    else
    {
        // TODO:
    }
}

//----------------------------------------------------------------------------------
// Module Functions Definition: Inputs
//----------------------------------------------------------------------------------

// Set internal gamepad mappings
int SetGamepadMappings(const char *mappings)
{
    TRACELOG(LOG_WARNING, "SetGamepadMappings() not implemented on target platform");
    return 0;
}

// Set mouse position XY
void SetMousePosition(int x, int y)
{
    CORE.Input.Mouse.currentPosition = (Vector2){ (float)x, (float)y };
    CORE.Input.Mouse.previousPosition = CORE.Input.Mouse.currentPosition;
}

// Set mouse cursor
void SetMouseCursor(int cursor)
{
    TRACELOG(LOG_WARNING, "SetMouseCursor() not implemented on target platform");
}

// Register all input events
void PollInputEvents(void)
{
#if defined(SUPPORT_GESTURES_SYSTEM)
    // NOTE: Gestures update must be called every frame to reset gestures correctly
    // because ProcessGestureEvent() is just called on an event, not every frame
    UpdateGestures();
#endif

    // Reset keys/chars pressed registered
    CORE.Input.Keyboard.keyPressedQueueCount = 0;
    CORE.Input.Keyboard.charPressedQueueCount = 0;

    // Reset key repeats
    for (int i = 0; i < MAX_KEYBOARD_KEYS; i++)
    {
        CORE.Input.Keyboard.previousKeyState[i] = CORE.Input.Keyboard.currentKeyState[i];
        CORE.Input.Keyboard.keyRepeatInFrame[i] = 0;
    }

    // Register previous mouse states
    for (int i = 0; i < MAX_MOUSE_BUTTONS; i++) CORE.Input.Mouse.previousButtonState[i] = CORE.Input.Mouse.currentButtonState[i];

    // Register previous mouse wheel state
    CORE.Input.Mouse.previousWheelMove = CORE.Input.Mouse.currentWheelMove;
    CORE.Input.Mouse.currentWheelMove = (Vector2){ 0.0f, 0.0f };

    // Register previous mouse position
    CORE.Input.Mouse.previousPosition = CORE.Input.Mouse.currentPosition;

    // Reset last gamepad button/axis registered state
    CORE.Input.Gamepad.lastButtonPressed = 0; // GAMEPAD_BUTTON_UNKNOWN
    //CORE.Input.Gamepad.axisCount = 0;

    PS2KbdRawKey key;
    for (int read_len = PS2KbdReadRaw(&key); read_len > 0; read_len = PS2KbdReadRaw(&key))
    {
        bool key_down = key.state == PS2KBD_RAWKEY_DOWN;
        bool is_char = false;
        int raylib_key_code = 0;

        if (key.key >= 4 && key.key <= 29) // a-z
        {
            is_char = true;
            raylib_key_code = key.key + 61;
        }
        else if (key.key >= 30 && key.key <= 38) // 1-9
        {
            is_char = true;
            raylib_key_code = key.key + 19;
        }
        else if (key.key == 39) // 0
        {
            is_char = true;
            raylib_key_code = 48;
        }
        else
        {
            switch (key.key)
            {
                case 40: raylib_key_code = KEY_ENTER; break;
                case 42: raylib_key_code = KEY_BACKSPACE; break;
                case 44: raylib_key_code = KEY_SPACE; is_char = true; break;
                case 79: raylib_key_code = KEY_RIGHT; break;
                case 80: raylib_key_code = KEY_LEFT; break;
                case 81: raylib_key_code = KEY_DOWN; break;
                case 82: raylib_key_code = KEY_UP; break;
                case 225: raylib_key_code = KEY_LEFT_SHIFT; break;
                case 229: raylib_key_code = KEY_RIGHT_SHIFT; break;
                default: TRACELOG(LOG_INFO,"PLATFORM: PollInputEvents: unmapped key %d", key.key);
            }
        }

        // If key was up, add it to the key pressed queue
        if ((CORE.Input.Keyboard.currentKeyState[raylib_key_code] == 0) && (CORE.Input.Keyboard.keyPressedQueueCount < MAX_KEY_PRESSED_QUEUE))
        {
            //TRACELOG(LOG_INFO,"KBD: Add to queue");
            CORE.Input.Keyboard.keyPressedQueue[CORE.Input.Keyboard.keyPressedQueueCount] = raylib_key_code;
            CORE.Input.Keyboard.keyPressedQueueCount++;
        }

        if (key_down && is_char && (CORE.Input.Keyboard.charPressedQueueCount < MAX_CHAR_PRESSED_QUEUE))
        {
            //TRACELOG(LOG_INFO,"KBD: Add to char queue");
            CORE.Input.Keyboard.charPressedQueue[CORE.Input.Keyboard.charPressedQueueCount] = raylib_key_code;

            //TRACELOG(LOG_INFO,"KBD: LSHift %d", CORE.Input.Keyboard.currentKeyState[KEY_LEFT_SHIFT]);
            //TRACELOG(LOG_INFO,"KBD: RShift %d", CORE.Input.Keyboard.currentKeyState[KEY_RIGHT_SHIFT]);

            if (!CORE.Input.Keyboard.currentKeyState[KEY_LEFT_SHIFT]
                && !CORE.Input.Keyboard.currentKeyState[KEY_RIGHT_SHIFT])
            {
                if (raylib_key_code >= KEY_A && raylib_key_code <= KEY_Z)
                    CORE.Input.Keyboard.charPressedQueue[CORE.Input.Keyboard.charPressedQueueCount] += 32; // Lowercase
            }
            else
            {
                if (raylib_key_code >= KEY_ZERO && raylib_key_code <= KEY_NINE)
                    CORE.Input.Keyboard.charPressedQueue[CORE.Input.Keyboard.charPressedQueueCount] -= 16; // Symbols
            }

            CORE.Input.Keyboard.charPressedQueueCount++;
        }

        CORE.Input.Keyboard.currentKeyState[raylib_key_code] = key.state == PS2KBD_RAWKEY_DOWN;
        //TRACELOG(LOG_INFO,"KBD: %d", key.state == PS2KBD_RAWKEY_DOWN);
    }
}

//----------------------------------------------------------------------------------
// Module Internal Functions Definition
//----------------------------------------------------------------------------------
int done = 0;
/* Exit callback */
int exit_callback(int arg1, int arg2, void *common)
{
    done = 1;
    return 0;
}

/* Callback thread */
/*int CallbackThread(SceSize args, void *argp)
{
    int cbid;

    // TODO
    //cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    //sceKernelRegisterExitCallback(cbid);
    //sceKernelSleepThreadCB();

    return 0;
}*/

/* Sets up the callback thread and returns its thread id */
int SetupCallbacks(void)
{
    int thid = 0;

    // TODO
    //thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
    //if(thid >= 0)
    //{
    //    sceKernelStartThread(thid, 0, 0);
    //}

    return thid;
}

void CustomLog(int msgType, const char *text, va_list args)
{
    char buffer[2048] = { 0 };


    vsnprintf(buffer,2048, text, args);
    buffer[2048-1] = 0;


    switch (msgType)
    {
        case LOG_TRACE: printf("[PS2][TRACE]%s\n",buffer); break;
        case LOG_DEBUG: printf("[PS2][DEBUG]%s\n",buffer); break;
        case LOG_INFO: printf("[PS2][INFO]%s\n",buffer); break;
        case LOG_WARNING: printf("[PS2][WARNING]%s\n",buffer); break;
        case LOG_ERROR: printf("[PS2][ERROR]%s\n",buffer); break;
        case LOG_FATAL: printf("[PS2][FATAL]%s\n",buffer); break;
        default: break;
    }
}

/* from ps2stuff
typedef enum { kPsm32 = 0,
    kPsm24            = 1,
    kPsm16            = 2,
    kPsm16s           = 10,
    kPsm8             = 19,
    kPsm8h            = 27,
    kPsm4             = 20,
    kPsm4hh           = 44,
    kPsm4hl           = 36,

    kPsmz32  = 48,
    kPsmz24  = 49,
    kPsmz16  = 50,
    kPsmz16s = 58,

    kInvalidPsm = -1
} tPSM;
*/

#define PS2GL_KPSM32	0
#define PS2GL_KPSM24	1
#define PS2GL_KPSM16	2
#define PS2GL_KPSM16S	10
#define PS2GL_KPSM8	19
#define PS2GL_KPSM8H	27
#define PS2GL_KPSM4	20
#define PS2GL_KPSM4HH	44
#define PS2GL_KPSM4HL	36

#define PS2GL_KPSMZ32	48
#define PS2GL_KPSMZ24	49
#define PS2GL_KPSMZ16	50
#define PS2GL_KPSMZ16S	58

/* from ps2glut */
static void initGsMemory()
{
    // frame and depth buffer
    pgl_slot_handle_t frame_slot_0, frame_slot_1, depth_slot;
    frame_slot_0 = pglAddGsMemSlot(0, 70, PS2GL_KPSM32);
    frame_slot_1 = pglAddGsMemSlot(70, 70, PS2GL_KPSM32);
    depth_slot   = pglAddGsMemSlot(140, 70, PS2GL_KPSMZ24);
    // lock these slots so that they aren't allocated by the memory manager
    pglLockGsMemSlot(frame_slot_0);
    pglLockGsMemSlot(frame_slot_1);
    pglLockGsMemSlot(depth_slot);

    // create gs memory area objects to use for frame and depth buffers
    pgl_area_handle_t frame_area_0, frame_area_1, depth_area;
    frame_area_0 = pglCreateGsMemArea(640, 224, PS2GL_KPSM24);
    frame_area_1 = pglCreateGsMemArea(640, 224, PS2GL_KPSM24);
    depth_area   = pglCreateGsMemArea(640, 224, PS2GL_KPSMZ24);
    // bind the areas to the slots we created above
    pglBindGsMemAreaToSlot(frame_area_0, frame_slot_0);
    pglBindGsMemAreaToSlot(frame_area_1, frame_slot_1);
    pglBindGsMemAreaToSlot(depth_area, depth_slot);

    // draw to the new areas...
    pglSetDrawBuffers(PGL_INTERLACED, frame_area_0, frame_area_1, depth_area);
    // ...and display from them
    pglSetDisplayBuffers(PGL_INTERLACED, frame_area_0, frame_area_1);

    // 32 bit

    // a slot for fonts (probably)
    pglAddGsMemSlot(210, 2, PS2GL_KPSM8);

    // 64x32
    pglAddGsMemSlot(212, 1, PS2GL_KPSM32);
    pglAddGsMemSlot(213, 1, PS2GL_KPSM32);
    // 64x64
    pglAddGsMemSlot(214, 2, PS2GL_KPSM32);
    pglAddGsMemSlot(216, 2, PS2GL_KPSM32);
    pglAddGsMemSlot(218, 2, PS2GL_KPSM32);
    pglAddGsMemSlot(220, 2, PS2GL_KPSM32);
    // 128x128
    pglAddGsMemSlot(222, 8, PS2GL_KPSM32);
    pglAddGsMemSlot(230, 8, PS2GL_KPSM32);
    // 256x256
    pglAddGsMemSlot(238, 32, PS2GL_KPSM32);
    pglAddGsMemSlot(270, 32, PS2GL_KPSM32);
    // 512x256
    pglAddGsMemSlot(302, 64, PS2GL_KPSM32);
    pglAddGsMemSlot(366, 64, PS2GL_KPSM32);

    pglPrintGsMemAllocation();
}

// Initialize platform: graphics, inputs and more
int InitPlatform(void)
{
    //call backs
    SetupCallbacks();

    // set ctrl register
    unsigned long* ctrl = (unsigned long*) 0x10003000;
    *ctrl = 1;

    platform.first_frame = true;
    // ps2gl
    SetGsCrt(1 /* interlaced */, 2 /* ntsc */, 1 /* frame */);
    int immBufferVertexSize = 64 * 1024;
    pglInit(immBufferVertexSize, 1000);
    initGsMemory();

    CORE.Window.fullscreen = true;
    CORE.Window.flags |= FLAG_FULLSCREEN_MODE;

    CORE.Window.display.width = CORE.Window.screen.width;            // User desired width
    CORE.Window.display.height = CORE.Window.screen.height;          // User desired height
    CORE.Window.render.width = CORE.Window.screen.width;
    CORE.Window.render.height = CORE.Window.screen.height;
    CORE.Window.eventWaiting = false;
    CORE.Window.screenScale = MatrixIdentity();     // No draw scaling required by default
    CORE.Window.currentFbo.width = CORE.Window.screen.width;
    CORE.Window.currentFbo.height = CORE.Window.screen.height;
    CORE.Input.Mouse.currentPosition.x = (float)CORE.Window.screen.width/2.0f;
    CORE.Input.Mouse.currentPosition.y = (float)CORE.Window.screen.height/2.0f;
    CORE.Input.Mouse.scale = (Vector2){ 1.0f, 1.0f };

    // At this point we need to manage render size vs screen size
    // NOTE: This function use and modify global module variables:
    //  -> CORE.Window.screen.width/CORE.Window.screen.height
    //  -> CORE.Window.render.width/CORE.Window.render.height
    //  -> CORE.Window.screenScale
    SetupFramebuffer(CORE.Window.display.width, CORE.Window.display.height);

    //ANativeWindow_setBuffersGeometry(platform.app->window, CORE.Window.render.width, CORE.Window.render.height, displayFormat);
    //ANativeWindow_setBuffersGeometry(platform.app->window, 0, 0, displayFormat);       // Force use of native display size

    {
        CORE.Window.render.width = CORE.Window.screen.width;
        CORE.Window.render.height = CORE.Window.screen.height;
        CORE.Window.currentFbo.width = CORE.Window.render.width;
        CORE.Window.currentFbo.height = CORE.Window.render.height;

        TRACELOG(LOG_INFO, "PLATFORM: Device initialized successfully");
        TRACELOG(LOG_INFO, "    > Display size: %i x %i", CORE.Window.display.width, CORE.Window.display.height);
        TRACELOG(LOG_INFO, "    > Screen size:  %i x %i", CORE.Window.screen.width, CORE.Window.screen.height);
        TRACELOG(LOG_INFO, "    > Render size:  %i x %i", CORE.Window.render.width, CORE.Window.render.height);
        TRACELOG(LOG_INFO, "    > Viewport offsets: %i, %i", CORE.Window.renderOffset.x, CORE.Window.renderOffset.y);
    }

    // Load OpenGL extensions
    // NOTE: GL procedures address loader is required to load extensions
    //rlLoadExtensions(eglGetProcAddress);
    //const char *gl_exts = (char *) glGetString(GL_EXTENSIONS);
    TRACELOG(LOG_INFO,"PLATFORM: GL_VENDOR:   \"%s\"", glGetString(GL_VENDOR));
    TRACELOG(LOG_INFO,"PLATFORM: GL_VERSION:  \"%s\"", glGetString(GL_VERSION));
    TRACELOG(LOG_INFO,"PLATFORM: GL_RENDERER: \"%s\"", glGetString(GL_RENDERER));
    //TRACELOG(LOG_INFO,"PLATFORM: SL_VERSION:  \"%s\"", glGetString(GL_SHADING_LANGUAGE_VERSION));
    CORE.Window.ready = true;

    // Initialize hi-res timer
    InitTimer();

    // Initialize base path for storage
    CORE.Storage.basePath = GetWorkingDirectory();
    TRACELOG(LOG_INFO, "PLATFORM: Initialized");

    ps2drv_load_modules(); // Load PlayStation 2 modules into IOP
                           // For keyboard, audio, file management etc.
    PS2KbdSetReadmode(PS2KBD_READMODE_RAW);
    PS2KbdSetBlockingMode(PS2KBD_NONBLOCKING);

    CORE.Input.Keyboard.currentKeyState[KEY_LEFT_SHIFT] = 0;
    CORE.Input.Keyboard.currentKeyState[KEY_RIGHT_SHIFT] = 0;

    return 0;
}

// Close platform
void ClosePlatform(void)
{
    // TODO: De-initialize graphics, inputs and more
}

// EOF
