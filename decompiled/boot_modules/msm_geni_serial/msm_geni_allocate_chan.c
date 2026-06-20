__int64 __fastcall msm_geni_allocate_chan(_QWORD *a1)
{
  _QWORD *v2; // x8
  unsigned int v3; // w20
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x9
  __int64 v6; // x8
  __int64 (*v7)(void); // x8
  unsigned int v8; // w0
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x9
  _QWORD *v11; // x8
  __int64 (*v12)(void); // x8

  ipc_log_string(a1[120], "%s: Start\n", "msm_geni_allocate_chan");
  _ftrace_dbg(a1[43], "%s: Start\n");
  v2 = (_QWORD *)a1[143];
  if ( !v2[1] )
  {
    v4 = dma_request_chan(a1[43], "rx");
    if ( v4 <= 0xFFFFFFFFFFFFF000LL )
      v5 = v4;
    else
      v5 = 0;
    *(_QWORD *)(a1[143] + 8LL) = v5;
    v6 = a1[143];
    if ( !*(_QWORD *)(v6 + 8) )
    {
      dev_err(a1[43], "%s:Failed to allocate RX slv ch\n", "msm_geni_allocate_chan");
      v3 = -5;
      goto LABEL_21;
    }
    *(_QWORD *)(v6 + 224) = msm_geni_uart_ev_cb;
    *(_QWORD *)(a1[143] + 232LL) = a1;
    *(_DWORD *)(a1[143] + 216LL) = 1;
    *(_QWORD *)(*(_QWORD *)(a1[143] + 8LL) + 104LL) = a1[143] + 216LL;
    v7 = *(__int64 (**)(void))(**(_QWORD **)(a1[143] + 8LL) + 312LL);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != -1098344795 )
        __break(0x8228u);
      v8 = v7();
      if ( !v8 )
      {
        if ( *(_QWORD *)a1[143] )
          goto LABEL_3;
        goto LABEL_13;
      }
      v3 = v8;
    }
    else
    {
      v3 = -38;
    }
    dev_err(a1[43], "Failed to Config Rx\n");
    dma_release_channel(*(_QWORD *)(a1[143] + 8LL));
    goto LABEL_21;
  }
  if ( *v2 )
  {
LABEL_3:
    v3 = 0;
    goto LABEL_21;
  }
LABEL_13:
  v9 = dma_request_chan(a1[43], "tx");
  if ( v9 <= 0xFFFFFFFFFFFFF000LL )
    v10 = v9;
  else
    v10 = 0;
  *(_QWORD *)a1[143] = v10;
  v11 = (_QWORD *)a1[143];
  if ( !*v11 )
  {
    dev_err(a1[43], "%s:Failed to allocate TX slv ch\n", "msm_geni_allocate_chan");
    dma_release_channel(*(_QWORD *)(a1[143] + 8LL));
    v3 = -5;
    *(_QWORD *)(a1[143] + 8LL) = 0;
    goto LABEL_21;
  }
  v11[25] = msm_geni_uart_ev_cb;
  *(_QWORD *)(a1[143] + 208LL) = a1;
  *(_DWORD *)(a1[143] + 192LL) = 1;
  *(_QWORD *)(*(_QWORD *)a1[143] + 104LL) = a1[143] + 192LL;
  v12 = *(__int64 (**)(void))(**(_QWORD **)a1[143] + 312LL);
  if ( !v12 )
  {
    v3 = -38;
LABEL_28:
    dev_err(a1[43], "Failed to Config Tx\n");
    msm_geni_deallocate_chan(a1);
    goto LABEL_21;
  }
  if ( *((_DWORD *)v12 - 1) != -1098344795 )
    __break(0x8228u);
  v3 = v12();
  if ( v3 )
    goto LABEL_28;
LABEL_21:
  ipc_log_string(a1[120], "%s: End\n", "msm_geni_allocate_chan");
  _ftrace_dbg(a1[43], "%s: End\n");
  return v3;
}
