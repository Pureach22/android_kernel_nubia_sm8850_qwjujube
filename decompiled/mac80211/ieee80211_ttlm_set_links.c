__int64 __fastcall ieee80211_ttlm_set_links(__int64 a1, unsigned int a2, __int64 a3, __int16 a4)
{
  __int64 v6; // x21
  unsigned int v7; // w20
  int v9; // w8
  __int64 v10; // x1
  unsigned int v11; // w22
  unsigned int v12; // w9
  unsigned int active; // w0
  __int64 v14; // x3
  unsigned int v15; // w0
  __int64 v16; // x1
  void *v17; // x0

  if ( !(_WORD)a2 )
  {
    v7 = -22;
LABEL_5:
    ieee80211_disconnect((_DWORD *)(a1 + 4720), 0);
    return v7;
  }
  if ( *(_BYTE *)(a1 + 5840) == 1 )
  {
    v6 = 0x400000000LL;
    *(_DWORD *)(a1 + 5838) = 0;
    *(_QWORD *)(a1 + 5822) = 0;
    *(_QWORD *)(a1 + 5830) = 0;
    *(_QWORD *)(a1 + 5806) = 0;
    *(_QWORD *)(a1 + 5814) = 0;
  }
  else
  {
    v6 = 0;
  }
  v9 = *(unsigned __int16 *)(a1 + 5802);
  if ( v9 != (unsigned __int16)a2 )
  {
    v10 = v9 & a2;
    v6 |= 0x200000000uLL;
    v11 = a3;
    if ( !(_DWORD)v10 )
    {
      v12 = *(unsigned __int16 *)(a1 + 5800) & (~(_WORD)a3 | 0xFFFF0000);
      v10 = v12 & -v12;
    }
    active = ieee80211_set_active_links(a1 + 4720, v10);
    a3 = v11;
    if ( active )
    {
      v7 = active;
      v17 = &unk_BB915;
      goto LABEL_18;
    }
  }
  v15 = ieee80211_vif_set_links((unsigned __int16 *)a1, *(unsigned __int16 *)(a1 + 5800), a3);
  if ( v15 )
  {
    v7 = v15;
    v17 = &unk_B9658;
LABEL_18:
    printk(v17, a1 + 1640, a3, v14);
    goto LABEL_5;
  }
  if ( a4 )
    v16 = v6 | 0x400000000LL;
  else
    v16 = v6;
  *(_WORD *)(a1 + 5806) = a4;
  ieee80211_vif_cfg_change_notify(a1, v16);
  return 0;
}
