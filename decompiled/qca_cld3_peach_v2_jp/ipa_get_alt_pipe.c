__int64 __fastcall ipa_get_alt_pipe(__int64 a1)
{
  __int64 v1; // x19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  if ( g_ipa_config )
  {
    if ( (*(_BYTE *)g_ipa_config & 1) != 0 )
    {
      v1 = *(_QWORD *)(a1 + 80);
      if ( (ipa_cb_is_ready(a1) & 1) != 0 && !wlan_objmgr_psoc_get_comp_private_obj(v1, 0x1Au) )
        qdf_trace_msg(0x61u, 2u, "%s: IPA object is NULL", v2, v3, v4, v5, v6, v7, v8, v9, "ipa_get_alt_pipe");
    }
  }
  return 4;
}
