__int64 __fastcall kgsl_iommu_send_tlb_hint(_QWORD *a1, char a2)
{
  __int64 result; // x0
  void (*v5)(void); // x8
  __int64 v6; // x0
  void (*v7)(void); // x8
  __int64 (*v8)(void); // x8

  result = qcom_skip_tlb_management(a1[8] + 16LL);
  if ( a1[87] )
    result = qcom_skip_tlb_management(a1[78] + 16LL);
  if ( a1[187] )
    result = qcom_skip_tlb_management(a1[186] + 16LL);
  if ( (a2 & 1) == 0 )
  {
    v5 = *(void (**)(void))(*(_QWORD *)(a1[17] + 8LL) + 32LL);
    if ( v5 )
    {
      if ( *((_DWORD *)v5 - 1) != -1056074712 )
        __break(0x8228u);
      v5();
    }
    v6 = a1[87];
    if ( v6 )
    {
      v7 = *(void (**)(void))(*(_QWORD *)(v6 + 8) + 32LL);
      if ( v7 )
      {
        if ( *((_DWORD *)v7 - 1) != -1056074712 )
          __break(0x8228u);
        v7();
      }
    }
    result = a1[187];
    if ( result )
    {
      v8 = *(__int64 (**)(void))(*(_QWORD *)(result + 8) + 32LL);
      if ( v8 )
      {
        if ( *((_DWORD *)v8 - 1) != -1056074712 )
          __break(0x8228u);
        return v8();
      }
    }
  }
  return result;
}
