__int64 __fastcall _ieee80211_disconnect(__int64 result)
{
  int v1; // w8
  __int64 v2; // x21
  __int64 v3; // x19
  __int64 v4; // x22
  int v5; // w8
  unsigned __int64 v6; // x10
  bool v7; // w20
  unsigned __int64 v8; // x11
  __int64 v9; // x10
  __int64 i; // x24
  __int64 v11; // x25
  __int64 v12; // x2
  int v13; // w21
  __int64 v14; // x0
  unsigned int v15; // w8
  __int64 v16; // [xsp+0h] [xbp-40h] BYREF
  int v17; // [xsp+8h] [xbp-38h]
  __int64 v18; // [xsp+Ch] [xbp-34h]
  int v19; // [xsp+14h] [xbp-2Ch]
  _QWORD v20[3]; // [xsp+18h] [xbp-28h] BYREF
  __int16 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(result + 2477) & 8) != 0 )
  {
    v1 = *(unsigned __int16 *)(result + 5800);
    v2 = *(_QWORD *)(result + 1616);
    v3 = result;
    v4 = result + 4568;
    v21 = 0;
    memset(v20, 0, sizeof(v20));
    if ( v1 && (*(_WORD *)(result + 5802) & 1) == 0 )
      goto LABEL_6;
    if ( !*(_QWORD *)v4 )
    {
      __break(0x800u);
      goto LABEL_6;
    }
    if ( (*(_BYTE *)(*(_QWORD *)v4 + 786LL) & 1) != 0 )
    {
LABEL_6:
      v5 = *(unsigned __int16 *)(result + 5800);
      v6 = 0;
      v7 = 1;
      while ( 1 )
      {
        v8 = v6 + 1;
        if ( v5 && ((*(unsigned __int16 *)(result + 5802) >> v8) & 1) != 0 )
        {
          v9 = *(_QWORD *)(result + 4576 + 8 * v6);
          if ( v9 )
          {
            if ( *(_BYTE *)(v9 + 786) != 1 )
              goto LABEL_14;
          }
          else
          {
            __break(0x800u);
          }
        }
        v6 = v8;
        v7 = v8 < 0xE;
        if ( v8 == 14 )
          goto LABEL_14;
      }
    }
    v7 = 1;
LABEL_14:
    if ( (*(_BYTE *)(result + 2477) & 2) != 0 )
    {
      v12 = 3;
    }
    else
    {
      for ( i = 0; i != 120; i += 8 )
      {
        v11 = *(_QWORD *)(v4 + i);
        if ( v11 )
        {
          cfg80211_unlink_bss(*(_QWORD *)(v2 + 72), *(_QWORD *)(*(_QWORD *)(v11 + 944) + 8LL));
          *(_QWORD *)(*(_QWORD *)(v11 + 944) + 8LL) = 0;
        }
      }
      if ( (*(_BYTE *)(v3 + 2477) & 2) != 0 )
        v12 = 3;
      else
        v12 = 4;
    }
    if ( v7 )
      v13 = 3;
    else
      v13 = 2;
    ieee80211_set_disassoc(v3, 192, v12, v7, v20);
    *(_BYTE *)(v3 + 5638) = 0;
    *(_BYTE *)(v3 + 4400) = 0;
    *(_BYTE *)(v3 + 4402) = 0;
    ieee80211_vif_unblock_queues_csa(v3);
    v14 = *(_QWORD *)(v3 + 1608);
    v16 = 1;
    v15 = *(unsigned __int8 *)(v3 + 2477);
    v17 = v13;
    v18 = 0x400000000LL;
    v19 = 0;
    if ( v7 )
      cfg80211_tx_mlme_mgmt(v14, v20, 26, (v15 >> 2) & 1);
    else
      cfg80211_rx_mlme_mgmt(v14, v20, 26);
    result = drv_event_callback(*(_QWORD *)(v3 + 1616), v3, &v16);
    *(_BYTE *)(v3 + 2477) &= ~4u;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
