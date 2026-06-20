__int64 __fastcall cam_sensor_handle_random_write(
        __int64 a1,
        __int64 *a2,
        _DWORD *a3,
        unsigned int *a4,
        _QWORD *a5,
        unsigned int a6)
{
  __int64 *i2c_ptr; // x0
  int v12; // w8
  _DWORD *v13; // x10
  __int64 v14; // x12
  unsigned int v15; // w8

  i2c_ptr = cam_sensor_get_i2c_ptr(a2, a6);
  if ( i2c_ptr && *i2c_ptr )
  {
    *a3 = 8 * a6 + 8;
    *((_DWORD *)i2c_ptr + 16) = 0;
    *((_DWORD *)i2c_ptr + 3) = *(unsigned __int8 *)(a1 + 7);
    *((_DWORD *)i2c_ptr + 4) = *(unsigned __int8 *)(a1 + 6);
    if ( a6 )
    {
      v12 = 0;
      do
      {
        v13 = (_DWORD *)(a1 + 8 + 8LL * v12);
        v14 = 16LL * v12++;
        *(_DWORD *)(*i2c_ptr + v14) = *v13;
        *(_DWORD *)(*i2c_ptr + v14 + 4) = v13[1];
        *(_DWORD *)(*i2c_ptr + v14 + 12) = 0;
      }
      while ( a6 != v12 );
    }
    v15 = 0;
    *a4 = a6;
    *a5 = i2c_ptr + 9;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_handle_random_write",
      292,
      "Failed in allocating i2c_list");
    return (unsigned int)-12;
  }
  return v15;
}
