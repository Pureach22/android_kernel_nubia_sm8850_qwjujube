__int64 __fastcall fastrpc_sysfs_notify_pids(__int64 result)
{
  if ( result )
  {
    if ( *(_QWORD *)(result + 176) )
      return sysfs_notify(result + 80, 0, pids_remote_sessions_attr);
  }
  return result;
}
