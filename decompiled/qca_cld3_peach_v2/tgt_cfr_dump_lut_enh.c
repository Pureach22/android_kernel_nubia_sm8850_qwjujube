__int64 __fastcall tgt_cfr_dump_lut_enh(
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
  __int64 v10; // x19
  __int64 v11; // x8
  __int64 v12; // x8

  v9 = *(_QWORD *)(result + 80);
  v10 = result;
  if ( v9 && (v11 = *(_QWORD *)(v9 + 2128)) != 0 )
  {
    v12 = *(_QWORD *)(v11 + 456);
    if ( !v12 )
      return result;
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_cfr_txops");
    v12 = 0xB437D400161CCCLL;
  }
  if ( *(_DWORD *)(v12 - 4) != 883436542 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64))v12)(v10);
}
