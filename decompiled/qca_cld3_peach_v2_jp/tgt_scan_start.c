__int64 __fastcall tgt_scan_start(
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
  __int64 v9; // x5
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 (__fastcall *v12)(__int64, __int64); // x8
  const char *v14; // x2

  if ( !*(_QWORD *)a1 )
  {
    v14 = "%s: vdev is NULL";
LABEL_11:
    qdf_trace_msg(0x15u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_scan_start");
    return 29;
  }
  v9 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: psoc: 0x%pK or pdev: 0x%pK is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "tgt_scan_start",
      0);
    return 29;
  }
  v11 = *(_QWORD *)(v10 + 2128);
  if ( !v11 )
  {
    qdf_trace_msg(0x15u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_scan_txops");
    v14 = "%s: NULL scan_ops";
    goto LABEL_11;
  }
  v12 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + 56);
  if ( !v12 )
    return 0;
  if ( *((_DWORD *)v12 - 1) != 727004350 )
    __break(0x8228u);
  return v12(v9, a1);
}
