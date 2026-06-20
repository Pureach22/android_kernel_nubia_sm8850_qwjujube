__int64 __fastcall wma_process_set_ie_info(
        _QWORD *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w5
  unsigned int v21; // w7
  unsigned int v22; // w6
  __int64 v23; // x8
  __int64 result; // x0
  _DWORD v25[4]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v26; // [xsp+18h] [xbp-18h]
  __int64 v27; // [xsp+20h] [xbp-10h]
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(0x36u, 2u, "%s: input pointer is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_set_ie_info");
    result = 16;
    goto LABEL_10;
  }
  if ( !a2[2] )
  {
    qdf_trace_msg(0x36u, 2u, "%s: Invalid IE length", a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_set_ie_info");
LABEL_9:
    result = 4;
    goto LABEL_10;
  }
  if ( (wma_is_vdev_valid(*a2, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev_id: %d is not active",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_process_set_ie_info",
      *a2);
    goto LABEL_9;
  }
  v20 = a2[1];
  v21 = a2[2];
  v22 = a2[3];
  v23 = *((_QWORD *)a2 + 2);
  v25[0] = *a2;
  v25[1] = v20;
  v25[3] = 0;
  LODWORD(v26) = v22;
  v27 = v23;
  v25[2] = v21;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev id: %d, ie_id: %d, band: %d, len: %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wma_process_set_ie_info");
  ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(54, 8, *((_QWORD *)a2 + 2), a2[2]);
  result = wmi_unified_process_set_ie_info_cmd(*a1, v25);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
