/***************************************************************
 * Copyright © 2011-2015 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import "NMAMapObject.h"

@class NMAGeoCoordinates;
@class UIColor;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */
/**
 * \class NMAMapCircle NMAMapCircle.h "NMAMapCircle.h"
 * Represents a NMAMapObject in the shape of a circle. %NMAMapCircle is helper
 * class for creating and updating a NMAMapPolygon representing a circle.
 */
@interface NMAMapCircle : NMAMapObject

/**
 * A convenience method to construct a NMAMapCircle at specified coordinates.
 *
 * \param coordinates The location of the map circle center
 */
+ (instancetype)mapCircleWithGeoCoordinates:(NMAGeoCoordinates*)coordinates;

/**
 * A convenience method to construct a NMAMapCircle at specified coordinates
 * and with a given radius.
 *
 * \param coordinates The location of the map circle center
 * \param radius The radius (in meters) of the map circle
 */
+ (instancetype)mapCircleWithGeoCoordinates:(NMAGeoCoordinates*)coordinates radius:(double)radius;

/**
 * The %NMAGeoCoordinates representing the center of the %NMAMapCircle.
 *
 * \note The NMAViewObject location property will return the same coordinates.
 */
@property (nonatomic, strong) NMAGeoCoordinates *center;

/**
 * The radius of the %NMAMapCircle, in meters.
 *
 * \note The default value is 1 meter
 */
@property (nonatomic) double radius;

/**
 * The line color for the %NMAMapCircle.
 *
 * \note The default value (in RGBA) is 0xC00066FF.
 */
@property (nonatomic, strong) UIColor *lineColor;

/**
 * The fill color for the %NMAMapCircle.
 *
 * \note The default value (in RGBA) is 0x00498A55
 */
@property (nonatomic, strong) UIColor *fillColor;

/**
 * The line width, in pixels, for the %NMAMapCircle border. The supported
 * value range is [0..100].
 *
 * \note The default value is 0 pixels
 */
@property (nonatomic) NSUInteger lineWidth;

/**
 * Initializes a %NMAMapCircle instance with the specified %NMAGeoCoordinates
 * as the center and a radius of 1 meter.
 *
 * \param coordinates A %NMAGeoCoordinates representing the %NMAMapCircle center
 * \return The %NMAMapCircle
 */
- (instancetype)initWithGeoCoordinates:(NMAGeoCoordinates *)coordinates;

/**
 * Initializes a %NMAMapCircle instance with the specified %NMAGeoCoordinates
 * as the center and the specified \p double as the radius (in meters).
 *
 * \param coordinates  A %NMAGeoCoordinates representing the %NMAMapCircle center
 * \param radius The radius of the circle
 * \return The %NMAMapCircle
 */
- (instancetype)initWithGeoCoordinates:(NMAGeoCoordinates *)coordinates radius:(double)radius;

@end
/** @}  */
