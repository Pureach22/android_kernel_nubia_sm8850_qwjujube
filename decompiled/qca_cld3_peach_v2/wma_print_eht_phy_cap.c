__int64 __fastcall wma_print_eht_phy_cap(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
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
  unsigned int v34; // w8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w9
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v62; // [xsp+0h] [xbp-20h]
  __int64 v63; // [xsp+0h] [xbp-20h]
  __int64 v64; // [xsp+0h] [xbp-20h]
  __int64 v65; // [xsp+0h] [xbp-20h]
  __int64 v66; // [xsp+8h] [xbp-18h]
  __int64 v67; // [xsp+8h] [xbp-18h]
  __int64 v68; // [xsp+10h] [xbp-10h]

  qdf_trace_msg(
    0x36u,
    8u,
    "%s: EHT PHY Cap: 320 MHz In 6 GHz 0x%01x, 242-tone RU In BW Wider Than 20 MHz 0x%01x, NDP With 4x EHT-LTF And 3.2 us"
    " GI 0x%01x, Partial BW UL MU-MIMO 0x%01x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wma_print_eht_phy_cap",
    (*a1 >> 1) & 1,
    (*a1 >> 2) & 1,
    (*a1 >> 3) & 1,
    (*a1 >> 4) & 1);
  qdf_trace_msg(
    0x36u,
    8u,
    " SU: Bfmer 0x%01x Bfmee 0x%01x, Bfmee SS: LE 80MHz 0x%03x 160MHz 0x%03x 320MHz 0x%03x, No. of Sounding Dim: LE 80MHz"
    " 0x%03x 160MHz 0x%03x 320MHz 0x%03x",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    (*a1 >> 5) & 1,
    (*a1 >> 6) & 1,
    (*a1 >> 7) & 7,
    (*a1 >> 10) & 7,
    (unsigned __int16)*a1 >> 13,
    HIWORD(*a1) & 7,
    (*a1 >> 19) & 7,
    (*a1 >> 22) & 7);
  LODWORD(v62) = (*a1 >> 30) & 1;
  qdf_trace_msg(
    0x36u,
    8u,
    " Ng 16 FB: SU 0x%01x MU 0x%01x, Codebook Size: 42 SU FB 0x%01x 75 MU FB: 0x%01x, Trigg SU Bfming FB 0x%01x, MU Bfmin"
    "g Partial BW FB 0x%01x",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    (*a1 >> 25) & 1,
    (*a1 >> 26) & 1,
    (*a1 >> 27) & 1,
    (*a1 >> 28) & 1,
    (*a1 >> 29) & 1,
    v62);
  qdf_trace_msg(
    0x36u,
    8u,
    " Triggered CQI FB 0x%01x, Partial BW DL MU-MIMO 0x%01x, PSR-Based SR 0x%01x, Power Boost Factor 0x%01x, MU PPDU 4x E"
    "HT-LTF 0.8 us GI 0x%01x",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    *a1 >> 31,
    (*a1 >> 30) & 1,
    (a1[1] >> 1) & 1,
    (a1[1] >> 2) & 1,
    (a1[1] >> 3) & 1);
  v34 = a1[1];
  LODWORD(v63) = (v34 >> 12) & 3;
  qdf_trace_msg(
    0x36u,
    8u,
    " Max Nc 0x%04x, Non-Triggered CQI FB 0x%01x, 1024-QAM 4096-QAM < 242-tone RU: TX 0x%01x RX 0x%01x, PPE Thresholds 0x"
    "%01x, Common Nominal Packet Padding 0x%02x",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    (unsigned __int8)v34 >> 4,
    (v34 >> 8) & 1,
    (v34 >> 9) & 1,
    (v34 >> 10) & 1,
    (v34 >> 11) & 1,
    v63);
  v43 = a1[1];
  LODWORD(v64) = (v43 >> 26) & 1;
  LODWORD(v66) = (v43 >> 27) & 1;
  qdf_trace_msg(
    0x36u,
    8u,
    " Max No. Supp LTFs 0x%05x, MCS 15 0x%04x, EHT DUP 6 GHz 0x%01x, 20MHz STA RX NDP Wider BW 0x%01x, Non-OFDMA UL MU-MI"
    "MO: LE 80MHz 0x%01x 160 MHz 0x%01x 320Mhz 0x%01x",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    (v43 >> 14) & 0x1F,
    (v43 >> 19) & 0xF,
    (v43 >> 23) & 1,
    HIBYTE(v43) & 1,
    (v43 >> 25) & 1,
    v64,
    v66);
  v52 = a1[2];
  LODWORD(v67) = (v52 >> 2) & 1;
  LODWORD(v68) = (v52 >> 3) & 1;
  LODWORD(v65) = (v52 >> 1) & 1;
  return qdf_trace_msg(
           0x36u,
           8u,
           " MUBfmer: LE 80MHz 0x%01x 160MHz 0x%01x 320Mhz 0x%01x, TB sound FBRL 0x%01x, WBW DLOFDMA Rx: 1024QAM 0x%01x 4"
           "096QAM 0x%01x, 20MHz: Lim Cap 0x%01x Trig MUBfing BWFB DLMU 0x%01x M-RU 0x%01x",
           v53,
           v54,
           v55,
           v56,
           v57,
           v58,
           v59,
           v60,
           (a1[1] >> 28) & 1,
           (a1[1] >> 29) & 1,
           (a1[1] >> 30) & 1,
           a1[1] >> 31,
           v52 & 1,
           v65,
           v67,
           v68,
           (v52 >> 4) & 1);
}
