__int64 __fastcall mlo_get_vdev_by_link_id(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
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
  int v13; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  __int64 *v23; // x23
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 *v26; // x22
  __int64 v27; // x19

  if ( a1 && (v11 = *(_QWORD *)(a1 + 1360)) != 0 )
  {
    v13 = a2;
    qdf_mutex_acquire(v11 + 1656);
    v23 = (__int64 *)(v11 + 24);
    v22 = *(_QWORD *)(v11 + 24);
    if ( (v22
       && (wlan_vdev_mlme_is_mlo_vdev(v22, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0
       && (v24 = *v23, *(unsigned __int8 *)(*v23 + 93) == v13)
       || (v26 = (__int64 *)(v11 + 32), (v25 = *(_QWORD *)(v11 + 32)) != 0)
       && (wlan_vdev_mlme_is_mlo_vdev(v25, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0
       && (v24 = *v26, v23 = (__int64 *)(v11 + 32), *(unsigned __int8 *)(*v26 + 93) == v13))
      && !(unsigned int)wlan_objmgr_vdev_try_get_ref(v24, a3, v14, v15, v16, v17, v18, v19, v20, v21) )
    {
      v27 = *v23;
    }
    else
    {
      v27 = 0;
    }
    qdf_mutex_release(v11 + 1656);
  }
  else
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: Invalid input", a4, a5, a6, a7, a8, a9, a10, a11, "mlo_get_vdev_by_link_id");
    return 0;
  }
  return v27;
}
