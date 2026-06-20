__int64 __fastcall cm_vdev_down_req(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d: down req status %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "cm_vdev_down_req",
    *(unsigned __int8 *)(a1 + 104),
    a2);
  return mlme_cm_vdev_down_req(a1);
}
