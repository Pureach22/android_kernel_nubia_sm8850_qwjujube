__int64 __fastcall ieee80211_probe_client(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 v4; // x22
  __int64 bss; // x0
  int v9; // w25
  int **v10; // x8
  __int64 v11; // x20
  int v12; // w26
  unsigned int v13; // w24
  __int64 v14; // x9
  __int64 v15; // x23
  __int64 v16; // x8
  int v17; // w9
  __int16 v18; // w28
  __int64 v19; // x0
  __int16 v20; // w10
  __int16 v21; // w10
  int v22; // w9
  __int16 v23; // w8
  int v24; // w8
  int v25; // w9
  unsigned int v26; // w21
  unsigned __int64 StatusReg; // x8
  __int64 v28; // x0

  v4 = *(_QWORD *)(a2 + 4304);
  _rcu_read_lock(a1, a2);
  bss = sta_info_get_bss(a2 + 2688, a3);
  if ( bss )
  {
    v9 = *(unsigned __int8 *)(bss + 2698);
    v10 = *(int ***)(a2 + 8328);
    v11 = bss;
    if ( v10 )
    {
      v12 = **v10;
      if ( *(_BYTE *)(bss + 2698) )
        v13 = 26;
      else
        v13 = 24;
      bss = _netdev_alloc_skb(0, *(_DWORD *)(v4 + 104) + v13, 2080);
      if ( bss )
      {
        *(_QWORD *)(bss + 16) = a2;
        v14 = *(int *)(v4 + 104);
        v15 = bss;
        v16 = *(_QWORD *)(bss + 224) + v14;
        v17 = *(_DWORD *)(bss + 208) + v14;
        *(_QWORD *)(bss + 224) = v16;
        if ( v9 )
          v18 = 712;
        else
          v18 = 584;
        *(_DWORD *)(bss + 208) = v17;
        v19 = skb_put(bss, v13);
        *(_WORD *)v19 = v18;
        *(_WORD *)(v19 + 2) = 0;
        v20 = *(_WORD *)(v11 + 2692);
        *(_DWORD *)(v19 + 4) = *(_DWORD *)(v11 + 2688);
        *(_WORD *)(v19 + 8) = v20;
        v21 = *(_WORD *)(a2 + 8534);
        *(_DWORD *)(v19 + 10) = *(_DWORD *)(a2 + 8530);
        *(_WORD *)(v19 + 14) = v21;
        v22 = *(_DWORD *)(a2 + 8530);
        v23 = *(_WORD *)(a2 + 8534);
        *(_WORD *)(v19 + 22) = 0;
        *(_DWORD *)(v19 + 16) = v22;
        *(_WORD *)(v19 + 20) = v23;
        v24 = *(_DWORD *)(v15 + 40);
        v25 = *(_DWORD *)(v15 + 44);
        *(_WORD *)(v15 + 124) = 0;
        *(_DWORD *)(v15 + 40) = v24 | 0x200001;
        *(_DWORD *)(v15 + 44) = v25 & 0xFFFFFFF8 | v12 & 7;
        *(_DWORD *)(v15 + 144) = 7;
        if ( v9 )
          *(_WORD *)(v19 + 24) = 7;
        v26 = ieee80211_attach_ack_skb(v4, v15, a4, 0x820u);
        if ( v26 )
        {
          bss = sk_skb_reason_drop(0);
        }
        else
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          *(_DWORD *)(StatusReg + 16) += 512;
          v28 = ieee80211_xmit(a2 + 2688, v11, v15);
          bss = local_bh_enable_0(v28);
        }
      }
      else
      {
        v26 = -12;
      }
    }
    else
    {
      __break(0x800u);
      v26 = -22;
    }
  }
  else
  {
    v26 = -67;
  }
  _rcu_read_unlock(bss);
  return v26;
}
