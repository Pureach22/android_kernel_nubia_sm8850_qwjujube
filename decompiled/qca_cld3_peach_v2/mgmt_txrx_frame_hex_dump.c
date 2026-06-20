__int64 __fastcall mgmt_txrx_frame_hex_dump(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x4
  char v16; // w21
  unsigned int frm_type; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x3
  const char *v27; // x4

  if ( a2 <= 0x17 )
    return qdf_trace_msg(
             0x4Bu,
             8u,
             "%s: frame len %d less than hdr size",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "mgmt_txrx_frame_hex_dump",
             a2);
  v15 = *(_BYTE *)a1 & 0xC;
  if ( (*(_BYTE *)a1 & 0xC) != 0 )
    return qdf_trace_msg(
             0x4Bu,
             8u,
             "%s: frame type %d not mgmt type",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "mgmt_txrx_frame_hex_dump",
             v15);
  v16 = a3;
  frm_type = mgmt_txrx_get_frm_type(*(_BYTE *)a1 & 0xF0, a1 + 24, a3, a4, v15);
  if ( (v16 & 1) != 0 )
    v26 = "TX";
  else
    v26 = (const char *)&unk_A39F4F;
  if ( frm_type > 0x8A )
    v27 = "MGMT_UNKNOWN";
  else
    v27 = off_AD0A68[frm_type];
  qdf_trace_msg(
    0x4Bu,
    8u,
    "%s MGMT: %s(%d) seq %d len %d:",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    frm_type,
    *(unsigned __int16 *)(a1 + 22) >> 4,
    a2);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(75, 8, a1, a2);
}
