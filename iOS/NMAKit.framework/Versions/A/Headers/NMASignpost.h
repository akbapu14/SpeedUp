/***************************************************************
 * Copyright © 2011-2015 HERE Global B.V. All rights reserved. *
 **************************************************************/

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */


/**
 * \class NMASignpost NMASignpost.h "NMASignpost.h"
 *
 * This class stores signpost information along the Route.
 *
 */
@interface NMASignpost : NSObject

/**
 *  The exit text of the signpost.
 */
@property (nonatomic, readonly) NSString *exitText;

@end

/** @} */
