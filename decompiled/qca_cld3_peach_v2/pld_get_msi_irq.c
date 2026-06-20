__int64 __fastcall pld_get_msi_irq(__int64 a1, unsigned int a2)
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
        goto LABEL_15;
      }
    }
    while ( *(_QWORD *)(v6 - 16) != a1 );
    raw_spin_unlock_irqrestore(v3 + 8, v5);
    if ( v6 == 16 )
      goto LABEL_15;
    v7 = *(unsigned int *)(v6 + 16);
    if ( (unsigned int)(v7 - 5) < 3 )
      return 0;
    if ( !(_DWORD)v7 )
      return cnss_get_msi_irq(a1, a2);
    if ( (unsigned int)(v7 - 1) < 4 )
    {
      printk(&unk_A0E3B2, "pld_get_msi_irq", 2167, v7);
      return 4294967277LL;
    }
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_15:
    v7 = 0xFFFFFFFFLL;
  }
  printk(&unk_9538F1, "pld_get_msi_irq", 2174, v7);
  return 4294967274LL;
}
