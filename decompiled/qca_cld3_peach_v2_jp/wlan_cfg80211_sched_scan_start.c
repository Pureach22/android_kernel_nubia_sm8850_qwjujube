__int64 __fastcall wlan_cfg80211_sched_scan_start(__int64 a1, __int64 a2, char a3)
{
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x8
  __int64 v12; // x25
  int v13; // w4
  int v14; // w8
  unsigned int v15; // w20
  char is_dfs_chnl_scan_enabled; // w0
  char v17; // w27
  __int64 v18; // x0
  const char *v19; // x26
  int v20; // w20
  int v21; // w23
  unsigned int v22; // w28
  int v23; // w0
  unsigned __int64 v24; // x26
  _DWORD *v25; // x23
  __int64 v26; // x25
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  __int64 v29; // x9
  unsigned __int64 v30; // x8
  __int64 v31; // x27
  unsigned __int8 *v32; // x20
  unsigned int v33; // w4
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  int *v36; // x10
  _DWORD *v37; // x9
  int v38; // w11
  int v39; // w12
  _DWORD *v40; // x9
  int v41; // w10
  unsigned int v42; // w0
  __int64 v43; // x20
  unsigned __int64 v44; // x8
  unsigned __int64 v45; // x25
  _DWORD *v46; // x26
  int v47; // w8
  int v48; // w8
  __int64 v49; // x20
  char v50; // w8
  __int64 v51; // x22
  __int64 v52; // x24
  unsigned __int64 v53; // x21
  __int64 v54; // x20
  _BYTE *v55; // [xsp+20h] [xbp-1F0h]
  char v56; // [xsp+2Ch] [xbp-1E4h]
  __int64 v57; // [xsp+38h] [xbp-1D8h]
  unsigned __int64 v58; // [xsp+38h] [xbp-1D8h]
  __int64 v59; // [xsp+40h] [xbp-1D0h]
  int beaconing_mode_count; // [xsp+48h] [xbp-1C8h]
  __int64 v61; // [xsp+50h] [xbp-1C0h]
  unsigned int v62; // [xsp+5Ch] [xbp-1B4h]
  char v63[4]; // [xsp+60h] [xbp-1B0h] BYREF
  char v64[4]; // [xsp+64h] [xbp-1ACh] BYREF
  _DWORD s[102]; // [xsp+68h] [xbp-1A8h] BYREF
  __int64 v66; // [xsp+200h] [xbp-10h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v64[0] = 0;
  memset(s, 0, sizeof(s));
  if ( (ucfg_scan_get_pno_in_progress(a1) & 1) == 0 )
  {
    if ( (unsigned int)ucfg_scan_get_pdev_status(v6)
      && (unsigned int)wlan_abort_scan(v6, *(unsigned __int8 *)(v6 + 40), 0xFFFFFFFFLL, 4294967294LL, 1) )
    {
      result = 4294967280LL;
      goto LABEL_20;
    }
    v8 = _qdf_mem_malloc(20696, "wlan_cfg80211_sched_scan_start", 409);
    if ( !v8 )
    {
      result = 4294967284LL;
      goto LABEL_20;
    }
    v9 = v8;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v6 + 1240);
      v11 = *(_QWORD *)(v6 + 1248);
    }
    else
    {
      raw_spin_lock_bh(v6 + 1240);
      v11 = *(_QWORD *)(v6 + 1248) | 1LL;
      *(_QWORD *)(v6 + 1248) = v11;
    }
    v12 = *(_QWORD *)(v6 + 80);
    if ( (v11 & 1) != 0 )
    {
      *(_QWORD *)(v6 + 1248) = v11 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v6 + 1240);
    }
    else
    {
      raw_spin_unlock(v6 + 1240);
    }
    v13 = *(_DWORD *)(a2 + 56);
    *(_DWORD *)(v9 + 8) = v13;
    v14 = *(unsigned __int8 *)(a1 + 104);
    *(_QWORD *)v9 = a1;
    *(_DWORD *)(v9 + 16) = v14;
    *(_BYTE *)(v9 + 20688) = (*(_DWORD *)(a2 + 40) & 0x4000) != 0;
    if ( (unsigned int)(v13 - 17) <= 0xFFFFFFEF )
    {
      qdf_trace_msg(72, 2, "%s: Network input is not correct %d", "wlan_cfg80211_sched_scan_start");
      goto LABEL_18;
    }
    if ( *(_DWORD *)(a2 + 20) >= 0x67u )
    {
      qdf_trace_msg(72, 2, "%s: Incorrect number of channels %d", "wlan_cfg80211_sched_scan_start");
      goto LABEL_18;
    }
    is_dfs_chnl_scan_enabled = ucfg_scan_is_dfs_chnl_scan_enabled(v12);
    if ( *(_DWORD *)(a2 + 20) )
    {
      v17 = is_dfs_chnl_scan_enabled;
      beaconing_mode_count = policy_mgr_get_beaconing_mode_count(v12, 0);
      v57 = (unsigned int)(5 * *(_DWORD *)(a2 + 20) + 1);
      v18 = _qdf_mem_malloc(v57, "wlan_cfg80211_sched_scan_start", 449);
      if ( !v18 )
      {
        v15 = -12;
        goto LABEL_19;
      }
      v19 = (const char *)v18;
      v61 = v12;
      v55 = (_BYTE *)(v9 + 20480);
      v56 = a3;
      v59 = a1;
      if ( *(_DWORD *)(a2 + 20) )
      {
        v20 = 0;
        v21 = 0;
        v62 = 0;
        while ( 1 )
        {
          v22 = *(unsigned __int16 *)(*(_QWORD *)(a2 + 192 + 8LL * v21) + 4LL);
          if ( (v17 & 1) == 0
            && (wlan_reg_is_dfs_for_freq(v6, *(unsigned __int16 *)(*(_QWORD *)(a2 + 192 + 8LL * v21) + 4LL)) & 1) != 0 )
          {
            qdf_trace_msg(72, 8, "%s: Dropping DFS channel freq :%d", "wlan_cfg80211_sched_scan_start", v22);
          }
          else if ( (wlan_reg_is_dsrc_freq(v22) & 1) == 0 )
          {
            if ( !beaconing_mode_count )
              goto LABEL_33;
            v63[0] = 0;
            if ( (unsigned int)policy_mgr_is_chan_ok_for_dnbs(v12, v22, v63) )
            {
              qdf_trace_msg(72, 2, "%s: DNBS check failed", "wlan_cfg80211_sched_scan_start");
              _qdf_mem_free(v19);
              goto LABEL_18;
            }
            if ( v63[0] == 1 )
            {
LABEL_33:
              v23 = scnprintf(&v19[v20], (unsigned int)(v57 - v20), " %d", v22);
              if ( v62 >= 0x66 )
                goto LABEL_93;
              v20 += v23;
              s[v62++] = v22;
            }
          }
          if ( (unsigned int)++v21 >= *(_DWORD *)(a2 + 20) )
            goto LABEL_38;
        }
      }
      v62 = 0;
LABEL_38:
      qdf_trace_msg(72, 8, "%s: Channel-List[%d]:%s", "wlan_cfg80211_sched_scan_start", v62, v19);
      _qdf_mem_free(v19);
      if ( !v62 )
      {
        qdf_trace_msg(72, 4, "%s: Channel list empty due to filtering of DSRC", "wlan_cfg80211_sched_scan_start");
LABEL_18:
        v15 = -22;
LABEL_19:
        _qdf_mem_free(v9);
        result = v15;
        goto LABEL_20;
      }
    }
    else
    {
      v61 = v12;
      v55 = (_BYTE *)(v9 + 20480);
      v56 = a3;
      v59 = a1;
      v62 = 0;
    }
    if ( *(_DWORD *)(v9 + 8) )
    {
      v24 = 0;
      v25 = (_DWORD *)(v9 + 132);
      v26 = v9 + 120;
      v27 = v62 - 1LL;
      if ( v27 >= 0x66 )
        v27 = 102;
      v28 = v27 + 1;
      v29 = 2;
      if ( (v28 & 1) != 0 )
        v29 = v28 & 1;
      v58 = v28 - v29;
      while ( 1 )
      {
        if ( v24 == 17 )
          goto LABEL_93;
        v31 = *(_QWORD *)(a2 + 48) + 44 * v24;
        v32 = (unsigned __int8 *)(v9 + 68 + 1280 * v24);
        v33 = *(unsigned __int8 *)(v31 + 32);
        *v32 = v33;
        if ( v33 - 33 < 0xFFFFFFE0 )
          break;
        qdf_mem_copy((_DWORD)v32 + 1, v31, v33);
        *(_QWORD *)(v32 + 36) = 0;
        *((_DWORD *)v32 + 11) = 0;
        if ( v62 )
        {
          if ( v62 >= 3 )
          {
            v36 = &s[1];
            v35 = v58;
            v37 = v25;
            do
            {
              v38 = *(v36 - 1);
              v39 = *v36;
              v35 -= 2LL;
              v36 += 2;
              *(v37 - 3) = v38;
              *v37 = v39;
              v37 += 6;
            }
            while ( v35 );
            v34 = v58;
          }
          else
          {
            v34 = 0;
          }
          v40 = (_DWORD *)(v26 + 12 * v34);
          while ( v34 != 102 )
          {
            if ( (v34 & 0x3FFFFFFFFFFFFFFFLL) == 0x66 )
              goto LABEL_94;
            v41 = s[v34++];
            *v40 = v41;
            v40 += 3;
            if ( v62 == v34 )
              goto LABEL_58;
          }
LABEL_93:
          __break(0x5512u);
LABEL_94:
          __break(1u);
        }
LABEL_58:
        v32[48] = v62;
        if ( (ucfg_is_6ghz_pno_scan_optimization_supported(v61) & 1) != 0 )
        {
          v42 = wlan_construct_shortssid(v32 + 1, *v32);
          v64[0] = v62;
          ucfg_scan_add_flags_to_pno_chan_list(v59, v9, v64, v42, (unsigned int)v24);
        }
        v30 = *(unsigned int *)(v9 + 8);
        ++v24;
        v25 += 320;
        v26 += 1280;
        *((_DWORD *)v32 + 319) = *(_DWORD *)(v31 + 40);
        if ( v24 >= v30 )
          goto LABEL_60;
      }
      qdf_trace_msg(72, 2, "%s:  SSID Len %d is not correct for network %d", "wlan_cfg80211_sched_scan_start", v33, v24);
      goto LABEL_18;
    }
