/**
 * @file slots.h
 * @brief Parking slot management functions.
 *
 * This module provides functions for managing parking slot allocation,
 * assignment, and availability tracking.
 */

#ifndef SLOTS_H
#define SLOTS_H

#include "common.h"

/**
 * @brief Find the first available free parking slot.
 *
 * @param[in] slots Array of parking slots
 * @param[in] count Number of slots in the array
 *
 * @return ID of first free slot, or -1 if no slots are available
 */
int find_free_slot(const Slot *slots, size_t count);

/**
 * @brief Assign a vehicle to a specific parking slot.
 *
 * @param[in,out] slots Array of parking slots
 * @param[in] count Number of slots in the array
 * @param[in] slot_id ID of the slot to assign
 * @param[in] plate Vehicle license plate
 *
 * @return true if assignment succeeds, false if slot is invalid or occupied
 */
bool assign_slot(Slot *slots, size_t count, int slot_id, const char *plate);

/**
 * @brief Release a parked vehicle from a slot.
 *
 * @param[in,out] slots Array of parking slots
 * @param[in] count Number of slots in the array
 * @param[in] slot_id ID of the slot to release
 *
 * @return true if release succeeds, false if slot is invalid or already free
 */
bool release_slot(Slot *slots, size_t count, int slot_id);

/**
 * @brief Count the number of free parking slots.
 *
 * @param[in] slots Array of parking slots
 * @param[in] count Number of slots in the array
 *
 * @return Number of free slots available
 */
int count_free_slots(const Slot *slots, size_t count);

#endif // SLOTS_H
