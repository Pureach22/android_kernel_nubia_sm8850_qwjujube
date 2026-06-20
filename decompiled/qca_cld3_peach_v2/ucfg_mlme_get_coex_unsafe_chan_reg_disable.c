__int64 __fastcall ucfg_mlme_get_coex_unsafe_chan_reg_disable(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  char v10; // w8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v10 = *(_BYTE *)(psoc_ext_obj_fl + 6608);
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: Failed to get MLME Obj",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "ucfg_mlme_get_coex_unsafe_chan_reg_disable");
    v10 = 0;
  }
  return v10 & 1;
}
