__int64 __fastcall ieee80211_emulate_switch_vif_chanctx(__int64 a1, __int64 a2, int a3)
{
  int v3; // w9
  __int64 result; // x0

  if ( a3 < 1 )
    return 4294967274LL;
  v3 = *(_DWORD *)(a1 + 1316);
  *(_BYTE *)(a1 + 56) = *(_BYTE *)(*(_QWORD *)(a2 + 24) + 102LL);
  if ( v3 )
  {
    result = ieee80211_calc_hw_conf_chan((unsigned int *)a1, *(__int64 **)(a2 + 24));
    if ( !(_DWORD)result )
      return result;
    drv_config(a1);
  }
  return 0;
}
