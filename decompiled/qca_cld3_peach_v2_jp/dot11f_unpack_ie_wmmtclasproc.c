__int64 __fastcall dot11f_unpack_ie_wmmtclasproc(__int64 a1, unsigned __int8 *a2, char a3, _BYTE *a4)
{
  int v5; // w8

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 )
  {
    v5 = *a2;
    a4[1] = v5;
    if ( v5 != 1 )
    {
      *a4 = 0;
      return 64;
    }
    if ( a3 != 1 )
    {
      a4[2] = a2[1];
      return 0;
    }
  }
  *a4 = 0;
  return 4;
}
