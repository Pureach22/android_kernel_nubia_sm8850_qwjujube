__int64 __fastcall hdd_medium_assess_expire_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  unsigned int v27; // w20
  char v28; // w9
  __int64 v29; // x21
  char v30; // w22
  unsigned __int8 *v31; // x23
  unsigned int v32; // w8
  unsigned __int8 *v33; // x26
  __int64 v34; // x27
  unsigned int v35; // w8
  unsigned int v36; // w9
  int v37; // w8
  int v38; // w10
  bool v39; // vf
  unsigned int v40; // w9
  unsigned int v41; // w10
  bool v42; // cf
  const char *v43; // x2
  unsigned __int64 v44; // x10
  __int64 v45; // x8
  unsigned __int64 v46; // x11
  __int64 v47; // x9
  unsigned int v48; // w12
  unsigned int v49; // w13
  int v50; // w13
  unsigned int v51; // w14
  unsigned int v52; // w15
  int v53; // w15
  unsigned int v54; // w10
  unsigned int v55; // w11
  unsigned int v56; // w5
  unsigned int v57; // w8
  unsigned int v58; // w9
  unsigned int v59; // w6
  unsigned int v60; // w19
  int v61; // w11
  int v62; // w12
  unsigned int v63; // w9
  unsigned int v64; // w7
  unsigned __int64 v65; // x8
  unsigned int v66; // w9
  unsigned __int64 v67; // x9
  unsigned int v68; // w25
  _QWORD *v69; // x27
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  _QWORD *link_info_by_vdev; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x26
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned __int64 v105; // x9
  unsigned __int8 *v106; // x8
  unsigned __int8 *v107; // x8
  __int64 v108; // x0
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // x19
  unsigned int *v126; // x8
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  __int64 v135; // [xsp+0h] [xbp-60h]
  __int64 v136; // [xsp+8h] [xbp-58h]
  __int64 v137; // [xsp+18h] [xbp-48h]
  _BYTE v138[4]; // [xsp+24h] [xbp-3Ch] BYREF
  __int64 v139; // [xsp+28h] [xbp-38h] BYREF
  void *v140; // [xsp+30h] [xbp-30h]
  __int64 v141; // [xsp+38h] [xbp-28h]
  __int64 v142; // [xsp+40h] [xbp-20h]
  __int64 v143; // [xsp+48h] [xbp-18h]
  __int64 v144; // [xsp+50h] [xbp-10h]
  __int64 v145; // [xsp+58h] [xbp-8h]

  v145 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v143 = 0;
  v144 = 0;
  v141 = 0;
  v142 = 0;
  v139 = 0;
  v140 = nullptr;
  context = _cds_get_context(51, (__int64)"hdd_medium_assess_expire_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  result = _wlan_hdd_validate_context(
             (__int64)context,
             (__int64)"hdd_medium_assess_expire_handler",
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16);
  if ( (_DWORD)result )
    goto LABEL_78;
  v26 = 0;
  v27 = 255;
  v28 = 1;
  v137 = (__int64)context;
  do
  {
    v29 = 756 * v26;
    v30 = v28;
    v31 = (unsigned __int8 *)&medium_assess_info + 756 * v26;
    if ( !v31[2] )
      goto LABEL_4;
    v32 = *v31;
    if ( v32 >= 3 )
      goto LABEL_80;
    if ( v32 == 2 )
      goto LABEL_79;
    v33 = (unsigned __int8 *)&medium_assess_info + 756 * *v31;
    v27 = v31[1];
    v34 = 756LL * *v31;
    v35 = *((_DWORD *)v33 + 188) + 1;
    *((_DWORD *)v33 + 188) = v35;
    if ( (v34 | 2uLL) > 0x5E8 )
      goto LABEL_79;
    v36 = v33[2];
    if ( !(v35 % v36) )
    {
      v37 = *((_DWORD *)v33 + 1) - 1;
      if ( v37 < 0 )
        v37 = 30;
      v38 = 31 - v36;
      v39 = __OFSUB__(v37, v36);
      v40 = v37 - v36;
      v41 = v38 - v37;
      if ( ((v40 & 0x80000000) != 0) != v39 )
        v40 = v41;
      v42 = v37 > 30 || v40 >= 0x1F;
      if ( v42 )
      {
        v43 = "%s: medium assess index is not valid.";
      }
      else
      {
        if ( (unsigned int)v37 >= 0x20 )
          goto LABEL_80;
        v44 = v34 + 8 + 24LL * (unsigned int)v37;
        if ( v44 > 0x5E7 )
          goto LABEL_79;
        v45 = (__int64)&v33[24 * v37 + 8];
        v46 = v34 + 8 + 24LL * v40;
        v47 = (__int64)&v33[24 * v40 + 8];
        if ( (*(_BYTE *)v45 & 1) != 0 )
        {
          if ( v44 > 0x5DF )
            goto LABEL_79;
LABEL_30:
          if ( v46 > 0x5DF )
            goto LABEL_79;
LABEL_31:
          v48 = *(_DWORD *)(v45 + 8);
          v49 = *(_DWORD *)(v47 + 8);
          if ( v48 < v49 )
            v50 = ~v49;
          else
            v50 = -v49;
          if ( v44 > 0x5DB || v46 > 0x5DB )
            goto LABEL_79;
          v51 = *(_DWORD *)(v45 + 12);
          v52 = *(_DWORD *)(v47 + 12);
          v53 = v51 < v52 ? ~v52 : -v52;
          if ( v44 > 0x5D3 || v46 > 0x5D3 )
            goto LABEL_79;
          v54 = *(_DWORD *)(v45 + 20);
          v55 = *(_DWORD *)(v47 + 20);
          v56 = v50 + v48;
          v57 = *(_DWORD *)(v45 + 4);
          v58 = *(_DWORD *)(v47 + 4);
          v59 = v53 + v51;
          v60 = 0;
          if ( v54 < v55 )
            v61 = ~v55;
          else
            v61 = -v55;
          v62 = -v58;
          if ( v57 < v58 )
            v62 = ~v58;
          v63 = v56 - v59;
          v64 = v61 + v54;
          v65 = v62 + v57;
          if ( v56 > v59 )
          {
            v42 = v63 >= v64;
            v66 = v63 - v64;
            if ( v66 != 0 && v42 )
            {
              if ( (_DWORD)v65 )
                v67 = 100 * (unsigned __int64)v66 / v65;
              else
                LODWORD(v67) = 0;
              if ( (unsigned int)v67 >= 0x64 )
                v60 = 100;
              else
                v60 = v67;
            }
            else
            {
              v60 = 0;
            }
          }
          LODWORD(v136) = v60;
          LODWORD(v135) = v65;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: pdev: %d, rx_c %u, tx %u myrx %u cycle %u congestion: %u",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            "hdd_congestion_notification_calculation",
            *v33,
            v135,
            v136);
          if ( (v34 | 3uLL) > 0x5E8 )
            goto LABEL_79;
          if ( v60 >= v33[3] )
          {
            v68 = v33[1];
            v69 = _cds_get_context(
                    51,
                    (__int64)"hdd_congestion_notification_report",
                    v18,
                    v19,
                    v20,
                    v21,
                    v22,
                    v23,
                    v24,
                    v25);
            if ( !(unsigned int)_wlan_hdd_validate_context(
                                  (__int64)v69,
                                  (__int64)"hdd_congestion_notification_report",
                                  v70,
                                  v71,
                                  v72,
                                  v73,
                                  v74,
                                  v75,
                                  v76,
                                  v77) )
            {
              link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev((__int64)v69, v68);
              if ( link_info_by_vdev )
              {
                v87 = _cfg80211_alloc_event_skb(v69[3], *link_info_by_vdev + 112LL, 103, 197, 0, 43, 32, 3264);
                if ( v87 )
                {
                  v96 = v87;
                  v138[0] = 1;
                  if ( (unsigned int)nla_put(v87, 1, 1, v138)
                    || (v138[0] = v60, (unsigned int)nla_put(v96, 12, 1, v138)) )
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: nla put failed",
                      v97,
                      v98,
                      v99,
                      v100,
                      v101,
                      v102,
                      v103,
                      v104,
                      "hdd_congestion_notification_report");
                    sk_skb_reason_drop(0, v96, 2);
                  }
                  else
                  {
                    _cfg80211_send_event_skb(v96, 3264);
                  }
                }
                else
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: wlan_cfg80211_vendor_event_alloc failed",
                    v88,
                    v89,
                    v90,
                    v91,
                    v92,
                    v93,
                    v94,
                    v95,
                    "hdd_congestion_notification_report");
                }
              }
              else
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to find adapter of vdev %d",
                  v79,
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  "hdd_congestion_notification_report",
                  v68);
              }
            }
          }
          goto LABEL_68;
        }
        if ( v44 > 0x5D7 )
          goto LABEL_79;
        if ( (*(_BYTE *)(v45 + 16) & 1) != 0 )
          goto LABEL_30;
        if ( v46 > 0x5E7 )
          goto LABEL_79;
        if ( (*(_BYTE *)v47 & 1) != 0 )
          goto LABEL_30;
        if ( v46 > 0x5D7 )
          goto LABEL_79;
        if ( (*(_BYTE *)(v47 + 16) & 1) != 0 )
          goto LABEL_31;
        v43 = "%s: medium assess data is not valid.";
      }
      qdf_trace_msg(0x33u, 2u, v43, v18, v19, v20, v21, v22, v23, v24, v25, "hdd_congestion_notification_calculation");
    }
