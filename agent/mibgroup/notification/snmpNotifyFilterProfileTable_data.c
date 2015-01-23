/*
 * This file was generated by mib2c and is intended for use as
 * a mib module for the ucd-snmp snmpd agent.
 */


/*
 * This should always be included first before anything else
 */
#include <net-snmp/net-snmp-config.h>

#include <sys/types.h>
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif


/*
 * minimal include directives
 */
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include "header_complex.h"
#include "snmpNotifyFilterProfileTable_data.h"


/*
 * global storage of our data, saved in and configured by header_complex()
 */
static struct header_complex_index *snmpNotifyFilterProfileTableStorage =
    NULL;


/*
 * init_snmpNotifyFilterProfileTable():
 *   Initialization routine.  This is called when the agent starts up.
 *   At a minimum, registration of your variables should take place here.
 */
void
init_snmpNotifyFilterProfileTable_data(void)
{
    DEBUGMSGTL(("snmpNotifyFilterProfileTable", "initializing...  "));
}

void
snmpNotifyFilterProfileTable_free(struct snmpNotifyFilterProfileTable_data
                                  *data)
{
    if (NULL == data)
        return;

    SNMP_FREE(data->snmpTargetParamsName);
    SNMP_FREE(data->snmpNotifyFilterProfileName);
    free(data);
}

/*
 *
 */
struct snmpNotifyFilterProfileTable_data *
snmpNotifyFilterProfileTable_create(char *paramsName, size_t paramsName_len,
                                    char *profileName, size_t profileName_len)
{
    struct snmpNotifyFilterProfileTable_data *profile = NULL;

    profile = SNMP_MALLOC_STRUCT(snmpNotifyFilterProfileTable_data);
    if (NULL == profile) {
        snmp_log(LOG_ERR,
                 "could not allocate snmpNotifyFilterProfileTable_data\n");
        return NULL;
    }

    profile->snmpTargetParamsName = malloc(paramsName_len+1);
    profile->snmpNotifyFilterProfileName = malloc(profileName_len+1);
    if (NULL == profile->snmpTargetParamsName ||
        NULL == profile->snmpNotifyFilterProfileName) {
        snmp_log(LOG_ERR,
                 "could not allocate snmpNotifyFilterProfileTable_data data\n");
        snmpNotifyFilterProfileTable_free(profile);
        return NULL;
    }

    memcpy(profile->snmpTargetParamsName, paramsName, paramsName_len);
    profile->snmpTargetParamsNameLen = paramsName_len;
    profile->snmpTargetParamsName[paramsName_len] = 0;

    memcpy(profile->snmpNotifyFilterProfileName, profileName, profileName_len);
    profile->snmpNotifyFilterProfileNameLen = profileName_len;
    profile->snmpNotifyFilterProfileName[profileName_len] = 0;

    profile->snmpNotifyFilterProfileRowStatus = RS_NOTREADY;
    profile->snmpNotifyFilterProfileStorType = ST_READONLY;

    return profile;
}

/*
 * snmpNotifyFilterProfileTable_add(): adds a structure node to our data set
 */
int
snmpNotifyFilterProfileTable_add(struct snmpNotifyFilterProfileTable_data
                                 *thedata)
{
    netsnmp_variable_list *vars = NULL;
    int retVal;

    DEBUGMSGTL(("snmpNotifyFilterProfileTable", "adding data...  "));
    /*
     * add the index variables to the varbind list, which is
     * used by header_complex to index the data
     */

    snmp_varlist_add_variable(&vars, NULL, 0, ASN_PRIV_IMPLIED_OCTET_STR,
                              (u_char *) thedata->snmpTargetParamsName,
                              thedata->snmpTargetParamsNameLen);

    if (header_complex_maybe_add_data(&snmpNotifyFilterProfileTableStorage, vars,
                                      thedata, 1) != NULL){
       DEBUGMSGTL(("snmpNotifyFilterProfileTable", "registered an entry\n"));
       retVal = SNMPERR_SUCCESS;
    }else{
       retVal = SNMPERR_GENERR;
    }


    DEBUGMSGTL(("snmpNotifyFilterProfileTable", "done.\n"));
    return retVal;
}


struct snmpNotifyFilterProfileTable_data *
snmpNotifyFilterProfileTable_find(const char *name, size_t len)
{
    netsnmp_variable_list *vars = NULL;
    struct snmpNotifyFilterProfileTable_data *data;

    /*
     * put requested info into var structure
     */
    snmp_varlist_add_variable(&vars, NULL, 0, ASN_PRIV_IMPLIED_OCTET_STR,
                              (const u_char *) name, len);

    /*
     * get the data from the header_complex storage
     */
    data = (struct snmpNotifyFilterProfileTable_data *)
        header_complex_get(snmpNotifyFilterProfileTableStorage, vars);

    /*
     * free search index
     */
    snmp_free_var(vars);

    return data;
}


char           *
get_FilterProfileName(const char *paramName, size_t paramName_len,
               size_t * profileName_len)
{
    struct snmpNotifyFilterProfileTable_data *data =
        snmpNotifyFilterProfileTable_find(paramName, paramName_len);

    /*
     * return the requested information (if this row is active)
     */
    if (data && data->snmpNotifyFilterProfileRowStatus == RS_ACTIVE) {
        *profileName_len = data->snmpNotifyFilterProfileNameLen;
        return data->snmpNotifyFilterProfileName;
    }

    *profileName_len = 0;
    return NULL;
}
