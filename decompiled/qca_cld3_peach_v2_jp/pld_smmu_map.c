__int64 __fastcall pld_smmu_map(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x23
  __int64 v9; // x0
  __int64 v10; // x24
  __int64 v11; // x3
  __int64 result; // x0

  v5 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v9 = raw_spin_lock_irqsave(pld_ctx + 8);
    v10 = v5 + 16;
    do
    {
      v10 = *(_QWORD *)v10;
      if ( v10 == v5 + 16 )
      {
        raw_spin_unlock_irqrestore(v5 + 8, v9);
        goto LABEL_13;
      }
    }
    while ( *(_QWORD *)(v10 - 16) != a1 );
    raw_spin_unlock_irqrestore(v5 + 8, v9);
    if ( v10 == 16 )
      goto LABEL_13;
    v11 = *(unsigned int *)(v10 + 16);
    result = 0;
    if ( (unsigned int)(v11 - 4) >= 4 && (_DWORD)v11 != 1 )
    {
      if ( (_DWORD)v11 )
        goto LABEL_14;
      return cnss_smmu_map(a1, a2, a3, a4);
    }
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
LABEL_13:
    v11 = 0xFFFFFFFFLL;
LABEL_14:
    printk(&unk_886A85, "pld_smmu_map", 1783, v11);
    return 4294967274LL;
  }
  return result;
}
