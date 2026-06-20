__int64 __fastcall qcrypto_aead_decrypt_aes_ccm(__int64 a1)
{
  __int64 v1; // x8
  int v3; // w9
  __int64 v5; // x0
  __int64 v6; // x11
  __int64 v7; // x12

  v1 = *(_QWORD *)(a1 + 32);
  if ( (unsigned int)(*(_DWORD *)(v1 + 220) - 4) > 0xC || (*(_DWORD *)(v1 + 220) & 1) != 0 )
    return 4294967274LL;
  v3 = *(_DWORD *)(v1 + 224);
  v5 = *(_QWORD *)(v1 + 56);
  if ( v3 != 32 && v3 != 16 )
    return 4294967274LL;
  v6 = *(_QWORD *)(a1 + 56);
  *(_QWORD *)(a1 + 156) = 1;
  v7 = qword_11A00;
  *(_QWORD *)(a1 + 208) = 0x100000002LL;
  *(_DWORD *)(a1 + 216) = 4;
  *(_QWORD *)(a1 + 128) = v6;
  qword_11A00 = v7 + 1;
  return qcrypto_queue_req(v5, *(_QWORD *)(v1 + 48), a1);
}
