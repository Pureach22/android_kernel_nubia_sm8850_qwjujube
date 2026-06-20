void *__fastcall cntr_payload_cleanup(__int64 a1)
{
  __int64 v2; // x9
  void *v3; // x0
  void *result; // x0
  __int64 v5; // x8

  memset(*(void **)(a1 + 24), 0, *(unsigned int *)(a1 + 48));
  v2 = *(_QWORD *)(a1 + 112);
  v3 = *(void **)(a1 + 64);
  *(_QWORD *)(a1 + 32) = *(_QWORD *)(a1 + 24);
  result = memset(v3, 0, 3LL * *(unsigned __int8 *)(v2 + 5));
  v5 = *(_QWORD *)(a1 + 72);
  *(_DWORD *)(a1 + 131) = 0;
  *(_BYTE *)(v5 + 2) = 0;
  *(_WORD *)v5 = 0;
  *(_BYTE *)(a1 + 134) = 0;
  *(_BYTE *)(a1 + 132) = 0;
  *(_DWORD *)(a1 + 40) = 0;
  return result;
}
