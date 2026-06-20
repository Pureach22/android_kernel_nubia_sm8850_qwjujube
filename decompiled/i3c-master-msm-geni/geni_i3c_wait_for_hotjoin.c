void __fastcall geni_i3c_wait_for_hotjoin(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0

  v2 = wait_for_completion_timeout(a1 + 2584, &byte_12[7]);
  v3 = *(_QWORD *)(a1 + 2528);
  if ( v2 )
  {
    ipc_log_string(v3, "%s: success time_remaining:%lu\n", "geni_i3c_wait_for_hotjoin", v2);
    if ( !*(_QWORD *)(a1 + 8) )
      return;
  }
  else
  {
    ipc_log_string(v3, "%s: hotjoin didn't received\n", "geni_i3c_wait_for_hotjoin");
    if ( !*(_QWORD *)(a1 + 8) )
      return;
  }
  i3c_trace_log();
}
