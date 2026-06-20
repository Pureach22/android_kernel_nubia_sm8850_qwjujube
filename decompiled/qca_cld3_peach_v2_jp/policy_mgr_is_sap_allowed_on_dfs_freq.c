__int64 __fastcall policy_mgr_is_sap_allowed_on_dfs_freq(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x19
  bool is_sta_sap_scc_allowed_on_dfs_chan; // w22
  unsigned int mode_specific_conn_info; // w21
  __int64 result; // x0
  unsigned int v18; // w25
  unsigned int v19; // w22
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
  int channel_state_for_pwrmode; // w0
  bool v37; // zf
  unsigned int v38; // w8
  __int64 context; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x23
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  const char *v57; // x2
  __int64 v58; // x0
  __int64 v59; // x23
  unsigned int *v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w21
  __int64 v70; // x0
  __int64 v71; // x20
  unsigned int *v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned __int8 *v81; // x8
  unsigned int *v82; // x8
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // x0
  unsigned int *v92; // x8
  unsigned int *v93; // x8
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x0
  unsigned int *v103; // x8
  __int64 v104; // x0
  unsigned int *v105; // x8
  __int64 v106; // x0
  unsigned int *v107; // x8
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // [xsp+0h] [xbp-10h] BYREF
  __int64 v117; // [xsp+8h] [xbp-8h]

  v117 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v116) = 0;
  LODWORD(v116) = 0;
  if ( (wlan_reg_is_dfs_for_freq(a1, a3, a4, a5, a6, a7, a8, a9, a10, a11) & 1) == 0 )
    goto LABEL_30;
  v14 = *(_QWORD *)(a1 + 80);
  if ( !v14 )
  {
LABEL_24:
    result = 0;
    goto LABEL_31;
  }
  is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(*(_QWORD *)(a1 + 80));
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(v14, 0, (unsigned __int64)&v116, 0);
  result = 0;
  if ( mode_specific_conn_info <= 4 )
  {
    v18 = is_sta_sap_scc_allowed_on_dfs_chan;
    v19 = policy_mgr_get_mode_specific_conn_info(v14, 0, (unsigned __int64)&v116 + mode_specific_conn_info, 2u);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: sta_sap_scc_on_dfs_chan %u, sta_cnt %u, gc_cnt %u",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "policy_mgr_is_sap_allowed_on_dfs_freq",
      v18,
      mode_specific_conn_info,
      v19);
    channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                  a1,
                                  a3,
                                  0,
                                  v28,
                                  v29,
                                  v30,
                                  v31,
                                  v32,
                                  v33,
                                  v34,
                                  v35);
    if ( v19 | mode_specific_conn_info )
      v37 = 0;
    else
      v37 = channel_state_for_pwrmode == 2;
    if ( v37 )
      v38 = v18;
    else
      v38 = 0;
    if ( v38 == 1 )
    {
      context = policy_mgr_get_context(v14);
      if ( context )
      {
        if ( *(_BYTE *)(context + 2661) == 1 )
        {
          v48 = context;
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: sta_sap_scc_on_dfs_chnl %d enable %d",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "policy_mgr_get_dfs_master_dynamic_enabled",
            *(unsigned __int8 *)(context + 2212),
            0);
          if ( (*(_BYTE *)(v48 + 2661) & 1) != 0 )
          {
            v57 = "%s: SAP not allowed on DFS channel if no dfs master capability!!";
LABEL_45:
            qdf_trace_msg(
              0x4Fu,
              2u,
              v57,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              "policy_mgr_is_sap_allowed_on_dfs_freq",
              v116,
              v117);
            result = 0;
            goto LABEL_31;
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: pm_ctx is NULL",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "policy_mgr_get_dfs_master_dynamic_enabled");
      }
    }
    v58 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v14, a2, 24);
    if ( v58 )
    {
      v59 = v58;
      if ( !(unsigned int)wlan_vdev_mlme_is_init_state(v58) && !(unsigned int)wlan_vdev_is_up_active_state(v59) )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: SAP is not yet UP: vdev %d",
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          "policy_mgr_is_sap_allowed_on_dfs_freq",
          (unsigned __int8)a2);
        wlan_objmgr_vdev_release_ref(v59, 0x18u, v93, v94, v95, v96, v97, v98, v99, v100, v101);
        goto LABEL_30;
      }
      wlan_objmgr_vdev_release_ref(v59, 0x18u, v60, v61, v62, v63, v64, v65, v66, v67, v68);
      v69 = v19 + mode_specific_conn_info;
      if ( !v69 )
        goto LABEL_30;
      v70 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              v14,
              (unsigned __int8)v116,
              24);
      if ( !v70 )
        goto LABEL_44;
      v71 = v70;
      if ( wlan_cm_is_vdev_disconnecting(v70, v49, v50, v51, v52, v53, v54, v55, v56) )
      {
        v81 = (unsigned __int8 *)&v116;
LABEL_23:
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: SAP is not allowed to move to DFS channel at this time, vdev %d",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          "policy_mgr_is_sap_allowed_on_dfs_freq",
          *v81,
          v116,
          v117);
        wlan_objmgr_vdev_release_ref(v71, 0x18u, v82, v83, v84, v85, v86, v87, v88, v89, v90);
        goto LABEL_24;
      }
      wlan_objmgr_vdev_release_ref(v71, 0x18u, v72, v73, v74, v75, v76, v77, v78, v79, v80);
      if ( v69 == 1 )
        goto LABEL_30;
      v91 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              v14,
              BYTE1(v116),
              24);
      if ( !v91 )
        goto LABEL_44;
      v71 = v91;
      if ( wlan_cm_is_vdev_disconnecting(v91, v49, v50, v51, v52, v53, v54, v55, v56) )
      {
        v81 = (unsigned __int8 *)&v116 + 1;
        goto LABEL_23;
      }
      wlan_objmgr_vdev_release_ref(v71, 0x18u, v92, v73, v74, v75, v76, v77, v78, v79, v80);
      if ( v69 == 2 )
        goto LABEL_30;
      v102 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               v14,
               BYTE2(v116),
               24);
      if ( !v102 )
        goto LABEL_44;
      v71 = v102;
      if ( wlan_cm_is_vdev_disconnecting(v102, v49, v50, v51, v52, v53, v54, v55, v56) )
      {
        v81 = (unsigned __int8 *)&v116 + 2;
        goto LABEL_23;
      }
      wlan_objmgr_vdev_release_ref(v71, 0x18u, v103, v73, v74, v75, v76, v77, v78, v79, v80);
      if ( v69 == 3 )
        goto LABEL_30;
      v104 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               v14,
               BYTE3(v116),
               24);
      if ( !v104 )
        goto LABEL_44;
      v71 = v104;
      if ( wlan_cm_is_vdev_disconnecting(v104, v49, v50, v51, v52, v53, v54, v55, v56) )
      {
        v81 = (unsigned __int8 *)&v116 + 3;
        goto LABEL_23;
      }
      wlan_objmgr_vdev_release_ref(v71, 0x18u, v105, v73, v74, v75, v76, v77, v78, v79, v80);
      if ( v69 == 4 )
      {
LABEL_30:
        result = 1;
        goto LABEL_31;
      }
      v106 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               v14,
               BYTE4(v116),
               24);
      if ( v106 )
      {
        v71 = v106;
        if ( wlan_cm_is_vdev_disconnecting(v106, v49, v50, v51, v52, v53, v54, v55, v56) )
        {
          v81 = (unsigned __int8 *)&v116 + 4;
          goto LABEL_23;
        }
        wlan_objmgr_vdev_release_ref(v71, 0x18u, v107, v73, v74, v75, v76, v77, v78, v79, v80);
        if ( v69 != 5 )
        {
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: idx:%u is out of bounds",
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            v115,
            "policy_mgr_is_sap_allowed_on_dfs_freq",
            5);
          result = 0;
          goto LABEL_31;
        }
        goto LABEL_30;
      }
    }
LABEL_44:
    v57 = "%s: Invalid vdev";
    goto LABEL_45;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
