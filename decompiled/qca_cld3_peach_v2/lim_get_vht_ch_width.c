__int64 __fastcall lim_get_vht_ch_width(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        _BYTE *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x29
  __int64 v14; // x30
  int v15; // w9
  __int64 result; // x0
  int v17; // w8
  unsigned int v18; // w8

  v15 = a2[3];
  if ( (*(_WORD *)(a1 + 12) & 0x2000) != 0 && a3 && (*(_WORD *)(a1 + 4) & 0x180) != 0 && *(_BYTE *)a3 )
    v15 = *(unsigned __int8 *)(a3 + 4);
  if ( a2[1] == 1 )
  {
    if ( v15 )
    {
      v17 = a2[2] - v15;
      if ( v17 < 0 )
        v17 = v15 - a2[2];
      if ( v17 == 8 )
      {
        result = 3;
        if ( !a5 )
          return result;
      }
      else
      {
        if ( (unsigned int)v17 <= 0x10 )
          result = 2;
        else
          result = 4;
        if ( !a5 )
          return result;
      }
    }
    else
    {
      result = 2;
      if ( !a5 )
        return result;
    }
  }
  else
  {
    if ( a2[1] )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid ch width in vht operation IE %d",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "lim_get_vht_ch_width",
        a2[1],
        v13,
        v14);
      return 0;
    }
    if ( a3 && *(_BYTE *)a3 && a4 && (*(_DWORD *)(a3 + 2) & 4) != 0 && *(_BYTE *)a4 && (*(_WORD *)(a4 + 1) & 2) != 0 )
    {
      result = 1;
      if ( !a5 )
        return result;
    }
    else
    {
      result = 0;
      if ( !a5 )
        return result;
    }
  }
  if ( *a5 )
  {
    v18 = a5[1] & 3;
    if ( v18 >= 2 )
    {
      if ( v18 == 2 )
      {
        if ( (a5[1] & 4) != 0 )
          v18 = 3;
        else
          v18 = 2;
      }
      else
      {
        v18 = 8;
      }
    }
    if ( v18 >= (unsigned int)result )
      return (unsigned int)result;
    else
      return v18;
  }
  return result;
}
