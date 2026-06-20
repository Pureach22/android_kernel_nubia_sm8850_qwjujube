// positive sp value has been detected, the output may be wrong!
__int64 __usercall htc_flush_endpoint@<X0>(
        __int64 a1@<X0>,
        unsigned int a2@<W1>,
        __int64 a3@<X3>,
        __int64 a4@<X4>,
        __int64 a5@<X8>)
{
  char *v5; // x9
  _DWORD *v6; // x28
  __int64 v7; // x29
  __int64 v8; // x8
  __int64 result; // x0
  int v10; // w10
  __int64 j; // x8
  _DWORD *v12; // x10
  int v13; // w11
  __int64 v14; // x19
  unsigned __int16 *v15; // x8
  unsigned int v16; // w20
  unsigned int chan_enum_for_freq; // w0
  __int64 i; // x19
  unsigned int *v19; // x22
  unsigned int v20; // w8
  char v21; // w0
  _DWORD *v22; // x10
  unsigned int *v23; // x10
  int v24; // w11
  int v25; // t1
  __int64 v26; // x19
  unsigned __int16 *v27; // x8
  unsigned int v28; // w20
  unsigned int v29; // w0
  _DWORD *v30; // x10
  unsigned int *v31; // x10
  int v32; // w11
  int v33; // t1
  __int64 v34; // x19
  unsigned __int16 *v35; // x8
  unsigned int v36; // w20
  unsigned int v37; // w0
  _DWORD *v38; // x10
  unsigned int *v39; // x10
  int v40; // w11
  int v41; // t1
  unsigned __int16 *v42; // x19
  int v43; // w8
  __int64 v44; // x8
  int *v45; // x8
  int v46; // w8
  __int64 v47; // x8
  int v48; // w5
  __int64 v49; // x20
  __int64 v50; // x20
  __int64 v51; // x21
  __int64 v52; // x20
  int v53; // w8
  int v54; // w8
  __int64 v55; // x19
  __int64 v56; // x20
  __int64 v57; // x0
  __int64 v58; // x19
  __int64 v59; // x0
  __int64 k; // x8
  _DWORD *v61; // x10
  int v62; // w11
  __int64 ii; // x19
  __int64 m; // x19
  unsigned int *v65; // x22
  unsigned int v66; // w8
  unsigned int *v67; // x17
  __int64 v68; // x8
  __int64 kk; // x9
  int *v70; // x12
  __int64 mm; // x13
  int v72; // w14
  _DWORD *v73; // x14
  int v74; // w15
  _DWORD *v75; // x15
  int v76; // w14
  __int64 v77; // x8
  __int64 v78; // x20
  __int64 v79; // x0
  __int64 v80; // x10
  __int64 v81; // x25
  __int64 nn; // x27
  int v83; // w8
  unsigned int *v84; // x20
  int v85; // w26
  unsigned int v86; // w21
  int v87; // w8
  __int64 v88; // x20
  unsigned int v89; // w21
  unsigned int *v90; // x22
  __int64 v91; // x26
  unsigned int v92; // w23
  unsigned int v93; // w24
  unsigned int *v94; // x22
  __int64 v95; // x28
  unsigned int v96; // w23
  unsigned int v97; // w24
  __int64 v98; // x20
  int v99; // w8
  int v100; // w8
  __int64 v101; // x0
  __int64 v102; // x20
  int v103; // w8
  int v104; // w8
  __int64 n; // x19
  unsigned int *v106; // x22
  unsigned int v107; // w8
  __int64 v108; // x8
  __int64 v109; // x9
  unsigned int v110; // w11
  int v111; // w8
  __int64 v112; // x9
  __int64 jj; // x10
  int v114; // w13
  __int64 v115; // [xsp-B8h] [xbp-C8h]
  unsigned int *v116; // [xsp-B0h] [xbp-C0h]
  __int64 v117; // [xsp-A8h] [xbp-B8h]
  _DWORD *v118; // [xsp-A0h] [xbp-B0h]

  if ( a2 < 0xA )
  {
    v8 = a1 + 328LL * a2;
    if ( *(_WORD *)(v8 + 12) )
      return htc_flush_endpoint_tx(a1, v8 + 8);
    else
      return printk(&unk_94DB9D, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", 2882, "false");
  }
  __break(0x5512u);
  if ( !a3 )
    JUMPOUT(0x17FEA4);
  while ( 1 )
  {
    if ( v5[30] )
    {
      v10 = *((_DWORD *)v5 + 3) | 1;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = v10;
    }
    a5 += 36;
    if ( a5 == 3672 )
      break;
    v5 = (char *)v6 + a5;
  }
  if ( (*(_BYTE *)(a4 + 68) & 1) == 0 )
  {
    for ( i = 0; i != 918; i += 9 )
    {
      v19 = &v6[i];
      v20 = v6[i + 3];
      if ( (v20 & 0x201) == 0x200 )
      {
        if ( *(_BYTE *)(a4 + 2253) == 1 )
        {
          v21 = ((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(*v19);
          a4 = *(_QWORD *)(v7 - 56);
          if ( (v21 & 1) != 0 )
            continue;
          v20 = v19[3];
        }
        v6[i + 2] = 2;
        v19[3] = v20 | 2;
      }
    }
  }
  if ( *(_BYTE *)(a4 + 764) == 1 && *(_BYTE *)(a4 + 765) == 1 )
  {
    for ( j = 0; j != 918; j += 9 )
    {
      v12 = &v6[j];
      v13 = v6[j + 3];
      if ( (v13 & 0x201) == 0x200 )
      {
        v12[2] = 0;
        v12[3] = v13 | 1;
      }
    }
  }
  if ( (*(_BYTE *)(a4 + 68) & 1) == 0 && (*(_BYTE *)(a4 + 2253) & 1) == 0 && *(_BYTE *)(a4 + 2252) == 1 )
  {
    if ( *(_DWORD *)(a4 + 2272) || *(unsigned __int8 *)(a4 + 2268) != 255 )
    {
      v14 = a4 + 2276;
      v15 = *(unsigned __int16 **)(a4 + 2276);
      if ( v15 )
      {
        v16 = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*v15);
        chan_enum_for_freq = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*(unsigned __int16 *)(*(_QWORD *)v14 + 2LL));
      }
      else
      {
        chan_enum_for_freq = reg_get_chan_enum_for_freq();
        v16 = chan_enum_for_freq;
      }
      a4 = *(_QWORD *)(v7 - 56);
      if ( v16 != 102 && chan_enum_for_freq != 102 && v16 <= chan_enum_for_freq )
      {
        do
        {
          v22 = &v6[9 * v16];
          v25 = v22[3];
          v23 = v22 + 3;
          v24 = v25;
          if ( (v25 & 0x201) == 0x200 )
            *v23 = v24 & 0xFFFFFFFC;
          ++v16;
        }
        while ( v16 <= chan_enum_for_freq );
      }
    }
    if ( *(_DWORD *)(a4 + 2288) || *(unsigned __int8 *)(a4 + 2284) != 255 )
    {
      v26 = a4 + 2292;
      v27 = *(unsigned __int16 **)(a4 + 2292);
      if ( v27 )
      {
        v28 = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*v27);
        v29 = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*(unsigned __int16 *)(*(_QWORD *)v26 + 2LL));
      }
      else
      {
        v29 = reg_get_chan_enum_for_freq();
        v28 = v29;
      }
      a4 = *(_QWORD *)(v7 - 56);
      if ( v28 != 102 && v29 != 102 && v28 <= v29 )
      {
        do
        {
          v30 = &v6[9 * v28];
          v33 = v30[3];
          v31 = v30 + 3;
          v32 = v33;
          if ( (v33 & 0x201) == 0x200 )
            *v31 = v32 & 0xFFFFFFFC;
          ++v28;
        }
        while ( v28 <= v29 );
      }
    }
    if ( *(_DWORD *)(a4 + 2304) || *(unsigned __int8 *)(a4 + 2300) != 255 )
    {
      v34 = a4 + 2308;
      v35 = *(unsigned __int16 **)(a4 + 2308);
      if ( v35 )
      {
        v36 = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*v35);
        v37 = ((__int64 (__fastcall *)(_QWORD))reg_get_chan_enum_for_freq)(*(unsigned __int16 *)(*(_QWORD *)v34 + 2LL));
      }
      else
      {
        v37 = reg_get_chan_enum_for_freq();
        v36 = v37;
      }
      a4 = *(_QWORD *)(v7 - 56);
      if ( v36 != 102 && v37 != 102 && v36 <= v37 )
      {
        do
        {
          v38 = &v6[9 * v36];
          v41 = v38[3];
          v39 = v38 + 3;
          v40 = v41;
          if ( (v41 & 0x201) == 0x200 )
            *v39 = v40 & 0xFFFFFFFC;
          ++v36;
        }
        while ( v36 <= v37 );
      }
    }
  }
  if ( v6 && (*(_BYTE *)(a4 + 61) & 1) != 0 )
  {
    v42 = (unsigned __int16 *)(a4 + 2254);
    if ( v6 != (_DWORD *)-396LL )
    {
      v43 = v6[99];
      if ( v43 == *v42 )
      {
        v44 = 0;
        goto LABEL_71;
      }
      if ( v43 == *(unsigned __int16 *)(a4 + 2258) )
      {
        v44 = 1;
LABEL_71:
        v6[103] = LOBYTE(v42[2 * v44 + 1]);
        v45 = v6 + 108;
        if ( v6 == (_DWORD *)-432LL )
          goto LABEL_79;
LABEL_74:
        v46 = *v45;
        if ( v46 == *v42 )
        {
          v47 = 0;
LABEL_78:
          v48 = LOBYTE(v42[2 * v47 + 1]);
          v6[112] = v48;
LABEL_80:
          qdf_trace_msg(
            81,
            8,
            "%s: Channel 12 tx_power = %d, 13 tx_power = %d",
            "reg_modify_chan_list_for_fcc_channel",
            v6[103],
            v48);
          a4 = *(_QWORD *)(v7 - 56);
          goto LABEL_81;
        }
        if ( v46 == *(unsigned __int16 *)(a4 + 2258) )
        {
          v47 = 1;
          goto LABEL_78;
        }
LABEL_79:
        v6[112] = 2;
        qdf_trace_msg(81, 8, "%s: Channel 13 not found from BDF", "reg_modify_chan_list_for_fcc_channel");
        v48 = v6[112];
        goto LABEL_80;
      }
    }
    v6[103] = 8;
    qdf_trace_msg(81, 8, "%s: Channel 12 not found from BDF", "reg_modify_chan_list_for_fcc_channel");
    a4 = *(_QWORD *)(v7 - 56);
    v45 = v6 + 108;
    if ( v6 == (_DWORD *)-432LL )
      goto LABEL_79;
    goto LABEL_74;
  }
