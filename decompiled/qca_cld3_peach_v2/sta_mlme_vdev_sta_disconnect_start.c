__int64 __fastcall sta_mlme_vdev_sta_disconnect_start(
        __int64 a1,
        unsigned int a2,
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
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: vdev id = %d ",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sta_mlme_vdev_sta_disconnect_start",
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 520) + 168LL));
  return lim_sta_mlme_vdev_sta_disconnect_start(a1, a2, a3);
}
