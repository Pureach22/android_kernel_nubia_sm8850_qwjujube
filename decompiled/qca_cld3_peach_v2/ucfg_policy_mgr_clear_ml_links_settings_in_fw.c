__int64 __fastcall ucfg_policy_mgr_clear_ml_links_settings_in_fw(__int64 a1, unsigned int a2)
{
  if ( (ml_is_nlink_service_supported(a1) & 1) != 0 )
    return policy_mgr_clear_ml_links_settings_in_fw_nlink(a1, a2);
  else
    return policy_mgr_clear_ml_links_settings_in_fw(a1, a2);
}
