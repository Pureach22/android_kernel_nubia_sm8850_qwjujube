void hdd_component_cb_deinit()
{
  __int64 v0; // x0

  v0 = osif_ll_sap_unregister_cb();
  hdd_pre_cac_unregister_cb(v0);
  osif_vdev_mgr_reset_legacy_cb();
  hdd_cm_unregister_cb();
}
