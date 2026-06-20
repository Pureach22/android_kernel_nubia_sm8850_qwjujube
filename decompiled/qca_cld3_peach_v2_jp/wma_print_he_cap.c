__int64 __fastcall wma_print_he_cap(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w8
  __int64 v10; // x19
  unsigned int v11; // w8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned __int64 v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned __int64 v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned __int64 v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned __int64 v73; // x8
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned __int64 v82; // x8
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  unsigned __int64 v91; // x8
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned int v124; // t1
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  __int64 v133; // [xsp+0h] [xbp-20h]
  __int64 v134; // [xsp+0h] [xbp-20h]
  __int64 v135; // [xsp+0h] [xbp-20h]
  __int64 v136; // [xsp+0h] [xbp-20h]
  __int64 v137; // [xsp+0h] [xbp-20h]
  __int64 v138; // [xsp+0h] [xbp-20h]
  __int64 v139; // [xsp+0h] [xbp-20h]
  __int64 v140; // [xsp+0h] [xbp-20h]
  __int64 v141; // [xsp+0h] [xbp-20h]
  __int64 v142; // [xsp+0h] [xbp-20h]
  __int64 v143; // [xsp+8h] [xbp-18h]
  __int64 v144; // [xsp+8h] [xbp-18h]
  __int64 v145; // [xsp+8h] [xbp-18h]
  __int64 v146; // [xsp+8h] [xbp-18h]
  __int64 v147; // [xsp+8h] [xbp-18h]
  __int64 v148; // [xsp+8h] [xbp-18h]
  __int64 v149; // [xsp+10h] [xbp-10h]

  if ( *(_BYTE *)result )
  {
    v9 = *(_DWORD *)(result + 1);
    v10 = result;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: HE Cap: HTC-HE 0x%01x, TWT: Reqstor 0x%01x Respder 0x%01x, Frag 0x%02x, Max MSDUs 0x%03x, Min frag 0x%02x, Tri"
      "gg MAC pad duration 0x%02x",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wma_print_he_cap",
      v9 & 1,
      (v9 >> 1) & 1,
      (v9 >> 2) & 1,
      (v9 >> 3) & 3,
      (unsigned __int8)v9 >> 5,
      (v9 >> 8) & 3,
      (v9 >> 10) & 3);
    v11 = *(_DWORD *)(v10 + 1);
    LODWORD(v133) = (v11 >> 20) & 1;
    LODWORD(v143) = (v11 >> 21) & 1;
    qdf_trace_msg(
      0x36u,
      8u,
      " Multi-TID aggr RX 0x%03x, Link adapt 0x%02x, All ACK 0x%01x, Trigg resp sched 0x%01x, A-Buff status rpt 0x%01x, B"
      "C TWT 0x%01x, 32bit BA 0x%01x",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      (v11 >> 12) & 7,
      (v11 >> 15) & 3,
      (v11 >> 17) & 1,
      (v11 >> 18) & 1,
      (v11 >> 19) & 1,
      v133,
      v143);
    v20 = *(_DWORD *)(v10 + 1);
    LODWORD(v134) = (v20 >> 29) & 1;
    LODWORD(v144) = (v20 >> 30) & 1;
    qdf_trace_msg(
      0x36u,
      8u,
      " MU Cascading 0x%01x, ACK enabled Multi-TID 0x%01x, OMI A-Cntrl 0x%01x, OFDMA RA 0x%01x, Max A-MPDU 0x%02x, A-MSDU"
      " Frag 0x%01x, Flex TWT sched 0x%01x",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      (v20 >> 22) & 1,
      (v20 >> 23) & 1,
      (v20 >> 25) & 1,
      (v20 >> 26) & 1,
      (v20 >> 27) & 3,
      v134,
      v144);
    v29 = *(_QWORD *)(v10 + 1);
    LODWORD(v135) = (v29 >> 36) & 1;
    LODWORD(v145) = (v29 >> 37) & 1;
    qdf_trace_msg(
      0x36u,
      8u,
      " Rx Ctrl frame MBSS 0x%01x, BSRP A-MPDU Aggr 0x%01x, Quite Time Period 0x%01x, A-BQR 0x%01x, SR Respder 0x%01x, nd"
      "p FB 0x%01x, ops supp 0x%01x",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      (v29 >> 31) & 1,
      HIDWORD(v29) & 1,
      (v29 >> 33) & 1,
      (v29 >> 34) & 1,
      (v29 >> 35) & 1,
      v135,
      v145);
    v38 = *(_QWORD *)(v10 + 1);
    LODWORD(v136) = (v38 >> 46) & 1;
    qdf_trace_msg(
      0x36u,
      8u,
      " Amsdu in ampdu 0x%01x, Multi-TID aggr 0x%03x, sub ch sel tx 0x%01x, UL 2x996tone RU 0x%01x, OM ctrl ULMU dis rx 0"
      "x%01x, DSMPS 0x%01x",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      (v38 >> 38) & 1,
      (v38 >> 40) & 7,
      (v38 >> 43) & 1,
      (v38 >> 44) & 1,
      (v38 >> 45) & 1,
      v136);
    v47 = *(_QWORD *)(v10 + 1);
    LODWORD(v137) = (v47 & 0x4000000000000000LL) != 0;
    qdf_trace_msg(
      0x36u,
      8u,
      " Punctured sounding 0x%01x, HTVHT Trigg frame Rx 0x%01x, Chan width 0x%07x, Preamble punct Rx 0x%04x, device class"
      " 0x%01x, LDPC 0x%01x",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      (v47 >> 47) & 1,
      HIWORD(v47) & 1,
      (v47 >> 50) & 0x7F,
      (v47 >> 57) & 0xF,
      (v47 >> 61) & 1,
      v137);
    qdf_trace_msg(
      0x36u,
      8u,
      " LTF and GI for HE PPDUs 0x%02x, Midamble Tx Rx MAX NSTS 0x%02x, LTF and GI for NDP 0x%02x, TB PPDU STBC Tx suppor"
      "t LE 80MHz 0x%01x",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      *(_QWORD *)(v10 + 1) >> 63,
      *(_DWORD *)(v10 + 9) & 3,
      (*(_DWORD *)(v10 + 9) >> 2) & 1,
      (*(_DWORD *)(v10 + 9) >> 3) & 1);
    v64 = *(_DWORD *)(v10 + 9);
    LODWORD(v138) = (v64 >> 15) & 1;
    qdf_trace_msg(
      0x36u,
      8u,
      " STBC Rx support LE 80Mhz 0x%01x, Doppler 0x%02x, UL MU: 0x%02x, DCM encoding: Tx 0x%03x Rx 0x%03x, HE MU PPDU payload 0x%01x",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      (v64 >> 4) & 1,
      (v64 >> 5) & 3,
      (v64 >> 7) & 3,
      (v64 >> 9) & 7,
      (v64 >> 12) & 7,
      v138);
    v73 = *(_QWORD *)(v10 + 9);
    LODWORD(v139) = ((unsigned int)v73 >> 27) & 7;
    LODWORD(v146) = (v73 >> 30) & 7;
    qdf_trace_msg(
      0x36u,
      8u,
      " SU: Bfer 0x%01x Bfee 0x%01x, MU Bfer 0x%01x, Bfee STS:  LE 80Mhz 0x%03x GT 80Mhz 0x%03x, No. of sounding dim: LE "
      "80Mhz 0x%03x GT 80Mhz 0x%03x",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      WORD1(v73) & 1,
      ((unsigned int)v73 >> 17) & 1,
      ((unsigned int)v73 >> 18) & 1,
      ((unsigned int)v73 >> 19) & 7,
      BYTE3(v73) & 7,
      v139,
      v146);
    v82 = *(_QWORD *)(v10 + 9);
    LODWORD(v140) = (v82 >> 40) & 1;
    qdf_trace_msg(
      0x36u,
      8u,
      " Ng=16 FB: SU 0x%01x MU 0x%01x, Codebook size: SU 0x%01x MU 0x%01x, Bfing trigger w/ Trigger 0x%01x, ER SU PPDU payload 0x%01x",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      (v82 >> 33) & 1,
      (v82 >> 34) & 1,
      (v82 >> 35) & 1,
      (v82 >> 36) & 1,
      (v82 >> 37) & 7,
      v140);
    v91 = *(_QWORD *)(v10 + 9);
    LODWORD(v141) = (v91 >> 46) & 7;
    LODWORD(v147) = (v91 >> 49) & 1;
    qdf_trace_msg(
      0x36u,
      8u,
      " DL MUMIMO on partial BW: 0x%01x, PPET 0x%01x, SRP 0x%01x, Power boost 0x%01x, 4x HE LTF 0x%01x, Max NC 0x%01x, TB"
      " PPDU stbc Tx GT 80Mhz 0x%01x",
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      (v91 >> 41) & 1,
      (v91 >> 42) & 1,
      (v91 >> 43) & 1,
      (v91 >> 44) & 1,
      (v91 >> 45) & 1,
      v141,
      v147);
    qdf_trace_msg(
      0x36u,
      8u,
      " STBC Rx GT 80Mhz 0x%01x, er ltf 800 gt 4x 0x%01x, ppdu 20: 40Mhz 2G 0x%01x 160_80p80Mhz 0x%01x, ppdu 80 160_80p80Mhz 0x%01x",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      (*(_QWORD *)(v10 + 9) >> 50) & 1LL,
      (*(_QWORD *)(v10 + 9) >> 51) & 1LL,
      (*(_QWORD *)(v10 + 9) >> 52) & 1LL,
      (*(_QWORD *)(v10 + 9) >> 53) & 1LL,
      (*(_QWORD *)(v10 + 9) >> 54) & 1LL);
    qdf_trace_msg(
      0x36u,
      8u,
      " ER 1X LTF GI 0x%01x, midamble tx/rx 1x LTF 0x%01x, DCM max BW 0x%02x, LT 16 sigb ofdm sym 0x%01x, non-trig cqi fb 0x%01x",
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      (*(_QWORD *)(v10 + 9) >> 55) & 1LL,
      HIBYTE(*(_QWORD *)(v10 + 9)) & 1LL,
      (*(_QWORD *)(v10 + 9) >> 57) & 3LL,
      (*(_QWORD *)(v10 + 9) >> 59) & 1LL,
      (*(_QWORD *)(v10 + 9) >> 60) & 1LL);
    qdf_trace_msg(
      0x36u,
      8u,
      " 1024 QAM LT 242 tone ru: Tx 0x%01x RX 0x%01x, RX full BW SU MU SIGB: Compress 0x%01x non compress 0x%01x",
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      (*(_QWORD *)(v10 + 9) >> 61) & 1LL,
      (*(_QWORD *)(v10 + 9) >> 62) & 1LL,
      *(_QWORD *)(v10 + 9) >> 63,
      *(_BYTE *)(v10 + 17) & 1);
    v124 = *(unsigned __int8 *)(v10 + 33);
    v10 += 33;
    LODWORD(v149) = (v124 >> 3) & 0xF;
    LODWORD(v148) = (v124 & 7) + 1;
    LODWORD(v142) = *(unsigned __int16 *)(v10 - 3);
    qdf_trace_msg(
      0x36u,
      8u,
      " RX MCS: LE 80MHz 0x%x 160MHz 0x%x 80+80MHz 0x%x, TX MCS: LE 80MHz 0x%x 160MHz 0x%x 80+80MHz 0x%x, NSS %d, RU inde"
      "x 0x%04x, num ppet %d",
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      *(unsigned __int16 *)(v10 - 13),
      *(unsigned __int16 *)(v10 - 9),
      *(unsigned __int16 *)(v10 - 5),
      *(unsigned __int16 *)(v10 - 11),
      *(unsigned __int16 *)(v10 - 7),
      v142,
      v148,
      v149,
      *(unsigned __int8 *)(v10 - 1));
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
             54,
             8,
             v10,
             *(unsigned __int8 *)(v10 - 1));
  }
  return result;
}
