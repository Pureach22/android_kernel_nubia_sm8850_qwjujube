__int64 __fastcall hdd_get_rate_flags(
        unsigned int a1,
        char a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        int *a5,
        unsigned __int64 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned __int16 *v14; // x11
  char *v15; // x8
  void *v16; // x9
  int v17; // w10
  unsigned __int16 *v18; // x8
  __int64 result; // x0
  const char *v20; // x3
  char *v21; // x9
  unsigned __int16 *v22; // x8
  int v23; // w8
  const char *v24; // x8
  __int64 v25; // x4
  const char *v26; // x3
  int v27; // w8
  int v28; // w8
  int v29; // w8
  int v30; // w8

  switch ( a2 )
  {
    case 4:
      if ( a4 < 0xEu )
      {
        v14 = (unsigned __int16 *)&supported_he_mcs_rate_nss2_0;
        v17 = a4;
        if ( a3 == 1 )
          v14 = (unsigned __int16 *)&supported_he_mcs_rate_nss1_0;
        if ( v14[25 * a4 + 19] == a1 )
        {
          *a5 = 0;
          return 2048;
        }
        if ( v14[25 * a4 + 20] == a1 )
        {
          v23 = 2;
        }
        else
        {
          if ( v14[25 * a4 + 21] != a1 )
          {
            if ( v14[25 * a4 + 13] == a1 )
            {
              *a5 = 0;
              return 1024;
            }
            if ( v14[25 * a4 + 14] == a1 )
            {
              v27 = 2;
            }
            else
            {
              if ( v14[25 * a4 + 15] != a1 )
              {
                if ( v14[25 * a4 + 7] == a1 )
                {
                  *a5 = 0;
                  return 512;
                }
                if ( v14[25 * a4 + 8] == a1 )
                {
                  v28 = 2;
                }
                else
                {
                  if ( v14[25 * a4 + 9] != a1 )
                  {
                    if ( v14[25 * a4 + 1] == a1 )
                    {
                      *a5 = 0;
                      return 256;
                    }
                    if ( v14[25 * a4 + 2] == a1 )
                    {
                      v29 = 2;
                    }
                    else
                    {
                      if ( v14[25 * a4 + 3] != a1 )
                      {
                        LODWORD(v16) = a1;
                        if ( (a4 > 4u) | (4u >> a4) & 1 )
                          goto LABEL_71;
                        if ( v14[25 * a4 + 22] == a1 )
                        {
                          v30 = 0;
                          result = 2048;
                        }
                        else
                        {
                          if ( v14[25 * a4 + 23] != a1 )
                          {
                            if ( v14[25 * a4 + 24] == a1 )
                            {
                              result = 2048;
                            }
                            else
                            {
                              if ( v14[25 * a4 + 16] == a1 )
                              {
                                v30 = 0;
                                result = 1024;
                                goto LABEL_83;
                              }
                              if ( v14[25 * a4 + 17] == a1 )
                              {
                                result = 1024;
                                v30 = 2;
                                goto LABEL_83;
                              }
                              if ( v14[25 * a4 + 18] != a1 )
                              {
                                if ( v14[25 * a4 + 10] == a1 )
                                {
                                  v30 = 0;
                                  result = 512;
                                  goto LABEL_83;
                                }
                                goto LABEL_89;
                              }
                              result = 1024;
                            }
LABEL_78:
                            v30 = 3;
                            goto LABEL_83;
                          }
                          result = 2048;
                          v30 = 2;
                        }
LABEL_83:
                        *a5 = v30;
                        *(_BYTE *)a6 = 1;
                        return result;
                      }
                      v29 = 3;
                    }
                    *a5 = v29;
                    return 256;
                  }
                  v28 = 3;
                }
                *a5 = v28;
                return 512;
              }
              v27 = 3;
            }
            *a5 = v27;
            return 1024;
          }
          v23 = 3;
        }
        *a5 = v23;
        return 2048;
      }
      v20 = "hdd_get_rate_flags_he";
      goto LABEL_13;
    case 3:
      if ( a4 < 0xCu )
      {
        v21 = (char *)&supported_vht_mcs_rate_nss2_0;
        if ( a3 == 1 )
          v21 = (char *)&supported_vht_mcs_rate_nss1_0;
        v22 = (unsigned __int16 *)&v21[14 * a4];
        if ( v22[1] == a1 )
          return 128;
        if ( v22[2] == a1 )
          return 136;
        if ( v22[3] == a1 )
          return 64;
        if ( v22[4] == a1 )
          return 72;
        if ( v22[5] == a1 )
          return 32;
        if ( v22[6] == a1 )
          return 40;
        v24 = "hdd_get_rate_flags_vht";
        goto LABEL_44;
      }
      v20 = "hdd_get_rate_flags_vht";
LABEL_13:
      qdf_trace_msg(0x33u, 2u, "%s: Invalid mcs index %d", a7, a8, a9, a10, a11, a12, a13, a14, v20);
      return 0;
    case 2:
      a6 = a3;
      v15 = (char *)&supported_mcs_rate_nss2_0;
      v16 = &supported_mcs_rate_nss1_0;
      v17 = a4;
      if ( a3 == 1 )
        v15 = (char *)&supported_mcs_rate_nss1_0;
      if ( a4 <= 7u )
      {
        v18 = (unsigned __int16 *)&v15[10 * a4];
        if ( v18[1] == a1 )
          return 2;
        if ( v18[2] == a1 )
          return 4;
        if ( v18[3] == a1 )
          return 10;
        if ( v18[4] == a1 )
          return 12;
        v24 = "hdd_get_rate_flags_ht";
LABEL_44:
        v25 = a1;
        v26 = v24;
LABEL_45:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: invalid params rate %d nss %d mcs %d",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          v26,
          v25);
        return 0;
      }
      __break(1u);
LABEL_89:
      if ( v14[25 * v17 + 11] == (_DWORD)v16 )
      {
        result = 512;
        v30 = 2;
        goto LABEL_83;
      }
      if ( v14[25 * v17 + 12] == (_DWORD)v16 )
      {
        result = 512;
        goto LABEL_78;
      }
      if ( v14[25 * v17 + 4] == (_DWORD)v16 )
      {
        v30 = 0;
        result = 256;
        goto LABEL_83;
      }
      if ( v14[25 * v17 + 5] == (_DWORD)v16 )
      {
        result = 256;
        v30 = 2;
        goto LABEL_83;
      }
      if ( v14[25 * v17 + 6] == (_DWORD)v16 )
      {
        result = 256;
        goto LABEL_78;
      }
LABEL_71:
      v26 = "hdd_get_rate_flags_he";
      v25 = (unsigned int)v16;
      goto LABEL_45;
  }
  return 0;
}
