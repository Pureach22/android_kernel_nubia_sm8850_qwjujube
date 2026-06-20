__int64 cleanup_module()
{
  __int64 v0; // x8
  __int64 v1; // x21
  char **v2; // x8
  __int64 v3; // x22
  __int64 v4; // x23
  void (*v5)(void); // x8
  __int64 v7; // x0

  v0 = 11;
  do
  {
    v1 = v0;
    v2 = &(&submodule_table)[3 * v0];
    if ( *((_DWORD *)v2 + 2) - 1 >= 0 )
    {
      v3 = 16LL * (unsigned int)(*((_DWORD *)v2 + 2) - 1);
      v4 = (__int64)(v2[2] + 8);
      do
      {
        v5 = *(void (**)(void))(v4 + v3);
        if ( *((_DWORD *)v5 - 1) != -440107680 )
          __break(0x8228u);
        v5();
        v3 -= 16;
      }
      while ( v3 != -16 );
    }
    v0 = v1 - 1;
  }
  while ( v1 );
  cam_debugfs_deinit();
  if ( tof_enable_0 == 1 )
  {
    v7 = printk(&unk_430044);
    vi530x_exit(v7);
  }
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           0x20000,
           3,
           "camera_exit",
           354,
           "Spectra camera driver exited!");
}
