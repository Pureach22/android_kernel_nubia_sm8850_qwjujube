_DWORD *__fastcall wlan_ipa_get_iface(_DWORD *a1, unsigned __int8 a2)
{
  if ( a1[274] == a2 )
    return a1 + 266;
  if ( a1[306] == a2 )
    return a1 + 298;
  if ( a1[338] == a2 )
    return a1 + 330;
  return nullptr;
}
