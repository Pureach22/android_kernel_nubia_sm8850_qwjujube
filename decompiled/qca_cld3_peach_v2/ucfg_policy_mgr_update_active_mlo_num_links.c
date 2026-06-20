__int64 __fastcall ucfg_policy_mgr_update_active_mlo_num_links(__int64 a1, unsigned int a2, unsigned int a3)
{
  if ( (ml_is_nlink_service_supported(a1) & 1) != 0 )
    return policy_mgr_update_active_mlo_num_nlink(a1, a2, a3);
  else
    return policy_mgr_update_active_mlo_num_links(a1, a2, a3);
}
