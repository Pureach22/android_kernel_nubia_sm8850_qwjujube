__int64 __fastcall ucfg_mlme_get_restart_beaconing_on_ch_avoid(__int64 a1, _DWORD *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v12 = psoc_ext_obj_fl;
    *a2 = *(_DWORD *)(v12 + 5980);
    return 0;
  }
  else
  {
    *a2 = 1;
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: Failed to get MLME Obj",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "ucfg_mlme_get_restart_beaconing_on_ch_avoid");
    return 4;
  }
}
