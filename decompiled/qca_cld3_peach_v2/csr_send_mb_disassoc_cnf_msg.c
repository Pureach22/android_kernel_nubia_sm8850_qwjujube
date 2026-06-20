__int64 __fastcall csr_send_mb_disassoc_cnf_msg(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  int v4; // w9
  int v5; // w9

  v3 = _qdf_mem_malloc(0x18u, "csr_send_mb_disassoc_cnf_msg", 6215);
  if ( !v3 )
    return 2;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)v3 = 1577995;
  *(_BYTE *)(v3 + 4) = *(_BYTE *)(a2 + 4);
  v4 = *(_DWORD *)(a2 + 18);
  *(_WORD *)(v3 + 22) = *(_WORD *)(a2 + 22);
  *(_DWORD *)(v3 + 18) = v4;
  v5 = *(_DWORD *)(a2 + 12);
  *(_WORD *)(v3 + 16) = *(_WORD *)(a2 + 16);
  *(_DWORD *)(v3 + 12) = v5;
  return umac_send_mb_message_to_mac(v3);
}
