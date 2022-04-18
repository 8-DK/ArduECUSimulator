#pragma once
// MESSAGE HEART_BEAT PACKING

#define MAVLINK_MSG_ID_HEART_BEAT 4


typedef struct __mavlink_heart_beat_t {
 uint64_t counter; /*<  heartbeat counter.*/
 uint64_t lastErr; /*<  last error generated.*/
 uint8_t target_system; /*<  System ID.*/
 uint8_t target_component; /*<  Component ID.*/
 uint8_t state; /*<  device specific state*/
 uint8_t mode; /*<  device mode.*/
} mavlink_heart_beat_t;

#define MAVLINK_MSG_ID_HEART_BEAT_LEN 20
#define MAVLINK_MSG_ID_HEART_BEAT_MIN_LEN 20
#define MAVLINK_MSG_ID_4_LEN 20
#define MAVLINK_MSG_ID_4_MIN_LEN 20

#define MAVLINK_MSG_ID_HEART_BEAT_CRC 199
#define MAVLINK_MSG_ID_4_CRC 199



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HEART_BEAT { \
    4, \
    "HEART_BEAT", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_heart_beat_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_heart_beat_t, target_component) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_heart_beat_t, state) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_heart_beat_t, mode) }, \
         { "counter", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_heart_beat_t, counter) }, \
         { "lastErr", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_heart_beat_t, lastErr) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HEART_BEAT { \
    "HEART_BEAT", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_heart_beat_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_heart_beat_t, target_component) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_heart_beat_t, state) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_heart_beat_t, mode) }, \
         { "counter", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_heart_beat_t, counter) }, \
         { "lastErr", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_heart_beat_t, lastErr) }, \
         } \
}
#endif

/**
 * @brief Pack a heart_beat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param state  device specific state
 * @param mode  device mode.
 * @param counter  heartbeat counter.
 * @param lastErr  last error generated.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heart_beat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t state, uint8_t mode, uint64_t counter, uint64_t lastErr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEART_BEAT_LEN];
    _mav_put_uint64_t(buf, 0, counter);
    _mav_put_uint64_t(buf, 8, lastErr);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);
    _mav_put_uint8_t(buf, 18, state);
    _mav_put_uint8_t(buf, 19, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEART_BEAT_LEN);
#else
    mavlink_heart_beat_t packet;
    packet.counter = counter;
    packet.lastErr = lastErr;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.state = state;
    packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEART_BEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEART_BEAT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HEART_BEAT_MIN_LEN, MAVLINK_MSG_ID_HEART_BEAT_LEN, MAVLINK_MSG_ID_HEART_BEAT_CRC);
}

/**
 * @brief Pack a heart_beat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param state  device specific state
 * @param mode  device mode.
 * @param counter  heartbeat counter.
 * @param lastErr  last error generated.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heart_beat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t state,uint8_t mode,uint64_t counter,uint64_t lastErr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEART_BEAT_LEN];
    _mav_put_uint64_t(buf, 0, counter);
    _mav_put_uint64_t(buf, 8, lastErr);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);
    _mav_put_uint8_t(buf, 18, state);
    _mav_put_uint8_t(buf, 19, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEART_BEAT_LEN);
#else
    mavlink_heart_beat_t packet;
    packet.counter = counter;
    packet.lastErr = lastErr;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.state = state;
    packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEART_BEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEART_BEAT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HEART_BEAT_MIN_LEN, MAVLINK_MSG_ID_HEART_BEAT_LEN, MAVLINK_MSG_ID_HEART_BEAT_CRC);
}

/**
 * @brief Encode a heart_beat struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param heart_beat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heart_beat_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_heart_beat_t* heart_beat)
{
    return mavlink_msg_heart_beat_pack(system_id, component_id, msg, heart_beat->target_system, heart_beat->target_component, heart_beat->state, heart_beat->mode, heart_beat->counter, heart_beat->lastErr);
}

/**
 * @brief Encode a heart_beat struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param heart_beat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heart_beat_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_heart_beat_t* heart_beat)
{
    return mavlink_msg_heart_beat_pack_chan(system_id, component_id, chan, msg, heart_beat->target_system, heart_beat->target_component, heart_beat->state, heart_beat->mode, heart_beat->counter, heart_beat->lastErr);
}

/**
 * @brief Send a heart_beat message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param state  device specific state
 * @param mode  device mode.
 * @param counter  heartbeat counter.
 * @param lastErr  last error generated.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_heart_beat_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t state, uint8_t mode, uint64_t counter, uint64_t lastErr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEART_BEAT_LEN];
    _mav_put_uint64_t(buf, 0, counter);
    _mav_put_uint64_t(buf, 8, lastErr);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);
    _mav_put_uint8_t(buf, 18, state);
    _mav_put_uint8_t(buf, 19, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEART_BEAT, buf, MAVLINK_MSG_ID_HEART_BEAT_MIN_LEN, MAVLINK_MSG_ID_HEART_BEAT_LEN, MAVLINK_MSG_ID_HEART_BEAT_CRC);
#else
    mavlink_heart_beat_t packet;
    packet.counter = counter;
    packet.lastErr = lastErr;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.state = state;
    packet.mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEART_BEAT, (const char *)&packet, MAVLINK_MSG_ID_HEART_BEAT_MIN_LEN, MAVLINK_MSG_ID_HEART_BEAT_LEN, MAVLINK_MSG_ID_HEART_BEAT_CRC);
#endif
}

/**
 * @brief Send a heart_beat message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_heart_beat_send_struct(mavlink_channel_t chan, const mavlink_heart_beat_t* heart_beat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_heart_beat_send(chan, heart_beat->target_system, heart_beat->target_component, heart_beat->state, heart_beat->mode, heart_beat->counter, heart_beat->lastErr);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEART_BEAT, (const char *)heart_beat, MAVLINK_MSG_ID_HEART_BEAT_MIN_LEN, MAVLINK_MSG_ID_HEART_BEAT_LEN, MAVLINK_MSG_ID_HEART_BEAT_CRC);
#endif
}

#if MAVLINK_MSG_ID_HEART_BEAT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_heart_beat_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t state, uint8_t mode, uint64_t counter, uint64_t lastErr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, counter);
    _mav_put_uint64_t(buf, 8, lastErr);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, target_component);
    _mav_put_uint8_t(buf, 18, state);
    _mav_put_uint8_t(buf, 19, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEART_BEAT, buf, MAVLINK_MSG_ID_HEART_BEAT_MIN_LEN, MAVLINK_MSG_ID_HEART_BEAT_LEN, MAVLINK_MSG_ID_HEART_BEAT_CRC);
#else
    mavlink_heart_beat_t *packet = (mavlink_heart_beat_t *)msgbuf;
    packet->counter = counter;
    packet->lastErr = lastErr;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->state = state;
    packet->mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEART_BEAT, (const char *)packet, MAVLINK_MSG_ID_HEART_BEAT_MIN_LEN, MAVLINK_MSG_ID_HEART_BEAT_LEN, MAVLINK_MSG_ID_HEART_BEAT_CRC);
#endif
}
#endif

#endif

// MESSAGE HEART_BEAT UNPACKING


/**
 * @brief Get field target_system from heart_beat message
 *
 * @return  System ID.
 */
