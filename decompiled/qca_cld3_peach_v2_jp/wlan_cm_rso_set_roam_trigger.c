__int64 __fastcall wlan_cm_rso_set_roam_trigger(__int64 a1, unsigned int a2, unsigned int *a3)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int *v15; // x8
  unsigned int v16; // w20
  __int64 v17; // x19
  __int64 ext_hdl_fl; // x0
  unsigned int v19; // w0
  __int64 v20; // x0

  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
  if ( vdev_by_id_from_pdev )
  {
    v15 = (unsigned int *)*((unsigned int *)vdev_by_id_from_pdev + 4);
    if ( ((unsigned int)v15 & 0xFFFFFFFD) != 0 )
    {
      v16 = 4;
LABEL_12:
      wlan_objmgr_vdev_release_ref((__int64)vdev_by_id_from_pdev, 0x4Du, v15, v7, v8, v9, v10, v11, v12, v13, v14);
      return v16;
    }
    v17 = (__int64)vdev_by_id_from_pdev;
    ext_hdl_fl = cm_get_ext_hdl_fl(
                   (__int64)vdev_by_id_from_pdev,
                   (__int64)"cm_roam_acquire_lock",
                   0x7C4u,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   v13,
                   v14);
    v15 = (unsigned int *)&unk_81C000;
    cm_roam_acquire_lock_rso_cfg = ext_hdl_fl;
    if ( ext_hdl_fl )
    {
      v16 = qdf_mutex_acquire(ext_hdl_fl);
      vdev_by_id_from_pdev = (_QWORD *)v17;
      if ( v16 )
        goto LABEL_12;
      v19 = cm_rso_set_roam_trigger(a1, a2, a3);
      v15 = (unsigned int *)*(unsigned int *)(v17 + 16);
      v16 = v19;
      if ( ((unsigned int)v15 & 0xFFFFFFFD) == 0 )
      {
        v20 = cm_get_ext_hdl_fl(v17, (__int64)"cm_roam_release_lock", 0x7CFu, v7, v8, v9, v10, v11, v12, v13, v14);
        v15 = (unsigned int *)&unk_81C000;
        cm_roam_release_lock_rso_cfg = v20;
        if ( v20 )
          qdf_mutex_release(v20);
      }
    }
    else
    {
      v16 = 4;
    }
    vdev_by_id_from_pdev = (_QWORD *)v17;
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev object is NULL",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "wlan_cm_rso_set_roam_trigger");
  return 4;
}
