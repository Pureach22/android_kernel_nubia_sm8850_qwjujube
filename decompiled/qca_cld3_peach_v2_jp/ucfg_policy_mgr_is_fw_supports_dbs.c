__int64 __fastcall ucfg_policy_mgr_is_fw_supports_dbs(__int64 a1)
{
  return policy_mgr_find_if_fw_supports_dbs(a1) & 1;
}
