__int64 __fastcall hdd_sysfs_dp_traffic_end_indication_destroy(__int64 a1)
{
  return device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dp_traffic_end_indication);
}
