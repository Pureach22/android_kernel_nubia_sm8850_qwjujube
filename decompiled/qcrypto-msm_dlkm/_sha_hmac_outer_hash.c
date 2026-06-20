__int64 __fastcall sha_hmac_outer_hash(__int64 a1, size_t n)
{
  __int64 v2; // x23
  __int64 v3; // x24
  int v4; // w22
  __int64 v6; // x8
  unsigned __int64 v7; // x9
  __int64 v8; // x20
  _QWORD *v9; // x21
  int v10; // w12
  __int64 v11; // x11
  int v12; // w8

  v2 = *(_QWORD *)(a1 + 32);
  v3 = a1 + 359;
  v4 = n;
  v6 = 0;
  v7 = (a1 + 359) & 0xFFFFFFFFFFFFFFC0LL;
  v8 = *(_QWORD *)(v2 + 56);
  do
  {
    *(_BYTE *)(v7 + v6) = *(_BYTE *)(v2 + 80 + v6) ^ 0x5C;
    ++v6;
  }
  while ( v6 != 64 );
  v9 = (_QWORD *)(a1 + 456);
  memcpy((void *)(v7 + 64), (const void *)(a1 + 456), (unsigned int)n);
  *(_DWORD *)(a1 + 500) = v4 + 64;
  v10 = *(_DWORD *)(a1 + 48);
  *(_DWORD *)(a1 + 48) = v4 + 64;
  *(_DWORD *)(a1 + 496) = v3 & 0xFC0;
  v11 = *(_QWORD *)(a1 + 56);
  *(_QWORD *)(a1 + 56) = a1 + 488;
  *(_DWORD *)(a1 + 292) = 0;
  *(_WORD *)(a1 + 224) = 1;
  *(_QWORD *)(a1 + 128) = v11;
  *(_DWORD *)(a1 + 136) = v10;
  *(_QWORD *)(a1 + 488) = ((unsigned __int64)((v3 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x13FFFFFFELL;
  *(_QWORD *)(a1 + 200) = 0;
  *(_QWORD *)(a1 + 208) = 0;
  *(_QWORD *)(a1 + 216) = 0;
  if ( *(_DWORD *)(v2 + 68) )
  {
    *v9 = 0x85AE67BB67E6096ALL;
    *(_QWORD *)(a1 + 464) = 0x3AF54FA572F36E3CLL;
    v12 = 32;
    *(_QWORD *)(a1 + 472) = 0x8C68059B7F520E51LL;
    *(_QWORD *)(a1 + 480) = 0x19CDE05BABD9831FLL;
  }
  else
  {
    *(_DWORD *)(a1 + 472) = -253635901;
    v12 = 20;
    *v9 = 0x89ABCDEF01234567LL;
    *(_QWORD *)(a1 + 464) = 0x76543210FEDCBA98LL;
  }
  *(_DWORD *)(v2 + 72) = v12;
  *(_BYTE *)(a1 + 225) = 1;
  return qcrypto_queue_req(v8, *(_QWORD *)(v2 + 48), a1);
}
