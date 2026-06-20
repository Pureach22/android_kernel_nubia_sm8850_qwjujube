__int64 __fastcall sub_57B368(__int64 a1)
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return wlan_ipa_is_shared_smmu_enabled(a1);
}
