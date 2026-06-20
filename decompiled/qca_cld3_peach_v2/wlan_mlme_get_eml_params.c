__int64 __fastcall wlan_mlme_get_eml_params(__int64 a1, _WORD *a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // w9
  unsigned int v13; // w9
  unsigned int v14; // w9
  unsigned int v15; // w9

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( !result )
    return qdf_trace_msg(0x1Fu, 2u, "%s: No psoc object", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_mlme_get_eml_params");
  v12 = *a2 & 0xFFFE | *(_WORD *)(result + 7334) & 1;
  *a2 = *a2 & 0xFFFE | *(_WORD *)(result + 7334) & 1;
  v13 = v12 & 0xFFFFFFF1 | (2 * ((*(unsigned __int16 *)(result + 7334) >> 1) & 7));
  *a2 = v13;
  v14 = v13 & 0xFFFFFF8F | (16 * ((*(unsigned __int16 *)(result + 7334) >> 4) & 7));
  *a2 = v14;
  v15 = v14 & 0xFFFFFF7F | (((*(unsigned __int16 *)(result + 7334) >> 7) & 1) << 7);
  *a2 = v15;
  *a2 = v15 & 0x87FF | *(_WORD *)(result + 7334) & 0x7800;
  return result;
}
