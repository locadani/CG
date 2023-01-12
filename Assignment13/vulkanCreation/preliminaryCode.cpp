#include "../Assignment13.h"

void Assignment13::createInstance() {
    // place your Vulkan instance creation code here [you can take it from Assingment 12]


    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    uint32_t extensionCount = 0;

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "A13";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    VkInstanceCreateInfo createInfo{};
    /*
        Tell vulkan driver what extensions we want to use
    */
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    /*
        specify global extensions, needed to interface with window system
    */
    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    /*
        global validation layer to activate
    */
    createInfo.enabledLayerCount = 0;

    //create vulkan instance
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }

    //from now we want to check the list of supported extension

    //get number of extensions
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    //vecor that will store extensions and their infos
    std::vector<VkExtensionProperties> extensions(extensionCount);

    //query extensions
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    //print extensions
    std::cout << "available extensions:\n";

    for (const auto& extension : extensions) {
        std::cout << '\t' << extension.extensionName << '\n';
    }

}

void Assignment13::initWindow() {
    glfwInit();

    // Continue with window creation
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(WIDTH, HEIGHT, "Assignment 13", nullptr, nullptr);

}

void Assignment13::cleanUp() {

    //will implicitly destroy also VkPhysicalDevice


    //TODO NOW command buffer allocation
    
    //command pool
    vkDestroyCommandPool(device, commandPool, nullptr);

    //presentation, to be done before destroying instance
    vkDestroySurfaceKHR(instance, surface, nullptr);
    vkDestroyInstance(instance, nullptr);
    //end presentation

    //logic
    //doesnt interact with instances
    vkDestroyDevice(device, nullptr);

    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);



    glfwTerminate();
}