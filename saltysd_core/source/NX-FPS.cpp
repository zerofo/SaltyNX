#include <switch_min.h>
#include "saltysd_ipc.h"
#include "saltysd_dynamic.h"
#include "saltysd_core.h"
#include "ltoa.h"
#include <cstdlib>
#include <cmath>
#include "lock.hpp"
#include <algorithm>

struct NVNTexture {
	char reserved[0x80];
};

struct NVNTextureView {
	char reserved[0x40];
};

struct NVNTextureBuilder {
	char reserved[0x80];
};

struct NVNWindow {
	char reserved[0x180];
};

struct NVNDevice {
	char reserved[0x3000];
};

typedef int NVNtextureFlags;
typedef int NVNtextureTarget;
typedef int NVNformat;
typedef int NVNmemoryPoolFlags;

struct NVNViewport {
	float x;
	float y;
	float width;
	float height;
};

struct VkViewport {
	float    x;
	float    y;
	float    width;
	float    height;
	float    minDepth;
	float    maxDepth;
};

struct glViewportArray {
	float x;
	float y;
	float width;
	float height;
};

typedef struct VkSwapchainCreateInfoKHR {
	int          sType;
	const void*  pNext;
	int          flags;
	void*        surface;
	uint32_t     minImageCount;
} VkSwapchainCreateInfoKHR;

