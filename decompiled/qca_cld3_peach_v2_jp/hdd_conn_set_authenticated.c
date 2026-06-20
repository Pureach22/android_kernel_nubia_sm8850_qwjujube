__int64 __fastcall hdd_conn_set_authenticated(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 vdev_by_user; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 result; // x0
  __int64 *v23; // x20
  __int64 v24; // x2
  int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Authenticated state Changed from oldState:%d to State:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_conn_set_authenticated",
    *(unsigned __int8 *)(a1 + 676),
    a2);
  *(_BYTE *)(a1 + 676) = a2;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 97, "hdd_conn_set_authenticated");
  if ( vdev_by_user )
  {
    v21 = vdev_by_user;
    ucfg_dp_conn_info_set_peer_authenticate(vdev_by_user, a2, v13, v14, v15, v16, v17, v18, v19, v20);
    _hdd_objmgr_put_vdev_by_user(v21, 97, "hdd_conn_set_authenticated");
  }
  if ( a2 )
  {
    result = qdf_get_time_of_the_day_in_hr_min_sec_usec(a1 + 884, 24);
    if ( ((*(_BYTE *)(a1 + 685) & 1) != 0 || !*(_DWORD *)(a1 + 672)) && (*(_DWORD *)(*(_QWORD *)a1 + 40LL) | 2) == 2 )
    {
      v23 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
      v25 = 0;
      wlan_mlme_get_auto_bmps_timer_value(*v23, &v25);
      if ( (hdd_cm_is_vdev_roaming(a1) & 1) != 0 )
        v24 = 1000;
      else
        v24 = (unsigned int)(1000 * v25);
      result = sme_ps_enable_auto_ps_timer(v23[2], *(unsigned __int8 *)(a1 + 8), v24);
    }
  }
  else
  {
    result = (__int64)qdf_mem_set((void *)(a1 + 884), 0x18u, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
