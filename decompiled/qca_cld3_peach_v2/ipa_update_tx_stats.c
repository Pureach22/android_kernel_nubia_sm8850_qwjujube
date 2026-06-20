__int64 __fastcall ipa_update_tx_stats(__int64 result)
{
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7

  if ( g_ipa_config && (*(_BYTE *)g_ipa_config & 1) != 0 )
  {
    result = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(result + 80), 0x1Au);
    if ( !result )
      return qdf_trace_msg(0x61u, 2u, "%s: IPA object is NULL", v1, v2, v3, v4, v5, v6, v7, v8, "ipa_update_tx_stats");
  }
  return result;
}
