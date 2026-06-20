__int64 __fastcall ucfg_cm_reset_key(__int64 a1, unsigned __int8 a2)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 rso_config_fl; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20

  wlan_cm_set_psk_pmk(a1, a2, nullptr, 0);
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
  if ( !vdev_by_id_from_pdev )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev object is NULL for vdev %d",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "ucfg_cm_reset_esecckm_info",
             a2);
  v13 = (__int64)vdev_by_id_from_pdev;
  rso_config_fl = wlan_cm_get_rso_config_fl(
                    (__int64)vdev_by_id_from_pdev,
                    (__int64)"ucfg_cm_reset_esecckm_info",
                    0x1EFu,
                    v5,
                    v6,
                    v7,
                    v8,
                    v9,
                    v10,
                    v11,
                    v12);
  if ( rso_config_fl )
  {
    v24 = rso_config_fl;
    qdf_mem_set((void *)(rso_config_fl + 679), 0x10u, 0);
    qdf_mem_set((void *)(v24 + 695), 0x20u, 0);
    *(_BYTE *)(v24 + 678) = 0;
  }
  return wlan_objmgr_vdev_release_ref(v13, 0x4Du, v15, v16, v17, v18, v19, v20, v21, v22, v23);
}
