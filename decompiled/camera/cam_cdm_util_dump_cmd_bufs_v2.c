__int64 __fastcall cam_cdm_util_dump_cmd_bufs_v2(__int64 *a1)
{
  _DWORD *v1; // x24
  __int64 v4; // x6
  unsigned __int64 v5; // x7
  unsigned __int64 v6; // x20
  unsigned int v7; // w8
  unsigned __int64 v8; // x23
  __int64 v9; // x0
  unsigned __int64 v10; // x23
  __int64 v11; // x0
  __int64 v12; // x20
  __int64 v13; // x8
  int *v14; // x9
  __int64 v15; // x10
  int v16; // w12
  __int64 v17; // x11
  __int64 v18; // x10
  unsigned int v19; // w11
  _DWORD *v20; // x12
  __int64 v21; // x8

  if ( !a1 || (v1 = (_DWORD *)a1[2]) == nullptr || !a1[3] || !a1[4] )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      3,
      "cam_cdm_util_dump_cmd_bufs_v2",
      1282,
      "Invalid args");
    return 4294967274LL;
  }
  do
  {
    v4 = *a1;
    v5 = a1[1];
    v6 = v5 - *a1;
    if ( v5 <= *a1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        2,
        "cam_cdm_util_dump_cmd_bufs_v2",
        1292,
        "Dump overshoot offset %zu size %zu",
        v4,
        v5);
      return 4294967268LL;
    }
    v7 = (unsigned __int8)HIBYTE(*v1);
    if ( v7 > 7 )
    {
      if ( HIBYTE(*v1) > 9u )
      {
        if ( v7 - 10 < 2 || v7 == 12 )
        {
LABEL_7:
          v1 += 3;
          continue;
        }
        goto LABEL_29;
      }
      if ( v7 != 8 && v7 != 9 )
        goto LABEL_29;
LABEL_30:
      ++v1;
      continue;
    }
    if ( HIBYTE(*v1) > 4u )
    {
      if ( v7 == 5 || v7 == 6 )
      {
        v1 += 2;
        continue;
      }
      if ( v7 == 7 )
        goto LABEL_7;
LABEL_29:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_util_dump_cmd_bufs_v2",
        1337,
        "Invalid CMD: 0x%x",
        HIBYTE(*v1));
      goto LABEL_30;
    }
    switch ( v7 )
    {
      case 1u:
        goto LABEL_7;
      case 3u:
        v10 = 4 * (unsigned int)(unsigned __int16)*v1 + 152;
        if ( v6 >= v10 )
        {
          v12 = a1[4] + v4;
          scnprintf(v12, 128, "CDM_REG_CONT:");
          *(_DWORD *)(v12 + 136) = 4;
          *(_DWORD *)(v12 + 144) = v1[1] & 0xFFFFFF;
          v13 = v12 + 144;
          *(_DWORD *)(v12 + 148) = *(unsigned __int16 *)v1;
          v14 = (int *)(v12 + 152);
          if ( *(_WORD *)v1 )
          {
            v15 = 0;
            do
            {
              v16 = v1[v15++ + 2];
              *v14++ = v16;
            }
            while ( (unsigned int)v15 < *(unsigned __int16 *)v1 );
            v17 = *(unsigned int *)(v12 + 136);
            v18 = (unsigned int)(v15 + 2);
          }
          else
          {
            v17 = 4;
            v18 = 2;
          }
          goto LABEL_46;
        }
        if ( (unsigned int)__ratelimit(&cam_cdm_util_dump_reg_cont_cmd_v2__rs, "cam_cdm_util_dump_reg_cont_cmd_v2") )
          v11 = 3;
        else
          v11 = 2;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, _QWORD))cam_print_log)(
          v11,
          1,
          2,
          "cam_cdm_util_dump_reg_cont_cmd_v2",
          1199,
          "Dump buffer exhaust remain %zu min %u",
          v6,
          (unsigned int)v10);
        v1 += 2;
        break;
      case 4u:
        v8 = 8LL * (unsigned __int16)*v1 + 148;
        if ( v6 >= v8 )
        {
          v12 = a1[4] + v4;
          scnprintf(v12, 128, "CDM_REG_RANDOM:");
          *(_DWORD *)(v12 + 136) = 4;
          *(_DWORD *)(v12 + 144) = *(unsigned __int16 *)v1;
          v13 = v12 + 144;
          v14 = (int *)(v12 + 148);
          if ( *(_WORD *)v1 )
          {
            v19 = 0;
            v18 = 1;
            do
            {
              v20 = &v1[v18];
              ++v19;
              v18 += 2;
              *v14 = *v20 & 0xFFFFFF;
              v14[1] = v20[1];
              v14 += 2;
            }
            while ( v19 < *(unsigned __int16 *)v1 );
            v17 = *(unsigned int *)(v12 + 136);
            v18 = (unsigned int)v18;
          }
          else
          {
            v17 = 4;
            v18 = 1;
          }
LABEL_46:
          v1 += v18;
          v21 = (((__int64)v14 - v13) >> 2) * v17;
          *(_QWORD *)(v12 + 128) = v21;
          *a1 += v21 + 144;
          break;
        }
        if ( (unsigned int)__ratelimit(&cam_cdm_util_dump_reg_random_cmd_v2__rs, "cam_cdm_util_dump_reg_random_cmd_v2") )
          v9 = 3;
        else
          v9 = 2;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, _QWORD))cam_print_log)(
          v9,
          1,
          2,
          "cam_cdm_util_dump_reg_random_cmd_v2",
          1249,
          "Dump buffer exhaust remain %zu min %u",
          v6,
          (unsigned int)v8);
        ++v1;
        break;
      default:
        goto LABEL_29;
    }
  }
  while ( (unsigned __int64)v1 < a1[3] );
  return 0;
}
