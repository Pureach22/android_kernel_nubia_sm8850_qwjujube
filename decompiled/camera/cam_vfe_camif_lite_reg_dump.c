__int64 __fastcall cam_vfe_camif_lite_reg_dump(__int64 result)
{
  __int64 v1; // x25
  __int64 v2; // x19
  __int64 v3; // x28
  unsigned __int64 v4; // x20
  int v5; // w7
  bool v6; // cf
  __int64 v7; // x8
  __int64 v8; // x8
  unsigned __int64 v9; // x20
  __int64 v10; // x8
  __int64 v11; // x8
  int v12; // w7
  int v13; // w8
  int v14; // w6
  int v15; // w8
  unsigned int v16; // w23
  __int64 v17; // x9
  __int64 v18; // x8
  int v19; // w7
  int v20; // w8
  unsigned int v21; // w23
  __int64 v22; // x9
  __int64 v23; // x8
  int v24; // w7
  int v25; // w8
  unsigned int v26; // w23
  __int64 v27; // x9
  __int64 v28; // x8
  int v29; // w7
  int v30; // w8
  unsigned int v31; // w23
  __int64 v32; // x9
  __int64 v33; // x8
  int v34; // w7
  int v35; // w8
  unsigned int v36; // w23
  __int64 v37; // x9
  __int64 v38; // x8
  int v39; // w7
  unsigned __int64 v40; // x22
  int v41; // w7
  __int64 v42; // x8
  __int64 v43; // x8
  int v44; // w8
  unsigned int v45; // w23
  __int64 v46; // x9
  __int64 v47; // x8
  int v48; // w7
  unsigned int v49; // w22
  __int64 v50; // x8
  __int64 v51; // x8
  int v52; // w7
  int v53; // w8
  unsigned int v54; // w23
  __int64 v55; // x9
  __int64 v56; // x8
  int v57; // w7
  int v58; // w8
  unsigned int v59; // w23
  __int64 v60; // x9
  __int64 v61; // x8
  int v62; // w7
  int v63; // w8
  unsigned int v64; // w23
  __int64 v65; // x9
  __int64 v66; // x8
  int v67; // w7
  unsigned __int64 v68; // x22
  __int64 v69; // x8
  __int64 v70; // x8
  int v71; // w7
  char v72; // w8
  unsigned __int64 v73; // x23
  int v74; // w7
  unsigned __int64 v75; // x8
  __int64 v76; // x8
  __int64 v77; // x8
  unsigned __int64 v78; // x23
  int v79; // w7
  unsigned __int64 v80; // x8
  __int64 v81; // x8
  __int64 v82; // x8
  unsigned __int64 v83; // x23
  int v84; // w7
  unsigned __int64 v85; // x8
  __int64 v86; // x8
  __int64 v87; // x8
  unsigned __int64 v88; // x23
  int v89; // w7
  unsigned __int64 v90; // x8
  __int64 v91; // x8
  __int64 v92; // x8

  if ( (unsigned int)(*(_DWORD *)(result + 8) - 1) < 2 )
    return result;
  v1 = *(_QWORD *)(result + 24);
  v2 = result;
  v3 = *(_QWORD *)(*(_QWORD *)(v1 + 40) + 3296LL);
  if ( !v3 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "cam_vfe_camif_lite_reg_dump",
             433,
             "Invalid soc_private");
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_lite_reg_dump",
    437,
    "IFE:%d TOP",
    *(_DWORD *)(*(_QWORD *)(v1 + 8) + 4LL));
  if ( (*(_BYTE *)(v3 + 24) & 1) != 0 )
  {
    v4 = 0;
    do
    {
      if ( v4 != 12 && (v4 & 0x78) != 0x20 )
      {
        v7 = *(_QWORD *)(v1 + 40);
        if ( v7 && *(_DWORD *)(v7 + 480) && (v8 = *(_QWORD *)(v7 + 288)) != 0 )
        {
          v5 = cam_io_r(v8 + v4);
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
          v5 = 0;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_camif_lite_reg_dump",
          455,
          "offset 0x%X value 0x%X",
          v4,
          v5);
      }
      v6 = v4 >= 0x71;
      v4 += 4LL;
    }
    while ( !v6 );
  }
  else
  {
    v9 = 0;
    do
    {
      if ( ((unsigned int)v9 > 0x38 || ((1LL << v9) & 0x110000010000000LL) == 0) && (_DWORD)v9 != 144 )
      {
        v10 = *(_QWORD *)(v1 + 40);
        if ( v10 && *(_DWORD *)(v10 + 480) && (v11 = *(_QWORD *)(v10 + 288)) != 0 )
        {
          v12 = cam_io_r(v11 + v9);
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
          v12 = 0;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_camif_lite_reg_dump",
          446,
          "offset 0x%X value 0x%X",
          v9,
          v12);
      }
      v6 = v9 >= 0x1F9;
      v9 += 4LL;
    }
    while ( !v6 );
  }
  v13 = *(_DWORD *)(v2 + 4);
  v14 = *(_DWORD *)(*(_QWORD *)(v1 + 8) + 4LL);
  if ( v13 <= 4 )
  {
    if ( v13 == 3 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_reg_dump",
        463,
        "IFE:%d RDI0 CAMIF",
        v14);
      if ( (*(_BYTE *)(v3 + 24) & 1) != 0 )
      {
        v35 = 4608;
        do
        {
          v37 = *(_QWORD *)(v1 + 40);
          if ( v35 == 4616 )
            v36 = 4704;
          else
            v36 = v35;
          if ( v37 && *(_DWORD *)(v37 + 480) && (v38 = *(_QWORD *)(v37 + 288)) != 0 )
          {
            v39 = cam_io_r(v38 + v36);
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
            v39 = 0;
          }
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_vfe_camif_lite_reg_dump",
                     484,
                     "offset 0x%X value 0x%X",
                     v36,
                     v39);
          if ( v36 == 4704 )
          {
            v36 = 4708;
          }
          else if ( v36 == 4720 )
          {
            v36 = 4844;
          }
          v35 = v36 + 4;
        }
        while ( v36 < 0x13F9 );
      }
      else
      {
        v58 = 39424;
        do
        {
          v60 = *(_QWORD *)(v1 + 40);
          if ( v58 == 39432 )
            v59 = 39520;
          else
            v59 = v58;
          if ( v60 && *(_DWORD *)(v60 + 480) && (v61 = *(_QWORD *)(v60 + 288)) != 0 )
          {
            v62 = cam_io_r(v61 + v59);
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
            v62 = 0;
          }
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_vfe_camif_lite_reg_dump",
                     471,
                     "offset 0x%X value 0x%X",
                     v59,
                     v62);
          if ( (unsigned __int16)v59 == 39520 )
          {
            v59 = 39524;
          }
          else if ( (unsigned __int16)v59 == 39536 )
          {
            v59 = 39660;
          }
          v58 = v59 + 4;
        }
        while ( v59 < 0x9BF9 );
      }
      goto LABEL_185;
    }
    if ( v13 == 4 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_reg_dump",
        499,
        "IFE:%d RDI1 CAMIF",
        v14);
      if ( (*(_BYTE *)(v3 + 24) & 1) != 0 )
      {
        v20 = 5120;
        do
        {
          v22 = *(_QWORD *)(v1 + 40);
          if ( v20 == 5128 )
            v21 = 5216;
          else
            v21 = v20;
          if ( v22 && *(_DWORD *)(v22 + 480) && (v23 = *(_QWORD *)(v22 + 288)) != 0 )
          {
            v24 = cam_io_r(v23 + v21);
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
            v24 = 0;
          }
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_vfe_camif_lite_reg_dump",
                     520,
                     "offset 0x%X value 0x%X",
                     v21,
                     v24);
          if ( v21 == 5216 )
          {
            v21 = 5220;
          }
          else if ( v21 == 5232 )
          {
            v21 = 5612;
          }
          v20 = v21 + 4;
        }
        while ( v21 < 0x15F9 );
      }
      else
      {
        v63 = 39936;
        do
        {
          v65 = *(_QWORD *)(v1 + 40);
          if ( v63 == 39944 )
            v64 = 40032;
          else
            v64 = v63;
          if ( v65 && *(_DWORD *)(v65 + 480) && (v66 = *(_QWORD *)(v65 + 288)) != 0 )
          {
            v67 = cam_io_r(v66 + v64);
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
            v67 = 0;
          }
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_vfe_camif_lite_reg_dump",
                     507,
                     "offset 0x%X value 0x%X",
                     v64,
                     v67);
          if ( (unsigned __int16)v64 == 40032 )
          {
            v64 = 40036;
          }
          else if ( (unsigned __int16)v64 == 40048 )
          {
            v64 = 40428;
          }
          v63 = v64 + 4;
        }
        while ( v64 < 0x9DF9 );
      }
      goto LABEL_185;
    }
