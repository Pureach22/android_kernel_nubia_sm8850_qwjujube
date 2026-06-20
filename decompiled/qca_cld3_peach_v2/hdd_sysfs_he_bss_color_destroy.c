__int64 __fastcall hdd_sysfs_he_bss_color_destroy(__int64 a1)
{
  return device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_he_bss_color);
}
