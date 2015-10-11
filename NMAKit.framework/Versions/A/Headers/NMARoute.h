/***************************************************************
 * Copyright © 2011-2015 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import "NMARoutingMode.h"

@class NMAGeoBoundingBox;
@class NMAWaypoint;
@class NMAManeuver;
@class NMAMapPolyline;
@class NMARouteTta;

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * \class NMARoute NMARoute.h "NMARoute.h"
 *
 * \brief Represents a path (a collection of maneuvers) connecting two or more waypoints.
 *
 * Waypoints may be thought of as the input to a route calculation whereas maneuvers are
 * the results of calculating a route.
 */
@interface NMARoute : NSObject

/**
 * \brief A constant used to indicate the whole route should be used in route leg selection.
 */
FOUNDATION_EXPORT NSInteger const NMARouteSublegWhole;

/**
 * \brief The starting NMAWaypoint for the %NMARoute.
 */
@property (nonatomic, readonly, weak) NMAWaypoint *start;

/**
 *  The destination NMAWaypoint for the %NMARoute.
 */
@property (nonatomic, readonly, weak) NMAWaypoint *destination;

/**
 *  Array of NMAWaypoint for all waypoints of the %NMARoute.
 */
@property (nonatomic, readonly, strong) NSArray *waypoints;

/**
 *  The length of the %NMARoute, in meters. This is the actual distance
 * covered if you were to travel the route.
 */
@property (nonatomic, readonly) NSUInteger length;

/**
 *  Returns the number of sub-legs the route has
 * a subleg is the part of a route between two stop waypoints.
 */
@property (nonatomic, readonly) NSUInteger sublegCount;

/**
 * \brief The NMARouteTta object of traveling the whole NMARoute
 */
@property (nonatomic, readonly) NMARouteTta *tta;

/**
 * \brief The NMARouteTta object of traveling the specified subLeg of the NMARoute
 *
 * \param subleg The index of the subleg on the NMARoute to be used for this calculation. If
 * NMARouteSublegWhole is provided, it is the same as tta property.
 */
- (NMARouteTta *)ttaForSubleg:(NSUInteger)subleg;

/**
 *  The smallest NMAGeoBoundingBox that contains the entire %NMARoute.
 */
@property (nonatomic, readonly, strong) NMAGeoBoundingBox *boundingBox;

/**
 *  Array of NMAManeuver to represent all the maneuvers that travelers will
 * encounter along the %NMARoute.
 */
@property (nonatomic, readonly, strong) NSArray *maneuvers;

/**
 *  The NMAMapPolyline representation of the route.
 */
@property (nonatomic, readonly, strong) NMAMapPolyline *mapPolyline;

/**
 *  The NMARoutingMode for the %NMARoute.
 */
@property (nonatomic, readonly, strong) NMARoutingMode *routingMode;

/**
 * A user-defined tag to identify the %NMARoute
 *
 * \note The default value for userTag is empty string.
 */
@property (nonatomic, strong) NSString *userTag;

@end
/**  @}  */
