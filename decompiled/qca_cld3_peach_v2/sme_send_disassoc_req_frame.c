__int64 __fastcall sme_send_disassoc_req_frame(__int64 a1, char a2, const void *a3, __int16 a4, char a5)
{
  __int64 result; // x0
  __int64 v10; // x22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  result = _qdf_mem_malloc(0x10u, "sme_send_disassoc_req_frame", 13064);
  if ( result )
  {
    *(_BYTE *)(result + 4) = a2;
    v10 = result;
    *(_DWORD *)result = 1053825;
    qdf_mem_copy((void *)(result + 5), a3, 6u);
    *(_WORD *)(v10 + 12) = a4;
    *(_BYTE *)(v10 + 14) = a5;
    result = umac_send_mb_message_to_mac(v10);
    if ( (_DWORD)result )
      return qdf_trace_msg(
               0x34u,
               2u,
               "%s: umac_send_mb_message_to_mac failed, %d",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "sme_send_disassoc_req_frame",
               (unsigned int)result);
  }
  return result;
}
