__int64 __fastcall cm_roam_start_init_on_connect(__int64 result, unsigned __int8 a2)
{
  __int64 v2; // x21
  __int64 v3; // x20
  _QWORD *vdev_by_id_from_pdev; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  int v15; // w4
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w22
  __int64 psoc_ext_obj_fl; // x0
  __int64 v27; // x23
  int v28; // w25
  int param; // w24
  char v30; // w8
  __int64 v31; // [xsp+8h] [xbp-28h] BYREF
  __int64 v32; // [xsp+10h] [xbp-20h]
  __int64 v33; // [xsp+18h] [xbp-18h]
  __int64 v34; // [xsp+20h] [xbp-10h]
  __int64 v35; // [xsp+28h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 80);
  if ( v2 )
  {
    v3 = result;
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(result, a2, 0x4Du);
    if ( !vdev_by_id_from_pdev )
    {
      result = qdf_trace_msg(
                 0x68u,
                 2u,
                 "%s: vdev_id: %d: vdev not found",
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 "cm_roam_start_init_on_connect",
                 a2);
      goto LABEL_7;
    }
    v33 = 0;
    v34 = 0;
    v14 = (__int64)vdev_by_id_from_pdev;
    v15 = *((_DWORD *)vdev_by_id_from_pdev + 4);
    v31 = 0;
    v32 = 0;
    if ( v15 )
    {
      qdf_trace_msg(0x68u, 8u, "%s: Wrong opmode %d", v6, v7, v8, v9, v10, v11, v12, v13, "cm_roam_start_init");
LABEL_5:
      result = wlan_objmgr_vdev_release_ref(v14, 0x4Du, v16, v17, v18, v19, v20, v21, v22, v23, v24);
      goto LABEL_7;
    }
    v25 = *((unsigned __int8 *)vdev_by_id_from_pdev + 104);
    psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v2);
    if ( !psoc_ext_obj_fl )
      goto LABEL_5;
    v27 = psoc_ext_obj_fl;
    wlan_cm_init_occupied_ch_freq_list(v3, v2, v25);
    LODWORD(v31) = *(_DWORD *)(v27 + 1728);
    wlan_cm_roam_cfg_set_value(v2, v25, 0, &v31);
    HIDWORD(v31) = *(_DWORD *)(v27 + 2564);
    wlan_cm_roam_cfg_set_value(v2, v25, 35, &v31);
    LODWORD(v31) = *(_DWORD *)(v27 + 1764);
    wlan_cm_roam_cfg_set_value(v2, v25, 2, &v31);
    wlan_cm_update_roam_scan_scheme_bitmap(v2, v25, 0);
    wlan_cm_roam_cfg_get_value(v2, v25, 20, (int)&v31);
    v28 = (unsigned __int8)v32;
    param = wlan_crypto_get_param(v14, 7u);
    if ( wlan_vdev_is_open_mode(v14) )
    {
      if ( !v28 || (*(_BYTE *)(v27 + 1896) & 1) == 0 )
        goto LABEL_12;
    }
    else if ( (param & 0x11300860) == 0 )
    {
LABEL_12:
      v30 = 0;
LABEL_15:
      LOBYTE(v32) = v30;
      wlan_cm_roam_cfg_set_value(v2, v25, 21, &v31);
      LODWORD(v31) = *(unsigned __int8 *)(v27 + 1705);
      wlan_cm_roam_cfg_set_value(v2, v25, 29, &v31);
      LODWORD(v31) = *(unsigned __int8 *)(v27 + 1706);
      wlan_cm_roam_cfg_set_value(v2, v25, 30, &v31);
      v16 = (unsigned int *)*(unsigned __int8 *)(v27 + 1708);
      if ( (_DWORD)v16 == 1 )
      {
        LODWORD(v31) = *(_DWORD *)(v27 + 3440);
        wlan_cm_roam_cfg_set_value(v2, v25, 37, &v31);
        LODWORD(v31) = *(_DWORD *)(v27 + 3444);
        wlan_cm_roam_cfg_set_value(v2, v25, 38, &v31);
        LODWORD(v31) = *(_DWORD *)(v27 + 3448);
        wlan_cm_roam_cfg_set_value(v2, v25, 39, &v31);
        LODWORD(v31) = *(_DWORD *)(v27 + 1728);
        wlan_cm_roam_cfg_set_value(v2, v25, 40, &v31);
        LODWORD(v31) = *(_DWORD *)(v27 + 2572);
        wlan_cm_roam_cfg_set_value(v2, v25, 41, &v31);
        LODWORD(v31) = *(_DWORD *)(v27 + 3420);
        wlan_cm_roam_cfg_set_value(v2, v25, 42, &v31);
        LODWORD(v31) = *(_DWORD *)(v27 + 3428);
        wlan_cm_roam_cfg_set_value(v2, v25, 44, &v31);
        LODWORD(v31) = *(_DWORD *)(v27 + 1556);
        wlan_cm_roam_cfg_set_value(v2, v25, 45, &v31);
        cm_store_sae_single_pmk_to_global_cache(v2, v3, v14);
        if ( (unsigned int)mlme_get_roam_state(v2, v25) != 5 )
        {
          wlan_clear_sae_auth_logs_cache(v2, v25);
          wlan_cm_roam_state_change(v3, v25, 2, 40);
        }
      }
      goto LABEL_5;
    }
    v30 = 1;
    goto LABEL_15;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
