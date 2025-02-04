typedef unsigned int NvU32;

#define NVAPI_MAX_THERMAL_SENSORS_PER_GPU	 3
#define NVAPI_MAX_PHYSICAL_GPUS			64
#define NVAPI_SHORT_STRING_MAX			64
#define NVAPI_DEFAULT_HANDLE     	 	 0

#define NV_DECLARE_HANDLE(name) struct name##__ { int unused; }; typedef struct name##__ *name

typedef char NvAPI_ShortString[NVAPI_SHORT_STRING_MAX];

typedef enum
{
    NVSTATUS_OK = 0,
    NVSTATUS_ERROR = -1,
    LIBRARY_NOT_FOUND = -2,
    NO_IMPLEMENTATION = -3,
    API_NOT_INTIALIZED = -4,
    INVALID_ARGUMENT = -5,
    NVIDIA_DEVICE_NOT_FOUND = -6,
    END_ENUMERATION = -7,
    INVALID_HANDLE = -8,
    INCOMPATIBLE_STRUCT_VERSION = -9,
    HANDLE_INVALIDATED = -10,
    OPENGL_CONTEXT_NOT_CURRENT = -11,
    NO_GL_EXPERT = -12,
    INSTRUMENTATION_DISABLED = -13,
    EXPECTED_LOGICAL_GPU_HANDLE = -100,
    EXPECTED_PHYSICAL_GPU_HANDLE = -101,
    EXPECTED_DISPLAY_HANDLE = -102,
    INVALID_COMBINATION = -103,
    NOT_SUPPORTED = -104,
    PORTID_NOT_FOUND = -105,
    EXPECTED_UNATTACHED_DISPLAY_HANDLE = -106,
    INVALID_PERF_LEVEL = -107,
    DEVICE_BUSY = -108,
    NV_PERSIST_FILE_NOT_FOUND = -109,
    PERSIST_DATA_NOT_FOUND = -110,
    EXPECTED_TV_DISPLAY = -111,
    EXPECTED_TV_DISPLAY_ON_DCONNECTOR = -112,
    NO_ACTIVE_SLI_TOPOLOGY = -113,
    SLI_RENDERING_MODE_NOTALLOWED = -114,
    EXPECTED_DIGITAL_FLAT_PANEL = -115,
    ARGUMENT_EXCEED_MAX_SIZE = -116,
    DEVICE_SWITCHING_NOT_ALLOWED = -117,
    TESTING_CLOCKS_NOT_SUPPORTED = -118,
    UNKNOWN_UNDERSCAN_CONFIG = -119,
    TIMEOUT_RECONFIGURING_GPU_TOPO = -120,
    DATA_NOT_FOUND = -121,
    EXPECTED_ANALOG_DISPLAY = -122,
    NO_VIDLINK = -123,
    REQUIRES_REBOOT = -124,
    INVALID_HYBRID_MODE = -125,
    MIXED_TARGET_TYPES = -126,
    SYSWOW64_NOT_SUPPORTED = -127,
    IMPLICIT_SET_GPU_TOPOLOGY_CHANGE_NOT_ALLOWED = -128,
    REQUEST_USER_TO_CLOSE_NON_MIGRATABLE_APPS = -129,
    OUT_OF_MEMORY = -130,
    WAS_STILL_DRAWING = -131,
    FILE_NOT_FOUND = -132,
    TOO_MANY_UNIQUE_STATE_OBJECTS = -133,
    INVALID_CALL = -134,
    D3D10_1_LIBRARY_NOT_FOUND = -135,
    FUNCTION_NOT_FOUND = -136
} NvStatus;


//GPU_THERMAL info

typedef enum
{
    NONE_CONTROLLER = 0,
    GPU_INTERNAL,
    ADM1032,
    MAX6649,
    MAX1617,
    LM99,
    LM89,
    LM64,
    ADT7473,
    SBMAX6649,
    VBIOSEVT,
    OS,
    UNKNOWN_CONTROLLER = -1
} NvThermalController;


typedef enum
{
    NONE_TARGET = 0,
    GPU = 1,
    MEMORY = 2,
    POWER_SUPPLY = 4,
    BOARD = 8,
    ALL = 15,
    UNKNOWN_TARGET = -1
} NvThermalTarget;


typedef struct
{
    NvThermalController Controller;
    NvU32 DefaultMinTemp;
    NvU32 DefaultMaxTemp;
    NvU32 CurrentTemp;
    NvThermalTarget Target;
} NvSensor;

typedef struct
{
	NvU32 Version;
	NvU32 Count;
	NvSensor Sensor[NVAPI_MAX_THERMAL_SENSORS_PER_GPU];
	
} NvGPUThermalSettings;

#define NV_GPU_THERMAL_SETTINGS_VER    (NvU32)(sizeof(NvGPUThermalSettings) | (1 << 16));
//#define NV_GPU_THERMAL_SETTINGS_VER      (NvU32)(sizeof(NvGPUThermalSettings) | (0x10000));

//DISPLAY_DRIVER info

typedef struct
{
    NvU32 version;
    NvU32 drvVersion;
    NvU32 bldChangeListNum;
    NvAPI_ShortString szBuildBranchString;
    NvAPI_ShortString szAdapterString;
} NV_DISPLAY_DRIVER_VERSION;

typedef NV_DISPLAY_DRIVER_VERSION TNvDisplayDriverVersion;
typedef TNvDisplayDriverVersion *PNvDisplayDriverVersion;

#define NV_DISPLAY_DRIVER_VERSION_VER  (NvU32)(sizeof(TNvDisplayDriverVersion) | (1 << 16));

//CHIPSET_DRIVER info

typedef struct
{
    NvU32 version;
    NvU32 vendorId;
    NvU32 deviceId;
    NvAPI_ShortString szVendorName;
    NvAPI_ShortString szChipsetName;
    NvU32 flags;
    NvU32 subSysVendorId;
    NvU32 subSysDeviceId;
    NvAPI_ShortString szSubSysVendorName;
} NV_CHIPSET_INFO;

typedef NV_CHIPSET_INFO TNvChipsetInfo;

#define NV_CHIPSET_INFO_VER  (NvU32)(sizeof(TNvChipsetInfo) | (3 << 16));

//GPU_BUS info

typedef enum
{
    GPU_BUS_TYPE_UNDEFINED    = 0,
    GPU_BUS_TYPE_PCI          = 1,
    GPU_BUS_TYPE_AGP          = 2,
    GPU_BUS_TYPE_PCI_EXPRESS  = 3,
    GPU_BUS_TYPE_FPCI         = 4
} NV_GPU_BUS_TYPE;

typedef enum
{
    NV_SYSTEM_TYPE_UNKNOWN = 0,
    NV_SYSTEM_TYPE_LAPTOP  = 1,
    NV_SYSTEM_TYPE_DESKTOP = 2,

} NV_SYSTEM_TYPE;


//Other definitions

//NV_DECLARE_HANDLE(NvPhysicalGpuHandle);
typedef HANDLE NvPhysicalGpuHandle;
//typedef struct {} NvPhysicalGpuHandle;
typedef NvPhysicalGpuHandle NvPhysicalGpuHandleArray[NVAPI_MAX_PHYSICAL_GPUS];

typedef HANDLE NvDisplayHandle;
//typedef struct {HANDLE h;} NvDisplayHandle;
typedef NvDisplayHandle *PNvDisplayHandle;


