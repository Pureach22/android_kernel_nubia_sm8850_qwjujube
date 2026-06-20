__int64 __fastcall msm_vidc_try_cmd(__int64 a1, unsigned int *a2)
{
  int v2; // w8
  unsigned int *v4; // x19
  unsigned int *v5; // x19

  v2 = *(_DWORD *)(a1 + 308);
  if ( v2 == 1 )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      v5 = a2;
      printk(&unk_9084F, "high", a1 + 340, "msm_vidc_try_cmd", *a2);
      a2 = v5;
    }
    if ( *a2 <= 1 )
    {
      a2[1] = 0;
      return 0;
    }
    return 4294967274LL;
  }
  if ( v2 == 2 )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v4 = a2;
        printk(&unk_9084F, "high", a1 + 340, "msm_vidc_try_cmd", *a2);
        a2 = v4;
      }
    }
    if ( *a2 <= 1 )
    {
      a2[1] = 0;
      *((_QWORD *)a2 + 1) = 0;
      return 0;
    }
    return 4294967274LL;
  }
  return 0;
}
