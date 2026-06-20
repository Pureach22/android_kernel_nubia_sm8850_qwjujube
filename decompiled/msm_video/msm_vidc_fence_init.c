__int64 __fastcall msm_vidc_fence_init(__int64 a1)
{
  __int64 v2; // x20
  char *v3; // x21
  __int64 v4; // x0
  __int64 v5; // x4

  v2 = a1 + 37808;
  v3 = (char *)(a1 + 37680);
  *(_QWORD *)(a1 + 37808) = dma_fence_context_alloc(1);
  *(_QWORD *)(v2 + 8) = 0;
  strcpy(v3, "input: rx ");
  *(_DWORD *)(v2 + 32) = 0;
  *(_QWORD *)(v2 + 40) = 0;
  *(_QWORD *)(v2 + 16) = v2 + 16;
  *(_QWORD *)(v2 + 24) = v2 + 16;
  *(_QWORD *)(v2 + 176) = dma_fence_context_alloc(1);
  *(_QWORD *)(v2 + 184) = 0;
  strcpy((char *)(a1 + 37856), "input: tx ");
  *(_DWORD *)(v2 + 208) = 0;
  *(_QWORD *)(v2 + 216) = 0;
  *(_QWORD *)(v2 + 192) = v2 + 192;
  *(_QWORD *)(v2 + 200) = v2 + 192;
  *(_QWORD *)(v2 + 352) = dma_fence_context_alloc(1);
  *(_QWORD *)(v2 + 360) = 0;
  *(_DWORD *)(v2 + 384) = 0;
  strcpy((char *)(a1 + 38032), "output: rx ");
  *(_QWORD *)(v2 + 392) = 0;
  *(_QWORD *)(v2 + 368) = v2 + 368;
  *(_QWORD *)(v2 + 376) = v2 + 368;
  v4 = dma_fence_context_alloc(1);
  *(_QWORD *)(v2 + 536) = 0;
  *(_QWORD *)(v2 + 528) = v4;
  *(_DWORD *)(v2 + 560) = 0;
  strcpy((char *)(a1 + 38208), "output: tx ");
  *(_QWORD *)(v2 + 568) = 0;
  *(_QWORD *)(v2 + 544) = v2 + 544;
  *(_QWORD *)(v2 + 552) = v2 + 544;
  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_80624, "high", a1 + 340, "msm_vidc_fence_init", v5);
  return 0;
}
