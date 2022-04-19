#pragma once
// MESSAGE READ_EEPROM PACKING

#define MAVLINK_MSG_ID_READ_EEPROM 6


typedef struct __mavlink_read_eeprom_t {
 uint16_t address; /*<  storage address.*/
 uint8_t target_system; /*<  System ID.*/
 uint8_t target_component; /*<  Component ID.*/
 uint8_t sendACK; /*<  operation response.*/
 uint8_t len; /*<  message len.*/
 uint8_t buffer[100]; /*<  data buffer.*/
 uint8_t status; /*<  status.*/
} mavlink_read_eeprom_t;

#define MAVLINK_MSG_ID_READ_EEPROM_LEN 107
#define MAVLINK_MSG_ID_READ_EEPROM_MIN_LEN 107
#define MAVLINK_MSG_ID_6_LEN 107
#define MAVLINK_MSG_ID_6_MIN_LEN 107

#define MAVLINK_MSG_ID_READ_EEPROM_CRC 93
#define MAVLINK_MSG_ID_6_CRC 93

#define MAVLINK_MSG_READ_EEPROM_FIELD_BUFFER_LEN 100

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_READ_EEPROM { \
    6, \
    "READ_EEPROM", \
    7, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_read_eeprom_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_read_eeprom_t, target_component) }, \
         { "sendACK", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_read_eeprom_t, sendACK) }, \
         { "address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_read_eeprom_t, address) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_read_eeprom_t, len) }, \
         { "buffer", NULL, MAVLINK_TYPE_UINT8_T, 100, 6, offsetof(mavlink_read_eeprom_t, buffer) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 106, offsetof(mavlink_read_eeprom_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_READ_EEPROM { \
    "READ_EEPROM", \
    7, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_read_eeprom_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_read_eeprom_t, target_component) }, \
         { "sendACK", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_read_eeprom_t, sendACK) }, \
         { "address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_read_eeprom_t, address) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_read_eeprom_t, len) }, \
         { "buffer", NULL, MAVLINK_TYPE_UINT8_T, 100, 6, offsetof(mavlink_read_eeprom_t, buffer) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 106, offsetof(mavlink_read_eeprom_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a read_eeprom message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param sendACK  operation response.
 * @param address  storage address.
 * @param len  message len.
 * @param buffer  data buffer.
 * @param status  status.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_read_eeprom_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t sendACK, uint16_t address, uint8_t len, const uint8_t *buffer, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_READ_EEPROM_LEN];
    _mav_put_uint16_t(buf, 0, address);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, sendACK);
    _mav_put_uint8_t(buf, 5, len);
    _mav_put_uint8_t(buf, 106, status);
    _mav_put_uint8_t_array(buf, 6, buffer, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_READ_EEPROM_LEN);
#else
    mavlink_read_eeprom_t packet;
    packet.address = address;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.sendACK = sendACK;
    packet.len = len;
    packet.status = status;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_READ_EEPROM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_READ_EEPROM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_READ_EEPROM_MIN_LEN, MAVLINK_MSG_ID_READ_EEPROM_LEN, MAVLINK_MSG_ID_READ_EEPROM_CRC);
}

