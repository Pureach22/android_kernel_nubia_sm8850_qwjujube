__int64 __fastcall lim_mon_mlme_vdev_start_send(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x0
  const char *v13; // x2

  if ( a11 )
  {
    v11 = *(_QWORD *)(a11 + 8608);
    if ( v11 )
    {
      lim_send_switch_chnl_params(v11, a11, a1, a2, a3, a4, a5, a6, a7, a8);
      return 0;
    }
    v13 = "%s: mac_ctx is NULL";
  }
  else
  {
    v13 = "%s: data is NULL";
  }
  qdf_trace_msg(0x35u, 2u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "lim_mon_mlme_vdev_start_send");
  return 4;
}
