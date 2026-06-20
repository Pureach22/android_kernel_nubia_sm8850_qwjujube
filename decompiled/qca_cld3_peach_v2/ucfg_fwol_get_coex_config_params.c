__int64 __fastcall ucfg_fwol_get_coex_config_params(__int64 a1, _QWORD *a2)
{
  __int64 psoc_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD *v12; // x8
  __int64 v14; // x9
  __int64 v15; // x8
  __int64 v16; // x10
  _QWORD *v17; // t2

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v12 = (_QWORD *)psoc_obj;
    v14 = *(_QWORD *)((char *)v12 + 14);
    v17 = v12;
    v15 = *v12;
    v16 = v17[1];
    *(_QWORD *)((char *)a2 + 14) = v14;
    *a2 = v15;
    a2[1] = v16;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: Failed to get fwol obj",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "ucfg_fwol_get_coex_config_params");
    return 16;
  }
}
