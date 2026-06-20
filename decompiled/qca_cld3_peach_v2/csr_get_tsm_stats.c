__int64 __fastcall csr_get_tsm_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  __int64 v9; // x0
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v9 = _qdf_mem_malloc(0x20u, "csr_get_tsm_stats", 1677);
  if ( !v9 )
    return 2;
  *(_BYTE *)(v9 + 4) = a5;
  *(_DWORD *)(v9 + 5) = a3;
  *(_DWORD *)v9 = 2102352;
  *(_WORD *)(v9 + 9) = WORD2(a3);
  *(_QWORD *)(v9 + 16) = a2;
  *(_QWORD *)(v9 + 24) = a4;
  result = umac_send_mb_message_to_mac(v9);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Failed to send down the TSM req (status=%d)",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "csr_get_tsm_stats",
      (unsigned int)result);
    return 16;
  }
  return result;
}
