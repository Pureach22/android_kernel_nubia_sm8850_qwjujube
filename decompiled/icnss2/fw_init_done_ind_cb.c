__int64 __fastcall fw_init_done_ind_cb(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x24
  __int64 v6; // x22
  int v9; // w8
  int v10; // w3
  __int64 v11; // x2
  const void *v12; // x4
  __int64 v13; // x0

  v5 = *(_QWORD *)(a1 + 1168);
  v6 = *(_QWORD *)(a1 - 616);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Received QMI WLFW FW initialization done indication\n");
  if ( !a3 )
  {
    printk("%sicnss2_qmi: Spurious indication\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: Spurious indication\n", (const char *)&unk_12DBF3);
  }
  if ( !*(_BYTE *)(a4 + 8)
    || (v9 = *(unsigned __int16 *)(a4 + 10), (unsigned int)(v9 - 1) > 0x18F)
    || (*(_WORD *)(a1 + 4888) = v9, !*(_BYTE *)a4)
    || (v10 = *(unsigned __int16 *)(a4 + 10),
        v11 = *(unsigned int *)(a4 + 4),
        (unsigned int)v11 > *(_DWORD *)(a1 + 1192) - v10) )
  {
    printk(
      "%sicnss2_qmi: Invalid Hang Data details, Offset:0x%x, Length:0x%x",
      byte_130B32,
      *(_DWORD *)(a4 + 4),
      *(unsigned __int16 *)(a4 + 10));
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Invalid Hang Data details, Offset:0x%x, Length:0x%x",
      (const char *)&unk_12DBF3,
      *(_DWORD *)(a4 + 4),
      *(unsigned __int16 *)(a4 + 10));
    goto LABEL_12;
  }
  if ( *(_QWORD *)(a1 + 4872) != v5 + v11 )
  {
    *(_QWORD *)(a1 + 4872) = v5 + v11;
    v13 = devm_ioremap(v6 + 16);
    *(_QWORD *)(a1 + 4880) = v13;
    if ( v13 )
    {
      LODWORD(v11) = *(_DWORD *)(a4 + 4);
      v10 = *(unsigned __int16 *)(a4 + 10);
      v12 = (const void *)v13;
      goto LABEL_10;
    }
    printk("%sicnss2_qmi: Hang Data ioremap failed: phy addr: %pa\n", byte_130B32, (const void *)(a1 + 4872));
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Hang Data ioremap failed: phy addr: %pa\n",
      (const char *)&unk_12DBF3,
      (const void *)(a1 + 4872));
LABEL_12:
    *(_WORD *)(a1 + 4888) = 0;
    *(_QWORD *)(a1 + 4880) = 0;
    *(_QWORD *)(a1 + 4872) = 0;
    return icnss_driver_event_post(a1 - 624, 9u, 0, 0);
  }
  v12 = *(const void **)(a1 + 4880);
LABEL_10:
  ipc_log_string(
    icnss_ipc_log_context,
    "icnss2_qmi: Hang Event Data details,Offset:0x%x, Length:0x%x,va_addr: 0x%pK\n",
    v11,
    v10,
    v12);
  return icnss_driver_event_post(a1 - 624, 9u, 0, 0);
}
