__int64 __fastcall target_if_spectral_is_valid_80p80_freq(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        bool *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  unsigned int v17; // w20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w8
  __int64 result; // x0
  const char *v44; // x2
  bool v46; // w8
  int v47; // [xsp+8h] [xbp-38h] BYREF
  __int64 v48; // [xsp+Ch] [xbp-34h]
  __int64 v49; // [xsp+14h] [xbp-2Ch]
  int v50; // [xsp+1Ch] [xbp-24h]
  int v51; // [xsp+20h] [xbp-20h] BYREF
  __int128 v52; // [xsp+24h] [xbp-1Ch]
  int v53; // [xsp+34h] [xbp-Ch]
  __int64 v54; // [xsp+38h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = 0;
  v52 = 0u;
  v50 = 0;
  v49 = 0;
  v48 = 0;
  if ( !a4 )
  {
    v44 = "%s: Argument(is_valid) is null";
LABEL_16:
    qdf_trace_msg(0x56u, 2u, v44, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_spectral_is_valid_80p80_freq");
    result = 29;
    goto LABEL_17;
  }
  if ( !a1 )
  {
    v44 = "%s: pdev is null.";
    goto LABEL_16;
  }
  v12 = *(_QWORD *)(a1 + 80);
  if ( !v12 )
  {
    v44 = "%s: psoc is null.";
    goto LABEL_16;
  }
  if ( (*(_BYTE *)(v12 + 22) & 0x10) != 0 )
  {
    result = 0;
    v46 = a2 - 5660 < 0x92 && a3 - 5660 < 0x92;
    *a4 = v46;
  }
  else
  {
    DWORD2(v52) = a3;
    v17 = a2 - 10;
    BYTE2(v52) = wlan_reg_freq_to_chan(a1, a3, a5, a6, a7, a8, a9, a10, a11, a12);
    v51 = 4;
    wlan_reg_set_channel_params_for_pwrmode(a1, v17, 0, (__int64)&v51, 0, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( v51 != 4 )
      goto LABEL_12;
    if ( *(_QWORD *)((char *)&v52 + 4) != __PAIR64__(a3, a2) )
      goto LABEL_12;
    v47 = 2;
    if ( (wlan_reg_get_5g_bonded_channel_state_for_pwrmode(a1, v17, &v47, 0, v26, v27, v28, v29, v30, v31, v32, v33)
        & 0xFFFFFFFB) == 0 )
      goto LABEL_12;
    v47 = 2;
    if ( (wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
            a1,
            DWORD2(v52) - 10,
            &v47,
            0,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41)
        & 0xFFFFFFFB) == 0 )
      goto LABEL_12;
    v42 = DWORD1(v52) - DWORD2(v52);
    if ( DWORD1(v52) - DWORD2(v52) < 0 )
      v42 = DWORD2(v52) - DWORD1(v52);
    if ( v42 > 80 )
    {
      result = 0;
      *a4 = 1;
    }
    else
    {
LABEL_12:
      result = 0;
      *a4 = 0;
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