LABEL_68:
    if ( v31[4] > 0x1Eu )
      goto LABEL_80;
    v105 = v29 + 24LL * v31[4] + 8;
    if ( v105 > 0x5E7 || (v106 = &v31[24 * v31[4]], v106[8] = 0, v107 = v106 + 8, v105 > 0x5D7) )
    {
LABEL_79:
      __break(1u);
LABEL_80:
      __break(0x5512u);
    }
    v107[16] = 0;
LABEL_4:
    v28 = 0;
    v26 = 1;
  }
  while ( (v30 & 1) != 0 );
  result = v137;
  if ( v27 != 255 )
  {
    v108 = hdd_get_link_info_by_vdev(v137, v27);
    if ( v108 )
    {
      result = _hdd_objmgr_get_vdev_by_user(v108, 0x26u, (__int64)"hdd_medium_assess_expire_handler");
      if ( result )
      {
        v141 = v27 | 0xFF00000000LL;
        v140 = &hdd_congestion_notification_cb;
        v125 = result;
        stime = jiffies + 10LL;
        ucfg_mc_cp_stats_send_stats_request(result, 5u, (__int64)&v139, v117, v118, v119, v120, v121, v122, v123, v124);
        _hdd_objmgr_put_vdev_by_user(
          v125,
          0x26u,
          (__int64)"hdd_medium_assess_expire_handler",
          v126,
          v127,
          v128,
          v129,
          v130,
          v131,
          v132,
          v133,
          v134);
        result = qdf_mc_timer_start((__int64)&hdd_medium_assess_timer, 0x3E8u);
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: Failed to find adapter of vdev %d",
                 v109,
                 v110,
                 v111,
                 v112,
                 v113,
                 v114,
                 v115,
                 v116,
                 "hdd_medium_assess_expire_handler",
                 v27);
    }
  }
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return result;
}