LABEL_113:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_reg_dump",
      617,
      "IFE:%d LCR CAMIF",
      v14);
    v44 = 40960;
    do
    {
      v46 = *(_QWORD *)(v1 + 40);
      if ( v44 == 40968 )
        v45 = 41056;
      else
        v45 = v44;
      if ( v46 && *(_DWORD *)(v46 + 480) && (v47 = *(_QWORD *)(v46 + 288)) != 0 )
      {
        v48 = cam_io_r(v47 + v45);
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
        v48 = 0;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_reg_dump",
        623,
        "offset 0x%X value 0x%X",
        v45,
        v48);
      if ( (unsigned __int16)v45 == 41056 )
      {
        v45 = 41060;
      }
      else if ( (unsigned __int16)v45 == 41072 )
      {
        v45 = 41452;
      }
      v44 = v45 + 4;
    }
    while ( v45 < 0xA1F9 );
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_reg_dump",
      630,
      "IFE:%d CLC LCR",
      *(_DWORD *)(*(_QWORD *)(v1 + 8) + 4LL));
    v49 = 41472;
    while ( 1 )
    {
      if ( (unsigned __int16)v49 == 41480 )
      {
        v49 = 41568;
        v50 = *(_QWORD *)(v1 + 40);
        if ( !v50 )
          goto LABEL_139;
      }
      else
      {
        if ( (unsigned __int16)v49 == 41608 )
          v49 = 41976;
        v50 = *(_QWORD *)(v1 + 40);
        if ( !v50 )
        {
LABEL_139:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x20000,
            1,
            "cam_soc_util_r",
            853,
            "No valid mapped starting address found");
          v52 = 0;
          goto LABEL_140;
        }
      }
      if ( !*(_DWORD *)(v50 + 480) )
        goto LABEL_139;
      v51 = *(_QWORD *)(v50 + 288);
      if ( !v51 )
        goto LABEL_139;
      v52 = cam_io_r(v51 + v49);
