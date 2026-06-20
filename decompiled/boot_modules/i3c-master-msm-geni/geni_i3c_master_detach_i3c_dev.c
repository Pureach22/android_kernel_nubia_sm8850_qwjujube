__int64 __fastcall geni_i3c_master_detach_i3c_dev(__int64 result)
{
  __int64 v1; // x22
  __int64 v2; // x19
  __int64 v3; // x21
  unsigned __int64 v4; // x20
  __int64 v5; // x19
  __int64 v6; // x0

  v1 = *(_QWORD *)(result + 16);
  v2 = result;
  v3 = *(_QWORD *)(v1 + 2424);
  if ( v3 )
  {
    if ( *(_DWORD *)(v1 + 2432) )
    {
      v4 = sched_clock(result);
      result = ipc_log_string(
                 v3,
                 "%s:start at %llu nsec(%llu usec)\n",
                 "geni_i3c_master_detach_i3c_dev",
                 v4,
                 v4 / 0x3E8);
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    v4 = -22;
  }
  *(_QWORD *)(v2 + 24) = 0;
  v5 = *(_QWORD *)(v1 + 2424);
  if ( v5 && v4 )
  {
    if ( *(_DWORD *)(v1 + 2432) )
    {
      v6 = sched_clock(result);
      return ipc_log_string(
               v5,
               "%s:took %llu nsec(%llu usec)\n",
               "geni_i3c_master_detach_i3c_dev",
               v6 - v4,
               (v6 - v4) / 0x3E8);
    }
  }
  return result;
}
