__int64 __fastcall drm_dp_downstream_444_to_420_conversion(unsigned __int8 *a1, _BYTE *a2)
{
  unsigned __int8 v2; // w8
  __int64 result; // x0

  v2 = a1[5];
  if ( (v2 & 1) == 0 )
    return 0;
  if ( *a1 < 0x13u )
    return 0;
  result = 0;
  if ( (v2 & 0x10) != 0 && (*a2 & 7) == 3 )
    return ((unsigned __int8)a2[3] >> 4) & 1;
  return result;
}
