__int64 __fastcall sensor_debugfs_getvalue(__int64 *a1, _QWORD *a2)
{
  __int64 v4; // x8
  __int64 v5; // x4
  unsigned int v6; // w0
  int v7; // w3
  __int64 result; // x0
  unsigned int v9; // w19
  unsigned int v10; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v5 = *((unsigned int *)a1 + 2);
  v10 = 0;
  v6 = camera_io_dev_read(v4 + 6480, *((unsigned int *)a1 + 4), (__int64)&v10, *((unsigned int *)a1 + 3), v5, 0);
  v7 = v10;
  if ( (v6 & 0x80000000) != 0 )
  {
    v9 = v6;
    printk(&unk_43A85B);
    result = v9;
  }
  else
  {
    *a2 = v10;
    result = 0;
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "sensor_debugfs_getvalue",
        164,
        "%s:%d: address = 0x%llx  value = 0x%x\n",
        "sensor_debugfs_getvalue",
        164,
        a1[2],
        v7);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
