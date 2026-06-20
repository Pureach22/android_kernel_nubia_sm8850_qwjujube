__int64 __fastcall dp_mon_soc_attach(
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
  __int64 (__fastcall *v9)(_QWORD); // x8
  size_t v11; // x2
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  __int64 v31; // x8
  void (__fastcall *v32)(_QWORD); // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  __int64 v42; // x20
  void (__fastcall *v43)(_QWORD); // x8
  void (__fastcall *v44)(_QWORD); // x8
  __int64 v45; // x8
  __int64 v46; // x8
  void (__fastcall *v47)(_QWORD); // x8

  if ( a1 )
  {
    v9 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1472);
    if ( v9 )
    {
      if ( *((_DWORD *)v9 - 1) != -1391804861 )
        __break(0x8228u);
      v11 = v9(4);
    }
    else
    {
      v11 = 456;
    }
    v13 = dp_context_alloc_mem(a1, 9u, v11, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( v13 )
    {
      *(_QWORD *)(a1 + 20056) = v13;
      dp_mon_ops_register(a1);
      v30 = *(_QWORD *)(a1 + 20056);
      if ( v30 && (v31 = *(_QWORD *)(v30 + 416)) != 0 )
      {
        v32 = *(void (__fastcall **)(_QWORD))(v31 + 896);
        if ( v32 )
        {
          if ( *((_DWORD *)v32 - 1) != -1093861181 )
            __break(0x8228u);
          v32(a1);
        }
      }
      else
      {
        qdf_trace_msg(
          0x92u,
          2u,
          "%s: Monitor ops is NULL",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "dp_mon_register_intr_ops");
      }
      dp_mon_cdp_ops_register((_QWORD **)a1, v22, v23, v24, v25, v26, v27, v28, v29);
      v41 = *(_QWORD *)(a1 + 20056);
      if ( !v41 )
        goto LABEL_32;
      v42 = *(_QWORD *)(v41 + 416);
      if ( v42 )
      {
        v43 = *(void (__fastcall **)(_QWORD))(v42 + 8);
        if ( v43 )
        {
          if ( *((_DWORD *)v43 - 1) != -1941278151 )
            __break(0x8228u);
          v43(a1);
        }
        v44 = *(void (__fastcall **)(_QWORD))(v42 + 16);
        if ( v44 )
        {
          if ( *((_DWORD *)v44 - 1) != -1941278151 )
            __break(0x8228u);
          v44(a1);
        }
      }
      v45 = *(_QWORD *)(a1 + 20056);
      if ( v45 && (v46 = *(_QWORD *)(v45 + 416)) != 0 )
      {
        v47 = *(void (__fastcall **)(_QWORD))(v46 + 904);
        if ( v47 )
        {
          if ( *((_DWORD *)v47 - 1) != -1093861181 )
            __break(0x8228u);
          v47(a1);
        }
      }
      else
      {
LABEL_32:
        qdf_trace_msg(
          0x92u,
          2u,
          "%s: Monitor ops is NULL",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "dp_mon_register_feature_ops");
      }
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: %pK: mem allocation failed",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "dp_mon_soc_attach",
        a1);
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(0x92u, 2u, "%s: dp_soc is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_soc_attach");
    return 16;
  }
}
