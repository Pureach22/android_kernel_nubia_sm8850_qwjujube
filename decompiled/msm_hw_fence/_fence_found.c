__int64 __fastcall fence_found(__int64 a1, __int64 a2)
{
  int v2; // w8
  int v4; // w9

  v2 = *(_DWORD *)(a2 + 112);
  if ( (~v2 & 0x3FFFFFFF) == 0 )
    return 4294967274LL;
  v4 = msm_hw_fence_debug_level;
  *(_DWORD *)(a2 + 112) = v2 + 1;
  if ( (~v4 & 0x10020) == 0 )
    printk(&unk_2A83D, "_fence_found", 1345, *(unsigned int *)(a2 + 32), *(_QWORD *)(a2 + 8));
  return 0;
}
