__int64 __fastcall sha_final(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  __int64 v5; // x9
  int v6; // w10
  size_t v7; // x2
  int v8; // w11

  v1 = *(_QWORD *)(a1 + 32);
  v3 = *(_QWORD *)(v1 + 56);
  if ( *(_BYTE *)(v3 + 25) == 1 && (unsigned int)copy_source(a1) )
    return 4294967284LL;
  v5 = *(_QWORD *)(a1 + 56);
  v6 = *(_DWORD *)(a1 + 48);
  v7 = *(unsigned int *)(a1 + 292);
  *(_BYTE *)(a1 + 225) = 1;
  *(_QWORD *)(a1 + 128) = v5;
  *(_DWORD *)(a1 + 136) = v6;
  memcpy((void *)((a1 + 359) & 0xFFFFFFFFFFFFFFC0LL), (const void *)(a1 + 226), v7);
  v8 = *(_DWORD *)(a1 + 292);
  *(_DWORD *)(a1 + 496) = (a1 + 359) & 0xFC0;
  *(_QWORD *)(a1 + 56) = a1 + 488;
  *(_DWORD *)(a1 + 500) = v8;
  *(_DWORD *)(a1 + 48) = v8;
  *(_QWORD *)(a1 + 488) = ((unsigned __int64)(((a1 + 359) << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x13FFFFFFELL;
  return qcrypto_queue_req(v3, *(_QWORD *)(v1 + 48), a1);
}
