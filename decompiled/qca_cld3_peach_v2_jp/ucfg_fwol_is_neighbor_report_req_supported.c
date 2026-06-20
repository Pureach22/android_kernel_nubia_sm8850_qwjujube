__int64 __fastcall ucfg_fwol_is_neighbor_report_req_supported(__int64 a1, _BYTE *a2)
{
  __int64 psoc_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 result; // x0
  char v15; // w8

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v13 = psoc_obj;
    result = 0;
    v15 = *(_BYTE *)(v13 + 200) & 1;
  }
  else
  {
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: Failed to get fwol obj",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "ucfg_fwol_is_neighbor_report_req_supported");
    v15 = *(_BYTE *)(cfg_psoc_get_values(a1) + 1088);
    result = 16;
  }
  *a2 = v15;
  return result;
}
