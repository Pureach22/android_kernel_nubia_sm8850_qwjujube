__int64 __fastcall ieee80211_smps_mode_to_smps_mode(int a1)
{
  if ( a1 == 3 )
    return 2;
  else
    return a1 == 2;
}
