__int64 __fastcall wlan_hdd_cfg80211_get_txpower(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  __int128 v15; // q4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int128 v19; // q16
  __int64 v20; // x22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  unsigned int v30; // w1
  int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w19
  int v49; // w8
  const char *v50; // x2
  __int64 v51; // x20
  char *v52; // x8
  __int64 v53; // x0
  __int64 vdev_by_user; // x0
  __int64 v55; // x21
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x4
  const char *v65; // x2
  unsigned int *v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  int tx_power; // w19
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  _QWORD v84[2]; // [xsp+0h] [xbp-10h] BYREF

  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 488);
  v84[0] = 0;
  result = _osif_psoc_sync_op_start(v6, v84, "wlan_hdd_cfg80211_get_txpower");
  if ( (_DWORD)result )
    goto LABEL_10;
  if ( a1 )
  {
    v20 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v11,
      v12,
      v13,
      v14,
      *(double *)&v15,
      v16,
      v17,
      v18,
      "__wlan_hdd_cfg80211_get_txpower",
      v20 + 296);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v29 = "%s: Command not allowed in FTM mode";
LABEL_5:
      v30 = 2;
LABEL_6:
      qdf_trace_msg(0x33u, v30, v29, v21, v22, v23, v24, v25, v26, v27, v28, "__wlan_hdd_cfg80211_get_txpower");
      v31 = -22;
LABEL_9:
      v48 = v31;
      _osif_psoc_sync_op_stop(v84[0], "wlan_hdd_cfg80211_get_txpower");
      result = v48;
LABEL_10:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    *a3 = 0;
    v31 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__wlan_hdd_cfg80211_get_txpower",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28);
    if ( v31 )
      goto LABEL_9;
    v31 = _wlan_hdd_validate_vdev_id(
            *(_BYTE *)(*(_QWORD *)(v20 + 55520) + 8LL),
            (__int64)"__wlan_hdd_cfg80211_get_txpower",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39);
    if ( v31 )
      goto LABEL_9;
    v49 = *(_DWORD *)(v20 + 2728);
    if ( v49 > 1 )
    {
      if ( v49 == 3 )
        goto LABEL_19;
      if ( v49 != 2 )
        goto LABEL_21;
    }
    else if ( v49 )
    {
      if ( v49 != 1 )
      {
LABEL_21:
        v51 = jiffies;
        if ( _wlan_hdd_cfg80211_get_txpower___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Current interface is not supported for get tx_power",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "__wlan_hdd_cfg80211_get_txpower");
          v31 = 0;
          _wlan_hdd_cfg80211_get_txpower___last_ticks = v51;
        }
        else
        {
          v31 = 0;
        }
        goto LABEL_9;
      }
LABEL_19:
      if ( (*(_QWORD *)(*(_QWORD *)(v20 + 55520) + 5968LL) & 2) == 0 )
      {
        v50 = "%s: SAP is not started yet";
LABEL_35:
        qdf_trace_msg(0x33u, 8u, v50, v40, v41, v42, v43, v44, v45, v46, v47, "__wlan_hdd_cfg80211_get_txpower");
        v31 = 0;
        goto LABEL_9;
      }
      goto LABEL_24;
    }
    if ( hdd_cm_is_vdev_roaming(*(_QWORD *)(v20 + 55520)) )
    {
      v29 = "%s: Roaming is in progress, rej this req";
      v30 = 8;
      goto LABEL_6;
    }
    if ( !hdd_cm_is_vdev_associated(*(_DWORD **)(v20 + 55520)) )
    {
      v50 = "%s: Not associated";
      goto LABEL_35;
    }
LABEL_24:
    _wlan_hdd_cfg80211_get_txpower_is_rate_limited = 0;
    if ( _wlan_hdd_cfg80211_get_txpower___first_time != 1
      || _wlan_hdd_cfg80211_get_txpower___last_ticks_150
       - jiffies
       + 250LL * *(unsigned __int8 *)(*(_QWORD *)(a1 + 1640) + 174LL) < 0 )
    {
      _wlan_hdd_cfg80211_get_txpower___last_ticks_150 = jiffies;
      v52 = &_wlan_hdd_cfg80211_get_txpower___first_time;
    }
    else
    {
      v52 = &_wlan_hdd_cfg80211_get_txpower_is_rate_limited;
    }
    v53 = *(_QWORD *)(v20 + 55520);
    *v52 = 1;
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(v53, 0x56u, (__int64)"__wlan_hdd_cfg80211_get_txpower");
    if ( !vdev_by_user )
    {
      v29 = "%s: vdev is NULL";
      goto LABEL_5;
    }
    v55 = vdev_by_user;
    if ( *(_DWORD *)(a1 + 3000) == 1 )
    {
      if ( _wlan_hdd_cfg80211_get_txpower_is_rate_limited != 1 || *(_BYTE *)(a1 + 9849) != 1 )
      {
        if ( (unsigned int)jiffies_to_msecs(jiffies) - *(_DWORD *)(v20 + 73796) > 0x15E )
        {
          qdf_mtrace(51, 51, 0x25u, *(_BYTE *)(*(_QWORD *)(v20 + 55520) + 8LL), *(_DWORD *)(v20 + 2728));
          tx_power = wlan_hdd_get_tx_power(v20 + 2688, a3);
          v66 = (unsigned int *)(&dword_2678 + 1);
          *(_BYTE *)(a1 + 9849) = 1;
        }
        else
        {
          *a3 = *(_DWORD *)(v20 + 73792);
          qdf_trace_msg(0x33u, 8u, "cached tx_power: %d", v76, v77, v78, v79, v80, v81, v82, v83);
          tx_power = 0;
        }
        goto LABEL_42;
      }
      ucfg_mc_cp_stats_get_tx_power(vdev_by_user, a3);
      v64 = (unsigned int)*a3;
      v65 = "%s: Rate limited, cached tx power = %d";
    }
    else
    {
      ucfg_mc_cp_stats_get_tx_power(vdev_by_user, a3);
      v64 = (unsigned int)*a3;
      v65 = "%s: Modules not enabled, cached tx power = %d";
    }
    qdf_trace_msg(0x33u, 8u, v65, v56, v57, v58, v59, v60, v61, v62, v63, "__wlan_hdd_cfg80211_get_txpower", v64);
    tx_power = 0;
LABEL_42:
    _hdd_objmgr_put_vdev_by_user(
      v55,
      0x56u,
      (__int64)"__wlan_hdd_cfg80211_get_txpower",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74);
    v31 = tx_power;
    goto LABEL_9;
  }
  __break(0x800u);
  *(_OWORD *)(v10 + 320) = v15;
  *(_OWORD *)(v10 + 336) = v19;
  return hdd_set_power_config(result, v8, v9);
}
