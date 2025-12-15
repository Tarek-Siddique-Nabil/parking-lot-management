/**
 * @file vehicle.h
 * @brief Vehicle entry and exit management functions.
 *
 * This module handles vehicle parking sessions, ticket generation,
 * and vehicle record management.
 */

#ifndef VEHICLE_H
#define VEHICLE_H

#include "common.h"

/**
 * @brief Generate a unique parking ticket ID.
 *
 * @param[out] ticket_id Buffer to store the generated ticket ID
 * @param[in] size Size of the ticket ID buffer
 *
 * @note Ensure buffer is at least MAX_TICKET_LEN bytes
 */
void generate_ticket(char *ticket_id, size_t size);

/**
 * @brief Find a vehicle record by license plate.
 *
 * @param[in] vehicles Array of vehicle records
 * @param[in] count Number of records in the array
 * @param[in] plate License plate to search for
 *
 * @return Index of the vehicle record, or -1 if not found
 */
int find_vehicle_by_plate(const VehicleRecord *vehicles, size_t count, const char *plate);

/**
 * @brief Create a new vehicle parking entry.
 *
 * @param[out] vehicle Pointer to vehicle record to initialize
 * @param[in] plate Vehicle license plate
 * @param[in] slot_id Assigned parking slot ID
 *
 * @return true if entry is created successfully, false otherwise
 */
bool create_vehicle_entry(VehicleRecord *vehicle, const char *plate, int slot_id);

/**
 * @brief Mark a vehicle's exit from the parking lot.
 *
 * @param[in,out] vehicle Pointer to vehicle record to update
 * @param[in] fee Calculated parking fee
 *
 * @return true if exit is processed successfully, false otherwise
 */
bool mark_vehicle_exit(VehicleRecord *vehicle, double fee);

#endif // VEHICLE_H
