__int64 __fastcall ucfg_fwol_get_enable_secondary_rate(__int64 a1, int *a2)
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
  int v12; // w8
  __int64 result; // x0

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v12 = *(_DWORD *)(psoc_obj + 1292);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: Failed to get FWOL obj",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "ucfg_fwol_get_enable_secondary_rate");
    result = 16;
    v12 = 23;
  }
  *a2 = v12;
  return result;
}
