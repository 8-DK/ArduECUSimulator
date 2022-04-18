#pragma once
// MESSAGE COMM_LINK_CONFIG PACKING

#define MAVLINK_MSG_ID_COMM_LINK_CONFIG 3


typedef struct __mavlink_comm_link_config_t {
 uint8_t target_system; /*<  System ID.*/
 uint8_t target_component; /*<  Component ID.*/
 uint8_t baudrate; /*<  CAN baud rate*/
 uint8_t crystalfreq; /*<  crystal frequency 8MHz / 16MHz.*/
 uint8_t len; /*<  message len.*/
} mavlink_comm_link_config_t;

#define MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN 5
#define MAVLINK_MSG_ID_COMM_LINK_CONFIG_MIN_LEN 5
#define MAVLINK_MSG_ID_3_LEN 5
#define MAVLINK_MSG_ID_3_MIN_LEN 5

#define MAVLINK_MSG_ID_COMM_LINK_CONFIG_CRC 31
#define MAVLINK_MSG_ID_3_CRC 31



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMM_LINK_CONFIG { \
    3, \
    "COMM_LINK_CONFIG", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_comm_link_config_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_comm_link_config_t, target_component) }, \
         { "baudrate", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_comm_link_config_t, baudrate) }, \
         { "crystalfreq", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_comm_link_config_t, crystalfreq) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_comm_link_config_t, len) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMM_LINK_CONFIG { \
    "COMM_LINK_CONFIG", \
    5, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_comm_link_config_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_comm_link_config_t, target_component) }, \
         { "baudrate", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_comm_link_config_t, baudrate) }, \
         { "crystalfreq", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_comm_link_config_t, crystalfreq) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_comm_link_config_t, len) }, \
         } \
}
#endif

