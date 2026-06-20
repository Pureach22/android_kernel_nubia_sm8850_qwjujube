void *__fastcall pipe_clear(__int64 a1)
{
  void *result; // x0

  *(_QWORD *)a1 = a1;
  *(_QWORD *)(a1 + 8) = a1;
  *(_QWORD *)(a1 + 184) = 0xFFFFFFFF00000000LL;
  *(_QWORD *)(a1 + 192) = 0;
  *(_QWORD *)(a1 + 216) = 0xFFFFFFFFLL;
  *(_DWORD *)(a1 + 224) = 0;
  *(_BYTE *)(a1 + 640) = 0;
  *(_BYTE *)(a1 + 208) = 0;
  result = memset((void *)(a1 + 232), 0, 0x198u);
  *(_QWORD *)(a1 + 560) = a1 + 560;
  *(_QWORD *)(a1 + 568) = a1 + 560;
  return result;
}
