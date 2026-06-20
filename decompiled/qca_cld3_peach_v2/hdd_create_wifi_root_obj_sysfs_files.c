__int64 hdd_create_wifi_root_obj_sysfs_files()
{
  __int64 wifi_root_obj; // x0
  __int64 wifi_feature_interface_sysfs_file; // x0
  __int64 rtpm_interface_sysfs_file; // x0

  wifi_root_obj = hdd_sysfs_create_wifi_root_obj();
  wifi_feature_interface_sysfs_file = hdd_create_wifi_feature_interface_sysfs_file(wifi_root_obj);
  rtpm_interface_sysfs_file = hdd_create_rtpm_interface_sysfs_file(wifi_feature_interface_sysfs_file);
  return hdd_create_apfmode_interface_sysfs_file(rtpm_interface_sysfs_file);
}
