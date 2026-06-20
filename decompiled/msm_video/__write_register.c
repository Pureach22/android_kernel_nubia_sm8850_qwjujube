__int64 __fastcall _write_register(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v7; // x4
  _QWORD *v8; // x8
  __int64 v9; // x21

  result = _strict_check(a1, "__write_register");
  if ( !(_DWORD)result )
  {
    if ( (is_core_sub_state(a1, 1) & 1) != 0 )
    {
      v8 = *(_QWORD **)(a1 + 3904);
      v9 = *v8;
      if ( (msm_vidc_debug & 4) != 0 )
        printk(&unk_83163, "low ", 0xFFFFFFFFLL, "codec", *v8);
      writel_relaxed(a3, v9 + a2);
      __dsb(0xEu);
      return 0;
    }
    else
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_911EE, "err ", 0xFFFFFFFFLL, "codec", v7);
      return 4294967274LL;
    }
  }
  return result;
}
