/** @file
 *  @brief MAVLink comm protocol generated from ardusim.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_ARDUSIM_H
#define MAVLINK_ARDUSIM_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_ARDUSIM.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42, 8, 4, 12, 15, 13, 6, 15, 14, 0, 12, 3, 0, 28, 44, 3, 9, 22, 12, 18, 34, 66, 98, 8, 48, 19, 3, 20, 24, 29, 45, 4, 40, 2, 206, 7, 29, 0, 0, 0, 0, 27, 44, 22, 25, 37, 0, 0, 0, 0, 42, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 3, 3, 6, 7, 2, 0, 0, 0, 0, 0, 65, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 134, 219, 208, 188, 84, 22, 19, 21, 134, 0, 78, 68, 0, 127, 154, 21, 21, 144, 1, 234, 73, 181, 22, 83, 167, 138, 234, 240, 47, 189, 52, 174, 229, 85, 159, 186, 72, 0, 0, 0, 0, 92, 36, 71, 98, 120, 0, 0, 0, 0, 134, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 69, 101, 50, 202, 17, 162, 0, 0, 0, 0, 0, 208, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_ARDUSIM

// ENUM DEFINITIONS


/** @brief  */
#ifndef HAVE_ENUM_MESSAGE_TYPE
#define HAVE_ENUM_MESSAGE_TYPE
typedef enum MESSAGE_TYPE
{
   REQUEST=1, /*  | */
   RESPONSE=2, /*  | */
   ACK=3, /*  | */
   NACK=4, /*  | */
   ERROR_RESP=5, /*  | */
   ACCELCAL_VEHICLE_POS_BACK=6, /*  | */
   MESSAGE_TYPE_ENUM_END=7, /*  | */
} MESSAGE_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAV_CMD
#define HAVE_ENUM_MAV_CMD
typedef enum MAV_CMD
{
   MAV_CMD_START_STOP_HSIM=211, /* Enable/disable SIM. |Enable (1: enable, 0:disable).| Empty.| Empty.| Empty.| Empty.| Empty.| Empty.|  */
   MAV_CMD_RESET_HSIM=212, /* Reset hardware simulator |Reset.| Empty.| Empty.| Empty.| Empty.| Empty.| Empty.|  */
   MAV_CMD_GET_LAST_HSIM_ERROR=213, /* Get last hardware simulator error. It may be sriver chip error. |Error Code 1| Error Code 2| Error Code 3| Empty.| Empty.| Empty.| Empty.|  */
   MAV_CMD_SET_CAN_SPEED=214, /* Set CAN interface speed. |CAN speed KBPS| Empty.| Empty.| Empty.| Empty.| Empty.| Empty.|  */
   MAV_CMD_READ_RXTX_STATUS=215, /* Read RX TX STATUS. |Empty.| Empty.| Empty.| Empty.| Empty.| Empty.| Empty.|  */
   MAV_CMD_CLEAR_RX_TX_STATUS=216, /* Clear RX TX Status. |Empty.| Empty.| Empty.| Empty.| Empty.| Empty.| Empty.|  */
   MAV_CMD_DO_SEND_BANNER=217, /* Reply with the version banner. |Empty.| Empty.| Empty.| Empty.| Empty.| Empty.| Empty.|  */
   MAV_CMD_SET_FACTORY_TEST_MODE=218, /* Command autopilot to get into factory test/diagnostic mode. |0 means get out of test mode, 1 means get into test mode.| Empty.| Empty.| Empty.| Empty.| Empty.| Empty.|  */
   MAV_CMD_FLASH_BOOTLOADER=219, /* Update the bootloader |Empty| Empty| Empty| Empty| Magic number - set to 290876 to actually flash| Empty| Empty|  */
   MAV_CMD_BATTERY_RESET=220, /* Reset battery capacity for batteries that accumulate consumed battery via integration. |Bitmask of batteries to reset. Least significant bit is for the first battery.| Battery percentage remaining to set.| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)|  */
   MAV_CMD_DEBUG_TRAP=221, /* Issue a trap signal to the autopilot process, presumably to enter the debugger. |Magic number - set to 32451 to actually trap.| Empty.| Empty.| Empty.| Empty.| Empty.| Empty.|  */
   MAV_CMD_SCRIPTING=222, /* Control onboard scripting. |Scripting command to execute| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)|  */
   MAV_CMD_ENUM_END=223, /*  | */
} MAV_CMD;
#endif

