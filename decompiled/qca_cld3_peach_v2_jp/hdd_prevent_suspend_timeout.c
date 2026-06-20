__int64 __fastcall hdd_prevent_suspend_timeout(unsigned int a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v5; // w20
  unsigned int ring_log_level; // w0
  const char *v7; // x0

  v5 = a2;
  ring_log_level = cds_get_ring_log_level(0, a2, a3, a4);
  if ( v5 != 10 || ring_log_level >= 3 )
  {
    v7 = qdf_wake_lock_name((__int64)&wlan_wake_lock);
    ((void (__fastcall *)(_QWORD, const char *, _QWORD, _QWORD))host_diag_log_wlock)(v5, v7, a1, 0);
  }
  return qdf_wake_lock_timeout_acquire((__int64)&wlan_wake_lock, a1);
}