LABEL_140:
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 8,
                 3,
                 "cam_vfe_camif_lite_reg_dump",
                 638,
                 "offset 0x%X value 0x%X",
                 v49,
                 v52);
      if ( (unsigned __int16)v49 == 41568 )
      {
        v49 = 41572;
      }
      else if ( (unsigned __int16)v49 == 41600 )
      {
        v49 = 41452;
      }
      v6 = v49 >= 0xA3F9;
      v49 += 4;
      if ( v6 )
        goto LABEL_185;
    }
  }
  if ( v13 == 5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_reg_dump",
      535,
      "IFE:%d RDI2 CAMIF",
      v14);
    if ( (*(_BYTE *)(v3 + 24) & 1) != 0 )
    {
      v25 = 5632;
      do
      {
        v27 = *(_QWORD *)(v1 + 40);
        if ( v25 == 5640 )
          v26 = 5728;
        else
          v26 = v25;
        if ( v27 && *(_DWORD *)(v27 + 480) && (v28 = *(_QWORD *)(v27 + 288)) != 0 )
        {
          v29 = cam_io_r(v28 + v26);
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
          v29 = 0;
        }
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   8,
                   3,
                   "cam_vfe_camif_lite_reg_dump",
                   556,
                   "offset 0x%X value 0x%X",
                   v26,
                   v29);
        if ( v26 == 5728 )
        {
          v26 = 5732;
        }
        else if ( v26 == 5744 )
        {
          v26 = 6124;
        }
        v25 = v26 + 4;
      }
      while ( v26 < 0x17F9 );
    }
    else
    {
      v53 = 40448;
      do
      {
        v55 = *(_QWORD *)(v1 + 40);
        if ( v53 == 40456 )
          v54 = 40544;
        else
          v54 = v53;
        if ( v55 && *(_DWORD *)(v55 + 480) && (v56 = *(_QWORD *)(v55 + 288)) != 0 )
        {
          v57 = cam_io_r(v56 + v54);
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
          v57 = 0;
        }
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   8,
                   3,
                   "cam_vfe_camif_lite_reg_dump",
                   543,
                   "offset 0x%X value 0x%X",
                   v54,
                   v57);
        if ( (unsigned __int16)v54 == 40544 )
        {
          v54 = 40548;
        }
        else if ( (unsigned __int16)v54 == 40560 )
        {
          v54 = 40940;
        }
        v53 = v54 + 4;
      }
      while ( v54 < 0x9FF9 );
    }
    goto LABEL_185;
  }
  if ( v13 == 6 )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "cam_vfe_camif_lite_reg_dump",
               571,
               "IFE:%d RDI3 CAMIF",
               v14);
    if ( *(_BYTE *)(v3 + 24) == 1 )
    {
      v30 = 6144;
      do
      {
        v32 = *(_QWORD *)(v1 + 40);
        if ( v30 == 6152 )
          v31 = 6240;
        else
          v31 = v30;
        if ( v32 && *(_DWORD *)(v32 + 480) && (v33 = *(_QWORD *)(v32 + 288)) != 0 )
        {
          v34 = cam_io_r(v33 + v31);
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
          v34 = 0;
        }
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   8,
                   3,
                   "cam_vfe_camif_lite_reg_dump",
                   579,
                   "offset 0x%X value 0x%X",
                   v31,
                   v34);
        if ( v31 == 6240 )
        {
          v31 = 6244;
        }
        else if ( v31 == 6256 )
        {
          v31 = 6636;
        }
        v30 = v31 + 4;
      }
      while ( v31 < 0x19F9 );
    }
    goto LABEL_185;
  }
  if ( v13 != 8 )
    goto LABEL_113;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_lite_reg_dump",
    594,
    "IFE:%d PDLIB CAMIF",
    v14);
  v15 = 41984;
  do
  {
    v17 = *(_QWORD *)(v1 + 40);
    if ( v15 == 41992 )
      v16 = 42080;
    else
      v16 = v15;
    if ( v17 && *(_DWORD *)(v17 + 480) && (v18 = *(_QWORD *)(v17 + 288)) != 0 )
    {
      v19 = cam_io_r(v18 + v16);
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
      "cam_vfe_camif_lite_reg_dump",
      600,
      "offset 0x%X value 0x%X",
      v16,
      v19);
    if ( (unsigned __int16)v16 == 42080 )
    {
      v16 = 42084;
    }
    else if ( (unsigned __int16)v16 == 42096 )
    {
      v16 = 42476;
    }
    v15 = v16 + 4;
  }
  while ( v16 < 0xA5F9 );
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_lite_reg_dump",
    608,
    "IFE:%d CLC PDLIB",
    *(_DWORD *)(*(_QWORD *)(v1 + 8) + 4LL));
  v40 = 42496;
  do
  {
    v42 = *(_QWORD *)(v1 + 40);
    if ( v42 && *(_DWORD *)(v42 + 480) && (v43 = *(_QWORD *)(v42 + 288)) != 0 )
    {
      v41 = cam_io_r(v43 + v40);
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
      v41 = 0;
    }
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "cam_vfe_camif_lite_reg_dump",
               611,
               "offset 0x%X value 0x%X",
               v40,
               v41);
    v6 = v40 >= 0xA715;
    v40 += 4LL;
  }
  while ( !v6 );
