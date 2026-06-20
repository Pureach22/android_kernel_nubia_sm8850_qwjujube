__int64 __fastcall notify_thermal_throttle_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_obj; // x0
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 (__fastcall *v22)(__int64, __int64); // x8
  const char *v24; // x2

  if ( !a1 )
  {
    v24 = "%s: NULL psoc handle";
LABEL_10:
    qdf_trace_msg(0x66u, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "notify_thermal_throttle_handler");
    return 4;
  }
  psoc_obj = fwol_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v24 = "%s: Failed to get FWOL Obj";
    goto LABEL_10;
  }
  v13 = psoc_obj;
  qdf_trace_msg(
    0x66u,
    8u,
    "thermal evt: pdev %d lvl %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    *(unsigned int *)(a2 + 8),
    *(unsigned int *)(a2 + 4));
  if ( *(_DWORD *)(a2 + 8) > *(_DWORD *)(v13 + 1428) )
    return 16;
  *(_DWORD *)(v13 + 1424) = *(_DWORD *)(a2 + 4);
  v22 = *(__int64 (__fastcall **)(__int64, __int64))(v13 + 1432);
  *(_DWORD *)(v13 + 1428) = *(_DWORD *)(a2 + 8);
  if ( !v22 )
  {
    qdf_trace_msg(
      0x66u,
      8u,
      "%s: no thermal throttle handler",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "notify_thermal_throttle_handler");
    return 16;
  }
  if ( *((_DWORD *)v22 - 1) != 76461256 )
    __break(0x8228u);
  return v22(a1, a2);
}
