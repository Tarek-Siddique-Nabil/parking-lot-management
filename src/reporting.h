/**
 * @file reporting.h
 * @brief Reporting and analysis functions.
 *
 * This module provides functions for generating reports on parking lot
 * status and financial metrics.
 */

#ifndef REPORTING_H
#define REPORTING_H

#include "common.h"

/**
 * @brief Generate a report of current parking slot status.
 *
 * Displays summary statistics including total slots, occupied slots,
 * and availability information.
 *
 * @param[in] slots Array of parking slots
 * @param[in] count Number of slots in the array
 */
void report_slot_status(const Slot *slots, size_t count);

/**
 * @brief Generate a revenue report from audit logs.
 *
 * Calculates total revenue, transaction counts, and other financial metrics
 * based on the provided log entries.
 *
 * @param[in] logs Array of audit log entries
 * @param[in] count Number of log entries in the array
 */
void report_revenue(const LogEntry *logs, size_t count);

#endif // REPORTING_H
