__int64 __fastcall target_if_cfr_set_cfr_support(
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
  __int64 (*v10)(void); // x8

  if ( !result )
    return qdf_trace_msg(
             0x6Au,
             2u,
             "%s: rx_ops is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "target_if_cfr_set_cfr_support");
  v9 = *(_QWORD *)(result + 2136);
  if ( !v9 )
    return qdf_trace_msg(
             0x6Au,
             2u,
             "%s: rx_ops is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "target_if_cfr_set_cfr_support");
  v10 = *(__int64 (**)(void))(v9 + 216);
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != 251981578 )
      __break(0x8228u);
    return v10();
  }
  return result;
}
