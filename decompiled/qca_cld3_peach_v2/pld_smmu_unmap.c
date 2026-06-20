__int64 __fastcall pld_smmu_unmap(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v4; // x22
  __int64 v7; // x0
  __int64 v8; // x23
  __int64 v9; // x3

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
        goto LABEL_14;
      }
    }
    while ( *(_QWORD *)(v8 - 16) != a1 );
    raw_spin_unlock_irqrestore(v4 + 8, v7);
    if ( v8 == 16 )
      goto LABEL_14;
    v9 = *(unsigned int *)(v8 + 16);
    if ( (unsigned int)v9 <= 7 )
    {
      if ( ((1 << v9) & 0x42) != 0 )
        return 0;
      if ( !(_DWORD)v9 )
        return cnss_smmu_unmap(a1, a2, a3);
      if ( ((1 << v9) & 0xB0) != 0 )
      {
        printk(&unk_A0E3B2, "pld_smmu_unmap", 1811, v9);
        return 0;
      }
    }
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_14:
    v9 = 0xFFFFFFFFLL;
  }
  printk(&unk_9538F1, "pld_smmu_unmap", 1814, v9);
  return 4294967274LL;
}
