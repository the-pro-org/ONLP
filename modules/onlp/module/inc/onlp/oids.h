/************************************************************
 * <bsn.cl fy=2014 v=onl>
 * </bsn.cl>
 ************************************************************
 *
 * ONLP Platform Object Identifiers.
 *
 ***********************************************************/
#ifndef __ONLP_OID_H__
#define __ONLP_OID_H__

/**
 * System peripherals are identified by a 32bit OID.
 *
 * The First byte is the object-class identifier:
 *    Thermal sensor object
 *    Fan object
 *    PSU object
 *    LED object
 *    MODULE object
 *    etc..
 * The remaining bytes are the object id.
 */

typedef uint32_t onlp_oid_t;

/* <auto.start.enum(onlp_oid_type).define> */
/** onlp_oid_type */
typedef enum onlp_oid_type_e {
    ONLP_OID_TYPE_THERMAL = 1,
    ONLP_OID_TYPE_FAN = 2,
    ONLP_OID_TYPE_PSU = 3,
    ONLP_OID_TYPE_LED = 4,
    ONLP_OID_TYPE_MODULE = 5,
} onlp_oid_type_t;
/* <auto.end.enum(onlp_oid_type).define> */

/**
 * Get the or set the type of an OID
 */
#define ONLP_OID_TYPE_GET(_id) ( ( (_id) >> 24) )
#define ONLP_OID_TYPE_CREATE(_type, _id) ( ( (_type) << 24) | (_id))

#define ONLP_THERMAL_ID_CREATE(_id) ONLP_OID_TYPE_CREATE(ONLP_OID_TYPE_THERMAL, _id)
#define ONLP_FAN_ID_CREATE(_id)     ONLP_OID_TYPE_CREATE(ONLP_OID_TYPE_FAN, _id)
#define ONLP_PSU_ID_CREATE(_id)     ONLP_OID_TYPE_CREATE(ONLP_OID_TYPE_PSU, _id)
#define ONLP_LED_ID_CREATE(_id)     ONLP_OID_TYPE_CREATE(ONLP_OID_TYPE_LED, _id)
#define ONLP_MODULE_ID_CREATE(_id)  ONLP_OID_TYPE_CREATE(ONLP_OID_TYPE_MODULE, _id)

#define ONLP_OID_IS_THERMAL(_id) ONLP_OID_IS_TYPE(ONLP_OID_TYPE_THERMAL)
#define ONLP_OID_IS_FAN(_id)     ONLP_OID_IS_TYPE(ONLP_OID_TYPE_FAN)
#define ONLP_OID_IS_PSU(_id)     ONLP_OID_IS_TYPE(ONLP_OID_TYPE_PSU)
#define ONLP_OID_IS_LED(_id)     ONLP_OID_IS_TYPE(ONLP_OID_TYPE_LED)
#define ONLP_OID_IS_MODULE(_id)  ONLP_OID_IS_TYPE(ONLP_OID_TYPE_MODULE)

/**
 * All OIDs have user-level description strings:
 */
#define ONLP_OID_DESC_SIZE 128

typedef char onlp_oid_desc_t[ONLP_OID_DESC_SIZE];

/* fixme */
typedef onlp_oid_t onlp_oid_table_t[32];


#endif /* __ONLP_OID_H__ */