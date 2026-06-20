__int64 __fastcall camera_io_dev_write(int *a1, _QWORD *a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  int v7; // w6

  if ( a1 && a2 )
  {
    if ( *a2 )
    {
      v7 = *a1;
      if ( *a1 > 2 )
      {
        if ( v7 == 3 )
          return cam_spi_write_table(a1, a2);
        if ( v7 == 4 )
          return cam_qup_i3c_write_table(a1, a2);
      }
      else
      {
        if ( v7 == 1 )
          return cam_cci_i2c_write_table(a1, a2);
        if ( v7 == 2 )
          return cam_qup_i2c_write_table(a1, a2);
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "camera_io_dev_write",
        173,
        "Invalid Master Type:%d",
        v7);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, int *))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "camera_io_dev_write",
        159,
        "Invalid Register Settings",
        a7,
        a1);
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "camera_io_dev_write",
      154,
      "Input parameters not valid ws: %pK ioinfo: %pK",
      a2,
      a1);
  }
  return 4294967274LL;
}
