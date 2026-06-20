__int64 __fastcall vdevmgr_vdev_stop_rsp_handle(
        __int64 a1,
        __int64 a2,
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
    0x1Fu,
    8u,
    "%s: vdev id = %d ",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "vdevmgr_vdev_stop_rsp_handle",
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL));
  return wma_vdev_stop_resp_handler(a1, a2);
}