LABEL_60:
    *(_BYTE *)(v9 + 12) = *(_DWORD *)(a2 + 16) == 0;
    if ( *(int *)(a2 + 16) >= 1 )
    {
      v43 = 0;
      do
      {
        v44 = *(unsigned int *)(v9 + 8);
        if ( (_DWORD)v44 )
        {
          v45 = 0;
          v46 = (_DWORD *)(v9 + 112);
          do
          {
            if ( v45 == 16 )
              goto LABEL_93;
            if ( *((unsigned __int8 *)v46 - 44) == *(unsigned __int8 *)(*(_QWORD *)(a2 + 8) + 33 * v43 + 32) )
            {
              if ( !(unsigned int)qdf_mem_cmp((char *)v46 - 43) )
              {
                *v46 = 2;
                break;
              }
              v44 = *(unsigned int *)(v9 + 8);
            }
            ++v45;
            v46 += 320;
          }
          while ( v45 < v44 );
        }
        ++v43;
      }
      while ( v43 < *(int *)(a2 + 16) );
    }
    wlan_config_sched_scan_plan(v61, v9, a2);
    v47 = *(_DWORD *)(a2 + 64);
    *(_BYTE *)(v9 + 36) = v56;
    *(_DWORD *)(v9 + 28) = v47;
    v55[188] = *(_BYTE *)(a2 + 96);
    v55[189] = *(_BYTE *)(a2 + 97);
    v48 = *(_DWORD *)(a2 + 100);
    if ( v48 )
    {
      v49 = v59;
      if ( v48 != 1 )
      {
LABEL_77:
        v55[191] = *(_BYTE *)(a2 + 104);
        v51 = *(_QWORD *)(v6 + 80);
        ucfg_scan_register_pno_cb(v51, wlan_cfg80211_pno_callback, 0);
        ucfg_scan_get_pno_def_params(v49, v9);
        if ( v55[68] == 1 )
          wlan_fill_scan_rand_attrs(v49, *(unsigned int *)(a2 + 40), a2 + 84, a2 + 90, v55 + 68, v9 + 20549, v9 + 20555);
        v52 = v49;
        if ( (ucfg_ie_allowlist_enabled(v51, v49) & 1) != 0 )
          ucfg_copy_ie_allowlist_attrs(v51, v9 + 20564);
        qdf_trace_msg(
          72,
          8,
          "%s: Network count %d n_ssids %d fast_scan_period: %d msec slow_scan_period: %d msec, fast_scan_max_cycles: %d,"
          " relative_rssi %d band_pref %d, rssi_pref %d",
          "wlan_cfg80211_sched_scan_start",
          *(_DWORD *)(v9 + 8),
          *(_DWORD *)(a2 + 16),
          *(_DWORD *)(v9 + 20),
          *(_DWORD *)(v9 + 24),
          *(_DWORD *)(v9 + 32),
          (char)v55[189],
          (char)v55[190],
          (char)v55[191]);
        if ( *(_DWORD *)(v9 + 8) )
        {
          v53 = 0;
          v54 = v9;
          while ( v53 != 16 )
          {
            qdf_trace_msg(
              72,
              8,
              "%s: [%d] ssid: %.*s, RSSI th %d bc NW type %u",
              "wlan_cfg80211_sched_scan_start",
              v53++,
              *(unsigned __int8 *)(v54 + 68),
              (const char *)(v54 + 69),
              *(_DWORD *)(v54 + 1344),
              *(_DWORD *)(v54 + 112));
            v54 += 1280;
            if ( v53 >= *(unsigned int *)(v9 + 8) )
              goto LABEL_85;
          }
          goto LABEL_93;
        }
LABEL_85:
        if ( (unsigned int)ucfg_scan_pno_start(v52, v9) )
        {
          qdf_trace_msg(72, 2, "%s: Failed to enable PNO", "wlan_cfg80211_sched_scan_start");
          goto LABEL_18;
        }
        v15 = 0;
        goto LABEL_19;
      }
      v50 = 2;
    }
    else
    {
      v49 = v59;
      v50 = 1;
    }
    v55[190] = v50;
    goto LABEL_77;
  }
  qdf_trace_msg(72, 8, "%s: pno is already in progress", "wlan_cfg80211_sched_scan_start");
  result = 4294967280LL;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
