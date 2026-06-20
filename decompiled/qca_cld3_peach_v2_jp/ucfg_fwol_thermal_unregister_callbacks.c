__int64 __fastcall ucfg_fwol_thermal_unregister_callbacks(__int64 a1)
{
  __int64 psoc_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    qdf_mem_set((void *)(psoc_obj + 1432), 8u, 0);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: Failed to get fwol obj",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "ucfg_fwol_thermal_unregister_callbacks");
    return 16;
  }
}
