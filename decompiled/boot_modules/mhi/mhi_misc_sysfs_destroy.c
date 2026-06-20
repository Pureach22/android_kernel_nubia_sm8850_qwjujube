__int64 __fastcall mhi_misc_sysfs_destroy(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 16);
  sysfs_remove_group(v1 + 40, &mhi_tsync_group);
  return sysfs_remove_group(v1 + 40, &mhi_misc_group);
}
