//
//  XCDateUnit.m
//  XCDateUnitExample
//
//  Created by 樊小聪 on 2018/5/14.
//  Copyright © 2018年 樊小聪. All rights reserved.
//


/*
 *  备注：处理与时间相关的逻辑 🐾
 */

#import "XCDateUnit.h"

@implementation XCDateUnit

+ (BOOL)isLeapYear:(NSInteger)year
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    
    return NO;
}

+ (NSString *)weekday
{
    return [self weekdayOfDate:[NSDate date]];
}

+ (NSString *)weekdayOfDate:(NSDate *)date
{
    NSArray *weekdays = @[@"星期日", @"星期一", @"星期二", @"星期三",
                          @"星期四", @"星期五", @"星期六"];
    
    NSDateComponents *components = [self dateComponentsWithDate:date];
    return weekdays[components.weekday-1];
}


+ (NSString *)stringFromDate:(NSDate *)date format:(NSString *)fmt
{
    NSDateFormatter *dateFmt = [[NSDateFormatter alloc] init];
    [dateFmt setLocale:[[NSLocale alloc] initWithLocaleIdentifier:@"zh_CN"]];
    [dateFmt setDateFormat:fmt];
    return [dateFmt stringFromDate:date];
}


+ (NSString *)stringFromMilliseconds:(NSString *)milliseconds format:(NSString *)fmt
{
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:(milliseconds.floatValue * 0.001)];
    NSDateFormatter *dateFmt = [[NSDateFormatter alloc] init];
    [dateFmt setLocale:[[NSLocale alloc] initWithLocaleIdentifier:@"zh_CN"]];
    [dateFmt setDateFormat:fmt];
    return [dateFmt stringFromDate:date];
}


+ (NSDate *)dateFromString:(NSString *)string format:(NSString *)fmt
{
    NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
    [dateFormat setLocale:[[NSLocale alloc] initWithLocaleIdentifier:@"zh_CN"]];
    [dateFormat setDateFormat:fmt];
    return [dateFormat dateFromString:string];
}


+ (NSDate *)dateByDate:(NSDate *)date offsetDays:(NSInteger)days
{
    NSTimeInterval aTimeInterval = [date timeIntervalSinceReferenceDate] + 24 * 60 * 60 * days;
    return [NSDate dateWithTimeIntervalSinceReferenceDate:aTimeInterval];
}

+ (NSDate *)dateByDate:(NSDate *)date offsetMonths:(NSInteger)months
{
    NSDateComponents *comps = [[NSDateComponents alloc] init];
    [comps setMonth:months];
    NSCalendar *calender = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    return [calender dateByAddingComponents:comps toDate:date options:0];
}

+ (NSInteger)daysBetweenDate:(NSDate *)beginDate endDate:(NSDate *)endDate
{
    /// 得到间隔秒数
    NSTimeInterval aTimeInterval = [endDate timeIntervalSinceDate:beginDate];
    return (NSInteger)aTimeInterval / (24 * 60 * 60);
}

+ (NSInteger)monthsBetweenDate:(NSDate *)beginDate endDate:(NSDate *)endDate
{
    NSDateComponents *beginComponents = [self dateComponentsWithDate:beginDate];
    NSDateComponents *endComponents = [self dateComponentsWithDate:endDate];
    
    /// 如果结束时间的年份 > 开始时间的年份
    if (endComponents.year > beginComponents.year) {
        return (endComponents.year - beginComponents.year) * 12 + endComponents.year - beginComponents.year;
    }
    
    /// 同一年
    return endComponents.year - beginComponents.year;
}

+ (NSInteger)daysOfCurrentMonth
{
    NSCalendar *calendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    NSRange range = [calendar rangeOfUnit:NSCalendarUnitDay inUnit:NSCalendarUnitMonth forDate:[NSDate date]];
    NSUInteger numberOfDaysInMonth = range.length;
    return numberOfDaysInMonth;
}

+ (NSInteger)daysOfYear:(NSInteger)year month:(NSInteger)month
{
    NSArray *months_31 = @[@"1", @"3", @"5", @"7", @"8", @"10", @"12"];
    
    /// 31天
    if ([months_31 containsObject:@(month).description]) {
        return 31;
    }
    
    /// 二月
    if (2 == month) {
        // 润年 29天
        if ([self isLeapYear:year]) {
            return 29;
        }
        
        // 非润年 28天
        return 28;
    }
    
    return 30;
}

#pragma mark - 🔒 👀 Privite Method 👀

+ (NSDateComponents *)dateComponentsWithDate:(NSDate *)date
{
    NSCalendar *calendar = [NSCalendar currentCalendar];
    unsigned flags = NSCalendarUnitYear |
    NSCalendarUnitMonth |
    NSCalendarUnitWeekday|
    NSCalendarUnitDay |
    NSCalendarUnitHour |
    NSCalendarUnitMinute |
    NSCalendarUnitSecond |
    NSCalendarUnitWeekdayOrdinal;
    
    return [calendar components:flags fromDate:date];
}

@end
