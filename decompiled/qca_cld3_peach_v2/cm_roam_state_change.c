__int64 __fastcall cm_roam_state_change(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        char a6)
{
  __int64 v6; // x24
  unsigned int v10; // w21
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x25
  unsigned int *v23; // x8
  char v24; // w23
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w27
  _QWORD *vdev_by_id_from_pdev; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x25
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int *v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  const char *v70; // x2
  __int64 v71; // x4
  unsigned int v72; // w0
  char roam_state; // w0
  __int64 v74; // x25
  char v75; // w24
  char v76; // w26
  unsigned __int8 rso_disabled_bitmap; // w28
  char supplicant_disabled_roaming; // w25
  char v79; // w0
  int v80; // w8
  int v81; // w7
  __int64 v82; // [xsp+0h] [xbp-10h] BYREF
  __int64 v83; // [xsp+8h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 80);
  BYTE4(v82) = a2;
  LOBYTE(v82) = 0;
  if ( !v6 )
  {
    result = 4;
    goto LABEL_46;
  }
  v10 = a2;
  result = (__int64)wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 2u);
  if ( result )
  {
    v22 = result;
    if ( (wlan_vdev_mlme_is_mlo_vdev(result, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
      v24 = mlo_check_if_all_vdev_up(v22);
    else
      v24 = (unsigned int)wlan_vdev_is_up() == 0;
    wlan_objmgr_vdev_release_ref(v22, 2u, v23, v25, v26, v27, v28, v29, v30, v31, v32);
    if ( !a3 || a3 == 3 )
      goto LABEL_9;
    if ( (v24 & 1) != 0 )
    {
      if ( a3 != 2
        || (policy_mgr_is_chan_switch_in_progress(v6) & 1) == 0
        && !policy_mgr_is_conc_sap_ready_for_mcc_to_scc_trans(v6) )
      {
LABEL_9:
        result = cm_handle_mlo_rso_state_change(a1, (char *)&v82 + 4, a3, a4, &v82);
        if ( (v82 & 1) != 0 )
          goto LABEL_46;
        v10 = BYTE4(v82);
        v41 = result;
        vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, SBYTE4(v82), 0x4Du);
        if ( vdev_by_id_from_pdev )
        {
          v51 = (__int64)vdev_by_id_from_pdev;
          v52 = cm_roam_acquire_lock();
          if ( v52 )
          {
            v41 = v52;
            qdf_trace_msg(
              0x68u,
              2u,
              "%s: Fail to acquire lock, status: %d",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "cm_roam_state_change");
LABEL_37:
            wlan_objmgr_vdev_release_ref(v51, 0x4Du, v61, v62, v63, v64, v65, v66, v67, v68, v69);
            goto LABEL_38;
          }
          if ( (int)a3 > 2 )
          {
            switch ( a3 )
            {
              case 3u:
                v72 = cm_roam_switch_to_rso_stop(a1, v10, a4, a5, a6 & 1);
                goto LABEL_35;
              case 4u:
                v72 = cm_roam_switch_to_roam_start(a1, v10);
                goto LABEL_35;
              case 5u:
                v72 = cm_roam_switch_to_roam_sync(a1, v10);
                goto LABEL_35;
            }
          }
          else
          {
            switch ( a3 )
            {
              case 0u:
                v72 = cm_roam_switch_to_deinit(a1, v10, a4);
                goto LABEL_35;
              case 1u:
                v72 = cm_roam_switch_to_init(a1, v10, a4);
                goto LABEL_35;
              case 2u:
                v72 = cm_roam_switch_to_rso_enable(a1, v10, a4);
LABEL_35:
                v41 = v72;
                goto LABEL_36;
            }
          }
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: ROAM: Invalid roam state %d",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "cm_roam_state_change",
            a3,
            v82,
            v83);
          v41 = 0;
LABEL_36:
          v62 = cm_roam_release_lock(v51);
          goto LABEL_37;
        }
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: Invalid vdev:%d",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "cm_roam_state_change",
          v10);
LABEL_38:
        roam_state = mlme_get_roam_state(v6, v10);
        v74 = *(_QWORD *)(a1 + 80);
        if ( v74 )
        {
          v75 = roam_state;
          v76 = mlme_get_roam_state(*(_QWORD *)(a1 + 80), v10);
          rso_disabled_bitmap = mlme_get_rso_disabled_bitmap(v74, v10);
          supplicant_disabled_roaming = mlme_get_supplicant_disabled_roaming(v74, v10);
          v79 = wlan_cm_roaming_in_progress(a1, v10);
          v80 = v24 & 1 | 2;
          if ( (supplicant_disabled_roaming & 1) == 0 )
            v80 = v24 & 1;
          if ( (v79 & 1) != 0 )
            v81 = v80 | 4;
          else
            v81 = v80;
          wlan_rec_debug_log(
            (char *)&off_0 + 1,
            v10,
            0x19u,
            0,
            nullptr,
            0,
            a3 & 0xF | ((unsigned __int8)v41 << 12) | (unsigned __int8)(16 * (v75 & 0xF)) | ((v76 & 0xF) << 8),
            v81 & 0xFFF80007 | (8 * rso_disabled_bitmap) & 0x7FF | ((unsigned __int8)a4 << 11));
        }
        result = v41;
        goto LABEL_46;
      }
      v70 = "%s: ROAM: roam state(%d) change requested when a concurrent SAP is in MCC or CSA is in progress";
      v71 = 2;
    }
    else
    {
      v70 = "%s: ROAM: roam state(%d) change requested in non-connected state";
      v71 = a3;
    }
    qdf_trace_msg(0x68u, 8u, v70, v33, v34, v35, v36, v37, v38, v39, v40, "cm_roam_state_change", v71, v82, v83);
    v41 = 0;
    goto LABEL_38;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
