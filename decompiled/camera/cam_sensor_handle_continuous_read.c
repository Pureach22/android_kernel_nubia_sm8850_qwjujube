__int64 __fastcall cam_sensor_handle_continuous_read(
        __int64 a1,
        __int64 *a2,
        _WORD *a3,
        _DWORD *a4,
        _QWORD *a5,
        int *a6)
{
  __int64 *i2c_ptr; // x0
  __int64 *v12; // x20
  __int64 result; // x0
  unsigned int v14; // w19

  i2c_ptr = cam_sensor_get_i2c_ptr(a2, 1u);
  v12 = i2c_ptr;
  if ( i2c_ptr && *i2c_ptr )
  {
    result = cam_sensor_get_io_buffer(a6, (__int64)i2c_ptr);
    if ( (_DWORD)result )
    {
      v14 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_handle_continuous_read",
        537,
        "Failed to get read buffer: %d",
        result);
      return v14;
    }
    else
    {
      *a3 = 12;
      *((_DWORD *)v12 + 16) = 4;
      *((_DWORD *)v12 + 3) = *(unsigned __int8 *)(a1 + 7);
      *((_DWORD *)v12 + 4) = *(unsigned __int8 *)(a1 + 6);
      *((_DWORD *)v12 + 2) = *(_DWORD *)a1;
      *(_DWORD *)*v12 = *(_DWORD *)(a1 + 8);
      *a4 = 0;
      *a5 = v12 + 9;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_handle_continuous_read",
      531,
      "Failed in allocating i2c_list: %pK",
      i2c_ptr);
    return 4294967284LL;
  }
  return result;
}
