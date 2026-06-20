__int64 __fastcall dp_mon_register_intr_ops(
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

  if ( !result )
    return qdf_trace_msg(
             0x92u,
             2u,
             "%s: Monitor ops is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_register_intr_ops");
  v9 = *(_QWORD *)(result + 20056);
  if ( !v9 )
    return qdf_trace_msg(
             0x92u,
             2u,
             "%s: Monitor ops is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_register_intr_ops");
  v10 = *(_QWORD *)(v9 + 416);
  if ( !v10 )
    return qdf_trace_msg(
             0x92u,
             2u,
             "%s: Monitor ops is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_register_intr_ops");
  v11 = *(__int64 (**)(void))(v10 + 896);
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != -1093861181 )
      __break(0x8228u);
    return v11();
  }
  return result;
}
