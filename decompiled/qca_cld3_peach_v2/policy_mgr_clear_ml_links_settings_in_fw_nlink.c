__int64 __fastcall policy_mgr_clear_ml_links_settings_in_fw_nlink(__int64 a1, __int64 a2)
{
  return ml_nlink_vendor_command_set_link(a1, a2, 0, 0, 0, 0, 0, 0);
}
