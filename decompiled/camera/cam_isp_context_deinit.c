__int64 __fastcall cam_isp_context_deinit(_QWORD *s)
{
  char *v2; // x20
  char **v3; // x9
  char **v4; // x8
  char *v5; // x23
  char **v6; // x0
  int v7; // w8
  const char *v8; // x6

  v2 = (char *)(s + 5715);
  v3 = (char **)s[5715];
  if ( v3 != s + 5715 )
  {
    do
    {
      v5 = *v3;
      v4 = (char **)v3[1];
      if ( *v4 == (char *)v3 && *((char ***)v5 + 1) == v3 )
      {
        *((_QWORD *)v5 + 1) = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      v6 = v3 - 1;
      *v3 = (char *)0xDEAD000000000100LL;
      v3[1] = (char *)0xDEAD000000000122LL;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v6, 0);
      else
        kvfree(v6);
      v3 = (char **)v5;
    }
    while ( v5 != v2 );
  }
  if ( *s )
    cam_context_deinit((_DWORD *)*s);
  v7 = *((_DWORD *)s + 5);
  if ( v7 > 2 )
  {
    if ( v7 <= 4 )
    {
      if ( v7 == 3 )
        v8 = "BUBBLE";
      else
        v8 = "BUBBLE_APPLIED";
      goto LABEL_28;
    }
    if ( v7 == 5 )
    {
      v8 = "HW_ERROR";
      goto LABEL_28;
    }
    if ( v7 == 6 )
    {
      v8 = "HALT";
      goto LABEL_28;
    }
    goto LABEL_24;
  }
  if ( v7 )
  {
    if ( v7 == 1 )
    {
      v8 = "APPLIED";
      goto LABEL_28;
    }
    if ( v7 == 2 )
    {
      v8 = "EPOCH";
LABEL_28:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_context_deinit",
        10912,
        "ISP context Substate[%s] is invalid",
        v8);
      goto LABEL_29;
    }
LABEL_24:
    v8 = "INVALID";
    goto LABEL_28;
  }
LABEL_29:
  isp_ctx_debug = 0;
  memset(s, 0, 0xB2C8u);
  return 0;
}
