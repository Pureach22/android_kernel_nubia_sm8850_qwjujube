__int64 __fastcall vdevmgr_vdev_delete_rsp_handle(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 *a10)
{
  qdf_trace_msg(0x1Fu, 8u, "%s: vdev id = %d ", a1, a2, a3, a4, a5, a6, a7, a8, "vdevmgr_vdev_delete_rsp_handle", *a10);
  return wma_vdev_detach_callback(a10);
}
