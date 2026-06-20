__int64 __fastcall ucfg_dcs_register_afc_sel_chan_cb(__int64 a1, __int64 a2, __int64 a3)
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

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
  if ( comp_private_obj )
  {
    v14 = comp_private_obj;
    *(_QWORD *)(v14 + 1176) = a2;
    *(_QWORD *)(v14 + 1184) = a3;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x74u,
      2u,
      "%s: dcs psoc private object is null",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "ucfg_dcs_register_afc_sel_chan_cb");
    return 4;
  }
}
