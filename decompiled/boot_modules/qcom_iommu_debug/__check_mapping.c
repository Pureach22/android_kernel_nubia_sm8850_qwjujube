__int64 __fastcall _check_mapping(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x8
  __int64 v6; // x8
  int v8; // w8
  __int64 v11; // x22
  __int64 result; // x0
  __int64 v13; // [xsp+0h] [xbp-30h] BYREF
  int v14; // [xsp+8h] [xbp-28h]
  int v15; // [xsp+Ch] [xbp-24h]
  __int64 v16; // [xsp+10h] [xbp-20h] BYREF
  __int64 v17; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v18[2]; // [xsp+20h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 824);
  v18[0] = a3;
  v17 = a4;
  if ( !v5 || (v6 = *(_QWORD *)(v5 + 56)) == 0 )
  {
    if ( (unsigned int)__ratelimit(&_check_mapping__rs, "__check_mapping") )
      dev_err(a1, "No fwspec.\n");
    goto LABEL_11;
  }
  v8 = *(unsigned __int16 *)(v6 + 16);
  v13 = a3;
  v14 = 0;
  v15 = v8;
  v11 = qcom_iommu_iova_to_phys_hard(a2, &v13);
  v16 = v11;
  if ( v11 != iommu_iova_to_phys(a2, a3) )
  {
    _warn_printk("hard/soft iova_to_phys fns don't agree...");
    __break(0x800u);
    if ( v11 == a4 )
      goto LABEL_5;
    goto LABEL_9;
  }
  if ( v11 != a4 )
  {
LABEL_9:
    if ( (unsigned int)__ratelimit(&_check_mapping__rs_110, "__check_mapping") )
      dev_err(a1, "Bad translation for %pa! Expected: %pa Got: %pa\n", v18, &v17, &v16);
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
LABEL_5:
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
