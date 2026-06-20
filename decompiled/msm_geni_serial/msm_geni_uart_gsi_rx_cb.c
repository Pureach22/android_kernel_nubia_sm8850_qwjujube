void __fastcall msm_geni_uart_gsi_rx_cb(unsigned int *a1)
{
  __int64 v1; // x24
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x1
  __int64 v6; // x1
  int inserted; // w21
  __int64 v8; // x8
  __int64 v9; // x0
  int v10; // w8
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x21
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x0
  __int64 (*v17)(void); // x9
  __int64 v18; // x8
  __int64 (*v19)(void); // x8
  unsigned int v20; // w0
  void (*v21)(void); // x8
  __int64 v22; // x0
  void (*v23)(void); // x8
  unsigned __int64 v24; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v25; // [xsp+10h] [xbp-A0h]
  __int64 v26; // [xsp+18h] [xbp-98h]
  __int64 v27; // [xsp+20h] [xbp-90h]
  __int64 v28; // [xsp+28h] [xbp-88h]
  __int64 v29; // [xsp+30h] [xbp-80h]
  __int64 v30; // [xsp+38h] [xbp-78h]
  __int64 v31; // [xsp+40h] [xbp-70h]
  __int64 v32; // [xsp+48h] [xbp-68h]
  __int64 v33; // [xsp+50h] [xbp-60h]
  __int64 v34; // [xsp+58h] [xbp-58h]
  __int64 v35; // [xsp+60h] [xbp-50h]
  _QWORD v36[9]; // [xsp+68h] [xbp-48h] BYREF

  v36[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *((_QWORD *)a1 + 4);
  v2 = *a1;
  v3 = *(_QWORD *)(v1 + 208);
  ipc_log_string(*(_QWORD *)(v1 + 944), "%s: Start\n", "msm_geni_uart_gsi_rx_cb");
  _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: Start\n");
  v4 = *(unsigned int *)(v1 + 1328);
  if ( (unsigned int)v4 >= 5 )
    goto LABEL_29;
  v5 = *(_QWORD *)(v1 + 832 + 8 * v4);
  LOBYTE(v24) = 0;
  inserted = _tty_insert_flip_string_flags(v3, v5, &v24, 0, v2);
  if ( (_DWORD)v2 != inserted )
  {
    ipc_log_string(*(_QWORD *)(v1 + 944), "%s: ret %d rx_bytes %d\n", "msm_geni_uart_gsi_rx_cb", inserted, v2);
    _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: ret %d rx_bytes %d\n");
  }
  *(_DWORD *)(v1 + 232) += inserted;
  tty_flip_buffer_push(v3, v6);
  v8 = *(unsigned int *)(v1 + 1328);
  if ( (unsigned int)v8 > 4 )
    goto LABEL_29;
  v9 = *(_QWORD *)(v1 + 832 + 8 * v8);
  v10 = (int)v2 >= 32 ? 32 : v2;
  v11 = *(_QWORD *)(v1 + 944);
  memset(v36, 0, 64);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  hex_dump_to_buffer(v9, v10, 32, 1, v36, 64, 0);
  scnprintf(&v24, 96, "%s[0x%.10x:%d] : %s", "GSI Rx", 0, v2, (const char *)v36);
  ipc_log_string(v11, "%s : %s\n", "dump_ipc", (const char *)&v24);
  _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s : %s\n");
  v12 = *(_QWORD *)(v1 + 960);
  v13 = *(unsigned int *)(v1 + 1328);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  ipc_log_string(v12, "%s: Start\n", "msm_geni_uart_rx_queue_dma_tre");
  _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: Start\n");
  sg_init_table(&v24, 1);
  if ( (unsigned int)v13 >= 6 )
LABEL_29:
    __break(0x5512u);
  v14 = *(_QWORD *)(v1 + 1144);
  v15 = v14 + 16 * v13 + 96;
  v25 = v15 & 0xFFF | 0x1000000000LL;
  v16 = *(_QWORD *)(v14 + 8);
  v24 = (v24 & 3 | ((unsigned __int64)((v15 << 8 >> 8) + 0x8000000000LL) >> 12 << 6)) - 0x140000000LL;
  if ( v16 )
  {
    if ( *(_QWORD *)v16 && (v17 = *(__int64 (**)(void))(*(_QWORD *)v16 + 272LL)) != nullptr )
    {
      if ( *((_DWORD *)v17 - 1) != -1221891457 )
        __break(0x8229u);
      v16 = v17();
      v14 = *(_QWORD *)(v1 + 1144);
    }
    else
    {
      v16 = 0;
    }
  }
  *(_QWORD *)(v14 + 600) = v16;
  v18 = *(_QWORD *)(*(_QWORD *)(v1 + 1144) + 600LL);
  if ( v18 )
  {
    *(_QWORD *)(v18 + 40) = msm_geni_uart_gsi_rx_cb;
    *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 1144) + 600LL) + 56LL) = *(_QWORD *)(v1 + 1144) + 656LL;
    v19 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v1 + 1144) + 600LL) + 24LL);
    if ( *((_DWORD *)v19 - 1) != 1188179853 )
      __break(0x8228u);
    v20 = v19();
    if ( (v20 & 0x80000000) != 0 )
    {
      printk(&unk_14AEE, "msm_geni_uart_rx_queue_dma_tre", v20);
      v23 = *(void (**)(void))(**(_QWORD **)(*(_QWORD *)(v1 + 1144) + 8LL) + 336LL);
      if ( v23 )
      {
        if ( *((_DWORD *)v23 - 1) != -403578064 )
          __break(0x8228u);
        v23();
      }
    }
    else
    {
      v21 = *(void (**)(void))(**(_QWORD **)(*(_QWORD *)(v1 + 1144) + 8LL) + 360LL);
      if ( *((_DWORD *)v21 - 1) != 905352215 )
        __break(0x8228u);
      v21();
      ipc_log_string(*(_QWORD *)(v1 + 960), "%s: End\n", "msm_geni_uart_rx_queue_dma_tre");
      _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: End\n");
    }
  }
  else
  {
    dev_err(*(_QWORD *)(v1 + 344), "%s:Prep_slave_sg failed\n", "msm_geni_uart_rx_queue_dma_tre");
  }
  v22 = *(_QWORD *)(v1 + 944);
  *(_DWORD *)(v1 + 1328) = ((unsigned __int8)*(_DWORD *)(v1 + 1328) + 1) & 3;
  ipc_log_string(v22, "%s: End\n", "msm_geni_uart_gsi_rx_cb");
  _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: End\n");
  _ReadStatusReg(SP_EL0);
}
