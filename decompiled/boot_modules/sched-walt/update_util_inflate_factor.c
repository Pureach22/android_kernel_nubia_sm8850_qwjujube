int *__fastcall update_util_inflate_factor(int *result, _DWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x10
  __int64 v4; // x8
  unsigned __int64 v5; // x11
  unsigned __int64 v6; // x10
  unsigned __int64 v7; // x9
  __int64 v8; // x11
  __int64 v9; // x11
  __int64 v10; // x11
  __int64 v11; // x11
  __int64 v12; // x11
  __int64 v13; // x11
  __int64 v14; // x11
  __int64 v15; // x11
  __int64 v16; // x11

  v2 = *(unsigned int *)(*(_QWORD *)a2 + 28LL);
  if ( (unsigned int)v2 >= 0x20 )
  {
    __break(0x5512u);
    return (int *)set_default_zone_util_pct_values();
  }
  else
  {
    v3 = result[56];
    if ( (_DWORD)v3 != -1 )
    {
      v4 = *(_QWORD *)((char *)&cpu_scale + *((_QWORD *)&_per_cpu_offset + v2));
      v5 = v4 * v3;
      v6 = *(unsigned int *)(*(_QWORD *)a2 + 40LL);
      v7 = 100LL * (unsigned int)v6;
      a2[18] = v5 / v6;
      a2[19] = v7 / result[57];
      v8 = result[58];
      if ( (_DWORD)v8 != -1 )
      {
        a2[20] = v4 * v8 / v6;
        a2[21] = v7 / result[59];
        v9 = result[60];
        if ( (_DWORD)v9 != -1 )
        {
          a2[22] = v4 * v9 / v6;
          a2[23] = v7 / result[61];
          v10 = result[62];
          if ( (_DWORD)v10 != -1 )
          {
            a2[24] = v4 * v10 / v6;
            a2[25] = v7 / result[63];
            v11 = result[64];
            if ( (_DWORD)v11 != -1 )
            {
              a2[26] = v4 * v11 / v6;
              a2[27] = v7 / result[65];
              v12 = result[66];
              if ( (_DWORD)v12 != -1 )
              {
                a2[28] = v4 * v12 / v6;
                a2[29] = v7 / result[67];
                v13 = result[68];
                if ( (_DWORD)v13 != -1 )
                {
                  a2[30] = v4 * v13 / v6;
                  a2[31] = v7 / result[69];
                  v14 = result[70];
                  if ( (_DWORD)v14 != -1 )
                  {
                    a2[32] = v4 * v14 / v6;
                    a2[33] = v7 / result[71];
                    v15 = result[72];
                    if ( (_DWORD)v15 != -1 )
                    {
                      a2[34] = v4 * v15 / v6;
                      a2[35] = v7 / result[73];
                      v16 = result[74];
                      if ( (_DWORD)v16 != -1 )
                      {
                        a2[36] = v4 * v16 / v6;
                        a2[37] = v7 / result[75];
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
  return result;
}
