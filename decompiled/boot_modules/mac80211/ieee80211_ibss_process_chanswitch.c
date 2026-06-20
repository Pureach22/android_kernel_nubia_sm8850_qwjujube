__int64 __fastcall ieee80211_ibss_process_chanswitch(__int64 a1, __int64 a2)
{
  int v4; // w8
  unsigned int *v5; // x8
  unsigned int v6; // w21
  int v7; // w0
  unsigned int v8; // w20
  __int64 v9; // x0
  __int64 v10; // x2
  int v11; // w0
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x1
  __int64 v15; // x8
  void *v16; // x0
  __int64 v18; // [xsp+8h] [xbp-218h] BYREF
  __int64 v19; // [xsp+10h] [xbp-210h] BYREF
  __int64 v20; // [xsp+18h] [xbp-208h]
  __int64 v21; // [xsp+20h] [xbp-200h]
  __int64 v22; // [xsp+28h] [xbp-1F8h]
  __int64 v23; // [xsp+30h] [xbp-1F0h]
  __int64 v24; // [xsp+38h] [xbp-1E8h]
  __int64 v25; // [xsp+40h] [xbp-1E0h]
  __int64 v26; // [xsp+48h] [xbp-1D8h]
  __int64 v27; // [xsp+50h] [xbp-1D0h]
  __int64 v28; // [xsp+58h] [xbp-1C8h]
  _QWORD s[53]; // [xsp+60h] [xbp-1C0h] BYREF
  int v30; // [xsp+20Ch] [xbp-14h] BYREF
  __int64 v31; // [xsp+210h] [xbp-10h]
  __int64 v32; // [xsp+218h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 2408);
  v18 = 0x100000002LL;
  if ( (unsigned int)(v4 - 6) < 2 )
    goto LABEL_4;
  if ( v4 == 1 )
  {
LABEL_5:
    HIDWORD(v18) = 0;
    goto LABEL_6;
  }
  if ( !v4 )
  {
LABEL_4:
    LODWORD(v18) = 1;
    goto LABEL_5;
  }
LABEL_6:
  v5 = *(unsigned int **)(a2 + 144);
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  if ( v5 )
    v6 = *v5;
  else
    v6 = 0;
  memset(s, 0, sizeof(s));
  v7 = ieee80211_parse_ch_switch_ie(a1, a2, **(unsigned int **)(a1 + 2400), v6, &v18, a1 + 2346, 0, &v19);
  if ( v7 < 0 )
    goto LABEL_38;
  if ( v7 )
  {
    v8 = 0;
    goto LABEL_40;
  }
  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL);
  if ( (*(_BYTE *)(v9 + 102) & 0x80) == 0 )
    goto LABEL_38;
  v10 = *(unsigned int *)(a1 + 2408);
  BYTE2(s[51]) = BYTE1(v27);
  s[0] = v19;
  s[1] = v20;
  s[2] = v21;
  s[3] = v22;
  if ( (int)v10 <= 5 )
  {
    if ( (unsigned int)v10 < 2 )
    {
LABEL_19:
      cfg80211_chandef_create(s, s[0], v10);
      v9 = *(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL);
      goto LABEL_22;
    }
    if ( (_DWORD)v10 == 2 )
    {
      if ( *(_DWORD *)(a1 + 2412) <= *(_DWORD *)(*(_QWORD *)(a1 + 2400) + 4LL) )
        v10 = 2;
      else
        v10 = 3;
      goto LABEL_19;
    }
LABEL_34:
    __break(0x800u);
    goto LABEL_38;
  }
  if ( (unsigned int)(v10 - 6) >= 2 )
    goto LABEL_34;
  if ( LODWORD(s[1]) != (_DWORD)v10 )
  {
    v15 = s[0];
    v16 = &unk_BB400;
    goto LABEL_37;
  }
LABEL_22:
  v30 = 1;
  v31 = 0;
  if ( (cfg80211_reg_check_beaconing(v9, s, &v30) & 1) == 0 )
  {
    v15 = s[0];
    v16 = &unk_B7CB6;
LABEL_37:
    printk(v16, a1 + 1640, a1 + 2346, *(unsigned int *)(v15 + 4));
    goto LABEL_38;
  }
  v11 = cfg80211_chandef_dfs_required(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), s, 1);
  if ( (v11 & 0x80000000) == 0 && (!v11 || *(_BYTE *)(a1 + 2344) == 1) )
  {
    v12 = *(_QWORD *)(a1 + 4944);
    LOBYTE(s[51]) = v11 != 0;
    if ( s[0] == v12
      && s[1] == *(_QWORD *)(a1 + 4952)
      && WORD2(s[3]) == *(unsigned __int16 *)(a1 + 4972)
      && LODWORD(s[2]) == *(_DWORD *)(a1 + 4960)
      && HIWORD(s[3]) == *(unsigned __int16 *)(a1 + 4974) )
    {
      goto LABEL_33;
    }
    v13 = *(_QWORD *)(a1 + 1616);
    v14 = *(_QWORD *)(a1 + 1608);
    BYTE1(s[51]) = (_BYTE)v27 != 0;
    if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, _QWORD *))ieee80211_channel_switch)(
                          *(_QWORD *)(v13 + 72),
                          v14,
                          s) )
    {
      ieee80211_ibss_csa_mark_radar(a1);
LABEL_33:
      v8 = 1;
      goto LABEL_40;
    }
  }
LABEL_38:
  wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), a1 + 2304);
  v8 = 1;
  if ( (int)cfg80211_chandef_dfs_required(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), a1 + 2400, 1) >= 1 )
    _cfg80211_radar_event(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), a1 + 2400, 0, 2080);
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return v8;
}
