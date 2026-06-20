__int64 __fastcall ieee80211_probe_mesh_link(__int64 a1, __int64 a2, const void *a3, unsigned int a4)
{
  __int64 v4; // x22
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x22
  __int64 v11; // x9
  void *v12; // x0
  __int16 v13; // w8
  __int16 v14; // w9
  __int16 v15; // w8
  unsigned __int64 StatusReg; // x8

  v4 = *(_QWORD *)(a2 + 4304);
  v8 = _netdev_alloc_skb(0, a4 + *(_DWORD *)(v4 + 104) + 48, 2080);
  if ( !v8 )
    return 4294967284LL;
  v9 = *(int *)(v4 + 104);
  v10 = v8;
  v11 = *(_QWORD *)(v8 + 224) + v9;
  LODWORD(v9) = *(_DWORD *)(v8 + 208) + v9;
  *(_QWORD *)(v8 + 224) = v11;
  *(_DWORD *)(v8 + 208) = v9;
  v12 = (void *)skb_put(v8, a4);
  memcpy(v12, a3, a4);
  v13 = *(_DWORD *)(v10 + 224);
  v14 = *(_DWORD *)(v10 + 216);
  *(_QWORD *)(v10 + 16) = a2;
  v15 = v13 - v14;
  *(_WORD *)(v10 + 180) = 256;
  *(_WORD *)(v10 + 184) = v15;
  *(_WORD *)(v10 + 186) = v15;
  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(StatusReg + 16) += 512;
  _ieee80211_subif_start_xmit(v10, *(_QWORD *)(v10 + 16), 0, 0x20u, 0);
  local_bh_enable_3();
  return 0;
}
