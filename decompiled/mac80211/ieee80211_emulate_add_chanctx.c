__int64 __fastcall ieee80211_emulate_add_chanctx(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 result; // x0

  v2 = *(_DWORD *)(a1 + 1316);
  *(_BYTE *)(a1 + 56) = *(_BYTE *)(a2 + 102);
  if ( !v2 )
    return 0;
  result = ieee80211_calc_hw_conf_chan((unsigned int *)a1, (__int64 *)a2);
  if ( (_DWORD)result )
    return drv_config(a1);
  return result;
}