typedef u64 (*nvnBootstrapLoader_0)(const char * nvnName);
typedef bool (*eglSwapBuffers_0)(const void* EGLDisplay, const void* EGLSurface);
typedef bool (*eglSwapInterval_0)(const void* EGLDisplay, int interval);
typedef void (*glViewport_0)(int x, int y, uint width, uint height);
typedef void (*glViewportArrayv_0)(uint firstViewport, uint viewportCount, const glViewportArray* pViewports);
typedef void (*glViewportArrayvNV_0)(uint firstViewport, uint viewportCount, const glViewportArray* pViewports);
typedef void (*glViewportArrayvOES_0)(uint firstViewport, uint viewportCount, const glViewportArray* pViewports);
typedef void (*glViewportIndexedf_0)(uint index, float x, float y, float width, float height);
typedef void (*glViewportIndexedfv_0)(uint index, const glViewportArray* pViewports);
typedef void (*glViewportIndexedfNV_0)(uint index, float x, float y, float width, float height);
typedef void (*glViewportIndexedfvNV_0)(uint index, const glViewportArray* pViewports);
typedef void (*glViewportIndexedfOES_0)(uint index, float x, float y, float width, float height);
typedef void (*glViewportIndexedfvOES_0)(uint index, const glViewportArray* pViewports);
typedef s32 (*vkQueuePresentKHR_0)(const void* vkQueue, const void* VkPresentInfoKHR);
typedef u64 (*_ZN2nn2os17ConvertToTimeSpanENS0_4TickE_0)(u64 tick);
typedef u64 (*_ZN2nn2os13GetSystemTickEv_0)();
typedef u64 (*_ZN2nn2os22GetSystemTickFrequencyEv_0)();
typedef u64 (*eglGetProcAddress_0)(const char* eglName);
typedef void* (*nvnCommandBufferSetRenderTargets_0)(const void* cmdBuf, int numTextures, const NVNTexture** texture, const NVNTextureView** textureView, const NVNTexture* depth, const NVNTextureView* depthView);
typedef void* (*nvnCommandBufferSetViewport_0)(const void* cmdBuf, int x, int y, int width, int height);
typedef void* (*nvnCommandBufferSetViewports_0)(void* cmdBuf, int start, int count, const NVNViewport* viewports);
typedef void* (*nvnCommandBufferSetDepthRange_0)(void* cmdBuf, float s0, float s1);
typedef u16 (*nvnTextureGetWidth_0)(const NVNTexture* texture);
typedef u16 (*nvnTextureGetHeight_0)(const NVNTexture* texture);
typedef u32 (*nvnTextureGetFormat_0)(const NVNTexture* texture);
typedef void* (*_vkGetInstanceProcAddr_0)(void* instance, const char* vkFunction);
typedef void* (*vkGetDeviceProcAddr_0)(void* device, const char* vkFunction);
typedef u32 (*_ZN2nn2ro12LookupSymbolEPmPKc_0)(uintptr_t* pOutAddress, const char* name);
typedef void (*vkCmdSetViewport_0)(void* commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports);
typedef void (*vkCmdSetViewportWithCount_0)(void* commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
typedef s32 (*vkCreateSwapchainKHR_0)(void* Device, const VkSwapchainCreateInfoKHR* pCreateInfo, const void* pAllocator, const void** pSwapchain);
typedef s32 (*vkGetSwapchainImagesKHR_0)(void* Device, void* VkSwapchainKHR, uint32_t* pSwapchainImageCount, int** pSwapchainImages);
typedef AppletFocusState (*GetCurrentFocusState_0)();

struct {
	uintptr_t nvnBootstrapLoader;
	uintptr_t eglSwapBuffers;
	uintptr_t eglSwapInterval;
	uintptr_t glViewport;
	uintptr_t glViewportArrayv;
	uintptr_t glViewportArrayvNV;
	uintptr_t glViewportArrayvOES;
	uintptr_t glViewportIndexedf;
	uintptr_t glViewportIndexedfv;
	uintptr_t glViewportIndexedfNV;
	uintptr_t glViewportIndexedfvNV;
	uintptr_t glViewportIndexedfOES;
	uintptr_t glViewportIndexedfvOES;
	uintptr_t vkQueuePresentKHR;
	uintptr_t nvSwapchainQueuePresentKHR;
	uintptr_t ConvertToTimeSpan;
	uintptr_t GetSystemTick;
	uintptr_t GetSystemTickFrequency;
	uintptr_t eglGetProcAddress;
	uintptr_t ReferSymbol;
	uintptr_t vkGetInstanceProcAddr;
	uintptr_t LookupSymbol;
	uintptr_t vkCmdSetViewport;
	uintptr_t vkCmdSetViewportWithCount;
	uintptr_t vkCreateSwapchainKHR;
	uintptr_t nvSwapchainCreateSwapchainKHR;
	uintptr_t nvSwapchainGetInstanceProcAddr;
	uintptr_t nvSwapchainGetDeviceProcAddr;
	uintptr_t vkGetDeviceProcAddr;

	uintptr_t nvnDeviceGetProcAddress;
	uintptr_t nvnQueuePresentTexture;

	uintptr_t nvnWindowSetPresentInterval;
	uintptr_t nvnWindowGetPresentInterval;
	uintptr_t nvnWindowBuilderSetTextures;
	uintptr_t nvnWindowAcquireTexture;
	uintptr_t nvnSyncWait;

	uintptr_t nvnWindowSetNumActiveTextures;
	uintptr_t nvnWindowInitialize;
	uintptr_t nvnTextureGetWidth;
	uintptr_t nvnTextureGetHeight;
	uintptr_t nvnTextureGetFormat;
	uintptr_t nvnCommandBufferSetRenderTargets;
	uintptr_t nvnCommandBufferSetViewport;
	uintptr_t nvnCommandBufferSetViewports;
	uintptr_t nvnCommandBufferSetDepthRange;
	uintptr_t vkGetSwapchainImagesKHR;
	uintptr_t nvSwapchainGetSwapchainImagesKHR;
	uintptr_t GetCurrentFocusState;
} Address_weaks;

struct nvnWindowBuilder {
	const char reserved[16];
	uint8_t numBufferedFrames;
};

ptrdiff_t SharedMemoryOffset = 1234;
uint8_t* configBuffer = 0;
size_t configSize = 0;
Result configRC = 1;

static uint32_t* sharedOperationMode = 0;

Result readConfig(const char* path, uint8_t** output_buffer) {
	FILE* patch_file = SaltySDCore_fopen(path, "rb");
	SaltySDCore_fseek(patch_file, 0, 2);
	configSize = SaltySDCore_ftell(patch_file);
	SaltySDCore_fseek(patch_file, 8, 0);
	uint32_t header_size = 0;
	SaltySDCore_fread(&header_size, 0x4, 1, patch_file);
	uint8_t* buffer = (uint8_t*)calloc(1, header_size);
	SaltySDCore_fseek(patch_file, 0, 0);
	SaltySDCore_fread(buffer, header_size, 1, patch_file);
	if (SaltySDCore_ftell(patch_file) != header_size || !LOCK::isValid(buffer, header_size)) {
		SaltySDCore_fclose(patch_file);
		free(buffer);
		return 0x1201;
	}
	if (LOCK::masterWrite) {
		Result ret = LOCK::applyMasterWrite(patch_file, header_size - 4);
		if (R_FAILED(ret))  {
			SaltySDCore_fclose(patch_file);
			return ret;
		}
		configSize = *(uint32_t*)(&(buffer[header_size - 4]));
	}
	free(buffer);
	buffer = (uint8_t*)calloc(1, configSize);
	SaltySDCore_fseek(patch_file, 0, 0);
	SaltySDCore_fread(buffer, configSize, 1, patch_file);
	SaltySDCore_fclose(patch_file);
	*output_buffer = buffer;
	return 0;
}

struct resolutionCalls {
	uint16_t width;
	uint16_t height;
	uint16_t calls;
};

bool resolutionLookup = false;

resolutionCalls m_resolutionRenderCalls[8] = {0};
resolutionCalls m_resolutionViewportCalls[8] = {0};

struct NxFpsSharedBlock {
	uint32_t MAGIC;
	uint8_t FPS;
	float FPSavg;
	bool pluginActive;
	uint8_t FPSlocked;
	uint8_t FPSmode;
	uint8_t ZeroSync;
	uint8_t patchApplied;
	uint8_t API;
	uint32_t FPSticks[10];
	uint8_t Buffers;
	uint8_t SetBuffers;
	uint8_t ActiveBuffers;
	uint8_t SetActiveBuffers;
	bool displaySync;
	resolutionCalls renderCalls[8];
	resolutionCalls viewportCalls[8];
	bool forceOriginalRefreshRate;
	bool dontForce60InDocked;
	bool forceSuspend;
	uint8_t currentRefreshRate;
} PACKED;

NxFpsSharedBlock* Shared = 0;

struct {
	uint8_t FPS = 0xFF;
	float FPSavg = 255;
	bool FPSmode = 0;
} Stats;

uint64_t systemtickfrequency = 19200000;
typedef void (*nvnQueuePresentTexture_0)(const void* _this, const void* unk2_1, int index);
typedef uintptr_t (*GetProcAddress)(const void* unk1_a, const char * nvnFunction_a);

bool changeFPS = false;
bool changedFPS = false;
typedef void (*nvnBuilderSetTextures_0)(const nvnWindowBuilder* nvnWindowBuilder, int buffers, const NVNTexture** texturesBuffer);
typedef void (*nvnWindowSetNumActiveTextures_0)(const NVNWindow* nvnWindow, int buffers);
typedef bool (*nvnWindowInitialize_0)(const NVNWindow* nvnWindow, const struct nvnWindowBuilder* windowBuilder);
typedef void* (*nvnWindowAcquireTexture_0)(const NVNWindow* nvnWindow, const void* nvnSync, const void* index);
typedef void (*nvnSetPresentInterval_0)(const NVNWindow* nvnWindow, int mode);
typedef int (*nvnGetPresentInterval_0)(const NVNWindow* nvnWindow);
typedef void* (*nvnSyncWait_0)(const void* _this, uint64_t timeout_ns);
void* WindowSync = 0;
uint64_t startFrameTick = 0;

enum {
	ZeroSyncType_None,
	ZeroSyncType_Soft,
	ZeroSyncType_Semi
};

inline void createBuildidPath(const uint64_t buildid, char* titleid, char* buffer) {
	strcpy(buffer, "sdmc:/switch/SaltySD/plugins/FPSLocker/patches/0");
	strcat(buffer, &titleid[0]);
	strcat(buffer, "/");
	ltoa(buildid, &titleid[0], 16);
	int zero_count = 16 - strlen(&titleid[0]);
	for (int i = 0; i < zero_count; i++) {
		strcat(buffer, "0");
	}
	strcat(buffer, &titleid[0]);
	strcat(buffer, ".bin");	
}

inline void CheckTitleID(char* buffer) {
    uint64_t titid = 0;
    svcGetInfo(&titid, InfoType_TitleId, CUR_PROCESS_HANDLE, 0);	
    ltoa(titid, buffer, 16);
}

inline uint64_t getMainAddress() {
	MemoryInfo memoryinfo = {0};
	u32 pageinfo = 0;

	uint64_t base_address = SaltySDCore_getCodeStart() + 0x4000;
	for (size_t i = 0; i < 3; i++) {
		Result rc = svcQueryMemory(&memoryinfo, &pageinfo, base_address);
		if (R_FAILED(rc)) return 0;
		if ((memoryinfo.addr == base_address) && (memoryinfo.perm & Perm_X))
			return base_address;
		base_address = memoryinfo.addr+memoryinfo.size;
	}

	return 0;
}

namespace NX_FPS_Math {
	uint8_t FPS_temp = 0;
	uint64_t starttick = 0;
	uint64_t starttick2 = 0;
	uint64_t frameend = 0;
	uint64_t frameavg = 0;
	uint8_t FPSlock = 0;
	int32_t FPStiming = 0;
	uint8_t FPStickItr = 0;
	uint8_t range = 0;
	
	bool FPSlock_delayed = false;
	bool old_force = false;
	uint32_t new_fpslock = 0;

	void PreFrame() {
		new_fpslock = (LOCK::overwriteRefreshRate ? LOCK::overwriteRefreshRate : (Shared -> FPSlocked));
		if (old_force != (Shared -> forceOriginalRefreshRate)) {
			if (*sharedOperationMode == 1 && !(Shared -> dontForce60InDocked))
				svcSleepThread(LOCK::DockedRefreshRateDelay);
			old_force = (Shared -> forceOriginalRefreshRate);
		}

		if ((FPStiming && !LOCK::blockDelayFPS && (new_fpslock && new_fpslock < (Shared -> currentRefreshRate)))) {
			if ((int32_t)(((_ZN2nn2os13GetSystemTickEv_0)(Address_weaks.GetSystemTick))() - frameend) < (FPStiming + (range * 20))) {
				FPSlock_delayed = true;
			}
			while ((int32_t)(((_ZN2nn2os13GetSystemTickEv_0)(Address_weaks.GetSystemTick))() - frameend) < (FPStiming + (range * 20))) {
				svcSleepThread(-2);
				svcSleepThread(10000);
			}
		}
	}

	void PostFrame() {
		uint64_t endtick = ((_ZN2nn2os13GetSystemTickEv_0)(Address_weaks.GetSystemTick))();
		uint64_t framedelta = endtick - frameend;

		Shared -> FPSticks[FPStickItr++] = framedelta;
		FPStickItr %= 10;
		
		frameavg = ((9*frameavg) + framedelta) / 10;
		Stats.FPSavg = systemtickfrequency / (float)frameavg;

		if (FPSlock_delayed && FPStiming) {
			if (Stats.FPSavg > ((float)new_fpslock)) {
				if (range < 200) {
					range++;
				}
			}
			else if ((std::lround(Stats.FPSavg) == new_fpslock) && (Stats.FPSavg < (float)new_fpslock)) {
				if (range > 0) {
					range--;
				}
			}
		}

		frameend = endtick;
		FPS_temp++;
		uint64_t deltatick = endtick - starttick;
		uint64_t deltatick2 = endtick - starttick2;
		if (deltatick2 > (systemtickfrequency / ((*sharedOperationMode == 1) ? 30 : 1))) {
			starttick2 = ((_ZN2nn2os13GetSystemTickEv_0)(Address_weaks.GetSystemTick))();
			LOCK::overwriteRefreshRate = 0;
			if (!configRC && FPSlock) {
				LOCK::applyPatch(configBuffer, FPSlock, (Shared -> currentRefreshRate));
			}
		}
		if (deltatick > systemtickfrequency) {
			starttick = ((_ZN2nn2os13GetSystemTickEv_0)(Address_weaks.GetSystemTick))();
			Stats.FPS = FPS_temp - 1;
			FPS_temp = 0;
			(Shared -> FPS) = Stats.FPS;
			if (!configRC && FPSlock) {
				(Shared -> patchApplied) = 1;
			}
			if (Shared -> forceSuspend) {
				while (((GetCurrentFocusState_0)(Address_weaks.GetCurrentFocusState))() == AppletFocusState_NotFocusedHomeSleep)
					svcSleepThread(16000000);
			}
		}

		if (LOCK::overwriteRefreshRate != 0) (Shared -> forceOriginalRefreshRate) = true;
		else (Shared -> forceOriginalRefreshRate) = false;

		(Shared -> FPSavg) = Stats.FPSavg;
		(Shared -> pluginActive) = true;

		if (!resolutionLookup && Shared -> renderCalls[0].calls == 0xFFFF) {
			resolutionLookup = true;
			Shared -> renderCalls[0].calls = 0;
		}
		if (resolutionLookup) {
			memcpy(Shared -> renderCalls, m_resolutionRenderCalls, sizeof(m_resolutionRenderCalls));
			memcpy(Shared -> viewportCalls, m_resolutionViewportCalls, sizeof(m_resolutionViewportCalls));
			memset(&m_resolutionRenderCalls, 0, sizeof(m_resolutionRenderCalls));
			memset(&m_resolutionViewportCalls, 0, sizeof(m_resolutionViewportCalls));
		}

	}

	template <typename T> void addResToViewports(T m_width, T m_height) {
		T ratio = (m_width * 10) / m_height;
		if (ratio >= (T)12 && ratio <= (T)18) {
			uint16_t width = (uint16_t)m_width;
			uint16_t height = (uint16_t)m_height;
			for (size_t i = 0; i < 8; i++) {
				if (width == m_resolutionViewportCalls[i].width) {
					m_resolutionViewportCalls[i].calls++;
					break;
				}
				if (m_resolutionViewportCalls[i].width == 0) {
					m_resolutionViewportCalls[i].width = width;
					m_resolutionViewportCalls[i].height = height;
					m_resolutionViewportCalls[i].calls = 1;
					break;
				}
			}			
		}		
	}

	template <typename T> void addResToRender(T m_width, T m_height) {
		T ratio = (m_width * 10) / m_height;
		if (ratio >= (T)12 && ratio <= (T)18) {
			uint16_t width = (uint16_t)m_width;
			uint16_t height = (uint16_t)m_height;
			for (size_t i = 0; i < 8; i++) {
				if (width == m_resolutionRenderCalls[i].width) {
					m_resolutionRenderCalls[i].calls++;
					break;
				}
				if (m_resolutionRenderCalls[i].width == 0) {
					m_resolutionRenderCalls[i].width = width;
					m_resolutionRenderCalls[i].height = height;
					m_resolutionRenderCalls[i].calls = 1;
					break;
				}
			}			
		}		
	}
}

namespace vk {

	int32_t QueuePresent (const void* VkQueue, const void* VkPresentInfoKHR);
	int32_t CreateSwapchain(void* Device, VkSwapchainCreateInfoKHR* pCreateInfo, const void* pAllocator, const void** pSwapchain);
	void* GetDeviceProcAddr(void* device, const char* vkFunction);
	void* GetInstanceProcAddr(void* instance, const char* vkFunction);

	void CmdSetViewport(void* commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) {
		if (resolutionLookup) for (uint i = firstViewport; i < firstViewport+viewportCount; i++) {
			if (pViewports[i].height > 1.f && pViewports[i].width > 1.f && pViewports[i].x == 0.f && pViewports[i].y == 0.f) {
				NX_FPS_Math::addResToViewports(pViewports[i].width, pViewports[i].height);
			}
		}
		return ((vkCmdSetViewport_0)(Address_weaks.vkCmdSetViewport))(commandBuffer, firstViewport, viewportCount, pViewports);
	}

	void CmdSetViewportWithCount(void* commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) {
		if (resolutionLookup) for (uint i = 0; i < viewportCount; i++) {
			if (pViewports[i].height > 1.f && pViewports[i].width > 1.f && pViewports[i].x == 0.f && pViewports[i].y == 0.f) {
				NX_FPS_Math::addResToViewports(pViewports[i].width, pViewports[i].height);
			}
		}
		return ((vkCmdSetViewportWithCount_0)(Address_weaks.vkCmdSetViewportWithCount))(commandBuffer, viewportCount, pViewports);
	}

	namespace Common {
		int32_t QueuePresent(const void* VkQueue_T, const void* VkPresentInfoKHR, uintptr_t pointer) {
			static bool frame_block = false;

			if (frame_block == true)
				return ((vkQueuePresentKHR_0)(pointer))(VkQueue_T, VkPresentInfoKHR);
			if (!NX_FPS_Math::starttick) {
				(Shared -> API) = 3;
				NX_FPS_Math::starttick = ((_ZN2nn2os13GetSystemTickEv_0)(Address_weaks.GetSystemTick))();
				NX_FPS_Math::starttick2 = NX_FPS_Math::starttick;
			}
			
			NX_FPS_Math::PreFrame();
			frame_block = true;
			int32_t vulkanResult = ((vkQueuePresentKHR_0)(pointer))(VkQueue_T, VkPresentInfoKHR);
			frame_block = false;
			if (vulkanResult >= 0) NX_FPS_Math::PostFrame();

			if (!NX_FPS_Math::new_fpslock) {
				NX_FPS_Math::FPStiming = 0;
				NX_FPS_Math::FPSlock = 0;
				changeFPS = false;
			}
			else {
				changeFPS = true;
				NX_FPS_Math::FPSlock = (Shared -> FPSlocked);
				if (NX_FPS_Math::new_fpslock != ((Shared -> currentRefreshRate) ? (Shared -> currentRefreshRate) : 60))
					NX_FPS_Math::FPStiming = (systemtickfrequency/NX_FPS_Math::new_fpslock) - 6000;
				else NX_FPS_Math::FPStiming = 0;
			}
			
			return vulkanResult;
		}

		int32_t CreateSwapchain(void* Device, VkSwapchainCreateInfoKHR* pCreateInfo, const void* pAllocator, const void** pSwapchain, uintptr_t pointer) {
			if ((Shared -> SetBuffers) > 0) {
				pCreateInfo -> minImageCount = (Shared -> SetBuffers);
			}
			int32_t vulkanResult = ((vkCreateSwapchainKHR_0)(pointer))(Device, (const VkSwapchainCreateInfoKHR*)pCreateInfo, pAllocator, pSwapchain);
			if (vulkanResult >= 0) {
				uint32_t numBuffers = 0;
				((vkGetSwapchainImagesKHR_0)(Address_weaks.vkGetSwapchainImagesKHR))(Device, (void*)pSwapchain[0], &numBuffers, nullptr);
				(Shared -> Buffers) = numBuffers;
			}
			return vulkanResult;
		}

		void* GetDeviceProcAddr(void* device, const char* vkFunction, uintptr_t pointer) {
			uintptr_t address = (uintptr_t)((vkGetDeviceProcAddr_0)(pointer))(device, vkFunction);
			if (!strcmp("vkQueuePresentKHR", vkFunction)) {
				if (!Address_weaks.vkQueuePresentKHR) Address_weaks.vkQueuePresentKHR = address;
				return (void*)&vk::QueuePresent;
			}
			if (!strcmp("vkGetDeviceProcAddr", vkFunction)) {
				if (!Address_weaks.vkGetDeviceProcAddr) Address_weaks.vkGetDeviceProcAddr = address;
				return (void*)pointer;
			}
			if (!strcmp("vkCmdSetViewport", vkFunction)) {
				if (!Address_weaks.vkCmdSetViewport) Address_weaks.vkCmdSetViewport = address;
				return (void*)&vk::CmdSetViewport;
			}
			if (!strcmp("vkCmdSetViewportWithCount", vkFunction)) {
				if (!Address_weaks.vkCmdSetViewportWithCount) Address_weaks.vkCmdSetViewportWithCount = address;
				return (void*)&vk::CmdSetViewportWithCount;
			}
			if (!strcmp("vkCreateSwapchainKHR", vkFunction)) {
				if (!Address_weaks.vkCreateSwapchainKHR) Address_weaks.vkCreateSwapchainKHR = address;
				return (void*)&vk::CreateSwapchain;
			}
			if (!strcmp("vkGetSwapchainImagesKHR", vkFunction)) {
				if (!Address_weaks.vkGetSwapchainImagesKHR) Address_weaks.vkGetSwapchainImagesKHR = address;
				return (void*)Address_weaks.vkGetSwapchainImagesKHR;
			}
			return (void*)address;
		}

		void* GetInstanceProcAddr(void* instance, const char* vkFunction, uintptr_t pointer) {
			uintptr_t address = (uintptr_t)((_vkGetInstanceProcAddr_0)(pointer))(instance, vkFunction);
			if (!strcmp("vkQueuePresentKHR", vkFunction)) {
				if (!Address_weaks.vkQueuePresentKHR) Address_weaks.vkQueuePresentKHR = address;
				return (void*)&vk::QueuePresent;
			}
			if (!strcmp("vkGetDeviceProcAddr", vkFunction)) {
				if (!Address_weaks.vkGetDeviceProcAddr) Address_weaks.vkGetDeviceProcAddr = address;
				return (void*)&vk::GetDeviceProcAddr;
			}
			if (!strcmp("vkCreateSwapchainKHR", vkFunction)) {
				if (!Address_weaks.vkCreateSwapchainKHR) Address_weaks.vkCreateSwapchainKHR = address;
				return (void*)&vk::CreateSwapchain;
			}
			if (!strcmp("vkGetSwapchainImagesKHR", vkFunction)) {
				if (!Address_weaks.vkGetSwapchainImagesKHR) Address_weaks.vkGetSwapchainImagesKHR = address;
				return (void*)Address_weaks.vkGetSwapchainImagesKHR;
			}
			if (!strcmp("vkCmdSetViewport", vkFunction)) {
				if (!Address_weaks.vkCmdSetViewport) Address_weaks.vkCmdSetViewport = address;
				return (void*)&vk::CmdSetViewport;
			}
			if (!strcmp("vkCmdSetViewportWithCount", vkFunction)) {
				if (!Address_weaks.vkCmdSetViewportWithCount) Address_weaks.vkCmdSetViewportWithCount = address;
				return (void*)&vk::CmdSetViewportWithCount;
			}
			return (void*)address;
		}
	}

	namespace nvSwapchain { 
		int32_t QueuePresent (const void* VkQueue_T, const void* VkPresentInfoKHR) {
			return vk::Common::QueuePresent(VkQueue_T, VkPresentInfoKHR, Address_weaks.nvSwapchainQueuePresentKHR);
		}

		int32_t CreateSwapchain(void* Device, VkSwapchainCreateInfoKHR* pCreateInfo, const void* pAllocator, const void** pSwapchain) {
			return vk::Common::CreateSwapchain(Device, pCreateInfo, pAllocator, pSwapchain, Address_weaks.nvSwapchainCreateSwapchainKHR);
		}

		void* GetDeviceProcAddr(void* device, const char* vkFunction) {
			return vk::Common::GetDeviceProcAddr(device, vkFunction, Address_weaks.nvSwapchainGetDeviceProcAddr);
		}

		void* GetInstanceProcAddr(void* instance, const char* vkFunction) {
			return vk::Common::GetInstanceProcAddr(instance, vkFunction, Address_weaks.nvSwapchainGetInstanceProcAddr);
		}
	}

	int32_t QueuePresent (const void* VkQueue, const void* VkPresentInfoKHR) {
		return vk::Common::QueuePresent(VkQueue, VkPresentInfoKHR, Address_weaks.vkQueuePresentKHR);
	}

	int32_t CreateSwapchain(void* Device, VkSwapchainCreateInfoKHR* pCreateInfo, const void* pAllocator, const void** pSwapchain) {
		return vk::Common::CreateSwapchain(Device, pCreateInfo, pAllocator, pSwapchain, Address_weaks.vkCreateSwapchainKHR);
	}

	void* GetDeviceProcAddr(void* device, const char* vkFunction) {
		return vk::Common::GetDeviceProcAddr(device, vkFunction, Address_weaks.vkGetDeviceProcAddr);
	}

	void* GetInstanceProcAddr(void* instance, const char* vkFunction) {
		return vk::Common::GetInstanceProcAddr(instance, vkFunction, Address_weaks.vkGetInstanceProcAddr);
	}

	u32 LookupSymbol(uintptr_t* pOutAddress, const char* name) {
		if (!strcmp("vkGetInstanceProcAddr", name)) {
			((_ZN2nn2ro12LookupSymbolEPmPKc_0)(Address_weaks.LookupSymbol))(&Address_weaks.vkGetInstanceProcAddr, name);
			*pOutAddress = (uintptr_t)&GetInstanceProcAddr;
			return 0;
		}
		if (!strcmp("vkGetDeviceProcAddr", name)) {
			((_ZN2nn2ro12LookupSymbolEPmPKc_0)(Address_weaks.LookupSymbol))(&Address_weaks.vkGetDeviceProcAddr, name);
			*pOutAddress = (uintptr_t)&GetDeviceProcAddr;
			return 0;
		}
		return ((_ZN2nn2ro12LookupSymbolEPmPKc_0)(Address_weaks.LookupSymbol))(pOutAddress, name);
	}
}

namespace EGL {

	#define EGL_MIN_SWAP_INTERVAL 0
	#define EGL_MAX_SWAP_INTERVAL 4

	bool Interval(const void* EGLDisplay, int interval) {
		bool result = false;
		if (!changeFPS) {
			result = ((eglSwapInterval_0)(Address_weaks.eglSwapInterval))(EGLDisplay, interval);
			changedFPS = false;
			if (result == true) {
				(Shared -> FPSmode) = std::clamp(interval, EGL_MIN_SWAP_INTERVAL, EGL_MAX_SWAP_INTERVAL);
			}
		}
		else if (interval < 0) {
			interval *= -1;
			if ((Shared -> FPSmode) != interval) {
				result = ((eglSwapInterval_0)(Address_weaks.eglSwapInterval))(EGLDisplay, interval);
				if (result == true)
					(Shared -> FPSmode) = interval;
			}
			changedFPS = true;
		}
		return result;
	}

	bool Swap (const void* EGLDisplay, const void* EGLSurface) {

		if (!NX_FPS_Math::starttick) {
			(Shared -> API) = 2;
			NX_FPS_Math::starttick = ((_ZN2nn2os13GetSystemTickEv_0)(Address_weaks.GetSystemTick))();
			NX_FPS_Math::starttick2 = NX_FPS_Math::starttick;
		}

		NX_FPS_Math::PreFrame();
		
		bool result = ((eglSwapBuffers_0)(Address_weaks.eglSwapBuffers))(EGLDisplay, EGLSurface);
		if (result == true)
			 NX_FPS_Math::PostFrame();

		if (!NX_FPS_Math::new_fpslock) {
			NX_FPS_Math::FPStiming = 0;
			NX_FPS_Math::FPSlock = 0;
			changeFPS = false;
		}
		else {
			changeFPS = true;
			NX_FPS_Math::FPSlock = (Shared -> FPSlocked);
			if (NX_FPS_Math::new_fpslock <= ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 4) : 15)) {
				if ((Shared -> FPSmode) != 4)
					EGL::Interval(EGLDisplay, -4);
				if (NX_FPS_Math::new_fpslock != ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 4) : 15)) {
					NX_FPS_Math::FPStiming = (systemtickfrequency/NX_FPS_Math::new_fpslock) - 6000;
				}
				else NX_FPS_Math::FPStiming = 0;			
			}
			else if (NX_FPS_Math::new_fpslock <= ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 3) : 20)) {
				if ((Shared -> FPSmode) != 3)
					EGL::Interval(EGLDisplay, -3);
				if (NX_FPS_Math::new_fpslock != ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 3) : 20)) {
					NX_FPS_Math::FPStiming = (systemtickfrequency/NX_FPS_Math::new_fpslock) - 6000;
				}
				else NX_FPS_Math::FPStiming = 0;			
			}
			else if (NX_FPS_Math::new_fpslock <= ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 2) : 30)) {
				if ((Shared -> FPSmode) != 2)
					EGL::Interval(EGLDisplay, -2);
				if (NX_FPS_Math::new_fpslock != ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 2) : 30)) {
					NX_FPS_Math::FPStiming = (systemtickfrequency/NX_FPS_Math::new_fpslock) - 6000;
				}
				else NX_FPS_Math::FPStiming = 0;			
			}
			else if (NX_FPS_Math::new_fpslock > ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 2) : 30)) {
				if ((Shared -> FPSmode) != 1)
					EGL::Interval(EGLDisplay, -1);
				if (NX_FPS_Math::new_fpslock != ((Shared -> currentRefreshRate) ? (Shared -> currentRefreshRate) : 60)) {
					NX_FPS_Math::FPStiming = (systemtickfrequency/NX_FPS_Math::new_fpslock) - 6000;
				}
				else NX_FPS_Math::FPStiming = 0;
			}
		}

		return result;
	}

	namespace Common {
		void ViewportArrayv(uint firstViewport, uint viewportCount, const glViewportArray* pViewports, uintptr_t pointer) {
			if (resolutionLookup) for (uint i = firstViewport; i < firstViewport+viewportCount; i++) {
				if (pViewports[i].height > 1.f && pViewports[i].width > 1.f && pViewports[i].x == 0.f && pViewports[i].y == 0.f) {
					NX_FPS_Math::addResToViewports(pViewports[i].width, pViewports[i].height);
				}
			}
			return ((glViewportArrayv_0)(pointer))(firstViewport, viewportCount, pViewports);
		}

		void ViewportIndexedf(uint index, float x, float y, float width, float height, uintptr_t pointer) {
			if (resolutionLookup && height > 1.f && width > 1.f && !x && !y) {
				NX_FPS_Math::addResToViewports(width, height);
			}
			return ((glViewportIndexedf_0)(pointer))(index, x, y, width, height);
		}

		void ViewportIndexedfv(uint i, const glViewportArray* pViewports, uintptr_t pointer) {
			if (resolutionLookup) {
				if (pViewports[i].height > 1.f && pViewports[i].width > 1.f && pViewports[i].x == 0.f && pViewports[i].y == 0.f) {
					NX_FPS_Math::addResToViewports(pViewports[i].width, pViewports[i].height);
				}
			}
			return ((glViewportIndexedfv_0)(pointer))(i, pViewports);
		}
	}

	void Viewport(int x, int y, uint width, uint height) {
		if (resolutionLookup && height > 1 && width > 1 && !x && !y) {
			NX_FPS_Math::addResToViewports(width, height);
		}
		return ((glViewport_0)(Address_weaks.glViewport))(x, y, width, height);
	}

	
	void ViewportArrayv(uint firstViewport, uint viewportCount, const glViewportArray* pViewports) {
		return EGL::Common::ViewportArrayv(firstViewport, viewportCount, pViewports, Address_weaks.glViewportArrayv);
	}

	void ViewportArrayvNV(uint firstViewport, uint viewportCount, const glViewportArray* pViewports) {
		return EGL::Common::ViewportArrayv(firstViewport, viewportCount, pViewports, Address_weaks.glViewportArrayvNV);
	}

	void ViewportArrayvOES(uint firstViewport, uint viewportCount, const glViewportArray* pViewports) {
		return EGL::Common::ViewportArrayv(firstViewport, viewportCount, pViewports, Address_weaks.glViewportArrayvOES);
	}

	void ViewportIndexedf(uint index, float x, float y, float width, float height) {
		return EGL::Common::ViewportIndexedf(index, x, y, width, height, Address_weaks.glViewportIndexedf);
	}

	void ViewportIndexedfNV(uint index, float x, float y, float width, float height) {
		return EGL::Common::ViewportIndexedf(index, x, y, width, height, Address_weaks.glViewportIndexedfNV);
	}

	void ViewportIndexedfOES(uint index, float x, float y, float width, float height) {
		return EGL::Common::ViewportIndexedf(index, x, y, width, height, Address_weaks.glViewportIndexedfOES);
	}

	void ViewportIndexedfv(uint i, const glViewportArray* pViewports) {
		return EGL::Common::ViewportIndexedfv(i, pViewports, Address_weaks.glViewportIndexedfv);
	}

	void ViewportIndexedfvNV(uint i, const glViewportArray* pViewports) {
		return EGL::Common::ViewportIndexedfv(i, pViewports, Address_weaks.glViewportIndexedfvNV);
	}

	void ViewportIndexedfvOES(uint i, const glViewportArray* pViewports) {
		return EGL::Common::ViewportIndexedfv(i, pViewports, Address_weaks.glViewportIndexedfvOES);
	}

	uintptr_t GetProc(const char* eglName) {
		uintptr_t address = ((eglGetProcAddress_0)(Address_weaks.eglGetProcAddress))(eglName);
		if (!strcmp(eglName, "eglSwapInterval")) {
			if (!Address_weaks.eglSwapInterval) Address_weaks.eglSwapInterval = address;
			return (uintptr_t)&Interval;
		}
		else if (!strcmp(eglName, "eglSwapBuffers")) {
			if (!Address_weaks.eglSwapBuffers) Address_weaks.eglSwapBuffers = address;
			return (uintptr_t)&Swap;
		}
		else if (!strcmp(eglName, "glViewport")) {
			if (!Address_weaks.glViewport) Address_weaks.glViewport = address;
			return (uintptr_t)&Viewport;
		}
		else if (!strcmp(eglName, "glViewportArrayv")) {
			if (!Address_weaks.glViewportArrayv) Address_weaks.glViewportArrayv = address;
			return (uintptr_t)&ViewportArrayv;
		}
		else if (!strcmp(eglName, "glViewportArrayvNV")) {
			if (!Address_weaks.glViewportArrayvNV) Address_weaks.glViewportArrayvNV = address;
			return (uintptr_t)&ViewportArrayvNV;
		}
		else if (!strcmp(eglName, "glViewportArrayvOES")) {
			if (!Address_weaks.glViewportArrayvOES) Address_weaks.glViewportArrayvOES = address;
			return (uintptr_t)&ViewportArrayvOES;
		}
		else if (!strcmp(eglName, "glViewportIndexedf")) {
			if (!Address_weaks.glViewportIndexedf) Address_weaks.glViewportIndexedf = address;
			return (uintptr_t)&ViewportIndexedf;
		}
		else if (!strcmp(eglName, "glViewportIndexedfNV")) {
			if (!Address_weaks.glViewportIndexedfNV) Address_weaks.glViewportIndexedfNV = address;
			return (uintptr_t)&ViewportIndexedfNV;
		}
		else if (!strcmp(eglName, "glViewportIndexedfOES")) {
			if (!Address_weaks.glViewportIndexedfOES) Address_weaks.glViewportIndexedfOES = address;
			return (uintptr_t)&ViewportIndexedfOES;
		}
		else if (!strcmp(eglName, "glViewportIndexedfv")) {
			if (!Address_weaks.glViewportIndexedfv) Address_weaks.glViewportIndexedfv = address;
			return (uintptr_t)&ViewportIndexedfv;
		}
		else if (!strcmp(eglName, "glViewportIndexedfvNV")) {
			if (!Address_weaks.glViewportIndexedfvNV) Address_weaks.glViewportIndexedfvNV = address;
			return (uintptr_t)&ViewportIndexedfvNV;
		}
		else if (!strcmp(eglName, "glViewportIndexedfvOES")) {
			if (!Address_weaks.glViewportIndexedfvOES) Address_weaks.glViewportIndexedfvOES = address;
			return (uintptr_t)&ViewportIndexedfvOES;
		}
		return address;
	}
}

