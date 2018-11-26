//
//  XCDateUnit.h
//  XCDateUnitExample
//
//  Created by 樊小聪 on 2018/5/14.
//  Copyright © 2018年 樊小聪. All rights reserved.
//


/*
 *  备注：处理与时间相关的逻辑 🐾
 */

#import <Foundation/Foundation.h>

@interface XCDateUnit : NSObject

/**
 *  是否是润年
 */
+ (BOOL)isLeapYear:(NSInteger)year;
+ (BOOL)isLeapYearOfDate:(NSDate *)date;


/**
 *  判断两个日期的年份是否相同
 *  判断两个日期的年份和月份是否相同
 *  判断同修日期的年月日是否相同
 */
+ (BOOL)isEqualYearBetweenDate:(NSDate *)date andDate:(NSDate *)otherDate;
+ (BOOL)isEqualYearMonthBetweenDate:(NSDate *)date andDate:(NSDate *)otherDate;
+ (BOOL)isEqualYearMonthDayBetweenDate:(NSDate *)date andDate:(NSDate *)otherDate;


/**
 *
 *  ------------------------
 *      按照 “天” 进行比较
 *  ------------------------
 *
 *  判断某日期是否在另外一个日期之前
 *  判断某日期是否在另外一个日期之后
 *  判断某日期是否在两个日期之间
 */
+ (BOOL)date:(NSDate *)dateA isEqualOrBefore:(NSDate *)dateB;
+ (BOOL)date:(NSDate *)dateA isEqualOrAfter:(NSDate *)dateB;
+ (BOOL)date:(NSDate *)date isEqualOrAfter:(NSDate *)startDate andEqualOrBefore:(NSDate *)endDate;

/**
 *  是星期几
 */
+ (NSString *)weekday;
+ (NSString *)weekdayOfDate:(NSDate *)date;

/**
 *  将日期转化为指定格式的时间字符串
 *  将毫秒数字符串转化为指定格式的时间字符串
 *  将时间字符串转化为指定格式的日期
 *  将日期转化为指定格式的日期
 */
+ (NSString *)stringFromDate:(NSDate *)date format:(NSString *)fmt;
+ (NSString *)stringFromMilliseconds:(NSString *)milliseconds format:(NSString *)fmt;
+ (NSDate *)dateFromString:(NSString *)string format:(NSString *)fmt;
+ (NSDate *)dateFromDate:(NSDate *)date format:(NSString *)fmt;

/**
 *  返回某个日期偏移指定天数的日期
 *  返回某个日期偏移指定月数的日期
 *  返回两个日期之间相隔的天数
 *  返回两个日期之间相隔的月数
 */
+ (NSDate *)dateByDate:(NSDate *)date offsetDays:(NSInteger)days;
+ (NSDate *)dateByDate:(NSDate *)date offsetMonths:(NSInteger)months;
+ (NSInteger)daysBetweenDate:(NSDate *)beginDate endDate:(NSDate *)endDate;
+ (NSInteger)monthsBetweenDate:(NSDate *)beginDate endDate:(NSDate *)endDate;


/**
 *  当月有多少天
 *  某年的某月有多少天
 *  当月的第一天
 *  指定日期所在月份的第一天
 *  当月的最后一天
 *  指定日期所在月份的最后一天
 */
+ (NSInteger)daysOfCurrentMonth;
+ (NSInteger)daysOfYear:(NSInteger)year month:(NSInteger)month;
+ (NSDate *)dateMonthBegin;
+ (NSDate *)dateMonthBeginOfDate:(NSDate *)date;
+ (NSDate *)dateMonthEnd;
+ (NSDate *)dateMonthEndOfDate:(NSDate *)date;


@end
