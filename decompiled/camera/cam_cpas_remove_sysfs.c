__int64 __fastcall cam_cpas_remove_sysfs(__int64 a1)
{
  __int64 v2; // x20

  mutex_lock(a1);
  v2 = *(_QWORD *)(a1 + 3392);
  sysfs_remove_file_ns(*(_QWORD *)(v2 + 1328), &cam_subparts_info_attribute, 0);
  kobject_put(*(_QWORD *)(v2 + 1328));
  return mutex_unlock(a1);
}
