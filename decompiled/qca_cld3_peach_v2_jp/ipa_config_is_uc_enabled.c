__int64 ipa_config_is_uc_enabled()
{
  if ( g_ipa_config )
    return (*(unsigned __int8 *)g_ipa_config >> 5) & 1;
  else
    return 0;
}
