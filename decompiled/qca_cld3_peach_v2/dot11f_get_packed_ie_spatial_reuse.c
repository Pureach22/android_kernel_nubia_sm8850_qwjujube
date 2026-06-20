__int64 __fastcall dot11f_get_packed_ie_spatial_reuse(__int64 a1, _BYTE *a2, _DWORD *a3)
{
  int v3; // w8

  if ( *a2 )
  {
    v3 = (*a3)++;
    if ( (a2[1] & 4) != 0 )
    {
      *a3 = v3 + 2;
      if ( (a2[1] & 8) != 0 )
        *a3 = v3 + 20;
    }
  }
  return 0;
}
