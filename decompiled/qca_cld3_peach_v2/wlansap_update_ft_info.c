__int64 __fastcall wlansap_update_ft_info(
        __int64 a1,
        const void *a2,
        __int64 a3,
        int a4,
        __int16 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  _QWORD *context; // x0
  _QWORD *v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  __int64 result; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w8
  _QWORD *v47; // x22
  unsigned int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w19
  __int64 v58; // x19
  unsigned int updated; // w20
  _QWORD *v60; // [xsp+0h] [xbp-10h] BYREF
  __int64 v61; // [xsp+8h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60 = nullptr;
  if ( !a1 )
  {
    v36 = "%s: Invalid SAP context";
LABEL_7:
    qdf_trace_msg(0x39u, 2u, v36, a6, a7, a8, a9, a10, a11, a12, a13, "wlansap_update_ft_info", v60, v61);
    goto LABEL_8;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a6, a7, a8, a9, a10, a11, a12, a13);
  if ( !context )
  {
    v36 = "%s: Invalid MAC context";
    goto LABEL_7;
  }
  v19 = context;
  if ( (unsigned int)qdf_wait_single_event(a1 + 1696, 0x1F4u) )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: wait for ft pending event timeout",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlansap_update_ft_info");
    wlansap_ft_cleanup(a1, v28, v29, v30, v31, v32, v33, v34, v35);
LABEL_8:
    result = 5;
    goto LABEL_9;
  }
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 1672), &v60) )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Failed to find ft assoc ind list",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wlansap_update_ft_info");
    result = 16;
  }
  else
  {
    while ( 1 )
    {
      v47 = v60;
      if ( !(unsigned int)qdf_mem_cmp(a2, (const void *)(v60[2] + 5LL), 6u) )
        break;
      v46 = qdf_list_peek_next((_QWORD *)(a1 + 1672), v47, &v60);
      result = 0;
      if ( v46 )
        goto LABEL_9;
    }
    v48 = qdf_list_remove_node(a1 + 1672, v47);
    if ( v48 )
    {
      v57 = v48;
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: Failed to remove ft assoc ind",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "wlansap_update_ft_info");
      result = v57;
    }
    else
    {
      v58 = v47[2];
      _qdf_mem_free((__int64)v47);
      if ( v58 )
      {
        *(_QWORD *)(v58 + 2928) = a3;
        *(_DWORD *)(v58 + 2936) = a4;
        *(_WORD *)(v58 + 2940) = a5;
        updated = sme_update_ft_info(v19, v58);
        _qdf_mem_free(v58);
        result = updated;
      }
      else
      {
        result = 0;
      }
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
