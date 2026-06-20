__int64 ipa_config_is_opt_wifi_dp_enabled()
{
  if ( g_ipa_config )
    return (*(unsigned __int8 *)(g_ipa_config + 1) >> 1) & 1;
  else
    return 0;
}
