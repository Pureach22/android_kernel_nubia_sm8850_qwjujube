__int64 __fastcall sha1_hmac_digest(__int64 a1)
{
  __int64 v1; // x10
  __int64 v3; // x21
  __int64 v4; // x20
  int v6; // w9

  v1 = *(_QWORD *)(a1 + 32);
  *(_DWORD *)(a1 + 292) = 0;
  ++qword_11A80;
  *(_WORD *)(a1 + 224) = 1;
  *(_QWORD *)(a1 + 200) = 0;
  *(_QWORD *)(a1 + 208) = 0;
  *(_DWORD *)(a1 + 472) = -253635901;
  *(_QWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 456) = 0x89ABCDEF01234567LL;
  *(_QWORD *)(a1 + 464) = 0x76543210FEDCBA98LL;
  *(_QWORD *)(v1 + 68) = 0x1400000002LL;
  v3 = *(_QWORD *)(a1 + 32);
  v4 = *(_QWORD *)(v3 + 56);
  if ( *(_BYTE *)(v4 + 25) == 1 && (unsigned int)copy_source(a1) )
    return 4294967284LL;
  v6 = *(_DWORD *)(a1 + 48);
  *(_QWORD *)(a1 + 128) = *(_QWORD *)(a1 + 56);
  *(_DWORD *)(a1 + 136) = v6;
  *(_WORD *)(a1 + 224) = 257;
  return qcrypto_queue_req(v4, *(_QWORD *)(v3 + 48), a1);
}
