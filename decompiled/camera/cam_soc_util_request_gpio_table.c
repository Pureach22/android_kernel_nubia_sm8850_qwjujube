__int64 __fastcall cam_soc_util_request_gpio_table(__int64 a1, int a2)
{
  __int64 v2; // x8
  unsigned int v3; // w20
  _DWORD *v4; // x20
  __int64 v5; // x19
  __int64 v6; // x21
  int v7; // w8
  int v8; // w9
  _QWORD *v9; // x26
  int v10; // w27
  const char **v11; // x23
  unsigned int v12; // t1

  v2 = *(_QWORD *)(a1 + 3208);
  if ( v2 )
  {
    if ( *(_BYTE *)(v2 + 8) )
    {
      if ( *(_BYTE *)(v2 + 25) == 1 )
      {
        v3 = 0;
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20000,
            4,
            "cam_soc_util_request_gpio_table",
            3423,
            "dev name %s does not have valid request gpio table",
            *(const char **)(a1 + 24));
          return 0;
        }
      }
      else
      {
        v4 = *(_DWORD **)(v2 + 16);
        v5 = *(unsigned __int8 *)(v2 + 24);
        if ( v4 && *(_BYTE *)(v2 + 24) )
        {
          v6 = 0;
          v7 = debug_mdl;
          v8 = debug_priority;
          v9 = v4 + 2;
          do
          {
            if ( (v7 & 0x20000) != 0 && !v8 )
            {
              v10 = a2;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                *(_QWORD *)&v7 & 0x20000LL,
                4,
                "cam_soc_util_request_gpio_table",
                3434,
                "i=%d, gpio=%d dir=%ld",
                v6,
                *((_DWORD *)v9 - 2),
                *v9);
              v7 = debug_mdl;
              v8 = debug_priority;
              a2 = v10;
            }
            ++v6;
            v9 += 3;
          }
          while ( v5 != v6 );
          if ( (a2 & 1) == 0 )
          {
            do
            {
              v12 = *v4;
              v4 += 6;
              gpio_free(v12);
              --v5;
            }
            while ( v5 );
            return 0;
          }
          v11 = (const char **)(v4 + 4);
          do
          {
            v3 = gpio_request_one(*((unsigned int *)v11 - 4), *(v11 - 1), *v11);
            if ( v3 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x20000,
                1,
                "cam_soc_util_request_gpio_table",
                3447,
                "gpio %d:%s request fails",
                *((_DWORD *)v11 - 4),
                *v11);
            --v5;
            v11 += 3;
          }
          while ( v5 );
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x20000,
            1,
            "cam_soc_util_request_gpio_table",
            3429,
            "Invalid gpio_tbl %pK / size %d",
            *(const void **)(v2 + 16),
            v5);
          return (unsigned int)-22;
        }
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_request_gpio_table",
        3415,
        "GPIO table size is invalid");
      return (unsigned int)-22;
    }
  }
  else
  {
    v3 = 0;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_request_gpio_table",
        3411,
        "No GPIO entry");
      return 0;
    }
  }
  return v3;
}
