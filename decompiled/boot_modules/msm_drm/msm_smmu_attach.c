__int64 __fastcall msm_smmu_attach(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x19
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  unsigned int v6; // w19

  v2 = *(_QWORD **)(a1 + 40);
  if ( v2 )
  {
    if ( (v2[5] & 1) != 0 )
    {
      return 0;
    }
    else
    {
      v4 = v2[4];
      if ( v4 )
      {
        *(_QWORD *)(*v2 + 632LL) = v4;
        v2[4] = 0;
      }
      result = qcom_iommu_sid_switch(*v2, 0);
      if ( (_DWORD)result )
      {
        v5 = *v2;
        v6 = result;
        dev_err(v5, "[%s:%d] iommu sid switch failed (%d)\n", "msm_smmu_attach", 90, result);
        return v6;
      }
      else
      {
        *((_BYTE *)v2 + 40) = 1;
      }
    }
  }
  else
  {
    printk(&unk_214797, a2);
    return 4294967274LL;
  }
  return result;
}
