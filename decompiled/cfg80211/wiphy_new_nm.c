__int64 __fastcall wiphy_new_nm(_QWORD *a1, int a2, const char *a3)
{
  unsigned __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x19
  int v8; // w21
  __int16 v9; // w8
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int v19; // w8
  unsigned int v20; // w8
  unsigned int v23; // w10

  if ( !a1[8] || a1[10] && a1[11] )
  {
    if ( !a1[42] )
      goto LABEL_9;
  }
  else
  {
    __break(0x800u);
    if ( !a1[42] )
      goto LABEL_9;
  }
  if ( !a1[43] || !a1[44] || !a1[45] )
    __break(0x800u);
LABEL_9:
  if ( a1[46] && !a1[48] )
  {
    __break(0x800u);
    if ( !a1[49] )
      goto LABEL_14;
  }
  else if ( !a1[49] )
  {
    goto LABEL_14;
  }
  if ( !a1[50] )
    __break(0x800u);
LABEL_14:
  if ( a1[3] && !a1[4] )
  {
    __break(0x800u);
    if ( !a1[17] )
      goto LABEL_19;
  }
  else if ( !a1[17] )
  {
    goto LABEL_19;
  }
  if ( !a1[18] )
    __break(0x800u);
LABEL_19:
  if ( a1[22] && !a1[23] )
  {
    __break(0x800u);
    if ( !a1[31] )
      goto LABEL_24;
  }
  else if ( !a1[31] )
  {
    goto LABEL_24;
  }
  if ( !a1[32] )
    __break(0x800u);
LABEL_24:
  if ( a1[82] && !a1[83] )
  {
    __break(0x800u);
    if ( !a1[14] )
      goto LABEL_29;
  }
  else if ( !a1[14] )
  {
    goto LABEL_29;
  }
  if ( !a1[16] )
    __break(0x800u);
LABEL_29:
  if ( a1[33] && !a1[34] )
  {
    __break(0x800u);
    if ( !*a1 )
      goto LABEL_34;
  }
  else if ( !*a1 )
  {
    goto LABEL_34;
  }
  if ( !a1[1] )
    __break(0x800u);
LABEL_34:
  if ( a1[74] && !a1[75] )
  {
    __break(0x800u);
    if ( !a1[63] )
      goto LABEL_39;
  }
  else if ( !a1[63] )
  {
    goto LABEL_39;
  }
  if ( !a1[64] )
    __break(0x800u);
LABEL_39:
  if ( a1[96] && !a1[97] )
  {
    __break(0x800u);
    if ( !a1[94] )
      goto LABEL_44;
  }
  else if ( !a1[94] )
  {
    goto LABEL_44;
  }
  if ( !a1[95] )
    __break(0x800u);
LABEL_44:
  v5 = a2 + 2528;
  v6 = _kmalloc_noprof(v5, 3520);
  v7 = v6;
  if ( !v6 )
    return 0;
  if ( v5 < 8 )
    goto LABEL_135;
  *(_QWORD *)v6 = a1;
  _X9 = &wiphy_new_nm_wiphy_counter;
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v19 = __ldxr((unsigned int *)&wiphy_new_nm_wiphy_counter);
    v20 = v19 + 1;
  }
  while ( __stlxr(v20, (unsigned int *)&wiphy_new_nm_wiphy_counter) );
  __dmb(0xBu);
  if ( v5 < 0x64 || (v5 & 0xFFFFFFFFFFFFFFFCLL) == 0x64 )
    goto LABEL_135;
  *(_DWORD *)(v6 + 100) = v20;
  if ( (v20 & 0x80000000) != 0 )
  {
LABEL_136:
    _X9 = &wiphy_new_nm_wiphy_counter;
    __asm { PRFM            #0x11, [X9] }
    do
      v23 = __ldxr((unsigned int *)&wiphy_new_nm_wiphy_counter);
    while ( __stxr(v23 - 1, (unsigned int *)&wiphy_new_nm_wiphy_counter) );
    goto LABEL_131;
  }
  if ( (v5 & 0xFFFFFFFFFFFFFFFCLL) == 0x64 )
    goto LABEL_135;
  *(_DWORD *)(v6 + 100) = v20 - 1;
  if ( a3 && *a3 )
  {
    rtnl_lock();
    if ( (cfg80211_dev_check_name(v7, a3) & 0x80000000) != 0 )
    {
      rtnl_unlock();
    }
    else
    {
      v8 = dev_set_name(v7 + 1384, "%s", a3);
      rtnl_unlock();
      if ( !v8 )
        goto LABEL_60;
    }
  }
  if ( (v5 & 0xFFFFFFFFFFFFFFFCLL) == 0x64 )
    goto LABEL_135;
  if ( (dev_set_name(v7 + 1384, "phy%d", *(_DWORD *)(v7 + 100)) & 0x80000000) != 0 )
  {
LABEL_131:
    kfree(v7);
    return 0;
  }
LABEL_60:
  _mutex_init();
  *(_QWORD *)(v7 + 2328) = v7 + 2328;
  *(_QWORD *)(v7 + 2336) = v7 + 2328;
  *(_QWORD *)(v7 + 144) = v7 + 144;
  *(_QWORD *)(v7 + 152) = v7 + 144;
  if ( v5 < 0xA0 )
    goto LABEL_135;
  if ( (v5 & 0xFFFFFFFFFFFFFFFCLL) == 0xA0 )
    goto LABEL_135;
  *(_DWORD *)(v7 + 160) = 0;
  if ( v5 < 0xB8 )
    goto LABEL_135;
  if ( (v5 & 0xFFFFFFFFFFFFFFFCLL) == 0xB8 )
    goto LABEL_135;
  *(_DWORD *)(v7 + 184) = 0;
  *(_QWORD *)(v7 + 192) = v7 + 192;
  *(_QWORD *)(v7 + 200) = v7 + 192;
  *(_QWORD *)(v7 + 248) = v7 + 248;
  *(_QWORD *)(v7 + 256) = v7 + 248;
  *(_QWORD *)(v7 + 272) = v7 + 272;
  *(_QWORD *)(v7 + 280) = v7 + 272;
  if ( v5 < 0x120 )
    goto LABEL_135;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x120 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 288) = &_cfg80211_scan_done;
  if ( v5 < 0x170 )
    goto LABEL_135;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x170 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 368) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v7 + 376) = v7 + 376;
  *(_QWORD *)(v7 + 384) = v7 + 376;
  if ( v5 < 0x188 )
    goto LABEL_135;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x188 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 392) = cfg80211_dfs_channels_update_work;
  init_timer_key(v7 + 400, &delayed_work_timer_fn, 0x200000, 0, 0);
  device_initialize(v7 + 1384);
  if ( v5 < 0x880 )
    goto LABEL_135;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x880 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 2176) = &ieee80211_class;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x5F8 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 1528) = v7;
  if ( (v5 & 0xFFFFFFFFFFFFFFFELL) == 0x674 )
    goto LABEL_135;
  v9 = *(_WORD *)(v7 + 1652);
  if ( (v9 & 8) == 0 )
  {
    if ( (v5 & 0xFFFFFFFFFFFFFFFELL) == 0x674 )
      goto LABEL_135;
    *(_WORD *)(v7 + 1652) = v9 | 2;
  }
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x298 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 664) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v7 + 672) = v7 + 672;
  *(_QWORD *)(v7 + 680) = v7 + 672;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x2B0 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 688) = cfg80211_destroy_iface_wk;
  *(_QWORD *)(v7 + 696) = v7 + 696;
  *(_QWORD *)(v7 + 704) = v7 + 696;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x2C8 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 712) = cfg80211_sched_scan_stop_wk;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x2D0 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 720) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v7 + 728) = v7 + 728;
  *(_QWORD *)(v7 + 736) = v7 + 728;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x2E8 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 744) = cfg80211_sched_scan_results_wk;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x310 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 784) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v7 + 792) = v7 + 792;
  *(_QWORD *)(v7 + 800) = v7 + 792;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x328 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 808) = cfg80211_propagate_radar_detect_wk;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x350 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 848) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v7 + 856) = v7 + 856;
  *(_QWORD *)(v7 + 864) = v7 + 856;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x368 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 872) = cfg80211_propagate_cac_done_wk;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x370 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 880) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v7 + 888) = v7 + 888;
  *(_QWORD *)(v7 + 896) = v7 + 888;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x388 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 904) = cfg80211_mgmt_registrations_update_wk;
  if ( (v5 & 0xFFFFFFFFFFFFFFFCLL) == 0x390 )
    goto LABEL_135;
  *(_DWORD *)(v7 + 912) = 0;
  atomic_store((unsigned __int64)&init_net, (unsigned __int64 *)(v7 + 2344));
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x28 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 40) = cfg80211_rfkill_set_block;
  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x5D8 )
    goto LABEL_135;
  v10 = *(_QWORD *)(v7 + 1496);
  if ( !v10 )
  {
    if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x568 )
    {
      v10 = *(_QWORD *)(v7 + 1384);
      goto LABEL_94;
    }
