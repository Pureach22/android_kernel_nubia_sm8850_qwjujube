__int64 __fastcall mlo_get_first_active_vdev_by_ml_dev_ctx(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  if ( a1 )
  {
    qdf_mutex_acquire(a1 + 1656);
    v18 = *(_QWORD *)(a1 + 24);
    if ( !v18
      || (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a1 + 24), v10, v11, v12, v13, v14, v15, v16, v17) & 1) == 0
      || (unsigned int)wlan_vdev_mlme_is_active(v18)
      || (unsigned int)wlan_objmgr_vdev_try_get_ref(v18, 0x5Au, v10, v11, v12, v13, v14, v15, v16, v17) )
    {
      v18 = *(_QWORD *)(a1 + 32);
      if ( !v18
        || (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a1 + 32), v10, v11, v12, v13, v14, v15, v16, v17) & 1) == 0
        || (unsigned int)wlan_vdev_mlme_is_active(v18)
        || (unsigned int)wlan_objmgr_vdev_try_get_ref(v18, 0x5Au, v19, v20, v21, v22, v23, v24, v25, v26) )
      {
        v18 = 0;
      }
    }
    qdf_mutex_release(a1 + 1656);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid input",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlo_get_first_active_vdev_by_ml_dev_ctx");
    return 0;
  }
  return v18;
}
