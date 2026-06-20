__int64 spss_remove()
{
  __int64 v0; // x19
  __int64 v1; // x0
  __int64 result; // x0

  device_destroy(*(_QWORD *)(spss_utils_dev + 16), *(unsigned int *)(spss_utils_dev + 8));
  class_destroy(*(_QWORD *)(spss_utils_dev + 16));
  unregister_chrdev_region(*(unsigned int *)(spss_utils_dev + 8), 1);
  v0 = spss_dev;
  device_remove_file(spss_dev, &dev_attr_calc_apps_cmac);
  device_remove_file(v0, &dev_attr_calc_fw_cmac);
  device_remove_file(v0, &dev_attr_spss_debug_reg);
  device_remove_file(v0, &dev_attr_test_fuse_state);
  device_remove_file(v0, &dev_attr_firmware_name);
  v1 = iar_nb;
  if ( __PAIR128__(iar_notif_handle, iar_nb) == 0 )
  {
    qcom_unregister_ssr_notifier(0, 0);
    v1 = iar_nb;
  }
  kfree(v1);
  iar_nb = 0;
  kfree(spss_utils_dev);
  spss_utils_dev = 0;
  result = cmac_mem;
  if ( cmac_mem )
  {
    result = iounmap(cmac_mem);
    cmac_mem = 0;
  }
  return result;
}
