__int64 __fastcall wlan_ipa_set_fw_cap_opt_dp_ctrl(__int64 a1, char a2)
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
  unsigned int v13; // w20
  __int64 v14; // x19

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Au);
  if ( comp_private_obj )
  {
    v13 = a2 & 1;
    v14 = comp_private_obj;
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: fw capability for opt_dp_ctrl, received from fw %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_ipa_set_fw_cap_opt_dp_ctrl",
      v13);
    *(_BYTE *)(v14 + 7441) = v13;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: IPA object is NULL for psoc_id[%d]",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_ipa_set_fw_cap_opt_dp_ctrl",
      *(unsigned __int8 *)(a1 + 48));
    return 16;
  }
}
