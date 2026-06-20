__int64 __fastcall qcrypto_aead_rfc4309_dec_aes_ccm(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x0
  __int16 v4; // w12
  __int64 *v5; // x11
  __int64 v6; // x11

  if ( (*(_DWORD *)(a1 + 48) | 4) != 0x14 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 32);
  v3 = *(_QWORD *)(v1 + 56);
  *(_QWORD *)(a1 + 208) = 0x100000002LL;
  *(_DWORD *)(a1 + 216) = 4;
  *(_DWORD *)(a1 + 156) = 1;
  *(_QWORD *)(a1 + 144) = 0;
  *(_QWORD *)(a1 + 136) = 0;
  *(_BYTE *)(a1 + 136) = 3;
  v4 = *(_WORD *)(v1 + 228);
  *(_BYTE *)(a1 + 139) = *(_BYTE *)(v1 + 230);
  v5 = *(__int64 **)(a1 + 56);
  *(_WORD *)(a1 + 137) = v4;
  v6 = *v5;
  *(_DWORD *)(a1 + 160) = 1;
  *(_QWORD *)(a1 + 128) = a1 + 136;
  *(_QWORD *)(a1 + 140) = v6;
  ++qword_11A10;
  return qcrypto_queue_req(v3, *(_QWORD *)(v1 + 48), a1);
}
