__int64 __fastcall pld_get_iova_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x22
  __int64 v7; // x0
  __int64 v8; // x23
  int v9; // w8

  v4 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v7 = raw_spin_lock_irqsave(pld_ctx + 8);
    v8 = v4 + 16;
    do
    {
      v8 = *(_QWORD *)v8;
      if ( v8 == v4 + 16 )
      {
        raw_spin_unlock_irqrestore(v4 + 8, v7);
        return 4294967201LL;
      }
    }
    while ( *(_QWORD *)(v8 - 16) != a1 );
    raw_spin_unlock_irqrestore(v4 + 8, v7);
    if ( v8 == 16 )
      return 4294967201LL;
    v9 = *(_DWORD *)(v8 + 16);
    if ( v9 == 6 )
    {
      return 4294967274LL;
    }
    else
    {
      if ( v9 )
        return 4294967201LL;
      return cnss_pci_get_iova_info(a1, a2, a3);
    }
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
    return 4294967201LL;
  }
}
