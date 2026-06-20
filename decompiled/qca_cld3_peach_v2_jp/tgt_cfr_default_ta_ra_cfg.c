__int64 __fastcall tgt_cfr_default_ta_ra_cfg(
        __int64 result,
        __int64 a2,
        char a3,
        unsigned int a4,
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
  __int64 v16; // x8
  __int64 v17; // x8

  v12 = *(_QWORD *)(result + 80);
  if ( v12 && (v16 = *(_QWORD *)(v12 + 2128)) != 0 )
  {
    v17 = *(_QWORD *)(v16 + 448);
    if ( !v17 )
      return result;
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: tx_ops is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_psoc_get_cfr_txops");
    v17 = 0x4802500A3DCE0LL;
  }
  if ( *(_DWORD *)(v17 - 4) != 64662584 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v17)(a2, a3 & 1, a4);
}
