__int64 __fastcall msm_vidc_fence_signal(__int64 a1, __int64 a2, char a3)
{
  if ( *(_QWORD *)(a2 + 264) )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_89281, "err ", a1 + 340, "msm_vidc_fence_signal", a2 + 16);
    }
    return 4294967274LL;
  }
  else
  {
    if ( (a3 & 1) != 0 )
    {
      if ( (*(_QWORD *)(a2 + 232) & 1) != 0 )
        __break(0x800u);
      *(_DWORD *)(a2 + 244) = -22;
    }
    dma_fence_signal(a2 + 184);
    return 0;
  }
}
