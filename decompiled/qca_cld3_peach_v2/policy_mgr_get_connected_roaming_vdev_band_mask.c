__int64 __fastcall policy_mgr_get_connected_roaming_vdev_band_mask(__int64 a1, unsigned int a2)
{
  char is_hw_sbs_capable; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x22
  unsigned int *v15; // x8
  unsigned int roam_band_value; // w19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int connected_vdev_band_mask; // w21
  char is_pcl_per_vdev_active; // w24
  char dual_sta_roaming_enabled; // w25
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
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int *v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int v71; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v72; // [xsp+8h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71 = 0;
  is_hw_sbs_capable = policy_mgr_is_hw_sbs_capable(a1);
  v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v5 )
  {
    v14 = v5;
    roam_band_value = wlan_cm_get_roam_band_value(a1, v5);
    if ( (is_hw_sbs_capable & 1) != 0 )
    {
      wlan_objmgr_vdev_release_ref(v14, 0x18u, v15, v17, v18, v19, v20, v21, v22, v23, v24);
    }
    else
    {
      connected_vdev_band_mask = policy_mgr_get_connected_vdev_band_mask(v14, v17, v18, v19, v20, v21, v22, v23, v24);
      is_pcl_per_vdev_active = wlan_cm_roam_is_pcl_per_vdev_active(a1, a2);
      dual_sta_roaming_enabled = wlan_mlme_get_dual_sta_roaming_enabled(a1);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: connected STA vdev_id:%d, pcl_per_vdev:%d, dual_sta_roam_active:%d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "policy_mgr_get_connected_roaming_vdev_band_mask",
        (unsigned __int8)a2,
        is_pcl_per_vdev_active & 1,
        dual_sta_roaming_enabled & 1);
      if ( (dual_sta_roaming_enabled & 1) == 0 || (is_pcl_per_vdev_active & 1) == 0 )
      {
        ucfg_reg_get_band(*(_QWORD *)(v14 + 216), &v71, v36, v37, v38, v39, v40, v41, v42, v43);
        wlan_objmgr_vdev_release_ref(v14, 0x18u, v53, v54, v55, v56, v57, v58, v59, v60, v61);
        if ( roam_band_value != v71 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: roam_band_mask:%d",
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            "policy_mgr_get_connected_roaming_vdev_band_mask",
            roam_band_value);
          goto LABEL_15;
        }
        if ( (is_pcl_per_vdev_active & 1) == 0 )
        {
          if ( (ucfg_mlme_is_roam_intra_band(a1) & 1) != 0 )
          {
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: connected STA band mask:%d",
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              "policy_mgr_get_connected_roaming_vdev_band_mask",
              connected_vdev_band_mask);
            roam_band_value = connected_vdev_band_mask;
            goto LABEL_15;
          }
          roam_band_value = v71;
        }
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: band_mask:%d",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "policy_mgr_get_connected_roaming_vdev_band_mask",
          roam_band_value);
        roam_band_value = v71;
        goto LABEL_15;
      }
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: connected vdev band mask:%d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "policy_mgr_get_connected_roaming_vdev_band_mask",
        connected_vdev_band_mask);
      wlan_objmgr_vdev_release_ref(v14, 0x18u, v44, v45, v46, v47, v48, v49, v50, v51, v52);
      roam_band_value = connected_vdev_band_mask;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: vdev is NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_get_connected_roaming_vdev_band_mask");
    roam_band_value = 0;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return roam_band_value;
}
