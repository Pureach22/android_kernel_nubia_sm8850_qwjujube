__int64 __fastcall hdd_reg_notifier(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x13
  char v13; // w23
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  __int64 v23; // x20
  __int64 v24; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int16 v41; // [xsp+4h] [xbp-Ch] BYREF
  char v42; // [xsp+6h] [xbp-Ah]
  __int64 v43; // [xsp+8h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v13 = *(_BYTE *)(a1 + 8460);
    v42 = 0;
    v41 = 0;
    if ( (cds_get_driver_state(a3, a4, a5, a6, a7, a8, a9, a10) & 4) != 0
      || (cds_get_driver_state(v14, v15, v16, v17, v18, v19, v20, v21) & 8) != 0
      || (result = cds_get_driver_state(v14, v15, v16, v17, v18, v19, v20, v21), (result & 0x10) != 0) )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: unloading or ssr in progress, ignore",
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 "hdd_reg_notifier");
    }
    else if ( *(_BYTE *)(a1 + 2024) == 1 )
    {
      v23 = jiffies;
      if ( hdd_reg_notifier___last_ticks - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: system/cfg80211 is already suspend",
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   "hdd_reg_notifier");
        hdd_reg_notifier___last_ticks = v23;
      }
    }
    else if ( *(_DWORD *)(a1 + 3000) == 2 )
    {
      v24 = jiffies;
      if ( hdd_reg_notifier___last_ticks_22 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: Driver module is closed, dropping request",
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   "hdd_reg_notifier");
        hdd_reg_notifier___last_ticks_22 = v24;
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: country: %c%c, initiator %d, dfs_region: %d",
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 "hdd_reg_notifier",
                 *(unsigned __int8 *)(a2 + 28),
                 *(unsigned __int8 *)(a2 + 29),
                 *(unsigned int *)(a2 + 20),
                 *(unsigned int *)(a2 + 32));
      if ( *(_DWORD *)(a2 + 20) == 1 && *(_DWORD *)(a2 + 24) == 1 )
      {
        qdf_event_reset(a1 + 8464);
        qdf_mutex_acquire(a1 + 8504);
        *(_BYTE *)(a1 + 8460) = 1;
        qdf_mutex_release(a1 + 8504);
        qdf_mem_copy(&v41, (const void *)(a2 + 28), 3u);
        result = ucfg_reg_set_country(*(_QWORD *)(a1 + 1544), &v41, v25, v26, v27, v28, v29, v30, v31, v32);
        if ( (_DWORD)result )
        {
          if ( (v13 & 1) == 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to set country",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "hdd_reg_notifier");
            qdf_mutex_acquire(a1 + 8504);
            *(_BYTE *)(a1 + 8460) = 0;
            result = qdf_mutex_release(a1 + 8504);
          }
        }
      }
    }
    _ReadStatusReg(SP_EL0);
  }
  else
  {
    __break(0x800u);
    if ( v10 )
      JUMPOUT(0x4230B0);
    return hdd_ch_avoid_ind();
  }
  return result;
}
