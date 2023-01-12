#pragma once

#include "resource.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <optional>

const uint32_t WIDTH = 640;
const uint32_t HEIGHT = 480;

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily; //check if allows to draw over surface defined
    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};



class Assignment13 {
public:
    void run() {
        initWindow();
        initVulkan();
        initApp();
        mainLoop();
        cleanUp();
   }

private:
    // place all the application variables here. As an example, here the one for the GLFW Window
    // and the Vulkan instances are already defined.

    GLFWwindow* window;
    VkInstance instance;

    //physical
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    //logical
    VkDevice device;
    VkQueue graphicsQueue; //handle queues

    //presentation
    VkSurfaceKHR surface;
    VkQueue presentQueue; //to modify logic device creation

    //commandPool
    VkCommandPool commandPool;

    //commandBuffer
    VkCommandBuffer commandBuffer; //automatically freed

    void initWindow();
    

    void initVulkan() {
        createInstance();
        createSurface();
        pickPhysicalDevice();
        createLogicalDevice();
        createCommandPool();
        createCommandBuffer();

        // Continue with:

        // Physical Device selection
        // Logical Device creation
        // Command Pool creation
        // Command Buffer creation
    }

    void createInstance();

    //physical
    void pickPhysicalDevice();
    bool isDeviceSuitable(VkPhysicalDevice device);
    //physical and logical (in physical file)
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    //logical
    void createLogicalDevice();

    //presentationSurface
    void createSurface();

    //commandPool
    void createCommandPool();

    //command Buffer
    void createCommandBuffer();
    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    void initApp() {
        // This will not be needed in this assignment!
    }

    void mainLoop() {
        // Wait for the window to close [you can take it from Assingment 12]
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }

    void cleanUp();

};

