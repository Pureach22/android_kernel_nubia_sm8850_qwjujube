__int64 __fastcall sha256_hmac_digest(__int64 a1)
{
  __int64 v1; // x11
  __int64 v2; // x9
  __int64 v4; // x21
  __int64 v5; // x20
  int v7; // w9

  v1 = *(_QWORD *)(a1 + 32);
  v2 = qword_11A88;
  *(_DWORD *)(a1 + 292) = 0;
  qword_11A88 = v2 + 1;
  *(_WORD *)(a1 + 224) = 1;
  *(_QWORD *)(a1 + 200) = 0;
  *(_QWORD *)(a1 + 208) = 0;
  *(_QWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 456) = 0x85AE67BB67E6096ALL;
  *(_QWORD *)(a1 + 464) = 0x3AF54FA572F36E3CLL;
  *(_QWORD *)(a1 + 472) = 0x8C68059B7F520E51LL;
  *(_QWORD *)(a1 + 480) = 0x19CDE05BABD9831FLL;
  *(_QWORD *)(v1 + 68) = 0x2000000003LL;
  v4 = *(_QWORD *)(a1 + 32);
  v5 = *(_QWORD *)(v4 + 56);
  if ( *(_BYTE *)(v5 + 25) == 1 && (unsigned int)copy_source(a1) )
    return 4294967284LL;
  v7 = *(_DWORD *)(a1 + 48);
  *(_QWORD *)(a1 + 128) = *(_QWORD *)(a1 + 56);
  *(_DWORD *)(a1 + 136) = v7;
  *(_WORD *)(a1 + 224) = 257;
  return qcrypto_queue_req(v5, *(_QWORD *)(v4 + 48), a1);
}
