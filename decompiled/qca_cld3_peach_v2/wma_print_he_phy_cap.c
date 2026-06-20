__int64 __fastcall wma_print_he_phy_cap(
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
  unsigned int v18; // w9
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v55; // [xsp+0h] [xbp-10h]
  __int64 v56; // [xsp+0h] [xbp-10h]
  __int64 v57; // [xsp+0h] [xbp-10h]
  __int64 v58; // [xsp+0h] [xbp-10h]
  __int64 v59; // [xsp+8h] [xbp-8h]

  qdf_trace_msg(
    0x36u,
    8u,
    "%s: HE PHY Caps: Chan width 0x%07x, Preamble punct Rx 0x%04x, dev class 0x%01x, LDPC 0x%01x, LTF and GI: HE PPDUs 0x%02x NDP 0x%02x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wma_print_he_phy_cap",
    (unsigned __int8)*a1 >> 1,
    (*a1 >> 8) & 0xF,
    (*a1 >> 12) & 1,
    (*a1 >> 13) & 1,
    (*a1 >> 14) & 1,
    (*a1 >> 17) & 1);
  LODWORD(v55) = (*a1 >> 27) & 7;
  qdf_trace_msg(
    0x36u,
    8u,
    " STBC Tx & Rx support LE 80Mhz 0x%02x, Doppler 0x%02x, UL MU: Full BW 0x%01x Partial BW 0x%01x, DCM encoding: TX 0x%03x RX 0x%03x",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    (*a1 >> 18) & 3,
    (*a1 >> 20) & 3,
    (*a1 >> 22) & 1,
    (*a1 >> 23) & 1,
    HIBYTE(*a1) & 7,
    v55);
  v18 = a1[1];
  LODWORD(v56) = (unsigned __int8)v18 >> 5;
  qdf_trace_msg(
    0x36u,
    8u,
    " HE MU PPDU payload 0x%01x, SU: Bfer 0x%01x Bfee 0x%01x, MU Bfer 0x%01x, Bfee STS: LE 80Mhz 0x%03x GT 80Mhz 0x%03x",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    (*a1 >> 30) & 1,
    *a1 >> 31,
    v18 & 1,
    (v18 >> 1) & 1,
    (v18 >> 2) & 7,
    v56);
  v27 = a1[1];
  LODWORD(v57) = (v27 >> 15) & 1;
  qdf_trace_msg(
    0x36u,
    8u,
    " NSTS: LE 80Mhz 0x%03x GT 80Mhz 0x%03x, No of Sounding dim: LE 80Mhz 0x%03x GT 80Mhz 0x%03x, Ng=16 FB: SU 0x%01x MU 0x%01x",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    (v27 >> 2) & 7,
    (unsigned __int8)v27 >> 5,
    (v27 >> 8) & 7,
    (v27 >> 11) & 7,
    (v27 >> 14) & 1,
    v57);
  v36 = a1[1];
  qdf_trace_msg(
    0x36u,
    8u,
    " Codebook size: SU 0x%01x MU 0x%01x, Beamforming trigger w/ Trigger 0x%01x, HE ER SU PPDU 0x%01x, DL MUMIMO on partial BW 0x%01x",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    HIWORD(v36) & 1,
    (v36 >> 17) & 1,
    (v36 >> 18) & 7,
    (v36 >> 21) & 1,
    (v36 >> 22) & 1);
  v45 = a1[1];
  LODWORD(v59) = a1[2] & 1;
  LODWORD(v58) = v45 >> 30;
  return qdf_trace_msg(
           0x36u,
           8u,
           " PPET 0x%01x, SRP based SR 0x%01x, Power boost 0x%01x, 4x HE LTF 0x%01x, Max Nc 0x%03x, STBC Tx/Rx GT 80Mhz 0"
           "x%02x, ER 4x HE LTF 0x%01x",
           v46,
           v47,
           v48,
           v49,
           v50,
           v51,
           v52,
           v53,
           (v45 >> 23) & 1,
           HIBYTE(v45) & 1,
           (v45 >> 25) & 1,
           (v45 >> 26) & 1,
           (v45 >> 27) & 7,
           v58,
           v59);
}
