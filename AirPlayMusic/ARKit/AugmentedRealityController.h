//
//  AugmentedRealityController.h
//  AR Kit
//
//  Modified by Niels W Hansen on 12/31/11.
//  Copyright 2013 Agilite Software All rights reserved.
//

#import "ARKit.h"

@class ARCoordinate;

@interface AugmentedRealityController : NSObject <UIAccelerometerDelegate, CLLocationManagerDelegate> {
	
@private
	double	latestHeading;
	double  degreeRange;
    float	viewAngle;
	float   prevHeading;
    int     cameraOrientation;

}

@property BOOL scaleViewsBasedOnDistance;
@property BOOL rotateViewsBasedOnPerspective;
@property BOOL debugMode;

@property double maximumScaleDistance;
@property double minimumScaleFactor;
@property double maximumRotationAngle;

@property (nonatomic, strong) UIAccelerometer           *accelerometerManager;
@property (nonatomic, strong) CLLocationManager         *locationManager;
@property (nonatomic, strong) ARCoordinate              *centerCoordinate;
@property (nonatomic, strong) CLLocation                *centerLocation;
@property (nonatomic, strong) UIView                    *displayView;
@property (nonatomic, strong) UIViewController          *parentViewController;
@property (nonatomic, strong) AVCaptureSession          *captureSession;
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;
@property (nonatomic, weak) id<ARDelegate> delegate;
@property (nonatomic, strong) UILabel  *debugView;
@property (nonatomic, strong) NSMutableArray	*coordinates;

- (id)initWithView:(UIView*)arView parentViewController:(UIViewController*)parentVC withDelgate:(id<ARDelegate>) aDelegate;
- (void)setupDebugPostion;
- (void)updateLocations;
- (void)stopListening;
- (void)unloadAV;

// Adding coordinates to the underlying data model.
- (void)addCoordinate:(ARGeoCoordinate *)coordinate;

// Removing coordinates
- (void)removeCoordinate:(ARGeoCoordinate *)coordinate;
- (void)removeCoordinates:(NSArray *)coordinateArray;
- (void)updateDebugMode:(BOOL) flag;


@end