__int64 __fastcall ieee80211_teardown_ttlm_work(__int64 a1, __int64 a2)
{
  int v2; // w9
  int v3; // w10
  __int64 v4; // x19
  unsigned int v5; // w8
  __int64 result; // x0

  if ( *(_BYTE *)(a2 + 2712) == 1 )
  {
    v2 = *(unsigned __int16 *)(a2 + 2676);
    v3 = *(unsigned __int16 *)(a2 + 2678);
    v4 = a2 - 3128;
    v5 = *(unsigned __int16 *)(a2 + 2672);
    *(_WORD *)(a2 + 2712) = 0;
    *(_QWORD *)(a2 + 2704) = 0;
    *(_QWORD *)(a2 + 2696) = 0;
    *(_QWORD *)(a2 + 2688) = 0;
    *(_QWORD *)(a2 + 2680) = 0;
    *(_WORD *)(a2 + 2678) = 0;
    ieee80211_vif_set_links((unsigned __int16 *)(a2 - 3128), v5, v2 & ~v3);
    return ieee80211_vif_cfg_change_notify(v4, 0x600000000LL);
  }
  return result;
}
