__int64 __fastcall read_fw2_block_header(_QWORD *a1, unsigned int *a2, unsigned int a3, int a4, unsigned int a5)
{
  unsigned __int64 v5; // x20
  unsigned int v6; // w8
  unsigned int v8; // w8
  unsigned __int64 v9; // x21
  _QWORD *v10; // x22
  unsigned int *v11; // x23
  unsigned int v12; // w24
  unsigned int v13; // w2
  unsigned int v14; // w3

  if ( !a2 )
    return 4294967284LL;
  v5 = *a2;
  v6 = -22;
  if ( (unsigned int)v5 <= 0xA && (unsigned int)v5 < a3 && (_DWORD)v5 && (v5 & 1) == 0 )
  {
    if ( a4 == 3 )
    {
      if ( a2[1] != 5 || a2[2] > 2 )
        return (unsigned int)-22;
      v8 = 3;
      if ( (unsigned int)v5 <= 3 )
        return 0;
    }
    else
    {
      v8 = 1;
      if ( (unsigned int)v5 <= 1 )
        return 0;
    }
    v9 = v8;
    while ( 1 )
    {
      v13 = a2[v9];
      if ( v13 - 2 >= 3 )
      {
        if ( v13 == 1 )
        {
          v14 = a2[v9 + 1];
          if ( v14 < a5 && v14 )
          {
            dev_err(*a1, "GPMU major version mis-match %d, %d\n", a5, v14);
            return (unsigned int)-22;
          }
        }
        else
        {
          v10 = a1;
          v11 = a2;
          v12 = a5;
          dev_err(*a1, "GPMU unknown header ID %d\n", v13);
          a2 = v11;
          a1 = v10;
          a5 = v12;
        }
      }
      v9 += 2LL;
      if ( v9 >= v5 )
        return 0;
    }
  }
  return v6;
}
