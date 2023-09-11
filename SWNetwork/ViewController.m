//
//  ViewController.m
//  SWNetwork
//
//  Created by fengjianfeng on 2023/5/8.
//

#import "ViewController.h"
#import "SWBaseRequestModel.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    NSArray * a = [SWBaseRequestModel modelPropertyBlacklist];
    NSLog(@"%@", a);
}


@end
