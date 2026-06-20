__int64 __fastcall wlan_ipa_wlan_evt(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, char a6)
{
  __int64 v6; // x5

  if ( (unsigned __int8)a2 > 1u )
    return 0;
  v6 = a6 & 1;
  if ( (unsigned int)a4 >= 9 )
    a4 = 14;
  else
    a4 = (unsigned int)a4;
  return _wlan_ipa_wlan_evt(a1, a2, a3, a4, a5, v6);
}
