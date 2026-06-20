__int64 __fastcall dsi_display_update_dsi_bitrate(__int64 a1, unsigned int a2)
{
  double v4; // d0
  int v5; // w8
  unsigned __int64 v6; // x22
  __int64 v7; // x21
  char v8; // w24
  unsigned __int64 v9; // x23
  unsigned __int64 v10; // x9
  char v11; // w8
  __int64 v12; // x25
  unsigned int *v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x10
  unsigned __int64 v16; // x10
  unsigned __int64 v17; // x27
  unsigned __int64 v18; // x26
  unsigned __int64 v19; // x20
  unsigned __int64 v20; // x28
  unsigned __int64 v21; // x5
  __int64 v22; // x9
  __int64 v23; // x3
  unsigned int v24; // w0
  unsigned int v25; // w0
  unsigned int v26; // w19

  v4 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s:bit rate:%d\n", "dsi_display_update_dsi_bitrate", a2);
  if ( !*(_QWORD *)(a1 + 264) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n", v4);
    return 4294967274LL;
  }
  if ( !a2 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid bit clock rate\n", v4);
    return 4294967274LL;
  }
  v5 = *(_DWORD *)(a1 + 160);
  v6 = a2;
  *(_QWORD *)(a1 + 1016) = a2;
  if ( !v5 )
    return 0;
  v7 = 0;
  v8 = 1;
  v9 = a2 / 7;
  while ( 1 )
  {
    v12 = *(_QWORD *)(a1 + 168 + 48 * v7);
    mutex_lock(v12 + 32);
    v13 = *(unsigned int **)(a1 + 264);
    v14 = ((v13[307] >> 1) & 1) + (v13[307] & 1) + ((v13[307] >> 2) & 1) + ((v13[307] >> 3) & 1);
    if ( !(_DWORD)v14 )
    {
      v26 = -22;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid lane count\n");
      goto LABEL_23;
    }
    v15 = v13[306];
    v16 = (unsigned int)v15 > 7 ? 24LL : qword_2915F8[v15];
    v17 = *(_QWORD *)(a1 + 1016) * v14;
    v18 = v17 / v16;
    if ( v13[319] )
    {
      v19 = v9;
      v20 = v9;
      v21 = v6;
      v22 = (16 * v18 * (unsigned __int128)0x2492492492492493uLL) >> 64;
      v18 = (v22 + ((16 * v18 - v22) >> 1)) >> 2;
    }
    else
    {
      v21 = v17 / v14;
      v20 = (v17 / v14) >> 3;
      v19 = v20 / v13[325];
    }
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: bit_clk_rate = %llu, bit_clk_rate_per_lane = %llu\n", v17, v21);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: byte_clk_rate = %llu, byte_intf_clk_rate = %llu\n", v20, v19);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: pclk_rate = %llu\n", v18);
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_update_dsi_bitrate", 4934, -1, v7, v17, v20, v18, 239);
    *(_DWORD *)(v12 + 2376) = v20;
    v23 = *(unsigned int *)(v12 + 8);
    *(_DWORD *)(v12 + 2380) = v19;
    *(_DWORD *)(v12 + 2384) = v18;
    v24 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64))dsi_clk_set_link_frequencies)(
            *(_QWORD *)(a1 + 1320),
            *(_QWORD *)(v12 + 2376),
            *(_QWORD *)(v12 + 2384),
            v23);
    if ( v24 )
      break;
    if ( *(_BYTE *)(a1 + 1032) == 1 )
    {
      *(_QWORD *)(v12 + 2392) = v18;
      v25 = ((__int64 (__fastcall *)(_QWORD, unsigned __int64, _QWORD))dsi_clk_set_esync_frequency)(
              *(_QWORD *)(a1 + 1320),
              v18,
              *(unsigned int *)(v12 + 8));
      if ( v25 )
      {
        v26 = v25;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to update esync frequency\n");
        goto LABEL_23;
      }
    }
    *(_QWORD *)(v12 + 2568) = v6;
    mutex_unlock(v12 + 32);
    v10 = v7 + 1;
    v7 = 1;
    v11 = v8 & (v10 < *(unsigned int *)(a1 + 160));
    v8 = 0;
    if ( (v11 & 1) == 0 )
      return 0;
  }
  v26 = v24;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to update link frequencies\n");
LABEL_23:
  mutex_unlock(v12 + 32);
  return v26;
}
