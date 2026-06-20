__int64 sub_57BBF8()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return ucfg_ipa_get_shared_smmu_enable();
}
