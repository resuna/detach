# DETACH(1)



## NAME
detach − when it absolutely has to run!

## SYNOPSIS
detach [‐va] [ ‐f filename ] command [ args ]

## DESCRIPTION
detach.   runs  a  command  in a whole new process group. Once you have
detached a process, you can airmail your terminal to Brazil.  It  won’t
care.

## OPTIONS
<dl>
<dt>
‐v<dd>    Natter at you about the command it’s running, both on the terminal and in the log file.

<dt>‐f filename<dd> By default, detach redirects output  to  "detach.out".  You  can override  this  with  the  ’‐f’  option. Really important if you don’t have write access in the current directory.

<dt>‐a <dd>    Append to the logfile instead of overwriting it.
</dl>

## AUTHOR
Peter da Silva

## NOTES
Detach uses execvp to execute the command. If you want to detach multi‐
ple commands use detach options sh ‐c ’command’...
