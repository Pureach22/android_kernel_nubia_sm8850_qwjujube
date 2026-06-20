__int64 __fastcall cm_handle_roam_reason_deauth(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
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
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x23
  _DWORD *v26; // x8
  __int64 v27; // x0

  result = (__int64)_cds_get_context(54, (__int64)"wma_handle_roam_reason_deauth", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( result )
  {
    v25 = result;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Received disconnect roam event reason:%d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wma_handle_roam_reason_deauth",
      a2);
    v26 = *(_DWORD **)(v25 + 3112);
    v27 = *(_QWORD *)(v25 + 16);
    if ( *(v26 - 1) != -1239420618 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD, _QWORD))v26)(v27, a1, a3, a4, a2);
    result = _qdf_mem_malloc(0xB00u, "wma_handle_roam_reason_deauth", 2933);
    if ( result )
    {
      *(_BYTE *)(result + 13) = a1;
      return _qdf_mem_free(result);
    }
  }
  return result;
}
