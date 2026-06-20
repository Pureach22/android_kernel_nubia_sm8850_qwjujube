__int64 __fastcall ap_mlme_vdev_update_beacon(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: vdev id = %d ",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "ap_mlme_vdev_update_beacon",
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 520) + 168LL));
  return lim_ap_mlme_vdev_update_beacon(a1, a2, a3, a4);
}
