Setup of the development machine

# Software versions

* OS: Ubuntu 12.04 (LTS)
* PostgreSQL: 9.1
* PostGIS: postgresql-9.1-postgis-2.0 (haven't build PostGIS from its source)
* GeoServer: Comes with cartaro installation 
* Java: java version "1.6.0_31"
* PHP version, extensions and configuration (full output of "php -i"): 5.3.10-1ubuntu3.11
* Webserver: tomcat7
* Type of PHP deployment: mod_php


phpinfo()
PHP Version => 5.3.10-1ubuntu3.11

System => Linux room_pc 3.5.0-49-generic #74~precise1-Ubuntu SMP Fri May 2 21:32:31 UTC 2014 x86_64
Build Date => Apr  4 2014 01:28:34
Server API => Command Line Interface
Virtual Directory Support => disabled
Configuration File (php.ini) Path => /etc/php5/cli
Loaded Configuration File => /etc/php5/cli/php.ini
Scan this dir for additional .ini files => /etc/php5/cli/conf.d
Additional .ini files parsed => /etc/php5/cli/conf.d/curl.ini,
/etc/php5/cli/conf.d/gd.ini,
/etc/php5/cli/conf.d/pdo.ini,
/etc/php5/cli/conf.d/pdo_pgsql.ini,
/etc/php5/cli/conf.d/pgsql.ini

PHP API => 20090626
PHP Extension => 20090626
Zend Extension => 220090626
Zend Extension Build => API220090626,NTS
PHP Extension Build => API20090626,NTS
Debug Build => no
Thread Safety => disabled
Zend Memory Manager => enabled
Zend Multibyte Support => disabled
IPv6 Support => enabled
Registered PHP Streams => https, ftps, compress.zlib, compress.bzip2, php, file, glob, data, http, ftp, phar, zip  
Registered Stream Socket Transports => tcp, udp, unix, udg, ssl, sslv3, tls
Registered Stream Filters => zlib.*, bzip2.*, convert.iconv.*, string.rot13, string.toupper, string.tolower, string.strip_tags, convert.*, consumed, dechunk


This server is protected with the Suhosin Patch 0.9.10
Copyright (c) 2006-2007 Hardened-PHP Project
Copyright (c) 2007-2009 SektionEins GmbH


This program makes use of the Zend Scripting Language Engine:
Zend Engine v2.3.0, Copyright (c) 1998-2012 Zend Technologies


 _______________________________________________________________________


Configuration

bcmath

BCMath support => enabled

Directive => Local Value => Master Value
bcmath.scale => 0 => 0

bz2

BZip2 Support => Enabled
Stream Wrapper support => compress.bzip2://
Stream Filter support => bzip2.decompress, bzip2.compress
BZip2 Version => 1.0.6, 6-Sept-2010

calendar

Calendar support => enabled

Core

PHP Version => 5.3.10-1ubuntu3.11

Directive => Local Value => Master Value
allow_call_time_pass_reference => Off => Off
allow_url_fopen => On => On
allow_url_include => Off => Off
always_populate_raw_post_data => Off => Off
arg_separator.input => & => &
arg_separator.output => & => &
asp_tags => Off => Off
auto_append_file => no value => no value
auto_globals_jit => On => On
auto_prepend_file => no value => no value
browscap => no value => no value
default_charset => no value => no value
default_mimetype => text/html => text/html
define_syslog_variables => Off => Off
disable_classes => no value => no value
disable_functions => no value => no value
display_errors => Off => Off
display_startup_errors => Off => Off
doc_root => no value => no value
docref_ext => no value => no value
docref_root => no value => no value
enable_dl => Off => Off
error_append_string => no value => no value
error_log => no value => no value
error_prepend_string => no value => no value
error_reporting => 22527 => 22527
exit_on_timeout => Off => Off
expose_php => On => On
extension_dir => /usr/lib/php5/20090626 => /usr/lib/php5/20090626
file_uploads => On => On
highlight.bg => <font style="color: #FFFFFF">#FFFFFF</font> => <font style="color: #FFFFFF">#FFFFFF</font>
highlight.comment => <font style="color: #FF8000">#FF8000</font> => <font style="color: #FF8000">#FF8000</font>
highlight.default => <font style="color: #0000BB">#0000BB</font> => <font style="color: #0000BB">#0000BB</font>
highlight.html => <font style="color: #000000">#000000</font> => <font style="color: #000000">#000000</font>
highlight.keyword => <font style="color: #007700">#007700</font> => <font style="color: #007700">#007700</font>
highlight.string => <font style="color: #DD0000">#DD0000</font> => <font style="color: #DD0000">#DD0000</font>
html_errors => Off => Off
ignore_repeated_errors => Off => Off
ignore_repeated_source => Off => Off
ignore_user_abort => Off => Off
implicit_flush => On => On
include_path => .:/usr/share/php:/usr/share/pear => .:/usr/share/php:/usr/share/pear
log_errors => On => On
log_errors_max_len => 1024 => 1024
magic_quotes_gpc => Off => Off
magic_quotes_runtime => Off => Off
magic_quotes_sybase => Off => Off
mail.add_x_header => On => On
mail.force_extra_parameters => no value => no value
mail.log => no value => no value
max_execution_time => 0 => 0
max_file_uploads => 20 => 20
max_input_nesting_level => 64 => 64
max_input_time => -1 => -1
max_input_vars => 1000 => 1000
memory_limit => -1 => -1
open_basedir => no value => no value
output_buffering => 0 => 0
output_handler => no value => no value
post_max_size => 8M => 8M
precision => 14 => 14
realpath_cache_size => 16K => 16K
realpath_cache_ttl => 120 => 120
register_argc_argv => On => On
register_globals => Off => Off
register_long_arrays => Off => Off
report_memleaks => On => On
report_zend_debug => Off => Off
request_order => GP => GP
safe_mode => Off => Off
safe_mode_exec_dir => no value => no value
safe_mode_gid => Off => Off
safe_mode_include_dir => no value => no value
sendmail_from => no value => no value
sendmail_path => /usr/sbin/sendmail -t -i  => /usr/sbin/sendmail -t -i 
serialize_precision => 17 => 17
short_open_tag => On => On
SMTP => localhost => localhost
smtp_port => 25 => 25
sql.safe_mode => Off => Off
track_errors => Off => Off
unserialize_callback_func => no value => no value
upload_max_filesize => 2M => 2M
upload_tmp_dir => no value => no value
user_dir => no value => no value
user_ini.cache_ttl => 300 => 300
user_ini.filename => .user.ini => .user.ini
variables_order => GPCS => GPCS
xmlrpc_error_number => 0 => 0
xmlrpc_errors => Off => Off
y2k_compliance => On => On
zend.enable_gc => On => On

ctype

ctype functions => enabled

curl

cURL support => enabled
cURL Information => 7.22.0
Age => 3
Features
AsynchDNS => No
Debug => No
GSS-Negotiate => Yes
IDN => Yes
IPv6 => Yes
Largefile => Yes
NTLM => Yes
SPNEGO => No
SSL => Yes
SSPI => No
krb4 => No
libz => Yes
CharConv => No
Protocols => dict, file, ftp, ftps, gopher, http, https, imap, imaps, ldap, pop3, pop3s, rtmp, rtsp, smtp, smtps, telnet, tftp
Host => x86_64-pc-linux-gnu
SSL Version => OpenSSL/1.0.1
ZLib Version => 1.2.3.4

date

date/time support => enabled
"Olson" Timezone Database Version => 0.system
Timezone Database => internal
Default timezone => Asia/Calcutta

Directive => Local Value => Master Value
date.default_latitude => 31.7667 => 31.7667
date.default_longitude => 35.2333 => 35.2333
date.sunrise_zenith => 90.583333 => 90.583333
date.sunset_zenith => 90.583333 => 90.583333
date.timezone => no value => no value

dba

DBA support => enabled
Supported handlers => cdb cdb_make db4 inifile flatfile 

Directive => Local Value => Master Value
dba.default_handler => flatfile => flatfile

dom

DOM/XML => enabled
DOM/XML API Version => 20031129
libxml Version => 2.7.8
HTML Support => enabled
XPath Support => enabled
XPointer Support => enabled
Schema Support => enabled
RelaxNG Support => enabled

ereg

Regex Library => Bundled library enabled

exif

EXIF Support => enabled
EXIF Version => 1.4 $Id: exif.c 321634 2012-01-01 13:15:04Z felipe $
Supported EXIF Version => 0220
Supported filetypes => JPEG,TIFF

Directive => Local Value => Master Value
exif.decode_jis_intel => JIS => JIS
exif.decode_jis_motorola => JIS => JIS
exif.decode_unicode_intel => UCS-2LE => UCS-2LE
exif.decode_unicode_motorola => UCS-2BE => UCS-2BE
exif.encode_jis => no value => no value
exif.encode_unicode => ISO-8859-15 => ISO-8859-15

fileinfo

fileinfo support => enabled
version => 1.0.5-dev

filter

Input Validation and Filtering => enabled
Revision => $Revision: 321634 $

Directive => Local Value => Master Value
filter.default => unsafe_raw => unsafe_raw
filter.default_flags => no value => no value

ftp

FTP support => enabled

gd

GD Support => enabled
GD Version => 2.0
FreeType Support => enabled
FreeType Linkage => with freetype
FreeType Version => 2.4.8
T1Lib Support => enabled
GIF Read Support => enabled
GIF Create Support => enabled
JPEG Support => enabled
libJPEG Version => unknown
PNG Support => enabled
libPNG Version => 1.2.46
WBMP Support => enabled

Directive => Local Value => Master Value
gd.jpeg_ignore_warning => 0 => 0

gettext

GetText Support => enabled

hash

hash support => enabled
Hashing Engines => md2 md4 md5 sha1 sha224 sha256 sha384 sha512 ripemd128 ripemd160 ripemd256 ripemd320 whirlpool tiger128,3 tiger160,3 tiger192,3 tiger128,4 tiger160,4 tiger192,4 snefru snefru256 gost adler32 crc32 crc32b salsa10 salsa20 haval128,3 haval160,3 haval192,3 haval224,3 haval256,3 haval128,4 haval160,4 haval192,4 haval224,4 haval256,4 haval128,5 haval160,5 haval192,5 haval224,5 haval256,5 

iconv

iconv support => enabled
iconv implementation => glibc
iconv library version => 2.15

Directive => Local Value => Master Value
iconv.input_encoding => ISO-8859-1 => ISO-8859-1
iconv.internal_encoding => ISO-8859-1 => ISO-8859-1
iconv.output_encoding => ISO-8859-1 => ISO-8859-1

json

json support => enabled
json version => 1.2.1

libxml

libXML support => active
libXML Compiled Version => 2.7.8
libXML Loaded Version => 20708
libXML streams => enabled

mbstring

Multibyte Support => enabled
Multibyte string engine => libmbfl
HTTP input encoding translation => disabled

mbstring extension makes use of "streamable kanji code filter and converter", which is distributed under the GNU Lesser General Public License version 2.1.

Multibyte (japanese) regex support => enabled
Multibyte regex (oniguruma) backtrack check => On
Multibyte regex (oniguruma) version => 4.7.1

Directive => Local Value => Master Value
mbstring.detect_order => no value => no value
mbstring.encoding_translation => Off => Off
mbstring.func_overload => 0 => 0
mbstring.http_input => pass => pass
mbstring.http_output => pass => pass
mbstring.http_output_conv_mimetypes => ^(text/|application/xhtml\+xml) => ^(text/|application/xhtml\+xml)
mbstring.internal_encoding => no value => no value
mbstring.language => neutral => neutral
mbstring.strict_detection => Off => Off
mbstring.substitute_character => no value => no value

mhash

MHASH support => Enabled
MHASH API Version => Emulated Support

openssl

OpenSSL support => enabled
OpenSSL Library Version => OpenSSL 1.0.1 14 Mar 2012
OpenSSL Header Version => OpenSSL 1.0.1 14 Mar 2012

pcntl

pcntl support => enabled

pcre

PCRE (Perl Compatible Regular Expressions) Support => enabled
PCRE Library Version => 8.12 2011-01-15

Directive => Local Value => Master Value
pcre.backtrack_limit => 1000000 => 1000000
pcre.recursion_limit => 100000 => 100000

PDO

PDO support => enabled
PDO drivers => pgsql

pdo_pgsql

PDO Driver for PostgreSQL => enabled
PostgreSQL(libpq) Version => 9.1.12
Module version => 1.0.2
Revision =>  $Id: pdo_pgsql.c 321634 2012-01-01 13:15:04Z felipe $ 

pgsql

PostgreSQL Support => enabled
PostgreSQL(libpq) Version => 9.1.12
Multibyte character support => enabled
SSL support => enabled
Active Persistent Links => 0
Active Links => 0

Directive => Local Value => Master Value
pgsql.allow_persistent => On => On
pgsql.auto_reset_persistent => Off => Off
pgsql.ignore_notice => Off => Off
pgsql.log_notice => Off => Off
pgsql.max_links => Unlimited => Unlimited
pgsql.max_persistent => Unlimited => Unlimited

Phar

Phar: PHP Archive support => enabled
Phar EXT version => 2.0.1
Phar API version => 1.1.1
SVN revision => $Revision: 321634 $
Phar-based phar archives => enabled
Tar-based phar archives => enabled
ZIP-based phar archives => enabled
gzip compression => enabled
bzip2 compression => enabled
Native OpenSSL support => enabled


Phar based on pear/PHP_Archive, original concept by Davey Shafik.
Phar fully realized by Gregory Beaver and Marcus Boerger.
Portions of tar implementation Copyright (c) 2003-2009 Tim Kientzle.
Directive => Local Value => Master Value
phar.cache_list => no value => no value
phar.readonly => On => On
phar.require_hash => On => On

posix

Revision => $Revision: 321634 $

Reflection

Reflection => enabled
Version => $Revision: 321634 $

session

Session Support => enabled
Registered save handlers => files user 
Registered serializer handlers => php php_binary wddx 

Directive => Local Value => Master Value
session.auto_start => Off => Off
session.bug_compat_42 => Off => Off
session.bug_compat_warn => Off => Off
session.cache_expire => 180 => 180
session.cache_limiter => nocache => nocache
session.cookie_domain => no value => no value
session.cookie_httponly => Off => Off
session.cookie_lifetime => 0 => 0
session.cookie_path => / => /
session.cookie_secure => Off => Off
session.entropy_file => no value => no value
session.entropy_length => 0 => 0
session.gc_divisor => 1000 => 1000
session.gc_maxlifetime => 1440 => 1440
session.gc_probability => 0 => 0
session.hash_bits_per_character => 5 => 5
session.hash_function => 0 => 0
session.name => PHPSESSID => PHPSESSID
session.referer_check => no value => no value
session.save_handler => files => files
session.save_path => /var/lib/php5 => /var/lib/php5
session.serialize_handler => php => php
session.use_cookies => On => On
session.use_only_cookies => On => On
session.use_trans_sid => 0 => 0

shmop

shmop support => enabled

SimpleXML

Simplexml support => enabled
Revision => $Revision: 321634 $
Schema support => enabled

soap

Soap Client => enabled
Soap Server => enabled

Directive => Local Value => Master Value
soap.wsdl_cache => 1 => 1
soap.wsdl_cache_dir => /tmp => /tmp
soap.wsdl_cache_enabled => 1 => 1
soap.wsdl_cache_limit => 5 => 5
soap.wsdl_cache_ttl => 86400 => 86400

sockets

Sockets Support => enabled

SPL

SPL support => enabled
Interfaces => Countable, OuterIterator, RecursiveIterator, SeekableIterator, SplObserver, SplSubject
Classes => AppendIterator, ArrayIterator, ArrayObject, BadFunctionCallException, BadMethodCallException, CachingIterator, DirectoryIterator, DomainException, EmptyIterator, FilesystemIterator, FilterIterator, GlobIterator, InfiniteIterator, InvalidArgumentException, IteratorIterator, LengthException, LimitIterator, LogicException, MultipleIterator, NoRewindIterator, OutOfBoundsException, OutOfRangeException, OverflowException, ParentIterator, RangeException, RecursiveArrayIterator, RecursiveCachingIterator, RecursiveDirectoryIterator, RecursiveFilterIterator, RecursiveIteratorIterator, RecursiveRegexIterator, RecursiveTreeIterator, RegexIterator, RuntimeException, SplDoublyLinkedList, SplFileInfo, SplFileObject, SplFixedArray, SplHeap, SplMinHeap, SplMaxHeap, SplObjectStorage, SplPriorityQueue, SplQueue, SplStack, SplTempFileObject, UnderflowException, UnexpectedValueException

standard

Dynamic Library Support => enabled
Path to sendmail => /usr/sbin/sendmail -t -i 

Directive => Local Value => Master Value
assert.active => 1 => 1
assert.bail => 0 => 0
assert.callback => no value => no value
assert.quiet_eval => 0 => 0
assert.warning => 1 => 1
auto_detect_line_endings => 0 => 0
default_socket_timeout => 60 => 60
from => no value => no value
safe_mode_allowed_env_vars => PHP_ => PHP_
safe_mode_protected_env_vars => LD_LIBRARY_PATH => LD_LIBRARY_PATH
url_rewriter.tags => a=href,area=href,frame=src,input=src,form=fakeentry => a=href,area=href,frame=src,input=src,form=fakeentry
user_agent => no value => no value

sysvmsg

sysvmsg support => enabled
Revision => $Revision: 321634 $

tokenizer

Tokenizer Support => enabled

wddx

WDDX Support => enabled
WDDX Session Serializer => enabled

xml

XML Support => active
XML Namespace Support => active
libxml2 Version => 2.7.8

xmlreader

XMLReader => enabled

xmlwriter

XMLWriter => enabled

zip

Zip => enabled
Extension Version => $Id: php_zip.c 321634 2012-01-01 13:15:04Z felipe $
Zip version => 1.9.1
Libzip version => 0.9.0

zlib

ZLib Support => enabled
Stream Wrapper support => compress.zlib://
Stream Filter support => zlib.inflate, zlib.deflate
Compiled Version => 1.2.1.1
Linked Version => 1.2.3.4

Directive => Local Value => Master Value
zlib.output_compression => Off => Off
zlib.output_compression_level => -1 => -1
zlib.output_handler => no value => no value

Additional Modules

Module Name
readline
sysvsem
sysvshm

Environment

Variable => Value
SSH_AGENT_PID => 1832
GPG_AGENT_INFO => /tmp/keyring-pFqoVh/gpg:0:1
TERM => xterm
SHELL => /bin/bash
XDG_SESSION_COOKIE => 606eb24510babe36c24e3a790000000c-1400598919.130006-75530078
WINDOWID => 56623110
GNOME_KEYRING_CONTROL => /tmp/keyring-pFqoVh
NO_PROXY => localhost,127.0.0.0/8, iiit.ac.in,.iiit.ac.in,10.0.0.0/8,10.10.1.15
USER => naveen
http_proxy => http://proxy.iiit.ac.in:8080/
LS_COLORS => rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:
LIBGL_DRIVERS_PATH => /usr/lib/fglrx/dri:/usr/lib/x86_64-linux-gnu/dri:/usr/lib/dri:/usr/lib32/fglrx/dri:/usr/lib/i386-linux-gnu/dri
XDG_SESSION_PATH => /org/freedesktop/DisplayManager/Session0
XDG_SEAT_PATH => /org/freedesktop/DisplayManager/Seat0
SSH_AUTH_SOCK => /tmp/keyring-pFqoVh/ssh
ftp_proxy => ftp://proxy.iiit.ac.in:8080/
SESSION_MANAGER => local/room_pc:@/tmp/.ICE-unix/1795,unix/room_pc:/tmp/.ICE-unix/1795
DEFAULTS_PATH => /usr/share/gconf/ubuntu.default.path
XDG_CONFIG_DIRS => /etc/xdg/xdg-ubuntu:/etc/xdg
ALL_PROXY => socks://proxy.iiit.ac.in:8080/
all_proxy => socks://proxy.iiit.ac.in:8080/
PATH => /usr/lib/lightdm/lightdm:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games
DESKTOP_SESSION => ubuntu
PWD => /home/naveen
socks_proxy => socks://proxy.iiit.ac.in:8080/
GNOME_KEYRING_PID => 1784
LANG => en_IN
MANDATORY_PATH => /usr/share/gconf/ubuntu.mandatory.path
UBUNTU_MENUPROXY => libappmenu.so
COMPIZ_CONFIG_PROFILE => ubuntu
https_proxy => https://proxy.iiit.ac.in:8080/
GDMSESSION => ubuntu
SHLVL => 1
HOME => /home/naveen
LANGUAGE => en_IN:en
GNOME_DESKTOP_SESSION_ID => this-is-deprecated
no_proxy => localhost,127.0.0.0/8, iiit.ac.in,.iiit.ac.in,10.0.0.0/8,10.10.1.15
LOGNAME => naveen
XDG_DATA_DIRS => /usr/share/ubuntu:/usr/share/gnome:/usr/local/share/:/usr/share/
DBUS_SESSION_BUS_ADDRESS => unix:abstract=/tmp/dbus-euYWrFUwvQ,guid=5e67767869a1384b612f35ba00000040
LESSOPEN => | /usr/bin/lesspipe %s
DISPLAY => :0
XDG_CURRENT_DESKTOP => Unity
LESSCLOSE => /usr/bin/lesspipe %s %s
COLORTERM => gnome-terminal
XAUTHORITY => /home/naveen/.Xauthority
_ => /usr/bin/php

PHP Variables

Variable => Value
_SERVER["SSH_AGENT_PID"] => 1832
_SERVER["GPG_AGENT_INFO"] => /tmp/keyring-pFqoVh/gpg:0:1
_SERVER["TERM"] => xterm
_SERVER["SHELL"] => /bin/bash
_SERVER["XDG_SESSION_COOKIE"] => 606eb24510babe36c24e3a790000000c-1400598919.130006-75530078
_SERVER["WINDOWID"] => 56623110
_SERVER["GNOME_KEYRING_CONTROL"] => /tmp/keyring-pFqoVh
_SERVER["NO_PROXY"] => localhost,127.0.0.0/8, iiit.ac.in,.iiit.ac.in,10.0.0.0/8,10.10.1.15
_SERVER["USER"] => naveen
_SERVER["http_proxy"] => http://proxy.iiit.ac.in:8080/
_SERVER["LS_COLORS"] => rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:
_SERVER["LIBGL_DRIVERS_PATH"] => /usr/lib/fglrx/dri:/usr/lib/x86_64-linux-gnu/dri:/usr/lib/dri:/usr/lib32/fglrx/dri:/usr/lib/i386-linux-gnu/dri
_SERVER["XDG_SESSION_PATH"] => /org/freedesktop/DisplayManager/Session0
_SERVER["XDG_SEAT_PATH"] => /org/freedesktop/DisplayManager/Seat0
_SERVER["SSH_AUTH_SOCK"] => /tmp/keyring-pFqoVh/ssh
_SERVER["ftp_proxy"] => ftp://proxy.iiit.ac.in:8080/
_SERVER["SESSION_MANAGER"] => local/room_pc:@/tmp/.ICE-unix/1795,unix/room_pc:/tmp/.ICE-unix/1795
_SERVER["DEFAULTS_PATH"] => /usr/share/gconf/ubuntu.default.path
_SERVER["XDG_CONFIG_DIRS"] => /etc/xdg/xdg-ubuntu:/etc/xdg
_SERVER["ALL_PROXY"] => socks://proxy.iiit.ac.in:8080/
_SERVER["all_proxy"] => socks://proxy.iiit.ac.in:8080/
_SERVER["PATH"] => /usr/lib/lightdm/lightdm:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games
_SERVER["DESKTOP_SESSION"] => ubuntu
_SERVER["PWD"] => /home/naveen
_SERVER["socks_proxy"] => socks://proxy.iiit.ac.in:8080/
_SERVER["GNOME_KEYRING_PID"] => 1784
_SERVER["LANG"] => en_IN
_SERVER["MANDATORY_PATH"] => /usr/share/gconf/ubuntu.mandatory.path
_SERVER["UBUNTU_MENUPROXY"] => libappmenu.so
_SERVER["COMPIZ_CONFIG_PROFILE"] => ubuntu
_SERVER["https_proxy"] => https://proxy.iiit.ac.in:8080/
_SERVER["GDMSESSION"] => ubuntu
_SERVER["SHLVL"] => 1
_SERVER["HOME"] => /home/naveen
_SERVER["LANGUAGE"] => en_IN:en
_SERVER["GNOME_DESKTOP_SESSION_ID"] => this-is-deprecated
_SERVER["no_proxy"] => localhost,127.0.0.0/8, iiit.ac.in,.iiit.ac.in,10.0.0.0/8,10.10.1.15
_SERVER["LOGNAME"] => naveen
_SERVER["XDG_DATA_DIRS"] => /usr/share/ubuntu:/usr/share/gnome:/usr/local/share/:/usr/share/
_SERVER["DBUS_SESSION_BUS_ADDRESS"] => unix:abstract=/tmp/dbus-euYWrFUwvQ,guid=5e67767869a1384b612f35ba00000040
_SERVER["LESSOPEN"] => | /usr/bin/lesspipe %s
_SERVER["DISPLAY"] => :0
_SERVER["XDG_CURRENT_DESKTOP"] => Unity
_SERVER["LESSCLOSE"] => /usr/bin/lesspipe %s %s
_SERVER["COLORTERM"] => gnome-terminal
_SERVER["XAUTHORITY"] => /home/naveen/.Xauthority
_SERVER["_"] => /usr/bin/php
_SERVER["PHP_SELF"] => 
_SERVER["SCRIPT_NAME"] => 
_SERVER["SCRIPT_FILENAME"] => 
_SERVER["PATH_TRANSLATED"] => 
_SERVER["DOCUMENT_ROOT"] => 
_SERVER["REQUEST_TIME"] => 1400600117
_SERVER["argv"] => Array
(
)

_SERVER["argc"] => 0

PHP License
This program is free software; you can redistribute it and/or modify
it under the terms of the PHP License as published by the PHP Group
and included in the distribution in the file:  LICENSE

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

If you did not receive a copy of the PHP license, or have any
questions about PHP licensing, please contact license@php.net.