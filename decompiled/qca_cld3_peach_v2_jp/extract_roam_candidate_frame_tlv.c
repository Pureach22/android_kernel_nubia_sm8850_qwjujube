__int64 __fastcall extract_roam_candidate_frame_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        int a11,
        __int64 a12)
{
  __int64 v12; // x9
  unsigned int v13; // w4
  const char *v14; // x2
  unsigned int v16; // w8
  __int64 v18; // x8
  __int64 v19; // x3
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  if ( !a10 || !a11 )
  {
    v14 = "%s: Empty roam candidate frame event";
LABEL_6:
    qdf_trace_msg(0x31u, 8u, v14, a1, a2, a3, a4, a5, a6, a7, a8, "extract_roam_candidate_frame_tlv");
    return 16;
  }
  v12 = *a10;
  v13 = *(_DWORD *)(*a10 + 4);
  if ( v13 < 6 )
  {
    v16 = *(_DWORD *)(v12 + 8);
    if ( v16 > *((_DWORD *)a10 + 6) )
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Invalid frame length %d expected : %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_roam_candidate_frame_tlv",
        v16);
      return 16;
    }
    if ( a10[2] )
    {
      *(_BYTE *)a12 = v13;
      *(_DWORD *)(a12 + 16) = *(_DWORD *)(v12 + 12);
      *(_DWORD *)(a12 + 4) = *(_DWORD *)(v12 + 8);
      v18 = a10[2];
      *(_BYTE *)(a12 + 20) = 1;
      *(_QWORD *)(a12 + 8) = v18;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Frame: vdev %d, rssi: %d, frame_length: %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_roam_candidate_frame_tlv");
      mgmt_txrx_frame_hex_dump(
        *(_QWORD *)(a12 + 8),
        *(_DWORD *)(a12 + 4),
        0,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27);
      return 0;
    }
    v14 = "%s: Frame pointer is Null";
    goto LABEL_6;
  }
  qdf_trace_msg(0x31u, 8u, "%s: Invalid VDEV id %d", a1, a2, a3, a4, a5, a6, a7, a8, "extract_roam_candidate_frame_tlv");
  return 16;
}
