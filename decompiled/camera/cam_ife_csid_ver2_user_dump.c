__int64 __fastcall cam_ife_csid_ver2_user_dump(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x2
  unsigned int v11; // w0
  __int64 v12; // x6
  __int64 v13; // x7
  __int64 v14; // x8
  const char *v15; // x5
  unsigned int v16; // w19
  __int64 v17; // x6
  __int64 v18; // x4
  __int64 i; // x25
  __int64 v21; // x2
  unsigned int v22; // w0
  __int64 v23; // x8
  char v24; // [xsp+0h] [xbp+0h]
  char v25; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_user_dump",
      8446,
      "Invalid bus private data");
    return 4294967274LL;
  }
  v8 = *(_QWORD *)(a1 + 31128);
  if ( !*(_DWORD *)(v8 + 92) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "cam_ife_csid_ver2_user_dump",
      8451,
      "CSID:%u powered down",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
    return 4294967274LL;
  }
  v11 = cam_common_user_dump_helper(
          a2,
          (__int64 (__fastcall *)(__int64, __int64))cam_common_user_dump_clock,
          v8,
          8,
          "CLK_RATE_PRINT:",
          a6,
          a7,
          a8,
          v24);
  if ( v11 )
  {
    v14 = *(_QWORD *)(a1 + 31120);
    v15 = "CSID:%u VER2: Clock dump failed, rc: %d";
    v16 = v11;
    v17 = *(unsigned int *)(v14 + 4);
    v18 = 8462;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_user_dump",
      v18,
      v15,
      v17,
      v16);
    return v16;
  }
  else
  {
    for ( i = 0; i != 1824; i += 152 )
    {
      v21 = a1 + i;
      if ( *(_DWORD *)(a1 + i + 8) > 1u )
      {
        if ( *(_QWORD *)(v21 + 24) )
        {
          v22 = cam_common_user_dump_helper(
                  a2,
                  (__int64 (__fastcall *)(__int64, __int64))&cam_ife_csid_ver2_user_dump_info,
                  v21,
                  4,
                  "CSID2_PATH.%s:",
                  a1 + i + 128,
                  v12,
                  v13,
                  v25);
          if ( v22 )
          {
            v23 = *(_QWORD *)(a1 + 31120);
            v15 = "CSID:%u VER2: Info dump failed, rc:%d";
            v16 = v22;
            v17 = *(unsigned int *)(v23 + 4);
            v18 = 8486;
            goto LABEL_5;
          }
        }
      }
      else if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver2_user_dump",
          8473,
          "CSID:%u VER2: path inactive res ID: %d, continuing",
          *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
          *(_DWORD *)(a1 + i + 4));
      }
    }
    return 0;
  }
}
