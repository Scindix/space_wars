#!/bin/sh

autoreconf --install || exit 1
automake -a || exit 1
