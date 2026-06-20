__int64 ipa_config_is_enabled()
{
  if ( g_ipa_config )
    return *(_BYTE *)g_ipa_config & 1;
  else
    return 0;
}
