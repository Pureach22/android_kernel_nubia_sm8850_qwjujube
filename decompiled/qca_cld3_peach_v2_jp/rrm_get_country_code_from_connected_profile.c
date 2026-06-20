__int64 __fastcall rrm_get_country_code_from_connected_profile(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3)
{
  int country_code; // w21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  __int64 v24; // x5
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  country_code = wlan_cm_get_country_code(*(_QWORD *)(a1 + 21560), a2, a3);
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: Country info from bcn:%c%c 0x%x",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "rrm_get_country_code_from_connected_profile",
             *a3,
             a3[1],
             a3[2]);
  if ( country_code )
    result = (__int64)qdf_mem_set(a3, 3u, 0);
  if ( !*a3 )
  {
    wlan_reg_read_current_country(*(_QWORD *)(a1 + 21552), a3, v15, v16, v17, v18, v19, v20, v21, v22);
    v23 = *a3;
    v24 = a3[1];
    a3[2] = 4;
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: Current country info %c%c 0x%x",
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             "rrm_get_country_code_from_connected_profile",
             v23,
             v24,
             4);
  }
  return result;
}
