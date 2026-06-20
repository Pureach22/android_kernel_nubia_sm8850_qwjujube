__int64 __fastcall drm_dp_downstream_min_tmds_clock(unsigned __int8 *a1, _BYTE *a2, __int64 a3)
{
  int v4; // w8
  __int64 v5; // x0

  if ( (a1[5] & 1) == 0 )
    return 0;
  if ( *a1 > 0x10u )
  {
    v4 = *a2 & 7;
    if ( (unsigned int)(v4 - 2) >= 2 )
    {
      if ( v4 != 5 )
        return 0;
      v5 = drm_edid_raw(a3);
      if ( v5 )
      {
        if ( *(unsigned __int8 *)(v5 + 19) >= 4u && (*(_BYTE *)(v5 + 20) & 0x87) == 0x85 )
          return 0;
      }
    }
    return 25000;
  }
  else if ( (a1[5] & 6) == 4 )
  {
    return 25000;
  }
  else
  {
    return 0;
  }
}
