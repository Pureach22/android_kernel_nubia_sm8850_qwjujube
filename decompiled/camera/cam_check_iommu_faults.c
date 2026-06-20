__int64 __fastcall cam_check_iommu_faults(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w9
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  int v6; // [xsp+10h] [xbp-10h]
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v5 = 0;
  if ( (unsigned int)qcom_iommu_get_fault_ids(a1, &v5) )
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               64,
               1,
               "cam_check_iommu_faults",
               627,
               "Cannot get smmu fault ids");
  else
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               64,
               1,
               "cam_check_iommu_faults",
               630,
               "smmu fault ids bid:%d pid:%d mid:%d",
               v5,
               HIDWORD(v5),
               v6);
  v4 = v6;
  *(_QWORD *)(a2 + 44) = v5;
  *(_DWORD *)(a2 + 52) = v4;
  _ReadStatusReg(SP_EL0);
  return result;
}
