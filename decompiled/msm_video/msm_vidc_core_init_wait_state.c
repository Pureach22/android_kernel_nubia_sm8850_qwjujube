__int64 __fastcall msm_vidc_core_init_wait_state(__int64 a1, int a2, _DWORD *a3)
{
  void *v4; // x0

  if ( a2 != 2 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v4 = &unk_95A14;
LABEL_10:
    printk(v4, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_core_init_wait_state");
    return 4294967274LL;
  }
  if ( *a3 )
  {
    *(_DWORD *)(a1 + 3720) |= *a3;
    return 0;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v4 = &unk_91899;
    goto LABEL_10;
  }
  return 4294967274LL;
}
