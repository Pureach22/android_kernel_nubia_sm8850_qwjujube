__int64 __fastcall target_if_reg_set_offloaded_info(
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
  _QWORD *v9; // x21
  _DWORD *v11; // x22
  __int64 v12; // x8
  __int64 v13; // x20
  __int64 (*v14)(void); // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  char v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  void (__fastcall *v33)(__int64, __int64); // x20
  __int64 v34; // x1

  if ( !a1 || (v9 = *(_QWORD **)(a1 + 2136)) == nullptr )
  {
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_regulatory_get_rx_ops");
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: reg_rx_ops is NULL",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "target_if_reg_set_offloaded_info");
    return 16;
  }
  v11 = (_DWORD *)v9[57];
  if ( v11 )
  {
    v12 = *(_QWORD *)(a1 + 2800);
    if ( v12 )
    {
      v13 = *(_QWORD *)(v12 + 16);
      if ( v13 )
      {
        v14 = (__int64 (*)(void))v9[74];
        if ( !v14 )
          goto LABEL_13;
        if ( *((_DWORD *)v14 - 1) != -1548408 )
          __break(0x8228u);
        if ( (v14() & 1) == 0 )
        {
LABEL_13:
          v23 = wmi_service_enabled(v13, 131);
          goto LABEL_14;
        }
        qdf_trace_msg(
          0x49u,
          8u,
          "%s: User disabled regulatory offload from ini",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "tgt_if_regulatory_is_regdb_offloaded");
      }
    }
    v23 = 0;
LABEL_14:
    if ( *(v11 - 1) != -132374536 )
      __break(0x8236u);
    ((void (__fastcall *)(__int64, _QWORD))v11)(a1, v23 & 1);
  }
  v33 = (void (__fastcall *)(__int64, __int64))v9[58];
  if ( v33 )
  {
    v34 = tgt_if_regulatory_is_11d_offloaded(a1) & 1;
    if ( *((_DWORD *)v33 - 1) != -132374536 )
      __break(0x8234u);
    v33(a1, v34);
  }
  return 0;
}
