__int64 __fastcall wlansap_get_max_bw_by_phymode(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w8
  __int64 result; // x0
  unsigned int vht_ch_width; // w0
  int v16; // w8
  unsigned int v17; // w20
  unsigned int v18; // w19
  bool v19; // cf
  _BOOL4 v20; // w9
  int eht_ch_width; // w0
  unsigned int v22; // w8

  if ( !a1 )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid SAP pointer",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlansap_get_max_bw_by_phymode");
    return 0;
  }
  v12 = *(_DWORD *)(a1 + 1484);
  if ( v12 > 2047 )
  {
    if ( v12 >= 0x2000 )
    {
      if ( v12 != 0x4000 && v12 != 0x2000 )
        return 0;
    }
    else if ( v12 != 2048 && v12 != 4096 )
    {
      return 0;
    }
LABEL_18:
    vht_ch_width = sme_get_vht_ch_width(a1, a2, a3, a4);
    v16 = *(_DWORD *)(a1 + 1484);
    v17 = vht_ch_width;
    if ( vht_ch_width < 2 )
      result = 2;
    else
      result = 3;
    if ( v16 == 0x4000 || v16 == 0x2000 )
    {
      v18 = result;
      result = sme_get_eht_ch_width(result);
      v19 = (_DWORD)result != 2 || v17 >= 2;
      v20 = !v19;
      if ( (_DWORD)result == 4 || (result = v18, v20) )
      {
        eht_ch_width = sme_get_eht_ch_width(result);
        if ( eht_ch_width == 2 )
          v22 = 3;
        else
          v22 = 2;
        if ( eht_ch_width == 4 )
          return 7;
        else
          return v22;
      }
    }
    return result;
  }
  if ( v12 > 255 )
  {
    if ( v12 != 256 && v12 != 512 )
      return 0;
    goto LABEL_18;
  }
  result = 1;
  if ( v12 != 16 && v12 != 64 )
    return 0;
  return result;
}
