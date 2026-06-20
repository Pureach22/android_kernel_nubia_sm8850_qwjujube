__int64 __fastcall dot11f_get_packed_ie_hs20vendor_ie(__int64 a1, _BYTE *a2, _DWORD *a3)
{
  int v3; // w8

  if ( *a2 )
  {
    v3 = (*a3)++;
    if ( (((unsigned __int8)a2[1] >> 1) & 3u) - 1 <= 1 )
      *a3 = v3 + 3;
  }
  return 0;
}
