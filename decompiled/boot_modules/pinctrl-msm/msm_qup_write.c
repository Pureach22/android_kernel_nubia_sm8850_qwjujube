__int64 __fastcall msm_qup_write(int a1, char a2)
{
  __int64 v2; // x10
  __int64 v3; // x9
  unsigned int *i; // x10

  v2 = *(_QWORD *)(msm_pinctrl_data + 968);
  v3 = *(unsigned int *)(v2 + 104);
  if ( (int)v3 < 1 )
    return 4294967294LL;
  for ( i = (unsigned int *)(*(_QWORD *)(v2 + 96) + 4LL); *(i - 1) != a1; i += 2 )
  {
    if ( !--v3 )
      return 4294967294LL;
  }
  writel_relaxed(a2 & 0x3F, (unsigned int *)(*(_QWORD *)(msm_pinctrl_data + 976) + *i));
  return 0;
}
