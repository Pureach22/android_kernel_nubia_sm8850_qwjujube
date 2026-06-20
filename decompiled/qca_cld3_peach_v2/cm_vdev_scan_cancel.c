__int64 __fastcall cm_vdev_scan_cancel(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  result = _qdf_mem_malloc(0x20u, "cm_vdev_scan_cancel", 1229);
  if ( result )
  {
    *(_QWORD *)result = a2;
    *(_DWORD *)(result + 16) = -1;
    *(_DWORD *)(result + 24) = *(unsigned __int8 *)(a2 + 168);
    v5 = *(unsigned __int8 *)(a1 + 40);
    *(_DWORD *)(result + 20) = 2;
    *(_DWORD *)(result + 28) = v5;
    result = wlan_scan_cancel(result);
    if ( (_DWORD)result )
      return qdf_trace_msg(
               0x68u,
               2u,
               "%s: vdev %d cancel scan request failed",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "cm_vdev_scan_cancel",
               *(unsigned __int8 *)(a2 + 168));
  }
  return result;
}
