__int64 __fastcall target_if_set_regulatory_is_both_psd_eirp_support_for_sp(
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
  __int64 v9; // x8
  void (__fastcall *v10)(__int64, __int64); // x19
  __int64 v11; // x8
  __int64 v12; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2136)) != 0 )
  {
    v10 = *(void (__fastcall **)(__int64, __int64))(v9 + 640);
    if ( v10 )
    {
      v11 = *(_QWORD *)(a1 + 2800);
      if ( v11 )
      {
        v11 = *(_QWORD *)(v11 + 16);
        if ( v11 )
        {
          v12 = a1;
          LOBYTE(v11) = wmi_service_enabled(v11, 308);
          a1 = v12;
        }
      }
      if ( *((_DWORD *)v10 - 1) != -132374536 )
        __break(0x8233u);
      v10(a1, v11 & 1);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_regulatory_get_rx_ops");
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: reg_rx_ops is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_set_regulatory_is_both_psd_eirp_support_for_sp");
    return 16;
  }
}
