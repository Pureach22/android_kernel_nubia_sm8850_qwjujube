__int64 __fastcall wlan_hdd_cfg80211_stats_ext_request(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v8; // x0
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x24
  __int64 **context; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w19
  __int64 v55; // x8
  __int64 v56; // x9
  _DWORD *v57; // x8
  __int64 v58; // x1
  unsigned __int8 *v59; // x9
  unsigned int v60; // t1
  unsigned int v61; // w0
  __int64 v62; // x25
  __int64 v63; // x9
  __int64 v64; // x10
  int v65; // w20
  __int64 (__fastcall *v66)(__int64 **, __int64); // x8
  __int64 v67; // x1
  unsigned int v68; // w0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x4
  __int64 v78; // x20
  int v79; // w4
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x20
  __int64 v89; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v90[3]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v91; // [xsp+28h] [xbp-28h]
  __int64 v92; // [xsp+30h] [xbp-20h]
  __int64 v93; // [xsp+38h] [xbp-18h] BYREF
  __int64 v94; // [xsp+40h] [xbp-10h]
  __int64 v95; // [xsp+48h] [xbp-8h]

  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v89 = 0;
  v9 = _osif_vdev_sync_op_start(v8, &v89, "wlan_hdd_cfg80211_stats_ext_request");
  if ( !(_DWORD)v9 )
  {
    v93 = 0;
    v94 = 0;
    if ( !a1 )
    {
      __break(0x800u);
      JUMPOUT(0x39DD10);
    }
    v18 = *(_QWORD *)(a2 + 32);
    context = (__int64 **)_cds_get_context(
                            71,
                            (__int64)"__wlan_hdd_cfg80211_stats_ext_request",
                            v10,
                            v11,
                            v12,
                            v13,
                            v14,
                            v15,
                            v16,
                            v17);
    v91 = 0;
    v92 = 0;
    memset(v90, 0, sizeof(v90));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "__wlan_hdd_cfg80211_stats_ext_request",
      v18 + 296);
    v36 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__wlan_hdd_cfg80211_stats_ext_request",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35);
    if ( v36 )
      goto LABEL_8;
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "__wlan_hdd_cfg80211_stats_ext_request");
      v36 = -1;
LABEL_8:
      v53 = v36;
      _osif_vdev_sync_op_stop(v89, "wlan_hdd_cfg80211_stats_ext_request");
      v9 = v53;
      goto LABEL_9;
    }
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                         *(_BYTE *)(*(_QWORD *)(v18 + 55520) + 8LL),
                         (__int64)"__wlan_hdd_cfg80211_stats_ext_request",
                         v37,
                         v38,
                         v39,
                         v40,
                         v41,
                         v42,
                         v43,
                         v44) )
    {
LABEL_7:
      v36 = -22;
      goto LABEL_8;
    }
    LOBYTE(v91) = 0;
    LODWORD(v90[0]) = 2;
    if ( context && *context && (v55 = **context) != 0 )
    {
      v56 = *(_QWORD *)(v18 + 55520);
      v57 = *(_DWORD **)(v55 + 520);
      v60 = *(unsigned __int8 *)(v56 + 8);
      v59 = (unsigned __int8 *)(v56 + 8);
      v58 = v60;
      if ( !v57 )
      {
        LODWORD(v93) = a4;
        v94 = a3;
LABEL_26:
        if ( *context )
        {
          v64 = (*context)[8];
          if ( v64 )
          {
            v65 = (int)v57;
            v66 = *(__int64 (__fastcall **)(__int64 **, __int64))(v64 + 240);
            if ( !v66 )
              goto LABEL_37;
            v67 = *v59;
            if ( *((_DWORD *)v66 - 1) != 261447488 )
              __break(0x8228u);
            v68 = v66(context, v67);
            v77 = v68;
            if ( !v68 )
              goto LABEL_37;
            goto LABEL_34;
          }
        }
LABEL_33:
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance:",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "cdp_request_rx_hw_stats");
        v77 = 4;
LABEL_34:
        v78 = jiffies;
        if ( _wlan_hdd_cfg80211_stats_ext_request___last_ticks_196 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to get hw stats: %u",
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            "__wlan_hdd_cfg80211_stats_ext_request",
            v77);
          _wlan_hdd_cfg80211_stats_ext_request___last_ticks_196 = v78;
        }
        v65 = -22;
LABEL_37:
        v79 = sme_stats_ext_request(*(unsigned __int8 *)(*(_QWORD *)(v18 + 55520) + 8LL), &v93);
        v36 = v65;
        if ( !v79 )
          goto LABEL_8;
        v88 = jiffies;
        if ( _wlan_hdd_cfg80211_stats_ext_request___last_ticks_197 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to get fw stats: %u",
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            v87,
            "__wlan_hdd_cfg80211_stats_ext_request");
          _wlan_hdd_cfg80211_stats_ext_request___last_ticks_197 = v88;
        }
        goto LABEL_7;
      }
      if ( *(v57 - 1) != -242941968 )
        __break(0x8228u);
      v61 = ((__int64 (__fastcall *)(__int64 **, __int64, _QWORD *))v57)(context, v58, v90);
      if ( v61 )
      {
        v62 = jiffies;
        if ( _wlan_hdd_cfg80211_stats_ext_request___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to get hw stats: %u",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "__wlan_hdd_cfg80211_stats_ext_request",
            v61);
          _wlan_hdd_cfg80211_stats_ext_request___last_ticks = v62;
        }
        LODWORD(v57) = -22;
      }
      else
      {
        LODWORD(v57) = 0;
      }
      v63 = *(_QWORD *)(v18 + 55520);
      LODWORD(v93) = a4;
      v94 = a3;
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "cdp_txrx_stats_request");
      LODWORD(v93) = a4;
      v94 = a3;
      if ( !context )
        goto LABEL_33;
      v63 = *(_QWORD *)(v18 + 55520);
      LODWORD(v57) = 0;
    }
    v59 = (unsigned __int8 *)(v63 + 8);
    goto LABEL_26;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return sub_39DB04(v9);
}
