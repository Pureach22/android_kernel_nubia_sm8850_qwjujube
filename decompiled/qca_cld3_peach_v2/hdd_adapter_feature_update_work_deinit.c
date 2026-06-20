__int64 __fastcall hdd_adapter_feature_update_work_deinit(
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
  const char *v18; // x2

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_adapter_feature_update_work_deinit");
  if ( *(_DWORD *)(a1 + 52520) == 1 )
  {
    cancel_work_sync(a1 + 52472);
    flush_work(a1 + 52472);
    v18 = "%s: exit";
    *(_DWORD *)(a1 + 52520) = 0;
  }
  else
  {
    v18 = "%s: work not yet init";
  }
  return qdf_trace_msg(0x33u, 8u, v18, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_adapter_feature_update_work_deinit");
}
