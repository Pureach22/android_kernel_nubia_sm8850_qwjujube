__int64 __fastcall qdf_wake_lock_release(__int64 a1, unsigned int a2)
{
  __int64 v3; // x0
  const char *v4; // x1

  v3 = a2;
  if ( a1 )
    v4 = *(const char **)a1;
  else
    v4 = "UNNAMED_WAKELOCK";
  ((void (__fastcall *)(__int64, const char *, _QWORD, __int64))host_diag_log_wlock)(v3, v4, 0, 1);
  _pm_relax(*(_QWORD *)(a1 + 192));
  return 0;
}
