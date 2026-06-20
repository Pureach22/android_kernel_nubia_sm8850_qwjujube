__int64 __fastcall qdf_wake_lock_acquire(__int64 a1, unsigned int a2)
{
  __int64 v3; // x0
  const char *v4; // x1

  v3 = a2;
  if ( a1 )
    v4 = *(const char **)a1;
  else
    v4 = "UNNAMED_WAKELOCK";
  ((void (__fastcall *)(__int64, const char *, _QWORD, _QWORD))host_diag_log_wlock)(v3, v4, 0, 0);
  _pm_stay_awake(*(_QWORD *)(a1 + 192));
  return 0;
}
