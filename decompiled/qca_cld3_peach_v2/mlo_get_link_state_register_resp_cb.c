__int64 __fastcall mlo_get_link_state_register_resp_cb(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  __int64 v21; // x21

  if ( !a1 )
    return 29;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
    return 29;
  v20 = *(_QWORD *)(a1 + 1360);
  if ( v20 )
  {
    v21 = *(_QWORD *)(v20 + 2224);
    if ( v21 )
    {
      qdf_mutex_acquire(v20 + 1656);
      *(_QWORD *)(v21 + 304) = a2[1];
      *(_QWORD *)(v21 + 312) = *a2;
      qdf_mutex_release(v20 + 1656);
      return 0;
    }
    else
    {
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: null mlo_dev_ctx",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "mlo_get_link_state_register_resp_cb");
    return 29;
  }
}