LABEL_185:
  if ( *(_BYTE *)(v3 + 24) != 1 )
    return result;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_lite_reg_dump",
    650,
    "IFE:%d LITE BUS WR",
    *(_DWORD *)(*(_QWORD *)(v1 + 8) + 4LL));
  v68 = 6656;
  do
  {
    v69 = *(_QWORD *)(v1 + 40);
    if ( v69 && *(_DWORD *)(v69 + 480) && (v70 = *(_QWORD *)(v69 + 288)) != 0 )
    {
      v71 = cam_io_r(v70 + v68);
      v72 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_187;
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
      v71 = 0;
      v72 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_187;
    }
    if ( !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v72 & 8,
        4,
        "cam_vfe_camif_lite_reg_dump",
        653,
        "offset 0x%X value 0x%X",
        v68,
        v71);
LABEL_187:
    v6 = v68 >= 0x1ADD;
    v68 += 4LL;
  }
  while ( !v6 );
  v73 = 7168;
  do
  {
    v76 = *(_QWORD *)(v1 + 40);
    if ( v76 && *(_DWORD *)(v76 + 480) && (v77 = *(_QWORD *)(v76 + 288)) != 0 )
    {
      v74 = cam_io_r(v77 + v73);
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
      v74 = 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_reg_dump",
      662,
      "offset 0x%X value 0x%X",
      v73,
      v74);
    v75 = v73 >> 7;
    v73 += 4LL;
  }
  while ( v75 < 0x39 );
  v78 = 7424;
  do
  {
    v81 = *(_QWORD *)(v1 + 40);
    if ( v81 && *(_DWORD *)(v81 + 480) && (v82 = *(_QWORD *)(v81 + 288)) != 0 )
    {
      v79 = cam_io_r(v82 + v78);
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
      v79 = 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_reg_dump",
      662,
      "offset 0x%X value 0x%X",
      v78,
      v79);
    v80 = v78 >> 7;
    v78 += 4LL;
  }
  while ( v80 < 0x3B );
  v83 = 7680;
  do
  {
    v86 = *(_QWORD *)(v1 + 40);
    if ( v86 && *(_DWORD *)(v86 + 480) && (v87 = *(_QWORD *)(v86 + 288)) != 0 )
    {
      v84 = cam_io_r(v87 + v83);
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
      v84 = 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_reg_dump",
      662,
      "offset 0x%X value 0x%X",
      v83,
      v84);
    v85 = v83 >> 7;
    v83 += 4LL;
  }
  while ( v85 < 0x3D );
  v88 = 7936;
  do
  {
    v91 = *(_QWORD *)(v1 + 40);
    if ( v91 && *(_DWORD *)(v91 + 480) && (v92 = *(_QWORD *)(v91 + 288)) != 0 )
    {
      v89 = cam_io_r(v92 + v88);
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
      v89 = 0;
    }
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "cam_vfe_camif_lite_reg_dump",
               662,
               "offset 0x%X value 0x%X",
               v88,
               v89);
    v90 = v88 >> 7;
    v88 += 4LL;
  }
  while ( v90 < 0x3F );
  return result;
}
