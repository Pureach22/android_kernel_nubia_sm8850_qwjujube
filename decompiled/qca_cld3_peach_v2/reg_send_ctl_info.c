__int64 __fastcall reg_send_ctl_info(
        __int64 a1,
        __int64 *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  __int64 v13; // x19
  __int64 v14; // x8
  unsigned int rdpair_from_regdmn_id; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w19
  __int16 *v27; // x8
  __int64 v28; // x0
  __int64 v29; // x21
  __int64 v30; // x22
  int v31; // w27
  unsigned int v32; // w23
  unsigned int v33; // w24
  int v34; // w28
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int16 v43; // w8
  unsigned int v44; // w20
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 (__fastcall *v61)(__int64, int *); // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned __int16 v70[2]; // [xsp+8h] [xbp-18h] BYREF
  int v71; // [xsp+Ch] [xbp-14h] BYREF
  __int16 v72; // [xsp+10h] [xbp-10h]
  __int16 v73; // [xsp+12h] [xbp-Eh]
  int v74; // [xsp+14h] [xbp-Ch]
  __int64 v75; // [xsp+18h] [xbp-8h]

  result = 0;
  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *a2;
  v74 = 0;
  if ( (*(_BYTE *)(a1 + 91095) & 1) == 0 )
  {
    v14 = *(_QWORD *)(a3 + 120);
    v70[0] = 0;
    if ( v14 )
    {
      rdpair_from_regdmn_id = reg_get_rdpair_from_regdmn_id(*((unsigned __int16 *)a2 + 7), v70);
      if ( rdpair_from_regdmn_id )
      {
        v26 = rdpair_from_regdmn_id;
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: Failed to get regdomain index for regdomain pair: %x",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "reg_send_ctl_info",
          *((unsigned __int16 *)a2 + 7));
LABEL_13:
        result = v26;
        goto LABEL_14;
      }
      v27 = &g_reg_dmn_pairs_0[2 * v70[0]];
      v28 = *((unsigned __int16 *)a2 + 7);
      v29 = *((unsigned __int8 *)v27 + 3);
      v30 = *((unsigned __int8 *)v27 + 2);
      v31 = reg_2g_sub_dmn_code[v29];
      v72 = v31;
      v32 = regdomains_2g[24 * v29];
      v33 = regdomains_5g[24 * v30];
      v34 = reg_5g_sub_dmn_code[v30];
      LOBYTE(v74) = regdomains_2g[24 * v29];
      BYTE1(v74) = v33;
      v73 = v34;
      if ( (reg_is_world_ctry_code(v28) & 1) != 0 )
        v43 = *((_WORD *)a2 + 7);
      else
        v43 = *((_WORD *)a2 + 8) | 0x8000;
      v44 = v43;
      v71 = v43;
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: regdomain pair = %u, regdomain index = %u",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "reg_send_ctl_info");
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: index_2g = %u, index_5g = %u, ctl_2g = %x, ctl_5g = %x",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "reg_send_ctl_info",
        (unsigned int)v29,
        (unsigned int)v30,
        v32,
        v33);
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: regd_2g = %x, regd_5g = %x, regd = %x",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "reg_send_ctl_info",
        (unsigned __int16)v31,
        (unsigned __int16)v34,
        v44);
      v61 = *(__int64 (__fastcall **)(__int64, int *))(a3 + 120);
      if ( *((_DWORD *)v61 - 1) != 565685169 )
        __break(0x8228u);
      result = v61(v13, &v71);
      if ( (_DWORD)result )
      {
        v26 = result;
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: Failed to send CTL info to firmware",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "reg_send_ctl_info");
        goto LABEL_13;
      }
    }
    else
    {
      qdf_trace_msg(0x51u, 2u, "%s: No regulatory tx_ops", a4, a5, a6, a7, a8, a9, a10, a11, "reg_send_ctl_info");
      result = 5;
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
