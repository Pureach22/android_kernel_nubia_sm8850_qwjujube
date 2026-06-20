__int64 __fastcall hdd_sysfs_stats_destroy(__int64 a1)
{
  device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dump_stats);
  device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_clear_stats);
  return device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_stats);
}
