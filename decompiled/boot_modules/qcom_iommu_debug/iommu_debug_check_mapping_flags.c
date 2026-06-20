__int64 __fastcall iommu_debug_check_mapping_flags(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  __int64 v6; // x20
  __int64 v8; // x21
  __int64 domain_for_dev; // x0
  __int64 v11; // x8
  __int64 v12; // x8
  int v13; // w9
  __int64 v14; // x22
  __int64 v15; // x24
  __int64 v16; // x0
  __int64 result; // x0
  __int64 v18; // [xsp+8h] [xbp-38h] BYREF
  __int64 v19; // [xsp+10h] [xbp-30h] BYREF
  __int64 v20; // [xsp+18h] [xbp-28h] BYREF
  int v21; // [xsp+20h] [xbp-20h]
  int v22; // [xsp+24h] [xbp-1Ch]
  __int64 v23; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v24[2]; // [xsp+30h] [xbp-10h] BYREF

  v6 = a4;
  v8 = a2;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = a4;
  v24[0] = a2;
  domain_for_dev = iommu_get_domain_for_dev();
  if ( !domain_for_dev )
  {
    dev_err(a1, "iommu_get_domain_for_dev() failed\n");
    goto LABEL_14;
  }
  v11 = *(_QWORD *)(a1 + 824);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 56)) == 0 )
  {
    dev_err(a1, "dev_iommu_fwspec_get() failed\n");
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  v13 = *(unsigned __int16 *)(v12 + 16);
  v20 = v8;
  v21 = a5;
  v22 = v13;
  if ( ((a3 + 4095) & 0xFFFFFFFFFFFFF000LL) != 0 )
  {
    v14 = domain_for_dev;
    v15 = -(__int64)((a3 + 4095) & 0xFFFFFFFFFFFFF000LL);
    while ( 1 )
    {
      v18 = qcom_iommu_iova_to_phys_hard(v14, &v20);
      v16 = iommu_iova_to_phys(v14, v8);
      v19 = v16;
      if ( v6 != v18 || v6 != v16 )
        break;
      v8 += 4096;
      v6 += 4096;
      v15 += 4096;
      v23 = v6;
      v24[0] = v8;
      if ( !v15 )
        goto LABEL_9;
    }
    if ( (unsigned int)__ratelimit(&iommu_debug_check_mapping_flags__rs, "iommu_debug_check_mapping_flags") )
      dev_err(
        a1,
        "Bad translation for %pad! Expected: %pa Got: %pa (ATOS) %pa (Table Walk) sid=%08x\n",
        v24,
        &v23,
        &v18,
        &v19,
        v22);
    goto LABEL_14;
  }
LABEL_9:
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
