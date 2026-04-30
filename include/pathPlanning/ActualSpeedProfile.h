// Copyright (c) 2026 UltiMaker
// CuraEngine is released under the terms of the AGPLv3 or higher

#ifndef ACTUAL_SPEED_PROFILE_H
#define ACTUAL_SPEED_PROFILE_H

#include "settings/types/Velocity.h"

namespace cura
{

/*!
 * \brief Planner-resolved speed profile for one emitted motion segment.
 *
 * Feedrates are in mm/s. Distances are in mm from the start of the segment.
 * A renderer can split the segment at accelerate_until and decelerate_after:
 * [0, accelerate_until] accelerates from entry to cruise/peak, the middle
 * cruises if accelerate_until < decelerate_after, and [decelerate_after,
 * segment end] decelerates from cruise/peak to exit.
 */
struct ActualSpeedProfile
{
    Velocity entry_feedrate;
    Velocity cruise_feedrate;
    Velocity exit_feedrate;
    double accelerate_until;
    double decelerate_after;
};

} // namespace cura

#endif // ACTUAL_SPEED_PROFILE_H
