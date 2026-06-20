__int64 __fastcall ucfg_dp_update_link_mac_addr(__int64 a1, int *a2, char a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 comp_private_obj; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w9
  __int64 result; // x0

  dp_get_context();
  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", v6, v7, v8, v9, v10, v11, v12, v13, "dp_get_vdev_priv_obj");
    comp_private_obj = 0;
  }
  if ( (is_dp_link_valid(comp_private_obj, v15, v16, v17, v18, v19, v20, v21, v22) & 1) != 0 )
  {
    v31 = *a2;
    if ( (a3 & 1) != 0 )
      result = 11;
    else
      result = 0;
    *(_WORD *)(comp_private_obj + 29) = *((_WORD *)a2 + 2);
    *(_DWORD *)(comp_private_obj + 25) = v31;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: dp_link from vdev %pK is invalid",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "ucfg_dp_update_link_mac_addr",
      a1);
    return 4;
  }
  return result;
}
