__int64 __fastcall sap_deinit_ctx(
        __int64 a1,
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
  _QWORD *context; // x0
  _QWORD *v19; // x20
  __int64 v20; // x1
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  _QWORD *v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _QWORD *v46; // x21
  const char *v47; // x2
  unsigned int v48; // w1
  const char *v49; // x2
  __int64 result; // x0
  __int64 v51; // x0
  _QWORD *i; // x1
  _QWORD *v53; // x24
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x25
  _QWORD *v63; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v64[2]; // [xsp+10h] [xbp-10h] BYREF

  v64[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x39u, 8u, "%s: wlansap_stop invoked successfully ", a2, a3, a4, a5, a6, a7, a8, a9, "sap_deinit_ctx");
  if ( !a1 )
  {
    v49 = "%s: Invalid SAP pointer";
LABEL_10:
    qdf_trace_msg(0x39u, 2u, v49, v10, v11, v12, v13, v14, v15, v16, v17, "sap_deinit_ctx");
    result = 5;
    goto LABEL_20;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", v10, v11, v12, v13, v14, v15, v16, v17);
  if ( !context )
  {
    v49 = "%s: Invalid MAC context";
    goto LABEL_10;
  }
  v19 = context;
  ucfg_scan_unregister_event_handler(
    context[2695],
    (__int64)wlansap_scan_complete_event_handler,
    a1,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17);
  wlansap_ft_cleanup(a1);
  if ( *(_DWORD *)(a1 + 1672) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "qdf_list_destroy");
  qdf_event_destroy(a1 + 1680, v20);
  v63 = nullptr;
  v64[0] = nullptr;
  v37 = _cds_get_context(53, (__int64)"sap_get_mac_context", v29, v30, v31, v32, v33, v34, v35, v36);
  if ( v37 )
  {
    v46 = v37;
    if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 1632), v64) )
    {
      for ( i = v64[0]; i; v64[0] = i )
      {
        qdf_list_peek_next((_QWORD *)(a1 + 1632), i, &v63);
        v53 = v64[0];
        if ( (unsigned int)qdf_list_remove_node(a1 + 1632, v64[0]) )
        {
          qdf_trace_msg(
            0x39u,
            2u,
            "%s: Failed to remove assoc ind",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "wlansap_owe_cleanup");
        }
        else
        {
          v62 = v53[2];
          _qdf_mem_free((__int64)v53);
          *(_QWORD *)(v62 + 2912) = 0;
          *(_DWORD *)(v62 + 2920) = 0;
          *(_WORD *)(v62 + 2924) = 1;
          sme_update_owe_info(v46, v62);
          _qdf_mem_free(v62);
        }
        i = v63;
        v63 = nullptr;
      }
      goto LABEL_13;
    }
    v47 = "%s: Failed to find assoc ind list";
    v48 = 8;
  }
  else
  {
    v47 = "%s: Invalid MAC context";
    v48 = 2;
  }
  qdf_trace_msg(0x39u, v48, v47, v38, v39, v40, v41, v42, v43, v44, v45, "wlansap_owe_cleanup");
LABEL_13:
  if ( *(_DWORD *)(a1 + 1648) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "qdf_list_destroy");
  wlan_scan_unregister_requester(v19[2694], *(unsigned __int16 *)(a1 + 1624), v38, v39, v40, v41, v42, v43, v44, v45);
  v51 = *(_QWORD *)(a1 + 1488);
  if ( v51 )
  {
    _qdf_mem_free(v51);
    *(_QWORD *)(a1 + 1488) = 0;
    *(_BYTE *)(a1 + 1496) = 0;
  }
  if ( *(unsigned __int8 *)(a1 + 12) != 255 )
    ((void (__fastcall *)(_QWORD *, __int64))sap_clear_session_param)(v19, a1);
  result = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
