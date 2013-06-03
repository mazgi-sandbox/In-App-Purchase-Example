//
//  IAPProductTypeListViewController.m
//  In-App-Purchase-Example
//
//  Created by matsuki hidenori on 6/3/13.
//
//

#import "IAPProductTypeListViewController.h"
#import "IAPProductType.h"

@interface IAPProductTypeListViewController ()
@property (strong, nonatomic) NSDictionary* types;
@property (strong, nonatomic) NSArray* typeKeys;
@end

@implementation IAPProductTypeListViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.types = [NSDictionary dictionaryWithObjectsAndKeys:
                      @"consumable products", IAPProductTypeKeyConsumable,
                      @"non consumable products", IAPProductTypeKeyNonConsumable,
                      @"auto renewable subscriptions", IAPProductTypeKeyAutoRenewableSubscriptions,
                      @"free subscription", IAPProductTypeKeyFreeSubscription,
                      @"non renewing subscription", IAPProductTypeKeyNonRenewingSubscription,
                      nil];
        self.typeKeys = [self.types allKeys];
    }
    return self;
}

#pragma mark - UITableViewDataSource methods

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.typeKeys count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"CellIdentifier"];
    if (!cell) {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"CellIdentifier"];
    }
    cell.textLabel.text = [self.types objectForKey:[self.typeKeys objectAtIndex:indexPath.row]];
    return cell;
}

#pragma mark - view lifecycle

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

@end
