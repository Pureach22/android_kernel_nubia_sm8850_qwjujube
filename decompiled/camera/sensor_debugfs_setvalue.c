__int64 __fastcall sensor_debugfs_setvalue(__int64 a1, __int64 a2)
{
  int v2; // w19
  unsigned int v3; // w0
  unsigned int v5; // w20
  __int64 v6; // x20

  v2 = a2;
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
  {
    v6 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "sensor_debugfs_setvalue",
      129,
      "%s:%d: address = 0x%llx  value = 0x%llx",
      "sensor_debugfs_setvalue",
      129,
      *(_QWORD *)(a1 + 16),
      a2);
    a1 = v6;
  }
  v3 = zte_cam_cci_i2c_write(
         *(_QWORD *)a1 + 6480LL,
         *(_DWORD *)(a1 + 16),
         v2,
         *(_DWORD *)(a1 + 12),
         *(_DWORD *)(a1 + 8));
  if ( (v3 & 0x80000000) == 0 )
    return 0;
  v5 = v3;
  printk(&unk_40BDCB);
  return v5;
}
