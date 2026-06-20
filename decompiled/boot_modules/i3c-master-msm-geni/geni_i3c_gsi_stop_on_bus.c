__int64 __fastcall geni_i3c_gsi_stop_on_bus(__int64 a1)
{
  unsigned int v1; // w20
  __int64 v3; // x0
  unsigned int v4; // w0
  const char *v5; // x2

  if ( *(int *)(a1 + 21544) <= 3 )
  {
    *(_BYTE *)(a1 + 21240) = 0;
    *(_DWORD *)(a1 + 104) = 0;
    *(_BYTE *)(a1 + 2960) = 0;
    *(_DWORD *)(a1 + 2552) = 0;
    *(_QWORD *)(a1 + 2864) = 7;
    v3 = *(_QWORD *)(a1 + 2528);
    *(_QWORD *)(a1 + 2872) = 0x20020000000000LL;
    ipc_log_string(
      v3,
      "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
      "geni_i3c_gsi_stop_on_bus",
      7,
      0,
      0,
      2097664);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
    *(_BYTE *)(a1 + 2960) |= 4u;
    v4 = gsi_common_fill_tre_buf(a1 + 2712, 1);
    v1 = gsi_common_prep_desc_and_submit(a1 + 2712, v4, 1, 0);
    if ( (v1 & 0x80000000) != 0 )
      *(_DWORD *)(a1 + 104) = v1;
    if ( !(unsigned int)wait_for_completion_timeout(a1 + 2552, &print_fmt_i3c_log_info[2], v5) )
    {
      ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:wait_for_completion timed out\n", "geni_i3c_gsi_stop_on_bus");
      if ( *(_QWORD *)(a1 + 8) )
        i3c_trace_log();
      geni_i3c_err(a1, 9u);
      *(_DWORD *)(a1 + 2552) = 0;
      *(_QWORD *)(a1 + 21264) = 0;
      *(_QWORD *)(a1 + 21272) = 0;
      *(_DWORD *)(a1 + 21280) = 0;
    }
    ipc_log_string(*(_QWORD *)(a1 + 2528), "%s: ret:%d\n", "geni_i3c_gsi_stop_on_bus", v1);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
  }
  else
  {
    return 0;
  }
  return v1;
}
