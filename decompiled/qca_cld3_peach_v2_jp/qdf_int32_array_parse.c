__int64 __fastcall qdf_int32_array_parse(_BYTE *a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v6; // x19
  __int64 v7; // x21
  __int64 v8; // x22
  _QWORD *v9; // x20
  unsigned __int8 *v10; // x0
  int v11; // w8
  int v12; // t1
  unsigned int v13; // w9
  int v14; // w9
  unsigned int v15; // w9
  __int64 v16; // x23
  int v17; // w11
  unsigned __int8 v18; // w10
  unsigned __int64 v19; // x10
  bool v20; // cf
  _BYTE *v21; // x0
  bool v22; // zf

  result = 4;
  if ( !a1 || !a2 || !a4 )
    return result;
  if ( !a3 )
    return 16;
  v6 = 0;
  while ( 2 )
  {
    v7 = a3;
    v8 = a2;
    v9 = a4;
    v10 = (unsigned __int8 *)skip_spaces(a1);
    v11 = *v10;
    if ( v11 == 45 || v11 == 43 )
    {
      v12 = *++v10;
      v13 = v12 - 48;
      if ( v12 == 48 )
        goto LABEL_9;
LABEL_14:
      if ( v13 > 9 )
        return 16;
LABEL_15:
      v15 = 10;
      goto LABEL_16;
    }
    v13 = v11 - 48;
    if ( v11 != 48 )
      goto LABEL_14;
LABEL_9:
    v14 = v10[1];
    if ( v14 == 120 )
    {
      v10 += 2;
      v15 = 16;
      goto LABEL_16;
    }
    if ( v14 == 111 )
    {
      v10 += 2;
      v15 = 8;
      goto LABEL_16;
    }
    if ( v14 != 98 )
      goto LABEL_15;
    v10 += 2;
    v15 = 2;
LABEL_16:
    v16 = 0;
    while ( 1 )
    {
      v17 = *v10;
      v18 = v17 - 48;
      if ( (unsigned int)(v17 - 48) < 0xA )
        goto LABEL_20;
      if ( (unsigned int)(v17 - 97) > 5 )
        break;
      v18 = v17 - 87;
LABEL_20:
      if ( v15 <= v18 )
        return 16;
LABEL_21:
      ++v10;
      v19 = v16 * v15 + v18;
      v20 = v19 >= v16;
      v16 = v19;
      if ( !v20 )
        return 46;
    }
    if ( (unsigned int)(v17 - 65) <= 5 )
    {
      v18 = v17 - 55;
      if ( v15 <= (unsigned __int8)(v17 - 55) )
        return 16;
      goto LABEL_21;
    }
    if ( v11 == 45 )
    {
      v16 = -v16;
      if ( v16 > 0 )
        return 46;
    }
    else if ( v16 < 0 )
    {
      return 46;
    }
    v21 = (_BYTE *)skip_spaces(v10);
    if ( *v21 == 44 )
    {
      a2 = v8;
      *(_DWORD *)(v8 + 4 * v6) = v16;
      a3 = v7;
      v22 = v6 + 1 == v7;
      a1 = v21 + 1;
      result = 16;
      ++v6;
      a4 = v9;
      if ( v22 )
        return result;
      continue;
    }
    break;
  }
  if ( !*v21 )
  {
    *(_DWORD *)(v8 + 4 * v6) = v16;
    *v9 = v6 + 1;
    return 0;
  }
  return 16;
}
