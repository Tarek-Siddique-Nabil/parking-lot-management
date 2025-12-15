/**
 * @file billing.h
 * @brief Parking fee calculation and receipt generation functions.
 *
 * This module handles parking fee calculations based on entry and exit times,
 * as well as receipt formatting for parking sessions.
 */

#ifndef BILLING_H
#define BILLING_H

#include "common.h"

/**
 * @brief Calculate the parking fee for a session.
 *
 * @param[in] entry_ts Entry timestamp (ISO format: YYYY-MM-DDTHH:MM:SS)
 * @param[in] exit_ts Exit timestamp (ISO format: YYYY-MM-DDTHH:MM:SS)
 * @param[in] rate_per_hour Hourly parking rate
 *
 * @return Calculated parking fee as a floating-point amount
 */
double calculate_fee(const char *entry_ts, const char *exit_ts, double rate_per_hour);

/**
 * @brief Format a parking receipt for a vehicle session.
 *
 * @param[in] vehicle Pointer to vehicle record with session details
 * @param[in] fee The calculated parking fee
 * @param[out] out_buf Buffer to store formatted receipt
 * @param[in] bufsize Size of the output buffer
 *
 * @return Pointer to the formatted receipt string, or NULL on error
 */
char *format_receipt(const VehicleRecord *vehicle, double fee, char *out_buf, size_t bufsize);

#endif // BILLING_H
