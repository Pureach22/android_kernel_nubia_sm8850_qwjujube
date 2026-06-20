__int64 __fastcall dp_bus_bandwidth_deinit(__int64 a1)
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
  __int64 v10; // x20
  __int64 v11; // x19
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  void (__fastcall *v22)(_QWORD); // x8
  const char *v23; // x2
  unsigned int v24; // w1

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( comp_private_obj )
  {
    v10 = *(_QWORD *)(comp_private_obj + 376);
    v11 = comp_private_obj;
    result = cds_get_conparam();
    if ( (_DWORD)result == 5 )
      return result;
    qdf_trace_msg(0x45u, 8u, "%s: enter", v13, v14, v15, v16, v17, v18, v19, v20, "dp_bus_bandwidth_deinit");
    qdf_periodic_work_stop_sync(v11 + 896);
    _qdf_periodic_work_destroy(v11 + 896);
    v21 = *(_QWORD *)(v11 + 1144);
    if ( v21 )
    {
      _qdf_mem_free(v21);
      *(_QWORD *)(v11 + 1144) = 0;
    }
    v22 = *(void (__fastcall **)(_QWORD))(v11 + 576);
    if ( *((_DWORD *)v22 - 1) != -528599275 )
      __break(0x8228u);
    v22(v10);
    v23 = "%s: exit";
    v24 = 8;
  }
  else
  {
    v23 = "%s: Unable to get DP context";
    v24 = 2;
  }
  return qdf_trace_msg(0x45u, v24, v23, v2, v3, v4, v5, v6, v7, v8, v9, "dp_bus_bandwidth_deinit");
}
