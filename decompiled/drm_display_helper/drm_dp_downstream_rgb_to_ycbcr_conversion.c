bool __fastcall drm_dp_downstream_rgb_to_ycbcr_conversion(unsigned __int8 *a1, _BYTE *a2, char a3)
{
  unsigned __int8 v3; // w8
  _BOOL8 result; // x0

  v3 = a1[5];
  if ( (v3 & 1) == 0 )
    return 0;
  if ( *a1 < 0x13u )
    return 0;
  result = 0;
  if ( (v3 & 0x10) != 0 && (*a2 & 7) == 3 )
    return (unsigned __int8)(a3 & a2[3]) != 0;
  return result;
}
