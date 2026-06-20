__int64 __fastcall qcedev_ce_high_bw_req(__int64 a1, char a2)
{
  int v4; // w8
  int v5; // w8
  unsigned int v6; // w0
  __int64 v7; // x3
  unsigned int v9; // w0
  __int64 v10; // x3

  mutex_lock(&qcedev_sent_bw_req);
  v4 = *(_DWORD *)(a1 + 20);
  if ( (a2 & 1) != 0 )
  {
    if ( !v4 )
    {
      if ( (unsigned int)qcedev_control_clocks(a1, 1) )
        return mutex_unlock(&qcedev_sent_bw_req);
      v9 = qce_set_irqs(*(_QWORD *)(a1 + 224), 1);
      if ( v9 )
      {
        printk(&unk_11E93, "qcedev_ce_high_bw_req", v9, v10);
        qcedev_control_clocks(a1, 0);
        return mutex_unlock(&qcedev_sent_bw_req);
      }
      v4 = *(_DWORD *)(a1 + 20);
    }
    v5 = v4 + 1;
    goto LABEL_9;
  }
  if ( v4 != 1 )
  {
LABEL_8:
    v5 = v4 - 1;
LABEL_9:
    *(_DWORD *)(a1 + 20) = v5;
    return mutex_unlock(&qcedev_sent_bw_req);
  }
  v6 = qce_set_irqs(*(_QWORD *)(a1 + 224), 0);
  if ( v6 )
  {
    printk(&unk_11FE7, "qcedev_ce_high_bw_req", v6, v7);
    return mutex_unlock(&qcedev_sent_bw_req);
  }
  if ( !(unsigned int)qcedev_control_clocks(a1, 0) )
  {
    v4 = *(_DWORD *)(a1 + 20);
    goto LABEL_8;
  }
  return mutex_unlock(&qcedev_sent_bw_req);
}
