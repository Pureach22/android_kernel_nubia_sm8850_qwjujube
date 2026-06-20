__int64 __fastcall osif_twt_clear_session_traffic_stats(__int64 a1, _WORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  int v4; // w8
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21
  const char *v24; // x2
  __int64 v25; // x20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _BYTE v42[4]; // [xsp+14h] [xbp-8Ch] BYREF
  int v43; // [xsp+18h] [xbp-88h] BYREF
  __int16 v44; // [xsp+1Ch] [xbp-84h]
  __int64 v45; // [xsp+20h] [xbp-80h] BYREF
  __int64 v46; // [xsp+28h] [xbp-78h]
  __int64 v47; // [xsp+30h] [xbp-70h]
  __int64 v48; // [xsp+38h] [xbp-68h]
  __int64 v49; // [xsp+40h] [xbp-60h]
  __int64 v50; // [xsp+48h] [xbp-58h]
  __int64 v51; // [xsp+50h] [xbp-50h]
  __int64 v52; // [xsp+58h] [xbp-48h]
  __int64 v53; // [xsp+60h] [xbp-40h]
  __int64 v54; // [xsp+68h] [xbp-38h]
  __int64 v55; // [xsp+70h] [xbp-30h]
  __int64 v56; // [xsp+78h] [xbp-28h]
  __int64 v57; // [xsp+80h] [xbp-20h]
  __int64 v58; // [xsp+88h] [xbp-18h]
  __int64 v59; // [xsp+90h] [xbp-10h]
  __int64 v60; // [xsp+98h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 152);
  if ( !v2 )
    goto LABEL_5;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v3 = *(_QWORD *)(v2 + 80);
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v45 = 0;
  if ( !v3 )
    goto LABEL_5;
  v4 = (__int16)a2[1];
  v42[0] = 0;
  v43 = 0;
  v44 = 0;
  if ( (v4 & 0x80000000) == 0 )
  {
    do_trace_netlink_extack("NLA_F_NESTED is missing");
    goto LABEL_5;
  }
  result = _nla_parse(&v45, 14, a2 + 2, (unsigned __int16)(*a2 - 4), &qca_wlan_vendor_twt_stats_dialog_policy, 31, 0);
  if ( (_DWORD)result )
    goto LABEL_6;
  ucfg_twt_get_twt_stats_enabled(v3, v42);
  if ( (v42[0] & 1) == 0 )
  {
    v24 = "%s: TWT Stats not supported by target";
    goto LABEL_14;
  }
  if ( !v46 )
  {
    v25 = jiffies;
    if ( osif_twt_clear_session_traffic_stats___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: TWT Clear stats - dialog id param is must",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "osif_twt_clear_session_traffic_stats");
      osif_twt_clear_session_traffic_stats___last_ticks = v25;
      result = 4294967274LL;
      goto LABEL_6;
    }
    goto LABEL_5;
  }
  if ( (unsigned int)osif_fill_peer_macaddr(a1, &v43) )
  {
LABEL_5:
    result = 4294967274LL;
    goto LABEL_6;
  }
  v23 = *(unsigned __int8 *)(v46 + 4);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: dialog_id %d peer mac_addr %02x:%02x:%02x:**:**:%02x",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "osif_twt_clear_session_traffic_stats",
    *(unsigned __int8 *)(v46 + 4),
    (unsigned __int8)v43,
    BYTE1(v43),
    BYTE2(v43),
    HIBYTE(v44));
  if ( (unsigned int)ucfg_twt_check_all_twt_support(v3, v23) )
  {
    v24 = "%s: All TWT sessions not supported by target";
LABEL_14:
    qdf_trace_msg(0x48u, 8u, v24, v7, v8, v9, v10, v11, v12, v13, v14, "osif_twt_clear_session_traffic_stats");
    result = 4294967201LL;
    goto LABEL_6;
  }
  if ( (ucfg_twt_is_command_in_progress() & 1) != 0 || (ucfg_twt_is_command_in_progress() & 1) != 0 )
  {
    qdf_trace_msg(
      0x48u,
      3u,
      "%s: Already TWT statistics or clear statistics exists",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "osif_twt_clear_session_traffic_stats");
    result = 4294967182LL;
  }
  else if ( (ucfg_twt_is_setup_done() & 1) != 0 )
  {
    result = wlan_cfg80211_mc_twt_clear_infra_cp_stats(a1, v23, &v43, v34, v35, v36, v37, v38, v39, v40, v41);
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: TWT session %d setup incomplete",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "osif_twt_clear_session_traffic_stats",
      v23);
    result = 4294967285LL;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