namespace NVN {
	bool WindowInitialize(const NVNWindow* nvnWindow, struct nvnWindowBuilder* windowBuilder) {
		if (!(Shared -> Buffers)) {
			(Shared -> Buffers) = windowBuilder -> numBufferedFrames;
			if ((Shared -> SetBuffers) >= 2 && (Shared -> SetBuffers) <= windowBuilder -> numBufferedFrames) {
				windowBuilder -> numBufferedFrames = (Shared -> SetBuffers);
			}
			(Shared -> ActiveBuffers) = windowBuilder -> numBufferedFrames;	
		}
		return ((nvnWindowInitialize_0)(Address_weaks.nvnWindowInitialize))(nvnWindow, windowBuilder);
	}

	void WindowBuilderSetTextures(const nvnWindowBuilder* nvnWindowBuilder, int numBufferedFrames, const NVNTexture** nvnTextures) {
		(Shared -> Buffers) = numBufferedFrames;
		if ((Shared -> SetBuffers) >= 2 && (Shared -> SetBuffers) <= numBufferedFrames) {
			numBufferedFrames = (Shared -> SetBuffers);
		}
		(Shared -> ActiveBuffers) = numBufferedFrames;
		return ((nvnBuilderSetTextures_0)(Address_weaks.nvnWindowBuilderSetTextures))(nvnWindowBuilder, numBufferedFrames, nvnTextures);
	}

