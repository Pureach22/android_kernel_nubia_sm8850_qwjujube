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
        __int64 a15,
        __int64 a16)
{
  __int64 v23; // x8
  unsigned int v24; // w26
  char v26; // w28
  char v27; // w27
  const char *v28; // x2
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w8
  unsigned int v38; // w9
  unsigned int v39; // w10
  int v40; // w11
  __int64 v41; // x12
  __int64 v42; // x1
  unsigned int v43; // w0
  unsigned int v44; // w2
  unsigned int v45; // w3
  __int16 v46; // w1
  int v47; // w2
  bool v48; // zf
  __int64 v49; // x9
  __int64 result; // x0
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
  char v78; // w8
  char v79; // w9
  unsigned int v80; // w23
  bool is_24ghz_ch_freq; // w0
  size_t v82[3]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v83[3]; // [xsp+18h] [xbp-18h] BYREF

  v83[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = *(_QWORD *)(a1 + 8);
  memset(v83, 0, 13);
  v24 = *(_DWORD *)(v23 + 5964);
  memset(&v82[1], 0, 13);
  if ( v24 > 0xA || ((1 << v24) & 0x53D) == 0 )
  {
    LOBYTE(v83[0]) = 0;
LABEL_10:
    v82[0] = *(_QWORD *)(v23 + 3024);
    wlan_mlme_get_cfg_str((char *)&v82[1] + 1, v23 + 3016, v82, a4, a5, a6, a7, a8, a9, a10, a11);
    v27 = v82[0];
    v26 = v83[0];
    LOBYTE(v82[1]) = v82[0];
    if ( LOBYTE(v83[0]) + (unsigned int)LOBYTE(v82[0]) <= 0xC )
    {
      if ( LOBYTE(v82[0]) )
        memcpy((char *)v83 + LOBYTE(v83[0]) + 1, (char *)&v82[1] + 1, LOBYTE(v82[0]));
      else
        v27 = 0;
      goto LABEL_15;
    }
LABEL_11:
    v28 = "%s: more than 12 rates in CFG";
    goto LABEL_41;
  }
  v82[0] = *(_QWORD *)(v23 + 2984);
  wlan_mlme_get_cfg_str((char *)v83 + 1, v23 + 2976, v82, a4, a5, a6, a7, a8, a9, a10, a11);
  LOBYTE(v83[0]) = v82[0];
  if ( v24 != 3 )
  {
    v23 = *(_QWORD *)(a1 + 8);
    goto LABEL_10;
  }
  v26 = v82[0];
  LOBYTE(v82[1]) = 0;
  if ( LOBYTE(v82[0]) > 0xCuLL )
    goto LABEL_11;
  v27 = 0;
LABEL_15:
  LOBYTE(v83[0]) = v26 + v27;
  qdf_mem_set(a2, 0x4Cu, 0);
  v37 = LOBYTE(v83[0]);
  if ( LOBYTE(v83[0]) )
  {
    v38 = 0;
    v39 = 0;
    v40 = 0;
    if ( LOBYTE(v83[0]) >= 0xCu )
      v41 = 12;
    else
      v41 = LOBYTE(v83[0]);
    while ( 1 )
    {
      v42 = 0;
      v43 = 0;
      v44 = 255;
      do
      {
        v45 = *((_BYTE *)v83 + v42 + 1) & 0x7F;
        if ( v44 > v45 )
          v43 = v42;
        ++v42;
        if ( v44 >= v45 )
          v44 = v45;
      }
      while ( v41 != v42 );
      if ( v43 > 0xB )
        break;
      v46 = *((unsigned __int8 *)v83 + v43 + 1);
      v47 = v46 & 0x7F;
      v48 = (unsigned int)(v47 - 12) > 0x3C || ((1LL << ((v46 & 0x7Fu) - 12)) & 0x1000001001001041LL) == 0;
      if ( !v48 || v47 == 108 || v47 == 96 )
      {
        if ( v39 > 7 )
          break;
        *(_WORD *)&a2[2 * v39++ + 8] = v46;
      }
      else
      {
        if ( v38 > 3 )
          break;
        *(_WORD *)&a2[2 * v38++] = v46;
      }
      ++v40;
      *((_BYTE *)v83 + v43 + 1) = -1;
      if ( v40 == v37 )
        goto LABEL_38;
    }
    __break(0x5512u);
  }
LABEL_38:
  if ( v24 - 7 >= 7 && v24 != 5 && v24 )
    goto LABEL_49;
  v49 = *(_QWORD *)(a1 + 8);
  v82[0] = 16;
  if ( !(unsigned int)wlan_mlme_get_cfg_str(a2 + 24, v49 + 3056, v82, v29, v30, v31, v32, v33, v34, v35, v36) )
  {
    if ( *(_BYTE *)(a13 + 8635) == 1 )
      a2[25] = 0;
    if ( a3 )
    {
      v51 = a2[25];
      a2[24] &= *a3;
      v52 = v51 & a3[1];
      v53 = a2[26];
      a2[25] = v52;
      v54 = v53 & a3[2];
      v55 = a2[27];
      a2[26] = v54;
      v56 = v55 & a3[3];
      v57 = a2[28];
      a2[27] = v56;
      v58 = v57 & a3[4];
      v59 = a2[29];
      a2[28] = v58;
      v60 = v59 & a3[5];
      v61 = a2[30];
      a2[29] = v60;
      v62 = v61 & a3[6];
      v63 = a2[31];
      a2[30] = v62;
      v64 = v63 & a3[7];
      v65 = a2[32];
      a2[31] = v64;
      v66 = v65 & a3[8];
      v67 = a2[33];
      a2[32] = v66;
      v68 = v67 & a3[9];
      v69 = a2[34];
      a2[33] = v68;
      v70 = v69 & a3[10];
      v71 = a2[35];
      a2[34] = v70;
      v72 = v71 & a3[11];
      v73 = a2[36];
      a2[35] = v72;
      v74 = v73 & a3[12];
      v75 = a2[37];
      a2[36] = v74;
      v76 = v75 & a3[13];
      v77 = a2[38];
      a2[37] = v76;
      v78 = v77 & a3[14];
      v79 = a2[39];
      a2[38] = v78;
      a2[39] = v79 & a3[15];
    }
    lim_dump_ht_mcs_mask(a2 + 24, 0);
LABEL_49:
    lim_populate_vht_mcs_set(a1, a2, a14, a13, *(_BYTE *)(a13 + 8635), 0);
    lim_populate_he_mcs_set(a1, a2, a15, a13, *(unsigned __int8 *)(a13 + 8635));
    v80 = *(_DWORD *)(a13 + 7176);
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a13 + 284));
    lim_populate_eht_mcs_set(a1, a2, a16, a13, v80, is_24ghz_ch_freq);
    result = 0;
    goto LABEL_50;
  }
  v28 = "%s: could not retrieve supportedMCSSet";
LABEL_41:
  qdf_trace_msg(0x35u, 2u, v28, a4, a5, a6, a7, a8, a9, a10, a11, "lim_populate_own_rate_set");
  result = 16;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
