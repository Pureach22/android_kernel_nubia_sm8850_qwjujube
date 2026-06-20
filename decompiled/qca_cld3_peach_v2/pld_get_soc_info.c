__int64 __fastcall pld_get_soc_info(__int64 a1, void *s)
{
  __int64 v4; // x21
  __int64 v5; // x0
  __int64 v6; // x22
  unsigned int v7; // w8

  memset(s, 0, 0x128u);
  v4 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v5 = raw_spin_lock_irqsave(pld_ctx + 8);
    v6 = v4 + 16;
    do
    {
      v6 = *(_QWORD *)v6;
      if ( v6 == v4 + 16 )
      {
        raw_spin_unlock_irqrestore(v4 + 8, v5);
        return 4294967274LL;
      }
    }
    while ( *(_QWORD *)(v6 - 16) != a1 );
    raw_spin_unlock_irqrestore(v4 + 8, v5);
    if ( v6 != 16 )
    {
      v7 = *(_DWORD *)(v6 + 16);
      if ( v7 <= 7 )
      {
        if ( ((1 << v7) & 0xF6) != 0 )
          return 0;
        if ( !v7 )
          return ((__int64 (__fastcall *)(__int64, void *))pld_pcie_get_soc_info)(a1, s);
      }
    }
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
  }
  return 4294967274LL;
}
