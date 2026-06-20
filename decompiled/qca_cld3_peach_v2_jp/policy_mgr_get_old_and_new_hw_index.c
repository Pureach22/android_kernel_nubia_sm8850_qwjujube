__int64 __fastcall policy_mgr_get_old_and_new_hw_index(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  __int64 comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( comp_private_obj )
  {
    v14 = comp_private_obj;
    *a2 = *(_DWORD *)(v14 + 1496);
    *a3 = *(_DWORD *)(v14 + 1500);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_get_old_and_new_hw_index");
    return 4;
  }
}
