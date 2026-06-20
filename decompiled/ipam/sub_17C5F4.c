__int64 sub_17C5F4()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return ipa_wigig_is_smmu_enabled();
}
