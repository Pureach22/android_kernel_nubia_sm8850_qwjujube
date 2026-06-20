__int64 __fastcall tsens_read_calibration(_QWORD *a1, char a2, __int64 a3, __int64 a4, char a5)
{
  unsigned int v5; // w8
  __int64 result; // x0
  const char *v8; // x20
  int v12; // w28
  __int64 v13; // x22
  _DWORD *v14; // x22
  int v15; // t1
  unsigned int v16; // w9
  int v17; // w10
  unsigned int j; // w11
  int v19; // w10
  unsigned int k; // w11
  unsigned int v21; // w11
  int v22; // w10
  unsigned int m; // w10
  unsigned int i; // w10
  unsigned int v25; // w9
  int v26; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v27; // [xsp+10h] [xbp-20h] BYREF
  char s[16]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *((_DWORD *)a1 + 2);
  strcpy(s, "sXX_pY_backup");
  if ( v5 > 0x10 )
  {
    result = 4294967274LL;
    goto LABEL_22;
  }
  if ( (a5 & 1) != 0 )
    v8 = "_backup";
  else
    v8 = (const char *)&unk_10983;
  v27 = 0;
  v26 = 0;
  result = snprintf(s, 0xEu, "mode%s", v8);
  if ( (result & 0x80000000) == 0 )
  {
    result = nvmem_cell_read_variable_le_u32(*a1, s, (char *)&v27 + 4);
    if ( (_DWORD)result == -2 )
    {
      dev_warn(*a1, "Please migrate to separate nvmem cells for calibration data\n");
      result = 4294967294LL;
      goto LABEL_22;
    }
    if ( (result & 0x80000000) == 0 )
    {
      result = snprintf(s, 0xEu, "base1%s", v8);
      if ( (result & 0x80000000) == 0 )
      {
        result = nvmem_cell_read_variable_le_u32(*a1, s, &v27);
        if ( (result & 0x80000000) == 0 )
        {
          result = snprintf(s, 0xEu, "base2%s", v8);
          if ( (result & 0x80000000) == 0 )
          {
            result = nvmem_cell_read_variable_le_u32(*a1, s, &v26);
            if ( (result & 0x80000000) == 0 )
            {
              if ( *((_DWORD *)a1 + 2) )
              {
                v12 = 0;
                while ( 1 )
                {
                  v13 = (__int64)&a1[11 * v12 + 325];
                  v15 = *(_DWORD *)(v13 + 68);
                  v14 = (_DWORD *)(v13 + 68);
                  result = snprintf(s, 0xEu, "s%d_p1%s", v15, v8);
                  if ( (result & 0x80000000) != 0 )
                    goto LABEL_22;
                  result = nvmem_cell_read_variable_le_u32(*a1, s, a3 + 4LL * v12);
                  if ( (_DWORD)result )
                    goto LABEL_22;
                  result = snprintf(s, 0xEu, "s%d_p2%s", *v14, v8);
                  if ( (result & 0x80000000) != 0 )
                    goto LABEL_22;
                  result = nvmem_cell_read_variable_le_u32(*a1, s, a4 + 4LL * v12);
                  if ( (_DWORD)result )
                    goto LABEL_22;
                  v16 = *((_DWORD *)a1 + 2);
                  if ( ++v12 >= v16 )
                    goto LABEL_24;
                }
              }
              v16 = 0;
LABEL_24:
              result = HIDWORD(v27);
              if ( SHIDWORD(v27) <= 2 )
              {
                if ( HIDWORD(v27) == 1 )
                {
                  if ( !v16 )
                  {
                    result = 1;
                    goto LABEL_22;
                  }
                  v21 = 0;
                  v22 = (_DWORD)v27 << a2;
                  do
                  {
                    *(_DWORD *)(a3 + 4LL * (int)v21++) += v22;
                    v16 = *((_DWORD *)a1 + 2);
                  }
                  while ( v21 < v16 );
                  goto LABEL_45;
                }
                if ( HIDWORD(v27) == 2 )
                  goto LABEL_34;
              }
              else
              {
                switch ( HIDWORD(v27) )
                {
                  case 3:
                    goto LABEL_28;
                  case 6:
                    goto LABEL_34;
                  case 7:
LABEL_28:
                    if ( !v16 )
                    {
LABEL_45:
                      if ( (_DWORD)result != 2 )
                      {
                        if ( (_DWORD)result != 3 )
                          goto LABEL_22;
                        if ( !v16 )
                        {
                          result = 3;
                          goto LABEL_22;
                        }
                        for ( i = 0; i < v16; ++i )
                        {
                          *(_DWORD *)(a4 + 4LL * (int)i) += HIDWORD(a1[11 * (int)i + 335]);
                          v16 = *((_DWORD *)a1 + 2);
                        }
                      }
                      if ( v16 )
                      {
                        v25 = 0;
                        do
                        {
                          *(_DWORD *)(a3 + 4LL * (int)v25) += LODWORD(a1[11 * (int)v25 + 335]);
                          ++v25;
                        }
                        while ( v25 < *((_DWORD *)a1 + 2) );
                      }
                      goto LABEL_22;
                    }
                    v17 = v26;
                    for ( j = 0; j < v16; ++j )
                    {
                      *(_DWORD *)(a4 + 4LL * (int)j) = (v17 + *(_DWORD *)(a4 + 4LL * (int)j)) << a2;
                      v16 = *((_DWORD *)a1 + 2);
                    }
LABEL_34:
                    if ( v16 )
                    {
                      v19 = v27;
                      for ( k = 0; k < v16; ++k )
                      {
                        *(_DWORD *)(a3 + 4LL * (int)k) = (v19 + *(_DWORD *)(a3 + 4LL * (int)k)) << a2;
                        v16 = *((_DWORD *)a1 + 2);
                      }
                    }
                    goto LABEL_45;
                }
              }
              if ( v16 )
              {
                for ( m = 0; m < v16; ++m )
                {
                  *(_DWORD *)(a3 + 4LL * (int)m) = 500;
                  *(_DWORD *)(a4 + 4LL * (int)m) = 780;
                  v16 = *((_DWORD *)a1 + 2);
                }
              }
              goto LABEL_45;
            }
          }
        }
      }
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
