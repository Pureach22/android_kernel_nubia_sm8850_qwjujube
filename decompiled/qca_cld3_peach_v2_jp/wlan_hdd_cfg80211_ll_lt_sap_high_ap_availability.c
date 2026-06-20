__int64 __fastcall wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  int v10; // w1
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x23
  __int64 *v20; // x22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
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
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x20
  __int64 v63; // x0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x20
  __int64 v73; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // x8
  const char *v99; // x2
  unsigned int *v100; // x8
  unsigned int v101; // w19
  __int64 v102; // x2
  __int64 v103; // x21
  __int64 v104; // x3
  __int64 v105; // [xsp+8h] [xbp-68h] BYREF
  _QWORD v106[2]; // [xsp+10h] [xbp-60h] BYREF
  __int64 v107; // [xsp+20h] [xbp-50h]
  __int64 v108; // [xsp+28h] [xbp-48h]
  __int64 v109; // [xsp+30h] [xbp-40h]
  __int64 v110; // [xsp+38h] [xbp-38h]
  unsigned int v111; // [xsp+40h] [xbp-30h] BYREF
  unsigned __int8 v112[4]; // [xsp+44h] [xbp-2Ch] BYREF
  __int64 v113; // [xsp+48h] [xbp-28h] BYREF
  __int64 v114; // [xsp+50h] [xbp-20h]
  __int64 v115; // [xsp+58h] [xbp-18h]
  __int64 v116; // [xsp+60h] [xbp-10h]
  __int64 v117; // [xsp+68h] [xbp-8h]

  v117 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v105 = 0;
  result = _osif_vdev_sync_op_start(v8, &v105, "wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability");
  if ( (_DWORD)result )
    goto LABEL_8;
  if ( a1 )
  {
    v19 = *(_QWORD *)(a2 + 32);
    v20 = (__int64 *)(a1 + 1536);
    v115 = 0;
    v116 = 0;
    v113 = 0;
    v114 = 0;
    v112[0] = -1;
    v111 = 0;
    v109 = 0;
    v110 = 0;
    v107 = 0;
    v108 = 0;
    v106[1] = 0;
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
      "__wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability",
      v19 + 296);
    if ( (unsigned int)_wlan_hdd_validate_context(
                         a1 + 1536,
                         (__int64)"__wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability",
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27,
                         v28)
      || (unsigned int)_hdd_validate_adapter(
                         v19 + 2688,
                         (__int64)"__wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability",
                         v29,
                         v30,
                         v31,
                         v32,
                         v33,
                         v34,
                         v35,
                         v36)
      || (unsigned int)_wlan_hdd_validate_vdev_id(
                         *(_BYTE *)(*(_QWORD *)(v19 + 55512) + 8LL),
                         (__int64)"__wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability",
                         v37,
                         v38,
                         v39,
                         v40,
                         v41,
                         v42,
                         v43,
                         v44) )
    {
      goto LABEL_6;
    }
    if ( !policy_mgr_is_vdev_ll_lt_sap(*v20, *(unsigned __int8 *)(*(_QWORD *)(v19 + 55512) + 8LL)) )
    {
      v62 = jiffies;
      if ( _wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Command not allowed on vdev %d",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "__wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability",
          *(unsigned __int8 *)(*(_QWORD *)(v19 + 55512) + 8LL));
        _wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability___last_ticks = v62;
      }
      goto LABEL_6;
    }
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "__wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability");
      v45 = -1;
      goto LABEL_7;
    }
    if ( (hdd_is_chan_switch_in_progress(v54, v55, v56, v57, v58, v59, v60, v61) & 1) != 0 )
    {
      v45 = -11;
      goto LABEL_7;
    }
    v63 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            *v20,
            *(unsigned __int8 *)(*(_QWORD *)(v19 + 55512) + 8LL),
            105);
    if ( !v63 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: vdev %d not found",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "__wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability",
        *(unsigned __int8 *)(*(_QWORD *)(v19 + 55512) + 8LL));
LABEL_6:
      v45 = -22;
LABEL_7:
      _osif_vdev_sync_op_stop(v105, "wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability");
      result = v45;
LABEL_8:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v72 = v63;
    v109 = v63;
    v73 = *v20;
    BYTE4(v107) = 0;
    v106[0] = 32;
    if ( (wlan_serialization_is_cmd_present_in_active_queue(
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v73,
            (unsigned int *)v106)
        & 1) == 0
      && (hdd_is_connection_in_progress(v112, &v111, v74, v75, v76, v77, v78, v79, v80, v81) & 1) != 0
      && !policy_mgr_is_vdev_ll_lt_sap(*v20, v112[0]) )
    {
      v103 = jiffies;
      v100 = (unsigned int *)(_wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability___last_ticks_7 - jiffies);
      if ( _wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability___last_ticks_7 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: connection in progress vdev %d reason %d",
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          "__wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability",
          v112[0],
          v111);
        _wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability___last_ticks_7 = v103;
      }
      v101 = 8;
      goto LABEL_36;
    }
    if ( (unsigned int)_nla_parse(&v113, 3, a3, a4, &wlan_hdd_ll_lt_sap_high_ap_availability_policy, 31, 0) )
    {
      v98 = *(_QWORD *)(v19 + 55512);
      v99 = "%s: vdev %d Invalid attribute";
    }
    else
    {
      if ( v114 )
      {
        if ( v116 )
          v102 = *(unsigned int *)(v116 + 4);
        else
          v102 = 0;
        if ( v115 )
          v104 = *(unsigned int *)(v115 + 4);
        else
          v104 = 0xFFFF;
        v101 = osif_ll_lt_sap_high_ap_availability(v72, *(unsigned __int8 *)(v114 + 4), v102, v104);
        goto LABEL_36;
      }
      v98 = *(_QWORD *)(v19 + 55512);
      v99 = "%s: Vdev %d attr high ap availability operation failed";
    }
    qdf_trace_msg(
      0x33u,
      2u,
      v99,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      "__wlan_hdd_cfg80211_ll_lt_sap_high_ap_availability",
      *(unsigned __int8 *)(v98 + 8));
    v101 = 4;
LABEL_36:
    wlan_objmgr_vdev_release_ref(v72, 0x69u, v100, v82, v83, v84, v85, v86, v87, v88, v89);
    v45 = qdf_status_to_os_return(v101);
    goto LABEL_7;
  }
  __break(0x800u);
  if ( v10 )
    JUMPOUT(0x3D2528);
  return wlan_hdd_ll_lt_sap_get_csa_timestamp();
}
