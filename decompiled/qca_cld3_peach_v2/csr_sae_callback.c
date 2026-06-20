__int64 __fastcall csr_sae_callback(
        _QWORD *a1,
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
  __int64 result; // x0
  unsigned int v13; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  __int64 v23; // x8
  _DWORD *v24; // x8
  __int64 v25; // x0

  if ( !a2 )
    return qdf_trace_msg(0x34u, 2u, "%s: SAE info is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "csr_sae_callback");
  result = qdf_trace_msg(
             0x34u,
             8u,
             "%s: vdev_id %d %02x:%02x:%02x:**:**:%02x",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "csr_sae_callback",
             *(unsigned int *)(a2 + 4),
             *(unsigned __int8 *)(a2 + 8),
             *(unsigned __int8 *)(a2 + 9),
             *(unsigned __int8 *)(a2 + 10),
             *(unsigned __int8 *)(a2 + 13));
  v13 = *(_DWORD *)(a2 + 4);
  if ( v13 != 255 )
  {
    result = _qdf_mem_malloc(0x180u, "csr_sae_callback", 131);
    if ( result )
    {
      v22 = result;
      *(_QWORD *)(result + 328) = a2;
      if ( a1 && v13 <= 5 && (v23 = a1[2162]) != 0 && (*(_BYTE *)(v23 + 96LL * v13 + 1) & 1) != 0 )
      {
        wlan_get_operation_chan_freq_vdev_id(a1[2704], v13);
        v24 = (_DWORD *)a1[2755];
        if ( v24 )
        {
          v25 = a1[2703];
          if ( *(v24 - 1) != 1469140685 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))v24)(v25, v13, v22, 49, 0);
        }
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Session ID: %d is not valid",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "csr_roam_call_callback",
          v13);
      }
      return _qdf_mem_free(v22);
    }
  }
  return result;
}
