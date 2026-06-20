__int64 __fastcall qdss_disable(__int64 a1)
{
  __int64 v2; // x1

  ipc_log_string(qdss_ipc_log, "%s: channel:%s\n", "qdss_disable", *(const char **)(a1 + 296));
  v2 = raw_spin_lock_irqsave(a1 + 456);
  if ( !*(_DWORD *)(a1 + 276) )
    return raw_spin_unlock_irqrestore(a1 + 456, v2);
  *(_DWORD *)(a1 + 276) = 0;
  raw_spin_unlock_irqrestore(a1 + 456, v2);
  qdss_eps_disable(a1);
  return queue_work_on(32, *(_QWORD *)(a1 + 464), a1 + 424);
}
