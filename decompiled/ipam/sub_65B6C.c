__int64 sub_65B6C()
{
  int v0; // w11

  if ( (v0 & 0x100000) == 0 )
    JUMPOUT(0x634FC);
  return ipa_smmu_store_sgt();
}
