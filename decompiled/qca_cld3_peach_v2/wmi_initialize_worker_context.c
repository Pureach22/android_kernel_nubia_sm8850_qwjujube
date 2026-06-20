__int64 __fastcall wmi_initialize_worker_context(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0
  const char *v13; // x2

  v2 = alloc_workqueue("wmi_rx_event_work_queue", 2, 0);
  *(_QWORD *)(a1 + 160) = v2;
  if ( v2 )
  {
    *(_QWORD *)(a1 + 144) = wmi_rx_event_work;
    *(_QWORD *)(a1 + 152) = a1;
    *(_DWORD *)(a1 + 72) = 0;
    *(_QWORD *)(a1 + 80) = 0;
    *(_QWORD *)(a1 + 88) = 0;
    *(_QWORD *)(a1 + 96) = 0;
    *(_QWORD *)(a1 + 104) = 0;
    *(_QWORD *)(a1 + 112) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 120) = a1 + 120;
    *(_QWORD *)(a1 + 128) = a1 + 120;
    *(_QWORD *)(a1 + 136) = _qdf_defer_func;
    v11 = alloc_workqueue("wmi_rx_diag_event_work_queue", 2, 0);
    *(_QWORD *)(a1 + 168) = v11;
    if ( v11 )
    {
      *(_QWORD *)(a1 + 248) = wmi_rx_diag_event_work;
      *(_QWORD *)(a1 + 256) = a1;
      *(_DWORD *)(a1 + 176) = 0;
      *(_QWORD *)(a1 + 184) = 0;
      *(_QWORD *)(a1 + 192) = 0;
      *(_QWORD *)(a1 + 200) = 0;
      *(_QWORD *)(a1 + 208) = 0;
      *(_QWORD *)(a1 + 216) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(a1 + 224) = a1 + 224;
      *(_QWORD *)(a1 + 232) = a1 + 224;
      *(_QWORD *)(a1 + 240) = _qdf_defer_func;
      *(_DWORD *)(a1 + 264) = 0;
      return 0;
    }
    v13 = "%s: failed to create wmi_rx_diag_event_work_queue";
  }
  else
  {
    v13 = "%s: failed to create wmi_rx_event_work_queue";
  }
  qdf_trace_msg(0x31u, 2u, v13, v3, v4, v5, v6, v7, v8, v9, v10, "wmi_initialize_worker_context");
  return 1;
}
