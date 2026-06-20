void __fastcall geni_i3c_enable_ibi_ctrl(__int64 a1, char a2)
{
  __int64 v2; // x21
  __int64 v4; // x8
  int v5; // w0
  int v6; // w0
  const char *v7; // x2
  int v8; // w8
  __int64 v9; // x0
  unsigned int *v10; // x0
  unsigned int v11; // w20
  const char *v12; // x2
  int v13; // w8
  __int64 v14; // x0

  v2 = a1 + 20480;
  if ( *(_BYTE *)(a1 + 21654) == 1 )
  {
    if ( (a2 & 1) != 0 )
    {
      v4 = *(_QWORD *)(a1 + 21328);
      *(_DWORD *)(a1 + 21360) = 0;
      v5 = readl_relaxed((unsigned int *)(v4 + 20));
      writel_relaxed(v5 | 1, (unsigned int *)(*(_QWORD *)(a1 + 21328) + 20LL));
      v6 = readl_relaxed(*(unsigned int **)(a1 + 21328));
      if ( (v6 & 1) != 0 )
        return;
      writel_relaxed(v6 | 1, *(unsigned int **)(a1 + 21328));
      v8 = wait_for_completion_timeout(v2 + 880, &print_fmt_i3c_log_info[2], v7);
      v9 = *(_QWORD *)(a1 + 2528);
      if ( v8 )
      {
        ipc_log_string(v9, "%s: IBI ctrl enabled\n", "geni_i3c_enable_ibi_ctrl");
        if ( !*(_QWORD *)(a1 + 8) )
          return;
      }
      else
      {
        ipc_log_string(v9, "timeout while ENABLE_CHANGE bit\n");
        if ( !*(_QWORD *)(a1 + 8) )
          return;
      }
      goto LABEL_17;
    }
    if ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 21328) + 12LL)) )
    {
      v10 = *(unsigned int **)(a1 + 21328);
      *(_DWORD *)(v2 + 960) = 0;
      *(_DWORD *)(v2 + 880) = 0;
      v11 = readl_relaxed(v10) & 0xFFFFFFFE;
      writel_relaxed(v11, *(unsigned int **)(a1 + 21328));
      v13 = wait_for_completion_timeout(v2 + 880, &print_fmt_i3c_log_info[2], v12);
      v14 = *(_QWORD *)(a1 + 2528);
      if ( !v13 )
      {
        ipc_log_string(v14, "timeout disabling IBI: 0x%x\n", *(_DWORD *)(v2 + 960));
        if ( !*(_QWORD *)(a1 + 8) )
          return;
        goto LABEL_17;
      }
      ipc_log_string(v14, "%s: IBI ctrl disabled\n", "geni_i3c_enable_ibi_ctrl");
      if ( *(_QWORD *)(a1 + 8) )
        i3c_trace_log();
    }
    else
    {
      v11 = 0;
    }
    ipc_log_string(*(_QWORD *)(a1 + 2528), "%s: IBI ctrl disabled, val:0x%x\n", "geni_i3c_enable_ibi_ctrl", v11);
    if ( !*(_QWORD *)(a1 + 8) )
      return;
LABEL_17:
    i3c_trace_log();
  }
}
