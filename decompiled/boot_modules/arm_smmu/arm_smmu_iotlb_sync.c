__int64 __fastcall arm_smmu_iotlb_sync(__int64 result)
{
  if ( *(_QWORD *)(result - 184) )
    return arm_smmu_flush_iotlb_all(result);
  return result;
}
