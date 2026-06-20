__int64 __fastcall wlan_cfg80211_tdls_mgmt_mlo(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 a3,
        char a4,
        char a5,
        int a6,
        __int64 a7,
        __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        unsigned int a17)
{
  __int64 *v17; // x27
  __int64 vdev_by_user; // x0
  __int64 v26; // x19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x21
  unsigned int *v36; // x8
  __int64 v38; // x20
  __int64 tdls_link_vdev; // x0
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x20
  unsigned int v50; // w19
  unsigned int *v51; // x8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 link_vdev; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x19
  unsigned int v78; // w20
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned int *v87; // x8
  unsigned int v88; // w28
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned int *v97; // x8
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  __int64 v114; // x21
  __int64 mlo_vdev; // x0
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int64 v124; // x25
  unsigned int *v125; // x8
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  unsigned int *v134; // x8
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  __int64 v143; // x20
  __int64 v144; // x20
  __int64 v145; // x25
  __int64 v146; // x0
  __int64 v147; // x25
  unsigned int *v148; // x8
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  __int64 v157; // x21

  v17 = *(__int64 **)(a1 + 24);
  if ( !v17 )
  {
    v38 = jiffies;
    if ( wlan_cfg80211_tdls_mgmt_mlo___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: hdd_ctx is null",
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        a16,
        "wlan_cfg80211_tdls_mgmt_mlo");
      wlan_cfg80211_tdls_mgmt_mlo___last_ticks = v38;
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 0x57u, (__int64)"wlan_cfg80211_tdls_mgmt_mlo");
  if ( !vdev_by_user )
    return 4294967274LL;
  v26 = vdev_by_user;
  if ( (unsigned int)wlan_vdev_is_up() )
  {
    v35 = jiffies;
    v36 = (unsigned int *)(wlan_cfg80211_tdls_mgmt_mlo___last_ticks_38 - jiffies);
    if ( wlan_cfg80211_tdls_mgmt_mlo___last_ticks_38 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: STA is not connected",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "wlan_cfg80211_tdls_mgmt_mlo");
      wlan_cfg80211_tdls_mgmt_mlo___last_ticks_38 = v35;
    }
    _hdd_objmgr_put_vdev_by_user(
      v26,
      0x57u,
      (__int64)"wlan_cfg80211_tdls_mgmt_mlo",
      v36,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34);
    return 4294967285LL;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(v26, v27, v28, v29, v30, v31, v32, v33, v34) & 1) == 0 )
    goto LABEL_18;
  tdls_link_vdev = ucfg_tdls_get_tdls_link_vdev(v26, 0x57u);
  if ( tdls_link_vdev )
  {
    v49 = tdls_link_vdev;
    _hdd_objmgr_put_vdev_by_user(
      v26,
      0x57u,
      (__int64)"wlan_cfg80211_tdls_mgmt_mlo",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48);
    v50 = wlan_cfg80211_tdls_mgmt(v49, a2, a3, a4, a5, a6, a7, a8, a17);
    ucfg_tdls_put_tdls_link_vdev(v49, 0x57u, v51, v52, v53, v54, v55, v56, v57, v58, v59);
    return v50;
  }
  if ( a3 != 10 )
  {
    if ( a3 == 14 )
    {
      _hdd_objmgr_put_vdev_by_user(
        v26,
        0x57u,
        (__int64)"wlan_cfg80211_tdls_mgmt_mlo",
        (unsigned int *)a3,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48);
      if ( (a17 & 0x80000000) != 0 )
      {
        v143 = jiffies;
        if ( wlan_cfg80211_tdls_mgmt_mlo___last_ticks_40 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: link id is invalid",
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            "wlan_cfg80211_tdls_mgmt_mlo");
          wlan_cfg80211_tdls_mgmt_mlo___last_ticks_40 = v143;
          return 4294967274LL;
        }
      }
      else
      {
        link_vdev = wlan_key_get_link_vdev(a1, 87, a17);
        if ( link_vdev )
        {
          v77 = link_vdev;
          v78 = wlan_cfg80211_tdls_mgmt(link_vdev, a2, 0xEu, a4, a5, a6, a7, a8, a17);
          wlan_key_put_link_vdev(v77, 0x57u, v79, v80, v81, v82, v83, v84, v85, v86);
          return v78;
        }
        v144 = jiffies;
        if ( wlan_cfg80211_tdls_mgmt_mlo___last_ticks_42 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: vdev is null",
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            "wlan_cfg80211_tdls_mgmt_mlo");
          wlan_cfg80211_tdls_mgmt_mlo___last_ticks_42 = v144;
          return 4294967274LL;
        }
      }
      return 4294967274LL;
    }
