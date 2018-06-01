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

/**
 *  当前日期是星期几
 */
+ (NSString *)weekday;

/**
 *  星期几
 *
 *  @param date 日期
 */
+ (NSString *)weekdayOfDate:(NSDate *)date;

/**
 *  将 Date 转化为指定格式的时间字符串
 *
 *
 *  @param date 日期
 *  @param fmt  格式
 */
+ (NSString *)stringFromDate:(NSDate *)date format:(NSString *)fmt;

/**
 *  将 毫秒数字符串转化为指定格式的时间字符串
 *
 *  @param milliseconds 毫秒数字符串
 *  @param fmt 格式
 */
+ (NSString *)stringFromMilliseconds:(NSString *)milliseconds format:(NSString *)fmt;

/**
 *  将指定格式的时间字符串转化为日期
 *
 *  @param string 时间字符串
 *  @param fmt    格式
 */
+ (NSDate *)dateFromString:(NSString *)string format:(NSString *)fmt;

/**
 *  返回某个日期偏移指定天数的日期
 *
 *  @param date 日期
 *  @param days 偏移天数
 */
+ (NSDate *)dateByDate:(NSDate *)date offsetDays:(NSInteger)days;

/**
 *  返回某个日期偏移指定月数的日期
 *
 *  @param date   日期
 *  @param months 偏移月数
 */
+ (NSDate *)dateByDate:(NSDate *)date offsetMonths:(NSInteger)months;

/**
 *  返回两个日期之间相隔的天数
 *
 *  @param beginDate 开始时间
 *  @param endDate   结束时间
 */
+ (NSInteger)daysBetweenDate:(NSDate *)beginDate endDate:(NSDate *)endDate;

/**
 *  返回两个日期之间相隔的月数
 *
 *  @param beginDate 开始时间
 *  @param endDate   结束时间
 */
+ (NSInteger)monthsBetweenDate:(NSDate *)beginDate endDate:(NSDate *)endDate;

/**
 *  当月有多少天
 */
+ (NSInteger)daysOfCurrentMonth;

/**
 *  某年的某月有多少天
 *
 *  @param year  年份
 *  @param month 月份(1-12月)
 */
+ (NSInteger)daysOfYear:(NSInteger)year month:(NSInteger)month;


@end
