__int64 __fastcall wlan_reg_get_chip_mode(__int64 a1, _QWORD *a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0xDu);
  if ( comp_private_obj )
  {
    v12 = comp_private_obj;
    *a2 = *(_QWORD *)(v12 + 56768);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev private obj is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_reg_get_chip_mode");
    return 5;
  }
}
