__int64 __fastcall cfg80211_bss_expire(__int64 result)
{
  __int64 v1; // x21
  __int64 *v2; // x1
  __int64 v3; // x20
  __int64 v4; // x19
  char v5; // w22
  __int64 *v6; // x24

  v1 = jiffies;
  v3 = result + 192;
  v2 = *(__int64 **)(result + 192);
  if ( v2 != (__int64 *)(result + 192) )
  {
    v4 = result;
    v5 = 0;
    do
    {
      v6 = (__int64 *)*v2;
      if ( !*((_DWORD *)v2 + 20) && v2[8] - v1 + 7500 < 0 )
      {
        result = _cfg80211_unlink_bss(v4);
        v5 |= result;
      }
      v2 = v6;
    }
    while ( v6 != (__int64 *)v3 );
    if ( (v5 & 1) != 0 )
      ++*(_DWORD *)(v4 + 216);
  }
  return result;
}
