__int64 __fastcall wlan_cfg80211_scan(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // x22
  __int64 v4; // x19
  int v5; // w25
  __int64 v9; // x26
  __int64 v10; // x0
  __int64 v11; // x20
  int v12; // w23
  int scan_id; // w0
  int v14; // w8
  int v15; // w8
  int v16; // w4
  __int64 result; // x0
  __int64 v18; // x23
  unsigned __int64 v19; // x26
  size_t v20; // x2
  int v21; // w8
  int v22; // w26
  int v23; // w8
  int v24; // w8
  int v25; // w8
  int v26; // w8
  int v27; // w8
  char v28; // w8
  int v29; // w8
  int beaconing_mode_count; // w0
  int v31; // w25
  unsigned int v32; // w28
  unsigned __int8 v33; // w27
  unsigned int v34; // w26
  int v35; // w8
  unsigned int *v36; // x22
  char *v37; // x23
  int v38; // w26
  int v39; // w8
  __int64 v40; // x8
  __int64 v41; // x9
  unsigned int v42; // w19
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x1
  size_t v46; // x2
  __int64 v47; // x1
  size_t v48; // x2
  _WORD *v49; // x0
  _WORD *v50; // x24
  __int64 v51; // x8
  __int64 v52; // x24
  char v53; // w24
  __int64 v54; // x0
  __int64 v55; // x23
  __int64 v56; // x22
  unsigned int v57; // w20
  int v58; // w8
  __int64 v59; // x24
  char v60; // w21
  int v61; // [xsp+4h] [xbp-3Ch]
  __int64 v62; // [xsp+8h] [xbp-38h]
  __int64 v63; // [xsp+10h] [xbp-30h]
  char *v64; // [xsp+20h] [xbp-20h]
  char v65[12]; // [xsp+2Ch] [xbp-14h] BYREF
  __int64 v66; // [xsp+38h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(_QWORD *)(v3 + 80);
  if ( !v4 )
  {
    qdf_trace_msg(72, 2, "%s: Invalid psoc object", "wlan_cfg80211_scan");
    goto LABEL_19;
  }
  v5 = *(_DWORD *)(a1 + 16);
  qdf_trace_msg(
    72,
    8,
    "%s: %s(vdev%d): mode %d flags 0x%x",
    "wlan_cfg80211_scan",
    (const char *)(*(_QWORD *)(*(_QWORD *)(a2 + 64) + 32LL) + 296LL),
    *(unsigned __int8 *)(a1 + 104),
    v5,
    *(_DWORD *)(a2 + 36));
  if ( (wlan_is_scan_allowed(a1) & 1) == 0 )
  {
    result = 4294967280LL;
    goto LABEL_20;
  }
  v9 = *(_QWORD *)(v3 + 24);
  if ( !v9 )
  {
    qdf_trace_msg(72, 2, "%s: Invalid osif priv object", "wlan_cfg80211_scan");
    goto LABEL_19;
  }
  v10 = _qdf_mem_malloc(2288, "wlan_cfg80211_scan", 1973);
  if ( !v10 )
  {
LABEL_19:
    result = 4294967274LL;
    goto LABEL_20;
  }
  v11 = v10;
  wlan_scan_init_default_params(a1, v10);
  v12 = *(unsigned __int16 *)(*(_QWORD *)(v9 + 16) + 88LL);
  scan_id = wlan_scan_get_scan_id(v4);
  if ( !scan_id )
  {
    qdf_trace_msg(72, 2, "%s: Invalid scan id", "wlan_cfg80211_scan");
    _qdf_mem_free(v11);
    goto LABEL_19;
  }
  *(_QWORD *)v11 = a1;
  v14 = *(unsigned __int8 *)(a1 + 104);
  *(_DWORD *)(v11 + 8) = scan_id;
  *(_DWORD *)(v11 + 12) = v12;
  *(_DWORD *)(v11 + 16) = v14;
  v15 = *(_DWORD *)(a2 + 36);
  if ( (v15 & 0x400) != 0 )
  {
    *(_BYTE *)(v11 + 96) |= 1u;
    v15 = *(_DWORD *)(a2 + 36);
    if ( (v15 & 0x100) == 0 )
    {
LABEL_8:
      if ( (v15 & 0x200) == 0 )
        goto LABEL_10;
      goto LABEL_9;
    }
  }
  else if ( (v15 & 0x100) == 0 )
  {
    goto LABEL_8;
  }
  *(_BYTE *)(v11 + 96) |= 2u;
  v15 = *(_DWORD *)(a2 + 36);
  if ( (v15 & 0x200) != 0 )
  {
LABEL_9:
    *(_BYTE *)(v11 + 96) |= 4u;
    v15 = *(_DWORD *)(a2 + 36);
  }
LABEL_10:
  v62 = v3;
  v63 = v9;
  v64 = a3;
  if ( (v15 & 0x4000) != 0 )
    *(_BYTE *)(v11 + 96) |= 8u;
  if ( *(_QWORD *)a2 )
  {
    v16 = *(_DWORD *)(a2 + 8);
    if ( v16 == 1 )
    {
      if ( !**(_BYTE **)a2 )
      {
        *(_DWORD *)(a2 + 8) = 0;
        goto LABEL_36;
      }
      *(_DWORD *)(v11 + 112) = 1;
    }
    else
    {
      if ( v16 < 1 )
        goto LABEL_36;
      *(_DWORD *)(v11 + 112) = v16;
      if ( (unsigned int)v16 >= 0x11 )
      {
        qdf_trace_msg(72, 4, "%s: number of ssid %d greater than MAX %d", "wlan_cfg80211_scan", v16, 16);
        *(_DWORD *)(v11 + 112) = 16;
      }
    }
    v18 = 0;
    v19 = 0;
    do
    {
      if ( v19 == 17 )
LABEL_155:
        __break(0x5512u);
      if ( *(unsigned __int8 *)(*(_QWORD *)a2 + v18 + 32) >= 0x20u )
        v20 = 32;
      else
        v20 = *(unsigned __int8 *)(*(_QWORD *)a2 + v18 + 32);
      *(_BYTE *)(v11 + v18 + 1348) = v20;
      qdf_mem_copy(v11 + v18 + 1349, *(_DWORD *)a2 + v18, v20);
      ++v19;
      v18 += 33;
    }
    while ( v19 < *(unsigned int *)(v11 + 112) );
  }
LABEL_36:
  if ( (v5 & 0xFFFFFFFB) == 3 || *(_QWORD *)a2 )
    *(_DWORD *)(v11 + 92) &= ~1u;
  if ( (a3[44] & 1) != 0 )
  {
    v21 = 0x2000;
  }
  else
  {
    if ( a3[45] != 1 )
      goto LABEL_44;
    v21 = 0x4000;
  }
  *(_DWORD *)(v11 + 92) |= v21;
LABEL_44:
  if ( a3[46] == 1 )
    *(_DWORD *)(v11 + 92) |= 0x1000u;
  if ( *(_DWORD *)(a2 + 8) == 1 && *(_QWORD *)a2 && !(unsigned int)qdf_mem_cmp(*(_QWORD *)a2) )
  {
    v22 = 1;
    if ( *(_BYTE *)(a2 + 129) == 1 )
      *(_DWORD *)(v11 + 28) = 1;
  }
  else
  {
    v22 = 0;
  }
  v23 = *((_DWORD *)a3 + 12);
  if ( v23 )
    *(_DWORD *)(v11 + 36) = v23;
  v24 = *((_DWORD *)a3 + 13);
  if ( v24 )
    *(_DWORD *)(v11 + 40) = v24;
  v25 = *((_DWORD *)a3 + 14);
  if ( v25 )
    *(_DWORD *)(v11 + 44) = v25;
  v26 = *((_DWORD *)a3 + 15);
  if ( v26 )
    *(_DWORD *)(v11 + 52) = v26;
  v27 = *((_DWORD *)a3 + 16);
  if ( v27 )
    *(_DWORD *)(v11 + 56) = v27;
  if ( (wlan_scan_cfg_honour_nl_scan_policy_flags(v4) & 1) != 0 )
  {
    v28 = *(_BYTE *)(v11 + 96);
    if ( (v28 & 1) != 0 )
      *(_DWORD *)(v11 + 100) = 4;
    if ( (v28 & 4) != 0 )
      *(_DWORD *)(v11 + 100) = 3;
  }
  *(_DWORD *)(v11 + 108) = 1;
  qdf_mem_copy(v11 + 1876, a2 + 84, 6u);
  if ( !(*(_DWORD *)(v11 + 1876) | *(unsigned __int16 *)(v11 + 1880)) )
  {
    *(_WORD *)(v11 + 1880) = -1;
    *(_DWORD *)(v11 + 1876) = -1;
  }
  if ( a3[69] == 1 )
  {
    if ( (a3[70] & 1) != 0 )
      goto LABEL_73;
    v29 = 0x400000;
  }
  else
  {
    if ( !a3[70] )
      goto LABEL_73;
    v29 = 0x800000;
  }
  *(_DWORD *)(v11 + 92) = *(_DWORD *)(v11 + 92) & 0xFF3FFFFF | v29;
LABEL_73:
  if ( !*(_DWORD *)(a2 + 12)
    || (beaconing_mode_count = policy_mgr_get_beaconing_mode_count(v4, 0), !*(_DWORD *)(a2 + 12)) )
  {
LABEL_98:
    qdf_trace_msg(72, 2, "%s: Received zero non-dsrc channels", "wlan_cfg80211_scan");
LABEL_99:
    v42 = -22;
    goto LABEL_100;
  }
  v31 = beaconing_mode_count;
  v32 = 0;
  v33 = 0;
  v61 = v22;
  do
  {
    v34 = *(_DWORD *)(*(_QWORD *)(a2 + 160 + 8LL * v33) + 4LL);
    if ( (wlan_reg_is_dsrc_freq(v34) & 1) != 0 )
      goto LABEL_77;
    if ( v31 )
    {
      v65[0] = 0;
      if ( (unsigned int)policy_mgr_is_chan_ok_for_dnbs(v4, v34, v65) )
      {
        qdf_trace_msg(72, 2, "%s: DNBS check failed", "wlan_cfg80211_scan");
        goto LABEL_99;
      }
      if ( v65[0] != 1 )
        goto LABEL_77;
    }
    v35 = *(_DWORD *)(v11 + 92);
    if ( (v35 & 0x400000) == 0 )
      goto LABEL_85;
    if ( (wlan_reg_is_24ghz_ch_freq(v34) & 1) == 0 )
    {
      v35 = *(_DWORD *)(v11 + 92);
LABEL_85:
      if ( (v35 & 0x800000) == 0
        || (wlan_reg_is_5ghz_ch_freq(v34) & 1) == 0 && (wlan_reg_is_6ghz_chan_freq(v34) & 1) == 0 )
      {
        goto LABEL_77;
      }
    }
    if ( v32 > 0x65 )
      goto LABEL_155;
    v36 = (unsigned int *)(v11 + 124 + 12LL * v32);
    *v36 = v34;
    v36[1] = util_scan_scm_freq_to_band(v34) == 1;
    if ( v32 == 101 )
    {
      v37 = v64;
      v38 = v61;
      LOBYTE(v32) = 102;
      goto LABEL_92;
    }
    ++v32;
LABEL_77:
    ++v33;
  }
  while ( *(_DWORD *)(a2 + 12) > (unsigned int)v33 );
  v37 = v64;
  v38 = v61;
  if ( !v32 )
    goto LABEL_98;
LABEL_92:
  *(_BYTE *)(v11 + 120) = v32;
  if ( v38 )
    *(_DWORD *)(v11 + 24) = 3;
  v39 = *((_DWORD *)v37 + 10);
  if ( v39 != 5 )
    *(_DWORD *)(v11 + 24) = v39;
  v40 = *(_QWORD *)(a2 + 24);
  if ( v40 )
  {
    LODWORD(v41) = *(_QWORD *)(a2 + 24);
  }
  else
  {
    v41 = *((_QWORD *)v37 + 2);
    if ( v41 )
      LODWORD(v41) = *((_DWORD *)v37 + 2);
  }
  if ( *((_QWORD *)v37 + 4) )
    LODWORD(v41) = *((_DWORD *)v37 + 6) + v41;
  if ( !(_DWORD)v41 )
  {
LABEL_111:
    if ( v40 )
    {
      *(_DWORD *)(v11 + 2024) = v40;
      v44 = *(_QWORD *)(v11 + 2032);
      v45 = *(_QWORD *)(a2 + 16);
      v46 = *(unsigned int *)(a2 + 24);
    }
    else
    {
      if ( !*((_QWORD *)v37 + 2) || (v58 = *((_DWORD *)v37 + 2)) == 0 )
      {
LABEL_114:
        v47 = *((_QWORD *)v37 + 4);
        if ( v47 )
        {
          v48 = *((unsigned int *)v37 + 6);
          if ( (_DWORD)v48 )
          {
            qdf_mem_copy(*(_QWORD *)(v11 + 2032) + *(_DWORD *)(v11 + 2024), v47, v48);
            *(_DWORD *)(v11 + 2024) += *((_DWORD *)v37 + 6);
          }
        }
        if ( (v38 & 1) == 0 )
        {
          if ( *(_BYTE *)(v11 + 1900) == 1 )
            wlan_scan_rand_attrs(a1, a2, v11);
          if ( (ucfg_ie_allowlist_enabled(v4, a1) & 1) != 0 && (ucfg_copy_ie_allowlist_attrs(v4, v11 + 1916) & 1) != 0 )
            *(_DWORD *)(v11 + 92) |= 0x100000u;
        }
        v49 = (_WORD *)_qdf_mem_malloc(720, "wlan_cfg80211_scan", 2198);
        v50 = v49;
        if ( v49 )
          *v49 |= 0x100u;
        if ( (*(_BYTE *)(a2 + 36) & 2) != 0 )
          ucfg_scan_flush_results(v62, v49);
        if ( v50 )
          _qdf_mem_free(v50);
        if ( v37[68] == 1 )
          *(_DWORD *)(v11 + 2072) |= 0x1000u;
        if ( v38 && *((_DWORD *)v37 + 18) == 7 )
          wlan_handle_sta_vdev_for_p2p_device(v4, v11);
        qdf_trace_msg(72, 8, "%s: scan_ctrl_flags_ext %0x", "wlan_cfg80211_scan", *(_DWORD *)(v11 + 2072));
        *(_BYTE *)(v11 + 2284) = v37[71];
        v51 = *(_QWORD *)(v63 + 16);
        v52 = v51 + 104;
        if ( v51 != -104 && (ucfg_scan_wake_lock_in_user_scan(v4) & 1) != 0 )
          qdf_wake_lock_timeout_acquire(v52, 5000);
        qdf_runtime_pm_prevent_suspend(*(_QWORD *)(v63 + 16) + 96LL);
        v53 = *v37;
        v54 = _qdf_mem_malloc(48, "wlan_schedule_scan_start_request", 682);
        if ( v54 )
        {
          v55 = v54;
          v56 = *(_QWORD *)(*(_QWORD *)(v62 + 24) + 16LL);
          *(_QWORD *)(v54 + 16) = a2;
          *(_BYTE *)(v54 + 28) = v53;
          *(_DWORD *)(v54 + 24) = *(_DWORD *)(v11 + 8);
          *(_QWORD *)(v54 + 32) = *(_QWORD *)(*(_QWORD *)(a2 + 64) + 32LL);
          *(_QWORD *)(v54 + 40) = qdf_get_time_of_the_day_ms();
          qdf_mutex_acquire(v56 + 24);
          if ( *(_DWORD *)(v56 + 16) > 7u )
          {
            ucfg_scm_scan_free_scan_request_mem(v11);
            v57 = 1;
          }
          else
          {
            v57 = wlan_scan_start(v11);
            if ( !v57 )
            {
              qdf_list_insert_back(v56, v55);
              qdf_mutex_release(v56 + 24);
LABEL_154:
              result = qdf_status_to_os_return(v57);
              goto LABEL_20;
            }
            qdf_trace_msg(72, 2, "%s: scan req failed with error %d", "wlan_schedule_scan_start_request", v57);
            if ( v57 == 1 )
              qdf_trace_msg(
                72,
                2,
                "%s: HO is in progress.So defer the scan by informing busy",
                "wlan_schedule_scan_start_request");
          }
          qdf_mutex_release(v56 + 24);
          v59 = jiffies;
          if ( wlan_schedule_scan_start_request___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              72,
              8,
              "%s: Failed to enqueue Scan Req as max scan %d already queued",
              "wlan_schedule_scan_start_request",
              *(_DWORD *)(v56 + 16));
            wlan_schedule_scan_start_request___last_ticks = v59;
          }
          _qdf_mem_free(v55);
        }
        else
        {
          ucfg_scm_scan_free_scan_request_mem(v11);
          v57 = 2;
        }
        qdf_mutex_acquire(*(_QWORD *)(v63 + 16) + 24LL);
        v60 = qdf_list_empty(*(_QWORD *)(v63 + 16));
        qdf_mutex_release(*(_QWORD *)(v63 + 16) + 24LL);
        if ( (v60 & 1) != 0 )
        {
          qdf_runtime_pm_allow_suspend(*(_QWORD *)(v63 + 16) + 96LL);
          wlan_scan_release_wake_lock(v4, *(_QWORD *)(v63 + 16) + 104LL);
        }
        goto LABEL_154;
      }
      *(_DWORD *)(v11 + 2024) = v58;
      v44 = *(_QWORD *)(v11 + 2032);
      v45 = *((_QWORD *)v37 + 2);
      v46 = *((unsigned int *)v37 + 2);
    }
    qdf_mem_copy(v44, v45, v46);
    goto LABEL_114;
  }
  v43 = _qdf_mem_malloc((unsigned int)v41, "wlan_cfg80211_scan", 2164);
  *(_QWORD *)(v11 + 2032) = v43;
  if ( v43 )
  {
    v40 = *(_QWORD *)(a2 + 24);
    goto LABEL_111;
  }
  v42 = -12;
LABEL_100:
  _qdf_mem_free(v11);
  result = v42;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
