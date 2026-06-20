__int64 __fastcall dp_direct_link_init(__int64 a1)
{
  char is_direct_link_supported; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x5
  _QWORD *v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  __int64 *context; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w20
  __int64 result; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w21
  __int64 v62; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v63; // [xsp+10h] [xbp-A0h]
  __int64 v64; // [xsp+18h] [xbp-98h]
  _QWORD v65[3]; // [xsp+20h] [xbp-90h] BYREF
  __int64 v66; // [xsp+38h] [xbp-78h]
  __int64 (__fastcall *v67)(); // [xsp+40h] [xbp-70h]
  __int64 (__fastcall *v68)(); // [xsp+48h] [xbp-68h]
  __int64 v69; // [xsp+50h] [xbp-60h]
  __int64 v70; // [xsp+58h] [xbp-58h]
  __int64 v71; // [xsp+60h] [xbp-50h]
  __int64 v72; // [xsp+68h] [xbp-48h]
  __int64 v73; // [xsp+70h] [xbp-40h]
  __int64 v74; // [xsp+78h] [xbp-38h]
  __int64 v75; // [xsp+80h] [xbp-30h]
  __int64 v76; // [xsp+88h] [xbp-28h]
  __int64 v77; // [xsp+90h] [xbp-20h]
  __int64 v78; // [xsp+98h] [xbp-18h]
  __int64 v79; // [xsp+A0h] [xbp-10h]
  __int64 v80; // [xsp+A8h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  is_direct_link_supported = pld_is_direct_link_supported(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 40LL));
  v11 = *(unsigned __int8 *)(a1 + 220);
  if ( (is_direct_link_supported & 1) == 0 || (v11 & 1) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Direct Link is not supported FW cap:%d ini:%d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_direct_link_init",
      is_direct_link_supported & 1,
      v11);
    result = 0;
    goto LABEL_8;
  }
  v12 = (_QWORD *)_qdf_mem_malloc(0x28u, "dp_direct_link_init", 2750);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to allocate memory for DP Direct Link context",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "dp_direct_link_init");
    result = 2;
    goto LABEL_8;
  }
  v21 = (__int64)v12;
  *v12 = a1;
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = nullptr;
  v69 = 0;
  v66 = 0;
  v67 = nullptr;
  v64 = 0;
  memset(v65, 0, sizeof(v65));
  v62 = 0;
  v63 = 0;
  context = (__int64 *)_cds_get_context(62, "dp_lpass_connect_htc_service");
  if ( !context )
  {
    v40 = 16;
    goto LABEL_11;
  }
  v66 = v21;
  v67 = dp_lpass_h2t_tx_complete;
  v68 = dp_lpass_t2h_msg_handler;
  LODWORD(v65[0]) = 526080;
  v31 = htc_connect_service(context, (unsigned __int16 *)v65, (__int64)&v62);
  if ( v31 )
  {
    v40 = v31;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: LPASS_DATA_MSG connect service failed",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "dp_lpass_connect_htc_service");
LABEL_11:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to connect to LPASS data msg service",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "dp_direct_link_init");
    _qdf_mem_free(v21);
    result = v40;
    goto LABEL_8;
  }
  *(_DWORD *)(v21 + 8) = HIDWORD(v63);
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: LPASS_DATA_MSG connect service successful",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "dp_lpass_connect_htc_service");
  v42 = _cds_get_context(71, "dp_direct_link_refill_ring_init");
  if ( !v42 )
  {
LABEL_17:
    _qdf_mem_free(v21);
    result = 16;
    goto LABEL_8;
  }
  v43 = dp_setup_direct_link_refill_ring(v42, *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)v21 + 8LL) + 40LL));
  *(_QWORD *)(v21 + 16) = v43;
  if ( !v43 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Refill ring init for Direct Link failed",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "dp_direct_link_refill_ring_init");
    goto LABEL_17;
  }
  v52 = dp_wfds_init(v21);
  if ( v52 )
  {
    v61 = v52;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to initialize QMI for Direct Link",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "dp_direct_link_init");
    dp_direct_link_refill_ring_deinit(*(_QWORD *)(a1 + 1472));
    _qdf_mem_free(v21);
    result = v61;
  }
  else
  {
    qdf_mutex_create(a1 + 1408);
    result = 0;
    *(_QWORD *)(a1 + 1472) = v21;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
