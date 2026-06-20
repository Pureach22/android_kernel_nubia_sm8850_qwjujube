__int64 __fastcall hdd_runtime_suspend_context_deinit(__int64 a1)
{
  if ( *(_BYTE *)(a1 + 1680) == 1 )
    qdf_runtime_pm_allow_suspend((__int64 *)(a1 + 1672));
  qdf_runtime_lock_deinit((__int64 *)(a1 + 1728));
  qdf_runtime_lock_deinit((__int64 *)(a1 + 1712));
  qdf_runtime_lock_deinit((__int64 *)(a1 + 1696));
  qdf_runtime_lock_deinit((__int64 *)(a1 + 1688));
  qdf_runtime_lock_deinit((__int64 *)(a1 + 1672));
  qdf_runtime_lock_deinit((__int64 *)(a1 + 1664));
  qdf_runtime_lock_deinit((__int64 *)(a1 + 1656));
  qdf_runtime_lock_deinit((__int64 *)(a1 + 1704));
  qdf_runtime_lock_deinit((__int64 *)(a1 + 1720));
  qdf_rtpm_deregister(2u);
  qdf_rtpm_deregister(1u);
  return wlan_scan_runtime_pm_deinit(*(_QWORD *)(a1 + 8));
}
