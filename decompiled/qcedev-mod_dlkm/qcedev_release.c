__int64 __fastcall qcedev_release(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *v4; // x20
  __int64 v6; // x21
  int v7; // w8
  unsigned int v8; // w0
  __int64 v9; // x3
  __int64 v10; // x2
  __int64 v11; // x3

  v4 = *(_QWORD **)(a2 + 32);
  v6 = *v4;
  if ( *v4 )
  {
    if ( *(_DWORD *)(v6 + 240) != 1447249220 )
      printk(&unk_126B9, "qcedev_release", *v4, a4);
    mutex_lock(&qcedev_sent_bw_req);
    v7 = *(_DWORD *)(v6 + 20);
    if ( v7 == 1 )
    {
      v8 = qce_set_irqs(*(_QWORD *)(v6 + 224), 0);
      if ( v8 )
      {
        printk(&unk_11FE7, "qcedev_ce_high_bw_req", v8, v9);
        goto LABEL_9;
      }
      if ( (unsigned int)qcedev_control_clocks(v6, 0) )
      {
LABEL_9:
        mutex_unlock(&qcedev_sent_bw_req);
        goto LABEL_10;
      }
      v7 = *(_DWORD *)(v6 + 20);
    }
    *(_DWORD *)(v6 + 20) = v7 - 1;
    goto LABEL_9;
  }
LABEL_10:
  if ( (unsigned int)qcedev_unmap_all_buffers(v4) )
    printk(&unk_12A39, "qcedev_release", v10, v11);
  kfree_sensitive(v4);
  *(_QWORD *)(a2 + 32) = 0;
  return 0;
}
