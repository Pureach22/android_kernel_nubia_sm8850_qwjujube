__int64 wlan_ipa_is_shared_smmu_enabled()
{
  return ipa_get_shared_smmu_enable() & 1;
}
