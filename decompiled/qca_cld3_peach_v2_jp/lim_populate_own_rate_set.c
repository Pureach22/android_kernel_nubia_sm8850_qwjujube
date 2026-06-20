__int64 __fastcall lim_populate_own_rate_set(
        __int64 a1,
        _BYTE *a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15)
{
  __int64 v21; // x8
  unsigned int v22; // w25
  char v24; // w27
  char v25; // w26
  const char *v26; // x2
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w8
  unsigned int v36; // w9
  unsigned int v37; // w10
  int v38; // w11
  __int64 v39; // x12
  __int64 v40; // x1
  unsigned int v41; // w0
  unsigned int v42; // w2
  unsigned int v43; // w3
  __int16 v44; // w1
  int v45; // w2
  bool v46; // zf
  __int64 v47; // x9
  __int64 result; // x0
  char v49; // w9
  char v50; // w8
  char v51; // w9
  char v52; // w8
  char v53; // w9
  char v54; // w8
  char v55; // w9
  char v56; // w8
  char v57; // w9
  char v58; // w8
  char v59; // w9
  char v60; // w8
  char v61; // w9
  char v62; // w8
  char v63; // w9
  char v64; // w8
  char v65; // w9
  char v66; // w8
  char v67; // w9
  char v68; // w8
  char v69; // w9
  char v70; // w8
  char v71; // w9
  char v72; // w8
  char v73; // w9
  char v74; // w8
  char v75; // w9
  char v76; // w8
  char v77; // w9
  size_t v78[3]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v79[3]; // [xsp+18h] [xbp-18h] BYREF

  v79[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = *(_QWORD *)(a1 + 8);
  memset(v79, 0, 13);
  v22 = *(_DWORD *)(v21 + 5748);
  memset(&v78[1], 0, 13);
  if ( v22 > 0xA || ((1 << v22) & 0x53D) == 0 )
  {
    LOBYTE(v79[0]) = 0;
LABEL_10:
    v78[0] = *(_QWORD *)(v21 + 2824);
    wlan_mlme_get_cfg_str((char *)&v78[1] + 1, v21 + 2816, v78, a4, a5, a6, a7, a8, a9, a10, a11);
    v25 = v78[0];
    v24 = v79[0];
    LOBYTE(v78[1]) = v78[0];
    if ( LOBYTE(v79[0]) + (unsigned int)LOBYTE(v78[0]) <= 0xC )
    {
      if ( LOBYTE(v78[0]) )
        memcpy((char *)v79 + LOBYTE(v79[0]) + 1, (char *)&v78[1] + 1, LOBYTE(v78[0]));
      else
        v25 = 0;
      goto LABEL_15;
    }
LABEL_11:
    v26 = "%s: more than 12 rates in CFG";
    goto LABEL_41;
  }
  v78[0] = *(_QWORD *)(v21 + 2784);
  wlan_mlme_get_cfg_str((char *)v79 + 1, v21 + 2776, v78, a4, a5, a6, a7, a8, a9, a10, a11);
  LOBYTE(v79[0]) = v78[0];
  if ( v22 != 3 )
  {
    v21 = *(_QWORD *)(a1 + 8);
    goto LABEL_10;
  }
  v24 = v78[0];
  LOBYTE(v78[1]) = 0;
  if ( LOBYTE(v78[0]) > 0xCuLL )
    goto LABEL_11;
  v25 = 0;
LABEL_15:
  LOBYTE(v79[0]) = v24 + v25;
  qdf_mem_set(a2, 0x3Eu, 0);
  v35 = LOBYTE(v79[0]);
  if ( LOBYTE(v79[0]) )
  {
    v36 = 0;
    v37 = 0;
    v38 = 0;
    if ( LOBYTE(v79[0]) >= 0xCu )
      v39 = 12;
    else
      v39 = LOBYTE(v79[0]);
    while ( 1 )
    {
      v40 = 0;
      v41 = 0;
      v42 = 255;
      do
      {
        v43 = *((_BYTE *)v79 + v40 + 1) & 0x7F;
        if ( v42 > v43 )
          v41 = v40;
        ++v40;
        if ( v42 >= v43 )
          v42 = v43;
      }
      while ( v39 != v40 );
      if ( v41 > 0xB )
        break;
      v44 = *((unsigned __int8 *)v79 + v41 + 1);
      v45 = v44 & 0x7F;
      v46 = (unsigned int)(v45 - 12) > 0x3C || ((1LL << ((v44 & 0x7Fu) - 12)) & 0x1000001001001041LL) == 0;
      if ( !v46 || v45 == 108 || v45 == 96 )
      {
        if ( v37 > 7 )
          break;
        *(_WORD *)&a2[2 * v37++ + 8] = v44;
      }
      else
      {
        if ( v36 > 3 )
          break;
        *(_WORD *)&a2[2 * v36++] = v44;
      }
      ++v38;
      *((_BYTE *)v79 + v41 + 1) = -1;
      if ( v38 == v35 )
        goto LABEL_38;
    }
    __break(0x5512u);
  }
LABEL_38:
  if ( v22 - 7 >= 7 && v22 != 5 && v22 )
    goto LABEL_49;
  v47 = *(_QWORD *)(a1 + 8);
  v78[0] = 16;
  if ( !(unsigned int)wlan_mlme_get_cfg_str(a2 + 24, v47 + 2856, v78, v27, v28, v29, v30, v31, v32, v33, v34) )
  {
    if ( *(_BYTE *)(a13 + 8635) == 1 )
      a2[25] = 0;
    if ( a3 )
    {
      v49 = a2[25];
      a2[24] &= *a3;
      v50 = v49 & a3[1];
      v51 = a2[26];
      a2[25] = v50;
      v52 = v51 & a3[2];
      v53 = a2[27];
      a2[26] = v52;
      v54 = v53 & a3[3];
      v55 = a2[28];
      a2[27] = v54;
      v56 = v55 & a3[4];
      v57 = a2[29];
      a2[28] = v56;
      v58 = v57 & a3[5];
      v59 = a2[30];
      a2[29] = v58;
      v60 = v59 & a3[6];
      v61 = a2[31];
      a2[30] = v60;
      v62 = v61 & a3[7];
      v63 = a2[32];
      a2[31] = v62;
      v64 = v63 & a3[8];
      v65 = a2[33];
      a2[32] = v64;
      v66 = v65 & a3[9];
      v67 = a2[34];
      a2[33] = v66;
      v68 = v67 & a3[10];
      v69 = a2[35];
      a2[34] = v68;
      v70 = v69 & a3[11];
      v71 = a2[36];
      a2[35] = v70;
      v72 = v71 & a3[12];
      v73 = a2[37];
      a2[36] = v72;
      v74 = v73 & a3[13];
      v75 = a2[38];
      a2[37] = v74;
      v76 = v75 & a3[14];
      v77 = a2[39];
      a2[38] = v76;
      a2[39] = v77 & a3[15];
    }
    lim_dump_ht_mcs_mask(a2 + 24, 0);
LABEL_49:
    lim_populate_vht_mcs_set(a1, a2, a14, a13, *(_BYTE *)(a13 + 8635), 0);
    lim_populate_he_mcs_set(a1, a2, a15, a13, *(unsigned __int8 *)(a13 + 8635));
    wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a13 + 284));
    result = 0;
    goto LABEL_50;
  }
  v26 = "%s: could not retrieve supportedMCSSet";
LABEL_41:
  qdf_trace_msg(0x35u, 2u, v26, a4, a5, a6, a7, a8, a9, a10, a11, "lim_populate_own_rate_set");
  result = 16;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
