__int64 __fastcall cm_roam_switch_to_init(__int64 a1, unsigned int a2, char a3)
{
  __int64 v3; // x20
  __int64 v7; // x0
  int dual_sta_roaming_enabled; // w21
  int v9; // w22
  unsigned int roam_state; // w24
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x23
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 result; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  const char *v56; // x2
  __int64 v57; // x4
  unsigned int v58; // w24
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  char is_primary_interface_configured; // w0
  unsigned int *v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  _BYTE v77[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v78; // [xsp+8h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 80);
  if ( !v3 || (v7 = *(_QWORD *)(a1 + 80), v77[0] = 0, !mlme_get_psoc_ext_obj_fl(v7)) )
  {
    result = 16;
    goto LABEL_20;
  }
  dual_sta_roaming_enabled = wlan_mlme_get_dual_sta_roaming_enabled(v3);
  v9 = policy_mgr_concurrent_sta_on_different_mac(v3);
  roam_state = mlme_get_roam_state(v3, a2);
  qdf_trace_msg(
    0x68u,
    4u,
    "%s: dual_sta_roam_active:%d, sta concurrency on different mac:%d, state:%d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "cm_roam_switch_to_init",
    dual_sta_roaming_enabled & 1,
    v9 & 1,
    roam_state);
  if ( roam_state == 5 )
  {
    mlme_set_roam_state(v3, a2, 1u);
    goto LABEL_19;
  }
  if ( roam_state )
  {
LABEL_19:
    result = 0;
    goto LABEL_20;
  }
  if ( !(unsigned int)mlme_get_roam_trigger_bitmap(v3, a2) )
  {
    v56 = "%s: CM_RSO: Cannot change to INIT state for vdev[%d]";
    v57 = (unsigned __int8)a2;
    goto LABEL_22;
  }
  if ( (dual_sta_roaming_enabled & v9 & 1) != 0 )
  {
    v27 = "%s: sta concurrency on different mac";
LABEL_8:
    qdf_trace_msg(0x68u, 4u, v27, v19, v20, v21, v22, v23, v24, v25, v26, "cm_roam_switch_to_init");
    goto LABEL_9;
  }
  v58 = (unsigned __int8)((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_get_roam_enabled_sta_session_id)(v3, a2);
  if ( !(dual_sta_roaming_enabled & 1 | (v58 == 255)) )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Do not enable RSO on %d, RSO is enabled on %d",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "cm_roam_switch_to_init",
      (unsigned __int8)a2,
      v58);
    result = 16;
    goto LABEL_20;
  }
  is_primary_interface_configured = wlan_mlme_is_primary_interface_configured(v3);
  if ( a3 != 46 && (is_primary_interface_configured & 1) != 0 )
  {
    v27 = "%s: STA + STA concurrency with a primary iface, have roaming enabled on both interfaces";
    goto LABEL_8;
  }
  if ( v58 != 255 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Interface vdev_id: %d, roaming enabled on vdev_id: %d, reason:%d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "cm_roam_switch_to_init",
      (unsigned __int8)a2,
      v58);
    if ( a3 == 46 )
    {
      cm_roam_state_change(a1, v58, 0, 0x2Eu, 0, 0);
      goto LABEL_9;
    }
    v56 = "%s: CM_RSO: Roam module already initialized on vdev:[%d]";
    v57 = v58;
LABEL_22:
    qdf_trace_msg(0x68u, 4u, v56, v19, v20, v21, v22, v23, v24, v25, v26, "cm_roam_switch_to_init", v57);
    result = 16;
    goto LABEL_20;
  }
LABEL_9:
  v28 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v3, a2, 2);
  if ( !v28 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: CM_RSO: vdev:%d is null",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "cm_roam_switch_to_init",
      (unsigned __int8)a2);
    result = 4;
    goto LABEL_20;
  }
  v37 = v28;
  if ( !cm_is_vdev_connected(v28, v29, v30, v31, v32, v33, v34, v35, v36) )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: CM_RSO: vdev:%d RSO Init received in non-connected state",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "cm_roam_switch_to_init",
      (unsigned __int8)a2);
    wlan_objmgr_vdev_release_ref(v37, 2u, v68, v69, v70, v71, v72, v73, v74, v75, v76);
    result = 4;
    goto LABEL_20;
  }
  wlan_objmgr_vdev_release_ref(v37, 2u, v38, v39, v40, v41, v42, v43, v44, v45, v46);
  result = cm_roam_init_req(v3, a2, 1);
  if ( !(_DWORD)result )
  {
    mlme_set_roam_state(v3, a2, 1u);
    if ( (dual_sta_roaming_enabled
        & v9
        & ((unsigned __int8)((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_get_roam_enabled_sta_session_id)(
                              v3,
                              a2) != 0xFF)) == 1 )
      wlan_cm_roam_activate_pcl_per_vdev(v3, a2, 1);
    policy_mgr_set_pcl_for_existing_combo(v3, 0, a2);
    wlan_mlme_get_usr_disabled_roaming(v3, v77);
    result = 0;
    if ( v77[0] == 1 )
    {
      result = cm_roam_send_disable_config(v3, a2, 1);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: ROAM: fast roaming disable failed. status %d",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "cm_roam_switch_to_init",
          (unsigned int)result);
        goto LABEL_19;
      }
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
