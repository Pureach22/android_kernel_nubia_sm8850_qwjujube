__int64 __fastcall msm_qup_read(int a1)
{
  __int64 v1; // x10
  __int64 v2; // x9
  unsigned int *i; // x10

  v1 = *(_QWORD *)(msm_pinctrl_data + 968);
  v2 = *(unsigned int *)(v1 + 104);
  if ( (int)v2 < 1 )
    return 4294967294LL;
  for ( i = (unsigned int *)(*(_QWORD *)(v1 + 96) + 4LL); *(i - 1) != a1; i += 2 )
  {
    if ( !--v2 )
      return 4294967294LL;
  }
  return readl_relaxed((unsigned int *)(*(_QWORD *)(msm_pinctrl_data + 976) + *i)) & 0x3F;
}
