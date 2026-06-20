unsigned __int64 __fastcall msm_vidc_get_context_bank_for_region(__int64 a1, unsigned int a2)
{
  void *v2; // x0
  __int64 v3; // x8
  unsigned __int64 result; // x0
  unsigned __int64 v5; // x8

  if ( a2 - 128 <= 0xFFFFFF80 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v2 = &unk_9644B;
LABEL_13:
      printk(v2, "err ", 0xFFFFFFFFLL, "codec", a2);
      return 0;
    }
    return 0;
  }
  v3 = *(_QWORD *)(a1 + 3904);
  result = *(_QWORD *)(v3 + 112);
  v5 = result + 56LL * *(unsigned int *)(v3 + 120);
  if ( result >= v5 )
    goto LABEL_7;
  while ( (*(_DWORD *)(result + 40) & a2) == 0 )
  {
    result += 56LL;
    if ( result >= v5 )
      goto LABEL_7;
  }
  if ( !result )
  {
LABEL_7:
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v2 = &unk_843A6;
      goto LABEL_13;
    }
    return 0;
  }
  return result;
}
