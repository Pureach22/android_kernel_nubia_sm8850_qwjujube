__int64 __fastcall _cam_isp_ctx_user_dump_state_monitor_array(_QWORD *a1, _QWORD *a2)
{
  unsigned __int64 v4; // x22
  __int64 v5; // x7
  unsigned int v6; // w23
  __int64 result; // x0
  unsigned __int64 v8; // x8
  unsigned int *v9; // x2
  const char *v10; // x5
  __int64 v11; // x8
  __int64 v12; // x8
  const char *v13; // x6
  int v14; // w0
  unsigned int v15; // w19
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a1 && a2 )
  {
    v4 = a1[4675];
    if ( v4 >= 0x54 )
    {
      v8 = v4 + 1;
      LODWORD(v4) = 84;
      v6 = v8 % 0x54;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_user_dump_state_monitor_array",
        767,
        "Dumping state information for preceding requests");
      while ( 1 )
      {
LABEL_8:
        v9 = (unsigned int *)&a1[7 * v6 + 4676];
        v10 = "INVALID";
        v11 = *v9;
        if ( (unsigned int)v11 <= 6 )
          v10 = off_451850[v11];
        v12 = v9[1];
        v13 = "CAM_ISP_EVENT_INVALID";
        if ( (unsigned int)v12 <= 0xB )
          v13 = off_451888[v12];
        v14 = cam_common_user_dump_helper(
                a2,
                (__int64 (__fastcall *)(__int64, __int64))cam_isp_ctx_user_dump_state_monitor_array_info,
                (__int64)v9,
                8,
                "ISP_STATE_MONITOR.%s.%s:",
                (__int64)v10,
                (__int64)v13,
                v5,
                vars0);
        if ( v14 )
          break;
        if ( v6 + 1 < 0x54 )
          ++v6;
        else
          v6 -= 83;
        LODWORD(v4) = v4 - 1;
        if ( !(_DWORD)v4 )
          return 0;
      }
      v15 = v14;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_user_dump_state_monitor_array",
        782,
        "CAM ISP CONTEXT: Event record dump failed, rc: %d",
        v14);
      return v15;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_user_dump_state_monitor_array",
        767,
        "Dumping state information for preceding requests");
      v6 = 0;
      result = 0;
      if ( (_DWORD)v4 )
        goto LABEL_8;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_user_dump_state_monitor_array",
      750,
      "Invalid args %pK %pK",
      a2,
      a1);
    return 4294967274LL;
  }
  return result;
}
