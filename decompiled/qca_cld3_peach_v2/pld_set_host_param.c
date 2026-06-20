__int64 __fastcall pld_set_host_param(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 v6; // x22
  int v7; // w8

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
        return 4294967274LL;
      }
    }
    while ( *(_QWORD *)(v6 - 16) != a1 );
    raw_spin_unlock_irqrestore(v3 + 8, v5);
    if ( v6 == 16 )
      return 4294967274LL;
    v7 = *(_DWORD *)(v6 + 16);
    if ( (unsigned int)(v7 - 1) < 7 )
      return 0;
    if ( !v7 )
      return pld_pcie_set_host_param(a1, a2);
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
  }
  return 4294967274LL;
}
