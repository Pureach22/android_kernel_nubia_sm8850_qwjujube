__int64 hdd_mlo_mgr_register_osif_ops()
{
  __int64 mlo_ctx; // x0

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  return wlan_mlo_mgr_register_osif_ext_ops(mlo_ctx, mlo_osif_ops);
}
