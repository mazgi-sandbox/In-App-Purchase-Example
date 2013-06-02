//
//  IAPFirstViewController.m
//  In-App-Purchase-Example
//
//  Created by matsuki hidenori on 6/2/13.
//
//

#import "IAPFirstViewController.h"

@interface IAPFirstViewController ()
@property (weak, nonatomic) IBOutlet UITableView *productsTableView;

@end

@implementation IAPFirstViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidUnload {
    [self setProductsTableView:nil];
    [super viewDidUnload];
}
@end
