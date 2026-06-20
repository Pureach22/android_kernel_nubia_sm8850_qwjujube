__int64 __fastcall ipa_opt_dpath_disable_clk_req(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Au);
  if ( comp_private_obj )
    return wlan_ipa_wdi_opt_dpath_disable_clk_req(comp_private_obj, v3, v4, v5, v6, v7, v8, v9, v10);
  qdf_trace_msg(
    0x61u,
    2u,
    "%s: IPA object is NULL for psoc_id[%d]",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "ipa_opt_dpath_disable_clk_req",
    *(unsigned __int8 *)(a1 + 48));
  return 16;
}
