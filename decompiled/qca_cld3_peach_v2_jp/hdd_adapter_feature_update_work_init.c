__int64 __fastcall hdd_adapter_feature_update_work_init(
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
  __int64 v10; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v10 = a1 + 49152;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_adapter_feature_update_work_init");
  *(_QWORD *)(v10 + 3360) = a1;
  *(_QWORD *)(v10 + 3352) = hdd_adapter_param_update_work;
  *(_QWORD *)(v10 + 3320) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v10 + 3328) = v10 + 3328;
  *(_QWORD *)(v10 + 3336) = v10 + 3328;
  *(_QWORD *)(v10 + 3344) = _qdf_defer_func;
  *(_DWORD *)(v10 + 3368) = 1;
  qdf_trace_msg(0x33u, 8u, "%s: exit", v11, v12, v13, v14, v15, v16, v17, v18, "hdd_adapter_feature_update_work_init");
  return 0;
}
