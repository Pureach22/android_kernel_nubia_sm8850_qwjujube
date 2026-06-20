__int64 __fastcall spcom_dmabuf_unlock(__int64 a1, char a2, __int64 a3)
{
  unsigned int v4; // w5
  __int64 v5; // x0
  __int64 result; // x0
  int v7; // w20

  if ( !a1 )
  {
    printk(&unk_12409, "spcom_dmabuf_unlock", a3);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: Invalid dmabuf info pointer\n", "spcom_dmabuf_unlock", &unk_F80E);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a1 + 8) )
  {
    printk(&unk_103A2, "spcom_dmabuf_unlock", a3);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: DMA buffer handle is NULL\n", "spcom_dmabuf_unlock", &unk_F80E);
    return 4294967274LL;
  }
  v4 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1804);
  if ( (a2 & 1) == 0 )
    goto LABEL_6;
  if ( !v4 )
  {
    printk(&unk_12A8F, "spcom_dmabuf_unlock", a3);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: Unknown PID\n", "spcom_dmabuf_unlock", &unk_F80E);
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a1 + 32) != v4 )
  {
    v7 = v4;
    printk(&unk_FDCA, "spcom_dmabuf_unlock", v4);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: PID [%u] is not the owner of this DMA buffer\n",
      "spcom_dmabuf_unlock",
      (const char *)&unk_F80E,
      v7);
    return 0xFFFFFFFFLL;
  }
LABEL_6:
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: unlock dmbuf fd [%d], PID [%u]\n",
    "spcom_dmabuf_unlock",
    (const char *)&unk_F80E,
    *(_DWORD *)a1,
    v4);
  v5 = *(_QWORD *)(a1 + 16);
  if ( v5 )
  {
    dma_buf_unmap_attachment_unlocked(v5, *(_QWORD *)(a1 + 24), 0);
    dma_buf_detach(*(_QWORD *)(a1 + 8), *(_QWORD *)(a1 + 16));
    *(_QWORD *)(a1 + 16) = 0;
    *(_QWORD *)(a1 + 24) = 0;
  }
  dma_buf_put(*(_QWORD *)(a1 + 8));
  result = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_DWORD *)a1 = -1;
  *(_DWORD *)(a1 + 32) = 0;
  return result;
}
