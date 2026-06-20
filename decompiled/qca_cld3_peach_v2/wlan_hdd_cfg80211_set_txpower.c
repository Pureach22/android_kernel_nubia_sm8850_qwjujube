__int64 __fastcall wlan_hdd_cfg80211_set_txpower(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x24
  const char *v27; // x2
  int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w19
  unsigned int *v46; // x8
  unsigned __int64 v47; // x22
  __int64 v48; // x23
  unsigned int v49; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w0
  __int64 v67; // x4
  const char *v68; // x2
  __int64 v69; // x22
  unsigned int v70; // w0
  _QWORD v71[2]; // [xsp+0h] [xbp-10h] BYREF

  v71[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 488);
  v71[0] = 0;
  result = _osif_psoc_sync_op_start(v8, v71, "wlan_hdd_cfg80211_set_txpower");
  if ( (_DWORD)result )
    goto LABEL_15;
  if ( a1 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v10, v11, v12, v13, v14, v15, v16, v17, "__wlan_hdd_cfg80211_set_txpower");
    if ( (a4 & 0x80000000) != 0 )
    {
      v27 = "%s: tx power < 0, not supported";
      goto LABEL_8;
    }
    if ( !a2 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wdev is null, set tx power failed",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "__wlan_hdd_cfg80211_set_txpower");
LABEL_10:
      v28 = -5;
      goto LABEL_14;
    }
    v26 = *(_QWORD *)(a2 + 32);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v27 = "%s: Command not allowed in FTM mode";
LABEL_8:
      qdf_trace_msg(0x33u, 2u, v27, v18, v19, v20, v21, v22, v23, v24, v25, "__wlan_hdd_cfg80211_set_txpower");
      v28 = -22;
LABEL_14:
      v45 = v28;
      _osif_psoc_sync_op_stop(v71[0], "wlan_hdd_cfg80211_set_txpower");
      result = v45;
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    qdf_mtrace(51, 51, 0x24u, 0xFFu, a3);
    v28 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__wlan_hdd_cfg80211_set_txpower",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36);
    if ( v28 )
      goto LABEL_14;
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                         *(_BYTE *)(*(_QWORD *)(v26 + 55520) + 8LL),
                         (__int64)"__wlan_hdd_cfg80211_set_txpower",
                         v37,
                         v38,
                         v39,
                         v40,
                         v41,
                         v42,
                         v43,
                         v44) )
    {
      v28 = -22;
      goto LABEL_14;
    }
    v46 = (unsigned int *)(v26 + 4305);
    if ( (*(_DWORD *)(v26 + 2728) | 2) != 3 )
    {
      v69 = *(_QWORD *)(v26 + 55520);
      if ( !hdd_cm_is_vdev_associated(*(_DWORD **)(v26 + 55520)) )
      {
        v47 = 0xFFFFFFFFFFFFLL;
LABEL_19:
        v48 = *(_QWORD *)(a1 + 1552);
        if ( a4 >= 0x64 )
          a4 /= 0x64u;
        v49 = ucfg_mlme_set_current_tx_power_level(*(_QWORD *)(a1 + 1536), a4);
        if ( v49 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: sme_cfg_set_int failed for tx power %d, %d",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "__wlan_hdd_cfg80211_set_txpower",
            a4,
            v49);
          goto LABEL_10;
        }
        *(_BYTE *)(a1 + 9849) = 0;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Set tx power level %d dbm",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "__wlan_hdd_cfg80211_set_txpower",
          a4);
        if ( a3 >= 2 )
        {
          if ( a3 != 2 )
          {
            v68 = "%s: Invalid power setting type %d";
            v67 = a3;
            goto LABEL_34;
          }
          v70 = sme_set_tx_power(
                  v48,
                  *(unsigned __int8 *)(*(_QWORD *)(v26 + 55520) + 8LL),
                  v47,
                  *(unsigned int *)(v26 + 2728),
                  a4);
          if ( v70 )
          {
            v67 = v70;
            v68 = "%s: Setting tx power failed, %d";
            goto LABEL_34;
          }
        }
        else
        {
          v66 = sme_set_max_tx_power(v48);
          if ( v66 )
          {
            v67 = v66;
            v68 = "%s: Setting maximum tx power failed, %d";
LABEL_34:
            qdf_trace_msg(
              0x33u,
              2u,
              v68,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              "__wlan_hdd_cfg80211_set_txpower",
              v67);
            goto LABEL_10;
          }
        }
        qdf_trace_msg(0x33u, 8u, "%s: exit", v58, v59, v60, v61, v62, v63, v64, v65, "__wlan_hdd_cfg80211_set_txpower");
        v28 = 0;
        goto LABEL_14;
      }
      v46 = (unsigned int *)(v69 + 308);
    }
    v47 = *v46 | ((unsigned __int64)*((unsigned __int16 *)v46 + 2) << 32);
    goto LABEL_19;
  }
  __break(0x800u);
  return wlan_hdd_get_ani_level();
}
