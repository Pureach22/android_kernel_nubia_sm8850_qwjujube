__int64 __fastcall pld_get_tsf_gpio(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x3
  int v6; // w8

  v2 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
LABEL_14:
    printk(&unk_8EB76B, "pld_get_tsf_gpio", 2873, v5);
    return 4294967274LL;
  }
  v3 = raw_spin_lock_irqsave(pld_ctx + 8);
  v4 = v2 + 16;
  do
  {
    v4 = *(_QWORD *)v4;
    if ( v4 == v2 + 16 )
    {
      raw_spin_unlock_irqrestore(v2 + 8, v3);
      goto LABEL_14;
    }
  }
  while ( *(_QWORD *)(v4 - 16) != a1 );
  raw_spin_unlock_irqrestore(v2 + 8, v3);
  if ( v4 == 16 )
    goto LABEL_14;
  v6 = *(_DWORD *)(v4 + 16);
  if ( (unsigned int)(v6 - 1) < 7 )
    return 4294967274LL;
  if ( v6 )
    goto LABEL_14;
  return pld_pcie_get_tsf_gpio(a1);
}
