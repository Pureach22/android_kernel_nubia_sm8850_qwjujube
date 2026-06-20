__int64 __fastcall ucfg_policy_mgr_is_hw_sbs_capable(__int64 a1)
{
  return policy_mgr_is_hw_dbs_capable(a1) & 1;
}