/** @brief  */
#ifndef HAVE_ENUM_SCRIPTING_CMD
#define HAVE_ENUM_SCRIPTING_CMD
typedef enum SCRIPTING_CMD
{
   SCRIPTING_CMD_REPL_START=0, /* Start a REPL session. | */
   SCRIPTING_CMD_REPL_STOP=1, /* End a REPL session. | */
   SCRIPTING_CMD_ENUM_END=2, /*  | */
} SCRIPTING_CMD;
#endif

/** @brief  */
#ifndef HAVE_ENUM_LIMITS_STATE
#define HAVE_ENUM_LIMITS_STATE
typedef enum LIMITS_STATE
{
   LIMITS_INIT=0, /* Pre-initialization. | */
   LIMITS_DISABLED=1, /* Disabled. | */
   LIMITS_ENABLED=2, /* Checking limits. | */
   LIMITS_TRIGGERED=3, /* A limit has been breached. | */
   LIMITS_RECOVERING=4, /* Taking action e.g. Return/RTL. | */
   LIMITS_RECOVERED=5, /* We're no longer in breach of a limit. | */
   LIMITS_STATE_ENUM_END=6, /*  | */
} LIMITS_STATE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_LIMIT_MODULE
#define HAVE_ENUM_LIMIT_MODULE
typedef enum LIMIT_MODULE
{
   LIMIT_GPSLOCK=1, /* Pre-initialization. | */
   LIMIT_GEOFENCE=2, /* Disabled. | */
   LIMIT_ALTITUDE=4, /* Checking limits. | */
   LIMIT_MODULE_ENUM_END=5, /*  | */
} LIMIT_MODULE;
#endif

/** @brief Flags in RALLY_POINT message. */
#ifndef HAVE_ENUM_RALLY_FLAGS
#define HAVE_ENUM_RALLY_FLAGS
typedef enum RALLY_FLAGS
{
   FAVORABLE_WIND=1, /* Flag set when requiring favorable winds for landing. | */
   LAND_IMMEDIATELY=2, /* Flag set when plane is to immediately descend to break altitude and land without GCS intervention. Flag not set when plane is to loiter at Rally point until commanded to land. | */
   RALLY_FLAGS_ENUM_END=3, /*  | */
} RALLY_FLAGS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_LED_CONTROL_PATTERN
#define HAVE_ENUM_LED_CONTROL_PATTERN
typedef enum LED_CONTROL_PATTERN
{
   LED_CONTROL_PATTERN_OFF=0, /* LED patterns off (return control to regular vehicle control). | */
   LED_CONTROL_PATTERN_FIRMWAREUPDATE=1, /* LEDs show pattern during firmware update. | */
   LED_CONTROL_PATTERN_CUSTOM=255, /* Custom Pattern using custom bytes fields. | */
   LED_CONTROL_PATTERN_ENUM_END=256, /*  | */
} LED_CONTROL_PATTERN;
#endif