	void WindowSetNumActiveTextures(const NVNWindow* nvnWindow, int numBufferedFrames) {
		(Shared -> SetActiveBuffers) = numBufferedFrames;
		if ((Shared -> SetBuffers) >= 2 && (Shared -> SetBuffers) <= (Shared -> Buffers)) {
			numBufferedFrames = (Shared -> SetBuffers);
		}
		(Shared -> ActiveBuffers) = numBufferedFrames;
		return ((nvnWindowSetNumActiveTextures_0)(Address_weaks.nvnWindowSetNumActiveTextures))(nvnWindow, numBufferedFrames);
	}

	void SetPresentInterval(const NVNWindow* nvnWindow, int mode) {
		if (mode < 0) {
			mode *= -1;
			if ((Shared -> FPSmode) != mode) {
				((nvnSetPresentInterval_0)(Address_weaks.nvnWindowSetPresentInterval))(nvnWindow, mode);
				(Shared -> FPSmode) = mode;
			}
			changedFPS = true;
		}
		else if (!changeFPS) {
			((nvnSetPresentInterval_0)(Address_weaks.nvnWindowSetPresentInterval))(nvnWindow, mode);
			changedFPS = false;
			(Shared -> FPSmode) = mode;
		}
		return;
	}

	void* SyncWait0(const void* _this, uint64_t timeout_ns) {
		uint64_t endFrameTick = ((_ZN2nn2os13GetSystemTickEv_0)(Address_weaks.GetSystemTick))();
		if (_this == WindowSync && (Shared -> ActiveBuffers) == 2) {
			if ((Shared -> ZeroSync) == ZeroSyncType_Semi) {
				u64 FrameTarget = (systemtickfrequency/60) - 8000;
				s64 new_timeout = (FrameTarget - (endFrameTick - startFrameTick)) - (systemtickfrequency / 1000);
				if ((Shared -> FPSlocked) == 60) {
					new_timeout = (systemtickfrequency/101) - (endFrameTick - startFrameTick);
				}
				if (new_timeout > 0) {
					timeout_ns = ((_ZN2nn2os17ConvertToTimeSpanENS0_4TickE_0)(Address_weaks.ConvertToTimeSpan))(new_timeout);
				}
				else timeout_ns = 0;
			}
			else if ((Shared -> ZeroSync) == ZeroSyncType_Soft) 
				timeout_ns = 0;
		}
		return ((nvnSyncWait_0)(Address_weaks.nvnSyncWait))(_this, timeout_ns);
	}

