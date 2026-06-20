__int64 __fastcall ieee80211_mcs_to_chains(_BYTE *a1)
{
  if ( !a1 )
    return 1;
  if ( a1[3] )
    return 4;
  if ( a1[2] )
    return 3;
  if ( a1[1] )
    return 2;
  return 1;
}
