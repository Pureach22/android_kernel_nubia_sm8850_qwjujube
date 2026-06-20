__int64 __fastcall target_if_mlo_link_set_active(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  __int64 v11; // x8
  __int64 v12; // x8
  unsigned int active; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  const char *v26; // x2
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _DWORD *v35; // x8

  if ( !a1 )
  {
    v26 = "%s: null psoc";
LABEL_9:
    qdf_trace_msg(0x49u, 2u, v26, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_mlo_link_set_active");
    return 16;
  }
  v10 = *(_QWORD *)(a1 + 2136);
  if ( !v10 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_mlo_get_rx_ops");
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops NULL", v27, v28, v29, v30, v31, v32, v33, v34, "target_if_mlo_link_set_active");
    return 4;
  }
  v11 = *(_QWORD *)(a1 + 2800);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 16)) == 0 )
  {
    v26 = "%s: null handle";
    goto LABEL_9;
  }
  active = wmi_send_mlo_link_set_active_cmd(v12);
  if ( active )
  {
    v24 = active;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: wmi mlo link set active send failed: %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "target_if_mlo_link_set_active",
      active);
    return v24;
  }
  else
  {
    v35 = *(_DWORD **)(v10 + 1304);
    if ( v35 )
    {
      if ( *(v35 - 1) != -1560588644 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v35)(a1, a2, 0);
    }
    return 0;
  }
}
