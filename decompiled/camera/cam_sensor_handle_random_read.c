__int64 __fastcall cam_sensor_handle_random_read(
        __int64 a1,
        __int64 *a2,
        _WORD *a3,
        unsigned int *a4,
        _QWORD *a5,
        __int64 a6,
        unsigned int a7)
{
  __int64 *i2c_ptr; // x0
  __int64 *v14; // x21
  int io_buffer; // w0
  unsigned int v16; // w19
  int v18; // w8
  int v19; // w8
  __int64 v20; // x10
  __int64 v21; // x12

  i2c_ptr = cam_sensor_get_i2c_ptr(a2, a7);
  v14 = i2c_ptr;
  if ( i2c_ptr && *i2c_ptr )
  {
    io_buffer = cam_sensor_get_io_buffer(a6, i2c_ptr);
    if ( io_buffer )
    {
      v16 = io_buffer;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_handle_random_read",
        492,
        "Failed to get read buffer: %d",
        io_buffer);
      return v16;
    }
    else
    {
      *a3 = 8 * a7 + 8;
      *((_DWORD *)v14 + 16) = 3;
      *((_DWORD *)v14 + 3) = *(unsigned __int8 *)(a1 + 7);
      v18 = *(unsigned __int8 *)(a1 + 6);
      *((_DWORD *)v14 + 2) = a7;
      *((_DWORD *)v14 + 4) = v18;
      if ( a7 )
      {
        v19 = 0;
        do
        {
          v20 = 8LL * v19;
          v21 = 16LL * v19++;
          *(_DWORD *)(*v14 + v21) = *(_DWORD *)(a1 + 8 + v20);
        }
        while ( a7 != v19 );
      }
      *a4 = a7;
      *a5 = v14 + 9;
      return 0;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_handle_random_read",
      486,
      "Failed in allocating i2c_list: %pK",
      i2c_ptr);
    return 4294967284LL;
  }
}
