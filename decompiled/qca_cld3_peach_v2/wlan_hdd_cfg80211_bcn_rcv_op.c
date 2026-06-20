__int64 __fastcall wlan_hdd_cfg80211_bcn_rcv_op(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
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
  __int64 v18; // x24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int started; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  __int64 vdev_by_user; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x23
  unsigned int pdev_status; // w22
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w19
  unsigned int v66; // w0
  const char *v67; // x2
  unsigned int v68; // w19
  unsigned int v69; // w20
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x21
  __int64 v79; // x22
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned int v96; // w20
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x20
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  __int64 *v138; // [xsp+0h] [xbp-80h] BYREF
  __int64 v139; // [xsp+8h] [xbp-78h] BYREF
  __int64 v140; // [xsp+10h] [xbp-70h]
  __int64 v141; // [xsp+18h] [xbp-68h]
  __int64 v142; // [xsp+20h] [xbp-60h]
  __int64 v143; // [xsp+28h] [xbp-58h]
  __int64 v144; // [xsp+30h] [xbp-50h]
  __int64 v145; // [xsp+38h] [xbp-48h]
  __int64 v146; // [xsp+40h] [xbp-40h]
  __int64 v147; // [xsp+48h] [xbp-38h]
  __int64 v148; // [xsp+50h] [xbp-30h]
  __int64 v149; // [xsp+58h] [xbp-28h]
  __int64 v150; // [xsp+60h] [xbp-20h]
  __int64 v151; // [xsp+68h] [xbp-18h]
  __int64 v152; // [xsp+70h] [xbp-10h]
  __int64 v153; // [xsp+78h] [xbp-8h]

  v153 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v138 = nullptr;
  result = _osif_vdev_sync_op_start(v8, &v138, (__int64)"wlan_hdd_cfg80211_bcn_rcv_op");
  if ( (_DWORD)result )
    goto LABEL_16;
  if ( a1 )
  {
    v18 = *(_QWORD *)(a2 + 32);
    v151 = 0;
    v152 = 0;
    v149 = 0;
    v150 = 0;
    v147 = 0;
    v148 = 0;
    v145 = 0;
    v146 = 0;
    v143 = 0;
    v144 = 0;
    v141 = 0;
    v142 = 0;
    v139 = 0;
    v140 = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_hdd_cfg80211_bcn_rcv_op",
      v18 + 296);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "__wlan_hdd_cfg80211_bcn_rcv_op");
      started = -1;
LABEL_15:
      v65 = started;
      _osif_vdev_sync_op_stop((__int64)v138, (__int64)"wlan_hdd_cfg80211_bcn_rcv_op");
      result = v65;
