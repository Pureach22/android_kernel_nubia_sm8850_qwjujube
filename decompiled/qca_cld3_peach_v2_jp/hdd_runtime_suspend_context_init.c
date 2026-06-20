__int64 __fastcall hdd_runtime_suspend_context_init(__int64 a1)
{
  __int64 v2; // x0

  _qdf_runtime_lock_init((__int64 *)(a1 + 1656), "&ctx->dfs");
  _qdf_runtime_lock_init((__int64 *)(a1 + 1664), "&ctx->connect");
  _qdf_runtime_lock_init((__int64 *)(a1 + 1672), "&ctx->user");
  _qdf_runtime_lock_init((__int64 *)(a1 + 1688), "&ctx->monitor_mode");
  _qdf_runtime_lock_init((__int64 *)(a1 + 1696), "&ctx->wow_unit_test");
  _qdf_runtime_lock_init((__int64 *)(a1 + 1704), "&ctx->system_suspend");
  _qdf_runtime_lock_init((__int64 *)(a1 + 1712), "&ctx->dyn_mac_addr_update");
  _qdf_runtime_lock_init((__int64 *)(a1 + 1720), "&ctx->vdev_destroy");
  _qdf_runtime_lock_init((__int64 *)(a1 + 1728), "&ctx->oem_data_cmd");
  qdf_rtpm_register(2u, 0);
  qdf_rtpm_register(1u, 0);
  v2 = *(_QWORD *)(a1 + 8);
  *(_BYTE *)(a1 + 1680) = 0;
  return wlan_scan_runtime_pm_init(v2);
}
