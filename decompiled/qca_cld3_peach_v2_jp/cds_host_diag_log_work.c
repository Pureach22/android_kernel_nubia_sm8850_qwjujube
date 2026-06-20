__int64 __fastcall cds_host_diag_log_work(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  const char *v5; // x0

  cds_get_ring_log_level(0, a2, a3, a4);
  v5 = qdf_wake_lock_name(a1);
  return ((__int64 (__fastcall *)(__int64, const char *, __int64, _QWORD))host_diag_log_wlock)(11, v5, 1000, 0);
}
