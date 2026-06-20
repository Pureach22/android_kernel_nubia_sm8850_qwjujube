__int64 __fastcall hdd_uninit(
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
  __int64 v18; // x8
  _DWORD *v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2

  qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_uninit", a1 + 296);
  if ( *(_DWORD *)(a1 + 2688) != 1885692259 )
  {
    v44 = "%s: Invalid magic";
LABEL_8:
    qdf_trace_msg(0x33u, 2u, v44, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_uninit");
    return qdf_trace_msg(0x33u, 8u, "%s: exit", v36, v37, v38, v39, v40, v41, v42, v43, "hdd_uninit");
  }
  if ( !*(_QWORD *)(a1 + 2712) )
  {
    v44 = "%s: NULL hdd_ctx";
    goto LABEL_8;
  }
  v18 = *(_QWORD *)(a1 + 2720);
  v19 = (_DWORD *)(a1 + 2688);
  if ( v18 != a1 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid device reference", v10, v11, v12, v13, v14, v15, v16, v17, "hdd_uninit");
    v18 = *(_QWORD *)(a1 + 2720);
  }
  qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v10, v11, v12, v13, v14, v15, v16, v17, "hdd_deinit_adapter", v18 + 296);
  hdd_deinit_session((__int64)v19, v20, v21, v22, v23, v24, v25, v26, v27);
  qdf_trace_msg(0x33u, 8u, "%s: exit", v28, v29, v30, v31, v32, v33, v34, v35, "hdd_deinit_adapter");
  *v19 = 0;
  return qdf_trace_msg(0x33u, 8u, "%s: exit", v36, v37, v38, v39, v40, v41, v42, v43, "hdd_uninit");
}
