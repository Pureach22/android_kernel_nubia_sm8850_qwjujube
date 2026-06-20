__int64 __fastcall validate_acl_mac_addrs(_WORD *a1)
{
  unsigned int v1; // w9
  __int64 result; // x0
  unsigned __int16 *v4; // x8
  unsigned int v5; // w10
  bool v6; // cc

  v1 = (unsigned __int16)(*a1 - 4);
  if ( v1 < 4 )
    return 0;
  result = 0;
  v4 = a1 + 2;
  do
  {
    v5 = *v4;
    if ( v5 < 4 || v1 < v5 )
      break;
    if ( v5 != 10 )
      return 4294967274LL;
    v6 = (int)v1 <= 15;
    v1 -= 12;
    result = (unsigned int)(result + 1);
    v4 += 6;
  }
  while ( !v6 );
  return result;
}
