void __fastcall ieee80211_csa_switch_work(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 v4; // x8
  unsigned int *v5; // x21
  int v6; // w9
  unsigned int v7; // w0
  __int64 v8; // x8
  __int64 v9; // x3
  void *v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 *v13; // x1
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v16; // x12
  __int64 v17; // x9
  __int64 v18; // x11
  __int64 v19; // x12
  __int64 v21; // x2
  _DWORD *v22; // x9
  _QWORD *v23; // x8
  __int64 v24; // x9
  __int64 v25; // x11
  __int64 v26; // x12
  __int64 v27; // x9
  __int64 v28; // x11
  __int64 v29; // x12
  __int64 v30; // x9
  __int64 v31; // x11
  __int64 v32; // x12
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x8

  v2 = a2 - 568;
  v3 = *(_QWORD *)(a2 - 568);
  if ( (*(_QWORD *)(v3 + 1632) & 1) == 0 )
    return;
  if ( (*(_BYTE *)(v3 + 2477) & 8) == 0 )
    return;
  v4 = *(_QWORD *)(a2 + 376);
  if ( *(_BYTE *)(v4 + 830) != 1 )
    return;
  v5 = (unsigned int *)(a2 - 560);
  v6 = *(_DWORD *)(a2 - 560);
  if ( *(_WORD *)(v3 + 5800) )
  {
    if ( (((unsigned __int64)*(unsigned __int16 *)(v3 + 5802) >> v6) & 1) != 0 )
      goto LABEL_6;
LABEL_12:
    v13 = (__int64 *)(a2 - 400);
    v14 = v13[3];
    v15 = *v13;
    v16 = v13[1];
    *(_QWORD *)(v4 + 152) = v13[2];
    *(_QWORD *)(v4 + 160) = v14;
    *(_QWORD *)(v4 + 136) = v15;
    *(_QWORD *)(v4 + 144) = v16;
    v17 = v13[7];
    v18 = v13[4];
    v19 = v13[5];
    *(_QWORD *)(v4 + 184) = v13[6];
    *(_QWORD *)(v4 + 192) = v17;
    *(_QWORD *)(v4 + 168) = v18;
    *(_QWORD *)(v4 + 176) = v19;
    cfg80211_ch_switch_notify(*(_QWORD *)(v3 + 1608), v13, *v5);
    return;
  }
  if ( v6 )
    goto LABEL_12;
LABEL_6:
  if ( *(_QWORD *)(a2 - 200) )
  {
    if ( (*(_BYTE *)(a2 - 127) & 1) == 0 )
    {
      v7 = ieee80211_link_use_reserved_context(a2 - 568);
      if ( v7 )
      {
        v8 = *(_QWORD *)v2;
        v9 = v7;
        if ( *(_WORD *)(*(_QWORD *)v2 + 5800LL) )
        {
          printk(&unk_B872F, v8 + 1640, *v5, v7);
          goto LABEL_32;
        }
        v10 = &unk_BC699;
        v11 = v8 + 1640;
        v12 = (unsigned int)v9;
        goto LABEL_30;
      }
    }
  }
  else
  {
    if ( !ieee80211_chanreq_identical(v4 + 136, a2 - 400) )
    {
      v35 = *(_QWORD *)v2;
      if ( !*(_WORD *)(*(_QWORD *)v2 + 5800LL) )
      {
        printk(&unk_B9B53, v35 + 1640, v21, v9);
LABEL_32:
        wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v3 + 1616) + 72LL), v3 + 2432);
        return;
      }
      v12 = *v5;
      v10 = &unk_BC92F;
      v11 = v35 + 1640;
LABEL_30:
      printk(v10, v11, v12, v9);
      goto LABEL_32;
    }
    v22 = *(_DWORD **)(a2 + 72);
    *(_BYTE *)(a2 + 216) = 1;
    if ( *v22 == 3 && *(_DWORD *)(a2 - 16) >= 4u )
    {
      ieee80211_rearrange_tpe(a2 + 104);
      if ( bcmp((const void *)(*(_QWORD *)(a2 + 376) + 724LL), (const void *)(a2 + 104), 0x68u) )
      {
        v23 = (_QWORD *)(*(_QWORD *)(a2 + 376) + 724LL);
        *v23 = *(_QWORD *)(a2 + 104);
        v24 = *(_QWORD *)(a2 + 136);
        v25 = *(_QWORD *)(a2 + 112);
        v26 = *(_QWORD *)(a2 + 120);
        v23[3] = *(_QWORD *)(a2 + 128);
        v23[4] = v24;
        v23[1] = v25;
        v23[2] = v26;
        v27 = *(_QWORD *)(a2 + 168);
        v28 = *(_QWORD *)(a2 + 144);
        v29 = *(_QWORD *)(a2 + 152);
        v23[7] = *(_QWORD *)(a2 + 160);
        v23[8] = v27;
        v23[5] = v28;
        v23[6] = v29;
        v30 = *(_QWORD *)(a2 + 200);
        v31 = *(_QWORD *)(a2 + 176);
        v32 = *(_QWORD *)(a2 + 184);
        v23[11] = *(_QWORD *)(a2 + 192);
        v23[12] = v30;
        v23[9] = v31;
        v23[10] = v32;
        ieee80211_link_info_change_notify(v3, v2, 0x800000000LL);
      }
    }
    if ( (*(_BYTE *)(v3 + 5872) & 1) == 0 && (*(_QWORD *)(*(_QWORD *)(v3 + 1616) + 96LL) & 0x20000) == 0 )
    {
      v33 = round_jiffies_up(*(_QWORD *)(v3 + 2456) + jiffies);
      mod_timer(v3 + 2344, v33);
    }
    if ( (*(_BYTE *)(v3 + 2477) & 8) != 0 )
    {
      if ( *(_DWORD *)(v3 + 2472) )
        *(_DWORD *)(v3 + 2472) = 0;
      if ( (*(_QWORD *)(*(_QWORD *)(v3 + 1616) + 96LL) & 0x20000) == 0 )
      {
        v34 = round_jiffies_up(jiffies + 7500LL);
        mod_timer(v3 + 2304, v34);
      }
    }
  }
}
