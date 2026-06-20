__int64 __fastcall pld_force_wake_request_sync(__int64 a1, unsigned int a2)
{
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x3

  v3 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v5 = raw_spin_lock_irqsave(pld_ctx + 8);
    v6 = v3 + 16;
    do
    {
      v6 = *(_QWORD *)v6;
      if ( v6 == v3 + 16 )
      {
        raw_spin_unlock_irqrestore(v3 + 8, v5);
        goto LABEL_14;
      }
    }
    while ( *(_QWORD *)(v6 - 16) != a1 );
    raw_spin_unlock_irqrestore(v3 + 8, v5);
    if ( v6 == 16 )
      goto LABEL_14;
    v7 = *(unsigned int *)(v6 + 16);
    if ( (unsigned int)(v7 - 1) < 7 )
      return 0;
    if ( !(_DWORD)v7 )
      return cnss_pci_force_wake_request_sync(a1, a2);
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
LABEL_14:
    v7 = 0xFFFFFFFFLL;
  }
  printk(&unk_886A85, "pld_force_wake_request_sync", 1189, v7);
  return 4294967274LL;
}
