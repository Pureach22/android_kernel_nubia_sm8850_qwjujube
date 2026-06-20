__int64 __fastcall cm_handle_mlo_rso_state_change(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 a4,
        char *a5)
{
  __int64 v6; // x25
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
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
  char v45; // w25
  const char *v46; // x2
  unsigned int v47; // w22
  char v48; // w0
  __int64 assoc_link_vdev; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  const char *v58; // x2
  unsigned int *v59; // x8
  unsigned int v60; // w24
  __int64 v61; // x22
  unsigned int roam_state; // w0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x0
  __int64 v72; // x1
  unsigned int v73; // w2
  __int64 v74; // x0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7

  v6 = *(_QWORD *)(a1 + 80);
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, *a2, 2u);
  if ( vdev_by_id_from_pdev )
  {
    v12 = (__int64)vdev_by_id_from_pdev;
    if ( wlan_vdev_mlme_get_is_mlo_vdev(v6, *a2) && (mlo_mgr_is_link_switch_in_progress(v12) & 1) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: MLO ROAM: Link switch in prog! skip RSO cmd:%d on vdev %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "cm_handle_mlo_rso_state_change",
        a3,
        *a2);
LABEL_33:
      v47 = 0;
LABEL_39:
      v59 = (_DWORD *)(&off_0 + 1);
      *a5 = 1;
      goto LABEL_40;
    }
    if ( wlan_vdev_mlme_get_is_mlo_vdev(v6, *a2)
      && cm_is_vdev_disconnecting(v12, v29, v30, v31, v32, v33, v34, v35, v36)
      && (a4 == 48 || a4 == 4) )
    {
      if ( (wlan_vdev_mlme_get_is_mlo_link(v6, *a2) & 1) != 0 || (wlan_is_roaming_enabled(a1, *a2) & 1) == 0 )
      {
        v45 = 1;
        v46 = "%s: MLO ROAM: skip RSO cmd:%d on assoc vdev %d";
      }
      else
      {
        v45 = 0;
        v46 = "%s: MLO ROAM: Process RSO cmd:%d on assoc vdev : %d";
      }
      qdf_trace_msg(0x68u, 8u, v46, v37, v38, v39, v40, v41, v42, v43, v44, "cm_handle_mlo_rso_state_change", a3, *a2);
      *a5 = v45;
    }
    if ( (wlan_vdev_mlme_is_mlo_vdev(v12, v29, v30, v31, v32, v33, v34, v35, v36) & 1) != 0 )
    {
      v48 = mlo_check_if_all_vdev_up(v12);
      if ( a4 == 56 && (v48 & 1) != 0 )
      {
        assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(v12);
        if ( assoc_link_vdev )
        {
          *a5 = 0;
          v58 = "%s: MLO_CSA: Send RSO on assoc vdev %d";
          *a2 = *(_BYTE *)(assoc_link_vdev + 168);
LABEL_20:
          qdf_trace_msg(0x68u, 8u, v58, v50, v51, v52, v53, v54, v55, v56, v57, "cm_handle_mlo_rso_state_change");
          v47 = 0;
LABEL_40:
          wlan_objmgr_vdev_release_ref(v12, 2u, v59, v21, v22, v23, v24, v25, v26, v27, v28);
          return v47;
        }
        goto LABEL_34;
      }
    }
    if ( (wlan_vdev_mlme_get_is_mlo_link(*(_QWORD *)(a1 + 80), *a2) & 1) == 0 )
    {
      v47 = 0;
      goto LABEL_40;
    }
    if ( (a4 & 0xFE) != 0x34 )
    {
      if ( a4 != 48 && a4 != 4 || !cm_is_vdev_disconnecting(v12, v21, v22, v23, v24, v25, v26, v27, v28) )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: MLO ROAM: skip RSO cmd on link vdev %d",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "cm_handle_mlo_rso_state_change",
          *a2);
        goto LABEL_33;
      }
      v74 = wlan_mlo_get_assoc_link_vdev(v12);
      if ( v74 )
      {
        v58 = "%s: MLO ROAM: process RSO stop on assoc vdev %d";
        *a2 = *(_BYTE *)(v74 + 168);
        *a5 = 0;
        goto LABEL_20;
      }
LABEL_34:
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Assoc vdev is NULL",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "cm_handle_mlo_rso_state_change");
      v47 = 16;
      goto LABEL_40;
    }
    v60 = *a2;
    v61 = *(_QWORD *)(a1 + 80);
    roam_state = mlme_get_roam_state(v61, *a2);
    if ( roam_state == 6 )
    {
      v71 = v61;
      v72 = v60;
      v73 = 0;
    }
    else
    {
      if ( roam_state )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: ROAM: vdev:%d MLO Roam synch not allowed in [%d] state reason:%d",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "cm_mlo_roam_switch_for_link",
          v60,
          roam_state,
          a4);
        v47 = 16;
        goto LABEL_38;
      }
      v71 = v61;
      v72 = v60;
      v73 = 6;
    }
    mlme_set_roam_state(v71, v72, v73);
    v47 = 0;
LABEL_38:
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: MLO ROAM: update rso state on link vdev %d",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "cm_handle_mlo_rso_state_change",
      *a2);
    goto LABEL_39;
  }
  return 16;
}
