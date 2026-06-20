__int64 __fastcall csr_roam_update_config(
        __int64 a1,
        unsigned __int8 a2,
        __int16 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w20
  __int64 v16; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0

  v12 = a2;
  if ( a2 > 5u )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: update HT config requested",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "csr_roam_update_config");
    goto LABEL_6;
  }
  v16 = *(_QWORD *)(a1 + 17296) + 96LL * a2;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: update HT config requested",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "csr_roam_update_config");
  if ( !v16 )
  {
LABEL_6:
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Session does not exist for session id %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "csr_roam_update_config",
      v12);
    return 16;
  }
  v25 = _qdf_mem_malloc(0xCu, "csr_roam_update_config", 7103);
  if ( !v25 )
    return 2;
  *(_BYTE *)(v25 + 4) = a2;
  *(_WORD *)(v25 + 6) = a3;
  *(_DWORD *)v25 = 791691;
  *(_DWORD *)(v25 + 8) = a4;
  return umac_send_mb_message_to_mac(v25);
}
