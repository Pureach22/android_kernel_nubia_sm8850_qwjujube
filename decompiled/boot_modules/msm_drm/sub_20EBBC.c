__int64 sub_20EBBC()
{
  int v0; // w24

  if ( (v0 & 0x10000000) == 0 )
    JUMPOUT(0x20C314);
  return msm_smmu_one_to_one_unmap();
}
