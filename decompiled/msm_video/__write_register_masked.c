__int64 __fastcall _write_register_masked(__int64 a1, unsigned int a2, int a3, int a4)
{
  __int64 result; // x0
  unsigned int *v9; // x22
  int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w23

  result = _strict_check(a1, "__write_register_masked");
  if ( !(_DWORD)result )
  {
    if ( (is_core_sub_state(a1, 1) & 1) != 0 )
    {
      v9 = (unsigned int *)(**(_QWORD **)(a1 + 3904) + a2);
      v10 = readl_relaxed_0(v9);
      __dsb(0xDu);
      v11 = v10 & ~a4 | a4 & a3;
      if ( (msm_vidc_debug & 4) != 0 )
      {
        v12 = v11;
        printk(&unk_91233, "low ", 0xFFFFFFFFLL, "codec", v9);
        v11 = v12;
      }
      writel_relaxed(v11, v9);
      __dsb(0xEu);
      return 0;
    }
    else
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_9751D, "err ", 0xFFFFFFFFLL, "codec", "__write_register_masked");
      return 4294967274LL;
    }
  }
  return result;
}
