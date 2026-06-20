__int64 __fastcall mlo_ap_ctx_deinit(
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
  __int64 result; // x0

  wlan_mlo_vdev_aid_mgr_deinit(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_mutex_destroy(*(_QWORD *)(a1 + 2232) + 16LL);
  result = _qdf_mem_free(*(_QWORD *)(a1 + 2232));
  *(_QWORD *)(a1 + 2232) = 0;
  return result;
}
