
###############################################################################
#
# Inclusive Makefile for the onlp module.
#
# Autogenerated 2016-01-07 23:42:50.082961
#
###############################################################################
onlp_BASEDIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
include $(onlp_BASEDIR)/module/make.mk
include $(onlp_BASEDIR)/module/auto/make.mk
include $(onlp_BASEDIR)/module/src/make.mk
include $(onlp_BASEDIR)/utest/_make.mk