/** @brief Flags in EKF_STATUS message. */
#ifndef HAVE_ENUM_EKF_STATUS_FLAGS
#define HAVE_ENUM_EKF_STATUS_FLAGS
typedef enum EKF_STATUS_FLAGS
{
   EKF_ATTITUDE=1, /* Set if EKF's attitude estimate is good. | */
   EKF_VELOCITY_HORIZ=2, /* Set if EKF's horizontal velocity estimate is good. | */
   EKF_VELOCITY_VERT=4, /* Set if EKF's vertical velocity estimate is good. | */
   EKF_POS_HORIZ_REL=8, /* Set if EKF's horizontal position (relative) estimate is good. | */
   EKF_POS_HORIZ_ABS=16, /* Set if EKF's horizontal position (absolute) estimate is good. | */
   EKF_POS_VERT_ABS=32, /* Set if EKF's vertical position (absolute) estimate is good. | */
   EKF_POS_VERT_AGL=64, /* Set if EKF's vertical position (above ground) estimate is good. | */
   EKF_CONST_POS_MODE=128, /* EKF is in constant position mode and does not know it's absolute or relative position. | */
   EKF_PRED_POS_HORIZ_REL=256, /* Set if EKF's predicted horizontal position (relative) estimate is good. | */
   EKF_PRED_POS_HORIZ_ABS=512, /* Set if EKF's predicted horizontal position (absolute) estimate is good. | */
   EKF_UNINITIALIZED=1024, /* Set if EKF has never been healthy. | */
   EKF_STATUS_FLAGS_ENUM_END=1025, /*  | */
} EKF_STATUS_FLAGS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_PID_TUNING_AXIS
#define HAVE_ENUM_PID_TUNING_AXIS
typedef enum PID_TUNING_AXIS
{
   PID_TUNING_ROLL=1, /*  | */
   PID_TUNING_PITCH=2, /*  | */
   PID_TUNING_YAW=3, /*  | */
   PID_TUNING_ACCZ=4, /*  | */
   PID_TUNING_STEER=5, /*  | */
   PID_TUNING_LANDING=6, /*  | */
   PID_TUNING_AXIS_ENUM_END=7, /*  | */
} PID_TUNING_AXIS;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAG_CAL_STATUS
#define HAVE_ENUM_MAG_CAL_STATUS
typedef enum MAG_CAL_STATUS
{
   MAG_CAL_NOT_STARTED=0, /*  | */
   MAG_CAL_WAITING_TO_START=1, /*  | */
   MAG_CAL_RUNNING_STEP_ONE=2, /*  | */
   MAG_CAL_RUNNING_STEP_TWO=3, /*  | */
   MAG_CAL_SUCCESS=4, /*  | */
   MAG_CAL_FAILED=5, /*  | */
   MAG_CAL_BAD_ORIENTATION=6, /*  | */
   MAG_CAL_BAD_RADIUS=7, /*  | */
   MAG_CAL_STATUS_ENUM_END=8, /*  | */
} MAG_CAL_STATUS;
#endif

/** @brief Special ACK block numbers control activation of dataflash log streaming. */
#ifndef HAVE_ENUM_MAV_REMOTE_LOG_DATA_BLOCK_COMMANDS
#define HAVE_ENUM_MAV_REMOTE_LOG_DATA_BLOCK_COMMANDS
typedef enum MAV_REMOTE_LOG_DATA_BLOCK_COMMANDS
{
   MAV_REMOTE_LOG_DATA_BLOCK_STOP=2147483645, /* UAV to stop sending DataFlash blocks. | */
   MAV_REMOTE_LOG_DATA_BLOCK_START=2147483646, /* UAV to start sending DataFlash blocks. | */
   MAV_REMOTE_LOG_DATA_BLOCK_COMMANDS_ENUM_END=2147483647, /*  | */
} MAV_REMOTE_LOG_DATA_BLOCK_COMMANDS;
#endif

/** @brief Possible remote log data block statuses. */
#ifndef HAVE_ENUM_MAV_REMOTE_LOG_DATA_BLOCK_STATUSES
#define HAVE_ENUM_MAV_REMOTE_LOG_DATA_BLOCK_STATUSES
typedef enum MAV_REMOTE_LOG_DATA_BLOCK_STATUSES
{
   MAV_REMOTE_LOG_DATA_BLOCK_NACK=0, /* This block has NOT been received. | */
   MAV_REMOTE_LOG_DATA_BLOCK_ACK=1, /* This block has been received. | */
   MAV_REMOTE_LOG_DATA_BLOCK_STATUSES_ENUM_END=2, /*  | */
} MAV_REMOTE_LOG_DATA_BLOCK_STATUSES;
#endif

/** @brief Bus types for device operations. */
#ifndef HAVE_ENUM_DEVICE_OP_BUSTYPE
#define HAVE_ENUM_DEVICE_OP_BUSTYPE
typedef enum DEVICE_OP_BUSTYPE
{
   DEVICE_OP_BUSTYPE_I2C=0, /* I2C Device operation. | */
   DEVICE_OP_BUSTYPE_SPI=1, /* SPI Device operation. | */
   DEVICE_OP_BUSTYPE_ENUM_END=2, /*  | */
} DEVICE_OP_BUSTYPE;
#endif

