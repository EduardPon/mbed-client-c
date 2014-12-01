/**
 * \file sn_nsdl.h
 *
 * \brief libNsdl generic header file
 *
 * Copyright © 2011 - 2014, ARM Limited or its affiliates. All rights reserved.
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SN_NSDL_H_
#define SN_NSDL_H_

/* * * Common * * */

#define SN_NSDL_SUCCESS  0
#define SN_NSDL_FAILURE (-1)

/* * * * * * * * * * * * * * */
/* * * * ENUMERATIONS  * * * */
/* * * * * * * * * * * * * * */


/**
 * \brief Used protocol
 */
typedef enum sn_nsdl_capab_
{
    SN_NSDL_PROTOCOL_HTTP           = 0x01,			/**< Unsupported */
    SN_NSDL_PROTOCOL_HTTPS          = 0x02,			/**< Unsupported */
    SN_NSDL_PROTOCOL_COAP           = 0x04			/**< Supported */
} sn_nsdl_capab_e;

/**
 * \brief Address type of given address
 */
typedef enum sn_nsdl_addr_type_
{
    SN_NSDL_ADDRESS_TYPE_IPV6       = 0x01,			/**< Supported */
    SN_NSDL_ADDRESS_TYPE_IPV4       = 0x02,			/**< Supported */
    SN_NSDL_ADDRESS_TYPE_HOSTNAME   = 0x03,			/**< Unsupported */
    SN_NSDL_ADDRESS_TYPE_NONE       = 0xFF
} sn_nsdl_addr_type_e;


#define SN_NDSL_RESOURCE_NOT_REGISTERED	0
#define SN_NDSL_RESOURCE_REGISTERING	1
#define SN_NDSL_RESOURCE_REGISTERED		2


/* * * * * * * * * * * * * */
/* * * * STRUCTURES  * * * */
/* * * * * * * * * * * * * */

/**
 * \brief Address structure of Packet data
 */
typedef struct sn_nsdl_addr_
{
    sn_nsdl_addr_type_e     type;

    uint8_t                 addr_len;
    uint8_t                *addr_ptr;

    uint16_t                port;

} sn_nsdl_addr_s;

/**
 * \brief Used for creating manually registration message with sn_coap_register()
 */
typedef struct registration_info_
{
	uint8_t *endpoint_ptr;			/**< Endpoint name */
	uint8_t endpoint_len;

	uint8_t *endpoint_type_ptr;		/**< Endpoint type */
	uint8_t endpoint_type_len;

	uint8_t *links_ptr;				/**< Resource registration string */
	uint16_t links_len;

} registration_info_t;

#endif /* SN_NSDL_H_ */

#ifdef __cplusplus
}
#endif