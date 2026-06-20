unsigned __int64 __fastcall fast_smmu_sync_single_for_cpu(__int64 a1, unsigned __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 domain_for_dev; // x0
  unsigned __int64 v8; // x22
  __int64 lock_irqsave; // x1
  __int64 v10; // x8
  unsigned __int64 v11; // x9
  __int64 v12; // x22
  unsigned __int64 result; // x0
  unsigned __int64 v14; // x0

  domain_for_dev = iommu_get_domain_for_dev(a1);
  if ( domain_for_dev )
  {
    v8 = domain_for_dev;
    lock_irqsave = raw_read_lock_irqsave(&mappings_lock);
    v10 = mappings;
    if ( mappings )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v11 = *(_QWORD *)(v10 - 128);
          if ( v11 <= v8 )
            break;
          v10 = *(_QWORD *)(v10 + 16);
          if ( !v10 )
            goto LABEL_8;
        }
        if ( v11 >= v8 )
          break;
        v10 = *(_QWORD *)(v10 + 8);
        if ( !v10 )
          goto LABEL_8;
      }
      v12 = v10 - 136;
    }
    else
    {
LABEL_8:
      v12 = 0;
    }
    raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
  }
  else
  {
    v12 = -22;
  }
  result = av8l_fast_iova_coherent_public(*(_QWORD *)(v12 + 96), a2);
  if ( (result & 1) == 0 )
  {
    v14 = av8l_fast_iova_to_phys_public(*(_QWORD *)(v12 + 96), a2);
    if ( !v14 )
      __break(0x800u);
    return qcom_arch_sync_dma_for_cpu(v14, a3, a4);
  }
  return result;
}
