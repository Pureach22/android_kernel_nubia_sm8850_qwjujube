void __fastcall qcom_slim_ngd_tx_msg_dma_cb(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x1
  int v4; // w8
  __int64 v5; // x20

  v1 = *(_QWORD *)(a1 + 8);
  if ( *(_BYTE *)(v1 + 5509) == 1 )
  {
    *(_BYTE *)(v1 + 5509) = 0;
    _slimbus_dbg();
    v4 = *(_DWORD *)(v1 + 5476);
    if ( v4 >= 2 )
    {
      printk(&unk_CC0B, v3);
      ipc_log_string(*(_QWORD *)(v1 + 5488), "Timedout due to delayed interrupt\n");
      if ( *(_DWORD *)(v1 + 5476) )
        goto LABEL_5;
    }
    else if ( v4 )
    {
LABEL_5:
      *(_QWORD *)(a1 + 16) = 0;
      return;
    }
    ipc_log_string(*(_QWORD *)(v1 + 5496), "Timedout due to delayed interrupt\n");
    goto LABEL_5;
  }
  v5 = raw_spin_lock_irqsave(v1 + 5144);
  if ( *(_QWORD *)(a1 + 16) )
  {
    complete(*(_QWORD *)(a1 + 16));
    *(_QWORD *)(a1 + 16) = 0;
  }
  *(_DWORD *)(v1 + 5428) = (*(_DWORD *)(v1 + 5428) + 1) % 30;
  raw_spin_unlock_irqrestore(v1 + 5144, v5);
}
