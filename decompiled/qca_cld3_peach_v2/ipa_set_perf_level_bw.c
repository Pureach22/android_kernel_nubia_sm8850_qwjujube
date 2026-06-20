__int64 __fastcall ipa_set_perf_level_bw(__int64 result)
{
  __int64 v1; // x20
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  if ( g_ipa_config )
  {
    if ( (*(_BYTE *)g_ipa_config & 1) != 0 )
    {
      v1 = *(_QWORD *)(result + 80);
      result = ipa_cb_is_ready(result);
      if ( (result & 1) != 0 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v1, 0x1Au);
        if ( comp_private_obj )
          return wlan_ipa_set_perf_level_bw(comp_private_obj);
        else
          return qdf_trace_msg(
                   0x61u,
                   2u,
                   "%s: IPA object is NULL",
                   v3,
                   v4,
                   v5,
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   "ipa_set_perf_level_bw");
      }
    }
  }
  return result;
}
