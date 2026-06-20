__int64 __fastcall _cam_isp_ctx_print_event_record(__int64 *a1)
{
  __int64 v1; // x25
  __int64 result; // x0
  unsigned __int64 v3; // x20
  int v4; // w26
  unsigned int v5; // w24
  unsigned int v6; // w28
  unsigned __int64 v7; // x22
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x8
  __int64 v11; // x4
  char *v12; // x0
  __int64 v13; // x3
  __int64 v14; // x1
  __int64 v15; // x5
  const char *v16; // x7
  __int64 v17; // [xsp+10h] [xbp-410h]
  _QWORD *v18; // [xsp+18h] [xbp-408h]
  _QWORD *v19; // [xsp+20h] [xbp-400h]
  char s[1000]; // [xsp+28h] [xbp-3F8h] BYREF
  __int64 v21; // [xsp+410h] [xbp-10h]

  v19 = a1 + 5264;
  v18 = a1 + 5270;
  v1 = 0;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *a1;
  do
  {
    v3 = v19[v1];
    if ( (unsigned int)(v3 + 1) > 1 )
      v4 = v3 + 1;
    else
      v4 = 1;
    memset(s, 0, sizeof(s));
    v5 = 0;
    if ( v3 >= 8 )
      v6 = (v3 + 1) & 7;
    else
      v6 = 0;
    if ( v3 >= 8 )
      v4 = 8;
    do
    {
      v7 = (unsigned __int64)&v18[64 * v1 + 8 * (unsigned __int64)v6];
      v8 = ns_to_timespec64(*(_QWORD *)(v7 + 8));
      if ( v5 >= 0x3E8 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "__cam_isp_ctx_print_event_record",
          226,
          "Overshooting buffer length %llu",
          v5);
        goto LABEL_19;
      }
      v10 = (unsigned __int128)(v9 * (__int128)0x20C49BA5E353F7CFLL) >> 64;
      v11 = v8;
      v12 = &s[v5];
      v13 = *(_QWORD *)v7;
      v14 = 1000 - v5;
      v15 = (v10 >> 7) + ((unsigned __int64)v10 >> 63);
      if ( *(_DWORD *)(v7 + 16) == 5 )
        result = scnprintf(
                   v12,
                   v14,
                   "%llu[%lld:%06ld] [%d %lld %llu %llu] | ",
                   v13,
                   v11,
                   v15,
                   *(_DWORD *)(v7 + 40),
                   *(_QWORD *)(v7 + 24),
                   *(_QWORD *)(v7 + 56),
                   *(_QWORD *)(v7 + 48));
      else
        result = scnprintf(v12, v14, "%llu[%lld:%06ld] ", v13, v11, v15);
      --v4;
      v5 += result;
      v6 = (v6 + 1) & 7;
    }
    while ( v4 );
    if ( !v5 )
      goto LABEL_3;
LABEL_19:
    v16 = "CAM_ISP_EVENT_INVALID";
    if ( (unsigned int)v1 <= 5 )
      v16 = off_451820[v1 & 7];
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "__cam_isp_ctx_print_event_record",
               251,
               "Ctx:%d %s: %s",
               *(_DWORD *)(v17 + 32),
               v16,
               s);
LABEL_3:
    ++v1;
  }
  while ( v1 != 6 );
  _ReadStatusReg(SP_EL0);
  return result;
}
