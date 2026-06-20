__int64 __fastcall spi_geni_unprepare_message(__int64 a1, _QWORD **a2)
{
  __int64 v2; // x23
  __int64 v3; // x20
  __int64 v5; // x22
  unsigned __int64 v6; // x19
  int v7; // w8
  _QWORD *i; // x22
  __int64 v9; // x1
  __int64 v10; // x1
  int v11; // w20
  __int64 v12; // x20
  __int64 v13; // x20
  __int64 v14; // x0

  v2 = *(_QWORD *)(a1 + 152);
  v3 = a1;
  v5 = *(_QWORD *)(v2 + 488);
  if ( v5 )
  {
    if ( *(_DWORD *)(v2 + 496) )
    {
      v6 = sched_clock(a1);
      a1 = ipc_log_string(v5, "%s:start at %llu nsec(%llu usec)\n", "spi_geni_unprepare_message", v6, v6 / 0x3E8);
    }
    else
    {
      v6 = 0;
    }
  }
  else
  {
    v6 = -22;
  }
  v7 = *(_DWORD *)(v2 + 452);
  *(_QWORD *)(v2 + 228) = 0;
  if ( v7 == 3 )
  {
    for ( i = *a2; i != a2; i = (_QWORD *)*i )
    {
      if ( *(i - 13) )
      {
        v9 = *(i - 6);
        if ( v9 != -1 )
          a1 = dma_unmap_page_attrs(*(_QWORD *)(v2 + 288), v9, *((unsigned int *)i - 24), 2, 0);
      }
      if ( *(i - 14) )
      {
        v10 = *(i - 7);
        if ( v10 != -1 )
          a1 = dma_unmap_page_attrs(*(_QWORD *)(v2 + 288), v10, *((unsigned int *)i - 24), 1, 0);
      }
    }
  }
  if ( *(_BYTE *)(v2 + 501) == 1 )
  {
    if ( *(_BYTE *)(v2 + 502) == 1 )
      spi_geni_unlock_bus(v3);
    a1 = *(_QWORD *)(v2 + 200);
    if ( *(_BYTE *)(v2 + 505) == 1 )
    {
      a1 = _pm_runtime_idle(a1, 4);
      v11 = *(_DWORD *)(*(_QWORD *)(v2 + 200) + 480LL);
      if ( v11 < 0 )
      {
        ipc_log_string(*(_QWORD *)(v2 + 472), "suspend usage count mismatch:%d", v11);
        a1 = *(_QWORD *)(v2 + 200);
        if ( a1 )
          spi_trace_log();
      }
    }
    else if ( *(_DWORD *)(a1 + 500) != 2 && (*(_WORD *)(a1 + 488) & 7) == 0 )
    {
      v12 = *(_QWORD *)(v2 + 200);
      *(_QWORD *)(v12 + 520) = ktime_get_mono_fast_ns();
      a1 = _pm_runtime_suspend(*(_QWORD *)(v2 + 200), 13);
    }
  }
  v13 = *(_QWORD *)(v2 + 488);
  if ( v13 && v6 && *(_DWORD *)(v2 + 496) )
  {
    v14 = sched_clock(a1);
    ipc_log_string(v13, "%s:took %llu nsec(%llu usec)\n", "spi_geni_unprepare_message", v14 - v6, (v14 - v6) / 0x3E8);
  }
  return 0;
}
