#include "../Assignment13.h"
#include <optional>
#include <set>



void Assignment13::pickPhysicalDevice() {
    //like with extensions
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
    if (deviceCount == 0) {
        throw std::runtime_error("failed to find GPUs with Vulkan support!");
    }

    //allocate an array to hold all the devices
    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

    //check if there is a suitable device
    for (const auto& device : devices) {
        if (isDeviceSuitable(device)) {
            physicalDevice = device;
            break;
        }
    }

    if (physicalDevice == VK_NULL_HANDLE) {
        throw std::runtime_error("failed to find a suitable GPU!");
    }

}

//TODO check if has graphic and presentation queue support
bool Assignment13::isDeviceSuitable(VkPhysicalDevice device) {
    /*VkPhysicalDeviceProperties deviceProperties;
    VkPhysicalDeviceFeatures deviceFeatures;
    vkGetPhysicalDeviceProperties(device, &deviceProperties);
    vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

    return deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU &&
        deviceFeatures.geometryShader;*/
    QueueFamilyIndices indices = findQueueFamilies(device);


    return indices.isComplete();
}


QueueFamilyIndices Assignment13::findQueueFamilies(VkPhysicalDevice device) {
    QueueFamilyIndices indices;
    uint32_t queueFamilyCount = 0;
    VkBool32 presentSupport = false;

    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());
    

    int i = 0;
    for (const auto& queueFamily : queueFamilies) {
        
        vkGetPhysicalDeviceSurfaceSupportKHR(device, i, surface, &presentSupport);
        
        if ((queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) && presentSupport) {
            indices.graphicsFamily = i;
            indices.presentFamily = i;
        }

        if (indices.isComplete())
            break;
        i++;
    }

    return indices;
}