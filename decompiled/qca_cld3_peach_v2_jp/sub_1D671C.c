// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_1D671C@<X0>(
        __int64 a1@<X4>,
        int a2@<W8>,
        double a3@<D0>,
        double a4@<D1>,
        double a5@<D2>,
        double a6@<D3>,
        double a7@<D4>,
        double a8@<D5>,
        double a9@<D6>,
        double a10@<D7>)
{
  int v10; // w9
  int v11; // w10
  char v12; // w19
  int *v13; // x28
  __int64 v14; // x29
  __int64 result; // x0
  int v16; // w8
  int v17; // w9
  int v18; // w8
  int v19; // w9
  int v20; // w8
  int v21; // w9
  int v22; // w8
  int v23; // w9
  int v24; // w10
  int v25; // w8
  __int64 j; // x8
  int *v27; // x9
  int v28; // w10
  __int64 k; // x8
  int *v30; // x9
  int v31; // w10
  __int64 n; // x8
  int *v33; // x10
  int v34; // w11
  __int64 v35; // x19
  unsigned __int16 *v36; // x8
  unsigned int v37; // w20
  unsigned int chan_enum_for_freq; // w0
  __int64 i; // x8
  int *v40; // x9
  int v41; // w10
  __int64 m; // x19
  unsigned int *v43; // x22
  unsigned int v44; // w8
  char v45; // w0
  int *v46; // x10
  unsigned int *v47; // x10
  int v48; // w11
  int v49; // t1
  __int64 v50; // x19
  unsigned __int16 *v51; // x8
  unsigned int v52; // w20
  unsigned int v53; // w0
  int *v54; // x10
  unsigned int *v55; // x10
  int v56; // w11
  int v57; // t1
  __int64 v58; // x19
  unsigned __int16 *v59; // x8
  unsigned int v60; // w20
  unsigned int v61; // w0
  int *v62; // x10
  unsigned int *v63; // x10
  int v64; // w11
  int v65; // t1
  unsigned __int16 *v66; // x19
  int v67; // w8
  __int64 v68; // x8
  int *v69; // x8
  int v70; // w8
  __int64 v71; // x8
  __int64 v72; // x20
  __int64 v73; // x20
  __int64 v74; // x21
  __int64 v75; // x20
  int v76; // w8
  int v77; // w8
  __int64 v78; // x19
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x20
  __int64 v88; // x0
  __int64 v89; // x19
  __int64 v90; // x0
  __int64 ii; // x8
  int *v92; // x10
  int v93; // w11
  __int64 mm; // x19
  const char *v95; // x2
  __int64 jj; // x19
  unsigned int *v97; // x22
  unsigned int v98; // w8
  unsigned int *v99; // x17
  __int64 v100; // x8
  __int64 i1; // x9
  int *v102; // x12
  __int64 i2; // x13
  int v104; // w14
  int *v105; // x14
  int v106; // w15
  int *v107; // x15
  int v108; // w14
  __int64 v109; // x8
  __int64 v110; // x20
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  __int64 v119; // x0
  __int64 v120; // x10
  __int64 v121; // x25
  __int64 i3; // x27
  int v123; // w8
  unsigned int *v124; // x20
  int v125; // w26
  unsigned int v126; // w21
  int v127; // w8
  __int64 v128; // x20
  unsigned int v129; // w21
  unsigned int *v130; // x22
  __int64 v131; // x26
  unsigned int v132; // w23
  unsigned int v133; // w24
  unsigned int *v134; // x22
  __int64 v135; // x28
  unsigned int v136; // w23
  unsigned int v137; // w24
  __int64 v138; // x20
  int v139; // w8
  int v140; // w8
  __int64 v141; // x0
  char *v142; // x20
  int v143; // w8
  __int64 v144; // x8
  __int64 kk; // x19
  unsigned int *v146; // x22
  unsigned int v147; // w8
  __int64 v148; // x8
  char *v149; // x9
  unsigned int v150; // w11
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  int v159; // w8
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  char *v168; // x9
  __int64 nn; // x10
  int v170; // w13
  __int64 v171; // [xsp-C8h] [xbp-C8h]
  unsigned int *v172; // [xsp-C0h] [xbp-C0h]
  __int64 v173; // [xsp-B8h] [xbp-B8h]
  int *v174; // [xsp-B0h] [xbp-B0h]

  if ( (v11 & 0x40000) == 0 )
    return wlan_vdev_mlme_set_ext_hdl();
  v13[74] = 0;
  v13[2] = 0;
  v13[3] = a2;
  v16 = v13[21];
  v13[11] = 0;
  v13[12] = v10;
  v17 = v13[30];
  v13[83] = 0;
  v13[20] = 0;
  v13[21] = v16 | 1;
  v18 = v17 | 1;
  v19 = v13[39];
  v13[29] = 0;
  v13[30] = v18;
  v20 = v19 | 1;
  v21 = v13[66];
  v13[92] = 0;
  v13[38] = 0;
  v13[39] = v20;
  v22 = v13[48];
  v13[101] = 0;
  v13[66] = v21 | 1;
  v13[75] = v11 | 1;
  v23 = v13[84];
  v24 = v13[57];
  v13[47] = 0;
  v13[48] = v22 | 1;
  v13[110] = 0;
  v13[84] = v23 | 1;
  v25 = v13[93];
  v13[56] = 0;
  v13[57] = v24 | 1;
  v13[119] = 0;
  v13[93] = v25 | 1;
  v13[102] |= 1u;
  v13[111] |= 1u;
  v13[120] |= 1u;
  if ( (v12 & 4) == 0 )
  {
    ((void (__fastcall *)(int *, int *))reg_modify_chan_list_for_band_6G)(v13, v13);
    a1 = *(_QWORD *)(v14 - 56);
  }
  if ( (*(_BYTE *)(a1 + 60) & 1) == 0 )
  {
    for ( i = 0; i != 918; i += 9 )
    {
      v40 = &v13[i];
      v41 = v13[i + 3];
      if ( (v41 & 8) != 0 )
      {
        v40[2] = 0;
        v40[3] = v41 | 1;
      }
    }
  }
  for ( j = 0; j != 918; j += 9 )
  {
    v27 = &v13[j];
    if ( BYTE1(v13[j + 6]) == 1 )
    {
      v28 = v27[3] | 1;
      v27[2] = 0;
      v27[3] = v28;
    }
  }
  for ( k = 0; k != 918; k += 9 )
  {
    v30 = &v13[k];
    if ( BYTE2(v13[k + 7]) )
    {
      v31 = v30[3] | 1;
      v30[2] = 0;
      v30[3] = v31;
    }
  }
  if ( (*(_BYTE *)(a1 + 68) & 1) == 0 )
  {
    for ( m = 0; m != 918; m += 9 )
    {
      v43 = (unsigned int *)&v13[m];
      v44 = v13[m + 3];
      if ( (v44 & 0x201) == 0x200 )
      {
        if ( *(_BYTE *)(a1 + 2253) == 1 )
        {
          v45 = ((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(*v43);
          a1 = *(_QWORD *)(v14 - 56);
          if ( (v45 & 1) != 0 )
            continue;
          v44 = v43[3];
        }
        v13[m + 2] = 2;
        v43[3] = v44 | 2;
      }
    }
  }
  if ( *(_BYTE *)(a1 + 764) == 1 && *(_BYTE *)(a1 + 765) == 1 )
  {
    for ( n = 0; n != 918; n += 9 )
    {
      v33 = &v13[n];
      v34 = v13[n + 3];
      if ( (v34 & 0x201) == 0x200 )
      {
        v33[2] = 0;
        v33[3] = v34 | 1;
      }
    }
  }
  if ( (*(_BYTE *)(a1 + 68) & 1) == 0 && (*(_BYTE *)(a1 + 2253) & 1) == 0 && *(_BYTE *)(a1 + 2252) == 1 )
  {
    if ( *(_DWORD *)(a1 + 2272) || *(unsigned __int8 *)(a1 + 2268) != 255 )
    {
      v35 = a1 + 2276;
      v36 = *(unsigned __int16 **)(a1 + 2276);
      if ( v36 )
      {
        v37 = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*v36);
        chan_enum_for_freq = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*(unsigned __int16 *)(*(_QWORD *)v35 + 2LL));
      }
      else
      {
        chan_enum_for_freq = reg_get_chan_enum_for_freq();
        v37 = chan_enum_for_freq;
      }
      a1 = *(_QWORD *)(v14 - 56);
      if ( v37 != 102 && chan_enum_for_freq != 102 && v37 <= chan_enum_for_freq )
      {
        do
        {
          v46 = &v13[9 * v37];
          v49 = v46[3];
          v47 = (unsigned int *)(v46 + 3);
          v48 = v49;
          if ( (v49 & 0x201) == 0x200 )
            *v47 = v48 & 0xFFFFFFFC;
          ++v37;
        }
        while ( v37 <= chan_enum_for_freq );
      }
    }
    if ( *(_DWORD *)(a1 + 2288) || *(unsigned __int8 *)(a1 + 2284) != 255 )
    {
      v50 = a1 + 2292;
      v51 = *(unsigned __int16 **)(a1 + 2292);
      if ( v51 )
      {
        v52 = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*v51);
        v53 = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*(unsigned __int16 *)(*(_QWORD *)v50 + 2LL));
      }
      else
      {
        v53 = reg_get_chan_enum_for_freq();
        v52 = v53;
      }
      a1 = *(_QWORD *)(v14 - 56);
      if ( v52 != 102 && v53 != 102 && v52 <= v53 )
      {
        do
        {
          v54 = &v13[9 * v52];
          v57 = v54[3];
          v55 = (unsigned int *)(v54 + 3);
          v56 = v57;
          if ( (v57 & 0x201) == 0x200 )
            *v55 = v56 & 0xFFFFFFFC;
          ++v52;
        }
        while ( v52 <= v53 );
      }
    }
    if ( *(_DWORD *)(a1 + 2304) || *(unsigned __int8 *)(a1 + 2300) != 255 )
    {
      v58 = a1 + 2308;
      v59 = *(unsigned __int16 **)(a1 + 2308);
      if ( v59 )
      {
        v60 = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*v59);
        v61 = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*(unsigned __int16 *)(*(_QWORD *)v58 + 2LL));
      }
      else
      {
        v61 = reg_get_chan_enum_for_freq();
        v60 = v61;
      }
      a1 = *(_QWORD *)(v14 - 56);
      if ( v60 != 102 && v61 != 102 && v60 <= v61 )
      {
        do
        {
          v62 = &v13[9 * v60];
          v65 = v62[3];
          v63 = (unsigned int *)(v62 + 3);
          v64 = v65;
          if ( (v65 & 0x201) == 0x200 )
            *v63 = v64 & 0xFFFFFFFC;
          ++v60;
        }
        while ( v60 <= v61 );
      }
    }
  }
  if ( v13 && (*(_BYTE *)(a1 + 61) & 1) != 0 )
  {
    v66 = (unsigned __int16 *)(a1 + 2254);
    if ( v13 != (int *)-396LL )
    {
      v67 = v13[99];
      if ( v67 == *v66 )
      {
        v68 = 0;
        goto LABEL_78;
      }
      if ( v67 == *(unsigned __int16 *)(a1 + 2258) )
      {
        v68 = 1;
LABEL_78:
        v13[103] = LOBYTE(v66[2 * v68 + 1]);
        v69 = v13 + 108;
        if ( v13 == (int *)-432LL )
          goto LABEL_86;
LABEL_81:
        v70 = *v69;
        if ( v70 == *v66 )
        {
          v71 = 0;
LABEL_85:
          v13[112] = LOBYTE(v66[2 * v71 + 1]);
LABEL_87:
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: Channel 12 tx_power = %d, 13 tx_power = %d",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "reg_modify_chan_list_for_fcc_channel",
            (unsigned int)v13[103]);
          a1 = *(_QWORD *)(v14 - 56);
          goto LABEL_88;
        }
        if ( v70 == *(unsigned __int16 *)(a1 + 2258) )
        {
          v71 = 1;
          goto LABEL_85;
        }
LABEL_86:
        v13[112] = 2;
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: Channel 13 not found from BDF",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "reg_modify_chan_list_for_fcc_channel",
          a1);
        goto LABEL_87;
      }
    }
    v13[103] = 8;
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: Channel 12 not found from BDF",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "reg_modify_chan_list_for_fcc_channel");
    a1 = *(_QWORD *)(v14 - 56);
    v69 = v13 + 108;
    if ( v13 == (int *)-432LL )
      goto LABEL_86;
    goto LABEL_81;
  }
