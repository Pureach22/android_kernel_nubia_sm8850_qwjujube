__int64 sub_5E0024()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return ipa_get_shared_smmu_enable();
}
