__int64 __fastcall mlo_peer_get_vdev_list(
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x22
  __int64 v24; // x22

  *a2 = 0;
  if ( a1 )
  {
    qdf_mutex_acquire(*(_QWORD *)(a1 + 784) + 120LL);
    v22 = *(_QWORD *)(a1 + 784);
    v23 = *(_QWORD *)(v22 + 16);
    if ( v23 )
    {
      if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(
                           *(_QWORD *)(v23 + 96),
                           0x5Au,
                           v14,
                           v15,
                           v16,
                           v17,
                           v18,
                           v19,
                           v20,
                           v21) )
        return qdf_mutex_release(*(_QWORD *)(a1 + 784) + 120LL);
      *(_QWORD *)(a3 + 8LL * (unsigned __int16)(*a2)++) = *(_QWORD *)(v23 + 96);
      v22 = *(_QWORD *)(a1 + 784);
    }
    v24 = *(_QWORD *)(v22 + 56);
    if ( v24 )
    {
      if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref(
                            *(_QWORD *)(v24 + 96),
                            0x5Au,
                            v14,
                            v15,
                            v16,
                            v17,
                            v18,
                            v19,
                            v20,
                            v21) )
        *(_QWORD *)(a3 + 8LL * (unsigned __int16)(*a2)++) = *(_QWORD *)(v24 + 96);
    }
    return qdf_mutex_release(*(_QWORD *)(a1 + 784) + 120LL);
  }
  return qdf_trace_msg(0x8Fu, 2u, "%s: Invalid input", a4, a5, a6, a7, a8, a9, a10, a11, "mlo_peer_get_vdev_list");
}
