__int64 __fastcall msm_framebuffer_set_cache_hint(_DWORD *a1, int a2, int a3, int a4)
{
  if ( !a1 )
    return 4294967274LL;
  a1[50] = a2;
  a1[51] = a3;
  a1[52] = a4;
  return 0;
}
