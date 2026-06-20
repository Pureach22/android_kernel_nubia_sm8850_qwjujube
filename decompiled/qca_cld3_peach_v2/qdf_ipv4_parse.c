__int64 __fastcall qdf_ipv4_parse(__int64 a1, unsigned int *a2)
{
  __int64 result; // x0
  unsigned __int8 *v5; // x0
  unsigned int v6; // w20
  unsigned __int8 *v7; // x8
  int v8; // w9
  char v9; // w10
  unsigned int v10; // w21
  unsigned __int8 *v11; // x9
  int v12; // w10
  char v13; // w11
  unsigned int v14; // w22
  unsigned __int8 *v15; // x8
  int v16; // w10
  char v17; // w11
  unsigned int v18; // w23
  unsigned __int8 *v19; // x0
  unsigned int v20; // w9
  unsigned int v21; // w9

  result = 4;
  if ( a1 && a2 )
  {
    v5 = (unsigned __int8 *)skip_spaces(a1);
    v6 = *v5 - 48;
    if ( v6 <= 9 )
    {
      v7 = v5 + 1;
      v8 = v5[1];
      v9 = v8 - 48;
      if ( (unsigned int)(v8 - 48) <= 9 )
      {
        v7 = v5 + 2;
        v8 = v5[2];
        LOBYTE(v6) = v9 + 10 * v6;
        if ( (unsigned int)(v8 - 48) <= 9 )
        {
          v6 = 10 * (unsigned __int8)v6 + (unsigned __int8)(v8 - 48);
          if ( v6 > 0xFF )
            return 16;
          v8 = v5[3];
          v7 = v5 + 3;
        }
      }
      if ( v8 != 46 )
        return 16;
      v10 = v7[1] - 48;
      if ( v10 > 9 )
        return 16;
      v11 = v7 + 2;
      v12 = v7[2];
      v13 = v12 - 48;
      if ( (unsigned int)(v12 - 48) <= 9 )
      {
        v11 = v7 + 3;
        v12 = v7[3];
        LOBYTE(v10) = v13 + 10 * v10;
        if ( (unsigned int)(v12 - 48) <= 9 )
        {
          v10 = 10 * (unsigned __int8)v10 + (unsigned __int8)(v12 - 48);
          if ( v10 > 0xFF )
            return 16;
          v12 = v7[4];
          v11 = v7 + 4;
        }
      }
      if ( v12 != 46 )
        return 16;
      v14 = v11[1] - 48;
      if ( v14 > 9 )
        return 16;
      v15 = v11 + 2;
      v16 = v11[2];
      v17 = v16 - 48;
      if ( (unsigned int)(v16 - 48) <= 9 )
      {
        v15 = v11 + 3;
        v16 = v11[3];
        LOBYTE(v14) = v17 + 10 * v14;
        if ( (unsigned int)(v16 - 48) <= 9 )
        {
          v14 = 10 * (unsigned __int8)v14 + (unsigned __int8)(v16 - 48);
          if ( v14 > 0xFF )
            return 16;
          v16 = v11[4];
          v15 = v11 + 4;
        }
      }
      if ( v16 == 46 )
      {
        v18 = v15[1] - 48;
        if ( v18 <= 9 )
        {
          v19 = v15 + 2;
          v20 = v15[2] - 48;
          if ( v20 > 9 || (v19 = v15 + 3, v18 = v20 + 10 * v18, v21 = v15[3] - 48, v21 > 9) )
          {
LABEL_26:
            if ( !*(_BYTE *)skip_spaces(v19) )
            {
              *a2 = ((unsigned __int8)v14 << 16) | (v18 << 24) | ((unsigned __int8)v10 << 8) | (unsigned __int8)v6;
              return 0;
            }
            return 16;
          }
          v18 = 10 * (unsigned __int8)v18 + (unsigned __int8)v21;
          if ( v18 <= 0xFF )
          {
            v19 = v15 + 4;
            goto LABEL_26;
          }
        }
      }
    }
    return 16;
  }
  return result;
}
