__int64 __fastcall ucfg_cm_set_ese_roam_scan_channel_list(__int64 a1, unsigned int a2, unsigned int *a3, char a4)
{
  __int64 v4; // x19
  __int64 v8; // x0
  __int64 psoc_ext_obj_fl; // x0
  __int64 v11; // x25
  _QWORD *vdev_by_id_from_pdev; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  unsigned int *v22; // x8
  unsigned int roam_scan_channel_list; // w27
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 rso_config_fl; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x24
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w0
  __int64 result; // x0
  int v52; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v53; // [xsp+8h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 80);
  if ( v4 && (v8 = *(_QWORD *)(a1 + 80), v52 = 0, (psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v8)) != 0) )
  {
    v11 = psoc_ext_obj_fl;
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
    if ( vdev_by_id_from_pdev )
    {
      v21 = (__int64)vdev_by_id_from_pdev;
      roam_scan_channel_list = cm_roam_acquire_lock(
                                 (__int64)vdev_by_id_from_pdev,
                                 v13,
                                 v14,
                                 v15,
                                 v16,
                                 v17,
                                 v18,
                                 v19,
                                 v20);
      if ( !roam_scan_channel_list )
      {
        rso_config_fl = wlan_cm_get_rso_config_fl(
                          v21,
                          (__int64)"ucfg_cm_set_ese_roam_scan_channel_list",
                          0xC7u,
                          v24,
                          v25,
                          v26,
                          v27,
                          v28,
                          v29,
                          v30,
                          v31);
        if ( rso_config_fl )
        {
          v41 = rso_config_fl;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: Chan list Before",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "ucfg_cm_set_ese_roam_scan_channel_list");
          cm_dump_freq_list((unsigned __int8 *)(v41 + 840));
          ucfg_reg_get_band(a1, &v52, v42, v43, v44, v45, v46, v47, v48, v49);
          v50 = wlan_reg_band_bitmap_to_band_info(v52);
          roam_scan_channel_list = cm_create_roam_scan_channel_list(a1, v41, a4, a3, a4, v50);
          if ( !roam_scan_channel_list )
          {
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: Chan list After",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "ucfg_cm_set_ese_roam_scan_channel_list");
            cm_dump_freq_list((unsigned __int8 *)(v41 + 840));
          }
          if ( *(_BYTE *)(v11 + 1912) == 1 )
            wlan_roam_update_cfg(v4, a2, 2u);
        }
        else
        {
          roam_scan_channel_list = 16;
        }
        cm_roam_release_lock(v21, v33, v34, v35, v36, v37, v38, v39, v40);
      }
      wlan_objmgr_vdev_release_ref(v21, 0x4Du, v22, v24, v25, v26, v27, v28, v29, v30, v31);
      result = roam_scan_channel_list;
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev object is NULL",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "ucfg_cm_set_ese_roam_scan_channel_list");
      result = 4;
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
