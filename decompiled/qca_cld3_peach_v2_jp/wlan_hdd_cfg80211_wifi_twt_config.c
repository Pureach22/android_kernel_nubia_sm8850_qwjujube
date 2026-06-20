__int64 __fastcall wlan_hdd_cfg80211_wifi_twt_config(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x23
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w0
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
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  const char *v45; // x3
  __int64 v46; // x20
  int v47; // w21
  __int64 vdev_by_user; // x0
  __int64 v49; // x19
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int *v58; // x8
  int session_traffic_stats; // w20
  unsigned int v60; // w19
  unsigned int v61; // w0
  __int64 v62; // x21
  const char *v63; // x0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 *v72; // [xsp+0h] [xbp-30h] BYREF
  __int64 v73; // [xsp+8h] [xbp-28h] BYREF
  __int64 v74; // [xsp+10h] [xbp-20h]
  __int64 v75; // [xsp+18h] [xbp-18h]
  __int64 v76; // [xsp+20h] [xbp-10h]
  __int64 v77; // [xsp+28h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v72 = nullptr;
  result = _osif_vdev_sync_op_start(v8, &v72, (__int64)"wlan_hdd_cfg80211_wifi_twt_config");
  if ( (_DWORD)result )
    goto LABEL_25;
  if ( a1 )
  {
    v10 = *(_QWORD *)(a2 + 32);
    v75 = 0;
    v76 = 0;
    v73 = 0;
    v74 = 0;
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "__wlan_hdd_cfg80211_wifi_twt_config");
      v19 = -1;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: enter(%s)",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "__wlan_hdd_cfg80211_wifi_twt_config",
        v10 + 296);
      v19 = _wlan_hdd_validate_context(
              a1 + 1536,
              (__int64)"__wlan_hdd_cfg80211_wifi_twt_config",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27);
      if ( !v19 )
      {
        v19 = _hdd_validate_adapter(
                v10 + 2688,
                (__int64)"__wlan_hdd_cfg80211_wifi_twt_config",
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35);
        if ( !v19 )
        {
          if ( (unsigned int)_nla_parse(&v73, 3, a3, a4, &wlan_hdd_wifi_twt_config_policy, 31, 0) )
          {
            v44 = "%s: invalid twt attr";
            v45 = "__wlan_hdd_cfg80211_wifi_twt_config";
          }
          else
          {
            if ( v74 )
            {
              v46 = v75;
              v47 = *(unsigned __int8 *)(v74 + 4);
              if ( v75 || v47 == 3 || v47 == 8 )
              {
                vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                                 *(_QWORD *)(v10 + 55512),
                                 0x5Eu,
                                 (__int64)"hdd_twt_configure");
                if ( vdev_by_user )
                {
                  v49 = vdev_by_user;
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: vdev:%d TWT_Operation: 0x%x",
                    v36,
                    v37,
                    v38,
                    v39,
                    v40,
                    v41,
                    v42,
                    v43,
                    "hdd_twt_configure",
                    *(unsigned __int8 *)(vdev_by_user + 104),
                    (unsigned int)v47);
                  if ( v47 > 4 )
                  {
                    if ( v47 <= 6 )
                    {
                      if ( v47 == 5 )
                        session_traffic_stats = osif_twt_nudge_req(v49, v46);
                      else
                        session_traffic_stats = osif_twt_get_session_traffic_stats(v49, v46);
                    }
                    else
                    {
                      switch ( v47 )
                      {
                        case 7:
                          session_traffic_stats = osif_twt_clear_session_traffic_stats(v49, v46);
                          break;
                        case 8:
                          session_traffic_stats = osif_twt_get_capabilities(v49);
                          break;
                        case 10:
                          session_traffic_stats = osif_twt_set_param(v49, v46);
                          break;
                        default:
                          qdf_trace_msg(
                            0x33u,
                            2u,
                            "%s: Invalid TWT Operation",
                            v50,
                            v51,
                            v52,
                            v53,
                            v54,
                            v55,
                            v56,
                            v57,
                            "hdd_twt_configure");
                          session_traffic_stats = -22;
                          break;
                      }
                    }
                  }
                  else if ( v47 <= 1 )
                  {
                    if ( v47 )
                      session_traffic_stats = osif_twt_get_session_req(v49, v46);
                    else
                      session_traffic_stats = osif_twt_setup_req(v49, v46);
                  }
                  else if ( v47 == 2 )
                  {
                    v61 = *(_DWORD *)(v10 + 2728);
                    if ( v61 == 1 )
                    {
                      session_traffic_stats = osif_twt_sap_teardown_req(v49, v46);
                    }
                    else if ( v61 )
                    {
                      v62 = jiffies;
                      v58 = (unsigned int *)(hdd_twt_terminate_session___last_ticks - jiffies);
                      if ( hdd_twt_terminate_session___last_ticks - jiffies + 125 < 0 )
                      {
                        v63 = qdf_opmode_str(v61);
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: TWT terminate is not supported on %s",
                          v64,
                          v65,
                          v66,
                          v67,
                          v68,
                          v69,
                          v70,
                          v71,
                          "hdd_twt_terminate_session",
                          v63);
                        hdd_twt_terminate_session___last_ticks = v62;
                      }
                      session_traffic_stats = -95;
                    }
                    else
                    {
                      session_traffic_stats = osif_twt_sta_teardown_req(v49, v46);
                    }
                  }
                  else if ( v47 == 3 )
                  {
                    session_traffic_stats = osif_twt_pause_req(v49, v46);
                  }
                  else
                  {
                    session_traffic_stats = osif_twt_resume_req(v49, v46);
                  }
                  _hdd_objmgr_put_vdev_by_user(
                    v49,
                    0x5Eu,
                    (__int64)"hdd_twt_configure",
                    v58,
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    v55,
                    v56,
                    v57);
                  v19 = session_traffic_stats;
                  goto LABEL_24;
                }
                v44 = "%s: vdev is NULL";
              }
              else
              {
                v44 = "%s: TWT parameters NOT specified";
              }
            }
            else
            {
              v44 = "%s: TWT operation NOT specified";
            }
            v45 = "hdd_twt_configure";
          }
          qdf_trace_msg(0x33u, 2u, v44, v36, v37, v38, v39, v40, v41, v42, v43, v45);
          v19 = -22;
        }
      }
    }
LABEL_24:
    v60 = v19;
    _osif_vdev_sync_op_stop((__int64)v72, (__int64)"wlan_hdd_cfg80211_wifi_twt_config");
    result = v60;
LABEL_25:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  return wlan_hdd_resume_pmo_twt();
}
