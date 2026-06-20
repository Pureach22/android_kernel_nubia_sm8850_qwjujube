void __fastcall epcs_update_ven_wmm_param(
        __int64 a1,
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
  _QWORD *context; // x0
  _BYTE *v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // [xsp+0h] [xbp-40h]
  __int64 v55; // [xsp+0h] [xbp-40h]
  __int64 v56; // [xsp+0h] [xbp-40h]
  __int64 v57; // [xsp+10h] [xbp-30h] BYREF
  __int64 v58; // [xsp+18h] [xbp-28h]
  int v59; // [xsp+20h] [xbp-20h]
  int v60; // [xsp+24h] [xbp-1Ch] BYREF
  char v61; // [xsp+28h] [xbp-18h]
  int v62; // [xsp+29h] [xbp-17h]
  char v63; // [xsp+2Dh] [xbp-13h]
  int v64; // [xsp+2Eh] [xbp-12h]
  char v65; // [xsp+32h] [xbp-Eh]
  int v66; // [xsp+33h] [xbp-Dh]
  char v67; // [xsp+37h] [xbp-9h]
  __int64 v68; // [xsp+38h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59 = 0;
  v57 = 0;
  v58 = 0;
  context = _cds_get_context(53, (__int64)"epcs_update_ven_wmm_param", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    v13 = context;
    if ( (unsigned int)dot11f_unpack_ie_wmm_params((__int64)context, (unsigned __int8 *)(a2 + 7), 0x18u, (__int64)&v57) )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: EPCS parsing wmm ie error",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "epcs_update_ven_wmm_param");
    }
    else
    {
      v60 = HIDWORD(v57);
      v61 = v13[21697];
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: WMM BE aci %d, acm %d, aifsn %d, cwmax %d, cwmin %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "epcs_update_ven_wmm_param",
        (WORD2(v57) >> 5) & 3,
        (WORD2(v57) >> 4) & 1,
        BYTE4(v57) & 0xF,
        WORD2(v57) >> 12,
        HIBYTE(WORD2(v57)) & 0xF);
      v62 = v58;
      LODWORD(v54) = BYTE1(v58) & 0xF;
      v63 = v13[21698];
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: WMM BK aci %d, acm %d, aifsn %d, cwmax %d, cwmin %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "epcs_update_ven_wmm_param",
        ((unsigned __int16)v58 >> 5) & 3,
        ((unsigned __int16)v58 >> 4) & 1,
        v58 & 0xF,
        (unsigned __int16)v58 >> 12,
        v54);
      v64 = HIDWORD(v58);
      LODWORD(v55) = HIBYTE(WORD2(v58)) & 0xF;
      v65 = v13[21699];
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: WMM VI aci %d, acm %d, aifsn %d, cwmax %d, cwmin %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "epcs_update_ven_wmm_param",
        (WORD2(v58) >> 5) & 3,
        (WORD2(v58) >> 4) & 1,
        BYTE4(v58) & 0xF,
        WORD2(v58) >> 12,
        v55);
      v66 = v59;
      LODWORD(v56) = BYTE1(v59) & 0xF;
      v67 = v13[21700];
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: WMM VO aci %d, acm %d, aifsn %d, cwmax %d, cwmin %d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "epcs_update_ven_wmm_param",
        ((unsigned __int16)v59 >> 5) & 3,
        ((unsigned __int16)v59 >> 4) & 1,
        v59 & 0xF,
        (unsigned __int16)v59 >> 12,
        v56);
      lim_send_epcs_update_edca_params(a1, (__int64)&v60, 0, v46, v47, v48, v49, v50, v51, v52, v53);
    }
  }
  _ReadStatusReg(SP_EL0);
}
