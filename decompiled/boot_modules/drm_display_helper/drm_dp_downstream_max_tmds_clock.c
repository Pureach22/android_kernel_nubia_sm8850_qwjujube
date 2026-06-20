__int64 __fastcall drm_dp_downstream_max_tmds_clock(unsigned __int8 *a1, _BYTE *a2, __int64 a3)
{
  int v4; // w9
  unsigned __int8 *v5; // x19
  _BYTE *v6; // x20
  __int64 v7; // x0
  __int64 v8; // x8

  if ( (a1[5] & 1) == 0 )
    return 0;
  if ( *a1 > 0x10u )
  {
    v4 = *a2 & 7;
    if ( v4 == 2 )
    {
      if ( (a1[5] & 0x10) == 0 )
        return 165000;
    }
    else
    {
      if ( v4 != 3 )
      {
        if ( v4 != 5 )
          return 0;
        v5 = a1;
        v6 = a2;
        v7 = drm_edid_raw(a3);
        a2 = v6;
        v8 = v7;
        a1 = v5;
        if ( v8 )
        {
          if ( *(unsigned __int8 *)(v8 + 19) >= 4u && (*(_BYTE *)(v8 + 20) & 0x87) == 0x85 )
            return 0;
        }
      }
      if ( (a1[5] & 0x10) == 0 )
        return 300000;
    }
    return 2500 * (unsigned int)(unsigned __int8)a2[1];
  }
  else if ( (a1[5] & 6) == 4 )
  {
    return 165000;
  }
  else
  {
    return 0;
  }
}
