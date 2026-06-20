__int64 __fastcall sha256_init(__int64 a1)
{
  __int64 v1; // x9
  _QWORD *v2; // x0

  v1 = *(_QWORD *)(a1 + 32);
  *(_DWORD *)(a1 + 292) = 0;
  *(_WORD *)(a1 + 224) = 1;
  *(_QWORD *)(a1 + 200) = 0;
  *(_QWORD *)(a1 + 208) = 0;
  *(_QWORD *)(a1 + 216) = 0;
  *(_DWORD *)(v1 + 68) = 1;
  *(_QWORD *)(a1 + 226) = 0;
  v2 = (_QWORD *)(a1 + 226);
  v2[6] = 0;
  v2[7] = 0;
  *(_QWORD *)((char *)v2 + 230) = 0x85AE67BB67E6096ALL;
  v2[4] = 0;
  v2[5] = 0;
  v2[2] = 0;
  v2[3] = 0;
  *(_QWORD *)((char *)v2 + 246) = 0x8C68059B7F520E51LL;
  *(_QWORD *)((char *)v2 + 238) = 0x3AF54FA572F36E3CLL;
  v2[1] = 0;
  *(_QWORD *)((char *)v2 + 254) = 0x19CDE05BABD9831FLL;
  *(_DWORD *)(v1 + 72) = 32;
  ++qword_11A78;
  return 0;
}
