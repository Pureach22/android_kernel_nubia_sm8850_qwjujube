unsigned __int64 __fastcall sdca_devices_debugfs_dentry_create(unsigned __int64 *a1, __int64 *a2)
{
  __int64 v2; // x8
  __int64 *v4; // x8
  __int64 v6; // x0
  unsigned __int64 result; // x0
  __int64 file; // x0
  unsigned __int64 v9; // x2
  __int64 v10; // x0
  unsigned __int64 v11; // x2

  v2 = *a2;
  if ( !a2[3] || !a2[4] )
    return dev_err(
             *(_QWORD *)(v2 + 24),
             "%s: read/write access check table is NULL\n",
             "sdca_devices_debugfs_dentry_create");
  v4 = *(__int64 **)(v2 + 24);
  v6 = v4[14];
  if ( !v6 )
    v6 = *v4;
  result = debugfs_create_dir(v6, 0);
  *a1 = result;
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    file = debugfs_create_file("address", 33060, result, a2, &codec_debug_address_ops);
    v9 = *a1;
    a1[2] = file;
    v10 = debugfs_create_file("data", 33060, v9, a2, &codec_debug_data_ops);
    v11 = *a1;
    a1[3] = v10;
    result = debugfs_create_file("registers", 33060, v11, a2, &codec_debug_registers_ops);
    a1[1] = result;
  }
  return result;
}
