__int64 __fastcall qiib_irq_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x0

  v3 = raw_spin_lock_irqsave(a2 + 208);
  ++*(_DWORD *)(a2 + 204);
  raw_spin_unlock_irqrestore(a2 + 208, v3);
  _wake_up(a2 + 176, 1, 1, 0);
  v4 = *(_QWORD *)(qiib_info + 88);
  if ( v4 )
    ipc_log_string(
      v4,
      "%s name[%s] pend_count[%d]\n",
      "qiib_irq_handler",
      *(const char **)(a2 + 24),
      *(_DWORD *)(a2 + 204));
  return 1;
}