/** @brief Deepstall flight stage. */
#ifndef HAVE_ENUM_DEEPSTALL_STAGE
#define HAVE_ENUM_DEEPSTALL_STAGE
typedef enum DEEPSTALL_STAGE
{
   DEEPSTALL_STAGE_FLY_TO_LANDING=0, /* Flying to the landing point. | */
   DEEPSTALL_STAGE_ESTIMATE_WIND=1, /* Building an estimate of the wind. | */
   DEEPSTALL_STAGE_WAIT_FOR_BREAKOUT=2, /* Waiting to breakout of the loiter to fly the approach. | */
   DEEPSTALL_STAGE_FLY_TO_ARC=3, /* Flying to the first arc point to turn around to the landing point. | */
   DEEPSTALL_STAGE_ARC=4, /* Turning around back to the deepstall landing point. | */
   DEEPSTALL_STAGE_APPROACH=5, /* Approaching the landing point. | */
   DEEPSTALL_STAGE_LAND=6, /* Stalling and steering towards the land point. | */
   DEEPSTALL_STAGE_ENUM_END=7, /*  | */
} DEEPSTALL_STAGE;
#endif

/** @brief A mapping of copter flight modes for custom_mode field of heartbeat. */
#ifndef HAVE_ENUM_COPTER_MODE
#define HAVE_ENUM_COPTER_MODE
typedef enum COPTER_MODE
{
   COPTER_MODE_STABILIZE=0, /*  | */
   COPTER_MODE_ACRO=1, /*  | */
   COPTER_MODE_ALT_HOLD=2, /*  | */
   COPTER_MODE_AUTO=3, /*  | */
   COPTER_MODE_GUIDED=4, /*  | */
   COPTER_MODE_LOITER=5, /*  | */
   COPTER_MODE_RTL=6, /*  | */
   COPTER_MODE_CIRCLE=7, /*  | */
   COPTER_MODE_LAND=9, /*  | */
   COPTER_MODE_DRIFT=11, /*  | */
   COPTER_MODE_SPORT=13, /*  | */
   COPTER_MODE_FLIP=14, /*  | */
   COPTER_MODE_AUTOTUNE=15, /*  | */
   COPTER_MODE_POSHOLD=16, /*  | */
   COPTER_MODE_BRAKE=17, /*  | */
   COPTER_MODE_THROW=18, /*  | */
   COPTER_MODE_AVOID_ADSB=19, /*  | */
   COPTER_MODE_GUIDED_NOGPS=20, /*  | */
   COPTER_MODE_SMART_RTL=21, /*  | */
   COPTER_MODE_ENUM_END=22, /*  | */
} COPTER_MODE;
#endif

