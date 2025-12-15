/**
 * @file common.h
 * @brief Common data structures and constants for the parking lot management system.
 *
 * This header defines all shared types, enumerations, and constants used throughout
 * the parking lot management application, including user roles, slot status, and
 * various entity records.
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stddef.h>

/** @brief Maximum length for username strings (including null terminator) */
#define MAX_USERNAME_LEN 32
/** @brief Maximum length for password strings (including null terminator) */
#define MAX_PASSWORD_LEN 64
/** @brief Maximum length for role name strings (including null terminator) */
#define MAX_ROLE_LEN 16
/** @brief Maximum length for vehicle plate strings (including null terminator) */
#define MAX_PLATE_LEN 16
/** @brief Maximum length for ticket ID strings (including null terminator) */
#define MAX_TICKET_LEN 16
/** @brief Maximum length for timestamp strings - format: YYYY-MM-DDTHH:MM:SS (including null terminator) */
#define MAX_TIMESTAMP_LEN 20
/** @brief Maximum length for detail strings (including null terminator) */
#define MAX_DETAILS_LEN 256

/**
 * @enum Role
 * @brief User role enumeration.
 */
typedef enum {
	ROLE_ADMIN,      /**< Administrator role */
	ROLE_ATTENDANT   /**< Parking attendant role */
} Role;

/**
 * @enum SlotStatus
 * @brief Parking slot status enumeration.
 */
typedef enum {
	SLOT_FREE,      /**< Slot is available */
	SLOT_OCCUPIED   /**< Slot is occupied */
} SlotStatus;

/**
 * @struct User
 * @brief User account information.
 */
typedef struct {
	char username[MAX_USERNAME_LEN]; /**< User's login name */
	char password[MAX_PASSWORD_LEN]; /**< User's password (should be hashed in production) */
	Role role;                       /**< User's role and permissions */
} User;

/**
 * @struct Slot
 * @brief Parking slot information.
 */
typedef struct {
	int slot_id;                      /**< Unique slot identifier */
	SlotStatus status;                /**< Current occupancy status */
	char vehicle_plate[MAX_PLATE_LEN]; /**< License plate of parked vehicle */
} Slot;

/**
 * @struct VehicleRecord
 * @brief Vehicle parking session record.
 */
typedef struct {
	char ticket_id[MAX_TICKET_LEN];    /**< Unique parking ticket identifier */
	char plate[MAX_PLATE_LEN];         /**< Vehicle license plate */
	char entry_ts[MAX_TIMESTAMP_LEN];  /**< Entry timestamp */
	char exit_ts[MAX_TIMESTAMP_LEN];   /**< Exit timestamp */
	int slot_id;                       /**< Assigned parking slot ID */
	bool active;                       /**< True if vehicle is currently parked */
	double fee;                        /**< Computed parking fee */
} VehicleRecord;

/**
 * @struct Rate
 * @brief Parking rate configuration.
 */
typedef struct {
	double rate_per_hour;     /**< Hourly parking rate in currency units */
	double grace_minutes;     /**< Grace period in minutes before billing starts */
} Rate;

/**
 * @struct LogEntry
 * @brief Audit log entry for system events.
 */
typedef struct {
	char timestamp[MAX_TIMESTAMP_LEN]; /**< Event timestamp */
	char event_type[MAX_ROLE_LEN];    /**< Type of event (e.g., "entry", "exit", "error") */
	char details[MAX_DETAILS_LEN];    /**< Event details and description */
	double amount;                    /**< Associated monetary amount */
} LogEntry;

#endif // COMMON_H
