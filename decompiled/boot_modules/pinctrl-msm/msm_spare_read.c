__int64 __fastcall msm_spare_read(int a1)
{
  __int64 v1; // x10
  __int64 v2; // x9
  __int64 v3; // x9

  v1 = *(_QWORD *)(msm_pinctrl_data + 968);
  v2 = *(_QWORD *)(v1 + 128);
  if ( v2 && *(_DWORD *)(v1 + 136) > a1 && (v3 = *(unsigned int *)(v2 + 8LL * a1 + 4), (_DWORD)v3) )
    return readl_relaxed((unsigned int *)(*(_QWORD *)(msm_pinctrl_data + 976) + v3)) & 0xFF00;
  else
    return 4294967294LL;
}