LABEL_88:
  if ( (*(_BYTE *)(a1 + 69) & 1) == 0 )
  {
    for ( ii = 0; ii != 918; ii += 9 )
    {
      if ( v13[ii] == 5720 )
      {
        v92 = &v13[ii];
        v93 = v13[ii + 3] | 1;
        v92[2] = 0;
        v92[3] = v93;
      }
    }
  }
  v72 = *(_QWORD *)(a1 + 36);
  if ( (((__int64 (__fastcall *)(__int64))reg_is_etsi_regdmn)(v72) & 1) != 0
    && (((__int64 (__fastcall *)(__int64))reg_is_etsi_srd_chan_allowed_master_mode)(v72) & 1) == 0 )
  {
    for ( jj = 0; jj != 918; jj += 9 )
    {
      v97 = (unsigned int *)&v13[jj];
      if ( (v13[jj + 3] & 1) == 0
        && (((__int64 (__fastcall *)(__int64, _QWORD))reg_is_etsi_srd_chan_for_freq)(v72, *v97) & 1) != 0 )
      {
        v98 = v97[3];
        v13[jj + 2] = 2;
        v97[3] = v98 | 2;
      }
    }
  }
  v73 = *(_QWORD *)(*(_QWORD *)(v14 - 56) + 36LL);
  v74 = *(_QWORD *)(v73 + 80);
  if ( (((__int64 (__fastcall *)(__int64))reg_is_fcc_regdmn)(v73) & 1) != 0 )
  {
    if ( (((__int64 (__fastcall *)(__int64))reg_is_5dot9_ghz_supported)(v74) & 1) != 0
      && (((__int64 (__fastcall *)(__int64))reg_is_regdb_offloaded)(v74) & 1) != 0 )
    {
      if ( (((__int64 (__fastcall *)(__int64))reg_is_5dot9_ghz_chan_allowed_master_mode)(v73) & 1) == 0 )
      {
        for ( kk = 0; kk != 918; kk += 9 )
        {
          v146 = (unsigned int *)&v13[kk];
          if ( (v13[kk + 3] & 1) == 0
            && (((__int64 (__fastcall *)(__int64, _QWORD))reg_is_5dot9_ghz_freq)(v73, *v146) & 1) != 0 )
          {
            v147 = v146[3];
            v13[kk + 2] = 2;
            v146[3] = v147 | 2;
          }
        }
      }
    }
    else
    {
      for ( mm = 0; mm != 918; mm += 9 )
      {
        if ( (((__int64 (__fastcall *)(__int64, _QWORD))reg_is_5dot9_ghz_freq)(v73, (unsigned int)v13[mm]) & 1) != 0 )
          *(_QWORD *)&v13[mm + 2] = 0x100000000LL;
      }
    }
  }
  v75 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v14 - 56) + 36LL) + 80LL);
  if ( (((__int64 (__fastcall *)(__int64))reg_is_lower_6g_edge_ch_supp)(v75) & 1) == 0 )
  {
    v76 = v13[381];
    v13[380] = 0;
    v13[381] = v76 | 1;
  }
  if ( (((__int64 (__fastcall *)(__int64))reg_is_upper_6g_edge_ch_disabled)(v75) & 1) != 0 )
  {
    v77 = v13[912];
    v13[911] = 0;
    v13[912] = v77 | 1;
  }
  v78 = *(_QWORD *)(v14 - 56);
  ((void (__fastcall *)(_QWORD, int *))reg_update_max_bw_6ghz_chan)(*(_QWORD *)(v78 + 36), v13);
  v87 = *(_QWORD *)(*(_QWORD *)(v78 + 36) + 80LL);
  *(_DWORD *)(v14 - 48) = 4;
  if ( !v87 )
  {
    v95 = "%s: psoc is NULL";
LABEL_120:
    qdf_trace_msg(0x51u, 2u, v95, v79, v80, v81, v82, v83, v84, v85, v86, "reg_populate_secondary_cur_chan_list");
    goto LABEL_121;
  }
  v88 = ((__int64 (__fastcall *)(__int64))reg_get_psoc_obj)(v87);
  if ( !v88 )
  {
    v95 = "%s: psoc reg component is NULL";
    goto LABEL_120;
  }
  v89 = v88;
  v90 = ((__int64 (__fastcall *)(__int64))reg_get_psoc_tx_ops)(v87);
  if ( !v90 )
    goto LABEL_121;
  if ( !*(_QWORD *)(v90 + 16) || (*(_BYTE *)(v87 + 23) & 0x10) == 0 )
  {
    qdf_mem_copy(v13 + 918, v13, 0xE58u);
    goto LABEL_121;
  }
  v141 = _qdf_mem_malloc(0x870u, "reg_populate_secondary_cur_chan_list", 2210);
  if ( !v141 )
    goto LABEL_121;
  v142 = (char *)v141;
  ((void (__fastcall *)(_QWORD, __int64))reg_get_cur_6g_ap_pwr_type)(
    *(_QWORD *)(*(_QWORD *)(v14 - 56) + 36LL),
    v14 - 48);
  v143 = *(_DWORD *)(v14 - 48);
  if ( v143 )
  {
    if ( v143 == 3 )
    {
      v144 = 4375;
    }
    else
    {
      if ( v143 != 2 )
      {
        v168 = v142 + 12;
        for ( nn = 508; nn != 1228; nn += 12 )
        {
          *(v168 - 8) = *(_BYTE *)(channel_map + nn);
          v170 = *(_DWORD *)(channel_map + nn - 4);
          *(_QWORD *)(v168 - 4) = 0x100000000LL;
          *((_DWORD *)v168 - 3) = v170;
          if ( (*(_BYTE *)(v89 + 93256) & 1) == 0 )
            v168[13] = 0;
          v168 += 36;
        }
        goto LABEL_189;
      }
      v144 = 3835;
    }
  }
  else
  {
    v144 = 2755;
  }
  qdf_mem_copy(v142, &v13[v144], 0x870u);
