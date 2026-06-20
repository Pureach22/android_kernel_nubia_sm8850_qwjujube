__int64 __fastcall pre_cac_stop(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  __int64 result; // x0

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Du);
  if ( !comp_private_obj )
    return qdf_trace_msg(0x98u, 2u, "%s:%u: psoc_priv is NULL", v2, v3, v4, v5, v6, v7, v8, v9, "pre_cac_stop", 35);
  v10 = comp_private_obj;
  result = qdf_trace_msg(0x98u, 8u, "%s: flush pre_cac_work", v2, v3, v4, v5, v6, v7, v8, v9, "pre_cac_stop");
  if ( *(_QWORD *)(v10 + 32) )
    return flush_work(v10);
  return result;
}
