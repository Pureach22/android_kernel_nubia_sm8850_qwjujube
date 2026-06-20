__int64 __fastcall pld_smmu_get_domain(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x3
  void *v7; // x0
  __int64 v8; // x2

  v2 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_13:
    v5 = 0xFFFFFFFFLL;
LABEL_14:
    v7 = &unk_9538F1;
    v8 = 1716;
    goto LABEL_15;
  }
  v3 = raw_spin_lock_irqsave(pld_ctx + 8);
  v4 = v2 + 16;
  do
  {
    v4 = *(_QWORD *)v4;
    if ( v4 == v2 + 16 )
    {
      raw_spin_unlock_irqrestore(v2 + 8, v3);
      goto LABEL_13;
    }
  }
  while ( *(_QWORD *)(v4 - 16) != a1 );
  raw_spin_unlock_irqrestore(v2 + 8, v3);
  if ( v4 == 16 )
    goto LABEL_13;
  v5 = *(unsigned int *)(v4 + 16);
  if ( (unsigned int)v5 > 7 )
    goto LABEL_14;
  if ( ((1 << v5) & 0xF2) != 0 )
    return 0;
  if ( !(_DWORD)v5 )
    return cnss_smmu_get_domain(a1);
  v7 = &unk_A0E3B2;
  v8 = 1713;
LABEL_15:
  printk(v7, "pld_smmu_get_domain", v8, v5);
  return 0;
}
