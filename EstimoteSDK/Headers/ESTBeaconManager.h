//
//  ESTBeaconManager.h
//  private-sdk-ios7
//
//  Version : 1.0.0
//  Created by Marcin Klimek on 9/18/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ESTBeaconRegion.h"
#import "ESTBeacon.h"

@class ESTBeaconManager;

/**
 
 The ESTBeaconManagerDelegate protocol defines the delegate methods to respond for related events.
 */

@protocol ESTBeaconManagerDelegate <NSObject>

@optional

/**
 * Method returns NSArray of all discoverd beacons
 *
 * @param manager estimote beacon manager
 * @param beacons all beacons as ESTBeacon objects
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(ESTBeaconRegion *)region;

/**
 * Method returns NSArray of all discoverd beacons
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 * @param error object containing error info
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
rangingBeaconsDidFailForRegion:(ESTBeaconRegion *)region
           withError:(NSError *)error;


/**
 * Method returns NSArray of all discoverd beacons
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 * @param error object containing error info
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
monitoringDidFailForRegion:(ESTBeaconRegion *)region
           withError:(NSError *)error;
/**
 * Method triggered when estimote beacon region enter
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
      didEnterRegion:(ESTBeaconRegion *)region;


/**
 * Method triggered when estimote beacon region exit
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
       didExitRegion:(ESTBeaconRegion *)region;

/**
 * Method triggered when estimote beacon region exit
 *
 * @param manager estimote beacon manager
 * @param state estimote beacon region state
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
     didDetermineState:(CLRegionState)state
             forRegion:(ESTBeaconRegion *)region;

/**
 * Method triggered when estimote beacon region exit
 *
 * @param manager estimote beacon manager
 * @param error info about any error
 *
 * @return void
 */
-(void)beaconManagerDidStartAdvertising:(ESTBeaconManager *)manager
                                  error:(NSError *)error;

/**
 * Method returns NSArray of all discoverd bluetooth beacons
 *
 * @param manager estimote beacon manager
 * @param beacons all beacons as ESTBeacon objects
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
          didDiscoverBeacons:(NSArray *)beacons
                    inRegion:(ESTBeaconRegion *)region;

/**
 * Method returns NSArray of all discoverd bluetooth beacons
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
    didFailDiscoveryInRegion:(ESTBeaconRegion *)region;

@end



/**
 
 The ESTBeaconManager class defines the interface for handling and configuring the estimote beacons and get related events to your application. You use an instance of this class to establish the parameters that describes each beacon behavior. You can also use a beacon manager object to retrieve all beacons in range.
 
 A beacon manager object provides support for the following location-related activities:
 
 * Monitoring distinct regions of interest and generating location events when the user enters or leaves those regions (works in background mode).
 * Reporting the range to nearby beacons and ther distance for the device.
 
 */

@interface ESTBeaconManager : NSObject <CLLocationManagerDelegate>

@property (nonatomic, weak) id <ESTBeaconManagerDelegate> delegate;

@property (nonatomic) BOOL avoidUnknownStateBeacons;

@property (nonatomic, strong) ESTBeaconRegion*         virtualBeaconRegion;

/**
 * Discovers all Estimote beacons that are visible in range.
 * returned Array contain ESTBeacon objects.
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)startRangingBeaconsInRegion:(ESTBeaconRegion*)region;

/**
 * Start to monitor for particular region.
 * Functionality works in the background mode as well.
 * Every time you enter or leave region appropriet
 * delegate method inovked: beaconManager:didEnterRegtion:
 * beaconManager:didExitRegion:
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)startMonitoringForRegion:(ESTBeaconRegion*)region;

/**
 * Starts monitoring Estimote beacons regions.
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)stopRangingBeaconsInRegion:(ESTBeaconRegion*)region;

/**
 * Start to monitor for particular region. 
 * Functionality works in the background mode as well.
 * Every time you enter or leave region 
 * delegate method inovked: beaconManager:didEnterRegtion:
 * beaconManager:didExitRegion:
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)stopMonitoringForRegion:(ESTBeaconRegion *)region;

/**
 * Methods allows to validate current state for particular region
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)requestStateForRegion:(ESTBeaconRegion *)region;

/**
 * Methods allows to turn device into virtual estimote beacon.
 *
 * @param major minor beacon value
 * @param minor major beacon value
 * @param identifier unique identifier for you region
 *
 * @return void
 */
-(void)startAdvertisingWithMajor:(ESTBeaconMajorValue)major
                       withMinor:(ESTBeaconMinorValue)minor
                  withIdentifier:(NSString*)identifier;


/**
 * Stop beacon advertising
 *
 * @return void
 */
-(void)stopAdvertising;

/**
 * Start beacon discovery process (bluetooth based)
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)startEstimoteBeaconsDiscoveryForRegion:(ESTBeaconRegion*)region;


/**
 * Stop beacon discovery process (bluetooth based)
 *
 * @return void
 */
-(void)stopEstimoteBeaconDiscovery;

@end

