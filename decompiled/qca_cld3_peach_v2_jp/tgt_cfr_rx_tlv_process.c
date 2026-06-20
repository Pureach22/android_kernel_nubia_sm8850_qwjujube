__int64 __fastcall tgt_cfr_rx_tlv_process(
        __int64 result,
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
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 v13; // x8
  __int64 v14; // x8

  v10 = *(_QWORD *)(result + 80);
  v11 = result;
  if ( v10 && (v13 = *(_QWORD *)(v10 + 2128)) != 0 )
  {
    v14 = *(_QWORD *)(v13 + 464);
    if ( !v14 )
      return result;
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_psoc_get_cfr_txops");
    v14 = 0x14ECE400048025LL;
  }
  if ( *(_DWORD *)(v14 - 4) != -1837742594 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64))v14)(v11, a2);
}
