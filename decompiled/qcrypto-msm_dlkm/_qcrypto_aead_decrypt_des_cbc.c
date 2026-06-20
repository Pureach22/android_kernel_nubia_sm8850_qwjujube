__int64 __fastcall qcrypto_aead_decrypt_des_cbc(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x0
  __int64 v4; // x9
  __int64 v5; // x9

  v1 = *(_QWORD *)(a1 + 32);
  v3 = *(_QWORD *)(v1 + 56);
  *(_DWORD *)(a1 + 156) = 1;
  v4 = *(_QWORD *)(a1 + 56);
  *(_QWORD *)(a1 + 208) = 0x100000000LL;
  *(_DWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 128) = v4;
  v5 = 9;
  if ( *(_DWORD *)(v1 + 68) == 2 )
    v5 = 3;
  ++qcrypto_stat[v5];
  return qcrypto_queue_req(v3, *(_QWORD *)(v1 + 48), a1);
}
