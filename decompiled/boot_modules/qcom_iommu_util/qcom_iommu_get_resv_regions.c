__int64 __fastcall qcom_iommu_get_resv_regions(__int64 result)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  v1 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 824) + 64LL) + 16LL);
  if ( v1 )
  {
    v2 = *(__int64 (**)(void))(v1 + 80);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != -2072681516 )
        __break(0x8228u);
      return v2();
    }
  }
  return result;
}
