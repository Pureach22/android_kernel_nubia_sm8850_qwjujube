__int64 __fastcall qdf_mac_parse(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0
  unsigned __int8 *v4; // x0
  int v5; // w8
  char v6; // w20
  int v7; // w8
  char v8; // w21
  int v9; // w8
  unsigned __int8 *v10; // x9
  int v11; // w10
  char v12; // w22
  int v13; // w10
  char v14; // w23
  unsigned __int8 *v15; // x10
  int v16; // w9
  char v17; // w24
  int v18; // w9
  char v19; // w25
  unsigned __int8 *v20; // x9
  int v21; // w10
  char v22; // w26
  int v23; // w10
  char v24; // w27
  unsigned __int8 *v25; // x10
  int v26; // w9
  char v27; // w12
  int v28; // w9
  char v29; // w11
  bool v30; // zf
  unsigned __int8 *v31; // x8
  int v32; // w9
  char v33; // w28
  int v34; // w9
  char v35; // w19
  char v36; // [xsp+0h] [xbp-10h]
  char v37; // [xsp+4h] [xbp-Ch]

  result = 4;
  if ( a1 && a2 )
  {
    v4 = (unsigned __int8 *)skip_spaces(a1);
    v5 = *v4;
    v6 = v5 - 48;
    if ( (unsigned int)(v5 - 48) >= 0xA )
    {
      if ( (unsigned int)(v5 - 97) > 5 )
      {
        if ( (unsigned int)(v5 - 65) > 5 )
          return 16;
        v6 = v5 - 55;
      }
      else
      {
        v6 = v5 - 87;
      }
    }
    v7 = v4[1];
    v8 = v7 - 48;
    if ( (unsigned int)(v7 - 48) >= 0xA )
    {
      if ( (unsigned int)(v7 - 97) > 5 )
      {
        if ( (unsigned int)(v7 - 65) > 5 )
          return 16;
        v8 = v7 - 55;
      }
      else
      {
        v8 = v7 - 87;
      }
    }
    v10 = v4 + 2;
    v9 = v4[2];
    if ( v9 == 58 )
    {
      v11 = v4[3];
      v10 = v4 + 3;
    }
    else
    {
      v11 = v4[2];
    }
    v12 = v11 - 48;
    if ( (unsigned int)(v11 - 48) >= 0xA )
    {
      if ( (unsigned int)(v11 - 97) > 5 )
      {
        if ( (unsigned int)(v11 - 65) > 5 )
          return 16;
        v12 = v11 - 55;
      }
      else
      {
        v12 = v11 - 87;
      }
    }
    v13 = v10[1];
    v14 = v13 - 48;
    if ( (unsigned int)(v13 - 48) >= 0xA )
    {
      if ( (unsigned int)(v13 - 97) > 5 )
      {
        if ( (unsigned int)(v13 - 65) > 5 )
          return 16;
        v14 = v13 - 55;
      }
      else
      {
        v14 = v13 - 87;
      }
    }
    v15 = v10 + 2;
    if ( v9 == 58 )
    {
      if ( *v15 != 58 )
        return 16;
      v15 = v10 + 3;
    }
    v16 = *v15;
    v17 = v16 - 48;
    if ( (unsigned int)(v16 - 48) >= 0xA )
    {
      if ( (unsigned int)(v16 - 97) >= 6 )
      {
        if ( (unsigned int)(v16 - 65) > 5 )
          return 16;
        v17 = v16 - 55;
      }
      else
      {
        v17 = v16 - 87;
      }
    }
    v18 = v15[1];
    v19 = v18 - 48;
    if ( (unsigned int)(v18 - 48) >= 0xA )
    {
      if ( (unsigned int)(v18 - 97) >= 6 )
      {
        if ( (unsigned int)(v18 - 65) > 5 )
          return 16;
        v19 = v18 - 55;
      }
      else
      {
        v19 = v18 - 87;
      }
    }
    v20 = v15 + 2;
    if ( v9 == 58 )
    {
      if ( *v20 != 58 )
        return 16;
      v20 = v15 + 3;
    }
    v21 = *v20;
    v22 = v21 - 48;
    if ( (unsigned int)(v21 - 48) >= 0xA )
    {
      if ( (unsigned int)(v21 - 97) >= 6 )
      {
        if ( (unsigned int)(v21 - 65) > 5 )
          return 16;
        v22 = v21 - 55;
      }
      else
      {
        v22 = v21 - 87;
      }
    }
    v23 = v20[1];
    v24 = v23 - 48;
    if ( (unsigned int)(v23 - 48) >= 0xA )
    {
      if ( (unsigned int)(v23 - 97) >= 6 )
      {
        if ( (unsigned int)(v23 - 65) > 5 )
          return 16;
        v24 = v23 - 55;
      }
      else
      {
        v24 = v23 - 87;
      }
    }
    v25 = v20 + 2;
    if ( v9 == 58 )
    {
      if ( *v25 != 58 )
        return 16;
      v25 = v20 + 3;
    }
    v26 = *v25;
    v27 = v26 - 48;
    if ( (unsigned int)(v26 - 48) >= 0xA )
    {
      if ( (unsigned int)(v26 - 97) >= 6 )
      {
        if ( (unsigned int)(v26 - 65) > 5 )
          return 16;
        v27 = v26 - 55;
      }
      else
      {
        v27 = v26 - 87;
      }
    }
    v28 = v25[1];
    v29 = v28 - 48;
    if ( (unsigned int)(v28 - 48) >= 0xA )
    {
      if ( (unsigned int)(v28 - 97) >= 6 )
      {
        if ( (unsigned int)(v28 - 65) > 5 )
          return 16;
        v29 = v28 - 55;
      }
      else
      {
        v29 = v28 - 87;
      }
    }
    v30 = v9 == 58;
    v31 = v25 + 2;
    if ( v30 )
    {
      if ( *v31 != 58 )
        return 16;
      v31 = v25 + 3;
    }
    v32 = *v31;
    v33 = v32 - 48;
    if ( (unsigned int)(v32 - 48) >= 0xA )
    {
      if ( (unsigned int)(v32 - 97) >= 6 )
      {
        if ( (unsigned int)(v32 - 65) > 5 )
          return 16;
        v33 = v32 - 55;
      }
      else
      {
        v33 = v32 - 87;
      }
    }
    v34 = v31[1];
    v35 = v34 - 48;
    if ( (unsigned int)(v34 - 48) < 0xA )
      goto LABEL_79;
    if ( (unsigned int)(v34 - 97) < 6 )
    {
      v35 = v34 - 87;
      goto LABEL_79;
    }
    if ( (unsigned int)(v34 - 65) <= 5 )
    {
      v35 = v34 - 55;
LABEL_79:
      v36 = v29;
      v37 = v27;
      if ( !*(_BYTE *)skip_spaces(v31 + 2) )
      {
        a2[1] = v14 | (16 * v12);
        *a2 = v8 | (16 * v6);
        a2[2] = v19 | (16 * v17);
        a2[3] = v24 | (16 * v22);
        a2[5] = v35 | (16 * v33);
        a2[4] = v36 | (16 * v37);
        return 0;
      }
    }
    return 16;
  }
  return result;
}
