__int64 __fastcall mon_mlme_vdev_down(
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
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: vdev id = %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "mon_mlme_vdev_down",
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL));
  return wma_mon_mlme_vdev_stop_resp(a1);
}
