__int64 __fastcall _cam_isp_ctx_dump_event_record(char *a1, _QWORD *a2)
{
  __int64 v3; // x22
  char *v4; // x11
  char *v5; // x12
  unsigned __int64 v6; // x10
  unsigned __int64 v7; // x7
  unsigned __int64 v8; // x8
  unsigned int v9; // w9
  unsigned __int64 v10; // x6
  unsigned __int64 v11; // x7
  char *v12; // x27
  unsigned int v13; // w28
  int v14; // w25
  const char *v15; // x5
  int v16; // w0
  __int64 result; // x0
  unsigned int v18; // w19
  char *v19; // [xsp+0h] [xbp-10h]
  char *v20; // [xsp+8h] [xbp-8h]

  if ( a1 && a2 )
  {
    v3 = 0;
    v4 = a1 + 42112;
    v5 = a1 + 42160;
    LOBYTE(v19) = (_BYTE)a1 - 80;
    v20 = a1 + 42112;
    while ( 2 )
    {
      v6 = *(_QWORD *)&v4[8 * v3];
      v8 = a2[2];
      v7 = a2[3];
      if ( v6 < 8 )
        v9 = v6 + 1;
      else
        v9 = 8;
      v10 = v8 - v7;
      if ( v8 <= v7 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          8,
          2,
          "__cam_isp_ctx_dump_event_record",
          292,
          "Dump buffer overshoot len %zu offset %zu",
          a2[2]);
        return 4294967268LL;
      }
      else
      {
        v11 = 168 * v9;
        if ( v10 < v11 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "__cam_isp_ctx_dump_event_record",
            303,
            "Dump buffer exhaust remain %zu min %u",
            v10,
            v11);
          return 4294967268LL;
        }
        else
        {
          v12 = &v5[512 * v3];
          if ( v6 >= 8 )
            v13 = ((_BYTE)v6 + 1) & 7;
          else
            v13 = 0;
          if ( v9 <= 1 )
            v14 = 1;
          else
            v14 = v9;
          do
          {
            v15 = "CAM_ISP_EVENT_INVALID";
            if ( (unsigned int)v3 <= 5 )
              v15 = off_451820[v3 & 7];
            v16 = cam_common_user_dump_helper(
                    a2,
                    (__int64 (__fastcall *)(__int64, __int64))cam_isp_ctx_user_dump_events,
                    (__int64)&v12[64 * (unsigned __int64)v13],
                    8,
                    "ISP_EVT_%s:",
                    (__int64)v15,
                    v10,
                    v11,
                    (char)v19);
            if ( v16 )
            {
              v18 = v16;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "__cam_isp_ctx_dump_event_record",
                315,
                "CAM_ISP_CONTEXT DUMP_EVENT_RECORD: Dump failed, rc: %d",
                v16);
              return v18;
            }
            --v14;
            v13 = (v13 + 1) & 7;
          }
          while ( v14 );
          v5 = v19;
          v4 = v20;
          ++v3;
          result = 0;
          if ( v3 != 6 )
            continue;
        }
      }
      break;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_dump_event_record",
      270,
      "Invalid args %pK %pK",
      a2,
      a1);
    return 4294967274LL;
  }
  return result;
}
