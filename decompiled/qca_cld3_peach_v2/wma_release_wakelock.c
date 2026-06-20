__int64 __fastcall wma_release_wakelock(
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
  _QWORD *context; // x20

  context = _cds_get_context(54, (__int64)"wma_release_wakelock", a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_wake_lock_release(a1, 0x10u);
  return qdf_runtime_pm_allow_suspend(context + 416);
}
