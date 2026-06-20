__int64 __fastcall target_if_cfr_info_send(
        __int64 result,
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
  __int64 v10; // x8
  __int64 (*v11)(void); // x8

  v9 = *(_QWORD *)(result + 80);
  if ( !v9 )
    return qdf_trace_msg(0x6Au, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_cfr_info_send");
  v10 = *(_QWORD *)(v9 + 2136);
  if ( !v10 )
    return qdf_trace_msg(0x6Au, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_cfr_info_send");
  v11 = *(__int64 (**)(void))(v10 + 224);
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != 1435207299 )
      __break(0x8228u);
    return v11();
  }
  return result;
}
