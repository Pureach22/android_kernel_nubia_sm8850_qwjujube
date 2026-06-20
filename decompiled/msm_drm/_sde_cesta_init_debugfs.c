__int64 __fastcall sde_cesta_init_debugfs(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = debugfs_create_dir(a2, 0);
  *(_QWORD *)(a1 + 1168) = result;
  if ( result )
  {
    debugfs_create_file("status", 256, result, a1, &debugfs_status_fops);
    return debugfs_create_x32("debug_mode", 384, *(_QWORD *)(a1 + 1168), a1 + 1160);
  }
  return result;
}
