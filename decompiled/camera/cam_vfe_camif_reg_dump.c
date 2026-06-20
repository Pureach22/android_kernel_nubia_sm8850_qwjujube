__int64 __fastcall cam_vfe_camif_reg_dump(__int64 result)
{
  __int64 v1; // x24
  unsigned __int64 v2; // x19
  int v3; // w7
  unsigned __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  unsigned __int64 v7; // x21
  int v8; // w7
  bool v9; // cf
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x25
  __int64 v13; // x26
  unsigned __int64 v14; // x23
  int v15; // w7
  __int64 v16; // x8
  __int64 v17; // x8

  if ( !result )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "cam_vfe_camif_reg_dump",
             530,
             "Error! Invalid input arguments");
  if ( (unsigned int)(*(_DWORD *)(result + 8) - 1) >= 2 )
  {
    v1 = *(_QWORD *)(result + 24);
    v2 = 0;
    do
    {
      v5 = *(_QWORD *)(v1 + 40);
      if ( v5 && *(_DWORD *)(v5 + 480) && (v6 = *(_QWORD *)(v5 + 288)) != 0 )
      {
        v3 = cam_io_r(v6 + v2);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_r",
          853,
          "No valid mapped starting address found");
        v3 = 0;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_reg_dump",
        541,
        "offset 0x%x value 0x%x",
        v2,
        v3);
      v4 = v2 >> 2;
      v2 += 4LL;
    }
    while ( v4 < 0x457 );
    v7 = 0x2000;
    do
    {
      v10 = *(_QWORD *)(v1 + 40);
      if ( v10 && *(_DWORD *)(v10 + 480) && (v11 = *(_QWORD *)(v10 + 288)) != 0 )
      {
        v8 = cam_io_r(v11 + v7);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_r",
          853,
          "No valid mapped starting address found");
        v8 = 0;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_reg_dump",
        546,
        "offset 0x%x value 0x%x",
        v7,
        v8);
      v9 = v7 >= 0x20B5;
      v7 += 4LL;
    }
    while ( !v9 );
    v12 = 0;
    v13 = 8704;
    do
    {
      v14 = v13;
      do
      {
        v16 = *(_QWORD *)(v1 + 40);
        if ( v16 && *(_DWORD *)(v16 + 480) && (v17 = *(_QWORD *)(v16 + 288)) != 0 )
        {
          v15 = cam_io_r(v17 + v14);
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x20000,
            1,
            "cam_soc_util_r",
            853,
            "No valid mapped starting address found");
          v15 = 0;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_camif_reg_dump",
          554,
          "offset 0x%x value 0x%x",
          v14,
          v15);
        v14 += 4LL;
      }
      while ( v14 < (v12 << 8) + 8824 );
      ++v12;
      v13 += 256;
    }
    while ( v12 != 24 );
    return cam_cpas_dump_camnoc_buff_fill_info();
  }
  return result;
}
