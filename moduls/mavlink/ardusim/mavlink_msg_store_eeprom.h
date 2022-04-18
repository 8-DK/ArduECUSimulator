#pragma once
// MESSAGE STORE_EEPROM PACKING

#define MAVLINK_MSG_ID_STORE_EEPROM 5


typedef struct __mavlink_store_eeprom_t {
 uint16_t address; /*<  storage address.*/
 uint8_t target_system; /*<  System ID.*/
 uint8_t target_component; /*<  Component ID.*/
 uint8_t ; /*<  device specific state*/
 uint8_t len; /*<  message len.*/
 uint8_t buffer[100]; /*<  data buffer.*/
} mavlink_store_eeprom_t;

#define MAVLINK_MSG_ID_STORE_EEPROM_LEN 106
#define MAVLINK_MSG_ID_STORE_EEPROM_MIN_LEN 106
#define MAVLINK_MSG_ID_5_LEN 106
#define MAVLINK_MSG_ID_5_MIN_LEN 106

#define MAVLINK_MSG_ID_STORE_EEPROM_CRC 228
#define MAVLINK_MSG_ID_5_CRC 228

#define MAVLINK_MSG_STORE_EEPROM_FIELD_BUFFER_LEN 100

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_STORE_EEPROM { \
    5, \
    "STORE_EEPROM", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_store_eeprom_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_store_eeprom_t, target_component) }, \
         { "", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_store_eeprom_t, ) }, \
         { "address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_store_eeprom_t, address) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_store_eeprom_t, len) }, \
         { "buffer", NULL, MAVLINK_TYPE_UINT8_T, 100, 6, offsetof(mavlink_store_eeprom_t, buffer) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_STORE_EEPROM { \
    "STORE_EEPROM", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_store_eeprom_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_store_eeprom_t, target_component) }, \
         { "", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_store_eeprom_t, ) }, \
         { "address", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_store_eeprom_t, address) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_store_eeprom_t, len) }, \
         { "buffer", NULL, MAVLINK_TYPE_UINT8_T, 100, 6, offsetof(mavlink_store_eeprom_t, buffer) }, \
         } \
}
#endif

/**
 * @brief Pack a store_eeprom message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param   device specific state
 * @param address  storage address.
 * @param len  message len.
 * @param buffer  data buffer.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_store_eeprom_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t , uint16_t address, uint8_t len, const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STORE_EEPROM_LEN];
    _mav_put_uint16_t(buf, 0, address);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, );
    _mav_put_uint8_t(buf, 5, len);
    _mav_put_uint8_t_array(buf, 6, buffer, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_STORE_EEPROM_LEN);
#else
    mavlink_store_eeprom_t packet;
    packet.address = address;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet. = ;
    packet.len = len;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_STORE_EEPROM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_STORE_EEPROM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_STORE_EEPROM_MIN_LEN, MAVLINK_MSG_ID_STORE_EEPROM_LEN, MAVLINK_MSG_ID_STORE_EEPROM_CRC);
}

/**
 * @brief Pack a store_eeprom message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param   device specific state
 * @param address  storage address.
 * @param len  message len.
 * @param buffer  data buffer.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_store_eeprom_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t ,uint16_t address,uint8_t len,const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STORE_EEPROM_LEN];
    _mav_put_uint16_t(buf, 0, address);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, );
    _mav_put_uint8_t(buf, 5, len);
    _mav_put_uint8_t_array(buf, 6, buffer, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_STORE_EEPROM_LEN);
#else
    mavlink_store_eeprom_t packet;
    packet.address = address;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet. = ;
    packet.len = len;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_STORE_EEPROM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_STORE_EEPROM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_STORE_EEPROM_MIN_LEN, MAVLINK_MSG_ID_STORE_EEPROM_LEN, MAVLINK_MSG_ID_STORE_EEPROM_CRC);
}

/**
 * @brief Encode a store_eeprom struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param store_eeprom C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_store_eeprom_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_store_eeprom_t* store_eeprom)
{
    return mavlink_msg_store_eeprom_pack(system_id, component_id, msg, store_eeprom->target_system, store_eeprom->target_component, store_eeprom->, store_eeprom->address, store_eeprom->len, store_eeprom->buffer);
}

/**
 * @brief Encode a store_eeprom struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param store_eeprom C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_store_eeprom_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_store_eeprom_t* store_eeprom)
{
    return mavlink_msg_store_eeprom_pack_chan(system_id, component_id, chan, msg, store_eeprom->target_system, store_eeprom->target_component, store_eeprom->, store_eeprom->address, store_eeprom->len, store_eeprom->buffer);
}

/**
 * @brief Send a store_eeprom message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param   device specific state
 * @param address  storage address.
 * @param len  message len.
 * @param buffer  data buffer.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_store_eeprom_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t , uint16_t address, uint8_t len, const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STORE_EEPROM_LEN];
    _mav_put_uint16_t(buf, 0, address);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, );
    _mav_put_uint8_t(buf, 5, len);
    _mav_put_uint8_t_array(buf, 6, buffer, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STORE_EEPROM, buf, MAVLINK_MSG_ID_STORE_EEPROM_MIN_LEN, MAVLINK_MSG_ID_STORE_EEPROM_LEN, MAVLINK_MSG_ID_STORE_EEPROM_CRC);
#else
    mavlink_store_eeprom_t packet;
    packet.address = address;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet. = ;
    packet.len = len;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STORE_EEPROM, (const char *)&packet, MAVLINK_MSG_ID_STORE_EEPROM_MIN_LEN, MAVLINK_MSG_ID_STORE_EEPROM_LEN, MAVLINK_MSG_ID_STORE_EEPROM_CRC);
#endif
}

/**
 * @brief Send a store_eeprom message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_store_eeprom_send_struct(mavlink_channel_t chan, const mavlink_store_eeprom_t* store_eeprom)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_store_eeprom_send(chan, store_eeprom->target_system, store_eeprom->target_component, store_eeprom->, store_eeprom->address, store_eeprom->len, store_eeprom->buffer);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STORE_EEPROM, (const char *)store_eeprom, MAVLINK_MSG_ID_STORE_EEPROM_MIN_LEN, MAVLINK_MSG_ID_STORE_EEPROM_LEN, MAVLINK_MSG_ID_STORE_EEPROM_CRC);
#endif
}

#if MAVLINK_MSG_ID_STORE_EEPROM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_store_eeprom_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t , uint16_t address, uint8_t len, const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, address);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_uint8_t(buf, 4, );
    _mav_put_uint8_t(buf, 5, len);
    _mav_put_uint8_t_array(buf, 6, buffer, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STORE_EEPROM, buf, MAVLINK_MSG_ID_STORE_EEPROM_MIN_LEN, MAVLINK_MSG_ID_STORE_EEPROM_LEN, MAVLINK_MSG_ID_STORE_EEPROM_CRC);
#else
    mavlink_store_eeprom_t *packet = (mavlink_store_eeprom_t *)msgbuf;
    packet->address = address;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet-> = ;
    packet->len = len;
    mav_array_memcpy(packet->buffer, buffer, sizeof(uint8_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STORE_EEPROM, (const char *)packet, MAVLINK_MSG_ID_STORE_EEPROM_MIN_LEN, MAVLINK_MSG_ID_STORE_EEPROM_LEN, MAVLINK_MSG_ID_STORE_EEPROM_CRC);
#endif
}
#endif

#endif

// MESSAGE STORE_EEPROM UNPACKING


/**
 * @brief Get field target_system from store_eeprom message
 *
 * @return  System ID.
 */
static inline uint8_t mavlink_msg_store_eeprom_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field target_component from store_eeprom message
 *
 * @return  Component ID.
 */
static inline uint8_t mavlink_msg_store_eeprom_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field  from store_eeprom message
 *
 * @return  device specific state
 */
static inline uint8_t mavlink_msg_store_eeprom_get_(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field address from store_eeprom message
 *
 * @return  storage address.
 */
static inline uint16_t mavlink_msg_store_eeprom_get_address(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field len from store_eeprom message
 *
 * @return  message len.
 */
static inline uint8_t mavlink_msg_store_eeprom_get_len(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field buffer from store_eeprom message
 *
 * @return  data buffer.
 */
static inline uint16_t mavlink_msg_store_eeprom_get_buffer(const mavlink_message_t* msg, uint8_t *buffer)
{
    return _MAV_RETURN_uint8_t_array(msg, buffer, 100,  6);
}

/**
 * @brief Decode a store_eeprom message into a struct
 *
 * @param msg The message to decode
 * @param store_eeprom C-struct to decode the message contents into
 */
static inline void mavlink_msg_store_eeprom_decode(const mavlink_message_t* msg, mavlink_store_eeprom_t* store_eeprom)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    store_eeprom->address = mavlink_msg_store_eeprom_get_address(msg);
    store_eeprom->target_system = mavlink_msg_store_eeprom_get_target_system(msg);
    store_eeprom->target_component = mavlink_msg_store_eeprom_get_target_component(msg);
    store_eeprom-> = mavlink_msg_store_eeprom_get_(msg);
    store_eeprom->len = mavlink_msg_store_eeprom_get_len(msg);
    mavlink_msg_store_eeprom_get_buffer(msg, store_eeprom->buffer);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_STORE_EEPROM_LEN? msg->len : MAVLINK_MSG_ID_STORE_EEPROM_LEN;
        memset(store_eeprom, 0, MAVLINK_MSG_ID_STORE_EEPROM_LEN);
    memcpy(store_eeprom, _MAV_PAYLOAD(msg), len);
#endif
}
