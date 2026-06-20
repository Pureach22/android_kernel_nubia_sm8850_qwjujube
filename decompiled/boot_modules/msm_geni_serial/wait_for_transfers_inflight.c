__int64 __fastcall wait_for_transfers_inflight(__int64 a1)
{
  char v2; // w0
  __int64 v3; // x21
  char v4; // w20
  bool v5; // zf
  __int64 v6; // x8
  char v7; // w22
  char v8; // w0
  __int64 v9; // x21
  char v10; // w20
  bool v11; // zf
  __int64 v12; // x8
  bool v13; // w22
  char v14; // w0
  __int64 v15; // x21
  char v16; // w20
  bool v17; // zf
  __int64 v18; // x8
  bool v19; // w22
  int v20; // w0

  if ( (readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL)) & 0x1000) != 0 )
  {
    v2 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
    v3 = *(_QWORD *)(a1 + 208);
    v4 = v2;
    if ( *(_DWORD *)(a1 + 584) == 2 )
    {
      v5 = *(_QWORD *)(a1 + 808) == 0;
      v6 = 3412;
    }
    else
    {
      v5 = (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 2048LL)) == 0;
      v6 = 2052;
    }
    v7 = !v5;
    if ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + v6))
      || (v4 & 1) != 0
      || (v7 & 1) != 0
      || *(_DWORD *)(v3 + 376) != *(_DWORD *)(v3 + 380) )
    {
      usleep_range_state(100, 150, 2);
      v8 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
      v9 = *(_QWORD *)(a1 + 208);
      v10 = v8;
      if ( *(_DWORD *)(a1 + 584) == 2 )
      {
        v11 = *(_QWORD *)(a1 + 808) == 0;
        v12 = 3412;
      }
      else
      {
        v11 = (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 2048LL)) == 0;
        v12 = 2052;
      }
      v13 = !v11;
      if ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + v12))
        || (v10 & 1) != 0
        || v13
        || *(_DWORD *)(v9 + 376) != *(_DWORD *)(v9 + 380) )
      {
        usleep_range_state(100, 150, 2);
      }
    }
    v14 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
    v15 = *(_QWORD *)(a1 + 208);
    v16 = v14;
    if ( *(_DWORD *)(a1 + 584) == 2 )
    {
      v17 = *(_QWORD *)(a1 + 808) == 0;
      v18 = 3412;
    }
    else
    {
      v17 = (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 2048LL)) == 0;
      v18 = 2052;
    }
    v19 = !v17;
    if ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + v18))
      || (v16 & 1) != 0
      || v19
      || *(_DWORD *)(v15 + 376) != *(_DWORD *)(v15 + 380) )
    {
      v20 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3412LL));
      if ( v20 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Bailout rx_len_in is set %d\n", "wait_for_transfers_inflight", v20);
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Bailout rx_len_in is set %d\n");
        return 4294967280LL;
      }
      geni_se_dump_dbg_regs((_QWORD *)a1);
    }
  }
  return 0;
}