/**
 * @brief Pack a comm_link_config message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param baudrate  CAN baud rate
 * @param crystalfreq  crystal frequency 8MHz / 16MHz.
 * @param len  message len.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_comm_link_config_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t baudrate, uint8_t crystalfreq, uint8_t len)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, baudrate);
    _mav_put_uint8_t(buf, 3, crystalfreq);
    _mav_put_uint8_t(buf, 4, len);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN);
#else
    mavlink_comm_link_config_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.baudrate = baudrate;
    packet.crystalfreq = crystalfreq;
    packet.len = len;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMM_LINK_CONFIG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMM_LINK_CONFIG_MIN_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_CRC);
}

/**
 * @brief Pack a comm_link_config message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param baudrate  CAN baud rate
 * @param crystalfreq  crystal frequency 8MHz / 16MHz.
 * @param len  message len.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_comm_link_config_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t baudrate,uint8_t crystalfreq,uint8_t len)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, baudrate);
    _mav_put_uint8_t(buf, 3, crystalfreq);
    _mav_put_uint8_t(buf, 4, len);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN);
#else
    mavlink_comm_link_config_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.baudrate = baudrate;
    packet.crystalfreq = crystalfreq;
    packet.len = len;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMM_LINK_CONFIG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMM_LINK_CONFIG_MIN_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_CRC);
}

/**
 * @brief Encode a comm_link_config struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param comm_link_config C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_comm_link_config_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_comm_link_config_t* comm_link_config)
{
    return mavlink_msg_comm_link_config_pack(system_id, component_id, msg, comm_link_config->target_system, comm_link_config->target_component, comm_link_config->baudrate, comm_link_config->crystalfreq, comm_link_config->len);
}

/**
 * @brief Encode a comm_link_config struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param comm_link_config C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_comm_link_config_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_comm_link_config_t* comm_link_config)
{
    return mavlink_msg_comm_link_config_pack_chan(system_id, component_id, chan, msg, comm_link_config->target_system, comm_link_config->target_component, comm_link_config->baudrate, comm_link_config->crystalfreq, comm_link_config->len);
}

/**
 * @brief Send a comm_link_config message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param baudrate  CAN baud rate
 * @param crystalfreq  crystal frequency 8MHz / 16MHz.
 * @param len  message len.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_comm_link_config_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t baudrate, uint8_t crystalfreq, uint8_t len)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, baudrate);
    _mav_put_uint8_t(buf, 3, crystalfreq);
    _mav_put_uint8_t(buf, 4, len);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMM_LINK_CONFIG, buf, MAVLINK_MSG_ID_COMM_LINK_CONFIG_MIN_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_CRC);
#else
    mavlink_comm_link_config_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.baudrate = baudrate;
    packet.crystalfreq = crystalfreq;
    packet.len = len;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMM_LINK_CONFIG, (const char *)&packet, MAVLINK_MSG_ID_COMM_LINK_CONFIG_MIN_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_CRC);
#endif
}

/**
 * @brief Send a comm_link_config message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_comm_link_config_send_struct(mavlink_channel_t chan, const mavlink_comm_link_config_t* comm_link_config)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_comm_link_config_send(chan, comm_link_config->target_system, comm_link_config->target_component, comm_link_config->baudrate, comm_link_config->crystalfreq, comm_link_config->len);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMM_LINK_CONFIG, (const char *)comm_link_config, MAVLINK_MSG_ID_COMM_LINK_CONFIG_MIN_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_CRC);
#endif
}

#if MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_comm_link_config_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t baudrate, uint8_t crystalfreq, uint8_t len)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, baudrate);
    _mav_put_uint8_t(buf, 3, crystalfreq);
    _mav_put_uint8_t(buf, 4, len);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMM_LINK_CONFIG, buf, MAVLINK_MSG_ID_COMM_LINK_CONFIG_MIN_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_CRC);
#else
    mavlink_comm_link_config_t *packet = (mavlink_comm_link_config_t *)msgbuf;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->baudrate = baudrate;
    packet->crystalfreq = crystalfreq;
    packet->len = len;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMM_LINK_CONFIG, (const char *)packet, MAVLINK_MSG_ID_COMM_LINK_CONFIG_MIN_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN, MAVLINK_MSG_ID_COMM_LINK_CONFIG_CRC);
#endif
}
#endif

#endif

// MESSAGE COMM_LINK_CONFIG UNPACKING


/**
 * @brief Get field target_system from comm_link_config message
 *
 * @return  System ID.
 */
static inline uint8_t mavlink_msg_comm_link_config_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from comm_link_config message
 *
 * @return  Component ID.
 */
static inline uint8_t mavlink_msg_comm_link_config_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field baudrate from comm_link_config message
 *
 * @return  CAN baud rate
 */
static inline uint8_t mavlink_msg_comm_link_config_get_baudrate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field crystalfreq from comm_link_config message
 *
 * @return  crystal frequency 8MHz / 16MHz.
 */
static inline uint8_t mavlink_msg_comm_link_config_get_crystalfreq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field len from comm_link_config message
 *
 * @return  message len.
 */
static inline uint8_t mavlink_msg_comm_link_config_get_len(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a comm_link_config message into a struct
 *
 * @param msg The message to decode
 * @param comm_link_config C-struct to decode the message contents into
 */
static inline void mavlink_msg_comm_link_config_decode(const mavlink_message_t* msg, mavlink_comm_link_config_t* comm_link_config)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    comm_link_config->target_system = mavlink_msg_comm_link_config_get_target_system(msg);
    comm_link_config->target_component = mavlink_msg_comm_link_config_get_target_component(msg);
    comm_link_config->baudrate = mavlink_msg_comm_link_config_get_baudrate(msg);
    comm_link_config->crystalfreq = mavlink_msg_comm_link_config_get_crystalfreq(msg);
    comm_link_config->len = mavlink_msg_comm_link_config_get_len(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN? msg->len : MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN;
        memset(comm_link_config, 0, MAVLINK_MSG_ID_COMM_LINK_CONFIG_LEN);
    memcpy(comm_link_config, _MAV_PAYLOAD(msg), len);
#endif
}
