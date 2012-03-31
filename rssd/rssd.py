#!/usr/bin/env python 

__author__ = "Ataliba Teixeira (ataliba@ataliba.net)"
__version__ = "$Revision: 1.2 $"
__date__ = "$Date: 2005/11/11 21:57:19 $"
__copyright__ = "Copyright (c) 2005 Ataliba Teixeira"
__license__ = "Python"

# importando minhas bibliotecas 
import daemon
#import rssparse

# importando as bibliotecas do python 
import time
import os
import sys

for arg in sys.argv:
    print arg
    
if __name__ == '__main__':
    print "Starting the daemonize program ... "
    daemon.daemonize()
    
