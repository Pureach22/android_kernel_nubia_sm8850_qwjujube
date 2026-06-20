__int64 mlme_unregister_mlo_ext_ops()
{
  if ( wlan_objmgr_get_mlo_ctx() )
    mlo_unreg_mlme_ext_cb();
  return 0;
}
