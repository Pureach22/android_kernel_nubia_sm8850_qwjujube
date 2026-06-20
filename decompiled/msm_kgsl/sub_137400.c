__int64 __fastcall sub_137400(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 _X5)
{
  __asm { PRFM            #0x17, [X5,#0x7C00] }
  return kgsl_iommu_map_global();
}
