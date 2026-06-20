__int64 __fastcall ieee80211_start_ap(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x22
  __int64 v8; // x19
  __int64 result; // x0
  __int64 v10; // x21
  __int16 v11; // w24
  _BYTE *v12; // x8
  _BYTE *v13; // x8
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v18; // x8
  _DWORD *v19; // x8
  _QWORD **v20; // x24
  __int64 v21; // x9
  _QWORD *v22; // x10
  _BYTE *v23; // x11
  char v24; // w10
  __int64 v25; // x11
  __int64 v26; // x13
  size_t v27; // x2
  int v28; // w10
  char v29; // w10
  int v30; // w10
  int v31; // w10
  int v32; // w10
  int v33; // w10
  int v34; // w10
  int v35; // w9
  unsigned int v36; // w0
  unsigned int started; // w0
  __int64 v38; // x1
  unsigned int v39; // w20
  _QWORD *v40; // x19
  size_t v41; // [xsp+8h] [xbp-58h]
  _QWORD v42[8]; // [xsp+10h] [xbp-50h] BYREF
  _QWORD v43[2]; // [xsp+50h] [xbp-10h] BYREF

  v43[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 4304);
  memset(&v42[4], 0, 32);
  v43[0] = 135004992;
  v4 = *(_QWORD *)(a3 + 8);
  v42[0] = *(_QWORD *)a3;
  v42[1] = v4;
  v5 = *(_QWORD *)(a3 + 24);
  v7 = a3 + 32;
  v6 = *(unsigned int *)(a3 + 32);
  v42[2] = *(_QWORD *)(a3 + 16);
  v42[3] = v5;
  if ( (unsigned int)v6 >= 0xF )
    __break(0x5512u);
  v8 = *(_QWORD *)(a2 + 8 * v6 + 7256);
  if ( !v8 )
  {
    result = 4294967229LL;
    goto LABEL_8;
  }
  if ( *(_QWORD *)(v8 + 536) )
  {
    result = 4294967182LL;
    goto LABEL_8;
  }
  if ( *(_DWORD *)(a3 + 368) )
  {
LABEL_7:
    result = 4294967201LL;
    goto LABEL_8;
  }
  v10 = *(_QWORD *)(v8 + 944);
  *(_DWORD *)(v8 + 444) = 1;
  *(_BYTE *)(v8 + 442) = *(_BYTE *)(*(_QWORD *)(a2 + 4304) + 1504LL);
  v11 = *(_WORD *)(v10 + 50);
  *(_WORD *)(v10 + 50) = *(_DWORD *)(a3 + 208);
  v12 = *(_BYTE **)(a3 + 760);
  if ( v12 )
    *(_BYTE *)(v10 + 842) = *v12 & 1;
  v13 = *(_BYTE **)(a3 + 768);
  if ( v13 )
  {
    *(_BYTE *)(v10 + 843) = (*v13 & 0x10) != 0;
    *(_BYTE *)(v10 + 845) = (**(_DWORD **)(a3 + 768) & 0x800) != 0;
    *(_BYTE *)(v10 + 846) = (**(_DWORD **)(a3 + 768) & 0x1000) != 0;
    *(_BYTE *)(v10 + 847) = (**(_DWORD **)(a3 + 768) & 0x80000) != 0;
    *(_BYTE *)(v10 + 848) = (**(_DWORD **)(a3 + 768) & 0x100000) != 0;
  }
  v14 = *(_QWORD *)(a3 + 776);
  if ( v14 )
  {
    if ( !*(_QWORD *)(a3 + 784) )
      goto LABEL_18;
    *(_BYTE *)(v10 + 40) = 1;
    v15 = 403440448;
    *(_BYTE *)(v10 + 34) = **(_BYTE **)(a3 + 784) & 7;
    *(_WORD *)(v10 + 38) = (**(_WORD **)(a3 + 784) >> 4) & 0x3FF;
    v14 = *(_QWORD *)(a3 + 776);
    if ( *(_BYTE *)(a3 + 193) )
      v15 = 940311360;
    v43[0] = v15;
    if ( v14 )
    {
LABEL_18:
      *(_BYTE *)(v10 + 844) = (*(_BYTE *)(v14 + 7) & 0x20) != 0;
      *(_BYTE *)(v10 + 849) = *(_BYTE *)(*(_QWORD *)(a3 + 776) + 9LL) >> 7;
      *(_BYTE *)(v10 + 850) = *(_BYTE *)(*(_QWORD *)(a3 + 776) + 10LL) & 1;
      *(_BYTE *)(v10 + 851) = (*(_BYTE *)(*(_QWORD *)(a3 + 776) + 10LL) & 2) != 0;
      *(_BYTE *)(v10 + 852) = (*(_BYTE *)(*(_QWORD *)(a3 + 776) + 8LL) & 0x40) != 0;
    }
  }
  if ( *(_QWORD *)(a3 + 792) )
  {
    if ( *(_BYTE *)(v10 + 40) != 1 )
      goto LABEL_7;
    *(_BYTE *)(v10 + 829) = 1;
    *(_BYTE *)(v10 + 853) = (*(_BYTE *)(*(_QWORD *)(a3 + 792) + 2LL) & 0x20) != 0;
    *(_BYTE *)(v10 + 854) = (*(_BYTE *)(*(_QWORD *)(a3 + 792) + 2LL) & 0x40) != 0;
    *(_BYTE *)(v10 + 855) = (*(_BYTE *)(*(_QWORD *)(a3 + 792) + 9LL) & 0x70) != 0;
    *(_BYTE *)(v10 + 856) = (*(_BYTE *)(*(_QWORD *)(a3 + 792) + 9LL) & 0xE) != 0;
  }
  else
  {
    *(_BYTE *)(v10 + 855) = 0;
    *(_WORD *)(v10 + 853) = 0;
  }
  if ( *(_DWORD *)(a2 + 7408) != 3
    || (v18 = *(_QWORD *)(a3 + 904)) == 0
    || (result = ieee80211_set_ap_mbssid_options(a2 + 2688, v18, *(_QWORD *)(a3 + 912), v10), !(_DWORD)result) )
  {
    result = ieee80211_link_use_channel(v8, v42, 0, 0);
    if ( (_DWORD)result )
    {
      *(_WORD *)(v10 + 50) = v11;
      goto LABEL_8;
    }
    ieee80211_link_copy_chanctx_to_vlans(v8, 0);
    v19 = (_DWORD *)a2;
    v20 = (_QWORD **)(a2 + 4952);
    v21 = a3;
    *(_WORD *)(a2 + 4628) = *(_WORD *)(a3 + 318);
    *(_BYTE *)(a2 + 4630) = *(_BYTE *)(a3 + 320);
    *(_BYTE *)(a2 + 4632) = *(_BYTE *)(a3 + 321);
    v22 = *(_QWORD **)(a2 + 4952);
    *(_BYTE *)(a2 + 4631) = *(_BYTE *)(a3 + 322);
    if ( v22 != (_QWORD *)(a2 + 4952) )
    {
      do
      {
        *((_WORD *)v22 - 162) = *(_WORD *)(a3 + 318);
        *((_BYTE *)v22 - 322) = *(_BYTE *)(a3 + 320);
        *((_BYTE *)v22 - 320) = *(_BYTE *)(a3 + 321);
        v23 = (char *)v22 - 321;
        v22 = (_QWORD *)*v22;
        *v23 = *(_BYTE *)(a3 + 322);
      }
      while ( v22 != v20 );
    }
    v24 = *(_DWORD *)(a3 + 212);
    *(_BYTE *)(v10 + 48) = 1;
    *(_BYTE *)(v10 + 49) = v24;
    *(_BYTE *)(v10 + 290) = *(_BYTE *)(a2 + 8536);
    *(_BYTE *)(v10 + 42) = *(_BYTE *)(a3 + 812);
    v25 = *(_QWORD *)(a3 + 820);
    v26 = *(_QWORD *)(a3 + 828);
    *(_QWORD *)(v10 + 337) = *(_QWORD *)(a3 + 833);
    *(_QWORD *)(v10 + 324) = v25;
    *(_QWORD *)(v10 + 332) = v26;
    LOWORD(v25) = *(_WORD *)(a3 + 192);
    *(_BYTE *)(v10 + 347) = *(_BYTE *)(a3 + 194);
    *(_WORD *)(v10 + 345) = v25;
    *(_BYTE *)(a2 + 7488) = **(_DWORD **)a3 == 4;
    v27 = *(_QWORD *)(a3 + 224);
    *(_QWORD *)(a2 + 7480) = v27;
    if ( v27 )
    {
      if ( v27 >= 0x21 && (ieee80211_start_ap___already_done & 1) == 0 )
      {
        ieee80211_start_ap___already_done = 1;
        v41 = v27;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v27,
          "field \"sdata->vif.cfg.ssid\" at ../soc-repo/net/mac80211/cfg.c:1442",
          0x20u);
        v27 = v41;
        v21 = a3;
        v19 = (_DWORD *)a2;
        __break(0x800u);
      }
      memcpy(v19 + 1862, *(const void **)(v21 + 216), v27);
      v21 = a3;
      v19 = (_DWORD *)a2;
    }
    v28 = *(_DWORD *)(v21 + 232);
    *(_QWORD *)(v10 + 236) = 0;
    *(_QWORD *)(v10 + 244) = 0;
    *(_QWORD *)(v10 + 252) = 0;
    *(_QWORD *)(v10 + 260) = 0;
    *(_QWORD *)(v10 + 268) = 0;
    *(_BYTE *)(v10 + 225) = v28 != 0;
    *(_QWORD *)(v10 + 276) = 0;
    *(_QWORD *)(v10 + 282) = 0;
    v29 = *(_BYTE *)(v21 + 376);
    *(_BYTE *)(v10 + 237) = v29 & 0x7F;
    if ( *(_BYTE *)(v21 + 377) == 1 )
      *(_BYTE *)(v10 + 237) = v29 | 0x80;
    *(_BYTE *)(a2 + 4944) = 0;
    if ( (*(_BYTE *)(*(_QWORD *)(v3 + 72) + 112LL) & 0x40) != 0 )
    {
      v30 = *(_DWORD *)(v21 + 396);
      v19[1230] = v30;
      if ( v30 )
        *(_BYTE *)(a2 + 4944) = 1;
      v31 = *(_DWORD *)(v21 + 456);
      v19[1231] = v31;
      if ( v31 )
        *(_BYTE *)(a2 + 4944) = 1;
      v32 = *(_DWORD *)(v21 + 516);
      v19[1232] = v32;
      if ( v32 )
        *(_BYTE *)(a2 + 4944) = 1;
      v33 = *(_DWORD *)(v21 + 576);
      v19[1233] = v33;
      if ( v33 )
        *(_BYTE *)(a2 + 4944) = 1;
      v34 = *(_DWORD *)(v21 + 636);
      v19[1234] = v34;
      if ( v34 )
        *(_BYTE *)(a2 + 4944) = 1;
      v35 = *(_DWORD *)(v21 + 696);
      v19[1235] = v35;
      if ( v35 )
        *(_BYTE *)(a2 + 4944) = 1;
    }
    if ( (*(_QWORD *)(v3 + 96) & 1) != 0 )
    {
      memcpy((void *)(v10 + 360), (const void *)(a3 + 396), 0x168u);
      v19 = (_DWORD *)a2;
    }
    v36 = ieee80211_assign_beacon(v19 + 672, v8, v7, 0, 0, v43);
    if ( (v36 & 0x80000000) != 0
      || (v36 = ieee80211_set_fils_discovery(a3 + 848, v8, v10, v43), (v36 & 0x80000000) != 0)
      || (v36 = ieee80211_set_unsol_bcast_probe_resp(a3 + 880, v8, v10, v43), (v36 & 0x80000000) != 0) )
    {
      v39 = v36;
LABEL_61:
      ieee80211_link_release_channel(v8);
      result = v39;
      goto LABEL_8;
    }
    started = drv_start_ap(*(_QWORD *)(a2 + 4304), a2 + 2688, v10);
    if ( started )
    {
      v38 = *(_QWORD *)(v8 + 536);
      v39 = started;
      if ( v38 )
        kvfree_call_rcu(v38 + 56, v38);
      *(_QWORD *)(v8 + 536) = 0;
      if ( !(unsigned __int8)ieee80211_num_beaconing_links(a2 + 2688) )
        *(_BYTE *)(a2 + 5269) = 0;
      goto LABEL_61;
    }
    ieee80211_recalc_dtim(v3, a2 + 2688);
    ieee80211_vif_cfg_change_notify(a2 + 2688, 0x8000);
    ieee80211_link_info_change_notify(a2 + 2688, v8, v43[0]);
    if ( (unsigned __int8)ieee80211_num_beaconing_links(a2 + 2688) <= 1u )
      netif_carrier_on(a2);
    v40 = *v20;
    if ( *v20 == v20 )
    {
      result = 0;
    }
    else
    {
      do
      {
        netif_carrier_on(*(v40 - 82));
        v40 = (_QWORD *)*v40;
        result = 0;
      }
      while ( v40 != v20 );
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
