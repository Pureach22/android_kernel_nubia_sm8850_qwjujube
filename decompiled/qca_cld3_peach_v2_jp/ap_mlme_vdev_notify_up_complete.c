__int64 __fastcall ap_mlme_vdev_notify_up_complete(
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
  if ( a1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Vdev %d is up",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ap_mlme_vdev_notify_up_complete",
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL));
    return 0;
  }
  else
  {
    qdf_trace_msg(0x1Fu, 2u, "%s: data is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "ap_mlme_vdev_notify_up_complete");
    return 4;
  }
}
