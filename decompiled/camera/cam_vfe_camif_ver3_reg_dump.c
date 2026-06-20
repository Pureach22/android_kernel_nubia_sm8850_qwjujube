__int64 __fastcall cam_vfe_camif_ver3_reg_dump(__int64 result)
{
  __int64 v1; // x25
  __int64 v2; // x19
  unsigned __int64 v3; // x21
  bool v4; // cf
  __int64 v5; // x8
  __int64 v6; // x8
  int v7; // w7
  unsigned int v8; // w8
  int v9; // w7
  __int64 v10; // x9
  unsigned int v11; // w24
  __int64 v12; // x8
  unsigned int v13; // w8
  int v14; // w7
  __int64 v15; // x9
  unsigned int v16; // w24
  __int64 v17; // x8
  unsigned __int64 v18; // x23
  int v19; // w7
  __int64 v20; // x8
  __int64 v21; // x8
  unsigned int v22; // w24
  int v23; // w7
  int v24; // w8
  __int64 v25; // x8
  __int64 v26; // x8
  unsigned __int64 v27; // x22
  __int64 v28; // x8
  __int64 v29; // x8
  int v30; // w7
  char v31; // w8
  __int64 v32; // x24
  __int64 v33; // x26
  unsigned __int64 v34; // x23
  int v35; // w7
  __int64 v36; // x8
  __int64 v37; // x8

  if ( (unsigned int)(*(_DWORD *)(result + 8) - 1) < 2 )
    return result;
  v1 = *(_QWORD *)(result + 24);
  v2 = result;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_reg_dump",
    633,
    "IFE:%d TOP",
    *(_DWORD *)(*(_QWORD *)(result + 16) + 4LL));
  v3 = 0;
  do
  {
    if ( ((unsigned int)v3 > 0x38 || ((1LL << v3) & 0x110000010000000LL) == 0) && (_DWORD)v3 != 144 )
    {
      v5 = *(_QWORD *)(v1 + 40);
      if ( v5 && *(_DWORD *)(v5 + 480) && (v6 = *(_QWORD *)(v5 + 288)) != 0 )
      {
        v7 = cam_io_r(v6 + v3);
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
        v7 = 0;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_reg_dump",
        639,
        "offset 0x%X value 0x%X",
        v3,
        v7);
    }
    v4 = v3 >= 0x1F9;
    v3 += 4LL;
  }
  while ( !v4 );
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_reg_dump",
    643,
    "IFE:%d PP CLC PREPROCESS",
    *(_DWORD *)(*(_QWORD *)(v2 + 16) + 4LL));
  v8 = 8704;
  do
  {
    v10 = *(_QWORD *)(v1 + 40);
    if ( v8 == 8712 )
      v11 = 8800;
    else
      v11 = v8;
    if ( v10 && *(_DWORD *)(v10 + 480) && (v12 = *(_QWORD *)(v10 + 288)) != 0 )
    {
      v9 = cam_io_r(v12 + v11);
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
      v9 = 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_reg_dump",
      648,
      "offset 0x%X value 0x%X",
      v11,
      v9);
    v8 = v11 + 4;
    if ( v11 == 8800 )
      v8 = 9208;
  }
  while ( v8 < 0x23FD );
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_reg_dump",
    653,
    "IFE:%d PP CLC CAMIF",
    *(_DWORD *)(*(_QWORD *)(v2 + 16) + 4LL));
  v13 = 9728;
  do
  {
    v15 = *(_QWORD *)(v1 + 40);
    if ( v13 == 9736 )
      v16 = 9824;
    else
      v16 = v13;
    if ( v15 && *(_DWORD *)(v15 + 480) && (v17 = *(_QWORD *)(v15 + 288)) != 0 )
    {
      v14 = cam_io_r(v17 + v16);
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
      v14 = 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_reg_dump",
      658,
      "offset 0x%X value 0x%X",
      v16,
      v14);
    v13 = v16 + 4;
    if ( v16 == 9856 )
      v13 = 10224;
    if ( v16 == 9824 )
      v13 = 9832;
  }
  while ( v13 < 0x27FD );
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_reg_dump",
    665,
    "IFE:%d PP CLC Modules",
    *(_DWORD *)(*(_QWORD *)(v2 + 16) + 4LL));
  v18 = 10240;
  do
  {
    v20 = *(_QWORD *)(v1 + 40);
    if ( v20 && *(_DWORD *)(v20 + 480) && (v21 = *(_QWORD *)(v20 + 288)) != 0 )
    {
      v19 = cam_io_r(v21 + v18);
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
      v19 = 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_reg_dump",
      668,
      "offset 0x%X value 0x%X",
      v18,
      v19);
    v4 = v18 >= 0x8FF9;
    v18 += 4LL;
  }
  while ( !v4 );
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_reg_dump",
    671,
    "IFE:%d BUS RD",
    *(_DWORD *)(*(_QWORD *)(v2 + 16) + 4LL));
  v22 = 43008;
  do
  {
    v25 = *(_QWORD *)(v1 + 40);
    if ( v25 && *(_DWORD *)(v25 + 480) && (v26 = *(_QWORD *)(v25 + 288)) != 0 )
    {
      v23 = cam_io_r(v26 + v22);
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
      v23 = 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_reg_dump",
      674,
      "offset 0x%X value 0x%X",
      v22,
      v23);
    if ( v22 == 43064 )
      v24 = 43076;
    else
      v24 = v22;
    if ( v24 == 43108 )
      v24 = 43124;
    if ( v24 == 43128 )
      v22 = 43136;
    else
      v22 = v24 + 4;
  }
  while ( v22 < 0xA89D );
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_reg_dump",
    683,
    "IFE:%d BUS WR",
    *(_DWORD *)(*(_QWORD *)(v2 + 16) + 4LL));
  v27 = 43520;
  do
  {
    v28 = *(_QWORD *)(v1 + 40);
    if ( v28 && *(_DWORD *)(v28 + 480) && (v29 = *(_QWORD *)(v28 + 288)) != 0 )
    {
      v30 = cam_io_r(v29 + v27);
      v31 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_62;
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
      v30 = 0;
      v31 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_62;
    }
    if ( !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v31 & 8,
        4,
        "cam_vfe_camif_ver3_reg_dump",
        686,
        "offset 0x%X value 0x%X",
        v27,
        v30);
LABEL_62:
    v4 = v27 >= 0xAAD9;
    v27 += 4LL;
  }
  while ( !v4 );
  v32 = 0;
  v33 = 44032;
  do
  {
    v34 = v33;
    do
    {
      v36 = *(_QWORD *)(v1 + 40);
      if ( v36 && *(_DWORD *)(v36 + 480) && (v37 = *(_QWORD *)(v36 + 288)) != 0 )
      {
        v35 = cam_io_r(v37 + v34);
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
        v35 = 0;
      }
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 8,
                 3,
                 "cam_vfe_camif_ver3_reg_dump",
                 694,
                 "offset 0x%X value 0x%X",
                 v34,
                 v35);
      v34 += 4LL;
    }
    while ( v34 < (v32 << 8) + 44164 );
    ++v32;
    v33 += 256;
  }
  while ( v32 != 26 );
  return result;
}
