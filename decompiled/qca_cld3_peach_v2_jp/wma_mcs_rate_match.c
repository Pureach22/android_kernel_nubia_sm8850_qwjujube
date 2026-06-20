__int64 __fastcall wma_mcs_rate_match(
        __int64 result,
        char a2,
        unsigned __int16 *a3,
        unsigned __int16 *a4,
        _BYTE *a5,
        int *a6)
{
  int v6; // w8
  __int64 v7; // x9
  int v8; // w10
  int v9; // w9
  int v10; // w8

  result = (unsigned __int16)result;
  if ( *a3 == (unsigned __int16)result )
  {
    v6 = 0;
    v7 = 0;
LABEL_8:
    *a5 = 1;
    result = a3[v7];
    goto LABEL_9;
  }
  if ( *a5 == 2 && *a4 == (unsigned __int16)result )
  {
    v6 = 0;
    goto LABEL_9;
  }
  if ( a3[1] == (unsigned __int16)result )
  {
    v6 = 1;
    v7 = 1;
    goto LABEL_8;
  }
  if ( *a5 == 2 && a4[1] == (unsigned __int16)result )
  {
    v6 = 1;
  }
  else
  {
    if ( (a2 & 1) == 0 )
      return 0;
    if ( a3[2] == (unsigned __int16)result )
    {
      v7 = 2;
      v6 = 2;
      goto LABEL_8;
    }
    if ( *a5 != 2 || a4[2] != (unsigned __int16)result )
      return 0;
    v6 = 2;
  }
LABEL_9:
  if ( (_DWORD)result )
  {
    if ( (a2 & 1) != 0 )
      v8 = 2;
    else
      v8 = 1;
    if ( (a2 & 1 & (v6 == 2)) != 0 )
      v9 = 3;
    else
      v9 = 0;
    if ( v6 == 1 )
      v10 = v8;
    else
      v10 = v9;
    *a6 = v10;
  }
  return result;
}
