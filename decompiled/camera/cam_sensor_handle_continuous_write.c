__int64 __fastcall cam_sensor_handle_continuous_write(
        __int64 a1,
        __int64 *a2,
        _DWORD *a3,
        unsigned int *a4,
        __int64 **a5,
        unsigned int a6)
{
  __int64 *i2c_ptr; // x0
  int v12; // w8
  int v13; // w8
  int v15; // w8
  int v16; // w8
  __int64 v17; // x11
  __int64 v18; // x10
  __int64 *v19; // x9

  i2c_ptr = cam_sensor_get_i2c_ptr(a2, a6);
  if ( !i2c_ptr || !*i2c_ptr )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_handle_continuous_write",
      331,
      "Failed in allocating i2c_list");
    return 4294967284LL;
  }
  *a3 = 8 * a6 + 12;
  v12 = *(unsigned __int8 *)(a1 + 4);
  if ( v12 == 3 )
  {
    v13 = 1;
  }
  else
  {
    if ( v12 != 5 )
      return 4294967274LL;
    v13 = 2;
  }
  *((_DWORD *)i2c_ptr + 16) = v13;
  *((_DWORD *)i2c_ptr + 3) = *(unsigned __int8 *)(a1 + 7);
  v15 = *(unsigned __int8 *)(a1 + 6);
  *((_DWORD *)i2c_ptr + 2) = a6;
  *((_DWORD *)i2c_ptr + 4) = v15;
  if ( a6 )
  {
    v16 = 0;
    do
    {
      v17 = 16LL * v16;
      *(_DWORD *)(*i2c_ptr + v17) = *(_DWORD *)(a1 + 8);
      v18 = 8LL * v16++;
      *(_DWORD *)(*i2c_ptr + v17 + 4) = *(_DWORD *)(a1 + 12 + v18);
      *(_DWORD *)(*i2c_ptr + v17 + 12) = 0;
    }
    while ( a6 != v16 );
  }
  v19 = i2c_ptr + 9;
  *a4 = a6;
  *a5 = v19;
  return 0;
}
