__int64 __fastcall cam_sensor_handle_poll(unsigned __int8 **a1, __int64 a2, _DWORD *a3, _DWORD *a4, _QWORD *a5)
{
  unsigned __int8 *v6; // x23
  _DWORD **i2c_ptr; // x0
  _DWORD *v11; // x9
  _DWORD *v12; // x8

  v6 = *a1;
  i2c_ptr = (_DWORD **)cam_sensor_get_i2c_ptr(a2, 1);
  if ( i2c_ptr && (v11 = *i2c_ptr, v12 = i2c_ptr, *i2c_ptr) )
  {
    v12[16] = 5;
    v12[4] = *v6;
    v12[3] = v6[1];
    *v11 = *((_DWORD *)v6 + 2);
    *(_DWORD *)(*(_QWORD *)v12 + 4LL) = *((_DWORD *)v6 + 3);
    *(_DWORD *)(*(_QWORD *)v12 + 8LL) = *((unsigned __int16 *)v6 + 3);
    *a1 += 20;
    *a3 += 20;
    *a4 = 1;
    *a5 = v12 + 18;
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_handle_poll",
      253,
      "Failed in allocating mem for list");
    return 4294967284LL;
  }
}
