__int64 __fastcall config_cpuss_register(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 a4,
        int a5,
        unsigned int a6)
{
  __int64 result; // x0
  int *v7; // x8
  int v8; // w9
  int v9; // w10
  _DWORD *v10; // x8
  int *v11; // x8

  if ( a4 <= 0x71u )
  {
    if ( a4 == 82 )
    {
      if ( !HIBYTE(a6) )
      {
        v7 = (int *)(a2 + 4LL * a3);
        result = 0;
        v8 = a5 | 3;
        v9 = a6 | 0x2000000;
        goto LABEL_13;
      }
      dev_err(a1, "repeat read time exceeded the limit\n");
      return 4294967274LL;
    }
    if ( a4 == 100 )
    {
      if ( !HIBYTE(a6) )
      {
        result = 0;
        v7 = (int *)(a2 + 4LL * a3);
        v8 = 3;
        v9 = a6 | 0x1000000;
LABEL_13:
        *v7 = v8;
        v7[1] = v9;
        return result;
      }
      dev_err(a1, "sleep time exceeded the limit\n");
      return 4294967274LL;
    }
LABEL_16:
    dev_err(a1, "Don't support this command\n");
    return 4294967274LL;
  }
  if ( a4 == 119 )
  {
    v11 = (int *)(a2 + 4LL * a3);
    *v11 = a5 | 2;
    v11[1] = a6;
    return 0;
  }
  if ( a4 != 114 )
    goto LABEL_16;
  if ( a6 < 5 )
  {
    *(_DWORD *)(a2 + 4LL * a3) = a5 | 1;
  }
  else
  {
    v10 = (_DWORD *)(a2 + 4LL * a3);
    *v10 = a5;
    v10[1] = a6;
  }
  return 0;
}
