__int64 __fastcall unreserve_hw_fence(__int64 a1, __int64 a2, unsigned int a3)
{
  int v3; // w8
  int v4; // w8

  v3 = *(_DWORD *)(a2 + 112);
  if ( (v3 & 0x3FFFFFFF) == 0 )
    return 4294967274LL;
  v4 = v3 - 1;
  *(_DWORD *)(a2 + 112) = v4;
  if ( !v4 )
  {
    *(_DWORD *)(a2 + 4) = 0;
    __dsb(0xEu);
    *(_QWORD *)(a2 + 8) = 0;
    *(_QWORD *)(a2 + 16) = 0;
    *(_QWORD *)(a2 + 24) = 0;
    *(_QWORD *)(a2 + 32) = 0;
    *(_QWORD *)(a2 + 80) = 0;
    *(_QWORD *)(a2 + 88) = 0;
    *(_QWORD *)(a2 + 96) = 0;
    *(_QWORD *)(a2 + 104) = 0;
    *(_QWORD *)(a2 + 48) = 0;
    *(_QWORD *)(a2 + 56) = -1;
    *(_QWORD *)(a2 + 64) = -1;
    *(_QWORD *)(a2 + 72) = -1;
    *(_QWORD *)(a2 + 112) = 0;
    *(_QWORD *)(a2 + 120) = 0;
    *(_DWORD *)a2 = 0;
    *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8LL * a3) = 0;
  }
  if ( (~msm_hw_fence_debug_level & 0x10020) == 0 )
    printk(&unk_27317, "_unreserve_hw_fence", 1262, *(unsigned int *)(a2 + 32), *(_QWORD *)(a2 + 8));
  return 0;
}
