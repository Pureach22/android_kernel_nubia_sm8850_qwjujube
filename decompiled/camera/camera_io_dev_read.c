__int64 __fastcall camera_io_dev_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, char a6)
{
  int v6; // w6
  _QWORD *v7; // x8
  const char *v9; // x5
  __int64 v10; // x4
  __int64 v11; // x8

  if ( a1 )
  {
    v6 = *(_DWORD *)a1;
    if ( *(int *)a1 > 2 )
    {
      if ( v6 == 4 )
      {
        v11 = *(_QWORD *)(a1 + 8);
        if ( v11 )
          return cam_qup_i3c_read(*(_QWORD *)(v11 + 8));
        v9 = "Invalid Args: qup_client: NULL";
        v10 = 104;
        goto LABEL_8;
      }
      if ( v6 == 3 )
        return cam_spi_read();
    }
    else
    {
      if ( v6 == 1 )
        return cam_cci_i2c_read(*(_QWORD *)(a1 + 16), a2, a3, a4, a5, a6 & 1);
      if ( v6 == 2 )
      {
        v7 = *(_QWORD **)(a1 + 8);
        if ( v7 )
          return cam_qup_i2c_read(*v7);
        v9 = "Invalid Args: qup_client: NULL";
        v10 = 94;
        goto LABEL_8;
      }
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "camera_io_dev_read",
      110,
      "Invalid Master Type: %d",
      v6);
    return 4294967274LL;
  }
  v9 = "Invalid Args";
  v10 = 85;
LABEL_8:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x4000000000LL,
    1,
    "camera_io_dev_read",
    v10,
    v9);
  return 4294967274LL;
}
