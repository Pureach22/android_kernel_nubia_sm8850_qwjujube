__int64 __fastcall ipa_uc_shutdown_opt_dp_ctrl_cleanup(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v1 = *(_QWORD *)(a1 + 80);
  result = ipa_cb_is_ready(a1);
  if ( (result & 1) != 0 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v1, 0x1Au);
    if ( comp_private_obj )
      return wlan_ipa_uc_shutdown_opt_dp_ctrl_cleanup(comp_private_obj);
    else
      return qdf_trace_msg(
               0x61u,
               2u,
               "%s: IPA object is NULL",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "ipa_uc_shutdown_opt_dp_ctrl_cleanup");
  }
  return result;
}
