__int64 __fastcall pld_is_device_awake(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x3
  __int64 result; // x0

  v2 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v3 = raw_spin_lock_irqsave(pld_ctx + 8);
    v4 = v2 + 16;
    do
    {
      v4 = *(_QWORD *)v4;
      if ( v4 == v2 + 16 )
      {
        raw_spin_unlock_irqrestore(v2 + 8, v3);
        goto LABEL_17;
      }
    }
    while ( *(_QWORD *)(v4 - 16) != a1 );
    raw_spin_unlock_irqrestore(v2 + 8, v3);
    if ( v4 == 16 )
      goto LABEL_17;
    v5 = *(unsigned int *)(v4 + 16);
    result = 1;
    if ( (int)v5 > 5 )
    {
      if ( (_DWORD)v5 == 6 )
        return 0;
      if ( (_DWORD)v5 == 7 )
        return result;
    }
    else
    {
      if ( (unsigned int)(v5 - 1) < 5 )
        return result;
      if ( !(_DWORD)v5 )
        return cnss_pci_is_device_awake(a1);
    }
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_17:
    v5 = 0xFFFFFFFFLL;
  }
  printk(&unk_9538F1, "pld_is_device_awake", 1245, v5);
  return 4294967274LL;
}
