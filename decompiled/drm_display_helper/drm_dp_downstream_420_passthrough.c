__int64 __fastcall drm_dp_downstream_420_passthrough(unsigned __int8 *a1, _BYTE *a2)
{
  if ( (a1[5] & 1) == 0 || *a1 < 0x13u )
    return 0;
  if ( (*a2 & 7) == 0 )
    return 1;
  if ( (*a2 & 7) != 3 || (a1[5] & 0x10) == 0 )
    return 0;
  return ((unsigned __int8)a2[3] >> 2) & 1;
}
