__int64 __fastcall wlan_mlme_get_phy_max_freq_range(
        __int64 a1,
        unsigned int *a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  _DWORD *v13; // x8
  unsigned int v14; // w25
  unsigned int v15; // w24
  unsigned int v17; // w23
  unsigned int v18; // w26
  __int64 v22; // x9
  _DWORD *v23; // x10
  unsigned int v24; // w11
  unsigned int v25; // w13
  unsigned int v26; // w12
  unsigned int v27; // w12
  unsigned int v28; // w11
  unsigned int v29; // w10
  unsigned int v30; // w11
  unsigned int v31; // w11
  __int64 v32; // x23
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  if ( a1 && (v13 = *(_DWORD **)(a1 + 2800)) != nullptr )
  {
    v14 = v13[326];
    v15 = v13[327];
    v17 = v13[328];
    v18 = v13[329];
    v22 = 0;
    do
    {
      v23 = &v13[v22];
      v22 += 64;
      v24 = v23[390];
      v25 = v23[391];
      if ( v24 >= v14 )
        v26 = v14;
      else
        v26 = v23[390];
      if ( !v14 )
        v26 = v23[390];
      if ( v24 )
        v14 = v26;
      v27 = v23[392];
      if ( v25 <= v15 )
        v28 = v15;
      else
        v28 = v23[391];
      v29 = v23[393];
      if ( !v15 )
        v28 = v25;
      if ( v25 )
        v15 = v28;
      if ( v27 >= v17 )
        v30 = v17;
      else
        v30 = v27;
      if ( !v17 )
        v30 = v27;
      if ( v27 )
        v17 = v30;
      if ( v29 <= v18 )
        v31 = v18;
      else
        v31 = v29;
      if ( !v18 )
        v31 = v29;
      if ( v29 )
        v18 = v31;
    }
    while ( v22 != 448 );
    if ( !v14 && !v15 && !v17 && !v18 )
    {
      v32 = a1;
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: no reg_cap_ext in mac_phy_cap",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "wlan_mlme_get_phy_max_freq_range");
      a1 = v32;
      v18 = 7125;
      v17 = 4990;
      v15 = 2494;
      v14 = 2397;
    }
    if ( (wlan_reg_is_6ghz_supported(a1, a6, a7, a8, a9, a10, a11, a12, a13) & 1) == 0 )
    {
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: disabling 6ghz channels",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "wlan_mlme_get_phy_max_freq_range");
      v18 = 5895;
    }
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: %d %d %d %d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "wlan_mlme_get_phy_max_freq_range",
      v14,
      v15,
      v17,
      v18);
    *a2 = v14;
    *a3 = v15;
    *a4 = v17;
    *a5 = v18;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: target_psoc_info is null",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_mlme_get_phy_max_freq_range");
    return 16;
  }
}
