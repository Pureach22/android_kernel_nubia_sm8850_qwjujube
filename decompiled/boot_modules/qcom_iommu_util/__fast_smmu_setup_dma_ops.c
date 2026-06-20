__int64 __fastcall _fast_smmu_setup_dma_ops(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 domain_for_dev; // x0
  unsigned __int64 v5; // x20
  __int64 lock_irqsave; // x0
  __int64 v7; // x8
  unsigned __int64 v8; // x9
  __int64 v9; // x20
  __int64 v10; // x0
  unsigned __int64 v11; // x21
  __int64 v12; // x0
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x24
  void *v16; // x8
  __int64 host_bridge; // x21
  __int64 v18; // x0
  _QWORD *v19; // x26
  _QWORD *v20; // x27
  __int64 i; // x21
  __int64 v22; // x0
  _QWORD *v23; // x23
  __int64 j; // x21
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x10
  unsigned __int64 v27; // x9
  bool v28; // cf
  unsigned __int64 v29; // x10
  unsigned __int64 v30; // x22
  int v31; // w26
  __int64 v32; // x21
  __int64 v33; // x0
  __int64 v34; // x22
  int msi_cookie; // w23
  _QWORD *v36; // x8
  __int64 v37; // x9
  __int64 v38; // x9
  __int64 v39; // x10
  __int64 v40; // x9
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x10
  __int64 v43; // x12
  unsigned __int64 v44; // x13
  unsigned __int64 v45; // x9
  unsigned __int64 v46; // x10
  unsigned __int64 v47; // x22
  unsigned int v48; // w23
  _QWORD v49[2]; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v50; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+18h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = iommu_get_domain_for_dev(a2);
  if ( result )
  {
    result = qcom_iommu_get_mappings_configuration(result);
    if ( (result & 0x80000004) == 4 )
    {
      domain_for_dev = iommu_get_domain_for_dev(a2);
      if ( domain_for_dev )
      {
        v5 = domain_for_dev;
        lock_irqsave = raw_read_lock_irqsave(&mappings_lock);
        v7 = mappings;
        if ( !mappings )
        {
LABEL_10:
          raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
LABEL_12:
          result = dev_err(a2, "Missing fastmap iova cookie\n");
          goto LABEL_40;
        }
        while ( 1 )
        {
          while ( 1 )
          {
            v8 = *(_QWORD *)(v7 - 128);
            if ( v8 <= v5 )
              break;
            v7 = *(_QWORD *)(v7 + 16);
            if ( !v7 )
              goto LABEL_10;
          }
          if ( v8 >= v5 )
            break;
          v7 = *(_QWORD *)(v7 + 8);
          if ( !v7 )
            goto LABEL_10;
        }
        v9 = v7 - 136;
        raw_read_unlock_irqrestore(&mappings_lock, lock_irqsave);
        if ( !v9 )
          goto LABEL_12;
      }
      else
      {
        v9 = -22;
      }
      v10 = iommu_get_domain_for_dev(a2);
      if ( v10 )
      {
        v11 = v10;
        v12 = raw_read_lock_irqsave(&mappings_lock);
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
                goto LABEL_21;
            }
            if ( v14 >= v11 )
              break;
            v13 = *(_QWORD *)(v13 + 8);
            if ( !v13 )
              goto LABEL_21;
          }
          v15 = v13 - 136;
        }
        else
        {
LABEL_21:
          v15 = 0;
        }
        raw_read_unlock_irqrestore(&mappings_lock, v12);
      }
      else
      {
        v15 = -22;
      }
      v16 = *(void **)(a2 + 128);
      v49[0] = v49;
      v49[1] = v49;
      if ( v16 == &pci_bus_type )
      {
        host_bridge = qcom_pci_find_host_bridge(*(_QWORD *)(a2 - 184));
        v18 = raw_spin_lock_irqsave(v9 + 104);
        v19 = *(_QWORD **)(host_bridge + 952);
        v20 = (_QWORD *)(host_bridge + 952);
        for ( i = v18; v19 != v20; v19 = (_QWORD *)*v19 )
        {
          v36 = (_QWORD *)v19[2];
          v37 = v36[3] & 0x1F00LL;
          if ( v37 == 512 || v37 == 256 )
          {
            v38 = v19[3];
            v39 = *v36 - v38;
            v40 = v36[1] + ~v38;
            v41 = *(_QWORD *)(v9 + 24);
            v42 = v39 & 0xFFFFFFFFFFFFF000LL;
            v43 = v40 | 0xFFF;
            v44 = (v40 | 0xFFF) + 1;
            v45 = v41 <= v42 ? v42 : *(_QWORD *)(v9 + 24);
            v46 = *(_QWORD *)(v9 + 32) + v41 >= v44 ? v43 + 1 : *(_QWORD *)(v9 + 32) + v41;
            if ( v45 < v46 )
            {
              v47 = (v45 - v41) >> 12;
              v48 = ((v46 - v41) >> 12) - v47;
              _bitmap_set(*(_QWORD *)(v9 + 56), (unsigned int)v47, v48);
              _bitmap_set(*(_QWORD *)(v9 + 64), (unsigned int)v47, v48);
            }
          }
        }
        raw_spin_unlock_irqrestore(v9 + 104, i);
      }
      qcom_iommu_get_resv_regions(a2);
      v22 = raw_spin_lock_irqsave(v15 + 104);
      v23 = (_QWORD *)v49[0];
      for ( j = v22; v23 != v49; v23 = (_QWORD *)*v23 )
      {
        v25 = *(_QWORD *)(v9 + 24);
        v26 = v23[2];
        v27 = v25 + *(_QWORD *)(v9 + 32) - 1;
        if ( v27 >= v26 + v23[3] - 1 )
          v27 = v26 + v23[3] - 1;
        v28 = v26 >= v25;
        v29 = v26 - v25;
        if ( !v28 )
          v29 = 0;
        v30 = v29 >> 12;
        v31 = ((v27 - v25) >> 12) - (v29 >> 12);
        _bitmap_set(*(_QWORD *)(v9 + 56), (unsigned int)(v29 >> 12), (unsigned int)(v31 + 1));
        _bitmap_set(*(_QWORD *)(v9 + 64), (unsigned int)v30, (unsigned int)(v31 + 1));
      }
      raw_spin_unlock_irqrestore(v15 + 104, j);
      iommu_put_resv_regions(a2, v49);
      v50 = 0;
      mutex_lock(v9 + 160);
      v32 = raw_spin_lock_irqsave(v9 + 104);
      if ( !*(_QWORD *)(*(_QWORD *)(v9 + 8) + 64LL) && (qcom_iommu_get_msi_size(a2, (__int64)&v50) & 0x80000000) == 0 )
      {
        v33 = _fast_smmu_alloc_iova(v9, v50);
        if ( v33 == -1 )
        {
          dev_err(a2, "iova allocator failed to reserve MSI range of size: 0x%x\n", v50);
        }
        else
        {
          v34 = v33;
          raw_spin_unlock_irqrestore(v9 + 104, v32);
          msi_cookie = iommu_get_msi_cookie(*(_QWORD *)(v9 + 8), v34);
          v32 = raw_spin_lock_irqsave(v9 + 104);
          if ( msi_cookie < 0 )
          {
            dev_err(a2, "failed to obtain MSI iova cookie rc: %d\n", msi_cookie);
            _fast_smmu_free_iova(v9, v34, v50);
          }
        }
      }
      raw_spin_unlock_irqrestore(v9 + 104, v32);
      result = mutex_unlock(v9 + 160);
      *(_QWORD *)(a2 + 632) = fast_smmu_dma_ops;
    }
  }
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
