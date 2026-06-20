__int64 __fastcall policy_mgr_get_connected_roaming_vdev_band_mask(__int64 a1, unsigned int a2)
{
  char is_hw_sbs_capable; // w22
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
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
  unsigned __int16 *active_channel; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x22
  char is_pcl_per_vdev_active; // w24
  char dual_sta_roaming_enabled; // w25
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
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
  unsigned int *v62; // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int v80; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v81; // [xsp+8h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v80 = 0;
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
      active_channel = (unsigned __int16 *)wlan_vdev_get_active_channel(v14);
      if ( active_channel )
      {
        v34 = 1LL << wlan_reg_freq_to_band(*active_channel);
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: no active channel",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "policy_mgr_get_connected_vdev_band_mask");
        LODWORD(v34) = 0;
      }
      is_pcl_per_vdev_active = wlan_cm_roam_is_pcl_per_vdev_active(a1, a2);
      dual_sta_roaming_enabled = wlan_mlme_get_dual_sta_roaming_enabled(a1);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: connected STA vdev_id:%d, pcl_per_vdev:%d, dual_sta_roam_active:%d",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "policy_mgr_get_connected_roaming_vdev_band_mask",
        (unsigned __int8)a2,
        is_pcl_per_vdev_active & 1,
        dual_sta_roaming_enabled & 1);
      if ( (dual_sta_roaming_enabled & 1) == 0 || (is_pcl_per_vdev_active & 1) == 0 )
      {
        ucfg_reg_get_band(*(_QWORD *)(v14 + 152), &v80, v45, v46, v47, v48, v49, v50, v51, v52);
        wlan_objmgr_vdev_release_ref(v14, 0x18u, v62, v63, v64, v65, v66, v67, v68, v69, v70);
        if ( roam_band_value != v80 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: roam_band_mask:%d",
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            "policy_mgr_get_connected_roaming_vdev_band_mask",
            roam_band_value);
          goto LABEL_18;
        }
        if ( (is_pcl_per_vdev_active & 1) == 0 )
        {
          if ( (ucfg_mlme_is_roam_intra_band(a1) & 1) != 0 )
          {
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: connected STA band mask:%d",
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              "policy_mgr_get_connected_roaming_vdev_band_mask",
              (unsigned int)v34);
            roam_band_value = v34;
            goto LABEL_18;
          }
          roam_band_value = v80;
        }
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: band_mask:%d",
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          "policy_mgr_get_connected_roaming_vdev_band_mask",
          roam_band_value);
        roam_band_value = v80;
        goto LABEL_18;
      }
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: connected vdev band mask:%d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "policy_mgr_get_connected_roaming_vdev_band_mask",
        (unsigned int)v34);
      wlan_objmgr_vdev_release_ref(v14, 0x18u, v53, v54, v55, v56, v57, v58, v59, v60, v61);
      roam_band_value = v34;
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
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return roam_band_value;
}
