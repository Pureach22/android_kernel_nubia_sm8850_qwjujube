__int64 __fastcall wlan_green_ap_send_ll_ps_event_params(__int64 a1, __int64 a2)
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
  __int64 v12; // x0
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // t2

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( comp_private_obj )
  {
    v14 = comp_private_obj + 120;
    v12 = *(_QWORD *)(comp_private_obj + 120);
    v13 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 8);
    if ( *((_DWORD *)v13 - 1) != 1261451295 )
      __break(0x8228u);
    return v13(v12, a2);
  }
  else
  {
    qdf_trace_msg(
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
      "wlan_green_ap_send_ll_ps_event_params");
    return 16;
  }
}
