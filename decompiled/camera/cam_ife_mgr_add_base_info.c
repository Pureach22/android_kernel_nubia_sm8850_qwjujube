_DWORD *__fastcall cam_ife_mgr_add_base_info(_DWORD *result, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w9
  _DWORD *v5; // x8
  int v6; // w11
  _DWORD *v7; // x10
  __int64 v8; // x10
  char v9; // w8
  __int64 v10; // x1
  const char *v11; // x5
  __int64 v12; // x4
  unsigned int v13; // w9
  unsigned int v14; // w9
  char v15; // w9

  v4 = result[2179];
  if ( v4 )
  {
    v5 = result + 2146;
    if ( result[2146] == (_DWORD)a3 && result[2148] == (_DWORD)a4 )
    {
      v6 = 0;
      v7 = result + 2146;
    }
    else
    {
      if ( v4 == 1 )
        goto LABEL_53;
      if ( result[2149] == (_DWORD)a3 && result[2151] == (_DWORD)a4 )
      {
        v8 = 2149;
        v6 = 1;
      }
      else
      {
        if ( v4 == 2 )
          goto LABEL_53;
        if ( result[2152] == (_DWORD)a3 && result[2154] == (_DWORD)a4 )
        {
          v8 = 2152;
          v6 = 2;
        }
        else
        {
          if ( v4 == 3 )
            goto LABEL_53;
          if ( result[2155] == (_DWORD)a3 && result[2157] == (_DWORD)a4 )
          {
            v8 = 2155;
            v6 = 3;
          }
          else
          {
            if ( v4 == 4 )
              goto LABEL_53;
            if ( result[2158] == (_DWORD)a3 && result[2160] == (_DWORD)a4 )
            {
              v8 = 2158;
              v6 = 4;
            }
            else
            {
              if ( v4 == 5 )
                goto LABEL_53;
              if ( result[2161] == (_DWORD)a3 && result[2163] == (_DWORD)a4 )
              {
                v8 = 2161;
                v6 = 5;
              }
              else
              {
                if ( v4 == 6 )
                  goto LABEL_53;
                if ( result[2164] == (_DWORD)a3 && result[2166] == (_DWORD)a4 )
                {
                  v8 = 2164;
                  v6 = 6;
                }
                else
                {
                  if ( v4 == 7 )
                    goto LABEL_53;
                  if ( result[2167] == (_DWORD)a3 && result[2169] == (_DWORD)a4 )
                  {
                    v8 = 2167;
                    v6 = 7;
                  }
                  else
                  {
                    if ( v4 == 8 )
                      goto LABEL_53;
                    if ( result[2170] == (_DWORD)a3 && result[2172] == (_DWORD)a4 )
                    {
                      v8 = 2170;
                      v6 = 8;
                    }
                    else
                    {
                      if ( v4 == 9 )
                        goto LABEL_53;
                      if ( result[2173] == (_DWORD)a3 && result[2175] == (_DWORD)a4 )
                      {
                        v8 = 2173;
                        v6 = 9;
                        a3 = (unsigned int)a3;
                      }
                      else
                      {
                        if ( v4 == 10 )
                        {
                          a3 = (unsigned int)a3;
                          goto LABEL_53;
                        }
                        if ( result[2176] != (_DWORD)a3 || result[2178] != (_DWORD)a4 )
                          goto LABEL_60;
                        v8 = 2176;
                        a3 = (unsigned int)a3;
                        v6 = 10;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      v7 = &result[v8];
    }
    if ( v7[1] == 2 )
    {
      v7[1] = a2;
      v4 = result[2179];
    }
    if ( v6 == v4 )
    {
LABEL_53:
      v5[3 * v4 + 1] = a2;
      v13 = result[2179];
      if ( v13 <= 0xA )
      {
        v5[3 * v13] = a3;
        v14 = result[2179];
        if ( v14 <= 0xA )
        {
          v5[3 * v14 + 2] = a4;
          v15 = debug_mdl;
          ++result[2179];
          if ( (v15 & 8) == 0 || debug_priority )
            return result;
          v11 = "Add split_id=%d ctx_idx: %u for base idx=%d num_base=%d hw_type=%d";
          v10 = v15 & 8;
          v12 = 2660;
          return (_DWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                             3,
                             v10,
                             4,
                             "cam_ife_mgr_add_base_info",
                             v12,
                             v11);
        }
      }
LABEL_60:
      __break(0x5512u);
      return (_DWORD *)cam_ife_mgr_find_core_idx(result, a2, a3, a4);
    }
  }
  else
  {
    result[2147] = a2;
    v9 = debug_mdl;
    result[2146] = a3;
    result[2148] = a4;
    result[2179] = 1;
    if ( (v9 & 8) != 0 && !debug_priority )
    {
      v10 = v9 & 8;
      v11 = "Add split id = %d ctx_idx: %u for base idx = %d num_base=%d hw_type=%d";
      v12 = 2638;
      return (_DWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                         3,
                         v10,
                         4,
                         "cam_ife_mgr_add_base_info",
                         v12,
                         v11);
    }
  }
  return result;
}
