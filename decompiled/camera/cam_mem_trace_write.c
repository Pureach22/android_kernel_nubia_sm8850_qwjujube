__int64 __fastcall cam_mem_trace_write(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  char *v5; // x0
  char *v6; // x20
  const char *v7; // x5
  __int64 v8; // x2
  __int64 v9; // x4
  unsigned int v10; // w8
  __int64 v11; // [xsp+8h] [xbp-58h] BYREF
  char *stringp; // [xsp+10h] [xbp-50h] BYREF
  _QWORD v13[9]; // [xsp+18h] [xbp-48h] BYREF

  v13[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v13, 0, 64);
  v11 = 0;
  if ( !inline_copy_from_user_0((__int64)v13, a2, 0x40u) )
  {
    stringp = (char *)v13;
    v5 = strsep(&stringp, " ");
    if ( !v5 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x400000,
        2,
        "cam_mem_trace_write",
        662,
        "Empty input");
      goto LABEL_3;
    }
    v6 = v5;
    if ( strnstr(v5, "enable", 6) )
    {
      byte_2FDB54 = 1;
      goto LABEL_3;
    }
    if ( strnstr(v6, "disable", 7) )
    {
      byte_2FDB54 = 0;
      goto LABEL_3;
    }
    if ( (unsigned int)kstrtouint(v6, 0, (char *)&v11 + 4) )
    {
      v7 = "Invalid input : %s";
      v8 = 2;
      v9 = 670;
LABEL_12:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, char *))cam_print_log)(
        3,
        0x400000,
        v8,
        "cam_mem_trace_write",
        v9,
        v7,
        v6);
      goto LABEL_3;
    }
    if ( SHIDWORD(v11) > 1 )
    {
      if ( HIDWORD(v11) == 2 )
      {
        if ( !stringp || (unsigned int)kstrtouint(stringp, 0, &v11) || (v10 = v11) == 0 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x400000,
            3,
            "cam_mem_trace_write",
            683,
            "Params err: No threshold to query sedentary mem");
          goto LABEL_3;
        }
        goto LABEL_25;
      }
      if ( HIDWORD(v11) == 3 )
      {
        cam_mem_trace_query_mass_mem();
        goto LABEL_3;
      }
    }
    else
    {
      if ( !HIDWORD(v11) )
      {
        cam_mem_trace_overview();
        goto LABEL_3;
      }
      if ( HIDWORD(v11) == 1 )
      {
        v10 = 0;
LABEL_25:
        cam_mem_trace_query(v10);
        goto LABEL_3;
      }
    }
    v7 = "Unsupported param %s";
    v8 = 3;
    v9 = 694;
    goto LABEL_12;
  }
  a3 = -14;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return a3;
}
