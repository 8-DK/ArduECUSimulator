#pragma once
// MESSAGE READ_CAN_RAW PACKING

#define MAVLINK_MSG_ID_READ_CAN_RAW 2


typedef struct __mavlink_read_can_raw_t {
 uint64_t msgId; /*<  CAN Message Id. For. Standard CAN 11 bit, For extended 29 bit*/
 uint8_t target_system; /*<  System ID.*/
 uint8_t target_component; /*<  Component ID.*/
 uint8_t extByte; /*<  Extend.*/
 uint8_t len; /*<  message len.*/
 uint8_t buffer[100]; /*<  message buffer.Max can data size id 64 byte.*/
} mavlink_read_can_raw_t;

#define MAVLINK_MSG_ID_READ_CAN_RAW_LEN 112
#define MAVLINK_MSG_ID_READ_CAN_RAW_MIN_LEN 112
#define MAVLINK_MSG_ID_2_LEN 112
#define MAVLINK_MSG_ID_2_MIN_LEN 112

#define MAVLINK_MSG_ID_READ_CAN_RAW_CRC 177
#define MAVLINK_MSG_ID_2_CRC 177

#define MAVLINK_MSG_READ_CAN_RAW_FIELD_BUFFER_LEN 100

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_READ_CAN_RAW { \
    2, \
    "READ_CAN_RAW", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_read_can_raw_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_read_can_raw_t, target_component) }, \
         { "msgId", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_read_can_raw_t, msgId) }, \
         { "extByte", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_read_can_raw_t, extByte) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_read_can_raw_t, len) }, \
         { "buffer", NULL, MAVLINK_TYPE_UINT8_T, 100, 12, offsetof(mavlink_read_can_raw_t, buffer) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_READ_CAN_RAW { \
    "READ_CAN_RAW", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_read_can_raw_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_read_can_raw_t, target_component) }, \
         { "msgId", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_read_can_raw_t, msgId) }, \
         { "extByte", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_read_can_raw_t, extByte) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_read_can_raw_t, len) }, \
         { "buffer", NULL, MAVLINK_TYPE_UINT8_T, 100, 12, offsetof(mavlink_read_can_raw_t, buffer) }, \
         } \
}
#endif

