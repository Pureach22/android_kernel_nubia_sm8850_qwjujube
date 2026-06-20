__int64 __fastcall modify_dma_buf_addr(const char *a1, __int64 a2, __int64 a3, unsigned int *a4)
{
  unsigned int v4; // w19
  unsigned __int64 v5; // x21
  __int64 v8; // x20
  unsigned __int64 v9; // x0
  __int64 v10; // x2
  unsigned __int64 v11; // x19
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x20
  unsigned __int64 v14; // x0
  __int64 v15; // x2
  unsigned __int64 v16; // x24
  __int64 v17; // x25
  __int64 v18; // x27
  const char *v19; // x28
  int v20; // w21
  __int64 v21; // x0
  unsigned int v22; // w20

  v4 = *a4;
  if ( (*a4 & 0x80000000) != 0 )
  {
    printk(&unk_10B52, "modify_dma_buf_addr", v4);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: invalid fd [%d]\n", "modify_dma_buf_addr", &unk_F80E, v4);
LABEL_24:
    LODWORD(v13) = -19;
    return (unsigned int)v13;
  }
  if ( (unsigned int)a3 <= 7 )
  {
    v22 = a3;
    printk(&unk_10F26, "modify_dma_buf_addr", a3);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: buf size too small [%d]\n",
      "modify_dma_buf_addr",
      &unk_F80E,
      v22);
    goto LABEL_24;
  }
  v5 = a4[1];
  v8 = (unsigned int)a3;
  if ( (v5 & 7) != 0 )
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: offset [%d] is NOT 64-bit aligned\n",
      "modify_dma_buf_addr",
      &unk_F80E,
      (unsigned int)v5);
  else
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: offset [%d] is 64-bit aligned\n",
      "modify_dma_buf_addr",
      &unk_F80E,
      (unsigned int)v5);
  if ( v8 - 8 < v5 )
  {
    printk(&unk_EC94, "modify_dma_buf_addr", (unsigned int)v5);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: invalid buf_offset [%d]\n",
      "modify_dma_buf_addr",
      &unk_F80E,
      (unsigned int)v5);
    goto LABEL_24;
  }
  v9 = dma_buf_get(v4);
  if ( !v9 || (v11 = v9, v9 >= 0xFFFFFFFFFFFFF001LL) )
  {
    printk(&unk_111CB, "modify_dma_buf_addr", v10);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: fail to get dma buf handle\n",
      "modify_dma_buf_addr",
      (const char *)&unk_F80E);
    LODWORD(v13) = -22;
    return (unsigned int)v13;
  }
  v12 = dma_buf_attach(v9, *(_QWORD *)(spcom_dev + 1184) + 16LL);
  v13 = v12;
  if ( !v12 || v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_10953, "modify_dma_buf_addr", (unsigned int)v12);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: fail to attach dma buf %d\n",
      "modify_dma_buf_addr",
      (const char *)&unk_F80E,
      v13);
    dma_buf_put(v11);
    return (unsigned int)v13;
  }
  v14 = dma_buf_map_attachment_unlocked(v12, 0);
  v16 = v14;
  if ( !v14 || v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_12DF3, "modify_dma_buf_addr", (unsigned int)v14);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: fail to get sg table of dma buf %d\n",
      "modify_dma_buf_addr",
      (const char *)&unk_F80E,
      v16);
LABEL_30:
    dma_buf_detach(v11, v13);
    dma_buf_put(v11);
    LODWORD(v13) = v16;
    return (unsigned int)v13;
  }
  if ( !*(_QWORD *)v14 )
  {
    printk(&unk_111F3, "modify_dma_buf_addr", v15);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: sgl is NULL\n", "modify_dma_buf_addr", (const char *)&unk_F80E);
    v20 = -12;
LABEL_29:
    dma_buf_unmap_attachment_unlocked(v13, v16, 0);
    LODWORD(v16) = v20;
    goto LABEL_30;
  }
  v17 = *(_QWORD *)(*(_QWORD *)v14 + 16LL);
  v18 = 0;
  while ( 1 )
  {
    v19 = &a1[v18];
    if ( *(_QWORD *)&a1[v18 + 352] == v11 )
      break;
    v18 += 40;
    if ( v18 == 1440 )
    {
      printk(&unk_E7E7, "modify_dma_buf_addr", a1);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s]: trying to send modified command on unlocked buffer\n",
        "modify_dma_buf_addr",
        (const char *)&unk_F80E,
        a1);
      v20 = -1;
      goto LABEL_29;
    }
  }
  v21 = *((_QWORD *)v19 + 45);
  if ( v21 )
  {
    dma_buf_unmap_attachment_unlocked(v21, *(_QWORD *)&a1[v18 + 368], 0);
    dma_buf_detach(v11, *((_QWORD *)v19 + 45));
  }
  *((_QWORD *)v19 + 45) = v13;
  *(_QWORD *)&a1[v18 + 368] = v16;
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: dma phys addr = [0x%lx]\n",
    "modify_dma_buf_addr",
    (const char *)&unk_F80E,
    v17);
  *(_QWORD *)(a2 + v5) = v17;
  dma_buf_put(v11);
  LODWORD(v13) = 0;
  return (unsigned int)v13;
}