LABEL_16:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    started = _hdd_validate_adapter(
                v18 + 2688,
                (__int64)"__wlan_hdd_cfg80211_bcn_rcv_op",
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26);
    if ( started )
      goto LABEL_15;
    if ( *(_DWORD *)(v18 + 2728) )
    {
      v36 = "%s: Command not allowed as device not in STA mode";
    }
    else
    {
      if ( hdd_cm_is_vdev_associated(*(_DWORD **)(v18 + 55520)) )
      {
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                         *(_QWORD *)(v18 + 55520),
                         0x4Fu,
                         (__int64)"__wlan_hdd_cfg80211_bcn_rcv_op");
        if ( !vdev_by_user )
        {
LABEL_14:
          started = -22;
          goto LABEL_15;
        }
        v46 = vdev_by_user;
        pdev_status = ucfg_scan_get_pdev_status(*(_QWORD *)(vdev_by_user + 216), v38, v39, v40, v41, v42, v43, v44, v45);
        wlan_objmgr_vdev_release_ref(v46, 0x4Fu, v48, v49, v50, v51, v52, v53, v54, v55, v56);
        if ( pdev_status )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Scan in progress: %d, bcn rpt start OP not allowed",
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            "__wlan_hdd_cfg80211_bcn_rcv_op",
            pdev_status);
          started = -16;
          goto LABEL_15;
        }
        v66 = _nla_parse(&v139, 13, a3, a4, &beacon_reporting_params_policy, 31, 0);
        if ( v66 )
        {
          v67 = "%s: Failed to parse the beacon reporting params %d";
          v68 = v66;
        }
        else
        {
          if ( !v140 )
          {
            v36 = "%s: attr beacon report OP type failed";
            goto LABEL_13;
          }
          v69 = *(unsigned __int8 *)(v140 + 4);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Bcn Report: OP type:%d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "__wlan_hdd_cfg80211_bcn_rcv_op",
            *(unsigned __int8 *)(v140 + 4));
          if ( v69 == 1 )
          {
            if ( (sme_is_beacon_report_started(
                    *(_QWORD *)(a1 + 1552),
                    *(unsigned __int8 *)(*(_QWORD *)(v18 + 55520) + 8LL),
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    v77)
                & 1) == 0 )
            {
              v105 = jiffies;
              if ( _wlan_hdd_cfg80211_bcn_rcv_op___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: BCN_RCV_STOP rej as no START CMD active",
                  v97,
                  v98,
                  v99,
                  v100,
                  v101,
                  v102,
                  v103,
                  v104,
                  "__wlan_hdd_cfg80211_bcn_rcv_op");
                _wlan_hdd_cfg80211_bcn_rcv_op___last_ticks = v105;
              }
              goto LABEL_14;
            }
            started = hdd_handle_beacon_reporting_stop_op(
                        a1 + 1536,
                        v18 + 2688,
                        v97,
                        v98,
                        v99,
                        v100,
                        v101,
                        v102,
                        v103,
                        v104);
            if ( !started )
              goto LABEL_15;
            v68 = started;
            v67 = "%s: Failed to stop the beacon report, %d";
          }
          else
          {
            if ( v69 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Invalid bcn report type %d",
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                "__wlan_hdd_cfg80211_bcn_rcv_op",
                v69);
              started = 0;
              goto LABEL_15;
            }
            v78 = v141;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: attr active_report %d",
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              "__wlan_hdd_cfg80211_bcn_rcv_op",
              v141 != 0);
            v79 = v152;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Attr beacon report do not resume %d",
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              "__wlan_hdd_cfg80211_bcn_rcv_op",
              v152 != 0);
            if ( v142 )
              v96 = *(unsigned __int8 *)(v142 + 4);
            else
              v96 = 1;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Beacon Report: Period: %d",
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              "__wlan_hdd_cfg80211_bcn_rcv_op",
              v96);
            if ( (sme_is_beacon_report_started(
                    *(_QWORD *)(a1 + 1552),
                    *(unsigned __int8 *)(*(_QWORD *)(v18 + 55520) + 8LL),
                    v106,
                    v107,
                    v108,
                    v109,
                    v110,
                    v111,
                    v112,
                    v113)
                & 1) != 0 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Start cmd already in progress, issue the stop to FW, before new start",
                v114,
                v115,
                v116,
                v117,
                v118,
                v119,
                v120,
                v121,
                "__wlan_hdd_cfg80211_bcn_rcv_op");
              if ( (unsigned int)hdd_handle_beacon_reporting_stop_op(
                                   a1 + 1536,
                                   v18 + 2688,
                                   v122,
                                   v123,
                                   v124,
                                   v125,
                                   v126,
                                   v127,
                                   v128,
                                   v129) )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to stop the beacon reporting before starting new start",
                  v130,
                  v131,
                  v132,
                  v133,
                  v134,
                  v135,
                  v136,
                  v137,
                  "__wlan_hdd_cfg80211_bcn_rcv_op");
                started = -11;
                goto LABEL_15;
              }
            }
            started = hdd_handle_beacon_reporting_start_op(a1 + 1536, v18 + 2688, v78 != 0, v96, v79 != 0);
            if ( !started )
              goto LABEL_15;
            v68 = started;
            v67 = "%s: Failed to start beacon reporting %d,";
          }
        }
        qdf_trace_msg(0x33u, 2u, v67, v28, v29, v30, v31, v32, v33, v34, v35, "__wlan_hdd_cfg80211_bcn_rcv_op", v68);
        started = v68;
        goto LABEL_15;
      }
      v36 = "%s: STA not in connected state";
    }
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v36, v28, v29, v30, v31, v32, v33, v34, v35, "__wlan_hdd_cfg80211_bcn_rcv_op");
    goto LABEL_14;
  }
  __break(0x800u);
  return ((__int64 (*)(void))hdd_handle_beacon_reporting_start_op)();
}
