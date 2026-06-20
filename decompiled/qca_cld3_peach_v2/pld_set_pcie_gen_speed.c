__int64 __fastcall pld_set_pcie_gen_speed(__int64 a1, unsigned int a2)
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
        goto LABEL_11;
      }
    }
    while ( *(_QWORD *)(v6 - 16) != a1 );
    raw_spin_unlock_irqrestore(v3 + 8, v5);
    if ( v6 != 16 && !*(_DWORD *)(v6 + 16) )
      return cnss_set_pcie_gen_speed(a1, a2);
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
  }
LABEL_11:
  printk(&unk_9C3340, "pld_set_pcie_gen_speed", 634, v7);
  return 4294967274LL;
}