LABEL_135:
    __break(1u);
    goto LABEL_136;
  }
LABEL_94:
  v11 = rfkill_alloc(v10, v7 + 1384, 1, v7 + 24, v7);
  if ( v5 < 0x9A8 || (v5 & 0xFFFFFFFFFFFFFFF8LL) == 0x9A8 )
    goto LABEL_135;
  *(_QWORD *)(v7 + 2472) = v11;
  if ( v11 )
  {
    if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x398 )
    {
      *(_QWORD *)(v7 + 920) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v7 + 928) = v7 + 928;
      *(_QWORD *)(v7 + 936) = v7 + 928;
      if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x3B0 )
      {
        *(_QWORD *)(v7 + 944) = cfg80211_wiphy_work;
        *(_QWORD *)(v7 + 952) = v7 + 952;
        *(_QWORD *)(v7 + 960) = v7 + 952;
        if ( (v5 & 0xFFFFFFFFFFFFFFFCLL) != 0x3C8 )
        {
          *(_DWORD *)(v7 + 968) = 0;
          if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x30 )
          {
            *(_QWORD *)(v7 + 48) = 0xFFFFFFFE00000LL;
            *(_QWORD *)(v7 + 56) = v7 + 56;
            *(_QWORD *)(v7 + 64) = v7 + 56;
            if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x48 )
            {
              *(_QWORD *)(v7 + 72) = cfg80211_rfkill_block_work;
              if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x130 )
              {
                *(_QWORD *)(v7 + 304) = 0xFFFFFFFE00000LL;
                *(_QWORD *)(v7 + 312) = v7 + 312;
                *(_QWORD *)(v7 + 320) = v7 + 312;
                if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x148 )
                {
                  *(_QWORD *)(v7 + 328) = cfg80211_conn_work;
                  if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x150 )
                  {
                    *(_QWORD *)(v7 + 336) = 0xFFFFFFFE00000LL;
                    *(_QWORD *)(v7 + 344) = v7 + 344;
                    *(_QWORD *)(v7 + 352) = v7 + 344;
                    if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x168 )
                    {
                      *(_QWORD *)(v7 + 360) = cfg80211_event_work;
                      if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x268 )
                      {
                        *(_QWORD *)(v7 + 616) = 0xFFFFFFFE00000LL;
                        *(_QWORD *)(v7 + 624) = v7 + 624;
                        *(_QWORD *)(v7 + 632) = v7 + 624;
                        if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x280 )
                        {
                          *(_QWORD *)(v7 + 640) = cfg80211_background_cac_abort_wk;
                          if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x200 )
                          {
                            *(_QWORD *)(v7 + 512) = 0xFFFFFFFE00000LL;
                            *(_QWORD *)(v7 + 520) = v7 + 520;
                            *(_QWORD *)(v7 + 528) = v7 + 520;
                            if ( (v5 & 0xFFFFFFFFFFFFFFF8LL) != 0x218 )
                            {
                              *(_QWORD *)(v7 + 536) = cfg80211_background_cac_done_wk;
                              init_timer_key(v7 + 544, &delayed_work_timer_fn, 0x200000, 0, 0);
                              _init_waitqueue_head(v7 + 120, "&rdev->dev_wait", &wiphy_new_nm___key_20);
                              *(_BYTE *)(v7 + 1188) = 7;
                              *(_BYTE *)(v7 + 1189) = 4;
                              if ( (v5 & 0xFFFFFFFFFFFFFFFCLL) != 0x4A8 )
                              {
                                *(_DWORD *)(v7 + 1192) = -1;
                                if ( (v5 & 0xFFFFFFFFFFFFFFFCLL) != 0x4AC )
                                {
                                  *(_DWORD *)(v7 + 1196) = -1;
                                  *(_BYTE *)(v7 + 1200) = 0;
                                  *(_BYTE *)(v7 + 2386) = 1;
                                  if ( (v5 & 0xFFFFFFFFFFFFFFFCLL) != 0x470 )
                                  {
                                    *(_DWORD *)(v7 + 1136) = 1;
                                    if ( (v5 & 0xFFFFFFFFFFFFFFFCLL) != 0x474 )
                                    {
                                      *(_DWORD *)(v7 + 1140) = -1;
                                      return v7 + 992;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    goto LABEL_135;
  }
  put_device(v7 + 1384);
  return 0;
}
