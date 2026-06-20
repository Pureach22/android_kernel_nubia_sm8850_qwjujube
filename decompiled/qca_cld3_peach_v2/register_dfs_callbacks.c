void register_dfs_callbacks()
{
  global_dfs_to_mlme = wlan_objmgr_pdev_component_obj_attach;
  off_9322D8 = wlan_objmgr_pdev_component_obj_detach;
}
