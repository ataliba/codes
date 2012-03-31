#/usr/bin/env python
# daemon.py
"""Robusto daemonizador de programas.
    Fonte : http://www.pythonbrasil.com.br/moin.cgi/DaemonizadorDeProgramas
    Baseado em
    http://starship.python.net/crew/jjkunce/python/daemonize.py
    http://www.noah.org/python/daemonize.py
"""

import sys
import os

try:
    MAXFD = os.sysconf('SC_OPEN_MAX')
except:
    MAXFD = 256

def daemonize(stdin='/dev/null', stdout='/dev/null', stderr='/dev/null',
              newhome='/', closeall=1):
    try:
        pid = os.fork()
        if pid > 0:
            sys.exit(0)
    except OSError, e:
        sys.stderr.write("o primeiro fork falhou: (%d) %s\n" %
                         (e.errno, e.errstr))
        sys.exit(1)

    os.setsid()
    os.chdir(newhome)
    os.umask(0)

    try:
        pid = os.fork()
        if pid > 0:
            sys.exit(0)
    except OSError, e:
        sys.stderr.write("o segundo fork falhou: (%d), %s\n" %
                         (e.errno, e.errstr))
        sys.exit(1)

    fin = open(stdin, 'r')
    fout = open(stdout, 'a+')
    ferr = open(stderr, 'a+', 0)
    os.dup2(fin.fileno(), sys.stdin.fileno())
    os.dup2(fout.fileno(), sys.stdout.fileno())
    os.dup2(ferr.fileno(), sys.stderr.fileno())

    if closeall:
        for i in range(3, MAXFD):
            try:
                os.close(i)
            except:
                pass

def test():
    import time
    daemonize()
    while 1:
        time.sleep(10)

if __name__ == '__main__':
    test()
