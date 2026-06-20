__int64 __fastcall dsi_ctrl_update_host_config(__int64 a1, int *a2, __int64 a3, char a4, __int64 a5)
{
  const char *v7; // x3
  int v12; // w4
  int *v13; // x8
  int *v14; // x20
  __int16 v15; // w8
  __int16 v16; // w9
  unsigned int v17; // w20
  int v18; // w10
  __int64 v19; // x9
  unsigned int v20; // w9
  __int64 v21; // x12
  unsigned int v22; // w10
  unsigned int v23; // w11
  __int64 v24; // x15
  unsigned __int64 v25; // x13
  unsigned __int64 v26; // x14
  unsigned __int64 v27; // x11
  int v28; // w12
  unsigned __int64 v29; // x22
  __int64 v30; // x12
  unsigned __int64 v31; // x21
  __int64 v32; // x0
  __int64 v33; // x11
  __int64 v34; // x12
  __int64 v35; // x12
  __int64 v36; // x12
  unsigned __int64 v37; // x23
  unsigned __int64 v38; // x6
  unsigned __int64 v39; // x24
  __int64 v40; // x9
  __int64 v41; // x3
  __int64 v42; // x1
  unsigned int v43; // w0
  __int64 v44; // x2
  unsigned int v45; // w0

  if ( a1 && a2 )
  {
    if ( *(_DWORD *)(a1 + 1608) == 1 )
      return 0;
    mutex_lock(a1 + 32);
    v12 = *a2;
    if ( (unsigned int)*a2 >= 4 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: Invalid dsi operation mode (%d)\n",
        *(const char **)(a1 + 16),
        v12);
LABEL_15:
      v17 = -22;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: panel validation failed, rc=%d\n",
        *(_QWORD *)(a1 + 16),
        4294967274LL);
      goto LABEL_16;
    }
    v13 = a2;
    if ( (a2[2] & 0xF) == 0 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: No data lanes are enabled\n",
        *(const char **)(a1 + 16));
      goto LABEL_15;
    }
    if ( (a4 & 0x31) != 0 )
    {
LABEL_13:
      v14 = v13;
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: Host config updated\n", *(const char **)(a1 + 16));
      memcpy((void *)(a1 + 2440), v14, 0x138u);
      v15 = *(_DWORD *)(a1 + 2592);
      v16 = *(_DWORD *)(a1 + 12);
      v17 = 0;
      v18 = *(_DWORD *)(a1 + 2616);
      *(_WORD *)(a1 + 2754) = 0;
      *(_WORD *)(a1 + 2756) = v15;
      *(_WORD *)(a1 + 2758) = v18;
      *(_BYTE *)(a1 + 2894) = 1;
      *(_WORD *)(a1 + 2752) = v16 * v15;
      *(_QWORD *)(a1 + 2760) = *(_QWORD *)(a1 + 2752);
      *(_WORD *)(a1 + 2760) = 0;
LABEL_16:
      mutex_unlock(a1 + 32);
      return v17;
    }
    v19 = (unsigned int)a2[1];
    if ( (unsigned int)v19 > 7 )
      v20 = 24;
    else
      v20 = bits_per_pixel[v19];
    v21 = *(_QWORD *)(a3 + 184);
    if ( *((_BYTE *)a2 + 60) == 1 )
      v22 = a2[17];
    else
      v22 = (((unsigned int)a2[2] >> 1) & 1)
          + (a2[2] & 1)
          + (((unsigned int)a2[2] >> 2) & 1)
          + (((unsigned int)a2[2] >> 3) & 1);
    v23 = a2[49];
    v24 = *((_QWORD *)a2 + 17);
    v25 = *(unsigned int *)(v21 + 2396);
    v26 = *(_QWORD *)(v21 + 2416);
    *((_BYTE *)a2 + 12) = v22;
    *((_BYTE *)a2 + 13) = v20;
    if ( v24 )
    {
      v27 = v22;
      v28 = a2[14];
      v29 = v24 * v22;
      if ( v28 == 1 )
      {
        v30 = (16 * v29 * (unsigned __int128)0x2492492492492493uLL) >> 64;
        v29 = (v30 + ((16 * v29 - v30) >> 1)) >> 2;
        v31 = v29 / v20;
        goto LABEL_40;
      }
    }
    else if ( v12 == 2 )
    {
      v28 = a2[14];
      v33 = 1000 * (0x3E8 % v23) / v23 + 1000 * (0x3E8 / v23);
      if ( v28 == 1 )
      {
        v32 = (16 * v26 * (unsigned __int128)0x2492492492492493uLL) >> 64;
        v26 = (v32 + ((16 * v26 - v32) >> 1)) >> 2;
      }
      v29 = v26 * v33 / v25 * v22;
    }
    else
    {
      if ( *((_BYTE *)a2 + 224) == 1 && (v34 = *((_QWORD *)a2 + 29)) != 0 )
      {
        v35 = *(int *)(v34 + 160);
      }
      else if ( *((_BYTE *)a2 + 225) == 1 && (v36 = *((_QWORD *)a2 + 30)) != 0 )
      {
        v35 = *(int *)(v36 + 500);
      }
      else
      {
        v35 = (unsigned int)a2[38];
      }
      v29 = v23
          * (unsigned __int64)v20
          * (v35 + (unsigned int)(a2[41] + a2[39] + a2[40]))
          * (unsigned int)(a2[45] + a2[44] + a2[46] + a2[47]);
      v28 = a2[14];
    }
    v27 = v22;
    v31 = v29 / v20;
    if ( !v28 )
    {
      v38 = v29 / v22;
      v39 = (((v38 + 4) >> 3) + 1) & 0x3FFFFFFFFFFFFFFELL;
      v37 = v39 / (unsigned int)a2[20];
      v40 = 8 * v39;
LABEL_42:
      *((_QWORD *)a2 + 16) = v40;
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dsi-debug]: %s: bit_clk_rate = %llu, bit_clk_rate_per_lane = %llu\n",
        *(const char **)(a1 + 16),
        v29,
        v38);
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dsi-debug]: %s: byte_clk_rate = %llu, byte_intf_clk = %llu\n",
        *(const char **)(a1 + 16),
        v39,
        v37);
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: pclk_rate = %llu\n", *(const char **)(a1 + 16), v31);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dsi_ctrl_update_link_freqs",
        1143,
        -1,
        *(_DWORD *)(a1 + 8),
        v29,
        v39,
        v31,
        239);
      *(_DWORD *)(a1 + 2376) = v39;
      v41 = *(unsigned int *)(a1 + 8);
      *(_DWORD *)(a1 + 2380) = v37;
      *(_DWORD *)(a1 + 2384) = v31;
      v42 = *(_QWORD *)(a1 + 2376);
      *(_DWORD *)(a1 + 2388) = *((_QWORD *)a2 + 15);
      v43 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))dsi_clk_set_link_frequencies)(
              a5,
              v42,
              *(_QWORD *)(a1 + 2384),
              v41);
      if ( v43 )
      {
        v17 = v43;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: Failed to update link frequencies\n",
          *(_QWORD *)(a1 + 16));
      }
      else
      {
        v13 = a2;
        if ( *((_BYTE *)a2 + 144) != 1 )
          goto LABEL_13;
        v44 = *(unsigned int *)(a1 + 8);
        *(_QWORD *)(a1 + 2392) = v31;
        v45 = ((__int64 (__fastcall *)(__int64, unsigned __int64, __int64))dsi_clk_set_esync_frequency)(a5, v31, v44);
        v13 = a2;
        if ( !v45 )
          goto LABEL_13;
        v17 = v45;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: Failed to update esync frequency\n",
          *(_QWORD *)(a1 + 16));
      }
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: failed to update link frequency, rc=%d\n",
        *(_QWORD *)(a1 + 16),
        v17);
      goto LABEL_16;
    }
LABEL_40:
    v37 = (v29 >> 4) / v27;
    v29 = 7 * (v29 >> 4);
    v38 = v29 / v27;
    v39 = v37;
    v40 = 7 * v37;
    goto LABEL_42;
  }
  if ( a1 )
    v7 = *(const char **)(a1 + 16);
  else
    v7 = "inv";
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", v7);
  return 4294967274LL;
}
