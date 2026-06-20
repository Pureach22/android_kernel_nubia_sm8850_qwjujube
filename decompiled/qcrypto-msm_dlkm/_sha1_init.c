__int64 __fastcall sha1_init(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0

  *(_DWORD *)(a1 + 292) = 0;
  *(_WORD *)(a1 + 224) = 1;
  v1 = *(_QWORD *)(a1 + 32);
  *(_QWORD *)(a1 + 200) = 0;
  *(_QWORD *)(a1 + 208) = 0;
  *(_QWORD *)(a1 + 216) = 0;
  *(_DWORD *)(v1 + 68) = 0;
  *(_QWORD *)(a1 + 226) = 0;
  v2 = a1 + 226;
  *(_DWORD *)(v2 + 246) = -253635901;
  *(_QWORD *)(v2 + 48) = 0;
  *(_QWORD *)(v2 + 56) = 0;
  *(_QWORD *)(v2 + 32) = 0;
  *(_QWORD *)(v2 + 40) = 0;
  *(_QWORD *)(v2 + 16) = 0;
  *(_QWORD *)(v2 + 24) = 0;
  *(_QWORD *)(v2 + 230) = 0x89ABCDEF01234567LL;
  *(_QWORD *)(v2 + 8) = 0;
  *(_QWORD *)(v2 + 238) = 0x76543210FEDCBA98LL;
  *(_DWORD *)(v1 + 72) = 20;
  ++qword_11A70;
  return 0;
}
