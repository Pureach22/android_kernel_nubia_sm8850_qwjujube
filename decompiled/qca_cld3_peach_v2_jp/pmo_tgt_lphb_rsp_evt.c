__int64 __fastcall pmo_tgt_lphb_rsp_evt(__int64 a1)
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
  void (*v11)(void); // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  v11 = *(void (**)(void))(comp_private_obj + 936);
  if ( v11 && *(_QWORD *)(comp_private_obj + 928) )
  {
    if ( *((_DWORD *)v11 - 1) != -89363269 )
      __break(0x8228u);
    v11();
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: lphb rsp callback/context is null for psoc %pK",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "pmo_tgt_lphb_rsp_evt",
      a1);
  }
  return 0;
}
