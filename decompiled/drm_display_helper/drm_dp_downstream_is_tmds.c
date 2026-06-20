bool __fastcall drm_dp_downstream_is_tmds(unsigned __int8 *a1, _BYTE *a2, __int64 a3)
{
  _BOOL8 result; // x0
  int v4; // w8
  __int64 v5; // x0

  if ( *a1 <= 0x10u )
    return (a1[5] & 6) == 4;
  v4 = *a2 & 7;
  result = true;
  if ( (unsigned int)(v4 - 2) >= 2 )
  {
    if ( v4 != 5 )
      return false;
    v5 = drm_edid_raw(a3);
    if ( v5 )
    {
      if ( *(unsigned __int8 *)(v5 + 19) >= 4u && (*(_BYTE *)(v5 + 20) & 0x87) == 0x85 )
        return false;
    }
  }
  return result;
}
