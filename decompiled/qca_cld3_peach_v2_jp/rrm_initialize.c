__int64 __fastcall rrm_initialize(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w8

  v1 = a1 + 0x4000;
  *(_QWORD *)(a1 + 20192) = 0;
  *(_QWORD *)(a1 + 20184) = 0;
  *(_QWORD *)(a1 + 20176) = 0;
  *(_QWORD *)(a1 + 20168) = 0;
  *(_QWORD *)(a1 + 20160) = 0;
  *(_WORD *)(a1 + 20153) = 0;
  *(_BYTE *)(a1 + 20136) = 0;
  *(_WORD *)(a1 + 20156) = -1;
  *(_BYTE *)(a1 + 20158) = 0;
  qdf_mem_set((void *)(a1 + 20148), 5u, 0);
  v3 = *(_DWORD *)(v1 + 3764) & 0xFF02F58C | 0x6D0A73;
  *(_BYTE *)(v1 + 3768) |= 0xCu;
  *(_DWORD *)(v1 + 3764) = v3;
  return 0;
}
