__int64 __fastcall qdf_uint64_parse(__int64 a1, unsigned __int64 *a2)
{
  unsigned __int8 *v3; // x0
  int v4; // w20
  int v5; // t1
  unsigned int v6; // w8
  int v7; // w8
  unsigned int v8; // w8
  __int64 result; // x0
  unsigned __int64 v10; // x21
  int v11; // w10
  unsigned __int8 v12; // w9
  unsigned __int64 v13; // x9
  bool v14; // cf
  _BYTE *v15; // x0
  int v16; // w8

  if ( !a1 )
    return 4;
  v3 = (unsigned __int8 *)skip_spaces();
  v4 = *v3;
  if ( v4 == 45 || v4 == 43 )
  {
    v5 = *++v3;
    v6 = v5 - 48;
    if ( v5 == 48 )
      goto LABEL_5;
LABEL_11:
    if ( v6 > 9 )
      return 16;
LABEL_12:
    v8 = 10;
    goto LABEL_15;
  }
  v6 = v4 - 48;
  if ( v4 != 48 )
    goto LABEL_11;
LABEL_5:
  v7 = v3[1];
  if ( v7 == 120 )
  {
    v3 += 2;
    v8 = 16;
    goto LABEL_15;
  }
  if ( v7 == 111 )
  {
    v3 += 2;
    v8 = 8;
    goto LABEL_15;
  }
  if ( v7 != 98 )
    goto LABEL_12;
  v3 += 2;
  v8 = 2;
LABEL_15:
  v10 = 0;
  while ( 1 )
  {
    v11 = *v3;
    v12 = v11 - 48;
    if ( (unsigned int)(v11 - 48) < 0xA )
      goto LABEL_19;
    if ( (unsigned int)(v11 - 97) > 5 )
      break;
    v12 = v11 - 87;
LABEL_19:
    if ( v8 <= v12 )
      return 16;
LABEL_20:
    ++v3;
    v13 = v10 * v8 + v12;
    v14 = v13 >= v10;
    v10 = v13;
    if ( !v14 )
      return 46;
  }
  if ( (unsigned int)(v11 - 65) <= 5 )
  {
    v12 = v11 - 55;
    if ( v8 <= (unsigned __int8)(v11 - 55) )
      return 16;
    goto LABEL_20;
  }
  v15 = (_BYTE *)skip_spaces();
  v16 = (unsigned __int8)*v15;
  if ( *v15 )
    result = 16;
  else
    result = 46;
  if ( v4 != 45 && !v16 )
  {
    *a2 = v10;
    return 0;
  }
  return result;
}
