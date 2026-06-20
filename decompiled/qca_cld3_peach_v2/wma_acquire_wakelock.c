__int64 __fastcall wma_acquire_wakelock(
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
  _QWORD *context; // x21
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  const char *v16; // x0

  context = _cds_get_context(54, (__int64)"wma_acquire_wakelock", a3, a4, a5, a6, a7, a8, a9, a10);
  cds_get_ring_log_level(0, v13, v14, v15);
  v16 = qdf_wake_lock_name(a1);
  ((void (__fastcall *)(__int64, const char *, _QWORD, _QWORD))host_diag_log_wlock)(16, v16, a2, 0);
  qdf_wake_lock_timeout_acquire(a1, a2);
  return qdf_runtime_pm_prevent_suspend(context + 416);
}
