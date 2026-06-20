__int64 *__fastcall ieee80211_dfs_cac_timer_work(__int64 a1, __int64 a2)
{
  unsigned int *v2; // x19
  _QWORD *v3; // x9
  unsigned int v4; // w8
  __int64 v5; // x10
  __int64 v6; // x11
  __int64 v7; // x9
  __int64 v8; // x12
  __int64 *result; // x0
  __int64 v10; // x20
  _QWORD v11[5]; // [xsp+8h] [xbp-28h] BYREF

  v2 = (unsigned int *)(a2 - 456);
  v11[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD **)(a2 + 480);
  v4 = *(_DWORD *)(a2 - 456);
  v5 = v3[17];
  v6 = v3[18];
  v8 = v3[19];
  v7 = v3[20];
  v11[0] = v5;
  v11[1] = v6;
  v11[2] = v8;
  v11[3] = v7;
  if ( v4 >= 0xF )
    __break(0x5512u);
  result = (__int64 *)(a2 - 464);
  v10 = *(_QWORD *)(a2 - 464);
  if ( *(_BYTE *)(v10 + 72LL * v4 + 456) == 1 )
  {
    ieee80211_link_release_channel(result);
    result = (__int64 *)cfg80211_cac_event(*(_QWORD *)(v10 + 1608), v11, 1, 3264, *v2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
