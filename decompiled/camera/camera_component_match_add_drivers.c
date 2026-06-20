__int64 __fastcall camera_component_match_add_drivers(__int64 a1, __int64 a2)
{
  __int64 i; // x23
  __int64 (__fastcall **v5)(); // x24
  __int64 device; // x0
  __int64 j; // x26
  __int64 v8; // x1
  __int64 k; // x23
  __int64 v11; // x24
  __int64 v12; // x0
  __int64 m; // x26
  __int64 v14; // x1

  if ( a1 && a2 )
  {
    for ( i = 0; i != 28; ++i )
    {
      v5 = cam_component_platform_drivers[i];
      device = bus_find_device(&platform_bus_type, 0, v5 + 5, camera_platform_compare_dev);
      for ( j = 0; device; device = bus_find_device(&platform_bus_type, j, v5 + 5, camera_platform_compare_dev) )
      {
        v8 = j;
        j = device;
        put_device(v8);
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20000,
            4,
            "camera_component_match_add_drivers",
            584,
            "Adding matched component:%s",
            *(const char **)(j - 16));
        component_match_add_release(a1, a2, 0, camera_component_compare_dev, j);
      }
      put_device(j);
    }
    for ( k = 0; k != 5; ++k )
    {
      v11 = (__int64)*(&cam_component_i2c_drivers + k);
      v12 = bus_find_device(&i2c_bus_type, 0, v11 + 48, camera_i2c_compare_dev);
      for ( m = 0; v12; v12 = bus_find_device(&i2c_bus_type, m, v11 + 48, camera_i2c_compare_dev) )
      {
        v14 = m;
        m = v12;
        put_device(v14);
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20000,
            4,
            "camera_component_match_add_drivers",
            606,
            "Adding matched component:%s",
            (const char *)(m - 28));
        component_match_add_release(a1, a2, 0, camera_component_compare_dev, m);
      }
      put_device(m);
    }
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "camera_component_match_add_drivers",
      565,
      "Invalid parameters for component match add");
    return 4294967274LL;
  }
}
