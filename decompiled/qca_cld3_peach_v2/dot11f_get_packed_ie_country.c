__int64 __fastcall dot11f_get_packed_ie_country(__int64 a1, _BYTE *a2, int *a3)
{
  int v3; // w8

  if ( *a2 )
  {
    v3 = *a3 + 6;
    *a3 = v3;
    if ( a2[7] )
      *a3 = 3 * (unsigned __int8)a2[7] + v3;
  }
  return 0;
}
