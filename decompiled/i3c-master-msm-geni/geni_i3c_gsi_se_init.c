__int64 __fastcall geni_i3c_gsi_se_init(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x9
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x0

  *(_DWORD *)(a1 + 108) = 3;
  geni_se_select_mode(a1, 3);
  ipc_log_string(*(_QWORD *)(a1 + 2528), "I3C in GSI ONLY mode\n");
  v2 = *(_QWORD *)(a1 + 8);
  if ( v2 )
  {
    i3c_trace_log();
    v2 = *(_QWORD *)(a1 + 8);
  }
  v3 = devm_kmalloc(v2, 224, 3520);
  *(_QWORD *)(a1 + 2808) = v3;
  if ( !v3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "could not allocate for tx_sg\n");
    v11 = *(_QWORD *)(a1 + 8);
    if ( v11 )
    {
      dev_err(v11, "could not allocate for tx_sg\n");
      if ( *(_QWORD *)(a1 + 8) )
        goto LABEL_16;
    }
    else
    {
      printk(&unk_1357A, v8, v9, v10);
      if ( *(_QWORD *)(a1 + 8) )
        goto LABEL_16;
    }
    return 4294967284LL;
  }
  v4 = devm_kmalloc(*(_QWORD *)(a1 + 8), 32, 3520);
  *(_QWORD *)(a1 + 12032) = v4;
  if ( !v4 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "could not allocate for rx_sg\n");
    v15 = *(_QWORD *)(a1 + 8);
    if ( !v15 )
    {
      printk(&unk_12BC0, v12, v13, v14);
      if ( !*(_QWORD *)(a1 + 8) )
        return 4294967284LL;
LABEL_16:
      i3c_trace_log();
      return 4294967284LL;
    }
    dev_err(v15, "could not allocate for rx_sg\n");
    if ( *(_QWORD *)(a1 + 8) )
      goto LABEL_16;
    return 4294967284LL;
  }
  v5 = *(_QWORD *)(a1 + 8);
  result = 0;
  *(_BYTE *)(a1 + 2712) = 4;
  *(_QWORD *)(a1 + 2720) = a1 + 2552;
  v7 = *(_QWORD *)(a1 + 2528);
  *(_QWORD *)(a1 + 2728) = v5;
  *(_QWORD *)(a1 + 21192) = v7;
  *(_QWORD *)(a1 + 11960) = gi3c_gsi_tx_cb;
  *(_QWORD *)(a1 + 21184) = gi3c_gsi_rx_cb;
  *(_QWORD *)(a1 + 21224) = gi3c_ev_cb;
  *(_QWORD *)(a1 + 21216) = a1 + 104;
  *(_QWORD *)(a1 + 21208) = a1 + 21240;
  *(_QWORD *)(a1 + 2736) = a1;
  return result;
}
