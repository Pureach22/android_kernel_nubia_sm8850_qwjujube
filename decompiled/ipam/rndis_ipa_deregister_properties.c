long double rndis_ipa_deregister_properties()
{
  long double result; // q0

  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_deregister_properties", 1955);
  if ( (unsigned int)((__int64 (*)(void))ipa_deregister_intf)() )
  {
    if ( ipa_rndis_logbuf )
      return ipc_log_string(
               ipa_rndis_logbuf,
               "RNDIS_IPA %s:%d Fail on Tx prop deregister\n",
               "rndis_ipa_deregister_properties",
               1959);
  }
  else if ( ipa_rndis_logbuf )
  {
    return ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_deregister_properties", 1962);
  }
  return result;
}
