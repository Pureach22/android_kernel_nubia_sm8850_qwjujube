__int64 __fastcall geni_i3c_resume_early(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  unsigned __int64 v3; // x20
  __int64 v4; // x21
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(v1 + 2536);
  if ( v2 )
  {
    if ( *(_DWORD *)(v1 + 2544) )
    {
      v3 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_resume_early", v3, v3 / 0x3E8);
    }
    else
    {
      v3 = 0;
    }
  }
  else
  {
    v3 = -22;
  }
  if ( *(_BYTE *)(v1 + 21460) == 1
    && (*(_BYTE *)(v1 + 21461) & 1) == 0
    && (unsigned int)geni_i3c_enable_naon_ibi_clks(v1, 1) )
  {
    ipc_log_string(*(_QWORD *)(v1 + 2528), "%s:  NAON clock failure\n", "geni_i3c_resume_early");
    v9 = *(_QWORD *)(v1 + 8);
    if ( v9 )
      dev_err(v9, "%s:  NAON clock failure\n", "geni_i3c_resume_early");
    else
      printk(&unk_13A7A, "geni_i3c_resume_early", v7, v8);
    if ( *(_QWORD *)(v1 + 8) )
      i3c_trace_log();
    return 4294967285LL;
  }
  else
  {
    v4 = *(_QWORD *)(v1 + 2536);
    if ( !v4 )
      return 0;
    result = 0;
    if ( v3 && *(_DWORD *)(v1 + 2544) )
    {
      v6 = sched_clock(0);
      ipc_log_string(v4, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_resume_early", v6 - v3, (v6 - v3) / 0x3E8);
      return 0;
    }
  }
  return result;
}
