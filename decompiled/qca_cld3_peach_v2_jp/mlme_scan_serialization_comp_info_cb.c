__int64 __fastcall mlme_scan_serialization_comp_info_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 result; // x0
  const char *v15; // x2

  if ( !a1 || !a2 )
  {
    v15 = "%s: comp_info or vdev is NULL";
    return qdf_trace_msg(0x68u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "mlme_scan_serialization_comp_info_cb");
  }
  v11 = *(_QWORD *)(a1 + 152);
  if ( !v11 )
  {
    v15 = "%s: pdev is NULL";
    return qdf_trace_msg(0x68u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "mlme_scan_serialization_comp_info_cb");
  }
  v12 = *(_QWORD *)(a3 + 40);
  if ( !v12 )
  {
    v15 = "%s: scan start request is null";
    return qdf_trace_msg(0x68u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "mlme_scan_serialization_comp_info_cb");
  }
  *(_BYTE *)(a2 + 3) = 0;
  if ( !*(_DWORD *)a3 && *(_DWORD *)(v12 + 28) == 4 )
    *(_BYTE *)(a2 + 3) = 1;
  *(_BYTE *)(a2 + 2) = 0;
  result = wlan_util_is_pdev_scan_allowed(v11, 0x2Eu);
  if ( (_DWORD)result )
    *(_BYTE *)(a2 + 2) = 1;
  return result;
}
