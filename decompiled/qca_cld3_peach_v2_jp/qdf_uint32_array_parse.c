__int64 __fastcall qdf_uint32_array_parse(_BYTE *a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  unsigned int v4; // w8
  __int64 v8; // x22
  unsigned __int8 *v9; // x0
  int v10; // w8
  int v11; // t1
  unsigned int v12; // w9
  int v13; // w9
  unsigned int v14; // w9
  unsigned __int64 v15; // x23
  int v16; // w11
  unsigned __int8 v17; // w10
  unsigned __int64 v18; // x10
  bool v19; // cf
  bool v20; // zf
  _BYTE *v21; // x0

  v4 = 4;
  if ( !a1 || !a2 || !a4 )
    return v4;
  if ( !a3 )
    return 16;
  v8 = 0;
  while ( 2 )
  {
    v9 = (unsigned __int8 *)skip_spaces(a1);
    v10 = *v9;
    if ( v10 == 45 || v10 == 43 )
    {
      v11 = *++v9;
      v12 = v11 - 48;
      if ( v11 == 48 )
        goto LABEL_9;
LABEL_14:
      if ( v12 > 9 )
        return 16;
LABEL_15:
      v14 = 10;
      goto LABEL_16;
    }
    v12 = v10 - 48;
    if ( v10 != 48 )
      goto LABEL_14;
LABEL_9:
    v13 = v9[1];
    if ( v13 == 120 )
    {
      v9 += 2;
      v14 = 16;
      goto LABEL_16;
    }
    if ( v13 == 111 )
    {
      v9 += 2;
      v14 = 8;
      goto LABEL_16;
    }
    if ( v13 != 98 )
      goto LABEL_15;
    v9 += 2;
    v14 = 2;
LABEL_16:
    v15 = 0;
    while ( 1 )
    {
      v16 = *v9;
      v17 = v16 - 48;
      if ( (unsigned int)(v16 - 48) < 0xA )
        goto LABEL_20;
      if ( (unsigned int)(v16 - 97) > 5 )
        break;
      v17 = v16 - 87;
LABEL_20:
      if ( v14 <= v17 )
        return 16;
LABEL_21:
      ++v9;
      v18 = v15 * v14 + v17;
      v19 = v18 >= v15;
      v15 = v18;
      if ( !v19 )
        return 46;
    }
    if ( (unsigned int)(v16 - 65) <= 5 )
    {
      v17 = v16 - 55;
      if ( v14 <= (unsigned __int8)(v16 - 55) )
        return 16;
      goto LABEL_21;
    }
    v20 = v10 == 45;
    v4 = 46;
    if ( v20 || HIDWORD(v15) )
      return v4;
    v21 = (_BYTE *)skip_spaces(v9);
    v4 = (unsigned __int8)*v21;
    if ( v4 != 44 )
    {
      if ( !*v21 )
      {
        *(_DWORD *)(a2 + 4 * v8) = v15;
        *a4 = v8 + 1;
        return v4;
      }
      return 16;
    }
    *(_DWORD *)(a2 + 4 * v8) = v15;
    a1 = v21 + 1;
    v20 = v8 + 1 == a3;
    v4 = 16;
    ++v8;
    if ( !v20 )
      continue;
    return v4;
  }
}
