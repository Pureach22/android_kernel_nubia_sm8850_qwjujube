__int64 __fastcall arm_smmu_domain_free(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  _QWORD *v3; // x21
  __int64 v4; // x22
  __int64 v5; // x22
  __int64 v6; // x8
  __int64 v7; // x0
  int v8; // w9
  unsigned int v9; // w8
  char v10; // w10
  int i; // w11
  __int64 v12; // x14
  __int64 v13; // x9
  __int64 v14; // x8
  __int64 v15; // x22
  unsigned int v17; // w8
  unsigned int v20; // w10
  unsigned __int64 v27; // x10

  v1 = a1;
  v2 = a1 - 184;
  if ( (*(_BYTE *)(a1 - 47) & 4) != 0 )
    a1 = fast_smmu_put_dma_cookie(a1);
  v3 = *(_QWORD **)(v1 - 184);
  if ( v3 )
  {
    v4 = *v3;
    if ( (*(_WORD *)(*v3 + 488LL) & 7) == 0 && (a1 = _pm_runtime_resume(*v3, 4), (a1 & 0x80000000) != 0) )
    {
      v17 = *(_DWORD *)(v4 + 480);
      do
      {
        if ( !v17 )
          break;
        _X12 = (unsigned int *)(v4 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v20 = __ldxr(_X12);
          if ( v20 != v17 )
            break;
          if ( !__stlxr(v17 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v20 == v17;
        v17 = v20;
      }
      while ( !_ZF );
    }
    else
    {
      if ( *(_BYTE *)(v1 + 120) == 1 && (*(_WORD *)(*v3 + 488LL) & 7) == 0 )
      {
        v5 = *v3;
        *(_QWORD *)(v5 + 520) = ktime_get_mono_fast_ns(a1);
        _pm_runtime_suspend(*v3, 13);
      }
      *(_QWORD *)(v3[10] + 48LL * *(unsigned __int8 *)(v1 - 136) + 40) = 0;
      arm_smmu_write_context_bank((__int64)v3, *(unsigned __int8 *)(v1 - 136));
      v6 = *(unsigned __int8 *)(v1 - 135);
      if ( v6 != 255 )
        devm_free_irq(*v3, *(unsigned int *)(v3[26] + 4 * v6), v2);
      v7 = qcom_free_io_pgtable_ops(*(_QWORD *)(v1 - 168));
      v8 = *((_DWORD *)v3 + 23);
      v9 = *(unsigned __int8 *)(v1 - 136);
      if ( !v8 )
        goto LABEL_17;
      v10 = 0;
      for ( i = 0; i != v8; ++i )
      {
        v12 = v3[14] + 24LL * i;
        if ( v9 == *(unsigned __int8 *)(v12 + 20) )
          v10 |= *(_BYTE *)(v12 + 21);
      }
      if ( (v10 & 1) == 0 )
      {
LABEL_17:
        v13 = v9 >> 6;
        v14 = 1LL << v9;
        _X9 = &v3[v13 + 8];
        __asm { PRFM            #0x11, [X9] }
        do
          v27 = __ldxr(_X9);
        while ( __stxr(v27 & ~v14, _X9) );
      }
      if ( (*(_WORD *)(*v3 + 488LL) & 7) == 0 )
      {
        v15 = *v3;
        *(_QWORD *)(v15 + 520) = ktime_get_mono_fast_ns(v7);
        _pm_runtime_suspend(*v3, 13);
      }
    }
  }
  iommu_logger_unregister(0, v1);
  return kfree(v2);
}
