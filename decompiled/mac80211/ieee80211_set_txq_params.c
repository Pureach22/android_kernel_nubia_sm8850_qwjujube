__int64 __fastcall ieee80211_set_txq_params(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v8; // w10
  unsigned __int64 v9; // x19
  __int64 v10; // x8
  unsigned __int64 v11; // x8
  char v13; // w8
  __int16 v15; // w9
  unsigned int v18; // w8
  unsigned int v19; // w10
  __int64 v20; // x11
  unsigned __int64 v21; // x9
  _BYTE v22[14]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_20;
  v10 = a3[3];
  if ( (v10 & 0x80000000) != 0 )
  {
    if ( *(_WORD *)(a2 + 8488) )
      v9 = -22;
    else
      v9 = a2 + 6304;
    goto LABEL_10;
  }
  if ( (unsigned int)v10 < 0xF )
  {
    v11 = *(_QWORD *)(a2 + 8 * v10 + 7256);
    if ( v11 )
      v9 = v11;
    else
      v9 = -67;
LABEL_10:
    if ( !*(_QWORD *)(*(_QWORD *)(a1 + 2000) + 336LL) || *(unsigned __int16 *)(a1 + 1664) < 4u )
    {
      LODWORD(v9) = -95;
LABEL_13:
      _ReadStatusReg(SP_EL0);
      return (unsigned int)v9;
    }
    if ( v9 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_13;
    v13 = *((_BYTE *)a3 + 10);
    *(_QWORD *)&v22[6] = 0;
    v15 = *((_WORD *)a3 + 4);
    v22[6] = v13;
    v18 = *a3;
    v19 = a3[1];
    *(_WORD *)&v22[4] = v15;
    *(_DWORD *)v22 = v19;
    ieee80211_regulatory_limit_wmm_params(a2 + 2688, v22, v18);
    if ( *a3 < 5 )
    {
      v20 = *(_QWORD *)&v22[6];
      v21 = v9 + 14LL * *a3;
      *(_QWORD *)(v21 + 888) = *(_QWORD *)v22;
      *(_QWORD *)(v21 + 894) = v20;
      if ( (unsigned int)drv_conf_tx(a1 + 1536, v9, *a3, v22) )
      {
        dev_printk(&unk_BBEF5, *(_QWORD *)(a1 + 1608) + 392LL, "failed to set TX queue parameters for AC %d\n", *a3);
        LODWORD(v9) = -22;
      }
      else
      {
        ieee80211_link_info_change_notify(a2 + 2688, v9, 0x2000);
        LODWORD(v9) = 0;
      }
      goto LABEL_13;
    }
  }
  __break(0x5512u);
LABEL_20:
  __break(0x800u);
  *(_DWORD *)(a8 - 120) = v9;
  *(_DWORD *)(a8 - 116) = v8;
  return ieee80211_set_monitor_channel();
}
