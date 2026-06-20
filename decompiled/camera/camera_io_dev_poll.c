__int64 __fastcall camera_io_dev_poll(
        int *a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 a4,
        unsigned int a5,
        unsigned int a6)
{
  int v6; // w8
  const char *v8; // x5
  __int64 v9; // x4
  _QWORD *v10; // x8
  __int64 v11; // x8

  if ( a1 )
  {
    v6 = *a1;
    if ( *a1 == 4 )
    {
      v11 = *((_QWORD *)a1 + 1);
      if ( v11 )
        return cam_qup_i3c_poll(*(_QWORD *)(v11 + 8));
      v8 = "qup_client is NULL";
      v9 = 38;
    }
    else
    {
      if ( v6 != 2 )
      {
        if ( v6 == 1 )
          return cam_cci_i2c_poll(*((_QWORD *)a1 + 2), a2, a3, a4, a6, a5);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x4000000000LL,
          1,
          "camera_io_dev_poll",
          44,
          "Invalid Master Type: %d",
          v6);
        return 4294967274LL;
      }
      v10 = *((_QWORD **)a1 + 1);
      if ( v10 )
        return cam_qup_i2c_poll(*v10);
      v8 = "qup_client is NULL";
      v9 = 31;
    }
  }
  else
  {
    v8 = "Invalid Args";
    v9 = 21;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x4000000000LL,
    1,
    "camera_io_dev_poll",
    v9,
    v8);
  return 4294967274LL;
}
