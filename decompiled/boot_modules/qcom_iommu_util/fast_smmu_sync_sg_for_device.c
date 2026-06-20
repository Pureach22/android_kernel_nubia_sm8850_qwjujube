__int64 __fastcall fast_smmu_sync_sg_for_device(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  unsigned __int64 v4; // x21
  __int64 domain_for_dev; // x0
  unsigned __int64 v9; // x22
  __int64 lock_irqsave; // x1
  __int64 v11; // x8
  unsigned __int64 v12; // x9
  __int64 v13; // x22
  __int64 result; // x0
  __int64 v15; // x21

  v4 = *(_QWORD *)(a2 + 16);
  domain_for_dev = iommu_get_domain_for_dev(a1);
  if ( domain_for_dev )
  {
    v9 = domain_for_dev;
    lock_irqsave = raw_read_lock_irqsave(&mappings_lock);
    v11 = mappings;
    if ( mappings )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v12 = *(_QWORD *)(v11 - 128);
          if ( v12 <= v9 )
            break;
          v11 = *(_QWORD *)(v11 + 16);
          if ( !v11 )
            goto LABEL_8;
        }
        if ( v12 >= v9 )
          break;
        v11 = *(_QWORD *)(v11 + 8);
        if ( !v11 )
          goto LABEL_8;
      }
      v13 = v11 - 136;
    }
    else
    {
LABEL_8:
      v13 = 0;
    }
    raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
  }
  else
  {
    v13 = -22;
  }
  result = av8l_fast_iova_coherent_public(*(_QWORD *)(v13 + 96), v4);
  if ( a3 >= 1 && (result & 1) == 0 )
  {
    v15 = a2;
    do
    {
      qcom_arch_sync_dma_for_device(
        *(unsigned int *)(v15 + 8)
      + (((*(_QWORD *)v15 & 0x3FFFFFFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6)
      + 0x5000000000LL,
        *(unsigned int *)(v15 + 12),
        a4);
      result = sg_next(v15);
      --a3;
      v15 = result;
    }
    while ( a3 );
  }
  return result;
}
