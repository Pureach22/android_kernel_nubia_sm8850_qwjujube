__int64 __fastcall camera_io_dev_read_seq(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, unsigned int a6)
{
  int v6; // w6
  _QWORD *v7; // x8
  __int64 v9; // x8
  __int64 v10; // x4

  v6 = *(_DWORD *)a1;
  if ( *(int *)a1 > 2 )
  {
    if ( v6 == 3 )
      return cam_spi_read_seq();
    if ( v6 == 4 )
    {
      v9 = *(_QWORD *)(a1 + 8);
      if ( v9 )
        return cam_qup_i3c_read_seq(*(_QWORD *)(v9 + 8), a2, a3, a4, a6);
      v10 = 136;
      goto LABEL_15;
    }
  }
  else
  {
    if ( v6 == 1 )
      return cam_camera_cci_i2c_read_seq(*(_QWORD *)(a1 + 16));
    if ( v6 == 2 )
    {
      v7 = *(_QWORD **)(a1 + 8);
      if ( v7 )
        return cam_qup_i2c_read_seq(*v7, a2, a3, a4, a6);
      v10 = 127;
LABEL_15:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "camera_io_dev_read_seq",
        v10,
        "Invalid Args: qup_client: NULL");
      return 4294967274LL;
    }
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x4000000000LL,
    1,
    "camera_io_dev_read_seq",
    142,
    "Invalid Master Type: %d",
    v6);
  return 4294967274LL;
}
