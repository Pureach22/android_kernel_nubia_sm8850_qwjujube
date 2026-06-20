void __fastcall qcom_geni_i3c_ibi_unconf(__int64 a1)
{
  __int64 v2; // x22
  __int64 v3; // x0
  __int64 v4; // x21
  unsigned __int64 v5; // x20
  unsigned int v6; // w21
  int v7; // w23
  __int64 v8; // x8
  const char *v9; // x2
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x0
  __int64 v14; // x21
  __int64 v15; // x0
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x0

  v2 = a1 + 20480;
  v3 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 21328) + 4120LL));
  if ( !(_DWORD)v3 )
    goto LABEL_19;
  v4 = *(_QWORD *)(a1 + 2536);
  if ( !v4 )
  {
    v5 = -22;
    if ( !*(_DWORD *)(v2 + 856) )
      goto LABEL_15;
    goto LABEL_9;
  }
  if ( *(_DWORD *)(a1 + 2544) )
  {
    v5 = sched_clock(v3);
    v3 = ipc_log_string(v4, "%s:start at %llu nsec(%llu usec)\n", "qcom_deallocate_ibi_table_entry", v5, v5 / 0x3E8);
    if ( !*(_DWORD *)(v2 + 856) )
      goto LABEL_15;
LABEL_9:
    v6 = 0;
    v7 = 6144;
    while ( 1 )
    {
      v8 = *(_QWORD *)(a1 + 21328);
      *(_DWORD *)(v2 + 960) = 0;
      *(_DWORD *)(v2 + 880) = 0;
      v3 = readl_relaxed((unsigned int *)(v8 + v7));
      if ( (v3 & 1) != 0 )
      {
        writel_relaxed(v3 & 0xFFFFFFFE, (unsigned int *)(*(_QWORD *)(a1 + 21328) + 4096LL));
        v3 = wait_for_completion_timeout(v2 + 880, &print_fmt_i3c_log_info[2], v9);
        if ( !(_DWORD)v3 )
          break;
      }
      ++v6;
      v7 += 128;
      if ( v6 >= *(_DWORD *)(v2 + 856) )
        goto LABEL_15;
    }
    ipc_log_string(*(_QWORD *)(a1 + 2528), "timeout while adding slave IBI\n");
    v13 = *(_QWORD *)(a1 + 8);
    if ( v13 )
      dev_err(v13, "timeout while adding slave IBI\n");
    else
      printk(&unk_1373F, v10, v11, v12);
    if ( *(_QWORD *)(a1 + 8) )
      goto LABEL_30;
    return;
  }
  v5 = 0;
  if ( *(_DWORD *)(v2 + 856) )
    goto LABEL_9;
LABEL_15:
  v14 = *(_QWORD *)(a1 + 2536);
  if ( v14 && v5 && *(_DWORD *)(a1 + 2544) )
  {
    v15 = sched_clock(v3);
    ipc_log_string(
      v14,
      "%s:took %llu nsec(%llu usec)\n",
      "qcom_deallocate_ibi_table_entry",
      v15 - v5,
      (v15 - v5) / 0x3E8);
  }
LABEL_19:
  geni_i3c_enable_ibi_ctrl(a1, 0);
  writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 + 21328) + 12LL));
  writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 + 21328) + 4104LL));
  if ( *(_BYTE *)(v2 + 1174) == 1 )
    writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 + 21328) + 20LL));
  if ( *(_BYTE *)(v2 + 980) != 1 || *(_BYTE *)(v2 + 981) != 1 || !(unsigned int)geni_i3c_enable_naon_ibi_clks(a1, 0) )
  {
    *(_BYTE *)(v2 + 841) = 0;
    return;
  }
  ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:  NAON clock failure\n", "qcom_geni_i3c_ibi_unconf");
  v18 = *(_QWORD *)(a1 + 8);
  if ( v18 )
    dev_err(v18, "%s:  NAON clock failure\n", "qcom_geni_i3c_ibi_unconf");
  else
    printk(&unk_13A7A, "qcom_geni_i3c_ibi_unconf", v16, v17);
  if ( *(_QWORD *)(a1 + 8) )
LABEL_30:
    i3c_trace_log();
}
