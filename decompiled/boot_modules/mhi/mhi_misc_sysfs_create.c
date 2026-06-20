__int64 __fastcall mhi_misc_sysfs_create(__int64 a1)
{
  __int64 v1; // x21
  unsigned int group; // w0
  __int64 result; // x0
  unsigned int v5; // w20
  __int64 v6; // x19
  __int64 v7; // x19

  v1 = *(_QWORD *)(a1 + 16);
  group = sysfs_create_group(v1 + 40, &mhi_misc_group);
  if ( group )
  {
    v5 = group;
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v1 + 40, "[E][%s] Failed to create misc sysfs group\n", "mhi_misc_sysfs_create");
    if ( v6 && *(_DWORD *)(v6 + 24) < 3u )
      ipc_log_string(*(_QWORD *)(v6 + 32), "[E][%s] Failed to create misc sysfs group\n", "mhi_misc_sysfs_create");
    return v5;
  }
  result = sysfs_create_group(v1 + 40, &mhi_tsync_group);
  if ( (_DWORD)result )
  {
    v5 = result;
    v7 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v1 + 40, "[E][%s] Failed to create time synchronization sysfs group\n", "mhi_misc_sysfs_create");
    if ( v7 )
    {
      if ( *(_DWORD *)(v7 + 24) <= 2u )
        ipc_log_string(
          *(_QWORD *)(v7 + 32),
          "[E][%s] Failed to create time synchronization sysfs group\n",
          "mhi_misc_sysfs_create");
    }
    return v5;
  }
  return result;
}
