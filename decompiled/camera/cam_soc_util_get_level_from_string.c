__int64 __fastcall cam_soc_util_get_level_from_string(const char *a1, int *a2)
{
  __int64 result; // x0
  int v5; // w8

  if ( !a2 )
    return 4294967274LL;
  result = strcmp(a1, "suspend");
  if ( (_DWORD)result )
  {
    result = strcmp(a1, "minsvs");
    if ( (_DWORD)result )
    {
      result = strcmp(a1, "lowsvsd2");
      if ( (_DWORD)result )
      {
        result = strcmp(a1, "lowsvsd1");
        if ( (_DWORD)result )
        {
          result = strcmp(a1, "lowsvs");
          if ( (_DWORD)result )
          {
            result = strcmp(a1, "svs");
            if ( (_DWORD)result )
            {
              result = strcmp(a1, "svs_l1");
              if ( (_DWORD)result )
              {
                result = strcmp(a1, "nominal");
                if ( (_DWORD)result )
                {
                  result = strcmp(a1, "nominal_l1");
                  if ( (_DWORD)result )
                  {
                    result = strcmp(a1, "turbo");
                    if ( (_DWORD)result )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        0x20000,
                        1,
                        "cam_soc_util_get_level_from_string",
                        1889,
                        "Invalid string %s",
                        a1);
                      return 4294967274LL;
                    }
                    v5 = 9;
                  }
                  else
                  {
                    v5 = 8;
                  }
                }
                else
                {
                  v5 = 7;
                }
              }
              else
              {
                v5 = 6;
              }
            }
            else
            {
              v5 = 5;
            }
          }
          else
          {
            v5 = 4;
          }
        }
        else
        {
          v5 = 3;
        }
      }
      else
      {
        v5 = 2;
      }
    }
    else
    {
      v5 = 1;
    }
    *a2 = v5;
  }
  else
  {
    *a2 = 0;
  }
  return result;
}
