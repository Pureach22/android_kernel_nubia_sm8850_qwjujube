__int64 __fastcall hdd_sysfs_pm_cinfo_destroy(__int64 a1)
{
  return sysfs_remove_file_ns(a1, &pm_cinfo_attribute, 0);
}
