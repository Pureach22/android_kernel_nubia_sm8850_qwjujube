__int64 __fastcall ucfg_nan_req_processor(
        __int64 a1,
        const void *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v12; // w8
  unsigned __int64 v13; // t2
  const void *v14; // x22
  __int64 v15; // x20
  __int64 v16; // x21
  unsigned int v17; // w23
  unsigned int v18; // w22
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 comp_private_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  void *v39; // x0
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v59; // [xsp+8h] [xbp-38h] BYREF
  void *v60; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v61)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v62)(); // [xsp+20h] [xbp-20h]
  __int64 v63; // [xsp+28h] [xbp-18h]
  __int64 v64; // [xsp+30h] [xbp-10h]
  __int64 v65; // [xsp+38h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63 = 0;
  v64 = 0;
  v61 = nullptr;
  v62 = nullptr;
  v59 = 0;
  v60 = nullptr;
  if ( !a2 )
  {
    qdf_trace_msg(0x53u, 1u, "%s: req is null", a4, a5, a6, a7, a8, a9, a10, a11, "ucfg_nan_req_processor");
    v18 = 29;
    goto LABEL_33;
  }
  HIDWORD(v13) = a3 - 4;
  LODWORD(v13) = a3 - 4;
  v12 = v13 >> 1;
  if ( v12 <= 1 )
  {
    if ( !v12 )
    {
      v14 = a2;
      v15 = 0;
      v16 = 0;
      v17 = 952;
      goto LABEL_18;
    }
    if ( v12 == 1 )
    {
      v14 = a2;
      v15 = 0;
      v16 = 0;
      v17 = 944;
      goto LABEL_18;
    }
LABEL_24:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: in correct message req type: %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ucfg_nan_req_processor",
      a3);
    v18 = 4;
    goto LABEL_33;
  }
  if ( v12 == 2 )
  {
    v19 = *(_QWORD *)(a1 + 152);
    if ( v19 && (v20 = *(_QWORD *)(v19 + 80)) != 0 )
    {
      v14 = a2;
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v20, 0xFu);
      if ( comp_private_obj )
      {
        v15 = comp_private_obj;
        v30 = osif_request_alloc(ucfg_nan_req_processor_params);
        if ( !v30 )
        {
          v18 = 2;
          qdf_trace_msg(
            0x53u,
            2u,
            "%s: Request allocation failure",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "ucfg_nan_req_processor");
          goto LABEL_33;
        }
        v16 = v30;
        v17 = 1040;
        *(_QWORD *)(v15 + 288) = osif_request_cookie(v30);
        goto LABEL_18;
      }
    }
    else
    {
      qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a4, a5, a6, a7, a8, a9, a10, a11, "nan_get_psoc_priv_obj");
    }
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan psoc priv object is NULL",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "ucfg_nan_req_processor");
    v18 = 4;
    goto LABEL_33;
  }
  if ( v12 == 6 )
  {
    v14 = a2;
    v15 = 0;
    v16 = 0;
    v17 = 8;
    goto LABEL_18;
  }
  if ( v12 != 7 )
    goto LABEL_24;
  v14 = a2;
  v15 = 0;
  v16 = 0;
  v17 = 24;
LABEL_18:
  v39 = (void *)_qdf_mem_malloc(v17, "ucfg_nan_req_processor", 488);
  v60 = v39;
  if ( v39 )
  {
    qdf_mem_copy(v39, v14, v17);
    LOWORD(v59) = a3;
    v61 = nan_scheduled_msg_handler;
    v62 = ucfg_nan_sch_msg_flush_cb;
    v40 = scheduler_post_message_debug(
            0x33u,
            0x53u,
            72,
            (unsigned __int16 *)&v59,
            0x1F4u,
            (__int64)"ucfg_nan_req_processor");
    if ( !v40 )
    {
      if ( a3 != 8 )
      {
        v18 = 0;
        goto LABEL_33;
      }
      qdf_trace_msg(
        0x53u,
        8u,
        "%s: Wait for NDP END indication",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "ucfg_nan_req_processor");
      v49 = osif_request_wait_for_response(v16);
      if ( v49 )
        qdf_trace_msg(
          0x53u,
          8u,
          "%s: NAN request timed out: %d",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "ucfg_nan_req_processor",
          v49);
      osif_request_put(v16);
      v18 = 0;
      goto LABEL_29;
    }
    v18 = v40;
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: failed to post msg to NAN component, status: %d",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "ucfg_nan_req_processor",
      v40);
    v39 = v60;
  }
  else
  {
    v18 = 2;
  }
  _qdf_mem_free((__int64)v39);
  if ( a3 == 8 )
  {
    osif_request_put(v16);
LABEL_29:
    *(_QWORD *)(v15 + 288) = 0;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return v18;
}
