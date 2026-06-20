__int64 __fastcall ucfg_fwol_get_all_adaptive_dwelltime_params(__int64 a1, __int64 a2)
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
  __int64 v12; // x8
  int v14; // w9
  __int64 v15; // x8

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v12 = psoc_obj;
    v14 = *(_DWORD *)(v12 + 1304);
    v15 = *(_QWORD *)(v12 + 1296);
    *(_DWORD *)(a2 + 8) = v14;
    *(_QWORD *)a2 = v15;
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
      "ucfg_fwol_get_all_adaptive_dwelltime_params");
    return 16;
  }
}
