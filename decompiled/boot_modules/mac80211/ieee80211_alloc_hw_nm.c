__int64 __fastcall ieee80211_alloc_hw_nm(int a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 result; // x0
  __int64 (__fastcall *v5)(__int64, __int64); // x21
  __int64 (__fastcall *v6)(__int64); // x8
  __int64 (__fastcall *v7)(__int64, __int64); // x9
  __int64 v9; // x1
  int v10; // w11
  __int64 v11; // x19
  int v12; // w8
  int v13; // w10
  char v14; // w16
  char v15; // w11
  char v16; // w14
  char v17; // w13
  char v18; // w15
  char v19; // w17
  char v20; // w11
  char v21; // w9
  char v22; // w8
  char v23; // w10
  char v24; // w8

  if ( !*a2 || !a2[1] || !a2[2] || !a2[9] || !a2[6] || !a2[8] || !a2[16] || !a2[94] || a2[37] && (a2[33] || a2[34]) )
    goto LABEL_17;
  v3 = a2[11];
  v2 = a2[12];
  if ( v2 && v3 )
  {
    if ( a2[10] )
    {
LABEL_17:
      __break(0x800u);
      return 0;
    }
  }
  else if ( (v2 != 0) != (v3 != 0) )
  {
    goto LABEL_17;
  }
  v5 = (__int64 (__fastcall *)(__int64, __int64))a2[74];
  v6 = (__int64 (__fastcall *)(__int64))a2[75];
  if ( v5 != ieee80211_emulate_add_chanctx )
  {
    if ( v6 == ieee80211_emulate_remove_chanctx )
      goto LABEL_17;
    v7 = (__int64 (__fastcall *)(__int64, __int64))a2[76];
    if ( v7 == ieee80211_emulate_change_chanctx )
      goto LABEL_17;
    if ( v5 && v6 && v7 && a2[77] && a2[78] )
      goto LABEL_27;
LABEL_40:
    result = 0;
    __break(0x800u);
    return result;
  }
  if ( v6 != ieee80211_emulate_remove_chanctx
    || (__int64 (__fastcall *)(__int64, __int64))a2[76] != ieee80211_emulate_change_chanctx )
  {
    goto LABEL_17;
  }
  if ( a2[77] || a2[78] )
    goto LABEL_40;
LABEL_27:
  result = wiphy_new_nm(&mac80211_config_ops, (unsigned int)(a1 + 5472));
  if ( result )
  {
    v10 = *(_DWORD *)(result + 100);
    v11 = result;
    *(_QWORD *)(result + 72) = &ieee80211_default_mgmt_stypes;
    v12 = v10 | 0x140068;
    *(_QWORD *)(result + 320) = &mac80211_wiphy_privid;
    *(_DWORD *)(result + 100) = v10 | 0x140068;
    if ( v5 == ieee80211_emulate_add_chanctx || a2[59] )
    {
      v12 = v10 | 0x340068;
      *(_DWORD *)(result + 100) = v10 | 0x340068;
    }
    v13 = *(_DWORD *)(result + 108);
    v14 = *(_BYTE *)(result + 117);
    v15 = *(_BYTE *)(result + 113);
    v16 = *(_BYTE *)(result + 118) | 1;
    v17 = *(_BYTE *)(result + 115);
    *(_DWORD *)(result + 108) = v13 | 0x8018223;
    v18 = *(_BYTE *)(result + 119);
    v19 = v15 | 2;
    *(_BYTE *)(result + 118) = v16;
    v20 = v17 | 4;
    *(_BYTE *)(result + 113) = v19;
    *(_BYTE *)(result + 117) = v14 | 0x84;
    *(_BYTE *)(result + 115) = v17 | 4;
    *(_BYTE *)(result + 119) = v18 | 0x20;
    if ( !a2[23] )
    {
      v20 = v17 | 0x64;
      *(_DWORD *)(result + 108) = v13 | 0x8018363;
      *(_BYTE *)(result + 115) = v17 | 0x64;
    }
    if ( !a2[19] )
    {
      v21 = *(_BYTE *)(result + 120);
      *(_DWORD *)(result + 100) = v12 | 0x100;
      *(_BYTE *)(result + 120) = v21 | 0x10;
    }
    v22 = *(_BYTE *)(result + 112);
    *(_BYTE *)(result + 115) = v20 | 0x10;
    *(_DWORD *)(result + 132) = 72;
    *(_BYTE *)(result + 112) = v22 | 2;
    if ( (unsigned int)sta_info_init(result + 1536, v9) )
    {
      wiphy_free(v11);
      return 0;
    }
    else
    {
      *(_QWORD *)(v11 + 1608) = v11;
      *(_QWORD *)(v11 + 2000) = a2;
      *(_QWORD *)(v11 + 1624) = v11 + 7008;
      *(_BYTE *)(v11 + 2936) = v5 == ieee80211_emulate_add_chanctx;
      if ( v5 == ieee80211_emulate_add_chanctx )
        *(_QWORD *)(v11 + 1632) |= 0x4000000uLL;
      v23 = *(_BYTE *)(v11 + 197);
      *(_BYTE *)(v11 + 1707) = 7;
      *(_WORD *)(v11 + 1669) = 1;
      *(_WORD *)(v11 + 1664) = 1;
      *(_DWORD *)(v11 + 1672) = 4194368;
      *(_WORD *)(v11 + 1677) = 2047;
      v24 = *(_BYTE *)(v11 + 196);
      *(_BYTE *)(v11 + 1551) = v23;
      *(_BYTE *)(v11 + 1552) = v24;
      *(_WORD *)(v11 + 1680) = 68;
      *(_DWORD *)(v11 + 1712) = 2304;
      *(_DWORD *)(v11 + 6692) = 0x80000000;
      *(_QWORD *)(v11 + 1320) = &mac80211_ht_capa_mod_mask;
      *(_QWORD *)(v11 + 1328) = &mac80211_vht_capa_mod_mask;
      *(_BYTE *)(v11 + 6999) = 64;
      *(_QWORD *)(v11 + 280) = v11 + 6992;
      *(_QWORD *)(v11 + 288) = v11 + 6992;
      *(_BYTE *)(v11 + 296) = 8;
      *(_WORD *)(v11 + 1704) = 0;
      *(_QWORD *)(v11 + 6152) = v11 + 6152;
      *(_QWORD *)(v11 + 6160) = v11 + 6152;
      *(_QWORD *)(v11 + 6168) = v11 + 6168;
      *(_QWORD *)(v11 + 6176) = v11 + 6168;
      _hw_addr_init(v11 + 2968);
      _mutex_init(v11 + 6184, "&local->iflist_mtx", &ieee80211_alloc_hw_nm___key);
      *(_DWORD *)(v11 + 2940) = 0;
      *(_DWORD *)(v11 + 3136) = 0;
      *(_DWORD *)(v11 + 2848) = 0;
      *(_QWORD *)(v11 + 1864) = v11 + 1864;
      *(_QWORD *)(v11 + 1872) = v11 + 1864;
      *(_DWORD *)(v11 + 1844) = 0;
      *(_DWORD *)(v11 + 1944) = 5000;
      *(_DWORD *)(v11 + 1960) = 12000;
      *(_DWORD *)(v11 + 1984) = 0;
      *(_QWORD *)(v11 + 1880) = v11 + 1880;
      *(_QWORD *)(v11 + 1888) = v11 + 1880;
      *(_QWORD *)(v11 + 1948) = 0x138800001388LL;
      *(_QWORD *)(v11 + 1848) = 0;
      *(_QWORD *)(v11 + 1964) = 0x2EE000002EE0LL;
      *(_DWORD *)(v11 + 1988) = 0;
      *(_QWORD *)(v11 + 1896) = v11 + 1896;
      *(_QWORD *)(v11 + 1904) = v11 + 1896;
      *(_DWORD *)(v11 + 1992) = 0;
      *(_QWORD *)(v11 + 1912) = v11 + 1912;
      *(_QWORD *)(v11 + 1920) = v11 + 1912;
      *(_DWORD *)(v11 + 1956) = 5000;
      *(_DWORD *)(v11 + 1856) = 0;
      *(_DWORD *)(v11 + 1972) = 12000;
      *(_DWORD *)(v11 + 1996) = 0;
      *(_WORD *)(v11 + 1940) = 3;
      *(_DWORD *)(v11 + 1976) = 24000;
      *(_DWORD *)(v11 + 1980) = 0;
      *(_DWORD *)(v11 + 1936) = 0;
      *(_QWORD *)(v11 + 6520) = v11 + 6520;
      *(_QWORD *)(v11 + 6528) = v11 + 6520;
      init_timer_key(v11 + 6464, &wiphy_delayed_work_timer, 0, 0, 0);
      *(_QWORD *)(v11 + 6432) = v11 + 6432;
      *(_QWORD *)(v11 + 6440) = v11 + 6432;
      *(_QWORD *)(v11 + 6448) = ieee80211_scan_work;
      *(_QWORD *)(v11 + 6696) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v11 + 6704) = v11 + 6704;
      *(_QWORD *)(v11 + 6712) = v11 + 6704;
      *(_QWORD *)(v11 + 6720) = ieee80211_restart_work;
      *(_QWORD *)(v11 + 3016) = v11 + 3016;
      *(_QWORD *)(v11 + 3024) = v11 + 3016;
      *(_QWORD *)(v11 + 3032) = ieee80211_dfs_radar_detected_work;
      *(_QWORD *)(v11 + 2944) = v11 + 2944;
      *(_QWORD *)(v11 + 2952) = v11 + 2944;
      *(_QWORD *)(v11 + 2960) = ieee80211_reconfig_filter;
      *(_QWORD *)(v11 + 6552) = v11 + 6552;
      *(_QWORD *)(v11 + 6560) = v11 + 6552;
      *(_QWORD *)(v11 + 6568) = ieee80211_dynamic_ps_enable_work;
      *(_QWORD *)(v11 + 6576) = v11 + 6576;
      *(_QWORD *)(v11 + 6584) = v11 + 6576;
      *(_QWORD *)(v11 + 6592) = ieee80211_dynamic_ps_disable_work;
      init_timer_key(v11 + 6600, ieee80211_dynamic_ps_timer, 0, 0, 0);
      *(_QWORD *)(v11 + 6368) = v11 + 6368;
      *(_QWORD *)(v11 + 6376) = v11 + 6368;
      *(_QWORD *)(v11 + 6384) = ieee80211_sched_scan_stopped_work;
      *(_DWORD *)(v11 + 6904) = 0;
      *(_QWORD *)(v11 + 6880) = 0x1000000400000000LL;
      *(_QWORD *)(v11 + 3536) = v11 + 3536;
      *(_QWORD *)(v11 + 3544) = v11 + 3536;
      *(_QWORD *)(v11 + 6888) = 0;
      *(_QWORD *)(v11 + 6896) = 0;
      *(_QWORD *)(v11 + 3552) = 0;
      *(_DWORD *)(v11 + 4000) = 0;
      *(_QWORD *)(v11 + 3560) = v11 + 3560;
      *(_QWORD *)(v11 + 3568) = v11 + 3560;
      *(_QWORD *)(v11 + 3576) = 0;
      *(_DWORD *)(v11 + 4004) = 0;
      *(_QWORD *)(v11 + 3584) = v11 + 3584;
      *(_QWORD *)(v11 + 3592) = v11 + 3584;
      *(_QWORD *)(v11 + 3600) = 0;
      *(_DWORD *)(v11 + 4008) = 0;
      *(_QWORD *)(v11 + 3608) = v11 + 3608;
      *(_QWORD *)(v11 + 3616) = v11 + 3608;
      *(_QWORD *)(v11 + 3624) = 0;
      *(_DWORD *)(v11 + 4012) = 0;
      *(_QWORD *)(v11 + 3632) = v11 + 3632;
      *(_QWORD *)(v11 + 3640) = v11 + 3632;
      *(_QWORD *)(v11 + 3648) = 0;
      *(_DWORD *)(v11 + 4016) = 0;
      *(_QWORD *)(v11 + 3656) = v11 + 3656;
      *(_QWORD *)(v11 + 3664) = v11 + 3656;
      *(_QWORD *)(v11 + 3672) = 0;
      *(_DWORD *)(v11 + 4020) = 0;
      *(_QWORD *)(v11 + 3680) = v11 + 3680;
      *(_QWORD *)(v11 + 3688) = v11 + 3680;
      *(_QWORD *)(v11 + 3696) = 0;
      *(_DWORD *)(v11 + 4024) = 0;
      *(_QWORD *)(v11 + 3704) = v11 + 3704;
      *(_QWORD *)(v11 + 3712) = v11 + 3704;
      *(_QWORD *)(v11 + 3720) = 0;
      *(_DWORD *)(v11 + 4028) = 0;
      *(_QWORD *)(v11 + 3728) = v11 + 3728;
      *(_QWORD *)(v11 + 3736) = v11 + 3728;
      *(_QWORD *)(v11 + 3744) = 0;
      *(_DWORD *)(v11 + 4032) = 0;
      *(_QWORD *)(v11 + 3752) = v11 + 3752;
      *(_QWORD *)(v11 + 3760) = v11 + 3752;
      *(_QWORD *)(v11 + 3768) = 0;
      *(_DWORD *)(v11 + 4036) = 0;
      *(_QWORD *)(v11 + 3776) = v11 + 3776;
      *(_QWORD *)(v11 + 3784) = v11 + 3776;
      *(_QWORD *)(v11 + 3792) = 0;
      *(_DWORD *)(v11 + 4040) = 0;
      *(_QWORD *)(v11 + 3800) = v11 + 3800;
      *(_QWORD *)(v11 + 3808) = v11 + 3800;
      *(_QWORD *)(v11 + 3816) = 0;
      *(_DWORD *)(v11 + 4044) = 0;
      *(_QWORD *)(v11 + 3824) = v11 + 3824;
      *(_QWORD *)(v11 + 3832) = v11 + 3824;
      *(_QWORD *)(v11 + 3840) = 0;
      *(_DWORD *)(v11 + 4048) = 0;
      *(_QWORD *)(v11 + 3848) = v11 + 3848;
      *(_QWORD *)(v11 + 3856) = v11 + 3848;
      *(_QWORD *)(v11 + 3864) = 0;
      *(_DWORD *)(v11 + 4052) = 0;
      *(_QWORD *)(v11 + 3872) = v11 + 3872;
      *(_QWORD *)(v11 + 3880) = v11 + 3872;
      *(_QWORD *)(v11 + 3888) = 0;
      *(_DWORD *)(v11 + 4056) = 0;
      *(_QWORD *)(v11 + 3912) = 0;
      *(_QWORD *)(v11 + 3896) = v11 + 3896;
      *(_QWORD *)(v11 + 3904) = v11 + 3896;
      *(_DWORD *)(v11 + 4060) = 0;
      tasklet_setup(v11 + 3920, ieee80211_tx_pending);
      tasklet_setup(v11 + 3960, ieee80211_wake_txqs);
      tasklet_setup(v11 + 3048, ieee80211_tasklet_handler);
      *(_QWORD *)(v11 + 3104) = 0;
      *(_QWORD *)(v11 + 3088) = v11 + 3088;
      *(_QWORD *)(v11 + 3096) = v11 + 3088;
      *(_QWORD *)(v11 + 3112) = v11 + 3112;
      *(_QWORD *)(v11 + 3120) = v11 + 3112;
      *(_QWORD *)(v11 + 3128) = 0;
      ieee80211_roc_setup(v11 + 1536);
      *(_DWORD *)(v11 + 1684) = -1;
      *(_WORD *)(v11 + 1688) = -1;
      return v11 + 1536;
    }
  }
  return result;
}
