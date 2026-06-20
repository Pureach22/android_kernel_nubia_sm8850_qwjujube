__int64 __fastcall mlme_get_max_vht_mcs_idx(__int16 a1, __int16 a2)
{
  char v2; // w8
  bool v3; // zf
  __int64 result; // x0
  unsigned int v5; // w8
  unsigned int v6; // w8

  v2 = a1;
  v3 = a1 == 0;
  result = 255;
  if ( !v3 )
  {
    v5 = v2 & 3;
    if ( v5 >= (a2 & 3u) )
      v5 = a2 & 3;
    v3 = v5 == 3;
    v6 = v5 + 7;
    if ( v3 )
      v6 = 3;
    if ( a2 )
      return v6;
    else
      return 255;
  }
  return result;
}
