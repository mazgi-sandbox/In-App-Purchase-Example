//
//  IAPProductListViewController.m
//  In-App-Purchase-Example
//
//  Created by matsuki hidenori on 6/3/13.
//
//

#import "IAPProductListViewController.h"
#import "IAPProductDetailViewController.h"

@interface IAPProductListViewController ()
@property (strong, nonatomic) NSMutableArray* productIdentifiers;
@end

@implementation IAPProductListViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.productIdentifiers = [NSMutableArray array];
    }
    return self;
}

#pragma mark - UITableViewDataSource methods

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.productIdentifiers count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"CellIdentifier"];
    if (!cell) {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"CellIdentifier"];
    }
    //TODO: replace product information
    cell.textLabel.text = [self.productIdentifiers objectAtIndex:indexPath.row];
    return cell;
}

#pragma mark - UITableViewDelegate methods

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    IAPProductDetailViewController* productDetailViewController = [[IAPProductDetailViewController alloc]initWithNibName:nil bundle:nil];
    //TODO: set product information
    [self.navigationController pushViewController:productDetailViewController animated:YES];

    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

#pragma mark - view lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.title = @"Products";
    //TODO: temporarily hard-coding
    [self.productIdentifiers addObject:@"consumable_01"];
    [self.productIdentifiers addObject:@"consumable_02"];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
