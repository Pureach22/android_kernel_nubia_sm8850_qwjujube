__int64 __fastcall ipa_set_perf_level_bw_enabled(__int64 a1)
{
  __int64 v1; // x19
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  char v11; // w0

  if ( !g_ipa_config )
    return 0;
  if ( (*(_BYTE *)g_ipa_config & 1) == 0 )
    goto LABEL_8;
  v1 = *(_QWORD *)(a1 + 80);
  if ( (ipa_cb_is_ready(a1) & 1) == 0 )
    goto LABEL_8;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v1, 0x1Au);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x61u, 2u, "%s: IPA object is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "ipa_set_perf_level_bw_enabled");
LABEL_8:
    v11 = 0;
    return v11 & 1;
  }
  v11 = wlan_ipa_set_perf_level_bw_enabled(comp_private_obj);
  return v11 & 1;
}
