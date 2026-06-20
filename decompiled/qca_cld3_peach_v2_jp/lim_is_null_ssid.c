__int64 __fastcall lim_is_null_ssid(unsigned __int8 *a1)
{
  int v1; // w8
  _BYTE *v2; // x0
  int v3; // w9
  int v4; // t1

  v1 = *a1;
  if ( !*a1 )
    return 1;
  v4 = a1[1];
  v2 = a1 + 1;
  v3 = v4;
  if ( v1 == 1 && v3 == 32 )
    return 1;
  while ( !*v2 )
  {
    --v1;
    ++v2;
    if ( !v1 )
      return 1;
  }
  return 0;
}
