__int64 __fastcall wlansap_get_user_config_acs_ch_list(
        unsigned __int8 a1,
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v22; // x8
  __int64 v23; // x9
  int v24; // w9
  const char *v25; // x2

  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid MAC context",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlansap_get_user_config_acs_ch_list");
    return 29;
  }
  if ( a1 > 5u )
    return 4;
  v22 = context[2 * a1 + 1861];
  if ( !v22 )
  {
    v25 = "%s: vdev %d sap_ctx is NULL";
LABEL_11:
    qdf_trace_msg(0x39u, 2u, v25, v13, v14, v15, v16, v17, v18, v19, v20, "wlansap_get_user_config_acs_ch_list");
    return 29;
  }
  v23 = *(_QWORD *)(v22 + 1544);
  if ( !v23 )
  {
    v25 = "%s: vdev %d acs_cfg is NULL";
    goto LABEL_11;
  }
  v24 = *(unsigned __int8 *)(v23 + 40);
  if ( (unsigned int)(v24 - 103) < 0xFFFFFF9A )
    return 4;
  *(_WORD *)(a2 + 18) = v24;
  qdf_mem_copy((void *)(a2 + 268), *(const void **)(*(_QWORD *)(v22 + 1544) + 32LL), (unsigned int)(4 * v24));
  return 0;
}
