//after selecting physical device, setup logical device to interface with it
#include "../Assignment13.h"
#include "physicalDevice.cpp" //for findQueueFamilies()
#include <set> //used for VkDeviceQueueCreateInfo

void Assignment13::createLogicalDevice() {
	QueueFamilyIndices indices = findQueueFamilies(physicalDevice);


	/*instead of this (1)
		VkDeviceQueueCreateInfo queueCreateInfo{};
		queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateInfo.queueFamilyIndex = indices.graphicsFamily.value();
		queueCreateInfo.queueCount = 1;*/

	/* this (1)
		* allows creation of presentation queue because
		* gives multiple vkdevice queue.. to create queue from
		* both families of struct QueueFamilyIndices*/
	
	std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
	std::set<uint32_t> uniqueQueueFamilies = { indices.graphicsFamily.value(), indices.presentFamily.value() };

	float queuePriority = 1.0f;
	for (uint32_t queueFamily : uniqueQueueFamilies) {
		VkDeviceQueueCreateInfo queueCreateInfo{};
		queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateInfo.queueFamilyIndex = queueFamily;
		queueCreateInfo.queueCount = 1;
		queueCreateInfo.pQueuePriorities = &queuePriority;
		queueCreateInfos.push_back(queueCreateInfo);
	}
	
	//CHECK
	//some lines missing in guide...
	//check https://vulkan-tutorial.com/code/05_window_surface.cpp
	//logical 
	VkPhysicalDeviceFeatures deviceFeatures{};


	//presentation
	VkDeviceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
	createInfo.pQueueCreateInfos = queueCreateInfos.data();

	vkGetDeviceQueue(device, indices.presentFamily.value(), 0, &presentQueue);
	//from logical
	/* no validationLayers variable found, this code is not strictly necessary
	createInfo.enabledExtensionCount = 0;

	if (enableValidationLayers) {
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		createInfo.ppEnabledLayerNames = validationLayers.data();
	}
	else {
		createInfo.enabledLayerCount = 0;
	}
	*/

	if (vkCreateDevice(physicalDevice, &createInfo, nullptr, &device) != VK_SUCCESS) {
		throw std::runtime_error("failed to create logical device!");
	}

	vkGetDeviceQueue(device, indices.graphicsFamily.value(), 0, &graphicsQueue);

	//now we can use graphics card!
}