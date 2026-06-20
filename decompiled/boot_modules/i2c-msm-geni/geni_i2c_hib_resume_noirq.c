__int64 __fastcall geni_i2c_hib_resume_noirq(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 152);
  ipc_log_string(*(_QWORD *)(v1 + 5096), "%s line:%d\n", "geni_i2c_hib_resume_noirq", 3457);
  if ( *(_QWORD *)v1 )
    i2c_trace_log();
  *(_DWORD *)(v1 + 9080) = 0;
  return 0;
}
