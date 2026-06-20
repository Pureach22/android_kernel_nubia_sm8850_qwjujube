__int64 __fastcall msm_vidc_fence_release(__int64 a1, __int64 a2)
{
  if ( *(_QWORD *)(a2 + 264) )
  {
    msm_vidc_put_sw_fence(a1, (char *)a2);
    return 0;
  }
  else
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_89281, "err ", a1 + 340, "msm_vidc_fence_release", a2 + 16);
    }
    return 4294967274LL;
  }
}