static inline uint8_t mavlink_msg_heart_beat_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field target_component from heart_beat message
 *
 * @return  Component ID.
 */
static inline uint8_t mavlink_msg_heart_beat_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field state from heart_beat message
 *
 * @return  device specific state
 */
static inline uint8_t mavlink_msg_heart_beat_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field mode from heart_beat message
 *
 * @return  device mode.
 */
static inline uint8_t mavlink_msg_heart_beat_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field counter from heart_beat message
 *
 * @return  heartbeat counter.
 */
static inline uint64_t mavlink_msg_heart_beat_get_counter(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field lastErr from heart_beat message
 *
 * @return  last error generated.
 */
static inline uint64_t mavlink_msg_heart_beat_get_lastErr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Decode a heart_beat message into a struct
 *
 * @param msg The message to decode
 * @param heart_beat C-struct to decode the message contents into
 */
static inline void mavlink_msg_heart_beat_decode(const mavlink_message_t* msg, mavlink_heart_beat_t* heart_beat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    heart_beat->counter = mavlink_msg_heart_beat_get_counter(msg);
    heart_beat->lastErr = mavlink_msg_heart_beat_get_lastErr(msg);
    heart_beat->target_system = mavlink_msg_heart_beat_get_target_system(msg);
    heart_beat->target_component = mavlink_msg_heart_beat_get_target_component(msg);
    heart_beat->state = mavlink_msg_heart_beat_get_state(msg);
    heart_beat->mode = mavlink_msg_heart_beat_get_mode(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HEART_BEAT_LEN? msg->len : MAVLINK_MSG_ID_HEART_BEAT_LEN;
        memset(heart_beat, 0, MAVLINK_MSG_ID_HEART_BEAT_LEN);
    memcpy(heart_beat, _MAV_PAYLOAD(msg), len);
#endif
}
