__int64 __fastcall spi_geni_unprepare_transfer_hardware(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x20
  unsigned __int64 v3; // x19
  int v5; // w0
  __int64 v6; // x0
  int v7; // w20
  __int64 v8; // x20
  __int64 v9; // x20
  __int64 v10; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(v1 + 488);
  if ( v2 )
  {
    if ( *(_DWORD *)(v1 + 496) )
    {
      v3 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "spi_geni_unprepare_transfer_hardware", v3, v3 / 0x3E8);
      if ( (*(_BYTE *)(v1 + 501) & 1) != 0 )
        goto LABEL_9;
    }
    else
    {
      v3 = 0;
      if ( (*(_BYTE *)(v1 + 501) & 1) != 0 )
      {
LABEL_9:
        *(_BYTE *)(v1 + 518) = 0;
        return 0;
      }
    }
  }
  else
  {
    v3 = -22;
    if ( (*(_BYTE *)(v1 + 501) & 1) != 0 )
      goto LABEL_9;
  }
  if ( *(_BYTE *)(v1 + 503) == 1 )
    goto LABEL_9;
  if ( *(_BYTE *)(v1 + 500) == 1 && (*(_BYTE *)(v1 + 504) & 1) == 0 )
  {
    v5 = pinctrl_select_state(*(_QWORD *)(v1 + 136), *(_QWORD *)(v1 + 152));
    if ( v5 )
    {
      ipc_log_string(
        *(_QWORD *)(v1 + 472),
        "%s: Error %d pinctrl_select_state\n",
        "spi_geni_unprepare_transfer_hardware",
        v5);
      if ( *(_QWORD *)(v1 + 200) )
        spi_trace_log();
    }
  }
  v6 = *(_QWORD *)(v1 + 200);
  if ( *(_BYTE *)(v1 + 505) == 1 )
  {
    v6 = _pm_runtime_idle(v6, 4);
    v7 = *(_DWORD *)(*(_QWORD *)(v1 + 200) + 480LL);
    if ( v7 < 0 )
    {
      ipc_log_string(*(_QWORD *)(v1 + 472), "suspend usage count mismatch:%d", v7);
      v6 = *(_QWORD *)(v1 + 200);
      if ( v6 )
        spi_trace_log();
    }
  }
  else if ( *(_DWORD *)(v6 + 500) != 2 && (*(_WORD *)(v6 + 488) & 7) == 0 )
  {
    v8 = *(_QWORD *)(v1 + 200);
    *(_QWORD *)(v8 + 520) = ktime_get_mono_fast_ns();
    v6 = _pm_runtime_suspend(*(_QWORD *)(v1 + 200), 13);
  }
  v9 = *(_QWORD *)(v1 + 488);
  *(_BYTE *)(v1 + 518) = 0;
  if ( v9 && v3 && *(_DWORD *)(v1 + 496) )
  {
    v10 = sched_clock(v6);
    ipc_log_string(
      v9,
      "%s:took %llu nsec(%llu usec)\n",
      "spi_geni_unprepare_transfer_hardware",
      v10 - v3,
      (v10 - v3) / 0x3E8);
  }
  return 0;
}
