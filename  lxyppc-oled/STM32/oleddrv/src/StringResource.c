/*******************************************************************************
* File Name          : StringResource.c
* Author             : lxyppc
* Version            : V1.0
* Date               : 10-01-21
* Description        : String resouce file
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "menu.h"
#include "StringResource.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

const LPCSTR StringTable_ENG[STR_LAST] = 
{
  [STR_DEFAULT]               = "Press to quit...",
  [STR_ROOT]                  = "Quit",
  [STR_STATUS]                = "Status",
  [STR_TEST]                  = "Test",
  [STR_SETTING]               = "Setting",
  [STR_ABOUT]                 = "About",
  [STR_SETTING_CONTRAST]      = "Contrast",
  [STR_SETTING_TIME]          = "Time",
  [STR_STATUS_BAT]            = "Battary",
  [STR_STATUS_GRAVITY]        = "Gravity",
  [STR_SETTING_LANGUAGE]      = "Language",
  [STR_LANG_ENG]              = "English",
  [STR_LANG_CHS]              = "ChineseS",
  [STR_CHANGE_CONTRAST]       = "Change contrast:",
  [STR_SET_TIME]              = "Set time:",
  [STR_VIEW_BATTARY]          = "Battary status:",
  [STR_BAT_CHARGE]            = "Charging ...",
  [STR_BAT_FULL]              = "Charge finish",
  [STR_BAT_NORMAL]            = "Disconnected",
  [STR_BAT_CAPACITY]          = "Capacity:",
  [STR_BAT_VOLTAGE]           = "Voltage: ",
  [STR_ABOUT_0]               = "Oled Project 1.0",
  [STR_ABOUT_1]               = "lxyppc@163.com",
  [STR_ABOUT_2]               = "All rights reserved",
  [STR_OK]                    = "OK",
  [STR_CANCEL]                = "Cancel",
  [STR_JAN]                   = "Jan",
  [STR_FEB]                   = "Feb",
  [STR_MAR]                   = "Mar",
  [STR_APR]                   = "Apr",
  [STR_MAY]                   = "May",
  [STR_JUN]                   = "Jun",
  [STR_JUL]                   = "Jul",
  [STR_AUG]                   = "Aug",
  [STR_SEP]                   = "Sep",
  [STR_OCT]                   = "Oct",
  [STR_NOV]                   = "Nov",
  [STR_DEC]                   = "Dec",
  [STR_SUNDAY]                = "Sun",
  [STR_MONDAY]                = "Mon",
  [STR_TUESDAY]               = "Tue",
  [STR_WEDNESDAY]             = "Wed",
  [STR_THURSDAY]              = "Thu",
  [STR_FRIDAY]                = "Fri",
  [STR_SATURDAY]              = "Sat",
  [STR_AM]                    = "am",
  [STR_PM]                    = "pm",
  [STR_YEAR]                  = "  Year:",
  [STR_MONTH]                 = " Month:",
  [STR_DATE]                  = "  Date:",
  [STR_HOUR]                  = "  Hour:",
  [STR_MINUTE]                = "Minute:",
};

const LPCSTR StringTable_CHS[STR_LAST] = 
{
  /*
  [STR_DEFAULT]               = "按中键退出",
  [STR_ROOT]                  = "退出",
  [STR_STATUS]                = "设备状态",
  [STR_TEST]                  = "测试",
  [STR_SETTING]               = "设置",
  [STR_ABOUT]                 = "关于",
  [STR_SETTING_CONTRAST]      = "对比度",
  [STR_SETTING_TIME]          = "时间",
  [STR_STATUS_BAT]            = "电池",
  [STR_STATUS_GRAVITY]        = "重力加速度",
  [STR_SETTING_LANGUAGE]      = "语言",
  [STR_LANG_ENG]              = "英语",
  [STR_LANG_CHS]              = "简体中文",
  [STR_CHANGE_CONTRAST]       = "更改对比度:",
  [STR_SET_TIME]              = "设置时间:",
  [STR_VIEW_BATTARY]          = "电池状态:",
  [STR_BAT_CHARGE]            = "充电中 ...",
  [STR_BAT_FULL]              = "充电完成",
  [STR_BAT_NORMAL]            = "断开连接",
  [STR_BAT_CAPACITY]          = "当前容量:",
  [STR_BAT_VOLTAGE]           = "当前电压: ",
  [STR_ABOUT_0]               = "Oled 项目 1.0",
  [STR_ABOUT_1]               = "lxyppc@163.com",
  [STR_ABOUT_2]               = "版权所有",
  [STR_OK]                    = "确定",
  [STR_CANCEL]                = "取消",
  [STR_JAN]                   = " 1月",
  [STR_FEB]                   = " 2月",
  [STR_MAR]                   = " 3月",
  [STR_APR]                   = " 4月",
  [STR_MAY]                   = " 5月",
  [STR_JUN]                   = " 6月",
  [STR_JUL]                   = " 7月",
  [STR_AUG]                   = " 8月",
  [STR_SEP]                   = " 9月",
  [STR_OCT]                   = "10月",
  [STR_NOV]                   = "11月",
  [STR_DEC]                   = "12月",
  [STR_SUNDAY]                = "周日",
  [STR_MONDAY]                = "周一",
  [STR_TUESDAY]               = "周二",
  [STR_WEDNESDAY]             = "周三",
  [STR_THURSDAY]              = "周四",
  [STR_FRIDAY]                = "周五",
  [STR_SATURDAY]              = "周六",
  [STR_AM]                    = "上午",
  [STR_PM]                    = "下午",
  [STR_YEAR]                  = "  年度:",
  [STR_MONTH]                 = "  月份:",
  [STR_DATE]                  = "  日期:",
  [STR_HOUR]                  = "  小时:",
  [STR_MINUTE]                = "  分钟:",
  */
  [STR_DEFAULT]               = /*"按中键退出"*/"\xA4\x84\xC6\xC1\x8D",
  [STR_ROOT]                  = /*"退出"*/"\xC1\x8D",
  [STR_STATUS]                = /*"设备状态"*/"\xBD\x97\xB5\xA1",
  [STR_TEST]                  = /*"测试"*/"\xB2\xBE",
  [STR_SETTING]               = /*"设置"*/"\xBD\xBA",
  [STR_ABOUT]                 = /*"关于"*/"\x8C\x86",
  [STR_SETTING_CONTRAST]      = /*"对比度"*/"\x9B\xB0\x9E",
  [STR_SETTING_TIME]          = /*"时间"*/"\xAA\xC7",
  [STR_STATUS_BAT]            = /*"电池"*/"\xB6\xB1",
  [STR_STATUS_GRAVITY]        = /*"重力加速度"*/"\xC3\x90\x91\xC2\x9E",
  [STR_SETTING_LANGUAGE]      = /*"语言"*/"\xBF\xBC",
  [STR_LANG_ENG]              = /*"英语"*/"\xBB\xBF",
  [STR_LANG_CHS]              = /*"简体中文"*/"\xB9\x89\x84\xA7",
  [STR_CHANGE_CONTRAST]       = /*"更改对比度:"*/"\xAB\xA6\x9B\xB0\x9E:",
  [STR_SET_TIME]              = /*"设置时间:"*/"\xBD\xBA\xAA\xC7:",
  [STR_VIEW_BATTARY]          = /*"电池状态:"*/"\xB6\xB1\xB5\xA1:",
  [STR_BAT_CHARGE]            = /*"充电中 ..."*/"\x8A\xB6\x84 ...",
  [STR_BAT_FULL]              = /*"充电完成"*/"\x8A\xB6\x98\xA2",
  [STR_BAT_NORMAL]            = /*"断开连接"*/"\xA8\x9F\xC0\xA5",
  [STR_BAT_CAPACITY]          = /*"当前容量:"*/"\xA0\x8F\x9A\xC4:",
  [STR_BAT_VOLTAGE]           = /*"当前电压: "*/"\xA0\x8F\xB6\x93: ",
  [STR_ABOUT_0]               = /*"Oled 项目 1.0"*/"Oled \xC8\xB7 1.0",
  [STR_ABOUT_1]               = /*"lxyppc@163.com"*/"lxyppc@163.com",
  [STR_ABOUT_2]               = /*"版权所有"*/"\xB4\xAF\xA3\xAD",
  [STR_OK]                    = /*"确定"*/"\xB8\x99",
  [STR_CANCEL]                = /*"取消"*/"\x94\xB3",
  [STR_JAN]                   = /*" 1月"*/" 1\xAC",
  [STR_FEB]                   = /*" 2月"*/" 2\xAC",
  [STR_MAR]                   = /*" 3月"*/" 3\xAC",
  [STR_APR]                   = /*" 4月"*/" 4\xAC",
  [STR_MAY]                   = /*" 5月"*/" 5\xAC",
  [STR_JUN]                   = /*" 6月"*/" 6\xAC",
  [STR_JUL]                   = /*" 7月"*/" 7\xAC",
  [STR_AUG]                   = /*" 8月"*/" 8\xAC",
  [STR_SEP]                   = /*" 9月"*/" 9\xAC",
  [STR_OCT]                   = /*"10月"*/"10\xAC",
  [STR_NOV]                   = /*"11月"*/"11\xAC",
  [STR_DEC]                   = /*"12月"*/"12\xAC",
  [STR_SUNDAY]                = /*"周日"*/"\x95\xA9",
  [STR_MONDAY]                = /*"周一"*/"\x95\x80",
  [STR_TUESDAY]               = /*"周二"*/"\x95\x85",
  [STR_WEDNESDAY]             = /*"周三"*/"\x95\x81",
  [STR_THURSDAY]              = /*"周四"*/"\x95\x96",
  [STR_FRIDAY]                = /*"周五"*/"\x95\x87",
  [STR_SATURDAY]              = /*"周六"*/"\x95\x8B",
  [STR_AM]                    = /*"上午"*/"\x82\x92",
  [STR_PM]                    = /*"下午"*/"\x83\x92",
  [STR_YEAR]                  = /*"  年度:"*/"  \x9D\x9E:",
  [STR_MONTH]                 = /*"  月份:"*/"  \xAC\x88:",
  [STR_DATE]                  = /*"  日期:"*/"  \xA9\xAE:",
  [STR_HOUR]                  = /*"  小时:"*/"  \x9C\xAA:",
  [STR_MINUTE]                = /*"  分钟:"*/"  \x8E\xC5:",

/* Replaced strings:
    一三上下中二于五份体充六关出分前力加午压取周四备完定容对小年度开当态成所按接改文断日时更月有期权比池测消版状电目确简置英言设试语连退速重量钟键间项
    808182838485868788898A8B8C8D8E8F909192939495969798999A9B9C9D9E9FA0A1A2A3A4A5A6A7A8A9AAABACADAEAFB0B1B2B3B4B5B6B7B8B9BABBBCBDBEBFC0C1C2C3C4C5C6C7C8
*/

};
