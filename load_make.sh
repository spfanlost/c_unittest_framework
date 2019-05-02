#!/bin/bash
#########################################################################
#
# Name:     loade_make shell script 
# Purpose:  clean, make, run  
##########################################################################
#  
#下面是字体输出颜色及终端格式控制  
# 字体色范围：30-37  
# echo -e "\033[30m 黑色字 \033[0m"  
# echo -e "\033[31m 红色字 \033[0m"  
# echo -e "\033[32m 绿色字 \033[0m"  
# echo -e "\033[33m 黄色字 \033[0m"  
# echo -e "\033[34m 蓝色字 \033[0m"  
# echo -e "\033[35m 紫色字 \033[0m"  
# echo -e "\033[36m 天蓝字 \033[0m"  
# echo -e "\033[37m 白色字 \033[0m"  
# #字背景颜色范围：40-47  
# echo -e "\033[40;37m 黑底白字 \033[0m"  
# echo -e "\033[41;37m 红底白字 \033[0m"  
# echo -e "\033[42;34m 绿底蓝字 \033[0m"  
# echo -e "\033[43;34m 黄底蓝字 \033[0m"  
# echo -e "\033[44;37m 蓝底白字 \033[0m"  
# echo -e "\033[45;30m 紫底黑字 \033[0m"  
# echo -e "\033[46;30m 天蓝底黑字 \033[0m"  
# echo -e "\033[47;34m 白底蓝字 \033[0m"  
# echo -e "\033[4;31m 下划线红字 \033[0m"  

echo -e "\033[32m----- clean! -> make! -----\033[0m"    
##find . -type f | xargs -n 5 touch 是为了解决 warning: Clock skew detected. Your build may be incomplete.
find . -type f | xargs -n 5 touch 
make -f Makefile clean 
make -f Makefile all
echo -e "\n\033[32mrun test!\033[0m" 
./test.run

##########################################################################
# 
#END:  loade_make shell script 
#
#########################################################################




