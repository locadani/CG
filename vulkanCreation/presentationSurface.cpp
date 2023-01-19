/*
    Note on Defines:
    Place these define before include vulkan, which now is in assignment13
*/
#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_EXPOSE_NATIVE_WIN32
//end Note on Defines
#include "../Assignment13.h"

#include <GLFW/glfw3native.h>

/* 
    
    Must be right after Instance creation, can influence device selection

    Create connection between vulkan and window system.
    Creates a abstract type of surface to present image.
    The actual one has been already created with GLFW
*/
void createSurface() {
    if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) {
        throw std::runtime_error("failed to create window surface!");
    }
}