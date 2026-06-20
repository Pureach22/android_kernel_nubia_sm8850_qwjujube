__int64 __fastcall tgt_cfr_stop_lut_age_timer(
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
  __int64 v11; // x8
  __int64 v12; // x19

  v9 = *(_QWORD *)(result + 80);
  if ( !v9 )
    return qdf_trace_msg(
             0x6Au,
             2u,
             "%s: Invalid PSOC: Flush LUT Timer cannot be stopped\n",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "tgt_cfr_stop_lut_age_timer");
  v10 = *(_QWORD *)(v9 + 2128);
  if ( v10 )
  {
    v11 = *(_QWORD *)(v10 + 440);
    if ( !v11 )
      return result;
  }
  else
  {
    v12 = result;
    qdf_trace_msg(0x6Au, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_cfr_txops");
    result = v12;
    v11 = 0x161B0C00048025LL;
  }
  if ( *(_DWORD *)(v11 - 4) != 883436542 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64))v11)(result);
}
