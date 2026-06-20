__int64 __fastcall htc_recovery_notifier_call(_QWORD *a1, __int64 a2, __int64 a3)
{
  htc_log_hang_credit_history(a1, a3);
  return 1;
}
