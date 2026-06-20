__int64 __fastcall wlansap_update_owe_info(
        __int64 a1,
        const void *a2,
        unsigned __int8 *a3,
        unsigned int a4,
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
  unsigned int v15; // w10
  unsigned __int8 *v16; // x11
  unsigned int v17; // w9
  unsigned int v18; // w8
  unsigned int v19; // w8
  bool v20; // cf
  _QWORD *context; // x0
  _QWORD *v25; // x21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _QWORD *v43; // x22
  unsigned int v44; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w19
  const char *v54; // x2
  const char *v55; // x2
  __int64 v56; // x4
  const char *v57; // x2
  __int64 v58; // x19
  unsigned int updated; // w20
  _QWORD *v60; // [xsp+0h] [xbp-10h] BYREF
  __int64 v61; // [xsp+8h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60 = nullptr;
  if ( a4 )
  {
    v15 = a4;
    v16 = a3;
    do
    {
      if ( v15 == 1 )
      {
        v55 = "%s: IE too short";
        goto LABEL_23;
      }
      v17 = *v16;
      v18 = v16[1];
      if ( v17 == 255 )
      {
        v17 = v16[2];
        if ( v17 != 32 )
        {
          v57 = "%s: Invalid DH IE ID %d";
          goto LABEL_27;
        }
        if ( v18 <= 1 )
        {
          v57 = "%s: Invalid DH IE len %d";
          goto LABEL_29;
        }
      }
      else
      {
        if ( v17 != 48 )
        {
          v57 = "%s: Invalid IE %d";
LABEL_27:
          v56 = v17;
          goto LABEL_30;
        }
        if ( (unsigned __int8)(v18 + 117) <= 0x76u )
        {
          v57 = "%s: Invalid RSN IE len %d";
LABEL_29:
          v56 = v16[1];
LABEL_30:
          qdf_trace_msg(0x39u, 2u, v57, a6, a7, a8, a9, a10, a11, a12, a13, "wlansap_validate_owe_ie", v56, v60, v61);
LABEL_31:
          v54 = "%s: Invalid OWE IE";
LABEL_32:
          qdf_trace_msg(0x39u, 2u, v54, a6, a7, a8, a9, a10, a11, a12, a13, "wlansap_update_owe_info", v60);
          result = 5;
          goto LABEL_33;
        }
      }
      v19 = (unsigned __int8)(v18 + 2);
      v20 = v15 >= v19;
      v15 -= v19;
      if ( !v20 )
      {
        v55 = "%s: Invalid IE len";
LABEL_23:
        qdf_trace_msg(0x39u, 2u, v55, a6, a7, a8, a9, a10, a11, a12, a13, "wlansap_validate_owe_ie", v60, v61);
        goto LABEL_31;
      }
      v16 += v19;
    }
    while ( v15 );
  }
  if ( !a1 )
  {
    v54 = "%s: Invalid SAP context";
    goto LABEL_32;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a6, a7, a8, a9, a10, a11, a12, a13);
  if ( !context )
  {
    v54 = "%s: Invalid MAC context";
    goto LABEL_32;
  }
  v25 = context;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 1632), &v60) )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Failed to find assoc ind list",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlansap_update_owe_info");
    result = 16;
  }
  else
  {
    while ( 1 )
    {
      v43 = v60;
      if ( !(unsigned int)qdf_mem_cmp(a2, (const void *)(v60[2] + 5LL), 6u) )
        break;
      if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 1632), v43, &v60) )
        goto LABEL_36;
    }
    v44 = qdf_list_remove_node(a1 + 1632, v43);
    if ( v44 )
    {
      v53 = v44;
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: Failed to remove assoc ind",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "wlansap_update_owe_info");
      result = v53;
      goto LABEL_33;
    }
    v58 = v43[2];
    _qdf_mem_free((__int64)v43);
    if ( v58 )
    {
      *(_QWORD *)(v58 + 2912) = a3;
      *(_DWORD *)(v58 + 2920) = a4;
      *(_WORD *)(v58 + 2924) = a5;
      updated = sme_update_owe_info(v25, v58);
      _qdf_mem_free(v58);
      result = updated;
      goto LABEL_33;
    }
LABEL_36:
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: No match owe node",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "wlansap_update_owe_info",
      v60,
      v61);
    result = 14;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
