bool __fastcall kgsl_sync_fence_has_signaled(__int64 a1)
{
  unsigned int v1; // w8
  unsigned int v2; // w9
  unsigned int v4; // w9
  unsigned int v5; // w8
  unsigned int v6; // w8
  bool v7; // cf

  v1 = *(_DWORD *)(a1 + 100);
  v2 = *(_DWORD *)(*(_QWORD *)(a1 + 72) + 68LL);
  if ( v2 == v1 )
    return 1;
  if ( v2 > v1 && ((v2 - v1) & 0x80000000) == 0 )
    return 1;
  v4 = v2 ^ 0x80000000;
  v5 = v1 ^ 0x80000000;
  v7 = v4 >= v5;
  v6 = v4 - v5;
  v7 = v6 == 0 || !v7 || v6 >= 0x80000001;
  return !v7;
}
