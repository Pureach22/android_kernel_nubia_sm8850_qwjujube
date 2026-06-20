__int64 __fastcall mhi_pm_sys_err_handler(__int64 result)
{
  __int64 v1; // x8

  if ( !*(_QWORD *)(result + 160) )
    return mhi_queue_state_transition(result, 5);
  v1 = *(_QWORD *)(*(_QWORD *)(result + 16) + 192LL);
  if ( v1 )
  {
    if ( !*(_DWORD *)(v1 + 24) )
      return ipc_log_string(
               *(_QWORD *)(v1 + 32),
               "[D][%s] Controller supports RDDM, skip SYS_ERROR\n",
               "mhi_pm_sys_err_handler");
  }
  return result;
}