LABEL_189:
  if ( *(_DWORD *)(v14 - 48) == 3 )
  {
    v148 = 0;
    do
    {
      v149 = &v142[v148];
      v148 += 72;
      v150 = *((_DWORD *)v149 + 12) & 0xFFFFFDFF;
      *((_DWORD *)v149 + 3) &= ~0x200u;
      *((_DWORD *)v149 + 12) = v150;
    }
    while ( v148 != 2160 );
  }
  qdf_mem_copy(v13 + 918, v13, 0x5E8u);
  qdf_mem_copy(v13 + 1296, v142, 0x870u);
  _qdf_mem_free((__int64)v142);
  v159 = *(_DWORD *)(*(_QWORD *)(v14 - 56) + 64LL);
  if ( v159 && (v159 & 4) == 0 )
    ((void (__fastcall *)(int *, int *))reg_modify_chan_list_for_band_6G)(v13, v13 + 918);
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: sta freq:state:ispsd:pwr:psd:flags(hex):",
    v151,
    v152,
    v153,
    v154,
    v155,
    v156,
    v157,
    v158,
    "reg_dump_valid_6ghz_cur_chan_list");
  ((void (__fastcall *)(int *))reg_dump_valid_6ghz_channel_list)(v13 + 378);
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: sap freq:state:ispsd:pwr:psd:flags(hex):",
    v160,
    v161,
    v162,
    v163,
    v164,
    v165,
    v166,
    v167,
    "reg_dump_valid_6ghz_cur_chan_list");
  ((void (__fastcall *)(int *))reg_dump_valid_6ghz_channel_list)(v13 + 1296);
