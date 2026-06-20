__int64 __fastcall sap_init_ctx(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        const void *a11,
        unsigned int a12,
        char a13,
        char a14)
{
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _QWORD *context; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  _QWORD *v44; // x21
  unsigned int v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 result; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7

  qdf_trace_msg(0x39u, 8u, "%s: wlansap_start invoked successfully", a2, a3, a4, a5, a6, a7, a8, a9, "sap_init_ctx");
  if ( a1 )
  {
    *(_DWORD *)(a1 + 732) = 0;
    qdf_mem_copy((void *)(a1 + 24), a11, 6u);
    context = _cds_get_context(53, (__int64)"sap_get_mac_context", v27, v28, v29, v30, v31, v32, v33, v34);
    if ( context )
    {
      v44 = context;
      *(_BYTE *)(a1 + 1643) = a13 & 1;
      v45 = ((__int64 (__fastcall *)(_QWORD *, __int64, _QWORD))sap_set_session_param)(context, a1, a12);
      if ( v45 )
      {
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: Calling sap_set_session_param status = %d",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "sap_init_ctx",
          v45);
        return 16;
      }
      if ( (a14 & 1) != 0 )
      {
        return 0;
      }
      else
      {
        *(_WORD *)(a1 + 1640) = wlan_scan_register_requester(
                                  v44[2703],
                                  "SAP",
                                  (__int64)sap_scan_event_callback,
                                  a1,
                                  v46,
                                  v47,
                                  v48,
                                  v49,
                                  v50,
                                  v51,
                                  v52,
                                  v53);
        *(_QWORD *)(a1 + 1648) = a1 + 1648;
        *(_QWORD *)(a1 + 1656) = a1 + 1648;
        *(_QWORD *)(a1 + 1664) = 0;
        *(_QWORD *)(a1 + 1672) = a1 + 1672;
        *(_QWORD *)(a1 + 1680) = a1 + 1672;
        *(_QWORD *)(a1 + 1688) = 0;
        qdf_event_create((_DWORD *)(a1 + 1696));
        result = ucfg_scan_register_event_handler(
                   v44[2704],
                   (__int64)wlansap_scan_complete_event_handler,
                   a1,
                   v55,
                   v56,
                   v57,
                   v58,
                   v59,
                   v60,
                   v61,
                   v62);
        if ( (_DWORD)result )
        {
          qdf_trace_msg(
            0x39u,
            2u,
            "%s: scan event register failed ",
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            "sap_init_ctx");
          return 16;
        }
      }
    }
    else
    {
      qdf_trace_msg(0x39u, 2u, "%s: Invalid MAC context", v36, v37, v38, v39, v40, v41, v42, v43, "sap_init_ctx");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid SAP pointer", v19, v20, v21, v22, v23, v24, v25, v26, "sap_init_ctx");
    return 5;
  }
  return result;
}
