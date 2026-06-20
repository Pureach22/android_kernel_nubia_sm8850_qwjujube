__int64 __fastcall rrm_initialize(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w8

  v1 = a1 + 0x4000;
  *(_QWORD *)(a1 + 20264) = 0;
  *(_QWORD *)(a1 + 20256) = 0;
  *(_QWORD *)(a1 + 20248) = 0;
  *(_QWORD *)(a1 + 20240) = 0;
  *(_QWORD *)(a1 + 20232) = 0;
  *(_WORD *)(a1 + 20225) = 0;
  *(_BYTE *)(a1 + 20208) = 0;
  *(_WORD *)(a1 + 20228) = -1;
  *(_BYTE *)(a1 + 20230) = 0;
  qdf_mem_set((void *)(a1 + 20220), 5u, 0);
  v3 = *(_DWORD *)(v1 + 3836) & 0xFF02F58C | 0x6D0A73;
  *(_BYTE *)(v1 + 3840) |= 0xCu;
  *(_DWORD *)(v1 + 3836) = v3;
  return 0;
}
