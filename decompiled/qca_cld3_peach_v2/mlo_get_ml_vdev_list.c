__int64 __fastcall mlo_get_ml_vdev_list(
        __int64 a1,
        _WORD *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  *a2 = 0;
  if ( a1 )
  {
    v11 = *(_QWORD *)(a1 + 1360);
    if ( v11 )
    {
      qdf_mutex_acquire(v11 + 1656);
      *a2 = 0;
      v22 = *(_QWORD *)(v11 + 24);
      if ( v22 && (wlan_vdev_mlme_is_mlo_vdev(v22, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
      {
        if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(
                             *(_QWORD *)(v11 + 24),
                             0x5Au,
                             v14,
                             v15,
                             v16,
                             v17,
                             v18,
                             v19,
                             v20,
                             v21) )
          return qdf_mutex_release(v11 + 1656);
        *(_QWORD *)(a3 + 8LL * (unsigned __int16)(*a2)++) = *(_QWORD *)(v11 + 24);
      }
      v23 = *(_QWORD *)(v11 + 32);
      if ( v23
        && (wlan_vdev_mlme_is_mlo_vdev(v23, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0
        && !(unsigned int)wlan_objmgr_vdev_try_get_ref(
                            *(_QWORD *)(v11 + 32),
                            0x5Au,
                            v24,
                            v25,
                            v26,
                            v27,
                            v28,
                            v29,
                            v30,
                            v31) )
      {
        *(_QWORD *)(a3 + 8LL * (unsigned __int16)(*a2)++) = *(_QWORD *)(v11 + 32);
      }
      return qdf_mutex_release(v11 + 1656);
    }
  }
  return qdf_trace_msg(0x8Fu, 2u, "%s: Invalid input", a4, a5, a6, a7, a8, a9, a10, a11, "mlo_get_ml_vdev_list");
}
