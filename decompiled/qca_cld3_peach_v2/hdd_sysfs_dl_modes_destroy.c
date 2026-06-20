__int64 __fastcall hdd_sysfs_dl_modes_destroy(__int64 a1)
{
  device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_vapon);
  device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_vapoff);
  device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_type);
  device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_report);
  device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_modon);
  device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_modoff);
  device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_mod_loglevel);
  return device_remove_file(*(_QWORD *)(a1 + 32) + 1376LL, &dev_attr_dl_loglevel);
}
