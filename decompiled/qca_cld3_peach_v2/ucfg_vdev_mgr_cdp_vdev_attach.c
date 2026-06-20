__int64 __fastcall ucfg_vdev_mgr_cdp_vdev_attach(__int64 a1)
{
  if ( wlan_objmgr_vdev_get_comp_private_obj(a1, 0) )
    return vdev_mgr_cdp_vdev_attach();
  else
    return 16;
}
