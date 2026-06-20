__int64 __fastcall vidc_port_from_hfi(__int64 a1, unsigned int a2)
{
  __int64 v2; // x4
  int *v3; // x8
  __int64 v5; // x2
  void *v6; // x0

  v2 = *(unsigned int *)(a1 + 308);
  if ( (_DWORD)v2 == 1 )
  {
    if ( a2 < 3 )
    {
      v3 = (int *)&unk_9FC98;
      return (unsigned int)v3[a2];
    }
  }
  else
  {
    if ( (_DWORD)v2 != 2 )
    {
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 5;
      v5 = a1 + 340;
      v6 = &unk_801EE;
      goto LABEL_16;
    }
    if ( a2 < 3 )
    {
      v3 = &dword_9E308;
      return (unsigned int)v3[a2];
    }
  }
  if ( !a1 || (msm_vidc_debug & 1) == 0 )
    return 5;
  v5 = a1 + 340;
  v6 = &unk_8EBDE;
  v2 = a2;
LABEL_16:
  printk(v6, "err ", v5, "vidc_port_from_hfi", v2);
  return 5;
}