LABEL_81:
  if ( (*(_BYTE *)(a4 + 69) & 1) == 0 )
  {
    for ( k = 0; k != 918; k += 9 )
    {
      if ( v6[k] == 5720 )
      {
        v61 = &v6[k];
        v62 = v6[k + 3] | 1;
        v61[2] = 0;
        v61[3] = v62;
      }
    }
  }
  v49 = *(_QWORD *)(a4 + 36);
  if ( (((__int64 (__fastcall *)(__int64))reg_is_etsi_regdmn)(v49) & 1) != 0
    && (((__int64 (__fastcall *)(__int64))reg_is_etsi_srd_chan_allowed_master_mode)(v49) & 1) == 0 )
  {
    for ( m = 0; m != 918; m += 9 )
    {
      v65 = &v6[m];
      if ( (v6[m + 3] & 1) == 0
        && (((__int64 (__fastcall *)(__int64, _QWORD))reg_is_etsi_srd_chan_for_freq)(v49, *v65) & 1) != 0 )
      {
        v66 = v65[3];
        v6[m + 2] = 2;
        v65[3] = v66 | 2;
      }
    }
  }
  v50 = *(_QWORD *)(*(_QWORD *)(v7 - 56) + 36LL);
  v51 = *(_QWORD *)(v50 + 80);
  if ( (((__int64 (__fastcall *)(__int64))reg_is_fcc_regdmn)(v50) & 1) != 0 )
  {
    if ( (((__int64 (__fastcall *)(__int64))reg_is_5dot9_ghz_supported)(v51) & 1) != 0
      && (((__int64 (__fastcall *)(__int64))reg_is_regdb_offloaded)(v51) & 1) != 0 )
    {
      if ( (((__int64 (__fastcall *)(__int64))reg_is_5dot9_ghz_chan_allowed_master_mode)(v50) & 1) == 0 )
      {
        for ( n = 0; n != 918; n += 9 )
        {
          v106 = &v6[n];
          if ( (v6[n + 3] & 1) == 0
            && (((__int64 (__fastcall *)(__int64, _QWORD))reg_is_5dot9_ghz_freq)(v50, *v106) & 1) != 0 )
          {
            v107 = v106[3];
            v6[n + 2] = 2;
            v106[3] = v107 | 2;
          }
        }
      }
    }
    else
    {
      for ( ii = 0; ii != 918; ii += 9 )
      {
        if ( (((__int64 (__fastcall *)(__int64, _QWORD))reg_is_5dot9_ghz_freq)(v50, (unsigned int)v6[ii]) & 1) != 0 )
          *(_QWORD *)&v6[ii + 2] = 0x100000000LL;
      }
    }
  }
  v52 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v7 - 56) + 36LL) + 80LL);
  if ( (((__int64 (__fastcall *)(__int64))reg_is_lower_6g_edge_ch_supp)(v52) & 1) == 0 )
  {
    v53 = v6[381];
    v6[380] = 0;
    v6[381] = v53 | 1;
  }
  if ( (((__int64 (__fastcall *)(__int64))reg_is_upper_6g_edge_ch_disabled)(v52) & 1) != 0 )
  {
    v54 = v6[912];
    v6[911] = 0;
    v6[912] = v54 | 1;
  }
  v55 = *(_QWORD *)(v7 - 56);
  ((void (__fastcall *)(_QWORD, _DWORD *))reg_update_max_bw_6ghz_chan)(*(_QWORD *)(v55 + 36), v6);
  v56 = *(_QWORD *)(*(_QWORD *)(v55 + 36) + 80LL);
  *(_DWORD *)(v7 - 48) = 4;
  if ( !v56 )
  {
    qdf_trace_msg(81, 2, "%s: psoc is NULL", "reg_populate_secondary_cur_chan_list");
    goto LABEL_113;
  }
  v57 = ((__int64 (__fastcall *)(__int64))reg_get_psoc_obj)(v56);
  if ( !v57 )
  {
    qdf_trace_msg(81, 2, "%s: psoc reg component is NULL", "reg_populate_secondary_cur_chan_list");
    goto LABEL_113;
  }
  v58 = v57;
  v59 = ((__int64 (__fastcall *)(__int64))reg_get_psoc_tx_ops)(v56);
  if ( v59 )
  {
    if ( !*(_QWORD *)(v59 + 16) || (*(_BYTE *)(v56 + 23) & 0x10) == 0 )
    {
      qdf_mem_copy((_DWORD)v6 + 3672, (int)v6, 0xE58u);
      goto LABEL_113;
    }
    v101 = _qdf_mem_malloc(2160, "reg_populate_secondary_cur_chan_list", 2210);
    if ( !v101 )
      goto LABEL_113;
    v102 = v101;
    ((void (__fastcall *)(_QWORD, __int64))reg_get_cur_6g_ap_pwr_type)(
      *(_QWORD *)(*(_QWORD *)(v7 - 56) + 36LL),
      v7 - 48);
    v103 = *(_DWORD *)(v7 - 48);
    if ( v103 )
    {
      if ( v103 == 3 )
      {
        v104 = 17500;
      }
      else
      {
        if ( v103 != 2 )
        {
          v112 = v102 + 12;
          for ( jj = 508; jj != 1228; jj += 12 )
          {
            *(_BYTE *)(v112 - 8) = *(_BYTE *)(channel_map + jj);
            v114 = *(_DWORD *)(channel_map + jj - 4);
            *(_QWORD *)(v112 - 4) = 0x100000000LL;
            *(_DWORD *)(v112 - 12) = v114;
            if ( (*(_BYTE *)(v58 + 93256) & 1) == 0 )
              *(_BYTE *)(v112 + 13) = 0;
            v112 += 36;
          }
          goto LABEL_181;
        }
        v104 = 15340;
      }
    }
    else
    {
      v104 = 11020;
    }
    qdf_mem_copy(v102, (_DWORD)v6 + v104, 0x870u);
LABEL_181:
    if ( *(_DWORD *)(v7 - 48) == 3 )
    {
      v108 = 0;
      do
      {
        v109 = v102 + v108;
        v108 += 72;
        v110 = *(_DWORD *)(v109 + 48) & 0xFFFFFDFF;
        *(_DWORD *)(v109 + 12) &= ~0x200u;
        *(_DWORD *)(v109 + 48) = v110;
      }
      while ( v108 != 2160 );
    }
    qdf_mem_copy((_DWORD)v6 + 3672, (int)v6, 0x5E8u);
    qdf_mem_copy((_DWORD)v6 + 5184, v102, 0x870u);
    _qdf_mem_free(v102);
    v111 = *(_DWORD *)(*(_QWORD *)(v7 - 56) + 64LL);
    if ( v111 && (v111 & 4) == 0 )
      ((void (__fastcall *)(_DWORD *, _DWORD *))reg_modify_chan_list_for_band_6G)(v6, v6 + 918);
    qdf_trace_msg(81, 8, "%s: sta freq:state:ispsd:pwr:psd:flags(hex):", "reg_dump_valid_6ghz_cur_chan_list");
    ((void (__fastcall *)(_DWORD *))reg_dump_valid_6ghz_channel_list)(v6 + 378);
    qdf_trace_msg(81, 8, "%s: sap freq:state:ispsd:pwr:psd:flags(hex):", "reg_dump_valid_6ghz_cur_chan_list");
    ((void (__fastcall *)(_DWORD *))reg_dump_valid_6ghz_channel_list)(v6 + 1296);
  }
