__int64 wlan_ipa_is_vlan_enabled()
{
  return ipa_config_is_vlan_enabled() & 1;
}
