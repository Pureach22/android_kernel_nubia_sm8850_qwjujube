void __fastcall epcs_update_mu_edca_param(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w8
  __int16 v22; // w10
  _BYTE *v23; // x22
  unsigned int v24; // w9
  unsigned int v25; // w10
  __int16 v26; // w11
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w9
  unsigned int v36; // w10
  __int16 v37; // w11
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w9
  unsigned int v47; // w10
  __int16 v48; // w11
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // [xsp+0h] [xbp-30h]
  __int64 v66; // [xsp+0h] [xbp-30h]
  __int64 v67; // [xsp+0h] [xbp-30h]
  __int64 v68; // [xsp+8h] [xbp-28h]
  __int64 v69; // [xsp+8h] [xbp-28h]
  __int64 v70; // [xsp+8h] [xbp-28h]
  char v71; // [xsp+14h] [xbp-1Ch] BYREF
  unsigned __int8 v72; // [xsp+15h] [xbp-1Bh]
  __int16 v73; // [xsp+16h] [xbp-1Ah]
  char v74; // [xsp+18h] [xbp-18h]
  char v75; // [xsp+19h] [xbp-17h]
  char v76; // [xsp+1Ah] [xbp-16h]
  __int16 v77; // [xsp+1Bh] [xbp-15h]
  char v78; // [xsp+1Dh] [xbp-13h]
  char v79; // [xsp+1Eh] [xbp-12h]
  char v80; // [xsp+1Fh] [xbp-11h]
  __int16 v81; // [xsp+20h] [xbp-10h]
  char v82; // [xsp+22h] [xbp-Eh]
  char v83; // [xsp+23h] [xbp-Dh]
  char v84; // [xsp+24h] [xbp-Ch]
  __int16 v85; // [xsp+25h] [xbp-Bh]
  char v86; // [xsp+27h] [xbp-9h]
  __int64 v87; // [xsp+28h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *a2 == 255 && a2[1] == 14 )
  {
    context = _cds_get_context(53, (__int64)"epcs_update_mu_edca_param", a3, a4, a5, a6, a7, a8, a9, a10);
    if ( context )
    {
      v21 = a2[4];
      v22 = a2[6];
      v72 = a2[5];
      v23 = context + 2560;
      v71 = v21;
      v73 = v22;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: muac rsvd %d, aci %d, acm %d, aifsn %d, cwmax %d, cwmin %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "epcs_update_mu_ac_value",
        v21 >> 7,
        (v21 >> 5) & 3,
        (v21 >> 4) & 1,
        v21 & 0xF,
        v72 >> 4,
        v72 & 0xF);
      v24 = a2[7];
      v25 = a2[8];
      v26 = a2[9];
      v74 = v23[1217];
      v76 = v25;
      v75 = v24;
      v77 = v26;
      LODWORD(v68) = v25 & 0xF;
      LODWORD(v65) = v25 >> 4;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: muac rsvd %d, aci %d, acm %d, aifsn %d, cwmax %d, cwmin %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "epcs_update_mu_ac_value",
        v24 >> 7,
        (v24 >> 5) & 3,
        (v24 >> 4) & 1,
        v24 & 0xF,
        v65,
        v68);
      v35 = a2[10];
      v36 = a2[11];
      v37 = a2[12];
      v78 = v23[1218];
      v80 = v36;
      v79 = v35;
      v81 = v37;
      LODWORD(v69) = v36 & 0xF;
      LODWORD(v66) = v36 >> 4;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: muac rsvd %d, aci %d, acm %d, aifsn %d, cwmax %d, cwmin %d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "epcs_update_mu_ac_value",
        v35 >> 7,
        (v35 >> 5) & 3,
        (v35 >> 4) & 1,
        v35 & 0xF,
        v66,
        v69);
      v46 = a2[13];
      v47 = a2[14];
      v48 = a2[15];
      v82 = v23[1219];
      v84 = v47;
      v83 = v46;
      v85 = v48;
      LODWORD(v70) = v47 & 0xF;
      LODWORD(v67) = v47 >> 4;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: muac rsvd %d, aci %d, acm %d, aifsn %d, cwmax %d, cwmin %d",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "epcs_update_mu_ac_value",
        v46 >> 7,
        (v46 >> 5) & 3,
        (v46 >> 4) & 1,
        v46 & 0xF,
        v67,
        v70);
      v86 = v23[1220];
      lim_send_epcs_update_edca_params(a1, (__int64)&v71, 1, v57, v58, v59, v60, v61, v62, v63, v64);
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: mu edca info for epcs is not valid or not exist",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "epcs_update_mu_edca_param");
  }
  _ReadStatusReg(SP_EL0);
}
