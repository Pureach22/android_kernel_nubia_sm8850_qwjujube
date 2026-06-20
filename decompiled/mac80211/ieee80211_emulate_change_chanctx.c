__int64 __fastcall ieee80211_emulate_change_chanctx(__int64 result, __int64 a2)
{
  int v2; // w9
  __int64 v3; // x19

  v2 = *(_DWORD *)(result + 1316);
  *(_BYTE *)(result + 56) = *(_BYTE *)(a2 + 102);
  if ( v2 )
  {
    v3 = result;
    result = ieee80211_calc_hw_conf_chan((unsigned int *)result, (__int64 *)a2);
    if ( (_DWORD)result )
      return drv_config(v3);
  }
  return result;
}
