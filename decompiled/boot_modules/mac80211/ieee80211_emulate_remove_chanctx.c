__int64 __fastcall ieee80211_emulate_remove_chanctx(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19

  v1 = *(_DWORD *)(result + 1316);
  *(_BYTE *)(result + 56) = 0;
  if ( v1 )
  {
    v2 = result;
    result = ieee80211_calc_hw_conf_chan((unsigned int *)result, nullptr);
    if ( (_DWORD)result )
      return drv_config(v2);
  }
  return result;
}
