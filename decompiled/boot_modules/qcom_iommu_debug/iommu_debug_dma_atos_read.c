__int64 __fastcall iommu_debug_dma_atos_read(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 result; // x0
  __int64 v6; // x9
  __int64 v7; // x23
  __int64 v11; // x8
  __int64 v12; // x22
  __int64 v13; // [xsp+18h] [xbp-78h] BYREF
  _QWORD v14[12]; // [xsp+20h] [xbp-70h] BYREF
  int v15; // [xsp+80h] [xbp-10h]
  __int64 v16; // [xsp+88h] [xbp-8h]

  result = 0;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a4;
  v7 = *(_QWORD *)(a1 + 32);
  v15 = 0;
  memset(v14, 0, sizeof(v14));
  if ( !v6 )
  {
    mutex_lock(v7 + 56);
    if ( *(_QWORD *)(v7 + 40) )
    {
      v11 = *(_QWORD *)(*(_QWORD *)(v7 + 32) + 824LL);
      if ( v11 && *(_QWORD *)(v11 + 56) )
      {
        v13 = qcom_iommu_iova_to_phys_hard();
        if ( v13 )
        {
          v12 = (int)scnprintf(v14, 100, "%pa\n", &v13);
        }
        else
        {
          v12 = 5;
          strcpy((char *)v14, "FAIL\n");
        }
        mutex_unlock(v7 + 56);
        result = simple_read_from_buffer(a2, a3, a4, v14, v12);
      }
      else
      {
        printk(&unk_D2AE, "iommu_debug_dma_atos_read");
        mutex_unlock(v7 + 56);
        result = 0;
      }
    }
    else
    {
      printk(&unk_CE32, "iommu_debug_dma_atos_read");
      mutex_unlock(v7 + 56);
      result = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
