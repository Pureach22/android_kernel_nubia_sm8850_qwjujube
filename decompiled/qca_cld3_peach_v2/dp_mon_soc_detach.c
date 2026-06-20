__int64 __fastcall dp_mon_soc_detach(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v11; // x8
  void (*v12)(void); // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x8
  __int64 v22; // x8
  const char *v24; // x2
  __int64 v25; // x9
  __int64 v26; // x21
  void (__fastcall *v27)(_QWORD); // x8
  double (__fastcall *v28)(_QWORD); // x8

  if ( !a1 )
  {
    qdf_trace_msg(0x92u, 2u, "%s: dp_soc is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_soc_detach");
    return 16;
  }
  v9 = a1[2514];
  if ( !v9 )
  {
    v24 = "%s: monitor soc is NULL";
LABEL_13:
    qdf_trace_msg(0x92u, 8u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "dp_monitor_vdev_timer_deinit");
    v21 = (_QWORD *)*a1;
    if ( !*a1 )
      goto LABEL_8;
    goto LABEL_14;
  }
  v11 = *(_QWORD *)(v9 + 416);
  if ( !v11 || (v12 = *(void (**)(void))(v11 + 512)) == nullptr )
  {
    v24 = "%s: callback not registered";
    goto LABEL_13;
  }
  if ( *((_DWORD *)v12 - 1) != -1093861181 )
    __break(0x8228u);
  v12();
  v21 = (_QWORD *)*a1;
  if ( !*a1 )
  {
LABEL_8:
    qdf_trace_msg(0x92u, 2u, "%s: cdp_ops is NULL", v13, v14, v15, v16, v17, v18, v19, v20, "dp_mon_cdp_ops_deregister");
    v22 = a1[2514];
    if ( !v22 )
      goto LABEL_24;
LABEL_15:
    v26 = *(_QWORD *)(v22 + 416);
    if ( v26 )
    {
      v27 = *(void (__fastcall **)(_QWORD))(v26 + 24);
      if ( v27 )
      {
        if ( *((_DWORD *)v27 - 1) != -1941278151 )
          __break(0x8228u);
        v27(a1);
      }
      v28 = *(double (__fastcall **)(_QWORD))(v26 + 32);
      if ( v28 )
      {
        if ( *((_DWORD *)v28 - 1) != -1941278151 )
          __break(0x8228u);
        v13 = v28(a1);
      }
    }
    goto LABEL_24;
  }
LABEL_14:
  v25 = *v21;
  v21[3] = 0;
  *(_QWORD *)(v25 + 168) = 0;
  *(_QWORD *)(*v21 + 376LL) = 0;
  *(_QWORD *)(v21[8] + 152LL) = 0;
  *(_QWORD *)(v21[8] + 160LL) = 0;
  *(_QWORD *)(v21[8] + 168LL) = 0;
  *(_QWORD *)(v21[1] + 160LL) = 0;
  *(_QWORD *)(v21[1] + 128LL) = 0;
  v22 = a1[2514];
  if ( v22 )
    goto LABEL_15;
LABEL_24:
  a1[2514] = 0;
  dp_context_free_mem((__int64)a1, 9u, v9, v13, v14, v15, v16, v17, v18, v19, v20);
  return 0;
}
