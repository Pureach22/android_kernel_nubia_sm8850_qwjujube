__int64 __fastcall wlan_mlme_set_eml_params(
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
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w9
  unsigned int v21; // w9
  unsigned int v22; // w9
  unsigned int v23; // w9

  if ( (*(_WORD *)(a2 + 172) & 1) == 0 )
    return qdf_trace_msg(
             0x1Fu,
             8u,
             "%s: EMLSR supp: %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_mlme_set_eml_params",
             0);
  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( !result )
    return qdf_trace_msg(
             0x1Fu,
             2u,
             "%s: No psoc object",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "wlan_mlme_set_eml_params");
  v20 = *(_WORD *)(result + 7334) & 0xFFFE | *(_WORD *)(a2 + 172) & 1;
  *(_WORD *)(result + 7334) = *(_WORD *)(result + 7334) & 0xFFFE | *(_WORD *)(a2 + 172) & 1;
  v21 = v20 & 0xFFFFFFF1 | (2 * ((*(unsigned __int16 *)(a2 + 172) >> 1) & 7));
  *(_WORD *)(result + 7334) = v21;
  v22 = v21 & 0xFFFFFF8F | (16 * ((*(unsigned __int16 *)(a2 + 172) >> 4) & 7));
  *(_WORD *)(result + 7334) = v22;
  v23 = v22 & 0xFFFFFF7F | (((*(unsigned __int16 *)(a2 + 172) >> 7) & 1) << 7);
  *(_WORD *)(result + 7334) = v23;
  *(_WORD *)(result + 7334) = v23 & 0x87FF | *(_WORD *)(a2 + 172) & 0x7800;
  return result;
}
