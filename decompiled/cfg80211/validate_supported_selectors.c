__int64 __fastcall validate_supported_selectors(_WORD *a1)
{
  char *v1; // x0
  __int16 v2; // t1
  __int64 v3; // x8
  int v4; // t1

  v2 = *a1;
  v1 = (char *)(a1 + 2);
  v3 = (unsigned __int8)(v2 - 4);
  if ( (_BYTE)v2 == 4 )
    return 0;
  while ( 1 )
  {
    v4 = *v1++;
    if ( v4 < 0 )
      break;
    if ( !--v3 )
      return 0;
  }
  return 4294967274LL;
}
