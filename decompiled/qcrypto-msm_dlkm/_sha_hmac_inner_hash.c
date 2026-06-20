__int64 __fastcall sha_hmac_inner_hash(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x23
  __int64 v4; // x20
  __int64 v5; // x21
  int v6; // w9
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 32);
  v3 = a1 + 359;
  v4 = *(_QWORD *)(v1 + 144);
  v5 = *(_QWORD *)(v1 + 56);
  memcpy((void *)((a1 + 359) & 0xFFFFFFFFFFFFFFC0LL), (const void *)(a1 + 226), *(unsigned int *)(a1 + 292));
  v6 = *(_DWORD *)(a1 + 292);
  *(_DWORD *)(a1 + 496) = v3 & 0xFC0;
  *(_DWORD *)(a1 + 500) = v6;
  *(_QWORD *)(a1 + 488) = ((unsigned __int64)((v3 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x13FFFFFFELL;
  *(_DWORD *)(v4 + 48) = v6;
  *(_QWORD *)(v4 + 56) = a1 + 488;
  *(_QWORD *)(v4 + 64) = a1 + 456;
  *(_BYTE *)(a1 + 225) = 1;
  result = qcrypto_queue_req(v5, *(_QWORD *)(v1 + 48), v4);
  if ( (_DWORD)result == -16 || (_DWORD)result == -115 )
  {
    result = wait_for_completion_interruptible(v1 + 152);
    *(_DWORD *)(v1 + 152) = 0;
  }
  return result;
}
