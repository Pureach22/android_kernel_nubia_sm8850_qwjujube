__int64 __fastcall ipa_opt_dpath_enable_clk_req(__int64 a1)
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
  __int64 result; // x0
  __int64 v12; // x19

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Au);
  if ( comp_private_obj )
  {
    if ( *(_BYTE *)(comp_private_obj + 7512) == 1 )
    {
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl, bypassing clock for unit testing",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "ipa_opt_dpath_enable_clk_req");
      return 0;
    }
    else
    {
      v12 = comp_private_obj;
      result = wlan_ipa_wdi_opt_dpath_enable_clk_req(comp_private_obj);
      if ( (_DWORD)result )
        return qdf_wait_for_event_completion(v12 + 8152, 0x1F4u);
      else
        ++*(_DWORD *)(v12 + 8412);
    }
  }
  else
  {
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
      "ipa_opt_dpath_enable_clk_req",
      *(unsigned __int8 *)(a1 + 48));
    return 16;
  }
  return result;
}
