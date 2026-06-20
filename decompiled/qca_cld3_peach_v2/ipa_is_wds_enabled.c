__int64 ipa_is_wds_enabled()
{
  if ( g_ipa_config )
    return *(unsigned __int8 *)(g_ipa_config + 37);
  else
    return 0;
}
