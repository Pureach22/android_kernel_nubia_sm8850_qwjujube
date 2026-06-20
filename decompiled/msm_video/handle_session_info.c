__int64 __fastcall handle_session_info(_DWORD *a1, __int64 a2)
{
  int v2; // w8
  unsigned int flag_info; // w20
  const char *v5; // x4
  _DWORD *v6; // x21
  _DWORD *v7; // x21

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 > 100663301 )
  {
    switch ( v2 )
    {
      case 100663302:
        v6 = a1;
        flag_info = handle_session_last_flag_info(a1, a2);
        a1 = v6;
        v5 = "drain last flag";
        if ( !v6 )
          return flag_info;
        goto LABEL_21;
      case 100663303:
        v7 = a1;
        flag_info = handle_session_last_flag_info(a1, a2);
        a1 = v7;
        v5 = "drc last flag";
        if ( !v7 )
          return flag_info;
        goto LABEL_21;
      case 100663304:
        flag_info = 0;
        v5 = "synx v2 fence error";
        a1[895] = 1;
        if ( !a1 )
          return flag_info;
        goto LABEL_21;
    }
    goto LABEL_16;
  }
  if ( v2 == 100663297 )
  {
    flag_info = 0;
    v5 = "unsupported";
    if ( !a1 )
      return flag_info;
    goto LABEL_21;
  }
  if ( v2 != 100663298 )
  {
    if ( v2 == 100663300 )
    {
      flag_info = 0;
      v5 = "buffer overflow";
      a1[894] = 1;
      if ( !a1 )
        return flag_info;
      goto LABEL_21;
    }
LABEL_16:
    flag_info = 0;
    v5 = "unknown";
    if ( !a1 )
      return flag_info;
    goto LABEL_21;
  }
  flag_info = 0;
  v5 = "data corrupt";
  a1[893] = 1;
  if ( !a1 )
    return flag_info;
LABEL_21:
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_8A232, "high", a1 + 85, *(unsigned int *)(a2 + 4), v5);
  return flag_info;
}
