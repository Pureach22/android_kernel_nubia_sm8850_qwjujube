__int64 __fastcall tgt_mc_cp_stats_inc_wake_lock_stats(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  _DWORD *v13; // x8

  if ( !a1 || (v12 = *(_QWORD *)(a1 + 2128)) == 0 )
  {
    qdf_trace_msg(0x62u, 2u, "%s: tx_ops is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "target_if_cp_stats_get_tx_ops");
    return 29;
  }
  v13 = *(_DWORD **)(v12 + 288);
  if ( !v13 )
    return 29;
  if ( *(v13 - 1) != 69631691 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD, __int64, __int64))v13)(a2, a3, a4);
  return 0;
}