LABEL_121:
  v99 = *(unsigned int **)(v14 - 56);
  v100 = *v99;
  if ( (_DWORD)v100 && *((_BYTE *)v99 + 4) == 1 )
  {
    for ( i1 = 0; i1 != v100; ++i1 )
    {
      v102 = &v13[9 * i1 + 13255];
      for ( i2 = 0; i2 != 918; i2 += 9 )
      {
        v104 = *v102;
        if ( *v102 == v13[i2] )
        {
          v105 = &v13[i2];
          v106 = v13[i2 + 3] | 1;
          v105[2] = 0;
          v105[3] = v106;
          v104 = *v102;
        }
        v107 = &v13[i2];
        if ( v104 == v13[i2 + 918] )
        {
          v108 = v107[921];
          v107[920] = 0;
          v107[921] = v108 | 1;
        }
      }
    }
  }
  v109 = *(_QWORD *)(v99 + 9);
  v110 = *(_QWORD *)(v109 + 80);
  if ( v110 )
  {
    v171 = *(unsigned __int16 *)(*(_QWORD *)(v14 - 56) + 1532LL);
    if ( (((__int64 (__fastcall *)(_QWORD))reg_check_coex_unsafe_chan_reg_disable)(*(_QWORD *)(v109 + 80)) & 1) != 0 )
    {
      v119 = ((__int64 (__fastcall *)(__int64))reg_get_psoc_obj)(v110);
      if ( v119 && (_DWORD)v171 && *(_BYTE *)(v119 + 93273) == 1 )
      {
        v120 = *(unsigned int *)(v119 + 93276);
        v121 = 0;
        *(_QWORD *)(v14 - 64) = v13 + 918;
        v173 = v120;
        *(_QWORD *)(v14 - 72) = (char *)v13 + 58226;
        v172 = (unsigned int *)(v119 + 93280);
        do
        {
          for ( i3 = 0; i3 != 102; ++i3 )
          {
            v124 = (unsigned int *)&v13[9 * i3];
            v125 = *(unsigned __int16 *)(*(_QWORD *)(v14 - 72) + 2 * v121);
            if ( v124[2] )
            {
              v126 = *v124;
              if ( *v124 != v125 )
              {
                if ( (((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(v126) & 1) == 0 || !(_DWORD)v173 )
                  goto LABEL_144;
                v134 = v172;
                v135 = v173;
                while ( 1 )
                {
                  v137 = *v134;
                  v136 = v134[1];
                  if ( ((((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(*v134) & 1) != 0
                     || v137 + 10 >= (unsigned int)reg_min_5ghz_chan_freq())
                    && ((((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(v136) & 1) != 0
                     || v136 - 10 <= (unsigned int)reg_max_5ghz_chan_freq())
                    && (v126 <= v137 || v126 >= v136) )
                  {
                    ((void (__fastcall *)(unsigned int *, unsigned int *))reg_modify_5g_maxbw)(v124, v134);
                    if ( *((unsigned __int16 *)v124 + 11) < 0x14u )
                      break;
                  }
                  --v135;
                  v134 += 4;
                  if ( !v135 )
                    goto LABEL_144;
                }
              }
              v127 = v124[3] | 1;
              v124[2] = 0;
              v124[3] = v127;
            }
LABEL_144:
            v128 = *(_QWORD *)(v14 - 64) + 36 * i3;
            if ( *(_DWORD *)(v128 + 8) )
            {
              v129 = *(_DWORD *)v128;
              if ( *(_DWORD *)v128 == v125 )
                goto LABEL_139;
              if ( (((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(v129) & 1) != 0 && (_DWORD)v173 )
              {
                v130 = v172;
                v131 = v173;
                while ( 1 )
                {
                  v133 = *v130;
                  v132 = v130[1];
                  if ( ((((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(*v130) & 1) != 0
                     || v133 + 10 >= (unsigned int)reg_min_5ghz_chan_freq())
                    && ((((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(v132) & 1) != 0
                     || v132 - 10 <= (unsigned int)reg_max_5ghz_chan_freq())
                    && (v129 <= v133 || v129 >= v132) )
                  {
                    ((void (__fastcall *)(__int64, unsigned int *))reg_modify_5g_maxbw)(v128, v130);
                    if ( *(unsigned __int16 *)(v128 + 22) < 0x14u )
                      break;
                  }
                  --v131;
                  v130 += 4;
                  if ( !v131 )
                    goto LABEL_140;
                }
LABEL_139:
                v123 = *(_DWORD *)(v128 + 12) | 1;
                *(_DWORD *)(v128 + 8) = 0;
                *(_DWORD *)(v128 + 12) = v123;
              }
            }
LABEL_140:
            v13 = v174;
          }
          ++v121;
        }
        while ( v121 != v171 );
      }
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: Don't disable reg channels for Coex unsafe channels",
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        "reg_modify_chan_list_for_avoid_chan_ext");
    }
  }
  v138 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v14 - 56) + 36LL) + 80LL);
  if ( (((__int64 (__fastcall *)(__int64))reg_is_lower_6g_edge_ch_supp)(v138) & 1) == 0 )
  {
    v139 = v13[1299];
    v13[1298] = 0;
    v13[1299] = v139 | 1;
  }
  result = ((__int64 (__fastcall *)(__int64))reg_is_upper_6g_edge_ch_disabled)(v138);
  if ( (result & 1) != 0 )
  {
    v140 = v13[1830];
    v13[1829] = 0;
    v13[1830] = v140 | 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
