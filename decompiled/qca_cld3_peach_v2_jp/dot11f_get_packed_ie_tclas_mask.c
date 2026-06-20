__int64 __fastcall dot11f_get_packed_ie_tclas_mask(__int64 a1, _BYTE *a2, int *a3)
{
  int v3; // w8

  if ( *a2 )
  {
    v3 = *a3;
    *a3 += 2;
    if ( a2[1] == 4 )
      *a3 = v3 + 18;
  }
  return 0;
}
