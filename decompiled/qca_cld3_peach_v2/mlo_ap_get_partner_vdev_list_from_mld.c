__int64 __fastcall mlo_ap_get_partner_vdev_list_from_mld(
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

  *a2 = 0;
  if ( a1 )
  {
    v11 = *(_QWORD *)(a1 + 1360);
    if ( v11 )
    {
      qdf_mutex_acquire(v11 + 1656);
      *a2 = 0;
      v22 = *(_QWORD *)(v11 + 24);
      if ( v22 && *(_DWORD *)(v22 + 16) == 1 )
      {
        if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(v22, 0x5Au, v14, v15, v16, v17, v18, v19, v20, v21) )
          return qdf_mutex_release(v11 + 1656);
        *(_QWORD *)(a3 + 8LL * (unsigned __int16)(*a2)++) = *(_QWORD *)(v11 + 24);
      }
      v23 = *(_QWORD *)(v11 + 32);
      if ( v23
        && *(_DWORD *)(v23 + 16) == 1
        && !(unsigned int)wlan_objmgr_vdev_try_get_ref(v23, 0x5Au, v14, v15, v16, v17, v18, v19, v20, v21) )
      {
        *(_QWORD *)(a3 + 8LL * (unsigned __int16)(*a2)++) = *(_QWORD *)(v11 + 32);
      }
      return qdf_mutex_release(v11 + 1656);
    }
  }
  return qdf_trace_msg(
           0x8Fu,
           2u,
           "%s: Invalid input",
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           "mlo_ap_get_partner_vdev_list_from_mld");
}
