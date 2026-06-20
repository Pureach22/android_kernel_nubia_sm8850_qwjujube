__int64 __fastcall ucfg_green_ap_get_debug_prints(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  char v10; // w8

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( comp_private_obj )
  {
    v10 = *(_BYTE *)(comp_private_obj + 152);
  }
  else
  {
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: green ap context obtained is NULL",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "ucfg_green_ap_get_debug_prints");
    v10 = 0;
  }
  return v10 & 1;
}
