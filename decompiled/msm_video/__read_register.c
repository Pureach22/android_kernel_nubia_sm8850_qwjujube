__int64 __fastcall _read_register(__int64 a1, unsigned int a2, _DWORD *a3)
{
  __int64 v6; // x4
  __int64 v7; // x21

  if ( (is_core_sub_state(a1, 1) & 1) != 0 )
  {
    v7 = **(_QWORD **)(a1 + 3904);
    *a3 = readl_relaxed_0((unsigned int *)(v7 + a2));
    __dsb(0xDu);
    if ( (msm_vidc_debug & 4) != 0 )
      printk(&unk_86232, "low ", 0xFFFFFFFFLL, "codec", v7);
    return 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_861EE, "err ", 0xFFFFFFFFLL, "codec", v6);
    return 4294967274LL;
  }
}
