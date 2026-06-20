__int64 __fastcall spi_geni_prepare_transfer_hardware(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x21
  unsigned __int64 v4; // x19
  __int64 v5; // x9
  __int64 result; // x0
  int v7; // w0
  int v8; // w0
  int v9; // w0
  int v10; // w20
  __int64 v11; // x20
  __int64 v12; // x0
  unsigned int v13; // w19
  unsigned int v14; // w19
  __int64 v15; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 488);
  if ( v3 )
  {
    if ( *(_DWORD *)(v1 + 496) )
    {
      v4 = ((__int64 (*)(void))sched_clock)();
      ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "spi_geni_prepare_transfer_hardware", v4, v4 / 0x3E8);
      if ( (*(_BYTE *)(v1 + 503) & 1) != 0 )
        return 0;
    }
    else
    {
      v4 = 0;
      if ( (*(_BYTE *)(v1 + 503) & 1) != 0 )
        return 0;
    }
  }
  else
  {
    v4 = -22;
    if ( (*(_BYTE *)(v1 + 503) & 1) != 0 )
      return 0;
  }
  v5 = *(_QWORD *)(v1 + 200);
  *(_BYTE *)(v1 + 518) = 1;
  if ( (*(_WORD *)(v5 + 488) & 7) != 0 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 472), "%s: System suspended\n", "spi_geni_prepare_transfer_hardware");
    if ( *(_QWORD *)(v1 + 200) )
      spi_trace_log();
    *(_BYTE *)(v1 + 518) = 0;
    return 4294967283LL;
  }
  if ( *(_BYTE *)(v1 + 500) == 1 && (*(_BYTE *)(v1 + 501) & 1) == 0 && (*(_BYTE *)(v1 + 504) & 1) == 0 )
  {
    v7 = pinctrl_select_state(*(_QWORD *)(v1 + 136), *(_QWORD *)(v1 + 144));
    if ( v7 )
    {
      ipc_log_string(
        *(_QWORD *)(v1 + 472),
        "%s: Error %d pinctrl_select_state\n",
        "spi_geni_prepare_transfer_hardware",
        v7);
      if ( *(_QWORD *)(v1 + 200) )
        spi_trace_log();
    }
  }
  if ( *(_BYTE *)(v1 + 224) == 1 && (*(_BYTE *)(v1 + 501) & 1) != 0 )
  {
LABEL_27:
    v11 = *(_QWORD *)(v1 + 488);
    if ( v11 )
    {
      result = 0;
      if ( !v4 || !*(_DWORD *)(v1 + 496) )
        return result;
      v12 = sched_clock(0);
      ipc_log_string(
        v11,
        "%s:took %llu nsec(%llu usec)\n",
        "spi_geni_prepare_transfer_hardware",
        v12 - v4,
        (v12 - v4) / 0x3E8);
    }
    return 0;
  }
  v8 = _pm_runtime_resume(*(_QWORD *)(v1 + 200), 4);
  if ( v8 < 0 )
  {
    v13 = v8;
    dev_err(*(_QWORD *)(v1 + 200), "%s:pm_runtime_get_sync failed %d\n", "spi_geni_prepare_transfer_hardware", v8);
    __break(0x800u);
    pm_runtime_put_noidle(*(_QWORD *)(v1 + 200));
    _pm_runtime_set_status(*(_QWORD *)(v1 + 200), 2);
    *(_BYTE *)(v1 + 518) = 0;
    return v13;
  }
  if ( (*(_BYTE *)(v1 + 224) & 1) != 0 || (v9 = spi_geni_mas_setup(a1)) == 0 )
  {
    if ( *(_BYTE *)(v1 + 505) == 1 )
    {
      v10 = *(_DWORD *)(*(_QWORD *)(v1 + 200) + 480LL);
      if ( v10 <= 0 )
      {
        ipc_log_string(*(_QWORD *)(v1 + 472), "resume usage count mismatch:%d", v10);
        if ( *(_QWORD *)(v1 + 200) )
          spi_trace_log();
      }
    }
    goto LABEL_27;
  }
  v14 = v9;
  ipc_log_string(*(_QWORD *)(v1 + 472), "%s mas_setup failed: %d\n", "spi_geni_prepare_transfer_hardware", v9);
  v15 = *(_QWORD *)(v1 + 200);
  if ( v15 )
    dev_err(v15, "%s mas_setup failed: %d\n", "spi_geni_prepare_transfer_hardware", v14);
  else
    printk(&unk_DF01);
  if ( *(_QWORD *)(v1 + 200) )
    spi_trace_log();
  *(_BYTE *)(v1 + 518) = 0;
  return v14;
}
