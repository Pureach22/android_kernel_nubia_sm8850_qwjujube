unsigned __int64 __fastcall fast_smmu_unmap_sg(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, char a5)
{
  __int64 domain_for_dev; // x0
  unsigned __int64 v11; // x24
  __int64 lock_irqsave; // x1
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x24
  unsigned __int64 v16; // x21
  __int64 v17; // x0
  int v18; // w20
  unsigned __int64 v19; // x19
  unsigned __int64 result; // x0
  __int64 v21; // x0
  unsigned __int64 v22; // x2
  __int64 v23; // x19

  domain_for_dev = iommu_get_domain_for_dev(a1);
  if ( domain_for_dev )
  {
    v11 = domain_for_dev;
    lock_irqsave = raw_read_lock_irqsave(&mappings_lock);
    v13 = mappings;
    if ( mappings )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v14 = *(_QWORD *)(v13 - 128);
          if ( v14 <= v11 )
            break;
          v13 = *(_QWORD *)(v13 + 16);
          if ( !v13 )
            goto LABEL_8;
        }
        if ( v14 >= v11 )
          break;
        v13 = *(_QWORD *)(v13 + 8);
        if ( !v13 )
          goto LABEL_8;
      }
      v15 = v13 - 136;
    }
    else
    {
LABEL_8:
      v15 = 0;
    }
    raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
    if ( (a5 & 0x20) == 0 )
      goto LABEL_13;
  }
  else
  {
    v15 = -22;
    if ( (a5 & 0x20) == 0 )
LABEL_13:
      fast_smmu_sync_sg_for_cpu(a1, a2, a3, a4);
  }
  v16 = *(_QWORD *)(a2 + 16);
  v17 = sg_next(a2);
  v18 = a3 - 1;
  if ( v18 >= 1 )
  {
    do
    {
      if ( !*(_DWORD *)(v17 + 24) )
        break;
      a2 = v17;
      v17 = sg_next(v17);
      --v18;
    }
    while ( v18 );
  }
  v19 = *(_QWORD *)(a2 + 16) - (v16 & 0xFFFFFFFFFFFFF000LL) + *(unsigned int *)(a2 + 24) + 4095;
  result = av8l_fast_unmap_public(*(_QWORD *)(v15 + 96), v16, v19 & 0xFFFFFFFFFFFFF000LL);
  if ( result )
  {
    v21 = raw_spin_lock_irqsave(v15 + 104);
    v22 = v19 >> 12;
    v23 = v21;
    _bitmap_clear(*(_QWORD *)(v15 + 56), (v16 - *(_QWORD *)(v15 + 24)) >> 12, v22);
    *(_BYTE *)(v15 + 80) = 1;
    return raw_spin_unlock_irqrestore(v15 + 104, v23);
  }
  return result;
}
