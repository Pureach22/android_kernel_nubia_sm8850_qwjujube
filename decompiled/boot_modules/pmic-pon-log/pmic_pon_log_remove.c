__int64 __fastcall pmic_pon_log_remove(__int64 a1)
{
  return ipc_log_context_destroy(*(_QWORD *)(*(_QWORD *)(a1 + 168) + 24LL));
}
