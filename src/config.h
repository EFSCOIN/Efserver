#ifndef CONFIG_H
#define CONFIG_H

#ifndef EFSERVER_DATADIR
#define EFSERVER_DATADIR  "/var/lib/efserver"
#endif

#define PACKAGE            "efserver"

#define EFSERVER_HOSTSFILE  EFSERVER_DATADIR "/hosts.json"
#define EFSERVER_DISTROFILE EFSERVER_DATADIR "/installed_distros.json"
#define EFSERVER_SETTINGSFILE EFSERVER_DATADIR "/settings.json"
#define EFSERVER_TFTPROOT   EFSERVER_DATADIR "/tftproot"
#define EFSERVER_DISTROROOT EFSERVER_DATADIR "/os"
#define EFSERVER_SHAREDROOT EFSERVER_DISTROROOT "/shared"
#define EFSERVER_HOMEROOT   "/home"
#define EFSERVER_DNSMASQCONFFILE "/etc/dnsmasq.d/Efserver"
#define EFSERVER_REPO_URL  "https://github.com/efscoin/efserver.json"
#define EFSERVER_REPO_CACHEFILE EFSERVER_DATADIR "/avail_distros_cache.json"
#define EFSERVER_POSTINSTALLSCRIPT EFSERVER_DATADIR "/scripts/postinstall.sh"

#define OUI_FILTER         "^(b8:27:eb|dc:a6:32):"
#define DHCPANALYZER_FILTER_STRING "PXEClient"

#define EFSERVER_LDAP_URL  "ldapi:///"
#define EFSERVER_DOMAIN    "efscoin.local"
#define EFSERVER_LDAP_DN   "dc=efscoin,dc=local"

#define EFSERVER_LDAP_USER "cn=admin,dc=efscoin,dc=local"

#define EFSERVER_LDAP_TIMEOUT  10
#define EFSERVER_MIN_UID   10000
#define EFSERVER_GID       100
#define EFSERVER_SHELL     "/bin/bash"

#endif // CONFIG_H
