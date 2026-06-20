__int64 __fastcall ll_lt_sap_get_tsf_stats_for_csa(__int64 a1, unsigned int a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x8
  const char *v15; // x2

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x34u);
  if ( !comp_private_obj )
  {
    v15 = "%s: psoc_ll_sap_obj is null";
LABEL_8:
    qdf_trace_msg(0xA1u, 2u, v15, v5, v6, v7, v8, v9, v10, v11, v12, "ll_lt_sap_get_tsf_stats_for_csa");
    return 4;
  }
  v13 = *(_DWORD **)(comp_private_obj + 16);
  if ( !v13 )
  {
    v15 = "%s: get_tsf_stats_for_csa op is NULL";
    goto LABEL_8;
  }
  if ( *(v13 - 1) != -132374536 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v13)(a1, a2);
}
