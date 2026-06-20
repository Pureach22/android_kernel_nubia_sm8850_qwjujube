__int64 __fastcall dp_bus_bandwidth_init(__int64 a1)
{
  __int64 comp_private_obj; // x0
  __int64 v2; // x20
  __int64 v3; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  void (__fastcall *v13)(_QWORD); // x8
  unsigned int v14; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  v2 = *(_QWORD *)(comp_private_obj + 376);
  v3 = comp_private_obj;
  if ( (unsigned int)cds_get_conparam() == 5 )
    return 0;
  qdf_trace_msg(0x45u, 8u, "%s: enter", v4, v5, v6, v7, v8, v9, v10, v11, "dp_bus_bandwidth_init");
  v13 = *(void (__fastcall **)(_QWORD))(v3 + 568);
  *(_DWORD *)(v3 + 1032) = 0;
  *(_QWORD *)(v3 + 1040) = 0;
  if ( *((_DWORD *)v13 - 1) != -528599275 )
    __break(0x8228u);
  v13(v2);
  *(_QWORD *)(v3 + 1144) = _qdf_mem_malloc(0x1400u, "wlan_dp_init_tx_rx_histogram", 1039);
  v14 = _qdf_periodic_work_create(v3 + 896, (__int64)dp_bus_bw_work_handler, v3);
  qdf_trace_msg(0x45u, 8u, "%s: exit", v15, v16, v17, v18, v19, v20, v21, v22, "dp_bus_bandwidth_init");
  return qdf_status_to_os_return(v14);
}
