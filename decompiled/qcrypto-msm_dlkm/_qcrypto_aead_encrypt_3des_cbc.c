__int64 __fastcall qcrypto_aead_encrypt_3des_cbc(__int64 a1)
{
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // x0
  __int64 v5; // x8

  v2 = *(_QWORD *)(a1 + 32);
  v3 = *(_QWORD *)(a1 + 56);
  v4 = *(_QWORD *)(v2 + 56);
  *(_DWORD *)(a1 + 156) = 1;
  *(_QWORD *)(a1 + 208) = 1;
  *(_DWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 128) = v3;
  v5 = 10;
  if ( *(_DWORD *)(v2 + 68) == 2 )
    v5 = 4;
  ++qcrypto_stat[v5];
  return qcrypto_queue_req(v4, *(_QWORD *)(v2 + 48), a1);
}
