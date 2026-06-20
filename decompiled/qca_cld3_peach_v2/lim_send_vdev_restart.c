__int64 __fastcall lim_send_vdev_restart(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  __int64 cmpt_obj; // x0
  const char *v13; // x2

  if ( a10 )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a10 + 16), a1, a2, a3, a4, a5, a6, a7, a8);
    if ( cmpt_obj )
    {
      *(_BYTE *)(cmpt_obj + 240) = *(_BYTE *)(a10 + 7020) != 0;
      return vdev_mgr_start_send(cmpt_obj, 1, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    v13 = "%s: vdev component object is NULL";
  }
  else
  {
    v13 = "%s: Invalid parameters";
  }
  return qdf_trace_msg(0x35u, 2u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "lim_send_vdev_restart");
}
