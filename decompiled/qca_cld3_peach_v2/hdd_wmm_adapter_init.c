__int64 __fastcall hdd_wmm_adapter_init(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_wmm_adapter_init");
  hdd_wmm_dscp_initial_state(a1, v10, v11, v12, v13, v14, v15, v16, v17);
  *(_BYTE *)(a1 + 3000) = 0;
  *(_QWORD *)(a1 + 1816) = a1 + 1816;
  *(_QWORD *)(a1 + 1824) = a1 + 1816;
  _mutex_init(a1 + 1832, "&adapter->hdd_wmm_status.mutex", &hdd_wmm_adapter_init___key);
  *(_QWORD *)(a1 + 1880) = 0;
  *(_QWORD *)(a1 + 2160) = 0;
  *(_QWORD *)(a1 + 2440) = 0;
  *(_QWORD *)(a1 + 2720) = 0;
  *(_BYTE *)(a1 + 41697) = -1;
  return 0;
}
