__int64 __fastcall qcrypto_aead_encrypt_des_cbc(__int64 a1)
{
  __int64 v1; // x9
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x8

  v1 = *(_QWORD *)(a1 + 32);
  v3 = *(_QWORD *)(v1 + 56);
  *(_DWORD *)(a1 + 156) = 1;
  v4 = *(_QWORD *)(a1 + 56);
  *(_QWORD *)(a1 + 208) = 0;
  *(_DWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 128) = v4;
  v5 = 8;
  if ( *(_DWORD *)(v1 + 68) == 2 )
    v5 = 2;
  ++qcrypto_stat[v5];
  return qcrypto_queue_req(v3, *(_QWORD *)(v1 + 48), a1);
}
