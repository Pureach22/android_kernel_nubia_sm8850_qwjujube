__int64 __fastcall ucfg_policy_mgr_update_mlo_links_based_on_linkid(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned __int8 *a4,
        _DWORD *a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  if ( (ml_is_nlink_service_supported(a1) & 1) != 0 )
    return policy_mgr_update_mlo_links_based_on_linkid_nlink(a1, a2, a3, a4, a5);
  else
    return policy_mgr_update_mlo_links_based_on_linkid(a1, a2, a3, a4, a5, v10, v11, v12, v13, v14, v15, v16, v17);
}
