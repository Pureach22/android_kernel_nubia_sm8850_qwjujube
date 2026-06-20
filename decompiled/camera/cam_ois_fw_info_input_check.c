__int64 __fastcall cam_ois_fw_info_input_check(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  unsigned __int64 v4; // x6
  unsigned __int64 v5; // x20
  unsigned int *v6; // x26
  __int64 v7; // x7
  __int64 v8; // x7
  __int64 v9; // x27
  unsigned __int64 v10; // x28
  __int64 v11; // x27
  unsigned __int64 v12; // x28
  __int64 v14; // x21

  if ( (*(_BYTE *)(a1 + 12) & 1) != 0 )
  {
    v3 = *(_DWORD *)(a1 + 16);
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
    {
      v14 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "cam_ois_fw_info_input_check",
        793,
        "versionSize: %d",
        v3);
      a1 = v14;
    }
  }
  else
  {
    v3 = 0;
  }
  v4 = ((unsigned __int64)*(unsigned __int8 *)(a1 + 6) << 6) + v3 + 32;
  if ( *(_BYTE *)(a1 + 6) )
  {
    v5 = 0;
    v6 = (unsigned int *)(a1 + 92);
    do
    {
      v7 = *(v6 - 1);
      if ( (_DWORD)v7 && (v4 += v7, (debug_mdl & 0x100000) != 0) && !debug_priority )
      {
        v11 = a1;
        v12 = v4;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 0x100000,
          4,
          "cam_ois_fw_info_input_check",
          802,
          "count:%d, fw init size:%d",
          (unsigned int)v5);
        v4 = v12;
        a1 = v11;
        v8 = *v6;
        if ( (_DWORD)v8 )
        {
LABEL_13:
          v4 += v8;
          if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
          {
            v9 = a1;
            v10 = v4;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              debug_mdl & 0x100000,
              4,
              "cam_ois_fw_info_input_check",
              806,
              "count:%d, fw finalize size:%d",
              (unsigned int)v5);
            v4 = v10;
            a1 = v9;
          }
        }
      }
      else
      {
        v8 = *v6;
        if ( (_DWORD)v8 )
          goto LABEL_13;
      }
      ++v5;
      v6 += 16;
    }
    while ( v5 < *(unsigned __int8 *)(a1 + 6) );
  }
  if ( v4 == a2 )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x100000,
    1,
    "cam_ois_fw_info_input_check",
    810,
    "cmd size validate error! cmdsize:%d, expect:%d",
    v4,
    a2);
  return 4294967274LL;
}
