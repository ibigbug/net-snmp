/* module to include the various ucd-snmp specific extension modules. */
config_require(ucd-snmp/proc)
config_require(ucd-snmp/versioninfo)
config_require(ucd-snmp/pass)
config_require(ucd-snmp/disk)
config_require(ucd-snmp/loadave)
config_require(ucd-snmp/extensible)
config_require(ucd-snmp/errormib)
config_require(ucd-snmp/registry)
config_arch_require(linux, ucd-snmp/memory)
config_arch_require(hpux9, ucd-snmp/memory)
config_arch_require(hpux10, ucd-snmp/memory)
config_arch_require(hpux9, ucd-snmp/hpux)
config_arch_require(hpux10, ucd-snmp/hpux)
config_arch_require(bsdi2, ucd-snmp/memory)
config_arch_require(bsdi3, ucd-snmp/memory)
config_arch_require(linux, ucd-snmp/vmstat)
config_add_mib(UCD-SNMP-MIB) 
