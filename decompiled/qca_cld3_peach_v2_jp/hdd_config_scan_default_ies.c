__int64 __fastcall hdd_config_scan_default_ies(
        unsigned __int8 *a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w25
  __int64 v13; // x23
  unsigned int v14; // w21
  __int64 *v15; // x24
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  __int64 v25; // x0
  unsigned __int16 v26; // w8
  void *v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 result; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  char v53[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v54; // [xsp+8h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a2;
  v13 = *(_QWORD *)a1;
  v14 = v12 - 4;
  v15 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: IE len %d session %d device mode %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_config_scan_default_ies",
    (unsigned __int16)(v12 - 4),
    a1[8],
    *(unsigned int *)(*(_QWORD *)a1 + 40LL));
  if ( (_WORD)v12 == 4 )
  {
    v24 = "%s: zero-length IE prohibited";
LABEL_17:
    qdf_trace_msg(0x33u, 2u, v24, v16, v17, v18, v19, v20, v21, v22, v23, "hdd_config_scan_default_ies");
    goto LABEL_18;
  }
  if ( (unsigned __int16)(v12 - 4) >= 0x801u )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: IE length %d exceeds max of %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_config_scan_default_ies",
      (unsigned __int16)(v12 - 4),
      2048);
LABEL_18:
    result = 4294967274LL;
    goto LABEL_19;
  }
  if ( !wlan_is_ie_valid((__int64)(a2 + 2), (unsigned __int16)(v12 - 4)) )
  {
    v24 = "%s: Invalid default scan IEs";
    goto LABEL_17;
  }
  v53[0] = 0;
  v25 = *(_QWORD *)(v13 + 41680);
  if ( v25 )
  {
    _qdf_mem_free(v25);
    *(_QWORD *)(v13 + 41680) = 0;
  }
  *(_WORD *)(v13 + 41688) = v14;
  ucfg_mlme_get_qcn_ie_support(*v15, v53);
  if ( v53[0] )
    v26 = v12 + 6;
  else
    v26 = v12 - 4;
  v27 = (void *)_qdf_mem_malloc(v26, "wlan_hdd_save_default_scan_ies", 9758);
  *(_QWORD *)(v13 + 41680) = v27;
  if ( v27 )
  {
    qdf_mem_copy(v27, a2 + 2, *(unsigned __int16 *)(v13 + 41688));
    if ( v53[0] == 1 )
      sme_add_qcn_ie(v15[2], *(_QWORD *)(v13 + 41680), v13 + 41688);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Saved default scan IE:len %d",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "wlan_hdd_save_default_scan_ies",
      *(unsigned __int16 *)(v13 + 41688));
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
      51,
      8,
      *(_QWORD *)(v13 + 41680),
      *(unsigned __int16 *)(v13 + 41688));
    if ( *(_DWORD *)(v13 + 40) )
      goto LABEL_15;
  }
  else
  {
    *(_WORD *)(v13 + 41688) = 0;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to save default scan IEs",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "hdd_config_scan_default_ies");
    if ( *(_DWORD *)(v13 + 40) )
    {
LABEL_15:
      result = 0;
      goto LABEL_19;
    }
  }
  result = sme_set_default_scan_ie(v15[2], a1[8], a2 + 2, v14);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to set default scan IEs in sme: %d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "hdd_config_scan_default_ies",
      (unsigned int)result);
    result = 0xFFFFFFFFLL;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
