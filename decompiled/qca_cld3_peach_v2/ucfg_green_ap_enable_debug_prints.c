__int64 __fastcall ucfg_green_ap_enable_debug_prints(__int64 a1, int a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( !result )
    return qdf_trace_msg(
             0x5Du,
             2u,
             "%s: green ap context obtained is NULL",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "ucfg_green_ap_enable_debug_prints");
  *(_BYTE *)(result + 152) = a2 != 0;
  return result;
}
