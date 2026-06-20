__int64 __fastcall cfg80211_validate_beacon_int(__int64 a1, __int64 a2, int a3)
{
  if ( (unsigned int)(a3 - 10001) >= 0xFFFFD8F9 )
    return 0;
  else
    return 4294967274LL;
}
