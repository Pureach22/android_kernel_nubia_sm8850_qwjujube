bool __fastcall kgsl_enable_signaling(__int64 a1)
{
  unsigned int v1; // w8
  unsigned int v2; // w9
  unsigned int v4; // w9
  unsigned int v5; // w8
  bool v6; // cf
  unsigned int v7; // w8

  v1 = *(_DWORD *)(a1 + 100);
  v2 = *(_DWORD *)(*(_QWORD *)(a1 + 72) + 68LL);
  if ( v2 == v1 )
    return 0;
  if ( v2 > v1 && ((v2 - v1) & 0x80000000) == 0 )
    return 0;
  v4 = v2 ^ 0x80000000;
  v5 = v1 ^ 0x80000000;
  v6 = v4 >= v5;
  v7 = v4 - v5;
  return v7 == 0 || !v6 || v7 > 0x80000000;
}
