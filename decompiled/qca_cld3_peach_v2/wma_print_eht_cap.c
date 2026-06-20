__int64 __fastcall wma_print_eht_cap(
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
  unsigned __int64 v20; // x8
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
  unsigned int v47; // w9
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned __int64 v65; // x8
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w9
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned __int64 v83; // x8
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // [xsp+0h] [xbp-40h]
  __int64 v93; // [xsp+0h] [xbp-40h]
  __int64 v94; // [xsp+0h] [xbp-40h]
  __int64 v95; // [xsp+0h] [xbp-40h]
  __int64 v96; // [xsp+0h] [xbp-40h]
  __int64 v97; // [xsp+0h] [xbp-40h]
  __int64 v98; // [xsp+0h] [xbp-40h]
  __int64 v99; // [xsp+0h] [xbp-40h]
  __int64 v100; // [xsp+0h] [xbp-40h]
  __int64 v101; // [xsp+8h] [xbp-38h]
  __int64 v102; // [xsp+8h] [xbp-38h]
  __int64 v103; // [xsp+8h] [xbp-38h]
  __int64 v104; // [xsp+8h] [xbp-38h]
  __int64 v105; // [xsp+8h] [xbp-38h]
  __int64 v106; // [xsp+8h] [xbp-38h]
  __int64 v107; // [xsp+8h] [xbp-38h]
  __int64 v108; // [xsp+8h] [xbp-38h]
  __int64 v109; // [xsp+10h] [xbp-30h]
  __int64 v110; // [xsp+10h] [xbp-30h]
  __int64 v111; // [xsp+10h] [xbp-30h]
  __int64 v112; // [xsp+10h] [xbp-30h]
  __int64 v113; // [xsp+10h] [xbp-30h]
  __int64 v114; // [xsp+18h] [xbp-28h]
  __int64 v115; // [xsp+18h] [xbp-28h]
  __int64 v116; // [xsp+18h] [xbp-28h]
  __int64 v117; // [xsp+18h] [xbp-28h]
  __int64 v118; // [xsp+20h] [xbp-20h]

  if ( *(_BYTE *)result )
  {
    v9 = *(_DWORD *)(result + 1);
    v10 = result;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: EHT Caps: EPCS PA 0x%01x OM ctl 0x%01x Triggered TXOP Sharing mode1:0x%01x mode2:0x%01x, Restricted TWT 0x%01x"
      " SCS Traffic Desc 0x%01x Max MPDU 0x%01x Max A-MPDU exponent ext: 0x%01x",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wma_print_eht_cap",
      v9 & 1,
      (v9 >> 1) & 1,
      (v9 >> 2) & 1,
      (v9 >> 3) & 1,
      (v9 >> 4) & 1,
      (v9 >> 5) & 1,
      (unsigned __int8)v9 >> 6,
      (v9 >> 8) & 1);
    v11 = *(_DWORD *)(v10 + 1);
    LODWORD(v92) = (v11 >> 18) & 1;
    LODWORD(v101) = (v11 >> 19) & 1;
    qdf_trace_msg(
      0x36u,
      8u,
      " TRS supp 0x%01x TXOP return support in TXOP M2 0x%01x Two BQRs supp 0x%01x EHT link adaptation supp 0x%01x 320MHz"
      " 6GHz 0x%01x 242-tone RU WT 20 MHz 0x%01x NDP_4x EHT-LTF 3.2 us GI 0x%01x",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      (v11 >> 9) & 1,
      (v11 >> 10) & 1,
      (v11 >> 11) & 1,
      (v11 >> 12) & 3,
      (v11 >> 17) & 1,
      v92,
      v101);
    v20 = *(_QWORD *)(v10 + 1);
    LODWORD(v93) = (v20 >> 30) & 7;
    LODWORD(v114) = (v20 >> 39) & 7;
    LODWORD(v109) = (v20 >> 36) & 7;
    LODWORD(v102) = (v20 >> 33) & 7;
    qdf_trace_msg(
      0x36u,
      8u,
      " Partial BW UL MU-MIMO: 0x%01x, SU: Bfer 0x%01x Bfee 0x%01x, Bfee SS: LE 80Mhz 0x%03x  160Mhz 0x%03x 320Mhz 0x%03x"
      ", No. of Sounding Dim LE 80Mhz 0x%03x  160Mhz 0x%03x 320Mhz 0x%03x ",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      ((unsigned int)v20 >> 20) & 1,
      ((unsigned int)v20 >> 21) & 1,
      ((unsigned int)v20 >> 22) & 1,
      BYTE3(v20) & 7,
      ((unsigned int)v20 >> 27) & 7,
      v93,
      v102,
      v109,
      v114);
    v29 = *(_QWORD *)(v10 + 1);
    LODWORD(v94) = (v29 >> 47) & 1;
    LODWORD(v110) = (v29 >> 49) & 1;
    LODWORD(v103) = HIWORD(v29) & 1;
    qdf_trace_msg(
      0x36u,
      8u,
      " Ng 16: SU Feedback 0x%01x, MU Feedback 0x%01x Codebook: 4 2 SU: 0x%01x, 7 5 MU: 0x%01x, Trig SU Bfing fb 0x%01x, "
      "MU Bfing partial BW 0x%01x Trig CQI FB 0x%01x, Part BW DL MU-MIMO: 0x%01x",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      (v29 >> 42) & 1,
      (v29 >> 43) & 1,
      (v29 >> 44) & 1,
      (v29 >> 45) & 1,
      (v29 >> 46) & 1,
      v94,
      v103,
      v110);
    v38 = *(_QWORD *)(v10 + 1);
    LODWORD(v95) = (v38 & 0x2000000000000000LL) != 0;
    LODWORD(v104) = (v38 & 0x4000000000000000LL) != 0;
    qdf_trace_msg(
      0x36u,
      8u,
      " PSR-Based SR 0x%01x, Power Boost Factor 0x%01x, MU PPDU With 4x EHT-LTF 0.8 us GI 0x%01x Max Nc: 0x%04x, Non-Trig"
      " CQI FB 0x%01x, 1024-QAM 4096-QAM < 242-tone RU: TX 0x%01x RX 0x%01x",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      (v38 >> 50) & 1,
      (v38 >> 51) & 1,
      (v38 >> 52) & 1,
      HIBYTE(v38) & 0xF,
      (v38 >> 60) & 1,
      v95,
      v104);
    v47 = *(_DWORD *)(v10 + 9);
    LODWORD(v96) = (v47 >> 12) & 1;
    qdf_trace_msg(
      0x36u,
      8u,
      " PPE Thresholds 0x%01x, Common Nominal Pkt Padding 0x%02x, Max No. Sup EHT-LTFs 0x%05x, MCS 15 0x%04x, DUP 6 GHz 0"
      "x%01x, 20 MHz STA RX NDP With Wider BW 0x%01x",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      *(_QWORD *)(v10 + 1) >> 63,
      v47 & 3,
      (v47 >> 2) & 0x1F,
      (v47 >> 7) & 0xF,
      (v47 >> 11) & 1,
      v96);
    v56 = *(_DWORD *)(v10 + 9);
    LODWORD(v97) = (v56 >> 18) & 1;
    LODWORD(v115) = (v56 >> 21) & 1;
    LODWORD(v111) = (v56 >> 20) & 1;
    LODWORD(v105) = (v56 >> 19) & 1;
    qdf_trace_msg(
      0x36u,
      8u,
      " Non-OFDMA ULMU: LE 80MHz 0x%01x 160MHz 0x%01x 320MHz 0x%01x, MUBfmer: LE 80MHz 0x%01x 160MHz 0x%01x 320MHz 0x%01x"
      ", TB sound FBRL 0x%01x, WBDL OFDMA Rx: 1024QAM 0x%01x 4096QAM 0x%01x",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      (v56 >> 13) & 1,
      (v56 >> 14) & 1,
      (v56 >> 15) & 1,
      HIWORD(v56) & 1,
      (v56 >> 17) & 1,
      v97,
      v105,
      v111,
      v115);
    v65 = *(_QWORD *)(v10 + 9);
    LODWORD(v98) = (v65 >> 36) & 0xF;
    LODWORD(v106) = (v65 >> 40) & 0xF;
    qdf_trace_msg(
      0x36u,
      8u,
      " 20 MHz-Only: Limited Cap 0x%01x Triggered MU Bfing Full BW FB, DL MU-MIMO 0x%01x M-RU Support 0x%01x, EHT MCS: 20"
      "MHz::: 0-7: RX: 0x%x TX: 0x%x, 8-9: RX: 0x%x TX: 0x%x",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      ((unsigned int)v65 >> 22) & 1,
      ((unsigned int)v65 >> 23) & 1,
      BYTE3(v65) & 1,
      (unsigned int)v65 >> 28,
      HIDWORD(v65) & 0xF,
      v98,
      v106);
    v74 = *(_DWORD *)(v10 + 17);
    LODWORD(v107) = (unsigned __int8)v74 >> 4;
    LODWORD(v116) = (unsigned __int16)v74 >> 12;
    LODWORD(v112) = (v74 >> 8) & 0xF;
    LODWORD(v99) = v74 & 0xF;
    qdf_trace_msg(
      0x36u,
      8u,
      " 20MHz::: 10-11: RX: 0x%x TX: 0x%x, 12-13: RX: 0x%x TX: 0x%x, 80Mhz LE::: 0-9: RX: 0x%x TX: 0x%x, 10-11: RX: 0x%x "
      "TX: 0x%x, 12-13: RX: 0x%x TX: 0x%x",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      (*(_QWORD *)(v10 + 9) >> 44) & 0xFLL,
      HIWORD(*(_QWORD *)(v10 + 9)) & 0xFLL,
      (*(_QWORD *)(v10 + 9) >> 52) & 0xFLL,
      HIBYTE(*(_QWORD *)(v10 + 9)) & 0xFLL,
      *(_QWORD *)(v10 + 9) >> 60,
      v99,
      v107,
      v112,
      v116,
      HIWORD(v74) & 0xF);
    v83 = *(_QWORD *)(v10 + 17);
    LODWORD(v118) = HIBYTE(v83) & 0xF;
    LODWORD(v117) = (v83 >> 52) & 0xF;
    LODWORD(v113) = HIWORD(v83) & 0xF;
    LODWORD(v108) = (v83 >> 44) & 0xF;
    LODWORD(v100) = (v83 >> 40) & 0xF;
    return qdf_trace_msg(
             0x36u,
             8u,
             " 160Mhz::: 0-9: RX: 0x%x TX: 0x%x, 10-11: RX: 0x%x TX: 0x%x, 12-13: RX: 0x%x TX: 0x%x, 320Mhz::: 0-9: RX: 0"
             "x%x TX: 0x%x, 10-11: RX: 0x%x TX: 0x%x, 12-13: RX: 0x%x TX: 0x%x",
             v84,
             v85,
             v86,
             v87,
             v88,
             v89,
             v90,
             v91,
             ((unsigned int)v83 >> 20) & 0xF,
             BYTE3(v83) & 0xF,
             (unsigned int)v83 >> 28,
             HIDWORD(v83) & 0xF,
             (v83 >> 36) & 0xF,
             v100,
             v108,
             v113,
             v117,
             v118,
             v83 >> 60,
             *(_BYTE *)(v10 + 25) & 0xF);
  }
  return result;
}