LABEL_18:
    v88 = wlan_cfg80211_tdls_mgmt(v26, a2, a3, a4, a5, a6, a7, a8, a17);
LABEL_19:
    _hdd_objmgr_put_vdev_by_user(
      v26,
      0x57u,
      (__int64)"wlan_cfg80211_tdls_mgmt_mlo",
      v87,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96);
    return v88;
  }
  if ( (ucfg_tdls_discovery_on_going(v26, v41, v42, v43, v44, v45, v46, v47, v48) & 1) == 0 )
  {
    mlo_vdev = ucfg_tdls_get_mlo_vdev();
    if ( mlo_vdev )
    {
      v124 = mlo_vdev;
      if ( (ucfg_tdls_is_vdev_allowed_to_tx(mlo_vdev) & 1) != 0
        && (wlan_hdd_is_tdls_allowed(v17, v124, v126, v127, v128, v129, v130, v131, v132, v133) & 1) != 0 )
      {
        v88 = wlan_cfg80211_tdls_mgmt(v124, a2, 0xAu, a4, a5, a6, a7, a8, a17);
        ucfg_tdls_release_mlo_vdev(v124, 0x57u, v134, v135, v136, v137, v138, v139, v140, v141, v142);
        goto LABEL_36;
      }
      ucfg_tdls_release_mlo_vdev(v124, 0x57u, v125, v126, v127, v128, v129, v130, v131, v132, v133);
    }
    else
    {
      v145 = jiffies;
      if ( wlan_cfg80211_tdls_mgmt_mlo___last_ticks_45 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: mlo vdev is NULL",
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          v122,
          v123,
          "wlan_cfg80211_tdls_mgmt_mlo");
        wlan_cfg80211_tdls_mgmt_mlo___last_ticks_45 = v145;
      }
    }
    v88 = 0;
LABEL_36:
    v146 = ucfg_tdls_get_mlo_vdev();
    if ( v146 )
    {
      v147 = v146;
      if ( (ucfg_tdls_is_vdev_allowed_to_tx(v146) & 1) != 0
        && (wlan_hdd_is_tdls_allowed(v17, v147, v149, v150, v151, v152, v153, v154, v155, v156) & 1) != 0 )
      {
        v88 = wlan_cfg80211_tdls_mgmt(v147, a2, 0xAu, a4, a5, a6, a7, a8, a17);
      }
      ucfg_tdls_release_mlo_vdev(v147, 0x57u, v148, v149, v150, v151, v152, v153, v154, v155, v156);
    }
    else
    {
      v157 = jiffies;
      v87 = (unsigned int *)(wlan_cfg80211_tdls_mgmt_mlo___last_ticks_45 - jiffies);
      if ( wlan_cfg80211_tdls_mgmt_mlo___last_ticks_45 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: mlo vdev is NULL",
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          "wlan_cfg80211_tdls_mgmt_mlo");
        wlan_cfg80211_tdls_mgmt_mlo___last_ticks_45 = v157;
      }
    }
    goto LABEL_19;
  }
  _hdd_objmgr_put_vdev_by_user(
    v26,
    0x57u,
    (__int64)"wlan_cfg80211_tdls_mgmt_mlo",
    v97,
    v98,
    v99,
    v100,
    v101,
    v102,
    v103,
    v104,
    v105);
  v114 = jiffies;
  if ( wlan_cfg80211_tdls_mgmt_mlo___last_ticks_43 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: discovery request is going on vdev %d",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "wlan_cfg80211_tdls_mgmt_mlo",
      *(unsigned __int8 *)(v26 + 168));
    wlan_cfg80211_tdls_mgmt_mlo___last_ticks_43 = v114;
  }
  return 4294967285LL;
}
