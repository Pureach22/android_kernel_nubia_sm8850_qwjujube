__int64 __fastcall qdf_bool_parse(__int64 a1, char *a2)
{
  __int64 result; // x0
  unsigned __int8 *v5; // x0
  int v6; // w8
  char v7; // w20
  char v8; // w9

  result = 4;
  if ( !a1 || !a2 )
    return result;
  v5 = (unsigned __int8 *)skip_spaces(a1);
  v6 = *v5;
  v7 = 1;
  v8 = v6 - 48;
  if ( (unsigned int)(v6 - 48) > 0x3E )
    goto LABEL_7;
  if ( ((1LL << v8) & 0x4000000040000001LL) == 0 )
  {
    if ( ((1LL << v8) & 0x20000000002LL) != 0 )
      goto LABEL_8;
LABEL_7:
    if ( v6 != 121 )
      return 16;
    goto LABEL_8;
  }
  v7 = 0;
LABEL_8:
  if ( *(_BYTE *)skip_spaces(v5 + 1) )
    return 16;
  *a2 = v7;
  return 0;
}