	void PresentTexture(const void* _this, const NVNWindow* nvnWindow, int index) {

		static int last_index = 0;
		if (last_index == index) {
			return ((nvnQueuePresentTexture_0)(Address_weaks.nvnQueuePresentTexture))(_this, nvnWindow, index);
		}
		//Initialize time calculation;
		if (!NX_FPS_Math::starttick) {
			NX_FPS_Math::starttick = ((_ZN2nn2os13GetSystemTickEv_0)(Address_weaks.GetSystemTick))();
			NX_FPS_Math::starttick2 = NX_FPS_Math::starttick;
			(Shared -> FPSmode) = (uint8_t)((nvnGetPresentInterval_0)(Address_weaks.nvnWindowGetPresentInterval))(nvnWindow);
		}
		NX_FPS_Math::PreFrame();
		((nvnQueuePresentTexture_0)(Address_weaks.nvnQueuePresentTexture))(_this, nvnWindow, index);
		NX_FPS_Math::PostFrame();
		last_index = index;

		(Shared -> FPSmode) = (uint8_t)((nvnGetPresentInterval_0)(Address_weaks.nvnWindowGetPresentInterval))(nvnWindow);

		if (!NX_FPS_Math::new_fpslock) {
			NX_FPS_Math::FPStiming = 0;
			NX_FPS_Math::FPSlock = 0;
			changeFPS = false;
		}
		else {
			changeFPS = true;
			NX_FPS_Math::FPSlock = (Shared -> FPSlocked);
			if (NX_FPS_Math::new_fpslock <= ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 4) : 15)) {
				if (((nvnGetPresentInterval_0)(Address_weaks.nvnWindowGetPresentInterval))(nvnWindow) != 4)
					NVN::SetPresentInterval(nvnWindow, -4);
				if ((NX_FPS_Math::new_fpslock != ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 4) : 15))
				|| (Shared -> ZeroSync)) {
					NX_FPS_Math::FPStiming = (systemtickfrequency/NX_FPS_Math::new_fpslock) - 6000;
					if (NX_FPS_Math::new_fpslock == ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 4) : 15)) {
						NX_FPS_Math::FPStiming -= 2000;
					}
				}
				else NX_FPS_Math::FPStiming = 0;			
			}
			else if (NX_FPS_Math::new_fpslock <= ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 3) : 20)) {
				if (((nvnGetPresentInterval_0)(Address_weaks.nvnWindowGetPresentInterval))(nvnWindow) != 3)
					NVN::SetPresentInterval(nvnWindow, -3);
				if ((NX_FPS_Math::new_fpslock != ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 3) : 20))
				|| (Shared -> ZeroSync)) {
					NX_FPS_Math::FPStiming = (systemtickfrequency/NX_FPS_Math::new_fpslock) - 6000;
					if (NX_FPS_Math::new_fpslock == ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 3) : 20)) {
						NX_FPS_Math::FPStiming -= 2000;
					}
				}
				else NX_FPS_Math::FPStiming = 0;			
			}
			else if (NX_FPS_Math::new_fpslock <= ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 2) : 30)) {
				if (((nvnGetPresentInterval_0)(Address_weaks.nvnWindowGetPresentInterval))(nvnWindow) != 2)
					NVN::SetPresentInterval(nvnWindow, -2);
				if (NX_FPS_Math::new_fpslock != ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 2) : 30)
				|| (Shared -> ZeroSync)) {
					NX_FPS_Math::FPStiming = (systemtickfrequency/NX_FPS_Math::new_fpslock) - 6000;
					if (NX_FPS_Math::new_fpslock == ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 2) : 30)) {
						NX_FPS_Math::FPStiming -= 2000;
					}
				}
				else NX_FPS_Math::FPStiming = 0;			
			}
			else if (NX_FPS_Math::new_fpslock > ((Shared -> currentRefreshRate) ? ((Shared -> currentRefreshRate) / 2) : 30)) {
				if (((nvnGetPresentInterval_0)(Address_weaks.nvnWindowGetPresentInterval))(nvnWindow) != 1) {
					NVN::SetPresentInterval(nvnWindow, -2); //This allows in game with glitched interval to unlock 60 FPS, f.e. WRC Generations
					NVN::SetPresentInterval(nvnWindow, -1);
				}
				if ((NX_FPS_Math::new_fpslock != ((Shared -> currentRefreshRate) ? (Shared -> currentRefreshRate) : 60))
				|| (Shared -> ZeroSync)) {
					NX_FPS_Math::FPStiming = (systemtickfrequency/NX_FPS_Math::new_fpslock) - 6000;
					if (NX_FPS_Math::new_fpslock == ((Shared -> currentRefreshRate) ? (Shared -> currentRefreshRate) : 60)) {
						NX_FPS_Math::FPStiming -= 2000;
					}
				}
				else NX_FPS_Math::FPStiming = 0;
			}
		}
		
		return;
	}

	void* AcquireTexture(const NVNWindow* nvnWindow, const void* nvnSync, const int* index) {
		if (WindowSync != nvnSync) {
			WindowSync = (void*)nvnSync;
		}
		void* ret = ((nvnWindowAcquireTexture_0)(Address_weaks.nvnWindowAcquireTexture))(nvnWindow, nvnSync, index);
		startFrameTick = ((_ZN2nn2os13GetSystemTickEv_0)(Address_weaks.GetSystemTick))();
		return ret;
	}

	struct nvnCommandBuffer {
		char reserved[0x80];
	};

	void* CommandBufferSetViewports(nvnCommandBuffer* cmdBuf, int start, int count, NVNViewport* viewports) {
		if (resolutionLookup) for (int i = start; i < start+count; i++) {
			if (viewports[i].height > 1.f && viewports[i].width > 1.f && viewports[i].x == 0.f && viewports[i].y == 0.f) {
				NX_FPS_Math::addResToViewports(viewports[i].width, viewports[i].height);
			}
		}
		return ((nvnCommandBufferSetViewports_0)(Address_weaks.nvnCommandBufferSetViewports))(cmdBuf, start, count, viewports);
	}

	void* CommandBufferSetViewport(const nvnCommandBuffer* cmdBuf, int x, int y, int width, int height) {
		if (resolutionLookup && height > 1 && width > 1 && !x && !y) {
			NX_FPS_Math::addResToViewports(width, height);
		}
		return ((nvnCommandBufferSetViewport_0)(Address_weaks.nvnCommandBufferSetViewport))(cmdBuf, x, y, width, height);
	}

	void* CommandBufferSetRenderTargets(const nvnCommandBuffer* cmdBuf, int numTextures, const NVNTexture** texture, const NVNTextureView** textureView, const NVNTexture* depthTexture, const NVNTextureView* depthView) {
		if (texture != NULL && depthTexture != NULL) {
			if (resolutionLookup) {
				uint16_t depth_width = ((nvnTextureGetWidth_0)(Address_weaks.nvnTextureGetWidth))(depthTexture);
				uint16_t depth_height = ((nvnTextureGetHeight_0)(Address_weaks.nvnTextureGetHeight))(depthTexture);
				int depth_format = ((nvnTextureGetFormat_0)(Address_weaks.nvnTextureGetFormat))(depthTexture);
				if (depth_width > 1 && depth_height > 1 && (depth_format >= 51 && depth_format <= 54)) {
					NX_FPS_Math::addResToRender(depth_width, depth_height);
				}
			}
		}
		return ((nvnCommandBufferSetRenderTargets_0)(Address_weaks.nvnCommandBufferSetRenderTargets))(cmdBuf, numTextures, texture, textureView, depthTexture, depthView);
	}

	uintptr_t GetProcAddress0 (NVNDevice* nvnDevice, const char* nvnFunction) {
		uintptr_t address = ((GetProcAddress)(Address_weaks.nvnDeviceGetProcAddress))(nvnDevice, nvnFunction);
		if (!strcmp("nvnDeviceGetProcAddress", nvnFunction))
			return (uintptr_t)&NVN::GetProcAddress0;
		else if (!strcmp("nvnQueuePresentTexture", nvnFunction)) {
			Address_weaks.nvnQueuePresentTexture = address;
			return (uintptr_t)&NVN::PresentTexture;
		}
		else if (!strcmp("nvnWindowAcquireTexture", nvnFunction)) {
			Address_weaks.nvnWindowAcquireTexture = address;
			return (uintptr_t)&NVN::AcquireTexture;
		}
		else if (!strcmp("nvnWindowSetPresentInterval", nvnFunction)) {
			Address_weaks.nvnWindowSetPresentInterval = address;
			return (uintptr_t)&NVN::SetPresentInterval;
		}
		else if (!strcmp("nvnWindowGetPresentInterval", nvnFunction)) {
			Address_weaks.nvnWindowGetPresentInterval = address;
		}
		else if (!strcmp("nvnWindowSetNumActiveTextures", nvnFunction)) {
			Address_weaks.nvnWindowSetNumActiveTextures = address;
			return (uintptr_t)&NVN::WindowSetNumActiveTextures;
		}
		else if (!strcmp("nvnWindowBuilderSetTextures", nvnFunction)) {
			Address_weaks.nvnWindowBuilderSetTextures = address;
			return (uintptr_t)&NVN::WindowBuilderSetTextures;
		}
		else if (!strcmp("nvnWindowInitialize", nvnFunction)) {
			Address_weaks.nvnWindowInitialize = address;
			return (uintptr_t)&NVN::WindowInitialize;
		}
		else if (!strcmp("nvnSyncWait", nvnFunction)) {
			Address_weaks.nvnSyncWait = address;
			return (uintptr_t)&NVN::SyncWait0;
		}
		else if (!strcmp("nvnCommandBufferSetRenderTargets", nvnFunction)) {
			Address_weaks.nvnCommandBufferSetRenderTargets = address;
			return (uintptr_t)&NVN::CommandBufferSetRenderTargets;
		}
		else if (!strcmp("nvnCommandBufferSetViewport", nvnFunction)) {
			Address_weaks.nvnCommandBufferSetViewport = address;
			return (uintptr_t)&NVN::CommandBufferSetViewport;
		}
		else if (!strcmp("nvnCommandBufferSetViewports", nvnFunction)) {
			Address_weaks.nvnCommandBufferSetViewports = address;
			return (uintptr_t)&NVN::CommandBufferSetViewports;
		}
		else if (!strcmp("nvnTextureGetWidth", nvnFunction)) {
			Address_weaks.nvnTextureGetWidth = address;
		}
		else if (!strcmp("nvnTextureGetHeight", nvnFunction)) {
			Address_weaks.nvnTextureGetHeight = address;
		}
		else if (!strcmp("nvnTextureGetFormat", nvnFunction)) {
			Address_weaks.nvnTextureGetFormat = address;
		}
		return address;
	}

	uintptr_t BootstrapLoader_1(const char* nvnName) {
		if (strcmp(nvnName, "nvnDeviceGetProcAddress") == 0) {
			(Shared -> API) = 1;
			Address_weaks.nvnDeviceGetProcAddress = ((nvnBootstrapLoader_0)(Address_weaks.nvnBootstrapLoader))("nvnDeviceGetProcAddress");
			return (uintptr_t)&GetProcAddress0;
		}
		uintptr_t ptrret = ((nvnBootstrapLoader_0)(Address_weaks.nvnBootstrapLoader))(nvnName);
		return ptrret;
	}
}

