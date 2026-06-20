__int64 __fastcall dp_pdev_bkp_stats_attach(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  v1 = a1 + 94208;
  *(_QWORD *)(a1 + 95496) = &dp_bk_pressure_stats_handler;
  *(_QWORD *)(a1 + 95464) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 95552) = a1 + 95544;
  *(_QWORD *)(a1 + 95544) = 0;
  *(_DWORD *)(a1 + 95520) = 0;
  *(_BYTE *)(a1 + 95524) = 0;
  *(_QWORD *)(a1 + 95504) = a1;
  *(_QWORD *)(a1 + 95472) = a1 + 95472;
  *(_QWORD *)(a1 + 95480) = a1 + 95472;
  *(_QWORD *)(a1 + 95488) = _qdf_defer_func;
  v2 = alloc_workqueue("dp_bkp_work_queue", 2, 0);
  *(_QWORD *)(v1 + 1304) = v2;
  if ( v2 )
  {
    *(_DWORD *)(v1 + 1320) = 0;
    *(_QWORD *)(v1 + 1328) = 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(0x80u, 1u, "%s: BKP stats attach failed", v3, v4, v5, v6, v7, v8, v9, v10, "dp_pdev_bkp_stats_attach");
    flush_work(v1 + 1256);
    cancel_work_sync(v1 + 1256);
    return 16;
  }
}
