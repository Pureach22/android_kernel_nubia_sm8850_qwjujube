__int64 __fastcall tgt_scan_obss_disable(
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
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 (__fastcall *v12)(__int64, __int64); // x9
  __int64 v13; // x1
  const char *v15; // x2

  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v15 = "%s: NULL PSOC";
LABEL_9:
    qdf_trace_msg(0x15u, 2u, v15, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_scan_obss_disable");
    return 16;
  }
  v11 = *(_QWORD *)(v10 + 2128);
  if ( !v11 )
  {
    qdf_trace_msg(0x15u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_scan_txops");
    v15 = "%s: NULL scan_ops";
    goto LABEL_9;
  }
  v12 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + 88);
  if ( !v12 )
    return 0;
  v13 = *(unsigned __int8 *)(a1 + 104);
  if ( *((_DWORD *)v12 - 1) != -132374536 )
    __break(0x8229u);
  return v12(v10, v13);
}
