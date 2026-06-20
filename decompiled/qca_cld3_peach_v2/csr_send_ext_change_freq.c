__int64 __fastcall csr_send_ext_change_freq(__int64 a1, int a2, char a3)
{
  __int64 v5; // x0

  v5 = _qdf_mem_malloc(0xCu, "csr_send_ext_change_freq", 7348);
  if ( !v5 )
    return 2;
  *(_BYTE *)(v5 + 8) = a3;
  *(_DWORD *)v5 = 791671;
  *(_DWORD *)(v5 + 4) = a2;
  return umac_send_mb_message_to_mac(v5);
}
