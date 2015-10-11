/***************************************************************
 * Copyright © 2011-2015 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import "NMALink.h"

@class NMADiscoveryRequest;

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMADiscoveryLink NMADiscoveryLink.h "NMADiscoveryLink.h"
 *
 * \brief Represents a discovery search results link that can be used to perform another discovery search.
 */
@interface NMADiscoveryLink : NMALink

/**
 * Creates an NMADiscoveryRequest object to perform another NMADiscoveryPage request.
 *
 * \note Attempts to read this property could return nil.
 *
 * \return The NMADiscoveryRequest
 */
- (NMADiscoveryRequest *)request;

@end

/** @} */