/**
 * @brief Pack a read_can_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param msgId  CAN Message Id. For. Standard CAN 11 bit, For extended 29 bit
 * @param extByte  Extend.
 * @param len  message len.
 * @param buffer  message buffer.Max can data size id 64 byte.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_read_can_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint64_t msgId, uint8_t extByte, uint8_t len, const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_READ_CAN_RAW_LEN];
    _mav_put_uint64_t(buf, 0, msgId);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, extByte);
    _mav_put_uint8_t(buf, 11, len);
    _mav_put_uint8_t_array(buf, 12, buffer, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_READ_CAN_RAW_LEN);
#else
    mavlink_read_can_raw_t packet;
    packet.msgId = msgId;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.extByte = extByte;
    packet.len = len;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_READ_CAN_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_READ_CAN_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_READ_CAN_RAW_MIN_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_CRC);
}

/**
 * @brief Pack a read_can_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param msgId  CAN Message Id. For. Standard CAN 11 bit, For extended 29 bit
 * @param extByte  Extend.
 * @param len  message len.
 * @param buffer  message buffer.Max can data size id 64 byte.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_read_can_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint64_t msgId,uint8_t extByte,uint8_t len,const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_READ_CAN_RAW_LEN];
    _mav_put_uint64_t(buf, 0, msgId);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, extByte);
    _mav_put_uint8_t(buf, 11, len);
    _mav_put_uint8_t_array(buf, 12, buffer, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_READ_CAN_RAW_LEN);
#else
    mavlink_read_can_raw_t packet;
    packet.msgId = msgId;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.extByte = extByte;
    packet.len = len;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_READ_CAN_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_READ_CAN_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_READ_CAN_RAW_MIN_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_CRC);
}

/**
 * @brief Encode a read_can_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param read_can_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_read_can_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_read_can_raw_t* read_can_raw)
{
    return mavlink_msg_read_can_raw_pack(system_id, component_id, msg, read_can_raw->target_system, read_can_raw->target_component, read_can_raw->msgId, read_can_raw->extByte, read_can_raw->len, read_can_raw->buffer);
}

/**
 * @brief Encode a read_can_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param read_can_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_read_can_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_read_can_raw_t* read_can_raw)
{
    return mavlink_msg_read_can_raw_pack_chan(system_id, component_id, chan, msg, read_can_raw->target_system, read_can_raw->target_component, read_can_raw->msgId, read_can_raw->extByte, read_can_raw->len, read_can_raw->buffer);
}

/**
 * @brief Send a read_can_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param msgId  CAN Message Id. For. Standard CAN 11 bit, For extended 29 bit
 * @param extByte  Extend.
 * @param len  message len.
 * @param buffer  message buffer.Max can data size id 64 byte.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_read_can_raw_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint64_t msgId, uint8_t extByte, uint8_t len, const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_READ_CAN_RAW_LEN];
    _mav_put_uint64_t(buf, 0, msgId);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, extByte);
    _mav_put_uint8_t(buf, 11, len);
    _mav_put_uint8_t_array(buf, 12, buffer, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_CAN_RAW, buf, MAVLINK_MSG_ID_READ_CAN_RAW_MIN_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_CRC);
#else
    mavlink_read_can_raw_t packet;
    packet.msgId = msgId;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.extByte = extByte;
    packet.len = len;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_CAN_RAW, (const char *)&packet, MAVLINK_MSG_ID_READ_CAN_RAW_MIN_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_CRC);
#endif
}

/**
 * @brief Send a read_can_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_read_can_raw_send_struct(mavlink_channel_t chan, const mavlink_read_can_raw_t* read_can_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_read_can_raw_send(chan, read_can_raw->target_system, read_can_raw->target_component, read_can_raw->msgId, read_can_raw->extByte, read_can_raw->len, read_can_raw->buffer);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_CAN_RAW, (const char *)read_can_raw, MAVLINK_MSG_ID_READ_CAN_RAW_MIN_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_READ_CAN_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_read_can_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint64_t msgId, uint8_t extByte, uint8_t len, const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, msgId);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, extByte);
    _mav_put_uint8_t(buf, 11, len);
    _mav_put_uint8_t_array(buf, 12, buffer, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_CAN_RAW, buf, MAVLINK_MSG_ID_READ_CAN_RAW_MIN_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_CRC);
#else
    mavlink_read_can_raw_t *packet = (mavlink_read_can_raw_t *)msgbuf;
    packet->msgId = msgId;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->extByte = extByte;
    packet->len = len;
    mav_array_memcpy(packet->buffer, buffer, sizeof(uint8_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_CAN_RAW, (const char *)packet, MAVLINK_MSG_ID_READ_CAN_RAW_MIN_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_LEN, MAVLINK_MSG_ID_READ_CAN_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE READ_CAN_RAW UNPACKING


/**
 * @brief Get field target_system from read_can_raw message
 *
 * @return  System ID.
 */
static inline uint8_t mavlink_msg_read_can_raw_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field target_component from read_can_raw message
 *
 * @return  Component ID.
 */
static inline uint8_t mavlink_msg_read_can_raw_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field msgId from read_can_raw message
 *
 * @return  CAN Message Id. For. Standard CAN 11 bit, For extended 29 bit
 */
static inline uint64_t mavlink_msg_read_can_raw_get_msgId(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field extByte from read_can_raw message
 *
 * @return  Extend.
 */
static inline uint8_t mavlink_msg_read_can_raw_get_extByte(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field len from read_can_raw message
 *
 * @return  message len.
 */
static inline uint8_t mavlink_msg_read_can_raw_get_len(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field buffer from read_can_raw message
 *
 * @return  message buffer.Max can data size id 64 byte.
 */
static inline uint16_t mavlink_msg_read_can_raw_get_buffer(const mavlink_message_t* msg, uint8_t *buffer)
{
    return _MAV_RETURN_uint8_t_array(msg, buffer, 100,  12);
}

/**
 * @brief Decode a read_can_raw message into a struct
 *
 * @param msg The message to decode
 * @param read_can_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_read_can_raw_decode(const mavlink_message_t* msg, mavlink_read_can_raw_t* read_can_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    read_can_raw->msgId = mavlink_msg_read_can_raw_get_msgId(msg);
    read_can_raw->target_system = mavlink_msg_read_can_raw_get_target_system(msg);
    read_can_raw->target_component = mavlink_msg_read_can_raw_get_target_component(msg);
    read_can_raw->extByte = mavlink_msg_read_can_raw_get_extByte(msg);
    read_can_raw->len = mavlink_msg_read_can_raw_get_len(msg);
    mavlink_msg_read_can_raw_get_buffer(msg, read_can_raw->buffer);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_READ_CAN_RAW_LEN? msg->len : MAVLINK_MSG_ID_READ_CAN_RAW_LEN;
        memset(read_can_raw, 0, MAVLINK_MSG_ID_READ_CAN_RAW_LEN);
    memcpy(read_can_raw, _MAV_PAYLOAD(msg), len);
#endif
}
