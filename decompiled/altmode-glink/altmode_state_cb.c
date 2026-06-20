__int64 __fastcall altmode_state_cb(__int64 a1, int a2)
{
  __int64 result; // x0

  result = ipc_log_string(altmode_ipc_log, "state: %d\n", a2);
  if ( a2 == 1 )
  {
    mutex_lock(a1 + 40);
    if ( *(_QWORD *)(a1 + 104) != a1 + 104 )
      queue_delayed_work_on(32, system_wq, a1 + 128, 5);
    return mutex_unlock(a1 + 40);
  }
  return result;
}