LABEL_113:
  v67 = *(unsigned int **)(v7 - 56);
  v68 = *v67;
  if ( (_DWORD)v68 && *((_BYTE *)v67 + 4) == 1 )
  {
    for ( kk = 0; kk != v68; ++kk )
    {
      v70 = &v6[9 * kk + 13255];
      for ( mm = 0; mm != 918; mm += 9 )
      {
        v72 = *v70;
        if ( *v70 == v6[mm] )
        {
          v73 = &v6[mm];
          v74 = v6[mm + 3] | 1;
          v73[2] = 0;
          v73[3] = v74;
          v72 = *v70;
        }
        v75 = &v6[mm];
        if ( v72 == v6[mm + 918] )
        {
          v76 = v75[921];
          v75[920] = 0;
          v75[921] = v76 | 1;
        }
      }
    }
  }
  v77 = *(_QWORD *)(v67 + 9);
  v78 = *(_QWORD *)(v77 + 80);
  if ( v78 )
  {
    v115 = *(unsigned __int16 *)(*(_QWORD *)(v7 - 56) + 1532LL);
    if ( (((__int64 (__fastcall *)(_QWORD))reg_check_coex_unsafe_chan_reg_disable)(*(_QWORD *)(v77 + 80)) & 1) != 0 )
    {
      v79 = ((__int64 (__fastcall *)(__int64))reg_get_psoc_obj)(v78);
      if ( v79 && (_DWORD)v115 && *(_BYTE *)(v79 + 93273) == 1 )
      {
        v80 = *(unsigned int *)(v79 + 93276);
        v81 = 0;
        *(_QWORD *)(v7 - 64) = v6 + 918;
        v117 = v80;
        *(_QWORD *)(v7 - 72) = (char *)v6 + 58226;
        v116 = (unsigned int *)(v79 + 93280);
        do
        {
          for ( nn = 0; nn != 102; ++nn )
          {
            v84 = &v6[9 * nn];
            v85 = *(unsigned __int16 *)(*(_QWORD *)(v7 - 72) + 2 * v81);
            if ( v84[2] )
            {
              v86 = *v84;
              if ( *v84 != v85 )
              {
                if ( (((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(v86) & 1) == 0 || !(_DWORD)v117 )
                  goto LABEL_136;
                v94 = v116;
                v95 = v117;
                while ( 1 )
                {
                  v97 = *v94;
                  v96 = v94[1];
                  if ( ((((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(*v94) & 1) != 0
                     || v97 + 10 >= (unsigned int)reg_min_5ghz_chan_freq())
                    && ((((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(v96) & 1) != 0
                     || v96 - 10 <= (unsigned int)reg_max_5ghz_chan_freq())
                    && (v86 <= v97 || v86 >= v96) )
                  {
                    ((void (__fastcall *)(unsigned int *, unsigned int *))reg_modify_5g_maxbw)(v84, v94);
                    if ( *((unsigned __int16 *)v84 + 11) < 0x14u )
                      break;
                  }
                  --v95;
                  v94 += 4;
                  if ( !v95 )
                    goto LABEL_136;
                }
              }
              v87 = v84[3] | 1;
              v84[2] = 0;
              v84[3] = v87;
            }
LABEL_136:
            v88 = *(_QWORD *)(v7 - 64) + 36 * nn;
            if ( *(_DWORD *)(v88 + 8) )
            {
              v89 = *(_DWORD *)v88;
              if ( *(_DWORD *)v88 == v85 )
                goto LABEL_131;
              if ( (((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(v89) & 1) != 0 && (_DWORD)v117 )
              {
                v90 = v116;
                v91 = v117;
                while ( 1 )
                {
                  v93 = *v90;
                  v92 = v90[1];
                  if ( ((((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(*v90) & 1) != 0
                     || v93 + 10 >= (unsigned int)reg_min_5ghz_chan_freq())
                    && ((((__int64 (__fastcall *)(_QWORD))reg_is_5ghz_ch_freq)(v92) & 1) != 0
                     || v92 - 10 <= (unsigned int)reg_max_5ghz_chan_freq())
                    && (v89 <= v93 || v89 >= v92) )
                  {
                    ((void (__fastcall *)(__int64, unsigned int *))reg_modify_5g_maxbw)(v88, v90);
                    if ( *(unsigned __int16 *)(v88 + 22) < 0x14u )
                      break;
                  }
                  --v91;
                  v90 += 4;
                  if ( !v91 )
                    goto LABEL_132;
                }
LABEL_131:
                v83 = *(_DWORD *)(v88 + 12) | 1;
                *(_DWORD *)(v88 + 8) = 0;
                *(_DWORD *)(v88 + 12) = v83;
              }
            }
LABEL_132:
            v6 = v118;
          }
          ++v81;
        }
        while ( v81 != v115 );
      }
    }
    else
    {
      qdf_trace_msg(
        81,
        8,
        "%s: Don't disable reg channels for Coex unsafe channels",
        "reg_modify_chan_list_for_avoid_chan_ext");
    }
  }
  v98 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v7 - 56) + 36LL) + 80LL);
  if ( (((__int64 (__fastcall *)(__int64))reg_is_lower_6g_edge_ch_supp)(v98) & 1) == 0 )
  {
    v99 = v6[1299];
    v6[1298] = 0;
    v6[1299] = v99 | 1;
  }
  result = ((__int64 (__fastcall *)(__int64))reg_is_upper_6g_edge_ch_disabled)(v98);
  if ( (result & 1) != 0 )
  {
    v100 = v6[1830];
    v6[1829] = 0;
    v6[1830] = v100 | 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
