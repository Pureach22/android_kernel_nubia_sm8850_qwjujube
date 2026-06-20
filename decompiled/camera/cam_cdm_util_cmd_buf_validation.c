__int64 __fastcall cam_cdm_util_cmd_buf_validation(
        __int64 a1,
        int a2,
        __int64 a3,
        unsigned int a4,
        unsigned __int16 *a5,
        unsigned __int64 *a6,
        int a7)
{
  int v8; // w9
  _QWORD *v9; // x10
  unsigned __int64 v10; // x6
  int v11; // w8
  unsigned int *i; // x9
  __int64 result; // x0
  unsigned __int64 v14; // x9
  int v15; // w8
  unsigned int v16; // w9
  const char *v17; // x5
  __int64 v18; // x4
  int v19; // w8
  unsigned int v20; // w9
  int v21; // w8
  unsigned int v22; // w9
  int v23; // w10
  int v24; // w7
  int v25; // w7
  unsigned __int64 v26; // x7
  const char *v27; // x5
  __int64 v28; // x4

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_util_cmd_buf_validation",
      505,
      "invalid base address");
    return 4294967274LL;
  }
  if ( a2 )
  {
    v8 = 0;
    while ( 1 )
    {
      v9 = *(_QWORD **)(a3 + 8LL * v8);
      if ( v9 )
      {
        if ( *v9 == a1 )
          break;
      }
      if ( a2 == ++v8 )
        goto LABEL_9;
    }
    v10 = v9[2];
    *a6 = v10;
    if ( !v10 )
      goto LABEL_8;
  }
  else
  {
LABEL_9:
    v10 = *a6;
    if ( !*a6 )
    {
LABEL_8:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_util_cmd_buf_validation",
        518,
        "Could not retrieve ioremap size, address not mapped!");
      return 4294967274LL;
    }
  }
  if ( a7 <= 3 )
  {
    if ( a7 == 1 )
    {
      v21 = *a5;
      v22 = v21 + 4;
      a7 = v21 + 1;
      if ( v22 > a4 )
      {
        v17 = "invalid CDM_SWD_DMI length %d";
        v18 = 617;
        goto LABEL_33;
      }
      v25 = (*((_DWORD *)a5 + 2) & 0xFFFFFF) + 8;
      if ( v10 < v25 + (a7 & 0x1FFFCu) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_util_cmd_buf_validation",
          626,
          "Offset out of mapped range! size:%llu offset:%u",
          v10,
          v25);
        return 4294967274LL;
      }
    }
    else
    {
      if ( a7 != 3 )
      {
LABEL_32:
        v17 = "unsupported cdm_cmd_type type 0%x";
        v18 = 633;
        goto LABEL_33;
      }
      v14 = *(_QWORD *)a5;
      if ( !(unsigned __int16)*(_QWORD *)a5 || ((4LL * (unsigned __int16)v14) | 2uLL) > a4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_util_cmd_buf_validation",
          556,
          "buffer size %d is not sufficient for count%d",
          a4,
          (unsigned __int16)*(_QWORD *)a5);
        return 4294967274LL;
      }
      v26 = HIDWORD(v14) & 0xFFFFFF;
      if ( v26 > v10 - 4 || v26 + 4LL * (unsigned __int16)v14 > v10 )
      {
        v27 = "Offset out of mapped range! size: %lu, offset: %u";
        v28 = 563;
        goto LABEL_48;
      }
    }
  }
  else
  {
    switch ( a7 )
    {
      case 116:
        v15 = *a5;
        v16 = v15 + 4;
        a7 = v15 + 1;
        if ( v16 > a4 )
        {
          v17 = "invalid CDM_SWD_DMI length %d";
          v18 = 574;
LABEL_33:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            1,
            1,
            "cam_cdm_util_cmd_buf_validation",
            v18,
            v17,
            (unsigned int)a7);
          return 4294967274LL;
        }
        v23 = *((_DWORD *)a5 + 2) & 0xFFFFFF;
        if ( (unsigned __int64)(v23 + 12 + (a7 & 0x1FFF8u)) - 4 > v10 || v10 < v23 + 8 + (a7 & 0x1FFF8u) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            1,
            "cam_cdm_util_cmd_buf_validation",
            586,
            "Offset out of mapped range! size:%llu lo_offset:%u hi_offset:%u",
            v10,
            v23 + 12,
            v23 + 8);
          return 4294967274LL;
        }
        break;
      case 115:
        v19 = *a5;
        v20 = v19 + 4;
        a7 = v19 + 1;
        if ( v20 > a4 )
        {
          v17 = "invalid CDM_SWD_DMI length %d";
          v18 = 597;
          goto LABEL_33;
        }
        v24 = (*((_DWORD *)a5 + 2) & 0xFFFFFF) + 12;
        if ( v10 < v24 + (a7 & 0x1FFFCu) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            1,
            "cam_cdm_util_cmd_buf_validation",
            606,
            "Offset out of mapped range! size:%llu lo_offset:%u",
            v10,
            v24);
          return 4294967274LL;
        }
        break;
      case 4:
        v11 = *a5;
        if ( !*a5 || 8 * v11 >= a4 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            1,
            "cam_cdm_util_cmd_buf_validation",
            531,
            "invalid reg_count  %d cmd_buf_size %d",
            v11,
            a4);
          return 4294967274LL;
        }
        for ( i = (unsigned int *)(a5 + 2); v10 - 4 >= *i; i += 2 )
        {
          result = 0;
          if ( !--v11 )
            return result;
        }
        v27 = "Offset out of mapped range, size:%llu offset:%u";
        v28 = 541;
LABEL_48:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_util_cmd_buf_validation",
          v28,
          v27);
        return 4294967274LL;
      default:
        goto LABEL_32;
    }
  }
  return 0;
}
