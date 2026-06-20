__int64 __fastcall geni_i2c_resume_early(__int64 a1)
{
  _QWORD *v1; // x19

  v1 = *(_QWORD **)(a1 + 152);
  ipc_log_string(v1[637], "%s ret=%d\n", "geni_i2c_resume_early", 1);
  if ( *v1 )
    i2c_trace_log();
  return 0;
}
