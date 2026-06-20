void __fastcall msm_geni_serial_init_gsi(__int64 a1)
{
  unsigned int v2; // w0
  const char *v3; // x21
  unsigned int v4; // w0
  unsigned int v5; // w0

  v2 = geni_icc_enable(a1 + 712);
  if ( v2 )
  {
    v3 = "%s: Error %d geni_icc_enable failed\n";
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Error %d geni_icc_enable failed\n", "msm_geni_serial_init_gsi", v2);
LABEL_7:
    _ftrace_dbg(*(_QWORD *)(a1 + 344), v3);
    return;
  }
  v4 = geni_icc_set_bw(a1 + 712);
  if ( v4 )
  {
    v3 = "%s: Error %d ICC BW voting failed\n";
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Error %d ICC BW voting failed\n", "msm_geni_serial_init_gsi", v4);
    goto LABEL_7;
  }
  *(_BYTE *)(a1 + 1136) = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 100LL)) & 1;
  v5 = geni_icc_disable(a1 + 712);
  if ( v5 )
  {
    v3 = "%s: Error %d geni_icc_disable failed\n";
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Error %d geni_icc_disable failed\n", "msm_geni_serial_init_gsi", v5);
    goto LABEL_7;
  }
  dev_info(*(_QWORD *)(a1 + 344), "gsi_mode:%d\n", *(unsigned __int8 *)(a1 + 1136));
  if ( *(_BYTE *)(a1 + 1136) == 1 )
  {
    *(_QWORD *)(a1 + 1144) = devm_kmalloc(*(_QWORD *)(a1 + 344), 704, 3520);
    *(_DWORD *)(a1 + 584) = 3;
    *(_QWORD *)(a1 + 1248) = alloc_workqueue("%s", byte_12);
    *(_QWORD *)(a1 + 1256) = alloc_workqueue("%s", byte_12);
    *(_QWORD *)(a1 + 1152) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 1160) = a1 + 1160;
    *(_QWORD *)(a1 + 1168) = a1 + 1160;
    *(_QWORD *)(a1 + 1176) = msm_geni_uart_gsi_xfer_tx;
    *(_QWORD *)(a1 + 1184) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 1192) = a1 + 1192;
    *(_QWORD *)(a1 + 1200) = a1 + 1192;
    *(_QWORD *)(a1 + 1216) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 1208) = msm_geni_uart_gsi_cancel_rx;
    *(_QWORD *)(a1 + 1224) = a1 + 1224;
    *(_QWORD *)(a1 + 1232) = a1 + 1224;
    *(_QWORD *)(a1 + 1240) = msm_geni_uart_gsi_cancel_tx;
  }
}
