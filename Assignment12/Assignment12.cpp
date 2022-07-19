// Following the Vulkan Tutorial until the
// Drawing a triangle -> Setup -> Instance
// section (currently at https://vulkan-tutorial.com/Drawing_a_triangle/Setup/Instance)
// create a 640 x 480 window, with title "Assignment 12", and list the global
// extensions supported by your O.S. 

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream> //for errors
#include <stdexcept>//for errors
#include <cstdlib>  //for EXIT_SUCCESS or EXIT_FAILURE
#include <vector>

const uint32_t WIDTH = 640;
const uint32_t HEIGHT = 480;

class Assignment12 {
public:
    // complete the Assignment class here 
    void run() {
        initWindow(); //for glfw
        initVulkan();
        mainLoop();
        cleanup();
    }


private:

    
    GLFWwindow* window;
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    void initWindow() {
        /*
            Initialize library
        */
        glfwInit();
        /*
            dont create a openGL context
            (Because we are using vulkan i guess)
        */
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); 
        /*
            dont allow window resizing
        */
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        /*
            Create actual window
        */
        window = glfwCreateWindow(WIDTH, HEIGHT, "Assignment 12", nullptr, nullptr);
    }

    VkInstance instance;
    void initVulkan() {
        /*
            Instance is connection bw app and vulkan library
        */
        createInstance();
    }

    void mainLoop() {
        //run until error or window closed
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents(); //check for errors or closed window
        }
    }

    void cleanup() {

        //destroy vulkan instance
        vkDestroyInstance(instance, nullptr);

        glfwDestroyWindow(window);
        glfwTerminate();
    }
    //up to here there were functions in the run() 


    void createInstance() {
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "A12";
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
        uint32_t extensionCount = 0;
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
};

int main() {
    Assignment12 app;

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}