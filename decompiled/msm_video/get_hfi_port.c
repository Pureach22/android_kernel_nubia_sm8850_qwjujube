__int64 __fastcall get_hfi_port(__int64 result, unsigned int a2)
{
  __int64 v2; // x4
  unsigned int *v3; // x8
  __int64 v4; // x2
  void *v5; // x0

  v2 = *(unsigned int *)(result + 308);
  if ( (_DWORD)v2 == 1 )
  {
    if ( a2 < 4 )
    {
      v3 = (unsigned int *)&unk_9E75C;
      return v3[a2];
    }
    goto LABEL_8;
  }
  if ( (_DWORD)v2 == 2 )
  {
    if ( a2 < 4 )
    {
      v3 = (unsigned int *)&unk_9E72C;
      return v3[a2];
    }
LABEL_8:
    if ( !result )
      return result;
    if ( (msm_vidc_debug & 1) == 0 )
      return 0;
    v4 = result + 340;
    v5 = &unk_937D9;
    v2 = a2;
    goto LABEL_16;
  }
  if ( !result )
    return result;
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v4 = result + 340;
    v5 = &unk_801EE;
LABEL_16:
    printk(v5, "err ", v4, "get_hfi_port", v2);
  }
  return 0;
}