/** @brief A mapping of sub flight modes for custom_mode field of heartbeat. */
#ifndef HAVE_ENUM_SUB_MODE
#define HAVE_ENUM_SUB_MODE
typedef enum SUB_MODE
{
   SUB_MODE_STABILIZE=0, /*  | */
   SUB_MODE_ACRO=1, /*  | */
   SUB_MODE_ALT_HOLD=2, /*  | */
   SUB_MODE_AUTO=3, /*  | */
   SUB_MODE_GUIDED=4, /*  | */
   SUB_MODE_CIRCLE=7, /*  | */
   SUB_MODE_SURFACE=9, /*  | */
   SUB_MODE_POSHOLD=16, /*  | */
   SUB_MODE_MANUAL=19, /*  | */
   SUB_MODE_ENUM_END=20, /*  | */
} SUB_MODE;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_sensor_offsets.h"
#include "./mavlink_msg_set_mag_offsets.h"
#include "./mavlink_msg_meminfo.h"
#include "./mavlink_msg_ap_adc.h"
#include "./mavlink_msg_digicam_configure.h"
#include "./mavlink_msg_digicam_control.h"
#include "./mavlink_msg_mount_configure.h"
#include "./mavlink_msg_mount_control.h"
#include "./mavlink_msg_mount_status.h"
#include "./mavlink_msg_fence_point.h"
#include "./mavlink_msg_fence_fetch_point.h"
#include "./mavlink_msg_ahrs.h"
#include "./mavlink_msg_simstate.h"
#include "./mavlink_msg_hwstatus.h"
#include "./mavlink_msg_radio.h"
#include "./mavlink_msg_limits_status.h"
#include "./mavlink_msg_wind.h"
#include "./mavlink_msg_data16.h"
#include "./mavlink_msg_data32.h"
#include "./mavlink_msg_data64.h"
#include "./mavlink_msg_data96.h"
#include "./mavlink_msg_rangefinder.h"
#include "./mavlink_msg_airspeed_autocal.h"
#include "./mavlink_msg_rally_point.h"
#include "./mavlink_msg_rally_fetch_point.h"
#include "./mavlink_msg_compassmot_status.h"
#include "./mavlink_msg_ahrs2.h"
#include "./mavlink_msg_camera_status.h"
#include "./mavlink_msg_camera_feedback.h"
#include "./mavlink_msg_battery2.h"
#include "./mavlink_msg_ahrs3.h"
#include "./mavlink_msg_autopilot_version_request.h"
#include "./mavlink_msg_remote_log_data_block.h"
#include "./mavlink_msg_remote_log_block_status.h"
#include "./mavlink_msg_led_control.h"
#include "./mavlink_msg_mag_cal_progress.h"
#include "./mavlink_msg_mag_cal_report.h"
#include "./mavlink_msg_ekf_status_report.h"
#include "./mavlink_msg_pid_tuning.h"
#include "./mavlink_msg_deepstall.h"
#include "./mavlink_msg_gimbal_report.h"
#include "./mavlink_msg_gimbal_control.h"
#include "./mavlink_msg_gimbal_torque_cmd_report.h"
#include "./mavlink_msg_gopro_heartbeat.h"
#include "./mavlink_msg_gopro_get_request.h"
#include "./mavlink_msg_gopro_get_response.h"
#include "./mavlink_msg_gopro_set_request.h"
#include "./mavlink_msg_gopro_set_response.h"
#include "./mavlink_msg_efi_status.h"
#include "./mavlink_msg_rpm.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {{"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_SENSOR_OFFSETS, MAVLINK_MESSAGE_INFO_SET_MAG_OFFSETS, MAVLINK_MESSAGE_INFO_MEMINFO, MAVLINK_MESSAGE_INFO_AP_ADC, MAVLINK_MESSAGE_INFO_DIGICAM_CONFIGURE, MAVLINK_MESSAGE_INFO_DIGICAM_CONTROL, MAVLINK_MESSAGE_INFO_MOUNT_CONFIGURE, MAVLINK_MESSAGE_INFO_MOUNT_CONTROL, MAVLINK_MESSAGE_INFO_MOUNT_STATUS, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_FENCE_POINT, MAVLINK_MESSAGE_INFO_FENCE_FETCH_POINT, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_AHRS, MAVLINK_MESSAGE_INFO_SIMSTATE, MAVLINK_MESSAGE_INFO_HWSTATUS, MAVLINK_MESSAGE_INFO_RADIO, MAVLINK_MESSAGE_INFO_LIMITS_STATUS, MAVLINK_MESSAGE_INFO_WIND, MAVLINK_MESSAGE_INFO_DATA16, MAVLINK_MESSAGE_INFO_DATA32, MAVLINK_MESSAGE_INFO_DATA64, MAVLINK_MESSAGE_INFO_DATA96, MAVLINK_MESSAGE_INFO_RANGEFINDER, MAVLINK_MESSAGE_INFO_AIRSPEED_AUTOCAL, MAVLINK_MESSAGE_INFO_RALLY_POINT, MAVLINK_MESSAGE_INFO_RALLY_FETCH_POINT, MAVLINK_MESSAGE_INFO_COMPASSMOT_STATUS, MAVLINK_MESSAGE_INFO_AHRS2, MAVLINK_MESSAGE_INFO_CAMERA_STATUS, MAVLINK_MESSAGE_INFO_CAMERA_FEEDBACK, MAVLINK_MESSAGE_INFO_BATTERY2, MAVLINK_MESSAGE_INFO_AHRS3, MAVLINK_MESSAGE_INFO_AUTOPILOT_VERSION_REQUEST, MAVLINK_MESSAGE_INFO_REMOTE_LOG_DATA_BLOCK, MAVLINK_MESSAGE_INFO_REMOTE_LOG_BLOCK_STATUS, MAVLINK_MESSAGE_INFO_LED_CONTROL, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_MAG_CAL_PROGRESS, MAVLINK_MESSAGE_INFO_MAG_CAL_REPORT, MAVLINK_MESSAGE_INFO_EKF_STATUS_REPORT, MAVLINK_MESSAGE_INFO_PID_TUNING, MAVLINK_MESSAGE_INFO_DEEPSTALL, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_GIMBAL_REPORT, MAVLINK_MESSAGE_INFO_GIMBAL_CONTROL, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_GIMBAL_TORQUE_CMD_REPORT, MAVLINK_MESSAGE_INFO_GOPRO_HEARTBEAT, MAVLINK_MESSAGE_INFO_GOPRO_GET_REQUEST, MAVLINK_MESSAGE_INFO_GOPRO_GET_RESPONSE, MAVLINK_MESSAGE_INFO_GOPRO_SET_REQUEST, MAVLINK_MESSAGE_INFO_GOPRO_SET_RESPONSE, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, MAVLINK_MESSAGE_INFO_EFI_STATUS, MAVLINK_MESSAGE_INFO_RPM, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",MAVLINK_TYPE_CHAR,0,0,0}}}}
# define MAVLINK_MESSAGE_NAMES {{ "AHRS", 163 }, { "AHRS2", 178 }, { "AHRS3", 182 }, { "AIRSPEED_AUTOCAL", 174 }, { "AP_ADC", 153 }, { "AUTOPILOT_VERSION_REQUEST", 183 }, { "BATTERY2", 181 }, { "CAMERA_FEEDBACK", 180 }, { "CAMERA_STATUS", 179 }, { "COMPASSMOT_STATUS", 177 }, { "DATA16", 169 }, { "DATA32", 170 }, { "DATA64", 171 }, { "DATA96", 172 }, { "DEEPSTALL", 195 }, { "DIGICAM_CONFIGURE", 154 }, { "DIGICAM_CONTROL", 155 }, { "EFI_STATUS", 225 }, { "EKF_STATUS_REPORT", 193 }, { "FENCE_FETCH_POINT", 161 }, { "FENCE_POINT", 160 }, { "GIMBAL_CONTROL", 201 }, { "GIMBAL_REPORT", 200 }, { "GIMBAL_TORQUE_CMD_REPORT", 214 }, { "GOPRO_GET_REQUEST", 216 }, { "GOPRO_GET_RESPONSE", 217 }, { "GOPRO_HEARTBEAT", 215 }, { "GOPRO_SET_REQUEST", 218 }, { "GOPRO_SET_RESPONSE", 219 }, { "HWSTATUS", 165 }, { "LED_CONTROL", 186 }, { "LIMITS_STATUS", 167 }, { "MAG_CAL_PROGRESS", 191 }, { "MAG_CAL_REPORT", 192 }, { "MEMINFO", 152 }, { "MOUNT_CONFIGURE", 156 }, { "MOUNT_CONTROL", 157 }, { "MOUNT_STATUS", 158 }, { "PID_TUNING", 194 }, { "RADIO", 166 }, { "RALLY_FETCH_POINT", 176 }, { "RALLY_POINT", 175 }, { "RANGEFINDER", 173 }, { "REMOTE_LOG_BLOCK_STATUS", 185 }, { "REMOTE_LOG_DATA_BLOCK", 184 }, { "RPM", 226 }, { "SENSOR_OFFSETS", 150 }, { "SET_MAG_OFFSETS", 151 }, { "SIMSTATE", 164 }, { "WIND", 168 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_ARDUSIM_H
