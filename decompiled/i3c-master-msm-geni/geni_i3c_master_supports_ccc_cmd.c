__int64 __fastcall geni_i3c_master_supports_ccc_cmd(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  unsigned __int64 v5; // x20
  unsigned int v6; // w8
  __int64 v7; // x21
  __int64 result; // x0
  __int64 v9; // x0

  v2 = *(_QWORD *)(a1 + 2424);
  if ( v2 )
  {
    if ( *(_DWORD *)(a1 + 2432) )
    {
      v5 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_master_supports_ccc_cmd", v5, v5 / 0x3E8);
    }
    else
    {
      v5 = 0;
    }
  }
  else
  {
    v5 = -22;
  }
  ipc_log_string(
    *(_QWORD *)(a1 + 2416),
    "Enter %s cmd->id:0x%x\n",
    "geni_i3c_master_supports_ccc_cmd",
    *(unsigned __int8 *)(a2 + 1));
  if ( *(_QWORD *)(a1 - 104) )
    i3c_trace_log();
  v6 = *(unsigned __int8 *)(a2 + 1);
  if ( v6 - 128 <= 0x15 && ((1 << (v6 + 0x80)) & 0x33FFC7) != 0 || v6 <= 0xA && ((1 << v6) & 0x7C7) != 0 )
  {
    v7 = *(_QWORD *)(a1 + 2424);
    if ( !v7 )
      return 1;
    result = 1;
    if ( v5 && *(_DWORD *)(a1 + 2432) )
    {
      v9 = sched_clock(1);
      ipc_log_string(
        v7,
        "%s:took %llu nsec(%llu usec)\n",
        "geni_i3c_master_supports_ccc_cmd",
        v9 - v5,
        (v9 - v5) / 0x3E8);
      return 1;
    }
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a1 + 2416), "%s: Unsupported cmd\n", "geni_i3c_master_supports_ccc_cmd");
    result = *(_QWORD *)(a1 - 104);
    if ( result )
    {
      i3c_trace_log();
      return 0;
    }
  }
  return result;
}
