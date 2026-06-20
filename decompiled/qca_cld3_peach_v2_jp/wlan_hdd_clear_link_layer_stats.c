__int64 __fastcall wlan_hdd_clear_link_layer_stats(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x10
  __int64 v3; // x0
  __int64 result; // x0
  int v5; // [xsp+8h] [xbp-18h] BYREF
  __int64 v6; // [xsp+Ch] [xbp-14h]
  int v7; // [xsp+14h] [xbp-Ch]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 52824);
  v2 = *(_QWORD *)(a1 + 24);
  v6 = 0x1C000000000LL;
  v7 = 0;
  LOBYTE(v1) = *(_BYTE *)(v1 + 8);
  v3 = *(_QWORD *)(v2 + 16);
  v5 = 1;
  LOBYTE(v6) = v1;
  result = sme_ll_stats_clear_req(v3, &v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
