__int64 __fastcall ieee80211_hw_conf_chan(__int64 a1)
{
  __int64 result; // x0

  if ( !*(_DWORD *)(a1 + 1316) )
    return 0;
  result = ieee80211_calc_hw_conf_chan();
  if ( (_DWORD)result )
    return drv_config(a1);
  return result;
}