extern "C" {

	void NX_FPS(SharedMemory* _sharedmemory, uint32_t* _sharedOperationMode) {
		sharedOperationMode = _sharedOperationMode;
		SaltySDCore_printf("NX-FPS: alive\n");
		LOCK::mappings.main_start = getMainAddress();
		SaltySDCore_printf("NX-FPS: found main at: 0x%lX\n", LOCK::mappings.main_start);
		Result ret = SaltySD_CheckIfSharedMemoryAvailable(&SharedMemoryOffset, sizeof(NxFpsSharedBlock));
		SaltySDCore_printf("NX-FPS: ret: 0x%X\n", ret);
		if (!ret) {
			SaltySDCore_printf("NX-FPS: MemoryOffset: %d\n", SharedMemoryOffset);

			Shared = (NxFpsSharedBlock*)((uintptr_t)shmemGetAddr(_sharedmemory) + SharedMemoryOffset);
			Shared -> MAGIC = 0x465053;
			
			Address_weaks.nvnBootstrapLoader = SaltySDCore_FindSymbolBuiltin("nvnBootstrapLoader");
			Address_weaks.eglSwapBuffers = SaltySDCore_FindSymbolBuiltin("eglSwapBuffers");
			Address_weaks.eglSwapInterval = SaltySDCore_FindSymbolBuiltin("eglSwapInterval");
			Address_weaks.vkQueuePresentKHR = SaltySDCore_FindSymbolBuiltin("vkQueuePresentKHR");
			Address_weaks.nvSwapchainQueuePresentKHR = SaltySDCore_FindSymbolBuiltin("_ZN11NvSwapchain15QueuePresentKHREP9VkQueue_TPK16VkPresentInfoKHR");
			Address_weaks.ConvertToTimeSpan = SaltySDCore_FindSymbolBuiltin("_ZN2nn2os17ConvertToTimeSpanENS0_4TickE");
			Address_weaks.GetSystemTick = SaltySDCore_FindSymbolBuiltin("_ZN2nn2os13GetSystemTickEv");
			Address_weaks.GetSystemTickFrequency = SaltySDCore_FindSymbolBuiltin("_ZN2nn2os22GetSystemTickFrequencyEv");
			Address_weaks.eglGetProcAddress = SaltySDCore_FindSymbolBuiltin("eglGetProcAddress");
			Address_weaks.vkGetInstanceProcAddr = SaltySDCore_FindSymbolBuiltin("vkGetInstanceProcAddr");
			Address_weaks.LookupSymbol = SaltySDCore_FindSymbolBuiltin("_ZN2nn2ro12LookupSymbolEPmPKc");
			Address_weaks.vkCmdSetViewport = SaltySDCore_FindSymbolBuiltin("vkCmdSetViewport");
			Address_weaks.glViewport = SaltySDCore_FindSymbolBuiltin("glViewport");
			Address_weaks.glViewportArrayv = SaltySDCore_FindSymbolBuiltin("glViewportArrayv");
			Address_weaks.glViewportArrayvNV = SaltySDCore_FindSymbolBuiltin("glViewportArrayvNV");
			Address_weaks.glViewportArrayvOES = SaltySDCore_FindSymbolBuiltin("glViewportArrayvOES");
			Address_weaks.glViewportIndexedf = SaltySDCore_FindSymbolBuiltin("glViewportIndexedf");
			Address_weaks.glViewportIndexedfNV = SaltySDCore_FindSymbolBuiltin("glViewportIndexedfNV");
			Address_weaks.glViewportIndexedfOES = SaltySDCore_FindSymbolBuiltin("glViewportIndexedfOES");
			Address_weaks.glViewportIndexedfv = SaltySDCore_FindSymbolBuiltin("glViewportIndexedfv");
			Address_weaks.glViewportIndexedfvNV = SaltySDCore_FindSymbolBuiltin("glViewportIndexedfvNV");
			Address_weaks.glViewportIndexedfvOES = SaltySDCore_FindSymbolBuiltin("glViewportIndexedfvOES");
			Address_weaks.vkCreateSwapchainKHR = SaltySDCore_FindSymbolBuiltin("vkCreateSwapchainKHR");
			Address_weaks.vkGetDeviceProcAddr = SaltySDCore_FindSymbolBuiltin("vkGetDeviceProcAddr");
			Address_weaks.vkGetSwapchainImagesKHR = SaltySDCore_FindSymbolBuiltin("vkGetSwapchainImagesKHR");
			Address_weaks.nvSwapchainGetSwapchainImagesKHR = SaltySDCore_FindSymbolBuiltin("_ZN11NvSwapchain21GetSwapchainImagesKHREP10VkDevice_TP16VkSwapchainKHR_TPjPP9VkImage_T");
			Address_weaks.nvSwapchainCreateSwapchainKHR = SaltySDCore_FindSymbolBuiltin("_ZN11NvSwapchain18CreateSwapchainKHREP10VkDevice_TPK24VkSwapchainCreateInfoKHRPK21VkAllocationCallbacksPP16VkSwapchainKHR_T");
			Address_weaks.GetCurrentFocusState = SaltySDCore_FindSymbolBuiltin("_ZN2nn2oe20GetCurrentFocusStateEv");			
			SaltySDCore_ReplaceImport("nvnBootstrapLoader", (void*)NVN::BootstrapLoader_1);
			SaltySDCore_ReplaceImport("eglSwapBuffers", (void*)EGL::Swap);
			SaltySDCore_ReplaceImport("eglSwapInterval", (void*)EGL::Interval);
			SaltySDCore_ReplaceImport("glViewport", (void*)EGL::Viewport);
			SaltySDCore_ReplaceImport("glViewportArrayv", (void*)EGL::ViewportArrayv);
			SaltySDCore_ReplaceImport("glViewportArrayvNV", (void*)EGL::ViewportArrayvNV);
			SaltySDCore_ReplaceImport("glViewportArrayvOES", (void*)EGL::ViewportArrayvOES);
			SaltySDCore_ReplaceImport("glViewportIndexedf", (void*)EGL::ViewportIndexedf);
			SaltySDCore_ReplaceImport("glViewportIndexedfNV", (void*)EGL::ViewportIndexedfNV);
			SaltySDCore_ReplaceImport("glViewportIndexedfOES", (void*)EGL::ViewportIndexedfOES);
			SaltySDCore_ReplaceImport("glViewportIndexedfv", (void*)EGL::ViewportIndexedfv);
			SaltySDCore_ReplaceImport("glViewportIndexedfvNV", (void*)EGL::ViewportIndexedfvNV);
			SaltySDCore_ReplaceImport("glViewportIndexedfvOES", (void*)EGL::ViewportIndexedfvOES);
			SaltySDCore_ReplaceImport("vkQueuePresentKHR", (void*)vk::QueuePresent);
			SaltySDCore_ReplaceImport("_ZN11NvSwapchain15QueuePresentKHREP9VkQueue_TPK16VkPresentInfoKHR", (void*)vk::nvSwapchain::QueuePresent);
			SaltySDCore_ReplaceImport("eglGetProcAddress", (void*)EGL::GetProc);
			SaltySDCore_ReplaceImport("vkGetDeviceProcAddr", (void*)vk::GetDeviceProcAddr);
			SaltySDCore_ReplaceImport("vkGetInstanceProcAddr", (void*)vk::GetInstanceProcAddr);
			SaltySDCore_ReplaceImport("vkCmdSetViewport", (void*)vk::CmdSetViewport);
			SaltySDCore_ReplaceImport("vkCmdSetViewportWithCount", (void*)vk::CmdSetViewportWithCount);
			SaltySDCore_ReplaceImport("vkCreateSwapchainKHR", (void*)vk::CreateSwapchain);
			if (Address_weaks.vkGetInstanceProcAddr) {
				//Minecraft is using nn::ro::LookupSymbol to search for Vulkan functions
				SaltySDCore_ReplaceImport("_ZN2nn2ro12LookupSymbolEPmPKc", (void*)vk::LookupSymbol);
			}
			
			systemtickfrequency = ((_ZN2nn2os22GetSystemTickFrequencyEv_0)(Address_weaks.GetSystemTickFrequency))();
			char titleid[17];
			CheckTitleID(&titleid[0]);
			char path[128];
			strcpy(&path[0], "sdmc:/switch/SaltySD/plugins/FPSLocker/0");
			strcat(&path[0], &titleid[0]);
			strcat(&path[0], ".dat");
			FILE* file_dat = SaltySDCore_fopen(path, "rb");
			if (file_dat) {
				uint8_t temp = 0;
				SaltySDCore_fread(&temp, 1, 1, file_dat);
				(Shared -> FPSlocked) = temp;
				if (temp >= 40 && temp <= 120) {
					FILE* sync_file = SaltySDCore_fopen("sdmc:/switch/SaltySD/flags/displaysync.flag", "rb");
					if  (sync_file) {
						SaltySDCore_fclose(sync_file);
						SaltySD_SetDisplayRefreshRate(temp);
						(Shared -> displaySync) = true;
					}
				}
				SaltySDCore_fread(&temp, 1, 1, file_dat);
				(Shared -> ZeroSync) = temp;
				if (SaltySDCore_fread(&temp, 1, 1, file_dat))
					(Shared -> SetBuffers) = temp;
				if (SaltySDCore_fread(&temp, 1, 1, file_dat))
					(Shared -> forceSuspend) = (bool)temp;
				SaltySDCore_fclose(file_dat);
			}

			u64 buildid = SaltySD_GetBID();
			if (!buildid) {
				SaltySDCore_printf("NX-FPS: getBID failed! Err: 0x%x\n", ret);
			}
			else {
				SaltySDCore_printf("NX-FPS: BID: %016lX\n", buildid);
				createBuildidPath(buildid, &titleid[0], &path[0]);
				FILE* patch_file = SaltySDCore_fopen(path, "rb");
				if (patch_file) {
					SaltySDCore_fclose(patch_file);
					SaltySDCore_printf("NX-FPS: FPSLocker: successfully opened: %s\n", path);
					configRC = readConfig(path, &configBuffer);
					if (LOCK::MasterWriteApplied) {
						(Shared -> patchApplied) = 2;
					}
					SaltySDCore_printf("NX-FPS: FPSLocker: readConfig rc: 0x%x\n", configRC);
					svcGetInfo(&LOCK::mappings.alias_start, InfoType_AliasRegionAddress, CUR_PROCESS_HANDLE, 0);
					svcGetInfo(&LOCK::mappings.heap_start, InfoType_HeapRegionAddress, CUR_PROCESS_HANDLE, 0);
				}
				else SaltySDCore_printf("NX-FPS: FPSLocker: File not found: %s\n", path);
			}
		}
		SaltySDCore_printf("NX-FPS: injection finished\n");
	}
}
