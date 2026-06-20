__int64 __fastcall cam_cpas_sysfs_get_subparts_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  _DWORD *v5; // x8
  unsigned int v6; // w6
  __int64 v7; // x20

  v3 = *(_QWORD *)(a1 + 96);
  mutex_lock(v3);
  v5 = *(_DWORD **)(v3 + 3392);
  v6 = scnprintf(
         a3,
         4096,
         "num_ifes: 0x%x, 0x%x\nnum_ife_lites: 0x%x, 0x%x\nnum_sfes: 0x%x, 0x%x\nnum_custom: 0x%x, 0x%x\n",
         v5[334],
         v5[335],
         v5[336],
         v5[337],
         v5[338],
         v5[339],
         v5[340],
         v5[341]);
  if ( v6 < 0x1000 )
  {
    v7 = v6;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_sysfs_get_subparts_info",
      5146,
      "camera subparts info sysfs string is truncated, len: %d",
      v6);
    v7 = -75;
  }
  mutex_unlock(v3);
  return v7;
}
