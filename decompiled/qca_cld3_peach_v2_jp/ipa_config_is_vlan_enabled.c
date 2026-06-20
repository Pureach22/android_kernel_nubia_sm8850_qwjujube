__int64 ipa_config_is_vlan_enabled()
{
  if ( g_ipa_config && (*(_BYTE *)g_ipa_config & 1) != 0 )
    return *(unsigned __int8 *)(g_ipa_config + 38);
  else
    return 0;
}
