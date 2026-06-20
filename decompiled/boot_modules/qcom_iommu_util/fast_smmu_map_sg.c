__int64 __fastcall fast_smmu_map_sg(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  __int64 domain_for_dev; // x0
  unsigned __int64 v11; // x24
  __int64 lock_irqsave; // x1
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x24
  int v16; // w1
  char v17; // w0
  __int64 v18; // x1
  char v19; // w25
  unsigned __int64 v20; // x26
  __int64 v21; // x27
  __int64 v22; // x26
  __int64 result; // x0
  unsigned int v24; // w22
  _QWORD v25[2]; // [xsp+0h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
    if ( (a5 & 0x8000) == 0 )
      goto LABEL_13;
LABEL_10:
    LOBYTE(v16) = 1;
    goto LABEL_16;
  }
  v15 = -22;
  if ( (a5 & 0x8000) != 0 )
    goto LABEL_10;
LABEL_13:
  if ( (a5 & 0x10000) != 0 )
    LOBYTE(v16) = 0;
  else
    v16 = (*(unsigned __int8 *)(a1 + 844) >> 5) & 1;
LABEL_16:
  v17 = qcom_dma_info_to_prot(a4, v16, a5);
  v18 = *(_QWORD *)(v15 + 16);
  v19 = v17;
  v25[0] = 0;
  v20 = qcom_iommu_dma_prepare_map_sg(a1, v18, a2, a3);
  v21 = raw_spin_lock_irqsave(v15 + 104);
  v22 = _fast_smmu_alloc_iova(v15, v20);
  raw_spin_unlock_irqrestore(v15 + 104, v21);
  if ( v22 == -1 )
  {
    qcom_iommu_dma_invalidate_sg(a2, a3);
    result = 0;
  }
  else
  {
    av8l_fast_map_sg_public(*(_QWORD *)(v15 + 96), v22, a2, a3, v19, v25);
    result = qcom_iommu_dma_finalise_sg(a1, a2, a3, v22);
    if ( (a5 & 0x20) == 0 )
    {
      v24 = result;
      fast_smmu_sync_sg_for_device(a1, a2, a3, a4);
      result = v24;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
