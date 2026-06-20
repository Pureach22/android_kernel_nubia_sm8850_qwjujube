__int64 __fastcall lim_update_he_bw_cap_mcs(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x22
  int v11; // w10
  __int64 v12; // x19
  __int64 v14; // x9
  unsigned int v15; // w10
  unsigned int v16; // w12
  int v17; // w11
  int v18; // w4
  int v19; // w1
  int v20; // w11
  int v21; // w0
  int v22; // w2
  int v23; // w15
  int v24; // w13
  int v25; // w14
  int v26; // w17
  int v27; // w3
  int v28; // w0
  int v29; // w2
  int v30; // w3
  int v31; // w5
  int v32; // w16
  int v33; // w17
  int v34; // w15
  int v35; // w16
  int v36; // w3
  int v37; // w4
  int v38; // w23
  int v39; // w5
  int v40; // w7
  int v41; // w6
  int v42; // w17
  int v43; // w4
  int v44; // w17
  int v45; // w0
  int v46; // w6
  int v47; // w23
  int v48; // w7
  int v49; // w5
  unsigned int v50; // w9
  unsigned int v51; // w12
  int v52; // w14
  int v53; // w1
  int v54; // w5
  int v55; // w15
  int v56; // w3
  int v57; // w7
  int v58; // w2
  int v59; // w17
  int v60; // w5
  int v61; // w6
  __int16 v62; // w0
  int v63; // w7
  int v64; // w23
  int v65; // w25
  int v66; // w21
  int v67; // w1
  int v68; // w6
  int v69; // w24
  int v70; // w5
  int v71; // w1
  int v72; // w2
  int v73; // w7
  __int16 v74; // w8
  int v75; // w10
  int v76; // w23
  int v77; // w4
  unsigned int v78; // w5
  int v79; // w6
  unsigned int v80; // w21
  unsigned int v81; // w9
  unsigned int *v82; // x23
  const char *v83; // x2
  unsigned int v84; // w21
  unsigned __int64 v85; // x8
  __int64 v86; // x9
  bool is_24ghz_ch_freq; // w0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned __int64 v96; // x10
  unsigned __int64 v97; // x8
  int v98; // [xsp+8h] [xbp-8h]
  int v99; // [xsp+Ch] [xbp-4h]

  v10 = result + 0x2000;
  if ( *(_BYTE *)(result + 8676) == 1 )
  {
    v11 = *(_DWORD *)(result + 7036);
    v12 = result;
    v14 = *(_QWORD *)(*(_QWORD *)(result + 8608) + 8LL);
    if ( v11 )
    {
      if ( !a2 || v11 != 2 )
        goto LABEL_17;
    }
    else if ( !a2 )
    {
      goto LABEL_17;
    }
    if ( !*(_BYTE *)(a2 + 2640) || (*(_BYTE *)(a2 + 2647) & 0x10) == 0 )
      goto LABEL_17;
    v15 = *(unsigned __int16 *)(a2 + 2664);
    v16 = *(unsigned __int16 *)(v14 + 1334);
    v99 = *(unsigned __int8 *)(v14 + 3531);
    v17 = (v15 >> 1) & 1;
    v18 = v17 ^ v15 & 1;
    v19 = v17 & ~(v16 & 1 | v15 & 1);
    v20 = (v16 >> 1) & v16 & 1 | (v15 >> 1) & v15 & 1;
    v21 = (v15 >> 2) & 1;
    v22 = (v16 >> 2) & 1;
    v23 = (v15 >> 3) & 1;
    v24 = v18 & ~(v16 >> 1) & v16 | ((v16 >> 1) ^ v16) & ~(v15 >> 1) & v15 & 1 | (2 * (v19 & (v16 >> 1) | v20));
    v25 = v22 & (v16 >> 3) | v21 & (v15 >> 3);
    v26 = ((v16 >> 3) ^ (v16 >> 2)) & ~(v15 >> 3) & v21;
    v27 = v23 ^ v21;
    v28 = v22 | v21;
    v29 = v27 & ~(v16 >> 3);
    v30 = (v15 >> 4) & 1;
    v31 = (v16 >> 4) & 1;
    v32 = v29 & (v16 >> 2) | v26;
    v33 = v31 & (v16 >> 5) | v30 & (v15 >> 5);
    v34 = v32 | (2 * (v23 & ~v28 & (v16 >> 3) | v25));
    v35 = ((v15 >> 5) & 1 ^ v30) & ~(v16 >> 5) & (v16 >> 4)
        | ((v16 >> 5) ^ (v16 >> 4)) & ~(v15 >> 5) & v30
        | (2 * ((v15 >> 5) & 1 & ~(v31 | v30) & (v16 >> 5) | v33));
    v36 = (v15 >> 6) & 1;
    v37 = (v16 >> 6) & 1;
    v38 = (v16 >> 8) & 1;
    LOWORD(v35) = v35 | v33;
    v39 = v37 & (v16 >> 7) | v36 & (v15 >> 7);
    v40 = (v15 >> 8) & 1;
    v41 = v38 & (v16 >> 9) | v40 & (v15 >> 9);
    v42 = ((v15 >> 7) & 1 ^ v36) & ~(v16 >> 7) & (v16 >> 6)
        | ((v16 >> 7) ^ (v16 >> 6)) & ~(v15 >> 7) & v36
        | (2 * ((v15 >> 7) & 1 & ~(v37 | v36) & (v16 >> 7) | v39));
    v43 = (v15 >> 10) & 1;
    LOWORD(v19) = v42 | v39;
    v44 = ((v15 >> 9) & 1 ^ v40) & ~(v16 >> 9) & (v16 >> 8)
        | ((v16 >> 9) ^ (v16 >> 8)) & ~(v15 >> 9) & v40
        | (2 * ((v15 >> 9) & 1 & ~(v38 | v40) & (v16 >> 9) | v41))
        | v41;
    v45 = (v16 >> 10) & 1 & (v16 >> 11) | v43 & (v15 >> 11);
    v46 = (v16 >> 14) & (v16 >> 15) | (v15 >> 14) & (v15 >> 15);
    v47 = (v15 >> 12) & 1;
    v48 = (v16 >> 12) & 1;
    LOWORD(v29) = ((v15 >> 11) & 1 ^ v43) & ~(unsigned __int16)(v16 >> 11) & (v16 >> 10)
                | ((v16 >> 11) ^ (v16 >> 10)) & ~(unsigned __int16)(v15 >> 11) & v43
                | (2
                 * (((v15 & 0x800) != 0)
                  & (unsigned __int8)~((v16 & 0x400) != 0 || (v15 & 0x400) != 0)
                  & (*(_WORD *)(v14 + 1334) >> 11)
                  | v45));
    v49 = v48 & (v16 >> 13) | v47 & (v15 >> 13);
    if ( ((unsigned __int16)(((((v15 >> 14)
                              & 1
                              ^ (unsigned __int16)(v15 >> 15))
                             & (unsigned __int16)~(unsigned __int16)(v16 >> 15)
                             & (unsigned __int16)(v16 >> 14)
                             | ((v16 >> 14)
                              & 1
                              ^ (unsigned __int16)(v16 >> 15))
                             & (unsigned __int16)~(unsigned __int16)(v15 >> 15)
                             & (unsigned __int16)(v15 >> 14)
                             | (unsigned __int16)(2 * ((v15 >> 15) & ~((v16 >> 14) | (v15 >> 14)) & (v16 >> 15) | v46))
                             | (unsigned __int16)v46) << 14)
                           | (16 * v35)
                           | ((_WORD)v19 << 6)
                           | ((_WORD)v44 << 8)
                           | (((unsigned __int16)v29 | (unsigned __int16)v45) << 10)
                           | ((((v15 >> 13)
                              & 1
                              ^ (unsigned __int16)v47)
                             & (unsigned __int16)~(unsigned __int16)(v16 >> 13)
                             & (*(_WORD *)(v14 + 1334) >> 12)
                             | ((v16 >> 13)
                              ^ (*(_WORD *)(v14 + 1334) >> 12))
                             & (unsigned __int16)~(unsigned __int16)(v15 >> 13)
                             & (unsigned __int16)v47
                             | (unsigned __int16)(2 * ((v15 >> 13) & 1 & ~(v48 | v47) & (v16 >> 13) | v49))
                             | (unsigned __int16)v49) << 12)
                           | v24
                           | (4 * (v34 | v25))
                           | (-1LL << (2 * *(_BYTE *)(v10 + 443))))
        | v20) == 0xFFFF )
      goto LABEL_14;
    v50 = *(unsigned __int16 *)(v14 + 1332);
    v51 = *(unsigned __int16 *)(a2 + 2666);
    v52 = (v51 >> 1) & 1;
    v53 = (v51 >> 2) & 1;
    v54 = (v50 >> 2) & 1;
    v55 = v54 & (v50 >> 3) | v53 & (v51 >> 3);
    v56 = (v51 >> 4) & 1;
    v57 = (v50 >> 4) & 1;
    v58 = v57 & (v50 >> 5) | v56 & (v51 >> 5);
    v59 = ((v51 >> 3) & 1 ^ v53) & ~(v50 >> 3) & (v50 >> 2)
        | ((v50 >> 3) ^ (v50 >> 2)) & ~(v51 >> 3) & v53
        | (2 * ((v51 >> 3) & 1 & ~(v54 | v53) & (v50 >> 3) | v55));
    v60 = (v51 >> 6) & 1;
    v61 = (v50 >> 6) & 1;
    v62 = ((v51 >> 5) & 1 ^ v56) & ~(unsigned __int16)(v50 >> 5) & (v50 >> 4)
        | ((v50 >> 5) ^ (v50 >> 4)) & ~(unsigned __int16)(v51 >> 5) & v56
        | (2 * ((v51 >> 5) & 1 & ~(v57 | v56) & (v50 >> 5) | v58))
        | v58;
    v63 = v61 & (v50 >> 7) | v60 & (v51 >> 7);
    v64 = (v51 >> 8) & 1;
    v65 = (v50 >> 8) & 1;
    v66 = v65 & (v50 >> 9) | v64 & (v51 >> 9);
    v67 = ((v51 >> 7) & 1 ^ v60) & ~(v50 >> 7) & (v50 >> 6)
        | ((v50 >> 7) ^ (v50 >> 6)) & ~(v51 >> 7) & v60
        | (2 * ((v51 >> 7) & 1 & ~(v61 | v60) & (v50 >> 7) | v63));
    v68 = (v51 >> 10) & 1;
    v69 = (v50 >> 10) & 1;
    LOWORD(v56) = v67 | v63;
    v70 = (v51 >> 11) & 1;
    v71 = ((v51 >> 9) & 1 ^ v64) & ~(v50 >> 9) & (v50 >> 8)
        | ((v50 >> 9) ^ (v50 >> 8)) & ~(v51 >> 9) & v64
        | (2 * ((v51 >> 9) & 1 & ~(v65 | v64) & (v50 >> 9) | v66))
        | v66;
    v72 = v69 & (v50 >> 11) | v68 & (v51 >> 11);
    v73 = (v70 ^ v68) & ~(v50 >> 11) & (v50 >> 10) | ((v50 >> 11) ^ (v50 >> 10)) & ~(v51 >> 11) & v68;
    v98 = (v50 >> 1) & v50 & 1 | (v51 >> 1) & v51 & 1;
    v74 = -1LL << (2 * *(_BYTE *)(v10 + 443));
    v75 = (v50 >> 14) & (v50 >> 15) | (v51 >> 14) & (v51 >> 15);
    v76 = (v51 >> 12) & 1;
    v77 = v70 & ~(v69 | v68) & (v50 >> 11);
    v78 = v50 >> 13;
    v79 = (v50 >> 12) & 1;
    v80 = v51 >> 13;
    if ( ((unsigned __int16)(((((v51 >> 14)
                              & 1
                              ^ (unsigned __int16)(v51 >> 15))
                             & (unsigned __int16)~(unsigned __int16)(v50 >> 15)
                             & (unsigned __int16)(v50 >> 14)
                             | ((v50 >> 14)
                              & 1
                              ^ (unsigned __int16)(v50 >> 15))
                             & (unsigned __int16)~(unsigned __int16)(v51 >> 15)
                             & (unsigned __int16)(v51 >> 14)
                             | (unsigned __int16)(2 * ((v51 >> 15) & ~((v50 >> 14) | (v51 >> 14)) & (v50 >> 15) | v75))
                             | (unsigned __int16)v75) << 14)
                           | (16 * v62)
                           | ((_WORD)v56 << 6)
                           | ((_WORD)v71 << 8)
                           | (((unsigned __int16)(v73 | (2 * (v77 | v72))) | (unsigned __int16)v72) << 10)
                           | ((((v51 >> 13)
                              & 1
                              ^ (unsigned __int16)v76)
                             & (unsigned __int16)~(_WORD)v78
                             & (unsigned __int16)(v50 >> 12)
                             | (v78
                              ^ (unsigned __int16)(v50 >> 12))
                             & (unsigned __int16)~(_WORD)v80
                             & (unsigned __int16)v76
                             | (unsigned __int16)(2
                                                * (((v51 & 0x2000) != 0)
                                                 & (unsigned __int8)~(v79 | v76)
                                                 & (unsigned __int8)v78
                                                 | v79 & v78
                                                 | v76 & v80))
                             | (unsigned __int16)(v79 & v78 | v76 & v80)) << 12)
                           | (v52 ^ v51 & 1) & ~(unsigned __int16)(v50 >> 1) & v50
                           | ((v50 >> 1) ^ v50) & ~(unsigned __int16)(v51 >> 1) & v51 & 1
                           | (2 * (v52 & ~(v50 & 1 | v51 & 1) & (v50 >> 1) | v98))
                           | (4 * (v59 | v55))
                           | v74)
        | v98) == 0xFFFF )
    {
LABEL_14:
      if ( *(_DWORD *)(v12 + 7176) == 3 )
      {
        v83 = "%s: HE160 Rx/Tx MCS is not valid, falling back to 80MHz";
        v82 = (unsigned int *)(v12 + 7176);
        goto LABEL_16;
      }
    }
    else
    {
      v81 = *(_DWORD *)(v12 + 7176);
      v82 = (unsigned int *)(v12 + 7176);
      if ( v99 != 2 )
      {
        v84 = 0;
        if ( v81 != 3 )
          goto LABEL_22;
        goto LABEL_20;
      }
      if ( v81 == 3 )
      {
        v83 = "%s: STA preferred HE80 over HE160, falling back to 80MHz";
LABEL_16:
        qdf_trace_msg(0x35u, 8u, v83, a3, a4, a5, a6, a7, a8, a9, a10, "lim_update_he_bw_cap_mcs");
        *v82 = 2;
      }
    }
LABEL_17:
    v81 = *(_DWORD *)(v12 + 7176);
    v82 = (unsigned int *)(v12 + 7176);
    if ( v81 <= 2 )
    {
      v84 = 1;
      *(_QWORD *)(v10 + 489) &= 0xFFCFFFFFFFFFFFFFLL;
LABEL_22:
      if ( v81 )
        goto LABEL_25;
      *(_QWORD *)(v10 + 489) &= 0xFE03FFFFFFFFFFFFLL;
      v85 = 0xFF8FFFFFFFFFFFFFLL;
      v86 = 8689;
LABEL_24:
      *(_QWORD *)(v12 + v86) &= v85;
LABEL_25:
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v12 + 284));
      v96 = 0xFEBBFFFFFFFFFFFFLL;
      if ( is_24ghz_ch_freq )
        v96 = 0xFE47FFFFFFFFFFFFLL;
      v97 = *(_QWORD *)(v10 + 489) & v96;
      *(_QWORD *)(v10 + 489) = v97;
      if ( (v97 & 0x10000000000000LL) != 0 )
      {
        if ( (v97 & 0x20000000000000LL) != 0 )
          goto LABEL_29;
      }
      else
      {
        *(_QWORD *)(v10 + 497) &= 0xFF9FFFFE38FFFFFFLL;
        *(_DWORD *)(v10 + 512) = -1;
        if ( (v97 & 0x20000000000000LL) != 0 )
        {
LABEL_29:
          if ( !a2 )
            return lim_print_he_channel_widths(v12 + 8680);
LABEL_30:
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Session width %d, AP: he_cap %d wd_2 %d is_80 %d",
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            v94,
            v95,
            "lim_update_he_bw_cap_mcs",
            *v82,
            *(unsigned __int8 *)(a2 + 2640),
            (*(_QWORD *)(a2 + 2641) >> 52) & 1LL,
            v84);
          return lim_print_he_channel_widths(v12 + 8680);
        }
      }
      *(_DWORD *)(v10 + 516) = -1;
      if ( !a2 )
        return lim_print_he_channel_widths(v12 + 8680);
      goto LABEL_30;
    }
    v84 = 1;
    if ( v81 != 3 )
      goto LABEL_22;
LABEL_20:
    v85 = 0xFFDFFFFFFFFFFFFFLL;
    v86 = 8681;
    goto LABEL_24;
  }
  return result;
}
