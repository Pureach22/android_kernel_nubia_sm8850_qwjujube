__int64 __fastcall msm_spare_write(int a1, __int16 a2)
{
  __int64 v2; // x10
  __int64 v3; // x9
  __int64 v4; // x9

  v2 = *(_QWORD *)(msm_pinctrl_data + 968);
  v3 = *(_QWORD *)(v2 + 128);
  if ( !v3 )
    return 4294967294LL;
  if ( *(_DWORD *)(v2 + 136) <= a1 )
    return 4294967294LL;
  v4 = *(unsigned int *)(v3 + 8LL * a1 + 4);
  if ( !(_DWORD)v4 )
    return 4294967294LL;
  writel_relaxed(a2 & 0xFF00, (unsigned int *)(*(_QWORD *)(msm_pinctrl_data + 976) + v4));
  return 0;
}
