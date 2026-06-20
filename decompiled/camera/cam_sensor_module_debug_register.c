__int64 cam_sensor_module_debug_register()
{
  __int64 result; // x0
  __int64 v1; // x0
  __int64 v2; // x8
  unsigned __int64 v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  display_buf = 0;
  if ( (unsigned int)cam_debugfs_create_subdir("i2c", v3) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_sensor_module_debug_register",
      328,
      "DebugFS could not create directory!");
    result = 4294967294LL;
  }
  else
  {
    debugfs_root_1 = v3[0];
    debugfs_create_file("i2c-rw", 420, v3[0], 0, &i2c_operations);
    if ( mem_trace_en == 1 )
      v1 = cam_mem_trace_alloc(3000, 0xCC0u, 0, "cam_sensor_module_debug_register", 0x151u);
    else
      v1 = _kvmalloc_node_noprof(3000, 0, 3520, 0xFFFFFFFFLL);
    v2 = v1;
    result = 0;
    display_buf = v2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
