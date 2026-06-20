__int64 __fastcall policy_mgr_get_updated_fw_mode_config(__int64 a1, unsigned int *a2, char a3, char a4)
{
  __int64 comp_private_obj; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w8
  int v17; // w9

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( comp_private_obj )
  {
    if ( (a3 & 1) != 0 )
      v16 = 0x80000000;
    else
      v16 = 0;
    if ( (a4 & 1) != 0 )
      v17 = 0x40000000;
    else
      v17 = 0;
    *a2 = (v17 | v16) & 0xC0000000 | *(_DWORD *)(comp_private_obj + 1516) & 0x3FFFFFFF;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: fw_mode_config:%x ",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "policy_mgr_get_updated_fw_mode_config");
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "policy_mgr_get_updated_fw_mode_config");
    return 16;
  }
}