/**
 * @brief Pack a read_eeprom message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param sendACK  operation response.
 * @param address  storage address.
 * @param len  message len.
 * @param buffer  data buffer.
 * @param status  status.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_read_eeprom_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t sendACK,uint16_t address,uint8_t len,const uint8_t *buffer,uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_READ_EEPROM_LEN];
    _mav_put_uint16_t(buf, 0, address);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, sendACK);
    _mav_put_uint8_t(buf, 5, len);
    _mav_put_uint8_t(buf, 106, status);
    _mav_put_uint8_t_array(buf, 6, buffer, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_READ_EEPROM_LEN);
#else
    mavlink_read_eeprom_t packet;
    packet.address = address;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.sendACK = sendACK;
    packet.len = len;
    packet.status = status;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_READ_EEPROM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_READ_EEPROM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_READ_EEPROM_MIN_LEN, MAVLINK_MSG_ID_READ_EEPROM_LEN, MAVLINK_MSG_ID_READ_EEPROM_CRC);
}

/**
 * @brief Encode a read_eeprom struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param read_eeprom C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_read_eeprom_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_read_eeprom_t* read_eeprom)
{
    return mavlink_msg_read_eeprom_pack(system_id, component_id, msg, read_eeprom->target_system, read_eeprom->target_component, read_eeprom->sendACK, read_eeprom->address, read_eeprom->len, read_eeprom->buffer, read_eeprom->status);
}

/**
 * @brief Encode a read_eeprom struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param read_eeprom C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_read_eeprom_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_read_eeprom_t* read_eeprom)
{
    return mavlink_msg_read_eeprom_pack_chan(system_id, component_id, chan, msg, read_eeprom->target_system, read_eeprom->target_component, read_eeprom->sendACK, read_eeprom->address, read_eeprom->len, read_eeprom->buffer, read_eeprom->status);
}

/**
 * @brief Send a read_eeprom message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param sendACK  operation response.
 * @param address  storage address.
 * @param len  message len.
 * @param buffer  data buffer.
 * @param status  status.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_read_eeprom_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t sendACK, uint16_t address, uint8_t len, const uint8_t *buffer, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_READ_EEPROM_LEN];
    _mav_put_uint16_t(buf, 0, address);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, sendACK);
    _mav_put_uint8_t(buf, 5, len);
    _mav_put_uint8_t(buf, 106, status);
    _mav_put_uint8_t_array(buf, 6, buffer, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_EEPROM, buf, MAVLINK_MSG_ID_READ_EEPROM_MIN_LEN, MAVLINK_MSG_ID_READ_EEPROM_LEN, MAVLINK_MSG_ID_READ_EEPROM_CRC);
#else
    mavlink_read_eeprom_t packet;
    packet.address = address;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.sendACK = sendACK;
    packet.len = len;
    packet.status = status;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_EEPROM, (const char *)&packet, MAVLINK_MSG_ID_READ_EEPROM_MIN_LEN, MAVLINK_MSG_ID_READ_EEPROM_LEN, MAVLINK_MSG_ID_READ_EEPROM_CRC);
#endif
}

/**
 * @brief Send a read_eeprom message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_read_eeprom_send_struct(mavlink_channel_t chan, const mavlink_read_eeprom_t* read_eeprom)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_read_eeprom_send(chan, read_eeprom->target_system, read_eeprom->target_component, read_eeprom->sendACK, read_eeprom->address, read_eeprom->len, read_eeprom->buffer, read_eeprom->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_EEPROM, (const char *)read_eeprom, MAVLINK_MSG_ID_READ_EEPROM_MIN_LEN, MAVLINK_MSG_ID_READ_EEPROM_LEN, MAVLINK_MSG_ID_READ_EEPROM_CRC);
#endif
}

#if MAVLINK_MSG_ID_READ_EEPROM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_read_eeprom_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t sendACK, uint16_t address, uint8_t len, const uint8_t *buffer, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, address);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, sendACK);
    _mav_put_uint8_t(buf, 5, len);
    _mav_put_uint8_t(buf, 106, status);
    _mav_put_uint8_t_array(buf, 6, buffer, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_EEPROM, buf, MAVLINK_MSG_ID_READ_EEPROM_MIN_LEN, MAVLINK_MSG_ID_READ_EEPROM_LEN, MAVLINK_MSG_ID_READ_EEPROM_CRC);
#else
    mavlink_read_eeprom_t *packet = (mavlink_read_eeprom_t *)msgbuf;
    packet->address = address;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->sendACK = sendACK;
    packet->len = len;
    packet->status = status;
    mav_array_memcpy(packet->buffer, buffer, sizeof(uint8_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_EEPROM, (const char *)packet, MAVLINK_MSG_ID_READ_EEPROM_MIN_LEN, MAVLINK_MSG_ID_READ_EEPROM_LEN, MAVLINK_MSG_ID_READ_EEPROM_CRC);
#endif
}
#endif

#endif

// MESSAGE READ_EEPROM UNPACKING


/**
 * @brief Get field target_system from read_eeprom message
 *
 * @return  System ID.
 */
static inline uint8_t mavlink_msg_read_eeprom_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field target_component from read_eeprom message
 *
 * @return  Component ID.
 */
static inline uint8_t mavlink_msg_read_eeprom_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field sendACK from read_eeprom message
 *
 * @return  operation response.
 */
static inline uint8_t mavlink_msg_read_eeprom_get_sendACK(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field address from read_eeprom message
 *
 * @return  storage address.
 */
static inline uint16_t mavlink_msg_read_eeprom_get_address(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field len from read_eeprom message
 *
 * @return  message len.
 */
static inline uint8_t mavlink_msg_read_eeprom_get_len(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field buffer from read_eeprom message
 *
 * @return  data buffer.
 */
static inline uint16_t mavlink_msg_read_eeprom_get_buffer(const mavlink_message_t* msg, uint8_t *buffer)
{
    return _MAV_RETURN_uint8_t_array(msg, buffer, 100,  6);
}

/**
 * @brief Get field status from read_eeprom message
 *
 * @return  status.
 */
static inline uint8_t mavlink_msg_read_eeprom_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  106);
}

/**
 * @brief Decode a read_eeprom message into a struct
 *
 * @param msg The message to decode
 * @param read_eeprom C-struct to decode the message contents into
 */
static inline void mavlink_msg_read_eeprom_decode(const mavlink_message_t* msg, mavlink_read_eeprom_t* read_eeprom)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    read_eeprom->address = mavlink_msg_read_eeprom_get_address(msg);
    read_eeprom->target_system = mavlink_msg_read_eeprom_get_target_system(msg);
    read_eeprom->target_component = mavlink_msg_read_eeprom_get_target_component(msg);
    read_eeprom->sendACK = mavlink_msg_read_eeprom_get_sendACK(msg);
    read_eeprom->len = mavlink_msg_read_eeprom_get_len(msg);
    mavlink_msg_read_eeprom_get_buffer(msg, read_eeprom->buffer);
    read_eeprom->status = mavlink_msg_read_eeprom_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_READ_EEPROM_LEN? msg->len : MAVLINK_MSG_ID_READ_EEPROM_LEN;
        memset(read_eeprom, 0, MAVLINK_MSG_ID_READ_EEPROM_LEN);
    memcpy(read_eeprom, _MAV_PAYLOAD(msg), len);
#endif
}
