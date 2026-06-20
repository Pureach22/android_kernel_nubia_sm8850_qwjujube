__int64 __fastcall sub_13BA04(int a1, int a2, int a3, int a4, char *a5)
{
  __int64 v5; // x30

  if ( (v5 & 0x200000000000LL) == 0 )
    JUMPOUT(0x141520);
  return cam_smmu_iommu_fault_handler(a1, a2, a3, a4, a5);
}
