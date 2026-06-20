void __fastcall msm_geni_check_stop_engine(__int64 a1)
{
  __int16 v2; // w0
  bool v3; // w20
  bool v4; // w0
  __int64 v5; // x21
  int v6; // w0
  __int64 v7; // x21
  __int64 v8; // x8
  bool v9; // w0
  __int64 v10; // x20
  __int64 v11; // x3
  const char *v12; // x21
  bool v13; // w20
  bool v14; // w0
  __int64 v15; // x21
  int v16; // w0
  __int64 v17; // x21
  __int64 v18; // x8
  bool v19; // w0
  __int64 v20; // x20
  __int64 v21; // x3
  __int64 v22; // x20
  const char *v23; // x20
  __int64 v24; // x0
  const char *v25; // x1
  const char *v26; // x21

  v2 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
  if ( (v2 & 1) != 0 )
  {
    *(_BYTE *)(a1 + 1038) = 0;
    *(_BYTE *)(a1 + 1040) = 1;
    *(_DWORD *)(a1 + 1048) = 0;
    v13 = msm_serial_try_disable_interrupts(a1);
    writel_relaxed(4u, (unsigned int *)(*(_QWORD *)(a1 + 712) + 1540LL));
    v14 = geni_wait_for_cmd_done(a1, v13);
    v15 = *(_QWORD *)(a1 + 960);
    if ( v14 )
    {
      v16 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
      ipc_log_string(v15, "%s: TX Cancel cmd failed, geni_status:0x%x\n", "msm_geni_check_stop_engine", v16);
      v17 = *(_QWORD *)(a1 + 344);
      readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
      _ftrace_dbg(v17, "%s: TX Cancel cmd failed, geni_status:0x%x\n");
      v18 = *(_QWORD *)(a1 + 712);
      *(_BYTE *)(a1 + 1038) = 0;
      *(_DWORD *)(a1 + 1048) = 0;
      writel_relaxed(2u, (unsigned int *)(v18 + 1540));
      v19 = geni_wait_for_cmd_done(a1, v13);
      v20 = *(_QWORD *)(a1 + 960);
      if ( v19 )
      {
        v21 = (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
        v12 = "%s: TX abort cmd failed, geni_status:0x%x\n";
        ipc_log_string(v20, "%s: TX abort cmd failed, geni_status:0x%x\n", "msm_geni_check_stop_engine", v21);
        goto LABEL_9;
      }
      v26 = "%s: TX abort cmd done\n";
      ipc_log_string(v20, "%s: TX abort cmd done\n", "msm_geni_check_stop_engine");
      goto LABEL_15;
    }
    v23 = "%s: TX Cancel cmd done\n";
    ipc_log_string(v15, "%s: TX Cancel cmd done\n", "msm_geni_check_stop_engine");
  }
  else
  {
    if ( (v2 & 0x1000) == 0 )
      return;
    *(_BYTE *)(a1 + 1039) = 0;
    *(_BYTE *)(a1 + 1041) = 1;
    *(_DWORD *)(a1 + 1080) = 0;
    v3 = msm_serial_try_disable_interrupts(a1);
    writel_relaxed(4u, (unsigned int *)(*(_QWORD *)(a1 + 712) + 1588LL));
    v4 = geni_wait_for_cmd_done(a1, v3);
    v5 = *(_QWORD *)(a1 + 960);
    if ( v4 )
    {
      v6 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
      ipc_log_string(v5, "%s: RX Cancel cmd failed, geni_status:0x%x\n", "msm_geni_check_stop_engine", v6);
      v7 = *(_QWORD *)(a1 + 344);
      readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
      _ftrace_dbg(v7, "%s: RX Cancel cmd failed, geni_status:0x%x\n");
      v8 = *(_QWORD *)(a1 + 712);
      *(_BYTE *)(a1 + 1039) = 0;
      *(_DWORD *)(a1 + 1080) = 0;
      writel_relaxed(2u, (unsigned int *)(v8 + 1588));
      v9 = geni_wait_for_cmd_done(a1, v3);
      v10 = *(_QWORD *)(a1 + 960);
      if ( v9 )
      {
        v11 = (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
        v12 = "%s: RX abort cmd failed, geni_status:0x%x\n";
        ipc_log_string(v10, "%s: RX abort cmd failed, geni_status:0x%x\n", "msm_geni_check_stop_engine", v11);
LABEL_9:
        v22 = *(_QWORD *)(a1 + 344);
        readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
        _ftrace_dbg(v22, v12);
        return;
      }
      v26 = "%s: RX abort cmd done\n";
      ipc_log_string(v10, "%s: RX abort cmd done\n", "msm_geni_check_stop_engine");
LABEL_15:
      v24 = *(_QWORD *)(a1 + 344);
      v25 = v26;
      goto LABEL_16;
    }
    v23 = "%s: RX cancel cmd done\n";
    ipc_log_string(v5, "%s: RX cancel cmd done\n", "msm_geni_check_stop_engine");
  }
  v24 = *(_QWORD *)(a1 + 344);
  v25 = v23;
LABEL_16:
  _ftrace_dbg(v24, v25);
}
