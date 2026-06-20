__int64 __fastcall cam_ife_mgr_find_core_idx(__int64 a1, _DWORD *a2, int a3, _DWORD *a4)
{
  int v4; // w9
  __int64 v5; // x9
  _DWORD *v6; // x9
  _DWORD *v8; // [xsp+10h] [xbp-10h]
  _DWORD *v9; // [xsp+18h] [xbp-8h]

  v4 = a2[2179];
  if ( !v4 )
    goto LABEL_50;
  if ( a2[2148] != a3 || a2[2147] != (_DWORD)a1 )
  {
    if ( v4 != 1 )
    {
      if ( a2[2151] == a3 && a2[2150] == (_DWORD)a1 )
      {
        v5 = 2149;
        goto LABEL_45;
      }
      if ( v4 != 2 )
      {
        if ( a2[2154] == a3 && a2[2153] == (_DWORD)a1 )
        {
          v5 = 2152;
          goto LABEL_45;
        }
        if ( v4 != 3 )
        {
          if ( a2[2157] == a3 && a2[2156] == (_DWORD)a1 )
          {
            v5 = 2155;
            goto LABEL_45;
          }
          if ( v4 != 4 )
          {
            if ( a2[2160] == a3 && a2[2159] == (_DWORD)a1 )
            {
              v5 = 2158;
              goto LABEL_45;
            }
            if ( v4 != 5 )
            {
              if ( a2[2163] == a3 && a2[2162] == (_DWORD)a1 )
              {
                v5 = 2161;
                goto LABEL_45;
              }
              if ( v4 != 6 )
              {
                if ( a2[2166] == a3 && a2[2165] == (_DWORD)a1 )
                {
                  v5 = 2164;
                  goto LABEL_45;
                }
                if ( v4 != 7 )
                {
                  if ( a2[2169] == a3 && a2[2168] == (_DWORD)a1 )
                  {
                    v5 = 2167;
                    goto LABEL_45;
                  }
                  if ( v4 != 8 )
                  {
                    if ( a2[2172] == a3 && a2[2171] == (_DWORD)a1 )
                    {
                      v5 = 2170;
                      goto LABEL_45;
                    }
                    if ( v4 != 9 )
                    {
                      if ( a2[2175] == a3 && a2[2174] == (_DWORD)a1 )
                      {
                        v5 = 2173;
                        goto LABEL_45;
                      }
                      if ( v4 != 10 )
                      {
                        if ( a2[2178] == a3 && a2[2177] == (_DWORD)a1 )
                        {
                          v5 = 2176;
                          goto LABEL_45;
                        }
                        if ( v4 != 11 )
                        {
                          __break(0x5512u);
                          return cam_ife_hw_mgr_free_hw_res(a1, a2);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_50:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_find_core_idx",
      8854,
      "Failed to find core idx for hw_type: %d split_id %d ctx_idx: %u",
      a3,
      a1,
      a2[14]);
    return 4294967274LL;
  }
  v5 = 2146;
LABEL_45:
  v6 = &a2[v5];
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v9 = v6;
    v8 = a4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_find_core_idx",
      8847,
      "Found core: %u for split_id: %d hw_type: %d ctx_idx: %u",
      *v6,
      a1,
      a3,
      a2[14]);
    v6 = v9;
    a4 = v8;
  }
  *a4 = *v6;
  return 0;
}
