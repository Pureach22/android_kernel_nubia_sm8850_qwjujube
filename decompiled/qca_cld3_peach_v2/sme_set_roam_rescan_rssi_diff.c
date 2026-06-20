__int64 __fastcall sme_set_roam_rescan_rssi_diff(_QWORD *a1, unsigned int a2, unsigned __int8 a3)
{
  int v5; // w23
  __int64 v7; // x0
  _QWORD *vdev_by_id_from_pdev; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x22
  __int64 rso_config_fl; // x0
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int *v28; // x8
  __int64 result; // x0
  unsigned int updated; // w20
  unsigned int v31[4]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v32; // [xsp+18h] [xbp-18h]
  __int64 v33; // [xsp+20h] [xbp-10h]
  __int64 v34; // [xsp+28h] [xbp-8h]

  v5 = a3;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a1[2704];
  v32 = 0;
  v33 = 0;
  v31[0] = 0;
  v31[3] = 0;
  *(_QWORD *)&v31[1] = a3;
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v7, a2, 0xBu);
  if ( !vdev_by_id_from_pdev )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: vdev object is NULL for vdev %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "sme_set_roam_rescan_rssi_diff",
      (unsigned __int8)a2);
LABEL_12:
    result = 4;
    goto LABEL_13;
  }
  v17 = (__int64)vdev_by_id_from_pdev;
  rso_config_fl = wlan_cm_get_rso_config_fl(
                    (__int64)vdev_by_id_from_pdev,
                    (__int64)"sme_set_roam_rescan_rssi_diff",
                    0x1BB4u,
                    v9,
                    v10,
                    v11,
                    v12,
                    v13,
                    v14,
                    v15,
                    v16);
  if ( !rso_config_fl )
  {
    wlan_objmgr_vdev_release_ref(v17, 0xBu, v19, v20, v21, v22, v23, v24, v25, v26, v27);
    goto LABEL_12;
  }
  v28 = (unsigned int *)*(unsigned __int8 *)(rso_config_fl + 1383);
  if ( (_DWORD)v28 == 1 )
  {
    v28 = (unsigned int *)*(unsigned __int8 *)(rso_config_fl + 92);
    if ( ((unsigned __int8)v28 & 1) == 0 )
      wlan_cm_roam_cfg_set_value(a1[2703], a2, 0x23u, v31);
  }
  wlan_objmgr_vdev_release_ref(v17, 0xBu, v28, v20, v21, v22, v23, v24, v25, v26, v27);
  result = qdf_mutex_acquire((__int64)(a1 + 1606));
  if ( !(_DWORD)result )
  {
    updated = cm_neighbor_roam_update_config(a1[2704], a2, a3, 0x13u);
    if ( !updated )
      *(_DWORD *)(a1[1] + 1932LL) = v5;
    qdf_mutex_release((__int64)(a1 + 1606));
    result = updated;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
