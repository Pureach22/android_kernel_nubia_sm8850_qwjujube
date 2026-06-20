__int64 __fastcall cam_cdm_util_validate_cmd_buf(_DWORD *a1, unsigned __int64 a2)
{
  unsigned int v2; // w19
  unsigned __int64 v3; // x8
  unsigned int v4; // w6
  int v5; // w9
  _DWORD *v6; // x10
  int v7; // w9
  _DWORD *v8; // x10

  if ( a1 && a2 )
  {
    while ( 1 )
    {
      v4 = HIBYTE(*a1);
      if ( v4 > 7 )
        break;
      if ( HIBYTE(*a1) <= 4u )
      {
        if ( v4 != 1 )
        {
          if ( v4 == 3 )
          {
            v3 = (unsigned __int64)(a1 + 2);
            v7 = *(unsigned __int16 *)a1;
            if ( *(_WORD *)a1 )
            {
              v8 = a1 + 1;
              v3 = (unsigned __int64)&a1[v7 - 1 + 3];
              while ( 1 )
              {
                if ( (unsigned __int64)++v8 > a2 )
                  return 1;
                if ( !--v7 )
                  goto LABEL_6;
              }
            }
            goto LABEL_6;
          }
          if ( v4 != 4 )
            goto LABEL_40;
          v5 = (unsigned __int16)*a1;
          if ( (unsigned __int16)*a1 )
          {
            v6 = a1 - 1;
            v3 = (unsigned __int64)&a1[2 * (v5 - 1) + 3];
            while ( 1 )
            {
              v6 += 2;
              if ( (unsigned __int64)v6 > a2 )
                return 1;
              if ( !--v5 )
                goto LABEL_6;
            }
          }
          goto LABEL_35;
        }
LABEL_4:
        if ( (unsigned __int64)a1 > a2 )
          return 1;
        goto LABEL_5;
      }
      if ( v4 == 5 )
      {
        v3 = (unsigned __int64)(a1 + 2);
        if ( (unsigned __int64)(a1 + 2) > a2 )
          return 1;
        goto LABEL_6;
      }
      if ( v4 == 6 )
      {
        v3 = (unsigned __int64)(a1 + 2);
        goto LABEL_6;
      }
      if ( v4 != 7 )
        goto LABEL_40;
LABEL_5:
      v3 = (unsigned __int64)(a1 + 3);
LABEL_6:
      a1 = (_DWORD *)v3;
      if ( v3 >= a2 )
        return 0;
    }
    if ( HIBYTE(*a1) <= 9u )
    {
      if ( v4 == 8 )
      {
        if ( (unsigned __int64)a1 > a2 )
          return 1;
      }
      else if ( v4 != 9 )
      {
LABEL_40:
        v2 = 1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_util_validate_cmd_buf",
          1104,
          "Invalid CMD: 0x%x buf 0x%x",
          v4,
          *a1);
        return v2;
      }
LABEL_35:
      v3 = (unsigned __int64)(a1 + 1);
      goto LABEL_6;
    }
    if ( v4 - 10 >= 2 )
    {
      if ( v4 != 12 )
        goto LABEL_40;
      goto LABEL_5;
    }
    goto LABEL_4;
  }
  v2 = 1;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    1,
    1,
    "cam_cdm_util_validate_cmd_buf",
    1041,
    "Invalid args");
  return v2;
}
