__int64 __fastcall rtc6226_vidioc_g_audio(__int64 a1, __int64 a2, __int64 a3)
{
  *(_WORD *)(a3 + 8) = 111;
  *(_QWORD *)a3 = 0x6964615200000000LL;
  *(_QWORD *)(a3 + 36) = 1;
  return 0;
}
